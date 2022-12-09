#include "PhoneNumber.hpp"
#include <tuple>

PhoneNumber::PhoneNumber() = default;

// Предполагается, что строка на входе корректная
PhoneNumber::PhoneNumber(const std::string& data): extensionNumber(std::nullopt){
    std::string country; country+=data[1];
    countryCode = std::stoi(country);
    cityCode = std::stoi(data.substr(3, 3));
    number = data.substr(7, 7);
    if(data.length() >= 16)
        extensionNumber = std::optional<int>(std::stoi(data.substr(15, data.length() - 15)));
}

PhoneNumber::PhoneNumber(const int _country, const int _city, const std::string& _number, const std::optional<int> _exten)
: countryCode(_country), cityCode(_city), number(_number), extensionNumber(_exten){}

std::ostream& operator<<(std::ostream& out, const PhoneNumber& phon){
    out << '+' << phon.countryCode << '(' << phon.cityCode << ')' << phon.number;
    if(phon.extensionNumber) out << ' ' << phon.extensionNumber.value();
    return out;
}

bool PhoneNumber::operator<(const PhoneNumber& phon){
    return std::tie(countryCode, cityCode, number, extensionNumber) <
    std::tie(phon.countryCode, phon.cityCode, phon.number, phon.extensionNumber);
    return false;
}

bool PhoneNumber::operator==(const PhoneNumber& phon){
    return std::tie(countryCode, cityCode, number, extensionNumber) ==
    std::tie(phon.countryCode, phon.cityCode, phon.number, phon.extensionNumber);
    return false;
}
