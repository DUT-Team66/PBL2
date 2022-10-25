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
void Phone::setEntryPrice(const int& price) {
    this->entryPrice = price;
}
const int& Phone::getEntryPrice() const{
    return this->entryPrice;
}

void Phone::setSalePrice(const int& price) {
    this->salePrice = price;
}
const int& Phone::getSalePrice() const {
    return this->salePrice;
}

void Phone::setRemainingAmount(const int& amount) {
    this->remainingAmount = amount;
}
const int& Phone::getRemainingAmount() const {
    return this->remainingAmount;
}

void Phone::showForCustomer()
{
    cout<<"Phone name: "<<this->phoneName
    <<"\nPhone ID: "<<this->phoneID
    <<"\nBrand: "<<this->brand
    <<"\nProcessor: "<<this->processor
    <<"\nRAM/ROM: "<<this->RAM_ROM
    <<"\nDisplay: "<<this->display
    <<"\nCamera: "<<this->camera
    <<"\nSale price: "<< this->salePrice
    <<"\nRemaining amount: "<< this->remainingAmount << "\n";
}
void Phone::showForStaff()
{
    cout<<"Phone name: "<<this->phoneName
    <<"\nPhone ID: "<<this->phoneID
    <<"\nBrand: "<<this->brand
    <<"\nProcessor: "<<this->processor
    <<"\nRAM/ROM: "<<this->RAM_ROM
    <<"\nDisplay: "<<this->display
    <<"\nCamera: "<<this->camera
    <<"\nEntry price: "<<this->entryPrice
    <<"\nSale price: "<<this->salePrice
    <<"\nRemaining amount: "<<this->remainingAmount << "\n";
}
void Phone::setInfo() {
    cin.ignore();
    cout << "Enter phone name: ";
    getline(cin, this->phoneName);
    cout << "Enter phone id: ";
    getline(cin, this->phoneID);
    cout << "Enter brand: ";
    getline(cin,this->brand);
    cout << "Enter processor: ";
    getline(cin, this->processor);
    cout << "Enter RAM/ROM: ";
    getline(cin, this->RAM_ROM);
    cout << "Enter display: ";
    getline(cin, this->display);
    cout << "Enter camera: ";
    getline(cin, this->camera);
    cout << "Enter entry price: ";
    cin >> this->entryPrice;
    cout << "Enter sale price: ";
    cin >> this->salePrice;
    cout << "Enter remaining amount: ";
    cin >> this->remainingAmount;
}
