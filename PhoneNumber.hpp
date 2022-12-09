#pragma once
#include <string>   // Для std::string
#include <optional> // Для std::optional
#include <ostream>  // Для std::ostream

// Task 2. Создайте структуру PhoneNumber с 4 полями:
// · код страны (целое число)
// · код города (целое число)
// · номер (строка)
// · добавочный номер (целое число, опциональный тип)
// Для этой структуры перегрузите оператор вывода.
// Необходимо, чтобы номер телефона выводился в формате: +7(911)1234567 12,
// где 7 – это номер страны, 911 – номер города, 1234567 – номер, 12 – добавочный номер.
// Если добавочного номера нет, то его выводить не надо. Также перегрузите операторы < и == (используйте tie)
class PhoneNumber{
private:
    int countryCode;
    int cityCode;
    std::string number;
    std::optional<int> extensionNumber;
public:
    PhoneNumber();
    PhoneNumber(const std::string& data);
    PhoneNumber(const int _country, const int _city, const std::string&  _number, const std::optional<int> _exten);
    friend std::ostream& operator<<(std::ostream& out, const PhoneNumber& phon);
    bool operator<(const PhoneNumber& phon);
    bool operator==(const PhoneNumber& phon);
};