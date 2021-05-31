#include "atm.h"
#include <iostream>


int main(int agrc, char *agrv[])
{
        std::string input = "";
        //Call loop func until exit
        //
        //init ids and passwds?
        while(1)
        {
        //switch statement might be better, but for now just ifelse
        std::cout<<"Please type 'login' or 'exit'"<<std::endl;
        std::getline (std::cin,input);
        if(input=="login"){
                login();
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
        //get id and pass
        std::string ID, pass;
        std::cout<<"Please input your ID"<<std::endl;
        std::getline (std::cin,ID);
        std::cout<<"Please input your your password"<<std::endl;
        std::getline (std::cin,pass);

        if(validate(ID,pass))
        {

        }
        else
        {
                std::cout<<"Error. Incorrect Password. Signing out"<<std::endl;
        }
        //remove this later
        exit(0);
}

bool validate(std::string ID,std::string pass)
{
        //obviously, change this later
        return true;
}
