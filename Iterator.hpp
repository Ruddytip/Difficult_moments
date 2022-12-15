#pragma once
#include <ostream>
#include <vector>

// Task 3. Реализовать собственный класс итератора, с помощью которого можно будет
// проитерироваться по диапазону целых чисел в цикле for-range-based.
class Iterator{
private:
    int* data;
public:
    // Конструктор на указатель
    Iterator(int* it);
    // Конструктор на ссылку
    Iterator(int& it);
    // Конструктор на тип данных std::vector::begin() и std::vector::end()
    Iterator(__gnu_cxx::__normal_iterator<int*, std::vector<int, std::allocator<int>>> it);
    bool operator!=(const Iterator& it);
    Iterator& operator++();
    Iterator& operator--();
    int& operator*();
    int* operator->();
    friend std::ostream& operator<<(std::ostream& out, const Iterator& it);
};