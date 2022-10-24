
#include <fstream>
#include <iomanip>
#include "AccountManager.h"
using namespace std;

AccountManager::AccountManager() {
	this-> p = nullptr;
	this->n = 0;
}
AccountManager::~AccountManager() {
	delete[] this->p;
}
void AccountManager::Add(const Account& acc) {
    if(this->n==0) 
    {
        this->p = new Account[this->n+1];
        *(this->p+this->n) = acc;
        this->n++;
    }
    else
    {
        Account *temp = new Account[this->n];
        for (int i=0;i<this->n;i++)
        {
            *(temp+i) = *(this->p+i);
        }
        delete[] this->p;
        this->p = new Account[this->n+1];
        for (int i=0;i<this->n;i++)  // còn ph?n t? cu?i
            *(this->p+i)=*(temp+i);
        delete[] temp;
        *(this->p+this->n) = acc;
        this->n++;
    }
}
void AccountManager::LoadData() 
{	

	fstream readfile("Account.txt", ios::in);
	string tmpline;
	while(getline(readfile,tmpline)) {
		
		string username = "", password = "";
		
		
		int i = 0;
		while(tmpline[i] != '/') {
			username += tmpline[i];
			++i;
		}
		++i;
		while(tmpline[i] != '/') {
			password += tmpline[i];
			++i;
		}
		Account acc(username, password);
		this->Add(acc);
		
    }
    readfile.close();
		
	
}

void AccountManager::ShowData()
{
    for(int i = 0; i < this->n; ++i) {
        cout << i + 1 << ". ";
        p[i].showData();
    }
}
void AccountManager::Login(bool& isAdmin, bool& isStaff) {
    
    while(true) {
        string username, password;
        cout << setw(20) << "" << "Enter your account" << "\n\n";
        cout << setw(22) << "" << "Username: ";
        cin >> username;
        cout << "\n";
        cout << setw(22) << "" << "Password: ";
        cin >> password;
        cout << "\n";
        
        
        for(int i = 0; i < this->n; ++i) {
            if(username == (this->p + i)->getUsername() && password == (this->p + i)->getPassword()) {
                isStaff = true;
                if(username == "admin") {
                    isAdmin = true;
                }
                break;
            }
        }
        if(isStaff)  {
            cout << "Login successfully!\n";
            break;
        } else {
            cout << "Invalid login information!\n";
        }
        system("pause"); 
    }
}
