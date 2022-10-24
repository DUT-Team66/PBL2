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
void ShoppingList::show()
{
    cout<<"Phone id: "<< this->phoneID <<", Amount: "<< this->amount << "\n";
}
