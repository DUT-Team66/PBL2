#include <iostream>
#include "QLNV.h"
#include <string>
using namespace std;
QLNV::QLNV()
{
    this->p=0;
    this->n=0;
}
QLNV::~QLNV()
{
    delete[] this->p;
}
void QLNV::Add(const NhanVien& s)
{
    if(this->n==0) {
        this->p = new NhanVien[this->n+1];
        *(this->p+this->n) = s;
        this->n++;
    }
    else {
        NhanVien *temp = new NhanVien[this->n];
        for (int i=0;i<this->n;i++)
        {
            *(temp+i) = *(this->p+i);
        }
        delete[] this->p;
        this->p = new NhanVien[this->n+1];
        for (int i=0;i<this->n;i++)  // còn phần tử cuối
            *(this->p+i)=*(temp+i);
        delete[] temp;
        *(this->p+this->n) = s;
        this->n++;
    }
}
void QLNV::Delete(string m)
{
    int index=-1;
    for (int i=0;i<this->n;i++)
    {
        if((this->p+i)->GetMaNV() == m)
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
            NhanVien *temp = new NhanVien[this->n];
            for (int i=0;i<this->n;i++)
            {
                *(temp+i) = *(this->p+i);
            }
            delete[] this->p;
            this->p = new NhanVien[this->n-1];
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
void QLNV::Search(string m)
{
    int index=-1;
    for (int i=0;i<this->n;i++)
    {
        if((this->p+i)->GetMaNV() == m)
        {
            index=i;
            break;
        }
    }

    if (index>=0) (this->p+index)->Show();
    cout<<endl;


}

int QLNV::IndexOf(string m)   // ham them
{
    int index=-1;
    for (int i=0;i<this->n;i++)
    {
        if((this->p+i)->GetLuong() == m)
        {
            index=i;
            break;
        }
    }
    return index;
}

//chu y: Update co the cap nhat nhieu cai
void QLNV::Update(string m) // Cap nhat muc luong
{
    int index=IndexOf(m);
    if (index>=0)
    {
        string g;
        cout<<"Muc luong moi: ";
        cin>>g;
        (this->p + index)->SetLuong(g);
    }
}
void QLNV::Show()
{
    for (int i=0;i<this->n;i++)
    {
        (this->p+i)->Show();  // Show ni của class SV
    }
    cout<<endl;

}