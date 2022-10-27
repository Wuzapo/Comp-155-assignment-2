#ifndef SUBACCOUNT_H
#define SUBACCOUNT_H
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include "Customeraccount.h"

class subAccount : Account{
    public: 
        subAccount(){
            setBalance(0);
        }
        subAccount(float setbal){
            setBalance(setbal);
        }

        //set/get balance
        bool setBalance(int setbal){
            int temp = balance;
            balance = setbal*100;
            if(balance < -2147482648 || balance > 2147483648){
                throw std::invalid_argument("Balance exceeding 2^31 by positive or negative. Such a number exceeds account memory allocation. Please enter a valid number.");
                balance = temp;
            }
            if(balance = setbal*100){
                setTransactionFlag();
                return true;
            }
        }
        int getBalance(){return balance;}

        //deposit/withdrawl function
        void deposit(int depositAmt){
            if(depositAmt > 0){
                int temp = balance;
                balance = balance + depositAmt*100;
                if(balance > 2147483648){
                    throw std::invalid_argument("Balance exceeding 2^31. Such a number is too large for this account. Please enter a valid number.");
                    balance = temp;
                }
            }
            else{
                throw std::invalid_argument("Invalid amount entered.");
            }
        }
        void withdrawl(int withAmt){
            if(withAmt > 0){
                int temp = balance;
                balance = balance - withAmt*100;
                if(balance < -2147482648){
                    throw std::invalid_argument("Balance exceeding -2^31. Such a number exceeds account memory allocation. Please enter a valid number.");
                    balance = temp;
                }
            }
            throw std::invalid_argument("Invalid amount entered.");
        }

        bool setTransactionFlag(){
            activated = true;
        }
        bool getTransactionFlag(){return(activated);}
    private:
        float balance;
        bool activated;
};





#endif