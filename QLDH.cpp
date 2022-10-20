#include <iostream>
#include "QLDH.h"
#include <string>
using namespace std;
QLDH::QLDH()
{
    this->p=0;
    this->n=0;
}
QLDH::~QLDH()
{
    delete[] this->p;
}
void QLDH::Add(const DonHang& s)
{
    if(this->n==0) {
        this->p = new DonHang[this->n+1];
        *(this->p+this->n) = s;
        this->n++;
    }
    else {
        DonHang *temp = new DonHang[this->n];
        for (int i=0;i<this->n;i++)
        {
            *(temp+i) = *(this->p+i);
        }
        delete[] this->p;
        this->p = new DonHang[this->n+1];
        for (int i=0;i<this->n;i++)  // còn phần tử cuối
            *(this->p+i)=*(temp+i);
        delete[] temp;
        *(this->p+this->n) = s;
        this->n++;
    }
}

void QLDH::SearchByMaDH(string m)
{
    int index=-1;
    for (int i=0;i<this->n;i++)
    {
        if((this->p+i)->GetMaDH() == m)
        {
            index=i;
            break;
        }
    }
    if (index>=0) (this->p+index)->Show();
    else cout<<"Khong co don hang nao!"<<endl;

}
void QLDH::SearchByMaKH(string m)
{
    int d=1;
    for (int i=0;i<this->n;i++)
    {
        if((this->p+i)->GetMaKH() == m)
        {
            cout<<"Don hang thu "<<d<<":"<<endl;
            d++;
            (this->p+i)->Show();
            cout<<endl;
        }
    }
}
void QLDH::SearchByMaNV(string m)
{   
    int d=1;
    for (int i=0;i<this->n;i++)
    {
        if((this->p+i)->GetMaNV() == m)
        {
            cout<<"Don hang thu "<<d<<":"<<endl;
            d++;
            (this->p+i)->Show();
            cout<<endl;
        }
    
    }     
}
void QLDH::Show() //Show All
{
    for (int i=0;i<this->n;i++)
    {
        (this->p+i)->Show();  
        cout<<endl;
    }
   
}