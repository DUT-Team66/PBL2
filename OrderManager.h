#ifndef _ORDERMANAGER_
#define _ORDERMANAGER_
#include "Order.h"
class OrderManager
{
    private: 
        Order *p;
        
    public:
        //Khong co SV
        OrderManager();
        ~OrderManager();
        const int& GetLength() const;
        const int& GetMonth(int) const; // lay thang mua order thu index
        const int& GetYear(int) const; // lay nam 
        const long long& GetTotalPrice(int) const; // lay tong tien cua 1 don hang
        void SearchByOrderID(string);
        void SearchByCustomerID(string);
        void SearchByStaffID(string);
        void Add(const Order&);
        void LoadData();
        void UpdateFile();
        void Show();
        void Menu();
        const OrderManager& operator=(const OrderManager& );
};
#endif