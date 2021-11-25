#include "soldier.hpp"
#include<stdlib.h>
#include<iostream>

#ifndef INFANTRY_H
#define INFANTRY_H

class Infantry: public Soldier {
    public:
        std::string weapon;

        Infantry(std::string name, std::string squad, int age, std::string weapon) : 
            Soldier(name,squad,age), weapon(weapon) {}

        Infantry():Soldier(),weapon("N/a") {}

        Infantry& operator= (const Infantry& rhs);

        void display();
    
};

#endif