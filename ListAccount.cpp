#include <iostream>
#include <string>
#include "ListAccount.h"
using namespace std;

ListAccount::ListAccount() {
	this-> p = nullptr;
	this->n = 0;
}
ListAccount::~ListAccount() {
	delete[] this->p;
}
void ListAccount::SetData() 
{	

	fstream readfile("Account.txt", ios::in);
	string tmpacc;
	while(getline(readfile,tmpacc)) {
		
		string username = "", password = "";
		
		
		int i = 0;
		while(tmpacc[i] != '/') {
			username += tmpacc[i];
			++i;
		}
		++i;
		while(tmpacc[i] != '/') {
			password += tmpacc[i];
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


void ListAccount::ShowData()
{
    for(int i = 0; i < this->n; ++i) {
        p[i].showData();
    }
}
