#pragma once
#include "Task.hpp"

// Task 3. Создать класс StudentsGroup, который реализует интерфейсы:

class IRepository {
    virtual void Open() = 0; // бинарная десериализация в файл virtual void Save() = 0; // бинарная сериализация в файл
};

class IMethods {
    virtual double GetAverageScore(const Task::FullName& name) = 0;
    virtual std::string GetAllInfo(const Task::FullName& name) = 0;
    virtual std::string GetAllInfo() = 0;
};

namespace Task{
    class StudentsGroup{
    private:
        std::vector<Task::Student> students; // Массив студентов
    public:
        StudentsGroup();
        StudentsGroup(const std::vector<Task::Student>& _s);
        void Save();
        void Open();
        double GetAverageScore(const Task::FullName& name);
        std::string GetAllInfo(const Task::FullName& name);
        std::string GetAllInfo();
    };

    void generate_Group_bin(const int& size_group);
};