#pragma once
#include <vector>  // Для std::vector
#include <ostream> // Для std::ostream

// Task 2. Создать класс, представляющий матрицу. Реализовать в нем метод,
// вычисляющий определитель матрицы. Для реализации используйте контейнеры из STL.
class Matrix{
private:
    std::vector<std::vector<int>> data;
    unsigned int size;
public:
    // Конструктор квадратной матрицы размером _size, инициализированную нулями
    Matrix(const unsigned int _size);
    // Конструктор для инициализации фигурными скобками
    Matrix(const std::initializer_list<std::initializer_list<int>>& in);
    friend std::ostream& operator<<(std::ostream& out, const Matrix& mtrx);
    std::vector<int>& operator[](unsigned int index);
    // Минор к элементу data[y][x]
    // Возвращает матрицу на 1 размер меньше, без указанных строк и столбцов
    Matrix getMinor(const unsigned int x, const unsigned int y);
    // возвращает определитель(детерминант)
    int determinant();
};
