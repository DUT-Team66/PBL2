#include <iostream>
#include "QLDT.h"
#include <string>
using namespace std;
QLDT::QLDT()
{
    this->p=0;
    this->n=0;
}
QLDT::~QLDT()
{
    delete[] this->p;
}
void QLDT::Add(const DienThoai& s)
{
    if(this->n==0) {
        this->p = new DienThoai[this->n+1];
        *(this->p+this->n) = s;
        this->n++;
    }
    else {
        DienThoai *temp = new DienThoai[this->n];
        for (int i=0;i<this->n;i++)
        {
            *(temp+i) = *(this->p+i);
        }
        delete[] this->p;
        this->p = new DienThoai[this->n+1];
        for (int i=0;i<this->n;i++)  // còn phần tử cuối
            *(this->p+i)=*(temp+i);
        delete[] temp;
        *(this->p+this->n) = s;
        this->n++;
    }
}
void QLDT::Delete(string m)
{
    int index=-1;
    for (int i=0;i<this->n;i++)
    {
        if((this->p+i)->GetMaDT() == m)
        {
            index=i;
            break;
        }
    }


    //Chu y truong hop index=-1(khong tim duoc)



    if (index >= 0)
    {
        if (this->n==1) {
            delete[] this->p;
            this->p=0;
            this->n--;
        }
        else {
            DienThoai *temp = new DienThoai[this->n];
            for (int i=0;i<this->n;i++)
            {
                *(temp+i) = *(this->p+i);
            }
            delete[] this->p;
            this->p = new DienThoai[this->n-1];
            for (int i=0;i<index;i++){
                *(p+i) = *(temp+i);
            }
            for (int i=index; i<this->n-1;i++){
                *(p+i)=*(temp+i+1);
            }
            delete[] temp;
            this->n--;
        }
    }
}
void QLDT::Search(string m)
{
    int index=-1;
    for (int i=0;i<this->n;i++)
    {
        if((this->p+i)->GetMaDT() == m)
        {
            index=i;
            break;
        }
    }

    if (index>=0) (this->p+index)->Show1();
    cout<<endl;

}
void QLDT::Show()
{
    int d=1;
    for (int i=0;i<this->n;i++)
    {
        cout<<d<<". ";
        (this->p+i)->Show1(); 
        d++; 
    }
   // cout<<endl;

}
int QLDT::Getlength()
{
    return this->n;
}