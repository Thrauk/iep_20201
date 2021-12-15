#include<stdlib.h>
#include<iostream>
#include<memory>
#include "soldier.hpp"

#ifndef TEAM_LEADER_H
#define TEAM_LEADER_H

class Team_Leader {
    public:
        std::string team_name;
        std::unique_ptr<Soldier> soldierUniquePtr;
        
        Team_Leader(std::string team_name) : 
            team_name(team_name) {}

        Team_Leader():team_name("N/A") {}

        void setUniquePtr(std::unique_ptr<Soldier>);

};

#endif