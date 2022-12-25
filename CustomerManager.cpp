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
    
}
CustomerManager::~CustomerManager()
{
    
}
int CustomerManager::GetLength()
{
    return this->list.size();
}
void CustomerManager::Add(const Customer& s)
{
    this->list.Add(s);
}
void CustomerManager::Delete(string m)
{
    this->list.Delete(m);
}
void CustomerManager::Search()
{
    // int index=-1;
    // for (Node *k=this->pHead;k!=NULL;k=k->pNext)
    // {
    //      if (k->data.getCustomerPhoneNumber()==m)
    //     {
    //         index=1;
    //         k->data.Show();    // chưa vẽ bảng
    //         break;
    //     }
    // }
    // if (index==-1) cout << "CustomerID does not exist!\n";
    // cout<<endl;
}
void CustomerManager::Show()  
{
    std::cout << setw(15) << "" << topLeftCorner << line(7); //order
    std::cout << topMid << line(30); // customer name
    std::cout << topMid << line(14); // customer phone number
    std::cout << topMid << line(26); // address
    std::cout << topRightCorner << "\n";
    
    std::cout << setw(15) << "" << col << setw(1) << "" << setw(6) << left << "Order";
    std::cout << col << setw(13) << "" << setw(30 - 13) << left << "Name";
    std::cout << col << setw(1) << "" << setw(14 - 1) << left << "Phone number";
    std::cout << col << setw(9) << "" << setw(26 - 9) << left << "Address";
    std::cout << col << "\n";
    
    int i = 1;
    for(Node<Customer> *tmp = this->list.HeadNode(); tmp != nullptr; tmp = tmp->NextNode()) {
         std::cout << setw(15) << "" << leftSide << line(7);
         std::cout << midMid << line(30);
         std::cout << midMid << line(14);
         std::cout << midMid << line(26);
         std::cout << rightSide << "\n";

         std::cout << setw(15) << "" << col << setw((7 - to_string(i).length())/2) << "" << setw(7 - (7 - to_string(i).length())/2) << left << i ; ++i;
         std::cout << col << setw((30 - tmp->Data().getCustomerName().length())/2) << "" << setw(30 - (30 - tmp->Data().getCustomerName().length())/2) << left << tmp->Data().getCustomerName();
         std::cout << col << setw((14 - tmp->Data().getCustomerPhoneNumber().length())/2) << "" << setw(14 - (14 - tmp->Data().getCustomerPhoneNumber().length())/2) << left << tmp->Data().getCustomerPhoneNumber();
         std::cout << col << setw(26 - (26 - tmp->Data().getCustomerAddress().length())/2) << right << tmp->Data().getCustomerAddress() << setw((26 - tmp->Data().getCustomerAddress().length())/2) << "";
         std::cout << col << "\n";
        
    }
    std::cout << setw(15) << "" << botLeftCorner << line(7);
    std::cout << botMid << line(30);
    std::cout << botMid << line(14);
    std::cout << botMid << line(26);
    std::cout << botRightCorner << "\n";

}
bool CustomerManager::setInfo(Customer& customer) {
    bool res = false;
    while(true) {
        std::cout << "\n";
        std::cout << setw(45) << "" << "Enter your information: " << "\n\n";

    
        string phoneNumber;
        std::cout << setw(42) << "" << arrow << " Phone number: ";
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
        Node<Customer> *tmp = this->list.HeadNode();
        while(tmp != nullptr) {
            if(phoneNumber == tmp->Data().getCustomerPhoneNumber()) {
                checkExist = true;
                break;
            }
            tmp = tmp->NextNode();
        }
        if(!checkExist) {
            cin.ignore();
            string name, address;
            std::cout << setw(42) << "" << arrow << " Name: ";
            getline(cin, name);
            
            std::cout << setw(42) << "" << arrow << " Address: ";
            getline(cin, address);

            customer.setCustomerPhoneNumber(phoneNumber);
            customer.setCustomerName(name);
            customer.setCustomerAddress(address);
        } else {
            std::cout << setw(42) << "" << "Customer exists!\n";
            customer = tmp->Data();
            customer.show();
            std::system("pause");   
            res = true;
        }
        string choice;
        while(true) {
            std::system("cls");
            std::cout << "\n";
            std::cout << setw(45) << "" << "Enter your information: " << "\n\n";
            std::cout << setw(42) << "" << "Phone number: " << phoneNumber << "\n";
            customer.show();
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
    return res;
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
    for (Node<Customer> *tmp = this->list.HeadNode(); tmp != nullptr; tmp = tmp->NextNode()) {
        string s = tmp->Data().getCustomerPhoneNumber() + "/" + tmp->Data().getCustomerName() + "/" + tmp->Data().getCustomerAddress() + "/" ;
        if(d != this->list.size() - 1) editfile << s << "\n";
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
            
            std::cout << setw(50) << "" << topLeftCorner << line(11) << topRightCorner << "\n";
            std::cout << setw(50) << "" << col << " CUSTOMERS " << col << "\n";
            std::cout << setw(50) << "" << botLeftCorner << line(11) << botRightCorner << "\n\n";
            std::cout << setw(47) << "" << "1. Search by name" << "\n"; 
            std::cout << setw(47) << "" << "2. Search by phone number" << "\n"; 
            std::cout << setw(47) << "" << "3. Search by address" << "\n"; 
            std::cout << setw(47) << "" << "4. Show all Customers" << "\n";
            std::cout << setw(47) << "" << "5. Go back" << "\n\n";
        
            std::cout << setw(45) << "" << "Your choice: ";
            cin >> choice;
            if(choice != "1" && choice != "2" && choice != "3" && choice != "4" && choice != "5") {
                HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(hConsole, brightred); 
                std::cout << "Invalid choice, please re-enter!\n";
                SetConsoleTextAttribute(hConsole, brightwhite); 
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
            for(Node<Customer> *tmp = this->list.HeadNode(); tmp != nullptr; tmp = tmp->NextNode()) {
                string tmps = "";
                for(int j = 0; j < tmp->Data().getCustomerName().length(); ++j){
                    tmps += tolower(tmp->Data().getCustomerName()[j]);
                }
                if(tmps.find(name) != -1) {
                    checkExist = true;
                    break;
                }
            }
            
            if(checkExist) {
                std::cout << setw(15) << "" << topLeftCorner << line(30);
                std::cout << topMid << line(14);
                std::cout << topMid << line(26);
                std::cout << topRightCorner << "\n";
                
                std::cout << setw(15) << "" << col << setw(13) << "" << setw(30 - 13) << left << "Name";
                std::cout << col << setw(1) << "" << setw(14 - 1) << left << "Phone number";
                std::cout << col << setw(9) << "" << setw(26 - 9) << left << "Address";
                std::cout << col << "\n";

                for(Node<Customer> *tmp = this->list.HeadNode(); tmp != nullptr; tmp = tmp->NextNode()) {
                    string tmps = "";
                    for(int j = 0; j < tmp->Data().getCustomerName().length(); ++j){
                        tmps += tolower(tmp->Data().getCustomerName()[j]);
                    }
                    if(tmps.find(name) != -1) { 
                         std::cout << setw(15) << "" << leftSide << line(30);
                         std::cout << midMid << line(14);
                         std::cout << midMid << line(26);
                         std::cout << rightSide << "\n";

                         std::cout << setw(15) << "" << col << setw((30 - tmp->Data().getCustomerName().length())/2) << "" << setw(30 - (30 - tmp->Data().getCustomerName().length())/2) << left << tmp->Data().getCustomerName();
                         std::cout << col << setw((14 - tmp->Data().getCustomerPhoneNumber().length())/2) << "" << setw(14 - (14 - tmp->Data().getCustomerPhoneNumber().length())/2) << left << tmp->Data().getCustomerPhoneNumber();
                         std::cout << col << setw(26 - (26 - tmp->Data().getCustomerAddress().length())/2) << right << tmp->Data().getCustomerAddress() << setw((26 - tmp->Data().getCustomerAddress().length())/2) << "";
                         std::cout << col << "\n";
                    }
                }
                std::cout << setw(15) << "" << botLeftCorner << line(30);
                std::cout << botMid << line(14);
                std::cout << botMid << line(26);
                std::cout << botRightCorner << "\n";
            } else {
                std::cout << setw(45) << "" << "No customers found!\n";
            }

            // std::system("pause");

        } else if (choice == "2") { // search by phone number
             std::cout << setw(45) << "" << "Enter phone number: ";
            string phoneNumber;
            std:: cin >> phoneNumber;
            bool checkExist = false;
            for(Node<Customer> *tmp = this->list.HeadNode(); tmp != nullptr; tmp = tmp->NextNode()) {
                if(tmp->Data().getCustomerPhoneNumber().find(phoneNumber) != -1) {
                    checkExist = true;
                    break;
                }
            }
            
            if(checkExist) {
                std::cout << setw(15) << "" << topLeftCorner << line(30);
                std::cout << topMid << line(14);
                std::cout << topMid << line(26);
                std::cout << topRightCorner << "\n";
                
                std::cout << setw(15) << "" << col << setw(13) << "" << setw(30 - 13) << left << "Name";
                std::cout << col << setw(1) << "" << setw(14 - 1) << left << "Phone number";
                std::cout << col << setw(9) << "" << setw(26 - 9) << left << "Address";
                std::cout << col << "\n";

                for(Node<Customer> *tmp = this->list.HeadNode(); tmp != nullptr; tmp = tmp->NextNode()) {
                    if(tmp->Data().getCustomerPhoneNumber().find(phoneNumber) != -1) { 
                         std::cout << setw(15) << "" << leftSide << line(30);
                         std::cout << midMid << line(14);
                         std::cout << midMid << line(26);
                         std::cout << rightSide << "\n";

                         std::cout << setw(15) << "" << col << setw((30 - tmp->Data().getCustomerPhoneNumber().length())/2) << "" << setw(30 - (30 - tmp->Data().getCustomerPhoneNumber().length())/2) << left << tmp->Data().getCustomerName();
                         std::cout << col << setw((14 - tmp->Data().getCustomerPhoneNumber().length())/2) << "" << setw(14 - (14 - tmp->Data().getCustomerPhoneNumber().length())/2) << left << tmp->Data().getCustomerPhoneNumber();
                         std::cout << col << setw(26 - (26 - tmp->Data().getCustomerAddress().length())/2) << right << tmp->Data().getCustomerAddress() << setw((26 - tmp->Data().getCustomerAddress().length())/2) << "";
                         std::cout << col << "\n";
                    }
                }
                std::cout << setw(15) << "" << botLeftCorner << line(30);
                std::cout << botMid << line(14);
                std::cout << botMid << line(26);
                std::cout << botRightCorner << "\n";
            } else {
                std::cout << setw(45) << "" << "No customers found!\n";
            }

            // std::system("pause");
        } else if(choice == "3") { // search by address
            std::cout << setw(45) << "" << "Enter address: ";
            string address;
            cin.ignore();
            std::getline(std::cin, address);
            for(int i = 0; i < address.length(); ++i) {
                address[i] = tolower(address[i]);
            }
            bool checkExist = false;
            for(Node<Customer> *tmp = this->list.HeadNode(); tmp != nullptr; tmp = tmp->NextNode()) {
                string tmps = "";
                for(int i = 0; i < tmp->Data().getCustomerAddress().length(); ++i) {
                    tmps += tolower(tmp->Data().getCustomerAddress()[i]);
                }
                if(tmps.find(address) != -1) {
                    checkExist = true;
                    break;
                }
            }
            
            if(checkExist) {
                std::cout << setw(15) << "" << topLeftCorner << line(30);
                std::cout << topMid << line(14);
                std::cout << topMid << line(26);
                std::cout << topRightCorner << "\n";
                
                std::cout << setw(15) << "" << col << setw(13) << "" << setw(30 - 13) << left << "Name";
                std::cout << col << setw(1) << "" << setw(14 - 1) << left << "Phone number";
                std::cout << col << setw(9) << "" << setw(26 - 9) << left << "Address";
                std::cout << col << "\n";

                for(Node<Customer> *tmp = this->list.HeadNode(); tmp != nullptr; tmp = tmp->NextNode()) {
                    string tmps = "";
                    for(int j = 0; j < tmp->Data().getCustomerAddress().length(); ++j){
                        tmps += tolower(tmp->Data().getCustomerAddress()[j]);
                    }
                    if(tmps.find(address) != -1) { 
                    std::cout << setw(15) << "" << leftSide << line(30);
                    std::cout << midMid << line(14);
                    std::cout << midMid << line(26);
                    std::cout << rightSide << "\n";

                    std::cout << setw(15) << "" << col << setw((30 - tmp->Data().getCustomerName().length())/2) << "" << setw(30 - (30 - tmp->Data().getCustomerName().length())/2) << left << tmp->Data().getCustomerName();
                    std::cout << col << setw((14 - tmp->Data().getCustomerPhoneNumber().length())/2) << "" << setw(14 - (14 - tmp->Data().getCustomerPhoneNumber().length())/2) << left << tmp->Data().getCustomerPhoneNumber();
                    std::cout << col << setw(26 - (26 - tmp->Data().getCustomerAddress().length())/2) << right << tmp->Data().getCustomerAddress() << setw((26 - tmp->Data().getCustomerAddress().length())/2) << "";
                    std::cout << col << "\n";
                    }
                }
                std::cout << setw(15) << "" << botLeftCorner << line(30);
                std::cout << botMid << line(14);
                std::cout << botMid << line(26);
                std::cout << botRightCorner << "\n";
            } else {
                std::cout << setw(45) << "" << "No customers found!\n";
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
// const CustomerManager& CustomerManager::operator=(const CustomerManager& v )
// {
//     this->list = v.list;
//     return *this;
// }