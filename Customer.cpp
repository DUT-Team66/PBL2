#include "Customer.h"
#include <iomanip>
#include <iostream>
using namespace std;
Customer::Customer() {
    this->customerID = "";
    this->customerName = "";
    this->customerPhoneNumber = "";
    this->customerAddress = "";
}
Customer::~Customer() {

}
void Customer::setCustomerID(const string& id) {
	this->customerID = id;
}
const string& Customer::getCustomerID() const {
	return this->customerID;
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
void Customer::setInfo() {
    cin.ignore();
    cout << setw(20) << "" << "Enter your information" << "\n\n";
	
	cout << setw(22) << "" << "Name: ";
	getline(cin, this->customerName);
	
	cout << setw(22) << "" << "ID: ";
	getline(cin, this->customerID);
	
	cout << setw(22) << "" << "Phone number: ";
	getline(cin, this->customerPhoneNumber);
	
	cout << setw(22) << "" << "Address: ";
	getline(cin, this->customerAddress);
}
void Customer::BuyPhone() {
    
}