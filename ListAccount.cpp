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
	string name, pass;
	while(cin >> name && cin >> pass) {
		Account tmp(name, pass);

		if(this->n==0) 
        {
            this->p = new Account[this->n+1];
            *(this->p+this->n) = tmp;
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
            for (int i=0;i<this->n;i++)  // còn phần tử cuối
                *(this->p+i)=*(temp+i);
            delete[] temp;
            *(this->p+this->n) = tmp;
            this->n++;
        }
        //tmp.showData();
    }
		
	
}


void ListAccount::ShowData()
{
    for(int i = 0; i < this->n; ++i) {
        p[i].showData();
    }
}
