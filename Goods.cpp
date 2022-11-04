#include <iostream>
#include "Goods.h"
#include <string>
using namespace std;

Goods::Goods() {
    this->phoneID = "";
    this->amount = 0;
    this->next = nullptr;
}
Goods::Goods(string id, int amount) {
    this->phoneID = id;
    this->amount = amount;
    this->next = nullptr;
}
Goods::~Goods() {
    delete this->next;
}
const string& Goods::getPhoneID() const {
    return this->phoneID;
}
const int& Goods::getAmount() const {
    return this->amount;
}
void Goods::show() {
    cout<< "Phone id: "<< this->phoneID <<", amount: "<< this->amount << "\n";
}
void Goods::setNextGoods(Goods*& g) {
    this->next = g;
}
Goods*& Goods::getNextGoods() {
    return this->next;
}