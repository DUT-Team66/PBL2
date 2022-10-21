#include "Phone.h"
#include <iostream>
#include <string>
using namespace std;

Phone::Phone()
{
    this->phoneName = "";
    this->phoneID = "";
    this->brand = "";
    this->processor = "";
    this->RAM_ROM = "";
    this->display = "";
    this->camera = "";
    this->entryPrice = 0;
    this->salePrice = 0;
    this->remainingAmount = 0;
}
Phone::Phone(string a, string b,string c, string d, string e, string g, string h)
: phoneName(a), phoneID(b), brand(c), processor(d), RAM_ROM(e), display(g), camera(h)
{
    this->entryPrice = 0;
    this->salePrice = 0;
    this->remainingAmount = 0;
}
Phone::~Phone()
{

}

void Phone::setPhoneID(const string& s)
{
    this->phoneID=s;
}
const string& Phone::getPhoneID()
{
    return this->phoneID;
}

void Phone::setPhoneName(const string& s)
{
    this->phoneName=s;
}
const string& Phone::getPhoneName()
{
    return this->phoneName;
}


void Phone::setBrand(const string& s)
{
    this->brand=s;
}
const string& Phone::getBrand()
{
    return this->brand;
}

void Phone::setRAM_ROM(const string& s)
{
    this->RAM_ROM=s;
}
const string& Phone::getRAM_ROM()
{
    return this->RAM_ROM;
}


void Phone::setProcessor(const string& s)
{
    this->processor=s;
}
const string& Phone::getProcessor()
{
    return this->processor;
}

void Phone::setCamera(const string& s)
{
    this->camera=s;
}
const string& Phone::getCamera()
{
    return this->camera;
}

void Phone::setDisplay(const string& s)
{
    this->display=s;
}
const string& Phone::getDisplay()
{
    return this->display;
}

void Phone::showForCustomer()
{
    cout<<"Phone name: "<<this->phoneName<<"\nPhone ID: "<<this->phoneID<<"\nBrand: "<<this->brand<<"\nProcessor: "<<this->processor<<"\nRAM/ROM: "<<this->RAM_ROM<<"\nCamera: "<<this->camera<<"\nDisplay: "<<this->display<<"\n";
}
void Phone::showForStaff()
{
    cout<<"Phone name: "<<this->phoneName<<"\nPhone ID: "<<this->phoneID<<"\nBrand: "<<this->brand<<"\nProcessor: "<<this->processor<<"\nRAM/ROM: "<<this->RAM_ROM<<"\nCamera: "<<this->camera<<"\nDisplay: "<<this->display<<"\n";
    cout<<"Entry price: "<<this->entryPrice<<"\nSale price: "<<this->salePrice<<"\nRemaining amount: "<<this->remainingAmount << "\n";
}
