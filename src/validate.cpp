#include <string>
#include "atm.h"


struct person {
        std::string ID;
        std::string pass;
        int balance;
};

bool validate(std::string ID, std::string pass)
{
        return true;
}