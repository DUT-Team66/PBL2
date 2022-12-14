#ifndef _STAFF_
#define _STAFF_

#include "PhoneManager.h"
#include "OrderManager.h"
#include "CustomerManager.h"
#include "MyLib.h"
#include "Account.h"
#include <string>
#include <iostream>
using namespace std;
class PhoneManager; 
class OrderManager;
class CustomerManager;

class Staff
{
    protected: 
        string name;
        string ID;
        string gender;
        string dob;
        string phoneNumber;
        string address;
        int salary;    
        Account account;
        PhoneManager *managePhone;
        OrderManager *manageOrder;
        CustomerManager *manageCustomer;
    public:

    
        Staff();
        Staff(string, string, string, string, string, string,string,string);
        ~Staff();

        void setID(const string&);
        const string& getID();
        void setName(const string&);
        const string& getName();
        void setDob(const string&);
        const string& getDob();
        void setAddress(const string& );
        const string& getAddress();
        void setPhoneNumber(const string&);
        const string& getPhoneNumber();
        void setGender(const string& );
        const string& getGender();
        void setSalary(const int&);
        const int& getSalary();
        void setUsername(const string&);
        const string& getUsername() const;
        void setPassword(const string&); 
        const string& getPassword() const;
        void setPhoneManager(PhoneManager&);
        const PhoneManager& getPhoneManager() const;
        void setOrderManager(OrderManager&);
        void setCustomerManager(CustomerManager&);
        
        void show(); // show staff information
        void Menu(); // staff route
    
        void setInfo(); // lay thong tin tu ban phim
        void UpdateAllFiles(); // update phone.txt


};      


#endif