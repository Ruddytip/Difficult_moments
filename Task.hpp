#pragma once
#include <string> // Для std::string
#include <vector> // Для std::vector
#include <fstream> // Для std::ostream, std::ofstream, std::ifstream

// Task 1. Установить библиотеку protobuf.

// Task 2. С помощью компилятора protobuf в отдельном пространстве имен сгенерировать классы:
// a. FullName с полями имя, фамилия, отчество (отчество опционально).
// b. Student с полями полное имя, массив оценок, средний балл.
// c. StudentsGroup с полем массив студентов.

// Пункт "c" реализован в файле Task3.hpp

namespace Task{

    // Абстрактный класс сохранения/загрезки
    class SL{
    public:
        virtual void save(const std::string& file) = 0;
        virtual void save(std::ofstream& out)      = 0;
        virtual void load(const std::string& file) = 0;
        virtual void load(std::ifstream& in)       = 0;
    };

    class FullName : public SL{
    private:
        std::string name; // Имя
        std::string surname; // Фамилия
        std::string patronymic; // Отчество
    public:
        FullName();
        FullName(const std::string _n, const std::string _s, const std::string _p);
        void save(const std::string& file);
        void save(std::ofstream& out);
        void load(const std::string& file);
        void load(std::ifstream& in);
        bool operator==(const FullName& FN);
        friend std::ostream& operator<<(std::ostream& out, const FullName& FN){
            out << "Name: ";
            out << FN.surname << " ";
            out << FN.name << " ";
            out << FN.patronymic << std::endl;
            return out;
        }
    };

    class Student : public SL{
    private:
        FullName name; // Имя
        std::vector<double> evaluations; // Массив оценок
        double avgEval; // Средний балл
    public:
        Student();
        Student(const FullName& _n, const std::vector<double>& _e);
        FullName getName() const;
        double getAVG() const;
        void save(const std::string& file);
        void save(std::ofstream& out);
        void load(const std::string& file);
        void load(std::ifstream& in);
        friend std::ostream& operator<<(std::ostream& out, const Student& s){
            out << s.name << "Evaluations: ";
            for(auto it = s.evaluations.begin(); it != s.evaluations.end(); ++it)
                out << *it << ( it != s.evaluations.end() - 1 ? ", " : "\n");
            out << "AVG evaluation: " << s.avgEval << std::endl;
            return out;
        }
    };

};