#include <iostream>
#include "atm.h"
#include <fstream>
//#include "validate.cpp"

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

//Login
void login(){
        //get id and pass
        std::string ID, pass;
        std::cout<<"Please input your ID"<<std::endl;
        std::getline (std::cin,ID);
        std::cout<<"Please input your your password"<<std::endl;
        std::getline (std::cin,pass);

        if(validate(ID,pass))
        //if(true)
        {

        }
        else
        {
                std::cout<<"Error. Incorrect Password. Signing out"<<std::endl;
        }
        //remove this later
        exit(0);
}

//create struct for user
struct user {
        std::string ID;
        std::string pass;
        int balance;
};

//Validate user
bool validate(std::string id, std::string password)
{
        //read from file, see if id and password are good
        if(id=="liam" && password == "password")
        {
                return true;
        }
        else
        {
                return false;
        }
}

//read data from users account
//password will be optional
int read(std::string id, std::string password)
{
        std::ifstream readfile;
        readfile.open("accounts.txt");
        std::string placeholder;

        while(std::getline(readfile, placeholder)) {
                //compare and stuff
                return 0; //remove this later
        }

        return 0;

}


//Options Menu withdraw/deposit
void options(std::string id)
{
        std::cout<<"Enter 1 to deposit and enter 2 to withdraw"<<std::endl;
        return;

}
