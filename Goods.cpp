#include <iostream>
#include "Goods.h"
#include <string>
using namespace std;

Goods::Goods()
{
    this->phoneID="";
    this->amount=0;
}
Goods::Goods(string id, int amount) {
    this->phoneID = id;
    this->amount = amount;
}
Goods::~Goods()
{

}
const string& Goods::getPhoneID() const {
    return this->phoneID;
}
void Goods::setPhoneID(const string& id) {
    this->phoneID = id;
}
const int& Goods::getAmount() const {
    return this->amount;
}
void Goods::setAmount(const int& amount) {
    this->amount = amount;
}
void Goods::show()
{
    cout<< "Phone id: "<< this->phoneID <<", amount: "<< this->amount << "\n";
}
