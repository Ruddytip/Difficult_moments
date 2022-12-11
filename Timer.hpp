#pragma once
#include <chrono>  // Для std::chrono
#include <string>  // Для std::string
#include <ostream> // Для std::ostream

class Timer{
private:
    using clock_t = std::chrono::high_resolution_clock;
    using second_t = std::chrono::duration<double, std::ratio<1>>;
    std::string m_name;
    std::chrono::time_point<clock_t> m_beg;
    double elapsed() const;
public:
    //конструктор по умолчанию
    Timer() = delete;
    // конструктор копирования
    Timer(const Timer& other) = delete;
    // копирующий оператор присваивания
    void operator=(const Timer& other) = delete;
    // конструктор перемещения
    Timer(Timer&& other) = delete;
    // перемещающий оператор присваивания
    void operator=(Timer&& other) = delete;
    // 
    Timer(std::string name);
    // 
    friend std::ostream& operator<<(std::ostream& out, const Timer& timer);
};