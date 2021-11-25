#include<iostream>
#include<stdlib.h>
#include "../inc/soldier.hpp"
#include "../inc/infantry.hpp"

// Assigment operator without the use of parent
Infantry& Infantry::operator= (const Infantry& rhs) {
        if(&rhs != this) {
            this->name = rhs.name;
            this->age = rhs.age;
            this->squad = rhs.squad;
            this->weapon = rhs.weapon;
        }
        else {
            std::cout << "Self assigment!\n";
        }
		return *this;
}

void Infantry::display () {
    std::cout << 
            "Infantry element has the following: \n" <<
            "\tName: " << this->name << "\n" <<
            "\tSquad: " << this->squad << "\n" <<
            "\tAge: " << this->age << "\n" <<
            "\tWeapon: " << this->weapon << "\n";
}

/*
class Infantry: public Soldier {
    public:
        std::string weapon;

        Infantry(std::string name, std::string squad, int age, std::string weapon) : 
            name(name), squad(squad), age(age), weapon(weapon) {}

        Infantry():name("N/A"),squad("N/A"),age(18),weapon("N/a") {}
    
    Infantry& operator = (const Infantry& rhs) {
        if(&rhs != this) {
            this->name = rhs.name;
            this->age = rhs.age;
            this->squad = rhs.squad;
            this->weapon = rhs.weapon;
        }
        else {
            std::cout << "Self assigment!";
        }
		return *this;
	}
};*/
