#include<iostream>
#include<stdlib.h>
#include "../inc/soldier.hpp"
#include "../inc/navy.hpp"
#include "../inc/infantry.hpp"

int main() {
    Soldier soldier("Jon Smith","Demon Dogs", 18);
    Soldier soldier2("Karl Marx", "Scorpions", 35);

    Navy navy("Jerry Mcguire", "Sea Lions", 18, "Colt45");
    Navy navy2("Raj Guadalajara", "Demon Dogs", 25, "Glock");

    Infantry infantry("Jim Carrey", "Cobra", 22, "AR-15");
    Infantry infantry2("Clayton Jones", "Bravo-6", 23, "M4A1");

    // self assign soldier
    soldier = soldier;
    soldier.display();

    // assign soldier
    soldier = soldier2;
    soldier.display();
    
    // self assign navy
    navy=navy;
    navy.display();

    // assign navy
    navy = navy2;
    navy.display();
    
    // assign navy to soldier
    soldier = navy;
    soldier.display();

    // self assignt infantry
    infantry = infantry;
    infantry.display();

    // assign infantry
    infantry = infantry2;
    infantry.display();

    return 0;
}