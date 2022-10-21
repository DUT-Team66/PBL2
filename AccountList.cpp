
#include <fstream>
#include <iomanip>
#include "AccountList.h"
using namespace std;

AccountList::AccountList() {
	this-> p = nullptr;
	this->n = 0;
}
AccountList::~AccountList() {
	delete[] this->p;
}
void AccountList::SetData() 
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
    readfile.close();
		
	
}


void AccountList::showData()
{
    for(int i = 0; i < this->n; ++i) {
        cout << i + 1 << ". ";
        p[i].showData();
    }
}
void AccountList::login() {
    
    while(true) {
        string username, password;
        cout << setw(20) << "" << "Enter your account" << "\n\n";
        cout << setw(22) << "" << "Username: ";
        cin >> username;
        cout << "\n";
        cout << setw(22) << "" << "Password: ";
        cin >> password;
        cout << "\n";
        
        bool check = 0;
        for(int i = 0; i < this->n; ++i) {
            if(username == (this->p + i)->getUsername() && password == (this->p + i)->getPassword()) {
                check = 1;
                break;
            }
        }
        if(check) {
            cout << "Login successfull!\n";
            break;
        } else {
            cout << "Invalid login information!\n";
        }
        system("pause"); 
    }
}
