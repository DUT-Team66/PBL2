#include <iostream>
#include "PhoneManager.h"
#include <string>
#include <fstream>
using namespace std;


PhoneManager::PhoneManager()
{
    this->p = nullptr;
    this->n = 0;
}
PhoneManager::~PhoneManager()
{
    delete[] this->p;
}
int PhoneManager::getlength()
{
    return this->n;
}
void PhoneManager::Add(const Phone& s)
{
    if(this->n==0) {
        this->p = new Phone[this->n+1];
        *(this->p+this->n) = s;
        this->n++;
    }
    else {
        Phone *temp = new Phone[this->n];
        for (int i=0;i<this->n;i++)
        {
            *(temp+i) = *(this->p+i);
        }
        delete[] this->p;
        this->p = new Phone[this->n+1];
        for (int i=0;i<this->n;i++)  // còn phần tử cuối
            *(this->p+i)=*(temp+i);
        delete[] temp;
        *(this->p+this->n) = s;
        this->n++;
    }
}
void PhoneManager::Delete(string m)
{
    int index=-1;
    for (int i=0;i<this->n;i++)
    {
        if((this->p+i)->getPhoneID() == m)
        {
            index=i;
            break;
        }
    }


    //Chu y truong hop index=-1(khong tim duoc)



    if (index >= 0)
    {
        if (this->n==1) {
            delete[] this->p;
            this->p=0;
            this->n--;
        }
        else {
            Phone *temp = new Phone[this->n];
            for (int i=0;i<this->n;i++)
            {
                *(temp+i) = *(this->p+i);
            }
            delete[] this->p;
            this->p = new Phone[this->n-1];
            for (int i=0;i<index;i++){
                *(p+i) = *(temp+i);
            }
            for (int i=index; i<this->n-1;i++){
                *(p+i)=*(temp+i+1);
            }
            delete[] temp;
            this->n--;
        }
    }
}
void PhoneManager::Search(string m)
{
    int index=-1;
    for (int i=0;i<this->n;i++)
    {
        if((this->p+i)->getPhoneID() == m)
        {
            index=i;
            break;
        }
    }

    if (index>=0) (this->p+index)->showForStaff();
    cout<<endl;

}
void PhoneManager::Show()
{
    int d=1;
    for (int i=0;i<this->n;i++)
    {
        cout<<d<<". ";
        (this->p+i)->showForStaff(); 
        d++; 
    }
   // cout<<endl;

}

void PhoneManager::SetData() {
    fstream readfile("Phone.txt", ios::in);
	string tmpline;
	while(getline(readfile,tmpline)) {
		
		string id = "", name = "", brand = "", processor = "", RAM_ROM = "", display = "", camera = "";
		
		
		int i = 0;
		while(tmpline[i] != '/') {
			name += tmpline[i];
			++i;
		}
		++i;
		while(tmpline[i] != '/') {
			id += tmpline[i];
			++i;
		}
        ++i;
        while(tmpline[i] != '/') {
			brand += tmpline[i];
			++i;
		}
        ++i;
        while(tmpline[i] != '/') {
			processor += tmpline[i];
			++i;
		}
        ++i;
        while(tmpline[i] != '/') {
			RAM_ROM += tmpline[i];
			++i;
		}
        ++i;
        while(tmpline[i] != '/') {
			display += tmpline[i];
			++i;
		}
        ++i;
		while(tmpline[i] != '/') {
			camera += tmpline[i];
			++i;
		}


        this->Add(Phone(name,id,brand,processor,RAM_ROM,display,camera));


    }
    readfile.close();
}