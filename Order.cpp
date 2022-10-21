#include "Order.h"
#include <iostream>
#include <string>
using namespace std;

Order::Order()
{
    this->ID = "";
    this->customerID = "";
    this->staffID = "";
    this->shoppingList = nullptr;
    this->shpllength = 0;
    this->purchaseDay = "";
    this->totalPrice = 0;
}
Order::~Order()
{
}
void Order::setID(const string &s)
{
    this->ID = s;
}
const string &Order::getID()
{
    return this->ID;
}
void Order::setCustomerID(const string &s)
{
    this->customerID = s;
}
const string &Order::getCustomerID()
{
    return this->customerID;
}
void Order::setStaffID(const string &s)
{
    this->staffID = s;
}
const string &Order::getStaffID()
{
    return this->staffID;
}
void Order::setPurchaseDay(const string &s)
{
    this->purchaseDay = s;
}
const string &Order::getPurchaseDay()
{
    return this->purchaseDay;
}
void Order::show()
{
    cout << "Order id: " << this->ID << "\n";
    cout << "Customer id: " << this->customerID << "\n";
    cout << "Staff id: " << this->staffID << "\n";
    for (int i = 0; i < this->shpllength; i++)
    {
        (this->shoppingList + i)->show();
    }
    cout << "Purchase day: " << this->purchaseDay << "\n";
    cout << "Total price: " << this->totalPrice << "\n";
}
