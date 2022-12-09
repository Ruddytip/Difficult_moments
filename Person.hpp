#pragma once
#include <string> // Для std::string
#include <ostream> // Для std::ostream

// Task 1. Создайте структуру Person с 3 полями: фамилия, имя, отчество.
// Поле отчество должно быть опционального типа, т.к. не у всех людей есть отчество.
// Перегрузите оператор вывода данных для этой структуры. Также перегрузите операторы < и == (используйте tie).
class Person{
private:
    std::string firstName, lastName, patronymic;
public:
    Person();
    Person(const std::string& _fName, const std::string& _lName);
    Person(const std::string& _fName, const std::string& _lName, const std::string& _patr);
    friend std::ostream& operator<<(std::ostream& out, const Person& pers);
    bool operator<(const Person& pers) const;
    bool operator==(const Person& pers) const;
    // Возвращает фамилию
    std::string getLastName() const;
};