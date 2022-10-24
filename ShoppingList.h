#ifndef _SHOPPINGLIST_
#define _SHOPPINGLIST_

#include <string>
using namespace std;
class ShoppingList
{
    private:
        string phoneID;
        int amount;
    public:
        ShoppingList();
        ShoppingList(string,int);
        ~ShoppingList();
        void show();
};
#endif