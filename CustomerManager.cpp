#include <iostream>
#include "CustomerManager.h"
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

CustomerManager::CustomerManager()
{
    this->pHead = nullptr;
    this->pTail=nullptr;
    this->n=0;
}
CustomerManager::~CustomerManager()
{
    Node *k;  
    while (this->pHead!=NULL)
    {
        k=this->pHead;
        this->pHead=this->pHead->pNext;
        delete k;
    }
    this->pTail=NULL;
    delete this->pHead;
    delete this->pTail;
}
int CustomerManager::GetLength()
{
    return this->n;
}
void CustomerManager::Add(const Customer& s)
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
void CustomerManager::Delete(string m)
{
    int index=-1;
    if (this->pHead->data.getCustomerID()==m)
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
        if (this->pTail->data.getCustomerID()==m)
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
                if (k->data.getCustomerID()==m)
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
        cout << "CustomerID does not exist!\n";
    }
}
void CustomerManager::Search(string m)
{
    int index=-1;
    for (Node *k=this->pHead;k!=NULL;k=k->pNext)
    {
         if (k->data.getCustomerID()==m)
        {
            index=1;
            k->data.Show();    // chưa vẽ bảng
            break;
        }
    }
    if (index==-1) cout << "CustomerID does not exist!\n";
    cout<<endl;
}
void CustomerManager::Show()   // Chưa vẽ bảng
{
    int d=1;
    for (Node *k=this->pHead;k!=NULL;k=k->pNext)
    {
        cout << setw(2) << d<< ". ";
        d++;
        k->data.Show(); 
    }

}



void CustomerManager::LoadData() {
    fstream readfile("Customer.txt", ios::in);
	string tmpline;
	while(getline(readfile,tmpline)) {
		
		string customerID = "", customerName = "", customerPhoneNumber = "", customerAddress = "";
		int i = 0;
		while(tmpline[i] != '/') {
			customerID += tmpline[i];
			++i;
		}
		++i;
		while(tmpline[i] != '/') {
			customerName += tmpline[i];
			++i;
		}
        ++i;
        while(tmpline[i] != '/') {
			customerPhoneNumber += tmpline[i];
			++i;
		}
        ++i;
        while(tmpline[i] != '/') {
			customerAddress += tmpline[i];
			++i;
		}
        ++i;
        this->Add(Customer(customerID,customerName,customerName,customerAddress));


    }
    readfile.close();
}
void CustomerManager::UpdateFile() {
    fstream editfile("Customer.txt", ios::out);
    int d=0;
    for (Node *k=this->pHead;k!=NULL;k=k->pNext) {
        string s = k->data.getCustomerID() + "/" + k->data.getCustomerName() + "/" + k->data.getCustomerPhoneNumber() + "/" + k->data.getCustomerAddress() + "/" ;
        if(d != this->n-1) editfile << s << "\n";
        else editfile << s;
        d++;
    }
    editfile.close();
}
void CustomerManager::Menu() {
    std::system("cls");
    while(true) {
        int choice;
        while(true) {
            
            cout << setw(25) << "" << "Customers" << "\n\n";
            cout << setw(22) << "" << "1. Add Customer" << "\n"; 
            cout << setw(22) << "" << "2. Delete Customer" << "\n"; 
            cout << setw(22) << "" << "3. Search Customer" << "\n"; 
            cout << setw(22) << "" << "4. Show all Customers" << "\n";
            cout << setw(22) << "" << "5. Go back" << "\n\n";
            
            cout << setw(20) << "" << "Your choice: ";
            cin >> choice;
            if(choice != 1 && choice != 2 && choice !=3 && choice != 4 && choice != 5) {
                cout << "Invalid choice, please re-enter!\n";
                std::system("pause");
                std::system("cls"); 
            } else break;
        }
        if(choice == 1) 
        {
            Customer p;
            string customerID;
            cout << setw(45) << "" << "Enter ID: ";
            cin.ignore();
            getline(cin, customerID);
            Node *tmp = this->pHead;
            bool checkExist = false;
            while(tmp != nullptr) {
                if(tmp->data.getCustomerID() == customerID) {
                    checkExist = true;
                    break;
                }
                tmp = tmp->pNext;
            }
            if(!checkExist) {
                string customerName, customerPhoneNumber, customerAddress;
                
                while (true)
                {
                    cout<<setw(45)<<""<<"Enter phonenumber: ";
                    getline(cin,customerPhoneNumber);       
                    bool checkLegal = true;
                    for(int i = 0; i < customerPhoneNumber.length(); ++i) {
                        if(customerPhoneNumber[i] < '0' || customerPhoneNumber[i] > '9') {
                            checkLegal = false;
                            break;
                        }
                    }
                    if(!checkLegal || customerPhoneNumber.length() != 10) {
                        cout << setw(45) << "" << "Invalid phone number, phone number must contain 10 digits!\n";
                        std::system("pause");
                        std::system("cls");
                    } 
                    else break;
                }
                cout << setw(45) << "" << "Enter name: ";
                getline(cin, customerName);
                cout<<setw(45)<<""<<"Enter Address: ";
                getline(cin,customerAddress);
                this->Add(Customer(customerID,customerName,customerAddress,customerAddress));
                cout << setw(45) << "" << "Add successfully!\n";
            } 
            else {
                cout << setw(45) << "" << "Customer exists!\n";
                tmp->data.Show();
            }
        } else if (choice == 2) {
            this->Show();         // Kẻ bảng    
            string s;
            cout << "Enter ID: ";
            cin >> s;
            this->Delete(s);
        } else if(choice == 3) {
            string s;
            cout << "Enter ID:";
            cin >> s;
            this->Search(s);
        
        } else if(choice == 4) {
            this->Show();   // Kẻ bảng
        } else {
            std::system("cls");
            break;  
        }
        std::system("pause");
        std::system("cls");
    }
   
}
const CustomerManager& CustomerManager::operator=(const CustomerManager& v )
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

