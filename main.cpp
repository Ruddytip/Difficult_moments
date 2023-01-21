#include <iostream>      // Для std::cout
#include <vector>
#include <algorithm>
#include "Task.hpp"
#include "gtest/gtest.h"

int check_length_name(Task::FullName& name){
    return (name.getName().length() + name.getSurname().length());
}
TEST(names, check_length_name){
    // Работа с именами =================================================================
    // Task::FullName name("Volkov", "Gena", "Vladovich");
    Task::FullName name("Kopach", "Olga", "");
    // Проверка на не пустые имя и фамилию
    ASSERT_GT(check_length_name(name), 0);
    std::cout << "Before parse - " << name;
    // name.save("Gena_name.bin");
    name.load("Gena_name.bin");
    // Проверка на не пустые имя и фамилию
    ASSERT_GT(check_length_name(name), 0);
    std::cout << "After parse -  " << name;
    std::cout << std::endl;
}

bool check_evel(const std::vector<double>& v) {
    for(const auto& it : v) if(it < 0) return false;
    return true;
}
TEST(students, check_evel){
    // Работа со студентами =============================================================
    Task::Student student( Task::FullName("Orehov", "Viktor", "Petrovich"), {1, 1.5, 5});
    // Проверкана положительность оценок
    ASSERT_TRUE(check_evel(student.getEvaluations()));
    std::cout << "Student before parse:\n" << student << std::endl;
    // student.save("Gena_student.bin");
    student.load("Gena_student.bin");
    // Проверкана положительность оценок
    ASSERT_TRUE(check_evel(student.getEvaluations()));
    std::cout << "Student after parse:\n" << student << std::endl;
}

int main(){
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}