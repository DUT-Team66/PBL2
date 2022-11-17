#ifndef _ORDER_
#define _ORDER_
#include "Goods.h"
#include <string>
#include "Date.h"
using namespace std;
class Order
{
    private: 
        string ID;
        string customerPhoneNumber;
        string staffID;
        //Goods* goods;
        struct Cart {
            Goods data;
            Cart* pNext;
            Cart() {
                this->data.setPhoneID("");
                this->data.setAmount(0);
                this->pNext = nullptr;
            }
        };
        Cart *cart;
        int shpllength; // Số các danh sách mua
        Date purchaseDay;
        long long totalPrice;
    public:
        Order();
        ~Order();
        void setID(const string& );
        const string& getID() const;
        void setCustomerPhoneNumber(const string& );
        const string& getCustomerPhoneNumber() const;
        void setStaffID(const string& );
        const string& getStaffID() const;
        //void setGoods(const Goods&);
        const Goods& getGoods(int) const; // get goods at index
        void setShpllength(const int&);
        const int& getShpllength() const;
        void setPurchaseDay(const Date& );
        const Date& getPurchaseDay() const;
        void setTotalPrice(const long long&);
        const long long& getTotalPrice() const;
        
        void show();
        bool searchCart(string);
        void addToCart(string,int);
        void addToCart(const Goods&);
};

#endif