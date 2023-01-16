#include "Task.hpp"

Task::FullName::FullName()
: surname(""), name(""), patronymic("") {}

Task::FullName::FullName(const std::string _s, const std::string _n, const std::string _p)
: surname(_s), name(_n), patronymic(_p) {}

void Task::FullName::save(const std::string& file){
    std::ofstream out(file, std::ios::binary | std::ios::trunc);
    if(!out.is_open()) return;
    save(out);
    out.close();
}

void Task::FullName::save(std::ofstream& out){
    auto file_write = [](std::ofstream& out, const std::string& str){
        uint8_t size = str.size();
        out.write(reinterpret_cast<char*>(&size), sizeof(size));
        for(uint8_t i = 0; i < size; ++i) out.write(&str[i], sizeof(char));
    };
    file_write(out, surname);    // Запись фамилии
    file_write(out, name);       // Запись имени
    file_write(out, patronymic); // Запись отчества
}

void Task::FullName::load(const std::string& file){
    std::ifstream in(file, std::ios::binary);
    if(!in.is_open()) return;
    load(in);
    in.close();
}

void Task::FullName::load(std::ifstream& in){
    auto file_read = [](std::ifstream& in, std::string& str){
        uint8_t size = 0;
        in.read(reinterpret_cast<char*>(&size), sizeof(size));
        str.resize(size);
        for(uint8_t i = 0; i < size; ++i) in.read(&str[i], sizeof(char));
    };

    file_read(in, surname);    // Чтение фамилии
    file_read(in, name);       // Чтение имени
    file_read(in, patronymic); // Чтение отчества
}

bool Task::FullName::operator==(const FullName& FN){
    if((surname    == FN.surname) &
       (name       == FN.name) & 
       (patronymic == FN.patronymic)) return true;
    return false;
}

Task::Student::Student()
: name() {
    evaluations.clear();
}

Task::Student::Student(const FullName& _n, const std::vector<double>& _e)
: name(_n), evaluations(_e) {
    double summ = 0.0;
    for(const auto& it : evaluations) summ+=it;
    avgEval = (evaluations.size() ? summ / evaluations.size() : 0.0);
}

Task::FullName Task::Student::getName() const {
    return name;
}

double Task::Student::getAVG() const{
    return avgEval;
}

void Task::Student::save(const std::string& file){
    std::ofstream out(file, std::ios::binary | std::ios::trunc);
    if(!out.is_open()) return;
    save(out);
    out.close();
}

void Task::Student::save(std::ofstream& out){
    // Запись имени
    name.save(out);

    // Запись всех оценок
    uint8_t size_e = evaluations.size();
    out.write(reinterpret_cast<char*>(&size_e), sizeof(size_e));
    for(auto& it : evaluations) out.write(reinterpret_cast<char*>(&it), sizeof(it));
    
    // Запись среднего балла
    out.write(reinterpret_cast<char*>(&avgEval), sizeof(avgEval));
}

void Task::Student::load(const std::string& file){
    std::ifstream in(file, std::ios::binary);
    if(!in.is_open()) return;
    load(in);
    in.close();
}

void Task::Student::load(std::ifstream& in){
    // Чтение имени
    name.load(in);
    // Чтение всех оценок
    uint8_t size_e = evaluations.size();
    in.read(reinterpret_cast<char*>(&size_e), sizeof(size_e));
    evaluations.resize(size_e);
    for(auto& it : evaluations) in.read(reinterpret_cast<char*>(&it), sizeof(it));
    
    // Чтение среднего балла
    in.read(reinterpret_cast<char*>(&avgEval), sizeof(avgEval));
}
