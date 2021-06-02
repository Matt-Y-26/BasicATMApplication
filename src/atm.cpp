#include <iostream>
#include "atm.h"
#include <fstream>
#include <stack>
#include <string>

//Matt's
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
            std::cout<<"Welcome"<<std::endl;
            options(ID);
            signed_inflag=true;
        }
        else
        {
                std::cout<<"Error. Incorrect Password. Signing out"<<std::endl;
                signed_inflag=false;
        }

}

//Validate user
bool validate(std::string id, std::string password)
{
        //read from file, see if id and password are good
        user U = read(id,password,0);
        if(U.ID==id && U.pass == password)
        {
                return true;
        }
        return false;
}

//read data from users account

user read(std::string id, std::string password, int option)
{
        std::ifstream readfile;
        readfile.open("accounts.txt");
        std::string placeholder;

        user U;
        std::stack <std::string> S;
        //goes over the entire line
        while(std::getline(readfile, placeholder)) {
                //go over all the characters
                std::string temp;
                int count=0;
                for(int x=0;x<placeholder.size();x++)
                {
                    //If it equals space
                    if(placeholder[x]==',')
                    {
                        count++;
                        S.push(temp);
                        temp="";
                    }
                    //else add it to temp
                    else{
                        temp.append(1, placeholder[x]);
                    }
                }
                //this is an ugly way, fix this
                U.balance=std::stoi(S.top());
                S.pop();
                U.pass=S.top();
                S.pop();
                U.ID=S.top();
                S.pop();

                if(U.pass==password&&U.ID==id) //found it?
                {
                    readfile.close();
                    return U;
                }
                //else keep going
        }

        readfile.close();
        return U;

}

//G's code
//Options Menu withdraw/deposit
void options(std::string id)
{
        int optionsCheck = 0; // Variable used to check if options should be exited
        while(optionsCheck == 0) // Loop until optionsCheck is not 0
        {
                std::string input = ""; // input is the users input for their action [deposit, widthdraw, or exit]
                std::cout<<"Enter 1 to deposit, enter 2 to withdraw, and enter 3 to exit"<<std::endl;
                std::getline(std::cin,input); //Store users response in input

                if(input == "1") // If the user selected deposit
                {
                        std::cout<<"***INIT:deposit***"<<std::endl;
                        //call deposit function
                        std::cout<<"***DONE:deposit***"<<std::endl;

                        //maybe make the following code into a function, as its used in deposit and withdraw

                        int depCheck = 0; // Variable used to check if the person wants to continue transactions or not (Not really necessary now that i think about it)
                        while (depCheck ==0)    // check if depCheck is unchanged
                        {
                                std::cout<<"Would you like to make more transactions?"<<std::endl;
                                std::cout<<"Enter 1 for yes, and 2 for no"<<std::endl;
                                std::string depInput = ""; //more transactions?
                                std::getline(std::cin,depInput);
                                if (depInput=="1") //If there are more transactions to complete, do not exit options Check loop
                                {
                                        depCheck=1;
                                        // std::cout<<"keep looping options and stop looping dep"<<std::endl;
                                }
                                else if(depInput=="2") //If there are no more transactions to complete,  exit options Check loop
                                {
                                        optionsCheck=1;
                                        depCheck=1;
                                        // std::cout<<"stop looping options and dep"<<std::endl;
                                }
                                else
                                {
                                        std::cout<<"***Error: Please enter '1' or '2'***"<<std::endl;
                                        // if there is any other inptu, ask for a valid input
                                }
                        }
                }
                else if (input == "2")
                {
                        std::cout<<"***INIT:withdraws***"<<std::endl;
                        //call withdraw function
                        std::cout<<"***DONE:withdraws***"<<std::endl;
                        int withCheck = 0;
                        while (withCheck ==0)
                        {
                                std::cout<<"Would you like to make more transactions?"<<std::endl;
                                std::cout<<"Enter 1 for yes, and 2 for no"<<std::endl;
                                std::string withInput = "";
                                std::getline(std::cin,withInput);
                                if (withInput=="1")
                                {
                                        withCheck=1;
                                        // std::cout<<"keep looping options and stop looping widthdraw"<<std::endl;
                                }
                                else if(withInput=="2")
                                {
                                        optionsCheck=1;
                                        withCheck=1;
                                        // std::cout<<"stop looping options and withdraw"<<std::endl;
                                }
                                else
                                {
                                        std::cout<<"***Error: Please enter '1' or '2'***"<<std::endl;
                                }
                        }
                }
                else if (input == "3") //Exit
                {
                        optionsCheck=1;
                }
                else //Invalid entry check, keep looping
                {
                        std::cout<<"***Error: Invalid Entry***"<<std::endl;
                }
        }
        return;
}

void deposit(std::string id)
{
        //TODO
        return;
}


void withdraw(std::string id)
{
        //TODO
        return;
}

bool moreTransactions()
{
        bool b = false;
        //TODO make the withdraw + deposit continue check into 1 function,
                // change the int in withCheck and depCheck to bool
        return true;
}
