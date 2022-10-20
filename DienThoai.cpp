#include "DienThoai.h"
#include <iostream>
#include <string>
using namespace std;

DienThoai::DienThoai()
{
    this->MaDT="";
    this->TenDT="";
    this->Hang="";
    this->RAM_ROM="";
    this->Chip="";
    this->Pin="";
    this->ManHinh="";
}
DienThoai::DienThoai(string a, string b,string c, string d, string e, string g, string h, int x, int y, int z)
: MaDT(a), TenDT(b), Hang(c), RAM_ROM(d), Chip(e), Pin(g), ManHinh(h), GiaNhap(x), GiaBan(y), SoLuong(z)
{

}
DienThoai::~DienThoai()
{

}

void DienThoai::SetMaDT(const string& s)
{
    this->MaDT=s;
}
const string& DienThoai::GetMaDT()
{
    return this->MaDT;
}

void DienThoai::SetTenDT(const string& s)
{
    this->TenDT=s;
}
const string& DienThoai::GetTenDT()
{
    return this->TenDT;
}


void DienThoai::SetHang(const string& s)
{
    this->Hang=s;
}
const string& DienThoai::GetHang()
{
    return this->Hang;
}

void DienThoai::SetRAM_ROM(const string& s)
{
    this->RAM_ROM=s;
}
const string& DienThoai::GetRAM_ROM()
{
    return this->RAM_ROM;
}


void DienThoai::SetChip(const string& s)
{
    this->Chip=s;
}
const string& DienThoai::GetChip()
{
    return this->Chip;
}

void DienThoai::SetPin(const string& s)
{
    this->Pin=s;
}
const string& DienThoai::GetPin()
{
    return this->Pin;
}

void DienThoai::SetManHinh(const string& s)
{
    this->ManHinh=s;
}
const string& DienThoai::GetManHinh()
{
    return this->ManHinh;
}

void DienThoai::Show1()
{
    cout<<"Ma dien thoai: "<<this->MaDT<<", Ten dien thoai: "<<this->TenDT<<", Hang san xuat: "<<this->Hang<<", RAM and ROM: "<<this->RAM_ROM<<"(GB), Chip xu li: "<<this->Chip<<", Dung luong pin"<<this->Pin<<"(mAh), Man hinh: "<<this->ManHinh<<endl;
}
void DienThoai::Show2()
{
    cout<<"Ma dien thoai: "<<this->MaDT<<", Ten dien thoai: "<<this->TenDT<<", Hang san xuat: "<<this->Hang<<", RAM and ROM: "<<this->RAM_ROM<<"(GB), Chip xu li: "<<this->Chip<<", Dung luong pin"<<this->Pin<<"(mAh), Man hinh: "<<this->ManHinh<<endl;
    cout<<"Gia nhap vao: "<<this->GiaNhap<<", Gia ban: "<<this->GiaBan<<", So luong con lai: "<<this->SoLuong;
}
