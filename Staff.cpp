#include "Staff.h"
#include <iostream>
#include <string>
#include <iomanip>

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
void Staff::setOrderManager(const OrderManager& orderManager) {
    this->manageOrder = orderManager;
}
void Staff::show()
{
    cout << "" << "Staff name: " << this->name << "\n";
    cout << "" << "Staff id: " << this->ID << "\n";
    cout << "Gender: " << this->gender << "\n";
    cout << "Day of birth: " << this->dob << "\n";
    cout << "Phone number: " << this->phoneNumber << "\n";
    cout << "Address: " << this->address << "\n";
    cout << "Salary: " << this->salary << "\n";

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
