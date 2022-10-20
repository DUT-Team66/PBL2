#include <iostream>
#include <string>
#include "Account.h"
using namespace std;
Account::Account() {
	this->account = "";
	this->password = "";
}
Account::Account(string account, string password)
{
	this->account = account;
	this->password = password;
}
void Account::setData() 
{
    //cout << "Username: ";
    cin >> this->account;
    //cout << "Password: ";
    cin >> this->password;
}
void Account::showData()
{
    cout << "Username: " << this->account << "\n";
    cout << "Password: " << this->password << "\n";
}