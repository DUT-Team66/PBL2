#include <iostream>
#include "ShoppingList.h"
#include <string>
using namespace std;

ShoppingList::ShoppingList()
{
    this->phoneID="";
    this->amount=0;
}
ShoppingList::ShoppingList(string id, int amount) {
    this->phoneID = id;
    this->amount = amount;
}
ShoppingList::~ShoppingList()
{

}
const string& ShoppingList::getPhoneID() const {
    return this->phoneID;
}
const int& ShoppingList::getAmount() const {
    return this->amount;
}
void ShoppingList::show()
{
    cout<<"Phone id: "<< this->phoneID <<", amount: "<< this->amount << "\n";
}
