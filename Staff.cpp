#include "Staff.h"
#include <iostream>
#include <string>
#include <iomanip>
#include "Table.h"
using namespace std;

Staff::Staff()
{
    this->name = "";
    this->ID = "";
    this->gender = "";
    this->dob = "";
    this->phoneNumber = "";
    this->address = "";
    this->salary = 5000000;
}
Staff::Staff(string a, string b, string c, string d, string e, string f,string g, string h)
    : name(a), ID(b), gender(c), dob(d), phoneNumber(e), address(f), account(g,h)
{
    this-> salary = 5000000;
}
Staff::~Staff()
{
}
void Staff::setID(const string &s)
{
    this->ID = s;
}
const string &Staff::getID()
{
    return this->ID;
}
void Staff::setName(const string &s)
{
    this->name = s;
}
const string &Staff::getName()
{
    return this->name;
}
void Staff::setDob(const string &s)
{
    this->dob = s;
}
const string &Staff::getDob()
{
    return this->dob;
}
void Staff::setAddress(const string &s)
{
    this->address = s;
}
const string &Staff::getAddress()
{
    return this->address;
}
void Staff::setPhoneNumber(const string &s)
{
    this->phoneNumber = s;
}
const string &Staff::getPhoneNumber()
{
    return this->phoneNumber;
}
void Staff::setGender(const string &s)
{
    this->gender = s;
}
const string &Staff::getGender()
{
    return this->gender;
}
void Staff::setSalary(const int &s)
{
    this->salary = s;
}
const int& Staff::getSalary()
{
    return this->salary;
}
void Staff::setUsername(const string& username) {
    this->account.setUsername(username);
}
const string& Staff::getUsername() const {
    return this->account.getUsername();
}
void Staff::setPassword(const string& password) {
    this->account.setPassword(password);
}
const string& Staff::getPassword() const {
    return this->account.getPassword();
}
void Staff::setPhoneManager(const PhoneManager& phoneManager) {
    this->managePhone = phoneManager;
}
const PhoneManager& Staff::getPhoneManager() const {
    return this->managePhone;
}
void Staff::setOrderManager(const OrderManager& orderManager) {
    this->manageOrder = orderManager;
}
void Staff::show()
{
    std::cout << topLeftCorner << line(30); // staff name
	std::cout << topMid << line(14); //staffID
	std::cout << topMid << line(8); // gender
	std::cout << topMid << line(12); // dob
	std::cout << topMid << line(14); //phonenumber
	std::cout << topMid << line(26); //address
	std::cout << topMid << line(13); //salary
	std::cout << topMid << line(11); //username
	std::cout << topMid << line(10); // password
	std::cout << topRightCorner << "\n";
	
	std::cout << col << setw(9) << "" << setw(21) << left << "Staff name"; 
	std::cout << col << setw(3) << "" << setw(11) << left << "Staff ID";
	std::cout << col << setw(1) << "" << setw(7) << left << "Gender";
	std::cout << col << setw(4) << "" << setw(8) << left << "DOB";
	std::cout << col << setw(1) << "" << setw(13) << left << "Phone number";
	std::cout << col << setw(9) << "" << setw(17) << left << "Address";
	std::cout << col << setw(2) << "" << setw(11) << left << "Salary";
	std::cout << col << setw(2) << "" << setw(9) << left << "Username";
	std::cout << col << setw(1) << "" << setw(9) << left << "Password";
	std::cout << col << "\n";

    std::cout << leftSide << line(30);
    std::cout << midMid << line(14);
    std::cout << midMid << line(8);
    std::cout << midMid << line(12);
    std::cout << midMid << line(14);
    std::cout << midMid << line(26);
    std::cout << midMid << line(13);
    std::cout << midMid << line(11);
    std::cout << midMid << line(10);
    std::cout << rightSide << "\n";
    
    std::cout << col << setw((30 - this->name.length())/2) << "" << setw(30 - (30 - this->name.length())/2) << left << this->name;
    std::cout << col << setw((14 - this->ID.length())/2) << "" << setw(14 - (14 -  this->ID.length())/2) << left << this->ID;
    std::cout << col << setw((8 - this->gender.length())/2) << "" << setw(8 - (8 - this->gender.length())/2) << left << this->gender;
    std::cout << col << setw((12 - this->dob.length())/2) << "" << setw(12 - (12 - this->dob.length())/2) << left << this->dob;
    std::cout << col << setw((14 - this->phoneNumber.length())/2) << "" << setw(14 - (14 - this->phoneNumber.length())/2) << left << this->phoneNumber;
    std::cout << col << setw(26 - (26 - this->address.length())/2) << right << this->address << setw((26 - this->address.length())/2) << "";
    std::cout << col << setw(13 - (13 - to_string(this->salary).length())/2) << right << this->salary << setw((13 - to_string(this->salary).length())/2) << "";
    std::cout << col << setw(11 - (11 - this->account.getUsername().length())/2) << right << this->account.getUsername() << setw((11 - this->account.getUsername().length())/2) << "";
    std::cout << col << setw(10 - (10 - this->account.getPassword().length())/2) << right << this->account.getPassword() << setw((10 - this->account.getPassword().length())/2) << ""; 
    std::cout << col << "\n";  

    std::cout << botLeftCorner << line(30); // staff name
	std::cout << botMid << line(14); //staffID
	std::cout << botMid << line(8); // gender
	std::cout << botMid << line(12); // dob
	std::cout << botMid << line(14); //phonenumber
	std::cout << botMid << line(26); //address
	std::cout << botMid << line(13); //salary
	std::cout << botMid << line(11); // username
	std::cout << botMid << line(10); // password
	std::cout << botRightCorner << "\n";
    

}
void Staff::showForSetInfo() {
    if(this->name != "") {
        cout << setw(45) << "" << "Enter name: " << this->name << "\n";
    }
    if(this->ID != "") {
        cout << setw(45) << "" << "Enter ID: " << this->ID << "\n";
    }
    if(this->gender != "" ) {
        cout << setw(45) << "" << "Enter gender: " << this->gender << "\n";
    }
    if(this->dob != "") {
        cout << setw(45) << "" << "Enter dob: " << this->dob << "\n";
    }
    if(this->phoneNumber != "") {
        cout << setw(45) << "" << "Enter phone number: " << this->phoneNumber << "\n";
    }
    if(this->address != "") {
        cout << setw(45) << "" << "Enter address: " << this->address << "\n";
    }
}

void Staff::Menu() {
    while(true) {
        int choice;
        while(true) {
            cout << setw(20) << "" << "Choose what you want to manage" << "\n\n";
            cout << setw(22) << "" << "1. Phones" << "\n";
            cout << setw(22) << "" << "2. Trades" << "\n";
            cout << setw(22) << "" << "3. Go back" << "\n\n";
            cout << setw(20) << "" << "Your choice: ";
            cin >> choice;
            if(choice != 1 && choice != 2 && choice != 3) {
                cout << setw(5) << "" << "Invalid choice, please re-enter!\n";
                system("pause");
                system("cls"); 
            } else break;
        }
        
        if(choice == 1) {
            this->managePhone.Menu();
        } else if(choice == 2) {
            this->manageOrder.Menu();
        } else break;
    }
}

void Staff::setInfo() {
    
    cin.ignore();
    cout << setw(4) << "" << "Enter name: ";
    getline(cin, this->name);
    cout << setw(4) << "" << "Enter ID: ";
    getline(cin, this->ID);
    cout << setw(4) << "" << "Enter gender: ";
    getline(cin, this->gender);
    cout << setw(4) << "" << "Enter dob: ";
    getline(cin, this->dob);
    cout << setw(4) << "" << "Enter phone number: ";
    getline(cin, this->phoneNumber);
    cout << setw(4) << "" << "Enter address: ";
    getline(cin, this->address);
}
void Staff::UpdateAllFiles() {
    this->managePhone.UpdateFile();
}
