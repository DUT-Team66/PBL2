#ifndef _ORDER_
#define _ORDER_
#include "ShoppingList.h"
#include <string>
#include "Date.h"
using namespace std;
class Order
{
    private: 
        string ID;
        string customerID;
        string staffID;
        ShoppingList* shoppingList;
        int shpllength; // Số các danh sách mua
        Date purchaseDay;
        int totalPrice;
    public:
        Order();
        ~Order();
        void setID(const string& );
        const string& getID() const;
        void setCustomerID(const string& );
        const string& getCustomerID() const;
        void setStaffID(const string& );
        const string& getStaffID() const;
        void setShoppingList(const ShoppingList&);
        const string& getShoppingList() const;
        void setPurchaseDay(const Date& );
        const Date& getPurchaseDay() const;
        void setTotalPrice(const int&);
        const int& getTotalPrice() const;
        
        void show();
        void addToShoppingList(const ShoppingList&);
};

#endif