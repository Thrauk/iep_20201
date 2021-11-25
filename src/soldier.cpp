#include<iostream>
#include<stdlib.h>
#include "../inc/soldier.hpp"

// Assigment operator
Soldier& Soldier::operator= (const Soldier& rhs) {
    if(&rhs != this) {
        this->name = rhs.name;
        this->age = rhs.age;
        this->squad = rhs.squad;
    }
    else {
        std::cout << "Self assigment!\n";
    }
    return *this;
}

void Soldier::display () {
    std::cout << 
            "Soldier element has the following: \n" <<
            "\tName: " << this->name << "\n" <<
            "\tSquad: " << this->squad << "\n" <<
            "\tAge: " << this->age << "\n";
}


/*
class Soldier {
    public:
        std::string name;
        std::string squad;
        int age;

        Soldier(std::string name, std::string squad, int age) : 
            name(name), squad(squad), age(age) {}

        Soldier():name("N/A"),squad("N/A"),age(18) {}
    
    Soldier& operator = (const Soldier& rhs) {
        if(&rhs != this) {
            this->name = rhs.name;
            this->age = rhs.age;
            this->squad = rhs.squad;
        }
        else {
            std::cout << "Self assigment!";
        }
		return *this;
	}
};*/
