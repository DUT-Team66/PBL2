#include "DonHang.h"
#include <iostream>
#include <string>
using namespace std;

DonHang::DonHang() 
{
    this->MaDH="";
    this->DSM=0;
    this->n=0;
    this->MaKH="";
    this->MaNV="";
    this->NgayMua="";
    this->TongTien=0;

}
DonHang::~DonHang()
{

}
void DonHang::SetMaDH(const string& s)
{
    this->MaDH=s;
}
const string& DonHang::GetMaDH()
{
    return this->MaDH;
}


void DonHang::SetMaKH(const string& s)
{
    this->MaKH=s;
}
const string& DonHang::GetMaKH()
{
    return this->MaKH;
}
void DonHang::SetMaNV(const string& s)
{
    this->MaNV=s;
}
const string& DonHang::GetMaNV()
{
    return this->MaNV;
}
void DonHang::SetNgayMua(const string& s)
{
    this->NgayMua=s;
}
const string& DonHang::GetNgayMua()
{
    return this->NgayMua;
}
void DonHang::Show()
{
    cout<<"Ma don hang: "<<this->MaDH<<", Ma khach hang: "<<this->MaKH<<", Ma nhan vien: "<<this->MaNV<<endl;
    for (int i=0;i<this->n;i++)
    {
        (this->DSM+i)->Show();
    }
    cout<<"Ngay mua: "<<this->NgayMua<<", Tong gia tien cho don hang: "<<this->TongTien;
}
