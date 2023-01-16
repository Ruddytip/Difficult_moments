#include <iostream>  // Для std::cout
#include "Task.hpp"  // Tasks 1, 2
#include "Task3.hpp" // Task 3

int main(){
    
    // Task 2 =============
    std::cout << "Task 2:\n";

    // Работа с именами =================================================================
    // Task::FullName name("Volkov", "Gena", "Vladovich");
    Task::FullName name("Kopach", "Olga", "");
    std::cout << "Before parse - " << name;
    // name.save("Gena_name.bin");
    name.load("Gena_name.bin");
    std::cout << "After parse -  " << name;
    std::cout << std::endl;

    // Работа со студентами =============================================================
    // Task::Student student(name, {5, 1, 5, 4.5, 4.3});
    Task::Student student( Task::FullName("Orehov", "Viktor", "Petrovich"), {1, 1.5, 5});
    std::cout << "Student before parse:\n" << student << std::endl;
    // student.save("Gena_student.bin");
    student.load("Gena_student.bin");
    std::cout << "Student after parse:\n" << student << std::endl;
   
    // ====================

    // Task 3 =============
    std::cout << "Task 3:\n";

    Task::generate_Group_bin(2); // Генерация Group.hpp
    Task::StudentsGroup group;
    group.Open(); // Чтение файла "Group.bin"

    // Проверка методов ==============================
    // std::cout << group.GetAverageScore(Task::FullName("Volkov", "Gena", "Petrovich")) << std::endl;
    // std::cout << group.GetAllInfo(Task::FullName("Volkov", "Gena", "Petrovich")) << std::endl;
    std::cout << group.GetAllInfo() << std::endl;
    
    // ====================

    return 0;
}