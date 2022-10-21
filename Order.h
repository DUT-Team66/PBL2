#ifndef _ORDER_
#define _ORDER_
#include "ShoppingList.h"
#include <string>
using namespace std;
class Order
{
    private: 
        string ID;
        string customerID;
        string staffID;
        ShoppingList* shoppingList;
        int shpllength; // Số các danh sách mua
        string purchaseDay;
        int totalPrice;
    public:
        Order();
        ~Order();
        void setID(const string& );
        const string& getID();
        void setCustomerID(const string& );
        const string& getCustomerID();
        void setStaffID(const string& );
        const string& getStaffID();
        void setShoppingList(const ShoppingList&);
        const string& getShoppingList();
        void setPurchaseDay(const string& );
        const string& getPurchaseDay();
        void show();
};

#endif