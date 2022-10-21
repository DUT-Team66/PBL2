#include "Staff.h"
#include <iostream>
#include <string>
using namespace std;
Staff::Staff()
{
    this->ID = "";
    this->name = "";
    this->dob = "";
    this->address = "";
    this->phoneNumber = "";
    this->gender = "";
    this->salary = "";
}
Staff::Staff(string a, string b, string c, string d, string e, string g, string h)
    : ID(a), name(b), dob(c), address(d), phoneNumber(e), gender(g), salary(h)
{
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
void Staff::setSalary(const string &s)
{
    this->salary = s;
}
const string& Staff::getSalary()
{
    return this->salary;
}
void Staff::show()
{
    cout << "Staff id: " << this->ID << "\n";
    cout << "Staff name: " << this->name << "\n";
    cout << "Day of birth: " << this->dob << "\n";
    cout << "Address: " << this->address << "\n";
    cout << "Phone number: " << this->phoneNumber << "\n";
    cout << "Gender: " << this->gender << "\n";
    cout << "Salary: " << this->salary << "\n";

}
