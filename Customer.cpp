#include "Customer.h"
#include <iomanip>
#include <iostream>
using namespace std;
Customer::Customer(string a, string b, string c) { 
    this->customerPhoneNumber = a;
    this->customerName = b;
    this->customerAddress = c;
}
Customer::~Customer() {

}
void Customer::setCustomerName(const string& name) {
	this->customerName = name;
}
const string& Customer::getCustomerName() const {
	return this->customerName;
}
void Customer::setCustomerPhoneNumber(const string& phoneNumber) {
	this->customerPhoneNumber = phoneNumber;
}
const string& Customer::getCustomerPhoneNumber() const {
	return this->customerPhoneNumber;
}
void Customer::setCustomerAddress(const string& address) {
	this->customerAddress = address;
}
const string& Customer::getCustomerAddress() const {
	return this->customerAddress;
}
const string& Customer::getID() const {
	return this->customerPhoneNumber;
}
void Customer::show()   // Chưa vẽ bảng
{
	cout << setw(42) << "" << "Name: " << this->customerName << "\n";
	//cout<<"CustomerPhoneNumber: "<<this->customerPhoneNumber<<"\n";
	cout << setw(42) << "" << "Address: " << this->customerAddress << "\n";
}