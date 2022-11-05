#include <iostream>
#include "PhoneManager.h"
#include <string>
#include <fstream>
#include <iomanip>
//#include "Table.h"
using namespace std;

PhoneManager::PhoneManager()
{
    this->pHead = nullptr;
    this->pTail=nullptr;
    this->n=0;
}
PhoneManager::~PhoneManager()
{
    delete this->pHead;
    delete this->pTail;
}
int PhoneManager::GetLength()
{
    return this->n;
}
void PhoneManager::Add(const Phone& s)
{
    Node *p= new Node;
    if (p==NULL)
    {
        cout<<"\nKhong du bo nho de cap phat\n"<<endl;
    }
    p->data=s;
    p->pNext=NULL;
    if (this->pHead==NULL)
    {
        this->pHead=this->pTail=p;
    }
    else
    {
        this->pTail->pNext=p;
        this->pTail=p;
    }
    this->n++;
}
void PhoneManager::Delete(string m)
{
    int index=-1;
    if (this->pHead->data.getPhoneID()==m)
    {
        if (this->pTail==this->pHead)
        {
            this->pHead=this->pTail=NULL;
            this->n--;
            index=1;
        }
        else {
            Node *p=this->pHead;
            this->pHead=this->pHead->pNext;
            delete p;
            this->n--;
            index=1;
        }
    }
    else 
        if (this->pTail->data.getPhoneID()==m)
        {
            for (Node *k=this->pHead;k!=NULL;k=k->pNext)
            {
                if (k->pNext==this->pTail)
                {
                    delete this->pTail;
                    k->pNext=NULL;
                    this->pTail=k;
                    this->n--;
                    index=1;
                }
            }
        }
        else {
            Node *g=new Node;
            for (Node *k=this->pHead;k!=NULL;k=k->pNext)
            {
                if (k->data.getPhoneID()==m)
                {
                    g->pNext=k->pNext;
                    delete k;
                    this->n--;
                    index=1;
                    break;
                }
                else g=k; 
            }
        }
    
    //Chu y truong hop index=-1(khong tim duoc)
    if (index==1) cout<<"Delete successfully!\n";
    else {
        cout << "PhoneID does not exist!\n";
    }
}
void PhoneManager::Update(string m){
    bool check = false;
    cin.ignore();
    for (Node *k=this->pHead;k!=NULL;k=k->pNext) {
        if(k->data.getPhoneID()==m) {
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
                k->data.setPhoneName(phoneName);
            } 
            if(phoneID != "") {
                k->data.setPhoneID(phoneID);
            }
            if(brand != "") {
                k->data.setBrand(brand);
            }
            if(processor != "") {
                k->data.setProcessor(processor);
            }
            if(RAM_ROM != "") {
                k->data.setRAM_ROM(RAM_ROM);
            } 
            if(display != "") {
                k->data.setDisplay(display);
            }
            if(camera != "") {
                k->data.setCamera(camera);
            }
            if (entryPrice != 0) {
                k->data.setEntryPrice(entryPrice);
            }
            if (salePrice != 0 ){
                k->data.setSalePrice(salePrice);
            }
            if (remainingAmount!=-1) {
                k->data.setRemainingAmount(remainingAmount);
            }
            cout << "Update successfully!\n";
            check = true;
            break;  
        }
    }
    if(!check) cout << "PhoneID does not exist!" << "\n";
}
void PhoneManager::Search(string m)
{
    int index=-1;
    for (Node *k=this->pHead;k!=NULL;k=k->pNext)
    {
         if (k->data.getPhoneID()==m)
        {
            index=1;
            k->data.showForStaff();
            break;
        }
    }

    
    if (index==-1) cout << "PhoneID does not exist!\n";
    cout<<endl;

}
const string& PhoneManager::getPhoneID(int index) {
    int pos=0;
    for (Node *k=this->pHead;k!=NULL;k=k->pNext)
    {
        if (pos==index) return k->data.getPhoneID();
        pos++;
    }
    return 0;
   // return (this->p + index)->getPhoneID();
}
void PhoneManager::Show()
{
    int d=1;
    for (Node *k=this->pHead;k!=NULL;k=k->pNext)
    {
        cout << setw(2) << d<< ". ";
        d++;
        k->data.showForStaff(); 
    }

}

void PhoneManager::ShowTable() {
    // for (int i=0;i<this->n;i+=2)
    // {
    //     cout<< setw(2) << right << i + 1 <<". " << setw(40) << left << k->data.getPhoneName()  << "" << i + 2 << ". " << k->pNext->data.getPhoneName() << "\n";
    // }
    // if(n & 1) {
    //     cout << this->n << ". " << (this->p + this->n - 1)->getPhoneName() << endl;
    // }
    int d=0;
    for (Node *k=this->pHead;k!=NULL;k=k->pNext)
    {
        cout<< setw(2) << right << d + 1 <<". " << setw(40) << left << k->data.getPhoneName()  << "" << d + 2 << ". " << k->pNext->data.getPhoneName() << "\n";
        d+=2;
        k=k->pNext;
    } 
    if(n & 1) {
        cout << this->n << ". " << this->pTail->data.getPhoneName() << endl;
    }  
}


void PhoneManager::Show(int index) {
    int pos=0;
    for (Node *k=this->pHead;k!=NULL;k=k->pNext)
    {
        if (pos==index) 
        {
            k->data.showForCustomer();
            break;
        }
        pos++;
    }
}
const int& PhoneManager::getPhonePrice(int index) {
    int pos=0;
    for (Node *k=this->pHead;k!=NULL;k=k->pNext)
    {
        if (pos==index) 
        {
            return k->data.getSalePrice();
        }
        pos++;
    }
    return 0;
}
const int& PhoneManager::getRemainingAmount(int index) {
    int pos=0;
    for (Node *k=this->pHead;k!=NULL;k=k->pNext)
    {
        
        if (pos==index) 
        {
            return k->data.getRemainingAmount();          
        }
        pos++;
    }
    return 0;
}
void PhoneManager::setRemainingAmount(int index, int amount) {
    int pos=0;
    for (Node *k=this->pHead;k!=NULL;k=k->pNext)
    {
        if (pos==index) 
        {
            //return k->data.getRemainingAmount();   
             k->data.setRemainingAmount(k->data.getRemainingAmount() - amount);
             return;     
        }
        pos++;
    }
   
}
void PhoneManager::LoadData() {
    fstream readfile("Phone.txt", ios::in);
	string tmpline;
	while(getline(readfile,tmpline)) {
		
		string id = "", name = "", brand = "", processor = "", RAM_ROM = "", display = "", camera = "";
		int entryprice = 0, saleprice = 0;
		
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
        ++i;
        while(tmpline[i] != '/') {
            entryprice = entryprice*10 + tmpline[i] - 48;
            ++i;
        }
        ++i;
        while(tmpline[i] != '/') {
            saleprice = saleprice*10 + tmpline[i] - 48;
            ++i;
        }
        ++i;


        this->Add(Phone(name,id,brand,processor,RAM_ROM,display,camera,entryprice,saleprice));


    }
    readfile.close();
}
void PhoneManager::UpdateFile() {
    fstream editfile("Phone.txt", ios::out);
    int d=0;
    for (Node *k=this->pHead;k!=NULL;k=k->pNext) {
        string s = k->data.getPhoneName() + "/" + k->data.getPhoneID() + "/" + k->data.getBrand() + "/" + k->data.getProcessor() + "/" + k->data.getRAM_ROM() + "/" + k->data.getDisplay() + "/" + k->data.getCamera() + "/" + to_string(k->data.getEntryPrice()) + "/" + to_string(k->data.getSalePrice()) + "/" ;
        if(d != this->n-1) editfile << s << "\n";
        else editfile << s;
        d++;
    }
    editfile.close();
}
void PhoneManager::Menu() {
    std::system("cls");
    while(true) {
        int choice;
        while(true) {
            
            // cout << setw(25) << "" << topLeftCorner << line(8) << topRightCorner << "\n";
	        // cout << setw(25) << "" << col << " PHONES " << col << "\n";
	        // cout << setw(25) << "" << botLeftCorner << line(8) << botRightCorner << "\n\n";
            cout << setw(25) << "" << "PHONES" << "\n\n";
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
        Node *k;  
        while (this->pHead!=NULL)
        {
            k=this->pHead;
            this->pHead=this->pHead->pNext;
            delete k;
        }
        this->pTail=NULL;
        for (Node *k=v.pHead;k!=NULL;k=k->pNext)
        {
            this->Add(k->data);
        }
        
    }
    return *this;
}

long long PhoneManager::GetVon()
{
    long long Von=0;
    for (Node *k=this->pHead;k!=NULL;k=k->pNext)
    {
        if (k->data.getRemainingAmount()<100) {
            Von+=(100-k->data.getRemainingAmount())*k->data.getEntryPrice();
            k->data.setRemainingAmount(100);
        }
    }
    return Von;
}