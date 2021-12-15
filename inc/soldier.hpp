#include<stdlib.h>
#include<iostream>
#include "objective.hpp"
#include<memory>

#ifndef SOLDIER_H
#define SOLDIER_H

class Soldier {
    public:
        std::string name;
        std::string squad;
        int age;
        std::shared_ptr<Objective> objectivePtr;
        
        Soldier(std::string name, std::string squad, int age) : 
            name(name), squad(squad), age(age) {}

        Soldier():name("N/A"),squad("N/A"),age(18) {}

        Soldier& operator= (const Soldier& rhs);

        void display();

};

#endif