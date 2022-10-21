#ifndef _STAFF_
#define _STAFF_


#include <string>
#include <iostream>
using namespace std;

class Staff
{
    private: 
        string ID;
        string name;
        string dob;
        string address;
        string phoneNumber;
        string gender;
        string salary;    
    public:

    
        Staff();
        Staff(string, string, string, string, string, string,string);
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
        void setSalary(const string& );
        const string& getSalary();
        void show();
};


#endif