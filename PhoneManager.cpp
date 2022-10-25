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
    else cout<<"PhoneID does not exist!"<<"\n}";
}
void PhoneManager::Update(string id){
    bool check = false;
    cin.ignore();
    for(int i = 0; i < this->n; ++i) {
        if((this->p + i)->getPhoneID() == id) {
            string phoneName, phoneID, brand, processor, RAM_ROM, display, camera ;
            int entryPrice, salePrice, remainingAmount; 
            cout<<"Enter phonename: ";
            getline(cin, phoneName);
            cout << "Enter phoneID: ";
            getline(cin,phoneID);
            cout << "Enter brand: ";
            getline(cin,brand);
            cout << "Enter processor: ";
            getline(cin, processor);
            cout<<"Enter RAM/ROM: ";
            getline(cin,RAM_ROM);
            cout<<"Enter display: ";
            getline(cin,display);
            cout<<"Enter camera: ";
            getline(cin,camera);
            cout<<"Enter entryprice: ";
            cin>>entryPrice;
            cout<<"Enter saleprice: ";
            cin>>salePrice;
            cout<<"Enter remainingamount: ";
            cin>> remainingAmount;
            if(phoneName != "") {
                (this->p+i)->setPhoneName(phoneName);
            } 
            if(phoneID != "") {
                (this->p+i)->setPhoneID(phoneID);
            }
            if(brand != "") {
                (this->p+i)->setBrand(brand);
            }
            if(processor != "") {
                (this->p+i)->setProcessor(processor);
            }
            if(RAM_ROM != "") {
                (this->p+i)->setRAM_ROM(RAM_ROM);
            } 
            if(display != "") {
                (this->p+i)->setDisplay(display);
            }
            if(camera != "") {
                (this->p+i)->setCamera(camera);
            }
            if (entryPrice != 0) {
                (this->p+i)->setEntryPrice(entryPrice);
            }
            if (salePrice != 0 ){
                (this->p+i)->setSalePrice(salePrice);
            }
            if (remainingAmount!=-1) {
                (this->p+i)->setRemainingAmount(remainingAmount);
            }
            check = true;
            break;  
        }
    }
    if(!check) cout << "PhoneID does not exist!" << "\n";
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
const PhoneManager& PhoneManager::operator=(const PhoneManager& v )
{
    if (this != &v) {
        this->n=v.n;
        delete[] this->p;
        this->p = new Phone[this->n];
        for (int i=0;i<this->n;i++)
            *(this->p + i) = *(v.p+i); 
    }
    return *this;
}
