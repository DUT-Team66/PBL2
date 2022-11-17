#ifndef _PHONE_
#define _PHONE_

#include <string>
#include <iostream>
using namespace std;
class Phone
{
    private: 
        string phoneName;//b
        string phoneID;//a
        string brand;//c
        string processor;//e
        string RAM_ROM; // d
        string display; //h 
        string camera; // g
        int entryPrice;//x
        int salePrice;//y
        int remainingAmount;//z
    public:
        Phone();
        Phone(string, string, string, string,string, string, string,int,int,int);
        ~Phone();

        void setPhoneID(const string& );
        const string& getPhoneID();

        void setPhoneName(const string& );
        const string& getPhoneName();

        void setBrand(const string& );
        const string& getBrand();

        void setRAM_ROM(const string& );
        const string& getRAM_ROM();

        void setProcessor(const string& );
        const string& getProcessor();

        void setDisplay(const string& );
        const string& getDisplay();

        void setCamera(const string& );
        const string& getCamera();

        void setEntryPrice(const int&);
        const int& getEntryPrice() const;

        void setSalePrice(const int&);
        const int& getSalePrice() const;

        void setRemainingAmount(const int&);
        const int& getRemainingAmount() const;
        
        void setInfo();
        void showForCustomer();   
        void showForStaff();   
        
};


#endif