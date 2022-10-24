#include <iostream>
#include "PhoneManager.h"
#include <string>
#include <fstream>
#include <iomanip>
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
int PhoneManager::GetLength()
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
void PhoneManager::Update(string id){

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
const string& PhoneManager::getPhoneID(int index) {
    return (this->p + index)->getPhoneID();
}
void PhoneManager::Show()
{
    
    for (int i=0;i<this->n;i++)
    {
        cout<< i + 1 <<". ";
        (this->p+i)->showForStaff(); 
    }
   // cout<<endl;

}
void PhoneManager::ShowTable() {
    for (int i=0;i<this->n;i+=2)
    {
        cout<< i + 1 <<". " << setw(50) << left << (this->p+i)->getPhoneName()  << "" << i + 2 << ". " << (this->p + i + 1)->getPhoneName() << "\n";
    }
    if(n & 1) {
        cout << this->n << ". " << (this->p + this->n - 1)->getPhoneName() << endl;
    }
}
void PhoneManager::Show(int index) {
    (this->p+index)->showForCustomer();
}

const int& PhoneManager::getPhonePrice(int index) {
    return (this->p + index)->getSalePrice();
}
void PhoneManager::LoadData() {
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
void PhoneManager::Menu() {
    std::system("cls");
    while(true) {
        int choice;
        while(true) {
            
            cout << setw(25) << "" << "PHONES" << "\n\n\n";
            cout << setw(22) << "" << "1. Add phone" << "\n"; // nhap day du thong tin cua phone
            cout << setw(22) << "" << "2. Delete phone" << "\n"; // nhap phoneid
            cout << setw(22) << "" << "3. Search phone" << "\n"; // nhap phoneid
            cout << setw(22) << "" << "4. Update phone" << "\n";
            cout << setw(22) << "" << "5. Show all phones" << "\n";
            cout << setw(22) << "" << "6. Go back" << "\n\n";
            
            cout << setw(20) << "" << "Your choice: ";
            cin >> choice;
            if(choice != 1 && choice != 2 && choice !=3 && choice != 4 && choice != 5 && choice != 6) {
                cout << "Invalid choice, please re-enter!\n";
                std::system("pause");
                std::system("cls"); 
            } else break;
        }
        if(choice == 1) {
            Phone p;
            p.setInfo();
            this->Add(p);
            cout << "Add successfully!\n";
        } else if (choice == 2) {
            string s;
            cout << "Enter ID: ";
            cin >> s;
            this->Delete(s);
            cout << "Delete successfully!\n";
        } else if(choice == 3) {
            string s;
            cout << "Enter ID:";
            cin >> s;
            this->Search(s);
        } else if (choice == 4) {
            string s;
            cout << "Enter ID: ";
            cin >> s;
            this->Update(s);
            cout << "Update successfully!\n";
        } else if(choice == 5) {
            this->Show();
        } else {
            std::system("cls");
            break;  
        }
        std::system("pause");
        std::system("cls");
    }
    
}