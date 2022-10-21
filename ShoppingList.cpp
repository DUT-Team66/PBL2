#include <iostream>
#include "ShoppingList.h"
#include <string>
using namespace std;

ShoppingList::ShoppingList()
{
    this->phoneID="";
    this->amount=0;
}
ShoppingList::~ShoppingList()
{

}
void ShoppingList::show()
{
    cout<<"Ma dien thoai: "<<this->phoneID<<", So luong: "<<this->amount;
}
