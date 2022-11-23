#ifndef _ORDERMANAGER_
#define _ORDERMANAGER_
#include "Order.h"
class OrderManager
{
    private: 
        struct Node{
            Order data;
            Node* pNext;
        };
        Node *pHead;
        Node *pTail;
        int n;
    public:
        //Khong co SV
        OrderManager();
        ~OrderManager();
        const int& GetLength() const;
        const int& GetMonth(int) ; // lay thang mua order thu index
        const int& GetYear(int) const; // lay nam 
        const long long& GetTotalPrice(int) const; // lay tong tien cua 1 don hang
        void SearchByOrderID(string);
        void SearchByCustomerPhoneNumber(string);
        void SearchByStaffID(string);
        void Add(const Order&);
        void LoadData();
        void UpdateFile();
        void Show();
        void Menu();
        const OrderManager& operator=(const OrderManager& );
};
#endif