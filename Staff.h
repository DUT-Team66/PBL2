#include <string>
#include <iostream>
using namespace std;

class Staff
{
    private: 
        string staffID;
        string staffName;
        string dob;
        string address;
        string phoneNumber;
        string gender;
        string salary;    
    public:

    
        Staff();
        Staff(string, string, string, string, string, string,string);
        ~Staff();
        void setStaffID(const string&);
        const string& getStaffID();
        void setStaffName(const string&);
        const string& getStaffName();
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
        void Show();
};
