#ifndef ATM_H_INCLUDED
#define CALCULATOR_H_INCLUDED
#include <iostream>

struct user {
        std::string ID;
        std::string pass;
        int balance;
};

void login();
bool validate(std::string ID, std::string pass);
user read (std::string id, std::string password);
void options(std::string id);

#endif
