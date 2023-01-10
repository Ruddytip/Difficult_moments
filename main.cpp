#include <iostream>  // Для std::cout
#include <vector>    // Для std::vector
#include <thread>    // Для std::thread
#include <cmath>     // Для std::sqrt
#include "Pcout.hpp" // Task 1
#include "Task3.hpp" // Task 3

// Task 2. Реализовать функцию, возвращающую i-ое простое число (например, миллионное простое
// число равно 15485863). Вычисления реализовать во вторичном потоке. В консоли отображать
// прогресс вычисления (в основном потоке).
size_t PrimeNumber(const size_t& i){
    if(i == 0) return 0;
    if(i == 1) return 2;
    const double step = 100.0 / static_cast<double>(i);
    double percent = 0.0;
    size_t count = 2; // Начинаем поиск со второго простого числа
    size_t out = 3;   // Второе простое число - 3

    // Печать прогресса вычисления
    std::thread printPercent([&](){
        while(percent <= 100.0) std::cout << percent << "%" << std::endl;
    });

    // Проверка простое ли число n
    auto isPrime = [](const size_t& n) -> bool{
        if(n%2 == 0) return false;
        size_t end = std::sqrt(n);
        for(size_t id = 3; id <= end; ++id){
            if(n%id == 0) return false;
        }
        return true;
    }; 

    // Поиск i-ого простого числа
    std::thread calculate([&](){
        while(count <= i){
            if(isPrime(out)) count++;
            out++;
            percent = step * count;
        }
        out--;
    });

    printPercent.join();
    calculate.join();

    return out;
}

int main(){

    // Task 1 =============
    std::cout << "Task 1:\n";
    const int size = std::thread::hardware_concurrency();
    std::vector<std::thread> threads;
    threads.resize(size);
    for(unsigned int i = 0; i < size; ++i) threads[i] = std::thread(print_to_pcout, i);
    for(auto& it : threads) it.join();
    std::cout << std::endl;
    // ====================

    // Task 2 =============
    std::cout << "Task 2:\n";
    size_t number = 1'000'000;
    size_t prime = PrimeNumber(number);
    std::cout << "Prime number " << number << " :- " << prime << std::endl;
    std::cout << std::endl;
    // ====================

    // Task 3 =============
    std::cout << "Task 3:\n";
    Task3();
    std::cout << std::endl;
    // ====================

    return 0;
}