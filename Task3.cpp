#include "Task3.hpp"
#include <fstream>
#include <sstream>

Task::StudentsGroup::StudentsGroup(){
    students.clear();
}

Task::StudentsGroup::StudentsGroup(const std::vector<Task::Student>& _s)
: students(_s) {}

void Task::StudentsGroup::Save(){
    std::ofstream out("Group.bin", std::ios::binary | std::ios::trunc);
    if(!out.is_open()) return;

    // Запись информации о студенте
    uint8_t size = students.size();
    out.write(reinterpret_cast<char*>(&size), sizeof(size));
    for(auto& it : students) it.save(out);

    out.close();
}

void Task::StudentsGroup::Open(){
    std::ifstream in("Group.bin", std::ios::binary);
    if(!in.is_open()) return;
    uint8_t size = 0;
    in.read(reinterpret_cast<char*>(&size), sizeof(size));
    students.resize(size);
    for(auto& it : students) it.load(in);
    in.close();
}

double Task::StudentsGroup::GetAverageScore(const Task::FullName &name){
    for(const auto& it : students)
        if(it.getName() == name)
            return it.getAVG();
    return -1.0; // Вернуть -1.0 если не найден студент
}

std::string Task::StudentsGroup::GetAllInfo(const Task::FullName &name){
    std::stringstream iss("Not found!\n");
    for(const auto& it : students)
        if(it.getName() == name){
            iss.clear();
            iss << it << "\n";
            break;
        }
    return iss.str();
}

std::string Task::StudentsGroup::GetAllInfo(){
    std::stringstream iss;
    iss << "Students: " << students.size() << "\n\n";
    for(const auto& it : students) iss << it << "\n";
    return iss.str();
}

#include <ctime> // Для std::srand()

// Генерирует файл Group.bin
void Task::generate_Group_bin(const int& size_group){

    std::vector<std::string> names =       {"Gena",      "Petya",      "Vasya",  "Oleg",   "Semen"};
    std::vector<std::string> surnames =    {"Volkov",    "Orehov",     "Maslin", "Pulkin", "Kuka"};
    std::vector<std::string> patronymics = {"Petrovich", "Seminovich", "Tolich", "Kolich", ""};

    std::vector<Task::Student> vec; vec.resize(size_group);
    std::srand(time(0));
    for(auto& stud : vec){
        int count_evel = rand() % 10;
        std::vector<double> evel; evel.resize(count_evel);
        for(auto& it : evel) it = (rand() % 50) / 10.0;

        Task::FullName name(surnames[rand() % surnames.size()],
                            names[rand() % names.size()],
                            patronymics[rand() % patronymics.size()]);

        stud = Task::Student(name, evel);
    }
    Task::StudentsGroup group(vec);
    group.Save();
}