#include "Iterator.hpp"

Iterator::Iterator(int* it): data(it){}

Iterator::Iterator(int& it): data(&it){}

Iterator::Iterator(__gnu_cxx::__normal_iterator<int *, std::vector<int, std::allocator<int>>> it)
: data(it.base()){}

bool Iterator::operator!=(const Iterator& it){ return (data != it.data); }

Iterator& Iterator::operator++(){ ++data; return *this; }

Iterator& Iterator::operator--(){ --data; return *this; }

int& Iterator::operator*(){ return *data; }

int* Iterator::operator->(){ return data; }

std::ostream& operator<<(std::ostream& out, const Iterator& it){
    out << *it.data;
    return out;
}
