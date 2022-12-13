#include <cmath> // Для std::pow
#include "Matrix.hpp"

Matrix::Matrix(const unsigned int _size)
: size(_size){
    data.resize(size);
    for(auto& it : data){
        it.resize(size);
        for(auto& cell : it) cell = 0;
    }
}

Matrix::Matrix(const std::initializer_list<std::initializer_list<int>> &in)
    : size(in.size())
{
    data.resize(size);
    for(unsigned int j = 0; j < size; ++j){
        data[j].resize(size);
        for(unsigned int i = 0; i < size; ++i)
            data[j][i] = *((in.begin() + j)->begin() + i);
    }
}

std::ostream& operator<<(std::ostream& out, const Matrix& mtrx){
    for(const auto& it : mtrx.data){
        for(const auto& cell : it) out << cell << "\t";
        out << std::endl;
    }
    return out;
}

std::vector<int>& Matrix::operator[](unsigned int index){
    return data[index];
}

Matrix Matrix::getMinor(const unsigned int x, const unsigned int y){
    Matrix out(size - 1);
    unsigned int out_j = 0;
    for(unsigned int j = 0; j < size; ++j){
        if(j == y) continue;
        unsigned int out_i = 0;
        for(unsigned int i = 0; i < size; ++i){
            if(i == x) continue;
            out[out_j][out_i++] = data[j][i];
        }
        out_j++;
    }
    return out;
}

int Matrix::determinant(){
    if(size == 0) return 0;
    if(size == 1) return data[0][0];
    if(size == 2) return data[0][0] * data[1][1] - data[1][0] * data[0][1];
    int out = 0;
    for(unsigned int j = 0; j < size; ++j){
        // формула разложения по строке
        out+= std::pow(-1, 1 + j) * data[j][1] * getMinor(1, j).determinant();
    }
    return out;
}
