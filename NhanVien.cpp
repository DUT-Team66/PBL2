#include "NhanVien.h"
#include <iostream>
#include <string>
using namespace std;
NhanVien::NhanVien()
{
    this->MaNV="";
    this->TenNV="";
    this->NgaySinh="";
    this->DiaChiNV="";
    this->SDTNV="";
    this->GioiTinh="";
    this->Luong="";
}
NhanVien::NhanVien(string a, string b, string c, string d, string e, string g, string h)
: MaNV(a), TenNV(b), NgaySinh(c), DiaChiNV(d), SDTNV(e), GioiTinh(g), Luong(h)
{
    
}
NhanVien::~NhanVien()
{
    
}
void NhanVien::SetMaNV(const string& s)
{
    this->MaNV=s;
}
const string& NhanVien::GetMaNV()
{
    return this->MaNV;
}
void NhanVien::SetTenNV(const string& s)
{
    this->TenNV=s;
}
const string& NhanVien::GetTenNV()
{
    return this->TenNV;
}
void NhanVien::SetNgaySinh(const string& s)
{
    this->NgaySinh=s;
}
const string& NhanVien::GetNgaySinh()
{
    return this->NgaySinh;
}
void NhanVien::SetDiaChiNV(const string& s)
{
    this->DiaChiNV=s;
}
const string& NhanVien::GetDiaChiNV()
{
    return this->DiaChiNV;
}
void NhanVien::SetSDTNV(const string& s)
{
    this->SDTNV=s;
}
const string& NhanVien::GetSDTNV()
{
    return this->SDTNV;
}
void NhanVien::SetGioiTinh(const string& s)
{
    this->GioiTinh=s;
}
const string& NhanVien::GetGioiTinh()
{
    return this->GioiTinh;
}
void NhanVien::SetLuong(const string& s)
{
    this->Luong=s;
}
const string& NhanVien::GetLuong()
{
    return this->Luong;
}
void NhanVien::Show()
{
    cout<<this->MaNV<<"  "<<this->TenNV<<"  "<<this->NgaySinh<<"  "<<this->DiaChiNV<<"  "<<this->SDTNV<<"  "<<this->GioiTinh<<"  "<<this->Luong<<endl;
}
