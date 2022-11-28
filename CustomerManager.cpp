#include <iostream>
#include "CustomerManager.h"
#include <string>
#include <fstream>
#include <iomanip>
#include "Table.h"
#include <windows.h>
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
    if (this->pHead->data.getCustomerPhoneNumber()==m)
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
        if (this->pTail->data.getCustomerPhoneNumber()==m)
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
                if (k->data.getCustomerPhoneNumber()==m)
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
        cout << "Customer does not exist!\n";
    }
}
void CustomerManager::Search(string m)
{
    int index=-1;
    for (Node *k=this->pHead;k!=NULL;k=k->pNext)
    {
         if (k->data.getCustomerPhoneNumber()==m)
        {
            index=1;
            k->data.Show();    // chưa vẽ bảng
            break;
        }
    }
    if (index==-1) cout << "CustomerID does not exist!\n";
    cout<<endl;
}
void CustomerManager::Show() const  
{
    cout << topLeftCorner << line(7); //order
    cout << topMid << line(30); // customer name
    cout << topMid << line(14); // customer phone number
    cout << topMid << line(26); // address
    cout << topRightCorner << "\n";
    
    cout << col << setw(1) << "" << setw(6) << left << "Order";
    cout << col << setw(13) << "" << setw(30 - 13) << left << "Name";
    cout << col << setw(1) << "" << setw(14 - 1) << left << "Phone number";
    cout << col << setw(9) << "" << setw(26 - 9) << left << "Address";
    cout << col << "\n";
    
    int i = 1;
    for(Node *tmp = this->pHead; tmp != nullptr; tmp = tmp->pNext) {
        std::cout << leftSide << line(7);
        std::cout << midMid << line(30);
        std::cout << midMid << line(14);
        std::cout << midMid << line(26);
        std::cout << rightSide << "\n";

        std::cout << col << setw((7 - to_string(i).length())/2) << "" << setw(7 - (7 - to_string(i).length())/2) << left << i ; ++i;
        std::cout << col << setw((30 - tmp->data.getCustomerName().length())/2) << "" << setw(30 - (30 - tmp->data.getCustomerName().length())/2) << left << tmp->data.getCustomerName();
        std::cout << col << setw((14 - tmp->data.getCustomerPhoneNumber().length())/2) << "" << setw(14 - (14 - tmp->data.getCustomerPhoneNumber().length())/2) << left << tmp->data.getCustomerPhoneNumber();
        std::cout << col << setw(26 - (26 - tmp->data.getCustomerAddress().length())/2) << right << tmp->data.getCustomerAddress() << setw((26 - tmp->data.getCustomerAddress().length())/2) << "";
        std::cout << col << "\n";
        
    }
    cout << botLeftCorner << line(7);
    cout << botMid << line(30);
    cout << botMid << line(14);
    cout << botMid << line(26);
    cout << botRightCorner << "\n";

}
void CustomerManager::setInfo(Customer& customer) {

    while(true) {
        cout << "\n";
        cout << setw(45) << "" << "Enter your information: " << "\n\n";

    
        string phoneNumber;
        cout << setw(42) << "" << "Phone number: ";
        cin >> phoneNumber;
        bool checkLegal = true;
        for(int i = 0; i < phoneNumber.length(); ++i) {
            if(phoneNumber[i] < '0' || phoneNumber[i] > '9') {
                checkLegal = false;
                break;
            }
        }
        if(!checkLegal || phoneNumber.length() != 10) {
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hConsole, 12);

            std::cout << setw(42) << "" << "Invalid phone number!\n";
            SetConsoleTextAttribute(hConsole, 15);

            std::system("pause");
            std::system("cls");
            continue;
        }
        bool checkExist = false;
        Node *tmp = this->pHead;
        while(tmp != nullptr) {
            if(phoneNumber == tmp->data.getCustomerPhoneNumber()) {
                checkExist = true;
                break;
            }
            tmp = tmp->pNext;
        }
        if(!checkExist) {
            cin.ignore();
            string name, address;
            cout << setw(42) << "" << "Name: ";
            getline(cin, name);
            
            cout << setw(42) << "" << "Address: ";
            getline(cin, address);

            customer.setCustomerPhoneNumber(phoneNumber);
            customer.setCustomerName(name);
            customer.setCustomerAddress(address);

        } else {
            cout << setw(42) << "" << "Customer exists!\n";
            customer = tmp->data;
            customer.Show();
            std::system("pause");   
        }
        string choice;
        while(true) {
            std::system("cls");
            cout << "\n";
            cout << setw(45) << "" << "Enter your information: " << "\n\n";
            cout << setw(42) << "" << "Phone number: " << phoneNumber << "\n";
            customer.Show();
            std::cout << "\n";
            std::cout << setw(42) << "" << "Enter B to re-enter information" << "\n";
            std::cout << setw(42) << "" << "Enter C to continue" << "\n";
            std::cout << setw(42) << "" << "Your choice: ";
            std::cin >> choice;
            if(choice != "B" && choice != "C") {
                std::cout << setw(42) << "" << "Invalid choice!\n";
                std::system("pause");
            } else break;
        }
        if(choice == "C") {
            break;
        }
        std::system("cls");
    }
}
void CustomerManager::LoadData() {
    fstream readfile("Customer.txt", ios::in);
	string tmpline;
	while(getline(readfile,tmpline)) {
		
		string customerName = "", customerPhoneNumber = "", customerAddress = "";
		int i = 0;
		while(tmpline[i] != '/') {
			customerPhoneNumber += tmpline[i];
			++i;
		}
        ++i;
		while(tmpline[i] != '/') {
			customerName += tmpline[i];
			++i;
		}
        ++i;
        while(tmpline[i] != '/') {
			customerAddress += tmpline[i];
			++i;
		}
        ++i;
        this->Add(Customer(customerPhoneNumber,customerName,customerAddress));


    }
    readfile.close();
}
void CustomerManager::UpdateFile() {
    fstream editfile("Customer.txt", ios::out);
    int d=0;
    for (Node *k=this->pHead;k!=NULL;k=k->pNext) {
        string s = k->data.getCustomerPhoneNumber() + "/" + k->data.getCustomerName() + "/" + k->data.getCustomerAddress() + "/" ;
        if(d != this->n-1) editfile << s << "\n";
        else editfile << s;
        d++;
    }
    editfile.close();
}
void CustomerManager::Menu() {
    std::system("cls");
    while(true) {
        string choice;
        while(true) {
            
            cout << setw(50) << "" << topLeftCorner << line(11) << topRightCorner << "\n";
            cout << setw(50) << "" << col << " CUSTOMERS " << col << "\n";
            cout << setw(50) << "" << botLeftCorner << line(11) << botRightCorner << "\n\n";
            cout << setw(47) << "" << "1. Search by name" << "\n"; 
            cout << setw(47) << "" << "2. Search by phone number" << "\n"; 
            cout << setw(47) << "" << "3. Search by address" << "\n"; 
            cout << setw(47) << "" << "4. Show all Customers" << "\n";
            cout << setw(47) << "" << "5. Go back" << "\n\n";
        
            cout << setw(45) << "" << "Your choice: ";
            cin >> choice;
            if(choice != "1" && choice != "2" && choice != "3" && choice != "4" && choice != "5") {
                cout << "Invalid choice, please re-enter!\n";
                std::system("pause");
                std::system("cls"); 
            } else break;
        }
        if(choice == "1") { // search by name
            std::cout << setw(45) << "" << "Enter name: ";
            string name;
            cin.ignore();
            std::getline(std::cin, name);
            for(int i = 0; i < name.length(); ++i) {
                name[i] = tolower(name[i]);
            }
            bool checkExist = false;
            for(Node *tmp = this->pHead; tmp != nullptr; tmp = tmp->pNext) {
                string tmps = "";
                for(int j = 0; j < tmp->data.getCustomerName().length(); ++j){
                    tmps += tolower(tmp->data.getCustomerName()[j]);
                }
                if(tmps.find(name) != -1) {
                    checkExist = true;
                    break;
                }
            }
            
            if(checkExist) {
                cout << topLeftCorner << line(30);
                cout << topMid << line(14);
                cout << topMid << line(26);
                cout << topRightCorner << "\n";
                
                cout << col << setw(13) << "" << setw(30 - 13) << left << "Name";
                cout << col << setw(1) << "" << setw(14 - 1) << left << "Phone number";
                cout << col << setw(9) << "" << setw(26 - 9) << left << "Address";
                cout << col << "\n";

                for(Node *tmp = this->pHead; tmp != nullptr; tmp = tmp->pNext) {
                    string tmps = "";
                    for(int j = 0; j < tmp->data.getCustomerName().length(); ++j){
                        tmps += tolower(tmp->data.getCustomerName()[j]);
                    }
                    if(tmps.find(name) != -1) { 
                        std::cout << leftSide << line(30);
                        std::cout << midMid << line(14);
                        std::cout << midMid << line(26);
                        std::cout << rightSide << "\n";

                        std::cout << col << setw((30 - tmp->data.getCustomerName().length())/2) << "" << setw(30 - (30 - tmp->data.getCustomerName().length())/2) << left << tmp->data.getCustomerName();
                        std::cout << col << setw((14 - tmp->data.getCustomerPhoneNumber().length())/2) << "" << setw(14 - (14 - tmp->data.getCustomerPhoneNumber().length())/2) << left << tmp->data.getCustomerPhoneNumber();
                        std::cout << col << setw(26 - (26 - tmp->data.getCustomerAddress().length())/2) << right << tmp->data.getCustomerAddress() << setw((26 - tmp->data.getCustomerAddress().length())/2) << "";
                        std::cout << col << "\n";
                    }
                }
                cout << botLeftCorner << line(30);
                cout << botMid << line(14);
                cout << botMid << line(26);
                cout << botRightCorner << "\n";
            } else {
                cout << setw(45) << "" << "No customers found!\n";
            }

            // std::system("pause");

        } else if (choice == "2") { // search by phone number
            std::cout << setw(45) << "" << "Enter phone number: " << "\n";
            string phoneNumber;
            std:: cin >> phoneNumber;
            bool checkExist = false;
            for(Node *tmp = this->pHead; tmp != nullptr; tmp = tmp->pNext) {
                if(tmp->data.getCustomerPhoneNumber().find(phoneNumber) != -1) {
                    checkExist = true;
                    break;
                }
            }
            
            if(checkExist) {
                cout << topLeftCorner << line(30);
                cout << topMid << line(14);
                cout << topMid << line(26);
                cout << topRightCorner << "\n";
                
                cout << col << setw(13) << "" << setw(30 - 13) << left << "Name";
                cout << col << setw(1) << "" << setw(14 - 1) << left << "Phone number";
                cout << col << setw(9) << "" << setw(26 - 9) << left << "Address";
                cout << col << "\n";

                for(Node *tmp = this->pHead; tmp != nullptr; tmp = tmp->pNext) {
                    if(tmp->data.getCustomerPhoneNumber().find(phoneNumber) != -1) { 
                        std::cout << leftSide << line(30);
                        std::cout << midMid << line(14);
                        std::cout << midMid << line(26);
                        std::cout << rightSide << "\n";

                        std::cout << col << setw((30 - tmp->data.getCustomerPhoneNumber().length())/2) << "" << setw(30 - (30 - tmp->data.getCustomerPhoneNumber().length())/2) << left << tmp->data.getCustomerName();
                        std::cout << col << setw((14 - tmp->data.getCustomerPhoneNumber().length())/2) << "" << setw(14 - (14 - tmp->data.getCustomerPhoneNumber().length())/2) << left << tmp->data.getCustomerPhoneNumber();
                        std::cout << col << setw(26 - (26 - tmp->data.getCustomerAddress().length())/2) << right << tmp->data.getCustomerAddress() << setw((26 - tmp->data.getCustomerAddress().length())/2) << "";
                        std::cout << col << "\n";
                    }
                }
                cout << botLeftCorner << line(30);
                cout << botMid << line(14);
                cout << botMid << line(26);
                cout << botRightCorner << "\n";
            } else {
                cout << setw(45) << "" << "No customers found!\n";
            }

            // std::system("pause");
        } else if(choice == "3") { // search by address
           std::cout << setw(45) << "" << "Enter address: " << "\n";
            string address;
            cin.ignore();
            std::getline(std::cin, address);
            for(int i = 0; i < address.length(); ++i) {
                address[i] = tolower(address[i]);
            }
            bool checkExist = false;
            for(Node *tmp = this->pHead; tmp != nullptr; tmp = tmp->pNext) {
                if(tmp->data.getCustomerAddress().find(address) != -1) {
                    checkExist = true;
                    break;
                }
            }
            
            if(checkExist) {
                cout << topLeftCorner << line(30);
                cout << topMid << line(14);
                cout << topMid << line(26);
                cout << topRightCorner << "\n";
                
                cout << col << setw(13) << "" << setw(30 - 13) << left << "Name";
                cout << col << setw(1) << "" << setw(14 - 1) << left << "Phone number";
                cout << col << setw(9) << "" << setw(26 - 9) << left << "Address";
                cout << col << "\n";

                for(Node *tmp = this->pHead; tmp != nullptr; tmp = tmp->pNext) {
                    string tmps = "";
                    for(int j = 0; j < tmp->data.getCustomerAddress().length(); ++j){
                        tmps += tolower(tmp->data.getCustomerAddress()[j]);
                    }
                    if(tmps.find(address) != -1) { 
                        std::cout << leftSide << line(30);
                        std::cout << midMid << line(14);
                        std::cout << midMid << line(26);
                        std::cout << rightSide << "\n";

                        std::cout << col << setw((30 - tmp->data.getCustomerName().length())/2) << "" << setw(30 - (30 - tmp->data.getCustomerName().length())/2) << left << tmp->data.getCustomerName();
                        std::cout << col << setw((14 - tmp->data.getCustomerPhoneNumber().length())/2) << "" << setw(14 - (14 - tmp->data.getCustomerPhoneNumber().length())/2) << left << tmp->data.getCustomerPhoneNumber();
                        std::cout << col << setw(26 - (26 - tmp->data.getCustomerAddress().length())/2) << right << tmp->data.getCustomerAddress() << setw((26 - tmp->data.getCustomerAddress().length())/2) << "";
                        std::cout << col << "\n";
                    }
                }
                cout << botLeftCorner << line(30);
                cout << botMid << line(14);
                cout << botMid << line(26);
                cout << botRightCorner << "\n";
            } else {
                cout << setw(45) << "" << "No customers found!\n";
            }

        
        } else if(choice == "4") { // show all
            this->Show();   
            //std::system("pause");
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