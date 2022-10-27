#ifndef BANKCUSTOMER_H
#define BANKCUSTOMER_H
#include <iomanip>
#include <stdexcept>
#include <sstream>
#include <string>
#include "CustomerAccount.h"

class Customer{
    public:
        Customer();
        Customer(Account accountIn, std::string& name, std::string& address1, std::string& address2, std::string& cityph, std::string& provinceph, std::string& postal, int work, int home, int cell){
            setAccount(accountIn);
            setFullName(name);
            setAddressLine1(address1);
            setAddressLine2(address2);
            setCity(cityph);
            setProvince(provinceph);
            setPostalCode(postal);
            setWorkPhone(work);
            setHomePhone(home);
            setCellPhone(cell);
        };

        //set/get customer account
        void setAccount(Account accountIn){
            Account = accountIn;
        }


        //set/get full name
        bool setFullName(std::string& name){
            if(name.size() < 6){
                throw std::invalid_argument("Name given is below required length of 6 characters.");
                return false;
            }
            else{fullName = name;
                 return true;}
        };
        std::string getFullName() const {return fullName;};

        //set/get address line 1
        bool setAddressLine1(std::string& address1){
            if(address1 == ""){
                throw std::invalid_argument("Address line 1 cannot be left empty.");
                return false;
            }
            else{addressLine1 = address1;
                 return true;}
        };
        std::string getAddressLine1() const {return addressLine1;};

        //set/get address line 2
        bool setAddressLine2(const std::string& address2){
            addressLine2 = address2;
            return true;
        };
        std::string getAddressLine2() const {return addressLine2;};

        //set/get City
        bool setCity(const std::string& cityph){
            city = cityph;
            return true;
        };
        std::string getCity() const {return city;};
        
        //set/get Province
        bool setProvince(const std::string& provinceph){
            province = provinceph;
            return true;
        };
        std::string getProvince() const {return province;};

        //set/get Postal Code
        bool setPostalCode(const std::string& postal){
            postalCode = postal;
            return true;
        };
        std::string getPostalCode() const{return postalCode;};

        //set/get Work Phone
        bool setWorkPhone(int work){
            if(work == 0 && homePhone == 0 && cellPhone == 0){
                throw std::invalid_argument("At least one phone number must be given");
                return false;
            }
            else{workPhone = work; return true;}
        };
        int getWorkPhone() {return workPhone;};

        //set/get Home Phone
        bool setHomePhone(int home){
            if(workPhone == 0 && home == 0 && cellPhone == 0){
                throw std::invalid_argument("At least one phone number must be given");
                return false;
            }
            else{homePhone = home; return true;}
        };
        int getHomePhone() {return homePhone;};

        //set/get Cell Phone
        bool setCellPhone(int cell){
            if(workPhone == 0 && homePhone == 0 && cell == 0){
                throw std::invalid_argument("At least one phone number must be given");
                return false;
            }
            else{cellPhone = cell; return true;}
        };
        int getCellPhone() {return cellPhone;};

    private:
        Account Account;
        std::string fullName;
        std::string addressLine1;
        std::string addressLine2;
        std::string city;
        std::string province;
        std::string postalCode;
        int workPhone;
        int homePhone;
        int cellPhone;

};

#endif