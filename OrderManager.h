#ifndef _ORDERMANAGER_
#define _ORDERMANAGER_
#include "Order.h"
class OrderManager
{
    private: 
        Order *p;
        int n;
    public:
        //Khong co SV
        OrderManager();
        ~OrderManager();
        void SearchByOrderID(string);
        void SearchByCustomerID(string);
        void SearchByStaffID(string);
        void Add(const Order&);
        void Show();
        void Menu();
};
#endif