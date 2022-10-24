#include "KhachHang.h"
#include <iostream>
#include <string>
using namespace std;

KhachHang::KhachHang()
{
    this->MaKH="";
    this->TenKH="";
    this->SDTKH="";
    this->DiaChiKH="";
}
KhachHang::~KhachHang()
{
    
}
void KhachHang::SetMaKH(const string& s)
{
    this->MaKH=s;
}
const string& KhachHang::GetMaKH()
{
    return this->MaKH;
}
void KhachHang::SetTenKH(const string& s)
{
    this->TenKH=s;
}
const string& KhachHang::GetTenKH()
{
    return this->TenKH;
}
void KhachHang::SetSDTKH(const string& s)
{
    this->SDTKH=s;
}
const string& KhachHang::GetSDTKH()
{
    return this->SDTKH;
}
void KhachHang::SetDiaChiKH(const string& s)
{
    this->DiaChiKH=s;
}
const string& KhachHang::GetDiaChiKH()
{
    return this->DiaChiKH;
}
