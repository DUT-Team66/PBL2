#ifndef _CUSTOMERMANAGER_
#define _CUSTOMERMANAGER_
#include "Customer.h"
#include "MyLib.h"

class CustomerManager
{
    private: 
        List<Customer> list;
    public:        
        CustomerManager();
        ~CustomerManager();
        int GetLength();
        void Add(const Customer& s);
        void Delete(string);
        void Search();
        void Show(); 
        void setInfo(Customer&);
        void LoadData();
        void UpdateFile();
        void Menu();
        const CustomerManager& operator=(const CustomerManager& );
};
#endif