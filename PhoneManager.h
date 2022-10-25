
#ifndef _PHONEMANAGER_
#define _PHONEMANAGER_
#include "Phone.h"
#include "ShoppingList.h"
class PhoneManager
{
    private: 
        Phone *p;
        int n;
    public:
        //Khong co SV
        PhoneManager();
        ~PhoneManager();
        void Add(const Phone& s);
        void Delete(string);
        void Search(string);
        void Update(string);
        void Show(); // show for staff

        void ShowTable(); // show table for customer
        void Show(int); // show 1 phone information


        int GetLength();
        const string& getPhoneID(int);
        const int& getPhonePrice(int);
        void LoadData();
        void Menu();

        const PhoneManager& operator=(const PhoneManager& );
};
#endif