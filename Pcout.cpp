#include "Pcout.hpp"
#include <iostream> // Для std::cout
#include <mutex>    // Для std::mutex

P_cout pcout;
std::mutex mutex_pcout;

P_cout& P_cout::operator<<(const int& in){
    std::lock_guard<std::mutex> lg(mutex_pcout);
    std::cout << "Thread " << in << " printing!" << std::endl;
    return *this;
}

P_cout& P_cout::operator<<(const std::string& in){
    std::lock_guard<std::mutex> lg(mutex_pcout);
    std::cout << in;
    return *this;
}

void print_to_pcout(const int& in){
    pcout << in;
}