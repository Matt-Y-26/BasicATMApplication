#ifndef ATM_H_INCLUDED
#define CALCULATOR_H_INCLUDED
#include <iostream>

bool signed_inflag;
struct user {
        std::string ID;
        std::string pass;
        int balance;
};

void login();
bool validate(std::string ID, std::string pass);
user read (std::string id, std::string password, int option);
void options(std::string id);
user getvalues (std::string id, std::string password);
user readoptions (std::string id, std::string password);

#endif
