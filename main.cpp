#include <iostream> // Для std::cout
#include <string>   // Для std::string
#include <vector>   // Для std::vector
#include <set>      // Для std::set
#include <map>
#include <sstream>

// Task 1. Создать шаблонную функцию, которая принимает итераторы на начало и конец последовательности слов,
// и выводящую в консоль список уникальных слов (если слово повторяется больше 1 раза, то вывести его надо один раз).
// Продемонстрировать работу функции, передав итераторы различных типов.
template<typename iterator>
void printUniqueWords(iterator begin, iterator end){
    std::set<std::string> out;
    for(auto it = begin; it != end; ++it) out.insert(*it);
    for(const auto& it : out) std::cout << it << " "; std::cout << std::endl;
}

// Task 2. Используя ассоциативный контейнер, напишите программу,
// которая будет считывать данные введенные пользователем из стандартного потока ввода и разбивать их на предложения.
// Далее программа должна вывести пользователю все предложения,
// а также количество слов в них, отсортировав предложения по количеству слов.
void Task2(){
    std::string str;
    std::getline(std::cin, str);
    std::map<int, std::string> suggestions;
    int index = 1; // Номер предложения
    std::stringstream iss(str); // Весь текст

    std::string suggestion("");
    while(!iss.eof()){
        std::string word;
        iss >> word;
        suggestion+=word;
        suggestion+=" ";
        if(word.find('.') != std::string::npos){
            suggestions.insert({ index++ , suggestion });
            suggestion = "";
        }
    }
    std::cout << std::endl;
    for(const auto& it : suggestions) std::cout << it.first << ": " << it.second << std::endl;
}

int main(){
    
    // Task 1 ====================
    std::cout << "Task 1:" << std::endl;
    std::vector<std::string> vec = { "test", "test1", "test2", "test", "test1"};
    std::cout << "The original words: ";
    for(const auto& it : vec) std::cout << it << " ";
    std::cout << "\nThe unique words:   ";
    printUniqueWords(vec.begin(), vec.end());
    std::cout << std::endl;
    // ===========================

    // Task 2 ====================
    std::cout << "Task 2:" << std::endl;
    // Предполагается, что обозначением конца строки является только точка.
    // Тестовый текст для проверки:
    // Advertisers study how people learn so that they can 'teach' them to respond to their advertising. They want us to be interested, to try something, and then to do it again. These are the elements of learning: interest, experience and repetition. If an advert can achieve this, it is successful. If an advert works well, the same technique can be used to advertise different things. So, for example, in winter if the weather is cold and you see a family having a warming cup of tea and feeling cosy, you may be interested and note the name of the tea ... Here the same technique is being used as with the cool, refreshing drink.
    Task2();
    std::cout << std::endl;
    // ===========================

    return 0;
}