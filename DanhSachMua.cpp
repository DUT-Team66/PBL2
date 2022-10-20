#include <iostream>
#include "DanhSachMua.h"
#include <string>
using namespace std;

DanhSachMua::DanhSachMua()
{
    this->MaDT="";
    this->SL=0;
}
DanhSachMua::~DanhSachMua()
{

}
void DanhSachMua::Show()
{
    cout<<"Ma dien thoai: "<<this->MaDT<<", So luong: "<<this->SL;
}
