#pragma once
#include <string> // Для std::string

// Task 1. Создайте потокобезопасную оболочку для объекта cout. Назовите ее pcout. Необходимо,
// чтобы несколько потоков могли обращаться к pcout и информация выводилась в консоль.
// Продемонстрируйте работу pcout.
struct P_cout{
    P_cout& operator<<(const int& in);
    P_cout& operator<<(const std::string& in);
};

// Функция для демонстрации обращения к pcout
void print_to_pcout(const int& in);