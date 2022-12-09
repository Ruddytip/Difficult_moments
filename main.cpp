// Имеется база сотрудников и номеров их телефонов.
// Требуется написать соответствующие структуры для хранения данных, и заполнить контейнер записями из базы.
// Затем необходимо реализовать методы обработки данных, а также вывести на экран всю необходимую информацию.
// Важно! Имена переменным, классам и функциям давайте осознанные, состоящие из слов на английском языке.
#include <iostream>
#include "Person.hpp"      // Task 1
#include "PhoneNumber.hpp" // Task 2
#include "PhoneBook.hpp"   // Task 3
#include <tuple>

int main(){

    // Task 1 ====================
    std::cout << "Task 1:\n";
    Person gena("Gena", "Chpek", "Otchestvo");
    Person olya("Olya", "Chpekovskiy");
    std::cout << gena << std::endl;
    std::cout << olya << std::endl;
    std::cout << (gena == olya) << std::endl;
    std::cout << std::endl;
    // ===========================

    // Task 2 ====================
    std::cout << "Task 2:\n";
    PhoneNumber My("+7(999)7558844 216");
    PhoneNumber Mem("+8(800)5553535");
    std::cout << "My: " << My << std::endl;
    std::cout << "Mem: " << Mem << std::endl;
    std::cout << std::endl;
    // ===========================

    // Task 3 ====================
    std::cout << "Task 3:\n";
    std::ifstream file("PhoneBook.txt"); // путь к файлу PhoneBook.txt
    PhoneBook book(file);
    std::cout << book;
    std::cout << "------SortByPhone-------" << std::endl;
    book.SortByPhone();
    std::cout << book;
    std::cout << "------SortByName--------" << std::endl;
    book.SortByName();
    std::cout << book;
    std::cout << "-----GetPhoneNumber-----" << std::endl;
    // лямбда функция, которая принимает фамилию и выводит номер телефона
    // человека, либо строку с ошибкой
    auto print_phone_number = [&book](const std::string& surname){
        std::cout << surname << "\t";
        auto answer = book.GetPhoneNumber(surname);
        if(std::get<0>(answer).empty())
            std::cout << std::get<1>(answer);
        else
            std::cout << std::get<0>(answer);
        std::cout << std::endl;
    };
    // вызовы лямбды
    print_phone_number("Ivanov");
    print_phone_number("Petrov");
    std::cout << "----ChangePhoneNumber----" << std::endl;
    book.ChangePhoneNumber(Person{ "Kotov", "Vasilii", "Eliseevich" },
    PhoneNumber{7, 123, "15344458", std::nullopt});
    book.ChangePhoneNumber(Person{ "Mironova", "Margarita", "Vladimirovna" },
    PhoneNumber{ 16, 465, "9155448", 13 });
    std::cout << book;
    std::cout << std::endl;
    // ===========================

    return 0;
}