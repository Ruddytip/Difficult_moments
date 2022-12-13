#include <iostream>     // Для std::cout
#include <list>         // Для std::list
#include "Matrix.hpp"   // Task 2
#include "Iterator.hpp" // Task 3

// Task 1. Написать функцию, добавляющую в конец списка вещественных чисел
// элемент, значение которого равно среднему арифметическому всех его элементов.
template<typename T>
void addAVG_to_EndList(std::list<T>& list){
    if(list.empty()) return;
    T summ = 0;
    for(const auto& it : list) summ+=it;
    list.push_back(summ / list.size());
}

int main(){
    
    // Task 1 ====================
    // std::cout << "Task 1:" << std::endl;
    // std::list<double> l1 = {4.3, 55., .0, 3.3, -12.999 };
    // std::cout << "List before: ";
    // for(const auto& it : l1) std::cout << it << ' ';
    // std::cout << std::endl;
    // addAVG_to_EndList(l1);
    // std::cout << "List after:  ";
    // for(const auto& it : l1) std::cout << it << ' ';
    // std::cout << std::endl;
    // ===========================

    // Task 2 ====================
    // std::cout << "Task 2:" << std::endl;
    // Matrix m = {{12, 0,  94},
    //             {26, 55, 12},
    //             {15, 7,  99}};
    // std::cout << m;
    // std::cout << "Determinant: " << m.determinant() << std::endl;
    // std::cout << std::endl;
    // ===========================

    // Task 3 ====================
    // std::cout << "Task 3:" << std::endl;
    
    // std::cout << std::endl;
    // ===========================
    return 0;
}