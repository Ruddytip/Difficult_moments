#include "Task3.hpp"
#include <vector>   // Для std::vector
#include <map>      // Для std::multimap
#include <string>   // Для std::string
#include <thread>   // Для std::thread
#include <mutex>    // Для std::mutex
#include <iostream> // Для std::cout

std::mutex mtx;

void Task3(){
    std::multimap<int, std::string> home;
    std::vector<std::string> things{"table", "chair", "armchair", "wardrobe", "bed"};

    std::thread Owner([&](){
        while(true){
            const int maxCost = 1000;
            std::string str = things[rand() % things.size()];
            int cost = rand() % maxCost;
            mtx.lock();
            home.insert(std::pair<int, std::string>(cost, str));
            std::cout << "The owner added a " << str << " worth " << cost << std::endl;
            mtx.unlock();
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        }
    });

    std::thread Thief([&](){
        while(true){
            mtx.lock();
            if(!home.empty()){
                auto it = --home.end();
                int cost = it->first;
                std::string str = it->second;
                home.erase(it);
                std::cout << "The thief stole a " << str << " worth " << cost << std::endl;
            }
            mtx.unlock();
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }
    });

    Owner.join();
    Thief.join();
}