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
        long long totalPrice;

        Order* next;
    public:
        Order();
        ~Order();
        void setID(const string& );
        const string& getID() const;
        void setCustomerID(const string& );
        const string& getCustomerID() const;
        void setStaffID(const string& );
        const string& getStaffID() const;
        //void setShoppingList(const ShoppingList&);
        const ShoppingList& getShoppingList(int) const;
        void setShpllength(const int&);
        const int& getShpllength() const;
        void setPurchaseDay(const Date& );
        const Date& getPurchaseDay() const;
        void setTotalPrice(const long long&);
        const long long& getTotalPrice() const;
        Order* getNextOrder() const;
        void setNextOrder(Order*);
        void show();
        bool searchShoppingList(string);
        void addToShoppingList(string,int);
        void addToShoppingList(const ShoppingList&);
};

#endif