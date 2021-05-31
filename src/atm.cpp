#include <iostream>
#include "atm.h"
#include <fstream>
#include <stack>
#include <string>
//#include "validate.cpp"

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


//Options Menu withdraw/deposit
void options(std::string id)
{
        std::cout<<"Enter 1 to deposit and enter 2 to withdraw"<<std::endl;
        return;

}
