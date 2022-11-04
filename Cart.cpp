#include "Cart.h"
#include <iostream>
using namespace std;

Cart::Cart() {
    this->p = nullptr;
}
Cart::~Cart() {
    delete this->p;
}
Goods*& Cart::getGoods() {
    return this->p;
}
bool Cart::searchCart(string phoneID) {
    Goods *tmp = this->p;
    while(tmp != nullptr) {
        if(phoneID == tmp->getPhoneID()) {
            return true;
        }

        tmp = tmp->getNextGoods();
    }
    return false;
}
void Cart::add(Goods*& g) {
    Goods* tmp = this->p;
    while(tmp->getNextGoods() != nullptr) {
        tmp = tmp->getNextGoods();
    }
    tmp->setNextGoods(g);
    delete tmp;
}
void Cart::add(string phoneID, int amount) {
    Goods* tmp = this->p;
    while(tmp != nullptr) {
        if(phoneID == tmp->getPhoneID()) {
            tmp->setAmount(tmp->getAmount() + amount);
            break;
        }
    }
    delete tmp;
}
