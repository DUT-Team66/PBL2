#include "Phone.h"
#include <iostream>
#include <string>
#include <iomanip>
#include "Table.h"
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
Phone::Phone(string a, string b,string c, string d, string e, string g, string h,int i, int j, int k)
: phoneName(a), phoneID(b), brand(c), processor(d), RAM_ROM(e), display(g), camera(h), entryPrice(i), salePrice(j), remainingAmount(k)
{
    
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

    std::cout << " " << topLeftCorner << line(39); // phonename
	std::cout << topMid << line(13); // phoneID
	std::cout << topMid << line(9); // brand
	std::cout << topMid << line(27); // processor
	std::cout << topMid << line(12); // RAM_ROM
	std::cout << topMid << line(29); // display
	std::cout << topMid << line(13); // camera
	std::cout << topMid << line(12); // saleprice
	std::cout << topMid << line(8); // remaining amount
	std::cout << topRightCorner << "\n";
	
	std::cout << " " << col << setw(14) << "" << setw(25) << left << "Phone name"; 
	std::cout << col << setw(3) << "" << setw(10) << left << "Phone ID";
	std::cout << col << setw(2) << "" << setw(7) << left << "Brand";
	std::cout << col << setw(9) << "" << setw(18) << left << "Processor";
	std::cout << col << setw(2) << "" << setw(10) << left << "RAM-ROM";
	std::cout << col << setw(11) << "" << setw(18) << left << "Display";
	std::cout << col << setw(3) << "" << setw(10) << left << "Camera";
	std::cout << col << setw(11) << right << "Sale price" << setw(1) << "" ;
	std::cout << col << setw(7) << right << "Amount" << setw(1) << "";
    std::cout << col << "\n";


    std::cout << " " << leftSide << line(39); // phonename
    std::cout << midMid << line(13); // phoneID
    std::cout << midMid << line(9); // brand
    std::cout << midMid << line(27); // processor
    std::cout << midMid << line(12); // RAM_ROM
    std::cout << midMid << line(29); // display
    std::cout << midMid << line(13); // camera
    std::cout << midMid << line(12); // saleprice
    std::cout << midMid << line(8); // remaining amount
    std::cout << rightSide << "\n";
    
    std::cout << " " << col << setw((39 - this->phoneName.length())/2) << "" << setw(39 - (39 - this->phoneName.length())/2) << left << this->phoneName; 
    std::cout << col << setw((13 - this->phoneID.length())/2) << "" << setw(13 - (13 - this->phoneID.length())/2) << left << this->phoneID;
    std::cout << col << setw((9 - this->brand.length())/2) << "" << setw(9 - (9 - this->brand.length())/2) << left << this->brand;
    std::cout << col << setw((27 - this->processor.length())/2) << "" << setw(27 - (27 - this->processor.length())/2) << left << this->processor;
    std::cout << col << setw((12 - this->RAM_ROM.length())/2) << "" << setw(12 - (12 - this->RAM_ROM.length())/2) << left << this->RAM_ROM;
    std::cout << col << setw((29 - this->display.length())/2) << "" << setw(29 - (29 - this->display.length())/2) << left << this->display;
    std::cout << col << setw((13 - this->camera.length())/2) << "" << setw(13 - (13 - this->camera.length())/2) << left << this->camera;
    std::cout << col << setw(12 - (12 - to_string(this->salePrice).length())/2) << right << this->salePrice << setw((12 - to_string(this->salePrice).length())/2) << "" ;
    std::cout << col << setw(8 - (8 - to_string(this->remainingAmount).length())/2) << right << this->remainingAmount << setw((8 - to_string(this->remainingAmount).length())/2) << "" ;
    std::cout << col << "\n";

    std::cout << " " << botLeftCorner << line(39); // staff name
	std::cout << botMid << line(13); //phone id
	std::cout << botMid << line(9); // brand
	std::cout << botMid << line(27); // processor
	std::cout << botMid << line(12); //ramrom
	std::cout << botMid << line(29); //display
	std::cout << botMid << line(13); //camera
	std::cout << botMid << line(12); // sale price
	std::cout << botMid << line(8); // remaining amount
	std::cout << botRightCorner << "\n";
}
void Phone::showForStaff()
{
    std::cout << topLeftCorner << line(39); // phonename
	std::cout << topMid << line(13); // phoneID
	std::cout << topMid << line(9); // brand
	std::cout << topMid << line(27); // processor
	std::cout << topMid << line(12); // RAM_ROM
	std::cout << topMid << line(29); // display
	std::cout << topMid << line(13); // camera
	std::cout << topMid << line(13); // entryprice
	std::cout << topMid << line(12); // saleprice
	std::cout << topMid << line(8); // remaining amount
	std::cout << topRightCorner << "\n";
	
	std::cout << col << setw(14) << "" << setw(25) << left << "Phone name"; 
	std::cout << col << setw(3) << "" << setw(10) << left << "Phone ID";
	std::cout << col << setw(2) << "" << setw(7) << left << "Brand";
	std::cout << col << setw(9) << "" << setw(18) << left << "Processor";
	std::cout << col << setw(2) << "" << setw(10) << left << "RAM-ROM";
	std::cout << col << setw(11) << "" << setw(18) << left << "Display";
	std::cout << col << setw(3) << "" << setw(10) << left << "Camera";
	std::cout << col << setw(12) << right << "Entry price" << setw(1) << "" ;
	std::cout << col << setw(11) << right << "Sale price" << setw(1) << "" ;
	std::cout << col << setw(7) << right << "Amount" << setw(1) << "";
    std::cout << col << "\n";

    std::cout << leftSide << line(39); // phonename
    std::cout << midMid << line(13); // phoneID
    std::cout << midMid << line(9); // brand
    std::cout << midMid << line(27); // processor
    std::cout << midMid << line(12); // RAM_ROM
    std::cout << midMid << line(29); // display
    std::cout << midMid << line(13); // camera
    std::cout << midMid << line(13); // entryprice
    std::cout << midMid << line(12); // saleprice
    std::cout << midMid << line(8); // remaining amount
    std::cout << rightSide << "\n";
    
    std::cout << col << setw((39 - this->phoneName.length())/2) << "" << setw(39 - (39 - this->phoneName.length())/2) << left << this->phoneName; 
    std::cout << col << setw((13 - this->phoneID.length())/2) << "" << setw(13 - (13 - this->phoneID.length())/2) << left << this->phoneID;
    std::cout << col << setw((9 - this->brand.length())/2) << "" << setw(9 - (9 - this->brand.length())/2) << left << this->brand;
    std::cout << col << setw((27 - this->processor.length())/2) << "" << setw(27 - (27 - this->processor.length())/2) << left << this->processor;
    std::cout << col << setw((12 - this->RAM_ROM.length())/2) << "" << setw(12 - (12 - this->RAM_ROM.length())/2) << left << this->RAM_ROM;
    std::cout << col << setw((29 - this->display.length())/2) << "" << setw(29 - (29 - this->display.length())/2) << left << this->display;
    std::cout << col << setw((13 - this->camera.length())/2) << "" << setw(13 - (13 - this->camera.length())/2) << left << this->camera;
    std::cout << col << setw(13 - (13 - to_string(this->entryPrice).length())/2) << right << this->entryPrice << setw((13 - to_string(this->entryPrice).length())/2) << "" ;
    std::cout << col << setw(12 - (12 - to_string(this->salePrice).length())/2) << right << this->salePrice << setw((12 - to_string(this->salePrice).length())/2) << "" ;
    std::cout << col << setw(8 - (8 - to_string(this->remainingAmount).length())/2) << right << this->remainingAmount << setw((8 - to_string(this->remainingAmount).length())/2) << "" ;
    std::cout << col << "\n";


    std::cout << botLeftCorner << line(39); // staff name
	std::cout << botMid << line(13); //phone id
	std::cout << botMid << line(9); // brand
	std::cout << botMid << line(27); // processor
	std::cout << botMid << line(12); //ramrom
	std::cout << botMid << line(29); //display
	std::cout << botMid << line(13); //camera
	std::cout << botMid << line(13); // entryprice
	std::cout << botMid << line(12); // sale price
	std::cout << botMid << line(8); // remaining amount
	std::cout << botRightCorner << "\n";
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