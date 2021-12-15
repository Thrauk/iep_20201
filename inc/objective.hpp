#include<stdlib.h>
#include<iostream>

#ifndef OBJECTIVE_H
#define OBJECTIVE_H

class Objective {
    public:
        std::string name;
        
        Objective(std::string name) : 
            name(name) {}

        Objective():name("N/A") {}


};

#endif