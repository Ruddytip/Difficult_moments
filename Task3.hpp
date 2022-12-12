#pragma once
#include <string> // Для std::string

// Task 3. Подсчитайте количество гласных букв в книге “Война и мир”. Для подсчета используйте 4
// способа:
// - count_if и find
// - count_if и цикл for
// - цикл for и find
// - 2 цикла for
// Замерьте время каждого способа подсчета и сделайте выводы.
// Справка:
    // count_if - это алгоритмическая функция из STL, которая принимает 3 параметра:
    // итератор на начало, итератор на конец и унарный предикат (функцию, принимающую один параметр и возвращающую тип bool).
    // find - это метод класса string, который возвращает позицию символа (строки),
    // переданного в качестве параметра, в исходной строке. Если символ не найден, то метод возвращает string::npos.

// Подсчёт с count_if и find
unsigned int count_if_find(const std::string& name);
// Подсчёт с count_if и цикл for
unsigned int count_if_for(const std::string& name);
// Подсчёт с for и find
unsigned int for_find(const std::string& name);
// Подсчёт с 2 циклами for
unsigned int for_for(const std::string& name);