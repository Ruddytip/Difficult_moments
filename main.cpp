#include <iostream>  // Для std::cout
#include <fstream>   // Для std::ifstream
#include <vector>    // Для std::vector
#include <algorithm> // Для std::sort
#include "Timer.hpp" // Для Timer
#include "Task3.hpp" // Task 3

// Task 1. Реализуйте шаблонную функцию Swap, которая принимает два указателя и обменивает местами значения,
// на которые указывают эти указатели (нужно обменивать именно сами указатели, переменные должны оставаться в тех же адресах памяти).
template<typename T>
void Swap(T& ptr_1, T& ptr_2){
    T dir = ptr_1;
    ptr_1 = ptr_2;
    ptr_2 = dir;
}

// Task 2. Реализуйте шаблонную функцию SortPointers,
// которая принимает вектор указателей и сортирует указатели по значениям, на которые они указывают.
template<typename T>
void SortPointers(std::vector<T>& vec){
    std::sort(vec.begin(), vec.end(), [](T a, T b){
        return *a < *b;
    });
}

int main(){

    // Task 1 ====================
    std::cout << "Task 1:\n";
    int A = 10, B = 50;
    int* ptrA = &A;
    int* ptrB = &B;
    std::cout << "Before:\n";
    std::cout << "\tvariable A, with a value of " << *ptrA << " at the address " << ptrA << std::endl;
    std::cout << "\tvariable B, with a value of " << *ptrB << " at the address " << ptrB << std::endl;
    Swap<int*>(ptrA, ptrB);
    std::cout << "After:\n";
    std::cout << "\tvariable A, with a value of " << *ptrA << " at the address " << ptrA << std::endl;
    std::cout << "\tvariable B, with a value of " << *ptrB << " at the address " << ptrB << std::endl;
    std::cout << std::endl;
    // ===========================

    // Task 2 ====================
    std::cout << "Task 2:\n";
    int a = 111, b = 5, c = 234, d = 9, e = 0, f = 2;
    std::vector<int*> vec = {&a, &b, &c, &d, &e, &f};
    std::cout << "Before:\n\t";
    for(const auto& it : vec) std::cout << *it << " "; std::cout << std::endl;
    SortPointers<int*>(vec);
    std::cout << "After:\n\t";
    for(const auto& it : vec) std::cout << *it << " "; std::cout << std::endl;
    std::cout << std::endl;
    // ===========================

    // Task 3 ====================
    std::cout << "Task 3:\n";

    std::ifstream file("War and Peace.txt");
    std::string str("");
    while(!file.eof()){
        std::string rdStr;
        std::getline(file, rdStr);
        str+=rdStr;
    }
    file.close();

    Timer if_find("Counting with cnt_if and find");
    std::cout << "Number of characters " << count_if_find(str) << " | " << if_find << std::endl;
    Timer if_for("Counting with cnt_if and for");
    std::cout << "Number of characters " << count_if_for(str)  << " | " << if_for  << std::endl;
    Timer for_fnd("Counting with for and find");
    std::cout << "Number of characters " << for_find(str)      << " | " << for_fnd << std::endl;
    Timer fr_fr("Counting with for and for");
    std::cout << "Number of characters " << for_for(str)       << " | " << fr_fr   << std::endl;
    std::cout << std::endl;
    // ===========================

    return 0;
}
