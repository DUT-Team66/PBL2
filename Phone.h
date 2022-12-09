#ifndef _PHONE_
#define _PHONE_

#include <string>
#include <iostream>
using namespace std;
class Phone
{
    private: 
        string phoneName;//a
        string phoneID;//b
        string brand;//c
        string processor;//d
        string RAM_ROM; // e
        string display; //g
        string camera; // h
        int entryPrice;//i
        int salePrice;//j
        int remainingAmount;//k
    public:
        Phone();
        Phone(string, string, string, string,string, string, string,int,int,int);
        ~Phone();

        void setID(const string& );
        const string& getID();

        void setName(const string& );
        const string& getName();

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
        void show() {
            cout << "phone show" << "\n";
        } 
        
};


#endif