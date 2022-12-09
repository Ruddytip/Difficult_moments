#include "PhoneBook.hpp"
#include <algorithm>
#include <tuple>
#include <sstream>
#include <iomanip>

PhoneBook::PhoneBook(std::ifstream& file){
    if(!file.is_open()){
        book.clear();
        return;
    }

    while(!file.eof()){
        std::string str;
        std::getline(file, str);
        std::stringstream iss(str);
        std::string first_name(""), last_name(""), father_name(""), phone(""), exNumber("");
        iss >> last_name >> first_name >> father_name;
        // Если нет отчества
        if(father_name[0] == '+'){
            iss >> exNumber;
            phone = father_name + exNumber;
            father_name = "";
        }else{
            iss >> phone >> exNumber;
            phone+=exNumber;
        }

        Person persOut(first_name, last_name, father_name);
        PhoneNumber phoneOut(phone);
        book.push_back(std::pair(persOut, phoneOut));
    }

    file.close();
}

std::ostream& operator<<(std::ostream& out, const PhoneBook& phon){
    for(const auto& it : phon.book){
        out << "Name: " << it.first;
        out << "Phone: " << it.second << std::endl;
    }
    return out;
}

void PhoneBook::SortByName(){
    std::sort(book.begin(), book.end(), [](std::pair<Person, PhoneNumber> first, std::pair<Person, PhoneNumber> second){
        return first.first < second.first;
    });
}

void PhoneBook::SortByPhone(){
    std::sort(book.begin(), book.end(), [](std::pair<Person, PhoneNumber> first, std::pair<Person, PhoneNumber> second){
        return first.second < second.second;
    });
}

std::tuple<std::string, PhoneNumber> PhoneBook::GetPhoneNumber(const std::string& name){
    unsigned int countPerson = 0;
    PhoneNumber number;
    for(auto& it : book)
        if((it.first.getLastName()) == name){
            ++countPerson;
            number = it.second;
        }
    if(countPerson == 1) return std::make_tuple("", number);
    if(countPerson > 1)  return std::make_tuple("found more than 1", PhoneNumber());
    return std::make_tuple("not found", PhoneNumber());
}

void PhoneBook::ChangePhoneNumber(const Person& pers, const PhoneNumber& phon){
    for(auto& it : book){
        if(it.first == pers){
            it.second = phon;
        }
    }
}
