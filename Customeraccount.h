/*
This is incomplete. I had quite a bit of trouble despite going through the lecture notes repeatedly, in understanding how I am supposed to call the customerAccount class inside itself for subaccounts without initializing any objects. I have worked with structures before and have created programs with multiple sub classes in those projects, but I am still having difficulty understanding what is specifically being asked when what's being asked hasn't been something covered in excercise or lecture. I'm willing to put in the work and would love any help to perform above the standard.
*/
#ifndef CUSTOMERACCOUNT_H
#define CUSTOMERACCOUNT_H
#include <iostream>
#include <string>
#include <vector>
#include "Bankcustomer.h"

class Account{
    public:
        Account();
        Account(Customer Customer, int actNumIn, int created, int branch, const std::string& stat){
            setCustomer(Customer);
            setAccountNumber(actNumIn);
            setCreationDate(created);
            setAccountStatus(stat);
            setBranchNum(branch);

        };

        //set/get customer
        bool setCustomer(Customer Customer){
            accountOwner = Customer;
            return true;
        }
        string getCustomer(){
            return(accountOwner.getFullName());
        }

        //set/get accountNum
        bool setAccountNumber(int actNumIn){
            if(actNumIn == 0){
                std::cout<< "Account number required for account creation.\n";
                return false;
            }
            else{
                accountNumber = actNumIn;
                if(accountNumber == actNumIn){
                    return true;
                }
            }
        };
        int getAccountNumber(){return accountNumber;};

        //set/get accountStatus
        bool setAccountStatus(const std::string& stat){
            //determining if the account already is closed
            if(status == "closed" && (stat == "open" || stat == "frozen")){
                throw std::invalid_argument("A closed account cannot be changed to 'open' or 'frozen'");
                return false;
            }
            else {status = stat;}
            //incase stat is an invalid value or empty
            if(status != "open" || status != "closed" || status != "frozen"){
                status = "open";
            }
            if(status == stat || status == "open"){
                return true;
            }
        }
        std::string getAccountStatus(){return status;};

        //set/get creationDate
        bool setCreationDate(int created){
            creationDate = created;
            if(creationDate == created){
                return true;
            }
            else{return false;}
        }
        int getCreationDate(){return creationDate;}

        //set/get BranchNum
        bool setBranchNum(int branch){
            branchNum = branch;
            if(branchNum == branch){
                return true;
            }
            else{return false;}
        }
        int getBranchNum(){return branchNum;}

        //subAccount creation
        void newSubAccount(std::vector <subAccount> &heldAccounts){
            //create subAccount object
            subAccount newAccount;
            heldAccounts.push_back(newAccount);
            std::cout << "Account placed in position " << &heldAccounts.back() << endl;
        }

        void deleteAccount(std::vector <subAccount> &heldAccounts){
            if(heldAccounts.back().getTransactionFlag() == true){
                throw invalid_argument("Cannot delete an account that has been involved in an equation.\n");
            }
            else{
                heldAccounts.pop_back();
            }
        }

    private:
        Customer accountOwner;
        int accountNumber;
        int creationDate;
        int branchNum;
        std::string status;
        std::vector <subAccount> heldAccounts;
};

#endif