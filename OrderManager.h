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
        void searchByOrderID(string);
        void searchByCustomerID(string);
        void searchByStaffID(string);
        void add(const Order&);
        void show();
};
#endif