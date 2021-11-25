#include "soldier.hpp"
#include<stdlib.h>
#include<iostream>

#ifndef NAVY_H
#define NAVY_H

class Navy: public Soldier {
    public:
        std::string weapon;
        Navy(std::string name, std::string squad, int age, std::string weapon) : 
            Soldier(name,squad,age), weapon(weapon) {}

        Navy():Soldier(), weapon("N/A") {}

        Navy& operator= (const Navy& rhs);

        void display();
};

#endif