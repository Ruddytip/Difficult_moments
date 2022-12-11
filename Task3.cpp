#include "Task3.hpp"
#include <algorithm> // Для std::count_if
#include "Timer.hpp" // Для Timer

const std::string vowel_letters = "AEIOUYaeiouy";

unsigned int count_if_find(const std::string& str){
    return std::count_if(str.begin(), str.end(), [](const char& c){
        return (vowel_letters.find(c) != std::string::npos);
    });
}

unsigned int count_if_for(const std::string& str){
    return std::count_if(str.begin(), str.end(), [](const char& c){
        for(const auto& it : vowel_letters)
            if(it == c) return true;
        return false;
    });
}

unsigned int for_find(const std::string& str){
    unsigned int count = 0;
    for(const auto& it : str)
        if(vowel_letters.find(it) != std::string::npos) ++count;
    return count;
}

unsigned int for_for(const std::string& str){
    unsigned int count = 0;
    for(const auto& it1 : str)
        for(const auto& it2 : vowel_letters)
            if(it1 == it2) ++count;
    return count;
}
