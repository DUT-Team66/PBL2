#include "Order.h"
#include <iostream>
#include <string>
#include <iomanip>  
#include "Table.h"
using namespace std;

Order::Order()
{
    this->ID = "";
    this->customerPhoneNumber = "";
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
void Order::setCustomerPhoneNumber(const string &s)
{
    this->customerPhoneNumber = s;
}
const string &Order::getCustomerPhoneNumber() const
{
    return this->customerPhoneNumber;
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
    
    int w = 26;

    cout << setw(40) << "" << topLeftCorner << line(w) << topRightCorner << "\n";
    cout << setw(40) << "" << col << " Order id: " << setw(w - 11) << right << this->ID << col << "\n";
    cout << setw(40) << "" << col << " Customer p/n: " << setw(w - 15) << right << this->customerPhoneNumber << col << "\n";
    cout << setw(40) << "" << col << " Staff id: " << setw(w - 11) << right << this->staffID << col << "\n";
    
    Cart* tmp = this->cart;
    string stmp = tmp->data.getPhoneID() + "/" + to_string(tmp->data.getAmount());
    cout << setw(40) << "" << col << " Cart: " << setw(w-7) << right << stmp << col << "\n";
    tmp = tmp->pNext;
    while(tmp != nullptr) {
        string stmp = tmp->data.getPhoneID() + "/" + to_string(tmp->data.getAmount());
        cout << setw(40) << "" << col << setw(w) << right << stmp << col << "\n";
        tmp = tmp->pNext; 
    }
    string date = to_string(this->purchaseDay.getDay()) + "/" + to_string(this->purchaseDay.getMonth()) + "/" + to_string(this->purchaseDay.getYear());
    cout << setw(40) << "" << col << " Purchase day: " << setw(w - 15) << right << date << col << "\n";
    cout << setw(40) << "" << col << " Total price: " << setw(w - 14) << right << this->totalPrice << col << "\n";
    cout << setw(40) << "" << botLeftCorner << line(w) << botRightCorner << "\n\n";
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
            break;
        }
        tmp = tmp->pNext;
    }
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