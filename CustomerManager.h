#ifndef _CUSTOMERMANAGER_
#define _CUSTOMERMANAGER_
#include "Customer.h"
class CustomerManager
{
    private: 
        struct Node{
            Customer data;
            Node* pNext;
        };
        Node *pHead;
        Node *pTail;
        int n;
    public:        
        CustomerManager();
        ~CustomerManager();
        int GetLength();
        void Add(const Customer& s);
        void Delete(string);
        void Search(string);
        void Show() const; 
        void setInfo(Customer&);
        void LoadData();
        void UpdateFile();
        void Menu();
        const CustomerManager& operator=(const CustomerManager& );
};
#endif