#include "Order.h"
#include <iostream>
#include <string>
#include <iomanip>  
#include "Table.h"
using namespace std;

Order::Order()
{
    this->ID = "";
    this->customerID = "";
    this->staffID = "";
    this->cart = nullptr;
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
const Goods& Order::getGoods(int index) const {
    Cart* tmp = this->cart;
    while(index--) {
        tmp = tmp->pNext;
    }
    return tmp->data;
}
void Order::setShpllength(const int& length) {
    this->shpllength = length;
}
const int& Order::getShpllength() const {
    return this->shpllength;
}
void Order::setTotalPrice(const long long& totalPrice) {
    this->totalPrice = totalPrice;
}
const long long& Order::getTotalPrice() const {
    return this->totalPrice;
}
void Order::show() //27 
{
    cout << setw(50) << "" << topLeftCorner << line(7) << topRightCorner << "\n";
    cout << setw(50) << "" << col << " ORDER " << col << "\n";
    cout << setw(50) << "" << botLeftCorner << line(7) << botRightCorner << "\n\n";

    cout << setw(46) << "" << topLeftCorner << line(27) << topRightCorner << "\n";
    cout << setw(46) << "" << col << " Order id: " << setw(27 - 11) << left << this->ID << col << "\n";
    cout << setw(46) << "" << col << " Customer id: " << setw(27 - 14) << left << this->customerID << col << "\n";
    cout << setw(46) << "" << col << " Staff id: " << setw(27 - 11) << left << this->staffID << col << "\n";
    cout << setw(46) << "" << col << " Cart: " << setw(27-7) << "" << col << "\n";
    
    Cart* tmp = this->cart;
    while(tmp != nullptr) {
        cout << setw(46) << "" << col << setw(3) << "" << tmp->data.getPhoneID() << "/" << tmp->data.getAmount() << setw(27 - 4 - tmp->data.getPhoneID().length() - to_string(tmp->data.getAmount()).length()) << "" << col << "\n";
        tmp = tmp->pNext; 
    }
    
    cout << setw(46) << "" << col << " Purchase day: " << this->purchaseDay << setw(27 - 15 - 2 - to_string(this->purchaseDay.getDay()).length() - to_string(this->purchaseDay.getMonth()).length() - to_string(this->purchaseDay.getYear()).length()) << "" << col << "\n";
    cout << setw(46) << "" << col << " Total price: " << setw(27 - 14) << left << this->totalPrice << col << "\n";
    cout << setw(46) << "" << botLeftCorner << line(27) << botRightCorner << "\n\n";
}
bool Order::searchCart(string id) {
    Cart* tmp = this->cart;
    while(tmp != nullptr) {
        if(tmp->data.getPhoneID() == id) {
            return true;
        }
        tmp = tmp->pNext;
    }
    return false;
}
void Order::addToCart(string id, int amount) {
    Cart* tmp = this->cart;
    while(tmp != nullptr) {
        if(tmp->data.getPhoneID() == id) {
            tmp->data.setAmount(tmp->data.getAmount() + amount);
        }
        tmp = tmp->pNext;
    }
    cout << "Add to cart successfully!\n";
    system("pause");
}
void Order::addToCart(const Goods& g) {
    Cart *c = new Cart;
    c->data.setPhoneID(g.getPhoneID());
    c->data.setAmount(g.getAmount());
    if(this->cart == nullptr) {
        this->cart = c;
    } else {
        Cart *tmp = this->cart;
        while(tmp->pNext != nullptr) {
            tmp = tmp->pNext;
        }
        tmp->pNext = c;
    }
    this->shpllength++;
}