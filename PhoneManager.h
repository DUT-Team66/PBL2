
#ifndef _PHONEMANAGER_
#define _PHONEMANAGER_
#include "Phone.h"
#include "Goods.h"
#include "Order.h"

class PhoneManager
{
    friend class Admin;
    private: 
        struct Node{
            Phone data;
            Node* pNext;
        };
        Node *pHead;
        Node *pTail;
        int n;
    public:
        //Khong co SV
        PhoneManager();
        ~PhoneManager();
        int GetLength();
        void Add(const Phone& s);
        void Delete(string);
        void Search();
        void Update();
        void Show(); // show for staff

        void ShowTable(); // show table for customer
        void Show(int); // show 1 phone information
        void Shopping(Order&); // buy phone

        const string& getPhoneID(int);
        const int& getPhonePrice(int);
        const int& getRemainingAmount(int);
        const int& getEntryPrice(int);
        void setRemainingAmount(int,int);
        void LoadData();
        void UpdateFile();
        void Menu();
        const PhoneManager& operator=(const PhoneManager& );

        long long GetVon();
};
#endif