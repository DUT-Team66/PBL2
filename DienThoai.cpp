#include "DienThoai.h"
#include <iostream>
#include <string>
using namespace std;

DienThoai::DienThoai()
{
    this->MaDT="";
    this->TenDT="";
    this->Hang="";
    this->RAM="";
    this->ROM="";
    this->Chip="";
    this->Pin="";
    this->ManHinh="";
    this->GiaNhap=0;
    this->GiaBan=0;
    this->SoLuong=0;
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

void DienThoai::SetRAM(const string& s)
{
    this->RAM=s;
}
const string& DienThoai::GetRAM()
{
    return this->RAM;
}

void DienThoai::SetROM(const string& s)
{
    this->ROM=s;    
}
const string& DienThoai::GetROM()
{
    return this->ROM;
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

void DienThoai::SetGiaNhap(const int& s)
{
    this->GiaNhap=s;
}
const int& DienThoai::GetGiaNhap()
{
    return this->GiaNhap;
}

void DienThoai::SetGiaBan(const int& s)
{
    this->GiaBan=s;
}


const int& DienThoai::GetGiaBan()
{
    return this->GiaBan;
}

void DienThoai::SetSoLuong(const int& s)
{
    this->SoLuong=s;
}
const int& DienThoai::GetSoLuong()
{
    return this->SoLuong;
}    
