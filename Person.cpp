#include "Person.hpp"
#include <tuple>
#include <iomanip>

Person::Person() = default;

Person::Person(const std::string& _fName, const std::string& _lName)
: firstName(_fName), lastName(_lName), patronymic(""){}

Person::Person(const std::string& _fName, const std::string& _lName, const std::string& _patr)
: firstName(_fName), lastName(_lName), patronymic(_patr){}

std::ostream& operator<<(std::ostream &out, const Person &pers){
    const unsigned int wid = 15; // Ширина полей вывода в консоль
    out << std::left;
    out << std::setw(wid) << pers.lastName;
    out << std::setw(wid) << pers.firstName;
    out << std::setw(wid) << pers.patronymic;
    out << std::right;
    return out;
}

bool Person::operator<(const Person& pers) const {
    return std::tie(lastName, firstName, patronymic) < std::tie(pers.lastName, pers.firstName, pers.patronymic);
}

bool Person::operator==(const Person& pers) const {
    return std::tie(firstName, lastName, patronymic) == std::tie(pers.firstName, pers.lastName, pers.patronymic);
}

std::string Person::getLastName() const {
    return lastName;
}
