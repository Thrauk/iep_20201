#include<iostream>
#include<stdlib.h>
#include<memory>
#include "../inc/soldier.hpp"
#include "../inc/navy.hpp"
#include "../inc/infantry.hpp"
#include "../inc/objective.hpp"
#include "../inc/team_leader.hpp"
#include<mutex>
#include<thread>

std::mutex m;
std::string squad = "Initial squad";

void changeSquad(std::string new_squad_name)
{
    m.lock();
    std::cout<<"Changing soldier squad" << std::endl;
    squad = new_squad_name;
    std::cout<<"Name changed into " + new_squad_name << std::endl;
    m.unlock();
}

int main() {
    /* ---------------- UNIQUE PTR ---------------- */
    
    Team_Leader teamLeader1("Team1");
    Team_Leader teamLeader2("Team2");

    std::unique_ptr<Soldier> soldierLeader (new Soldier("Jon Smith","Demon Dogs", 18));

    // prints reference to the newly created Soldier object
    std::cout << soldierLeader.get() << std::endl;

    std::cout << std::endl;

    // We transfer the pointer reference to team's 1 pointer
    teamLeader1.soldierUniquePtr = std::move(soldierLeader);

    /*
        example output
        0x7fffe4866eb0
    */

    // Will display 0 (null) because the reference has been moved
    std::cout << soldierLeader.get() << std::endl;
    // Will display the original reference
    std::cout << teamLeader1.soldierUniquePtr.get() << std::endl;

    /*
        example outout
        0
        0x7fffe4866eb0
    */

    std::cout << std::endl;

    teamLeader2.soldierUniquePtr = std::move(teamLeader1.soldierUniquePtr);

    // Will display 0 (null) because the reference has been moved
    std::cout << soldierLeader.get() << std::endl;
    // Will display 0 (null) because the reference has been moved
    std::cout << teamLeader1.soldierUniquePtr.get() << std::endl;
    // Will display the original reference
    std::cout << teamLeader2.soldierUniquePtr.get() << std::endl;

    /*
        example output
        0
        0
        0x7fffe4866eb0
    */


    /* ---------------- SHARED PTR ---------------- */
    std::shared_ptr<Objective> objectivePtr1( new Objective("Capture enemy base"));
    
    Soldier soldier1("Karl Marx", "Scorpions", 35);
    Soldier soldier2("Jerry Mcguire", "Sea Lions", 18);
    Soldier soldier3("Raj Guadalajara", "Demon Dogs", 25);

    std::cout << std::endl;

    // should output 1
    std::cout << objectivePtr1.use_count() << std::endl; 

    soldier1.objectivePtr = objectivePtr1;

    // should output 2
    std::cout << objectivePtr1.use_count() << std::endl; 

    soldier2.objectivePtr = objectivePtr1;
    // should output 3
    std::cout << objectivePtr1.use_count() << std::endl; 

    soldier3.objectivePtr = objectivePtr1;
    // should output 4
    std::cout << objectivePtr1.use_count() << std::endl; 


    /* ---------------- MUTEX ---------------- */
    std::thread task1(changeSquad,"Koala fighters");
    std::thread task2(changeSquad, "Shadow force");

    task1.join();
    task2.join();

    return 0;
}