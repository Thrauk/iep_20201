#include<iostream>
#include<stdlib.h>
#include "../inc/soldier.hpp"
#include "../inc/navy.hpp"


// Navy assigment operator
Navy& Navy::operator= (const Navy& rhs) {
    if(&rhs != this) {
        // Call parent class assigment operator
        Soldier::operator=(rhs);
        this->weapon = rhs.weapon;
    }
    else {
        std::cout << "Self assigment!\n";
    }
    return *this;
}

void Navy::display () {
    std::cout << 
            "Navy element has the following: \n" <<
            "\tName: " << this->name << "\n" <<
            "\tSquad: " << this->squad << "\n" <<
            "\tAge: " << this->age << "\n" <<
            "\tWeapon: " << this->weapon << "\n";
}

/*
class Navy: public Soldier {
    public:
        std::string weapon;

        Navy(std::string name, std::string squad, int age, std::string weapon) : 
            Soldier(name,squad,age), weapon(weapon) {}

        Navy():Soldier(), weapon("N/A") {}
    
    Navy& operator = (const Navy& rhs) {
        if(&rhs != this) {
            Soldier::operator=(rhs);
            this->weapon = rhs.weapon;
        }
        else {
            std::cout << "Self assigment!";
        }
		return *this;
	}
};
*/