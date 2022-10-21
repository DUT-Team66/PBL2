#include <iostream>
#include <string>
#include <iomanip>
#include "Account.h"
using namespace std;
Account::Account() {
	this->username = "";
	this->password = "";
}
Account::Account(string account, string password)
{
	this->username = account;
	this->password = password;
}
// void Account::setData() 
// {
//     //cout << "Username: ";
//     cin >> this->username;
//     //cout << "Password: ";
//     cin >> this->password;
// }
string Account::getUsername() {
    return this->username;
}
string Account::getPassword() {
    return this->password;
}
void Account::showData()
{
    cout << "Username: " << this->username << "\n";
    cout << "Password: " << this->password << "\n";
}
