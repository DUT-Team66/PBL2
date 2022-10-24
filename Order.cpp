#include "Order.h"
#include <iostream>
#include <string>
#include <iomanip>  
using namespace std;

Order::Order()
{
    this->ID = "";
    this->customerID = "";
    this->staffID = "";
    this->shoppingList = nullptr;
    this->shpllength = 0;
    this->purchaseDay = Date(0,0,0);
    this->totalPrice = 0;
}
Order::~Order()
{
}
void Order::setID(const string &s)
{
    this->ID = s;
}
const string &Order::getID() const
{
    return this->ID;
}
void Order::setCustomerID(const string &s)
{
    this->customerID = s;
}
const string &Order::getCustomerID() const
{
    return this->customerID;
}
void Order::setStaffID(const string &s)
{
    this->staffID = s;
}
const string &Order::getStaffID() const
{
    return this->staffID;
}
void Order::setPurchaseDay(const Date &s)
{
    this->purchaseDay = s;
}
const Date &Order::getPurchaseDay() const
{
    return this->purchaseDay;
}
void Order::setTotalPrice(const int& totalPrice) {
    this->totalPrice = totalPrice;
}
const int& Order::getTotalPrice() const {
    return this->totalPrice;
}
void Order::show()
{
    cout << "Order id: " << this->ID << "\n";
    cout << "Customer id: " << this->customerID << "\n";
    cout << "Staff id: " << this->staffID << "\n";
    cout << "Shopping list: \n";
    for (int i = 0; i < this->shpllength; i++)
    {
        cout << setw(5) << "";
        (this->shoppingList + i)->show();
    }
    cout << "Purchase day: " << this->purchaseDay << "\n";
    cout << "Total price: " << this->totalPrice << "\n";
}
void Order::addToShoppingList(const ShoppingList& sl) {
    if(this->shpllength==0) 
    {
        this->shoppingList = new ShoppingList[this->shpllength+1];
        *(this->shoppingList+this->shpllength) = sl;
        this->shpllength++;
    }
    else
    {
        ShoppingList *temp = new ShoppingList[this->shpllength];
        for (int i=0;i<this->shpllength;i++)
        {
            *(temp+i) = *(this->shoppingList+i);
        }
        delete[] this->shoppingList;
        this->shoppingList = new ShoppingList[this->shpllength+1];
        for (int i=0;i<this->shpllength;i++)  // còn ph?n t? cu?i
            *(this->shoppingList+i)=*(temp+i);
        delete[] temp;
        *(this->shoppingList+this->shpllength) = sl;
        this->shpllength++;
    }
    cout << "Add to cart successfully!\n";
    system("pause");
}