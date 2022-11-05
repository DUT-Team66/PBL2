#include <iostream>
#include <string>
#include <iomanip>
#include "Account.h"
using namespace std;
Account::Account() {
	this->username = "";
	this->password = "";
}
Account::Account(string username, string password)
{
	this->username = username;
	this->password = password;
}
// void Account::setData() 
// {
//     //cout << "Username: ";
//     cin >> this->username;
//     //cout << "Password: ";
//     cin >> this->password;
// }
void Account::setUsername(const string& username) {
    this->username = username;
}
const string& Account::getUsername() const {
    return this->username;
}
void Account::setPassword(const string& password) {
    this->password = password;
}
const string& Account::getPassword() const {
    return this->password;
}
void Account::showData()
{
    cout << "Username: " << this->username << "\n";
    cout << "Password: " << this->password << "\n";
}
