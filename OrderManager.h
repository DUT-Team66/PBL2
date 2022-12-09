#ifndef _ORDERMANAGER_
#define _ORDERMANAGER_
#include "Order.h"
#include "MyLib.h"
class OrderManager
{
    private: 
        List<Order> list;
    public:
        //Khong co SV
        OrderManager();
        ~OrderManager();
        int GetLength() const;
        const int& GetMonth(int) ; // lay thang mua order thu index
        const int& GetYear(int); // lay nam 
        const long long& GetTotalPrice(int); // lay tong tien cua 1 don hang
        void SearchByOrderID(string);
        void SearchByCustomerPhoneNumber(string);
        void SearchByStaffID(string);
        void Add(const Order&);
        void LoadData();
        void UpdateFile();
        void Show();
        void Menu();
        // const OrderManager& operator=(const OrderManager& );
};
#endif