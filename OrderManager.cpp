#include <iostream>
#include "OrderManager.h"
#include <string>
using namespace std;
OrderManager::OrderManager()
{
    this->p = nullptr;
    this->n = 0;
}
OrderManager::~OrderManager()
{
    delete[] this->p;
}
void OrderManager::Add(const Order& s)
{
    if(this->n==0) {
        this->p = new Order[this->n+1];
        *(this->p+this->n) = s;
        this->n++;
    }
    else {
        Order *temp = new Order[this->n];
        for (int i=0;i<this->n;i++)
        {
            *(temp+i) = *(this->p+i);
        }
        delete[] this->p;
        this->p = new Order[this->n+1];
        for (int i=0;i<this->n;i++)  // còn phần tử cuối
            *(this->p+i)=*(temp+i);
        delete[] temp;
        *(this->p+this->n) = s;
        this->n++;
    }
}

void OrderManager::SearchByOrderID(string m)
{
    int index=-1;
    for (int i=0;i<this->n;i++)
    {
        if((this->p+i)->getID() == m)
        {
            index=i;
            break;
        }
    }
    if (index>=0) (this->p+index)->show();
    else cout<<"Khong co don hang nao!"<<endl;

}
void OrderManager::SearchByCustomerID(string m)
{
    int d=1;
    for (int i=0;i<this->n;i++)
    {
        if((this->p+i)->getCustomerID() == m)
        {
            cout<<"Don hang thu "<<d<<":"<<endl;
            d++;
            (this->p+i)->show();
            cout<<endl;
        }
    }
}
void OrderManager::SearchByStaffID(string m)
{   
    int d=1;
    for (int i=0;i<this->n;i++)
    {
        if((this->p+i)->getStaffID() == m)
        {
            cout<<"Don hang thu "<<d<<":"<<endl;
            d++;
            (this->p+i)->show();
            cout<<endl;
        }
    
    }     
}
void OrderManager::Show() //Show All
{
    for (int i=0;i<this->n;i++)
    {
        (this->p+i)->show();  
        cout<<endl;
    }
   
}