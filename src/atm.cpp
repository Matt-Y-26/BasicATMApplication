#include "atm.h"
#include <iostream>


int main(int agrc, char *agrv[])
{
        std::string input = "";
        //Call loop func until exit
        while(1)
        {
        //switch statement might be better, but for now just ifelse
        std::cout<<"Please type 'login' or 'exit'"<<std::endl;
        std::getline (std::cin,input);
        if(input=="login"){

        }
        else if(input=="exit"){
                return 0;
        }
        else
        {
                std::cout<<"Error: Not login or exit. Try Again"<<std::endl;
        }
        }
}

void login(){

}
