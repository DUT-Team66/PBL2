#include <iostream>
#include "PhoneManager.h"
#include <string>
#include <fstream>
#include <iomanip>
#include "Table.h"
#include "Order.h"
#include <windows.h>
#include <ctime>
using namespace std;
int stringToInt(string s) {
    int res = 0;
    for(int i = 0;i < s.length(); ++i) {
        if(s[i] < '0' || s[i] > '9') {
            return 0;
        } else {
            res = res*10 + s[i] - 48;
        }
    }
    return res;
    
}
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
int PhoneManager::GetLength() const
{
    return this->n;
}
void PhoneManager::Add(const Phone& s)
{
    Node *p= new Node;
    if (p==NULL)
    {
        std::cout<<"\nKhong du bo nho de cap phat\n"<<endl;
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
    if (index==1) std::cout<<"Delete successfully!\n";
    else {
        std::cout << "PhoneID does not exist!\n";
    }
}
void PhoneManager::Update(){
    
    while(true) {
        std::system("cls");
        std::cout << setw(50) << "" << topLeftCorner << line(8) << topRightCorner << "\n";
        std::cout << setw(50) << "" << col << " PHONES " << col << "\n";
        std::cout << setw(50) << "" << botLeftCorner << line(8) << botRightCorner << "\n\n";

        this->Show();
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, grey); 
        cout << setw(45) << "" <<"Enter 'exit' to exit!\n";
        SetConsoleTextAttribute(hConsole, brightwhite); 
        string id;
        std::cout << setw(45) << "" << "Enter phone id: ";
        std::cin >> id;
        if(id == "exit") {
            return;
        } 
        bool checkExist = false;
        Node *phone = this->pHead;
        while(phone != nullptr) {
            if(phone->data.getPhoneID() == id) {
                checkExist = true;
                break;
            }
            phone = phone->pNext;
        }

        if(checkExist) {
            while(true) {
                std::system("cls");
                std::cout << setw(50) << "" << topLeftCorner << line(8) << topRightCorner << "\n";
                std::cout << setw(50) << "" << col << " PHONES " << col << "\n";
                std::cout << setw(50) << "" << botLeftCorner << line(8) << botRightCorner << "\n\n";
                
                phone->data.showForStaff();

                std::cout << setw(47) << "" << "1. Update name" << "\n";
                std::cout << setw(47) << "" << "2. Update brand" << "\n";
                std::cout << setw(47) << "" << "3. Update processor" << "\n";
                std::cout << setw(47) << "" << "4. Update RAM_ROM" << "\n";
                std::cout << setw(47) << "" << "5. Update sale price" << "\n";
                std::cout << setw(47) << "" << "6. Go back" << "\n";
                string choice;  
                std::cout << setw(45) << "" << arrow << " Your choice: ";
                std::cin >> choice;
                
                if(choice == "1") { // phone name
                    string name; 
                    std::cout << setw(45) << "" << "Enter new phone name: ";
                    std::cin.ignore();
                    std::getline(std::cin, name);
                    phone->data.setPhoneName(name);
                    std::cout << setw(45) << "" << "Update successfully" << "\n";
                    std::system("pause");
                } else if(choice == "2") { //brand
                    string brand;
                    std::cout << setw(45) << "" << "Enter new brand: ";
                    std::cin >> brand;
                    phone->data.setBrand(brand);
                    std::cout << setw(45) << "" << "Update successfully\n";
                    std::system("pause"); 
                } else if(choice == "3") { // processor
                    string processor;
                    std::cout << setw(45) << "" << "Enter new processor: ";
                    std::cin.ignore();
                    std::getline(std::cin, processor);
                    phone->data.setProcessor(processor);
                    std::cout << setw(45) << "" << "Update successfully" << "\n";
                    std::system("pause");
                } else if(choice == "4") { // ramrom
                    string RAM, ROM;
                    std::cout << setw(45) << "" << "Enter new RAM(GB): ";
                    std::cin >> RAM;
                    bool checkLegal = true;
                    for(int i = 0; i < RAM.length(); ++i) {
                        if(RAM[i] < '0' || RAM[i] > '9') {
                            checkLegal = false;
                            break;
                        }
                    }
                    if(!checkLegal) {
                        std::cout << setw(45) << "" << "Invalid information!\n";
                        std::system("pause");
                        continue;
                    }
                    std::cout << setw(45) << "" << "Enter new ROM(GB): ";
                    std::cin >> ROM;
                    for(int i = 0; i < ROM.length(); ++i) {
                        if(ROM[i] < '0' || ROM[i] > '9') {
                            checkLegal = false;
                            break;
                        }
                    }
                    if(!checkLegal) {
                        std::cout << setw(45) << "" << "Invalid information!\n";
                        std::system("pause");
                        continue;
                    }

                    
                    phone->data.setRAM_ROM(RAM + "GB-" + ROM + "GB");
                    std::cout << setw(45) << "" << "Update successfully!\n";
                    std::system("pause"); 
                } else if(choice == "5") { // update sale price
                    string price;
                    std::cout << setw(45) << "" << "Enter new sale price: ";
                    std::cin >> price;
                    bool checkLegal = true;
                    for(int i = 0; i < price.length(); ++i) {
                        if(price[i] < '0' || price[i] > '9') {
                            checkLegal = false;
                            break;
                        }
                    }
                    if(checkLegal) {
                        phone->data.setSalePrice(stoi(price));
                        std::cout << setw(45) << "" << "Update successfully" << "\n";
                    } else {
                        std::cout << setw(45) << "" << "Invalid price\n";
                    }
                    std::system("pause");   

                } else if(choice == "6") {
                    break;
                } else {
                    cout << setw(45) << "" << "Invalid choice\n";
                    cin.ignore(32767, '\n');
                    std::system("pause");
                }
            }
        } else {
            cout << setw(45) << "" << "Phone ID does not exist!\n";
            std::system("pause");
        }

    }


}
void PhoneManager::Search()
{
    while(true) {
        string choice; 
        while(true) {
            std::system("cls");
            std::cout << setw(50) << "" << topLeftCorner << line(8) << topRightCorner << "\n";
            std::cout << setw(50) << "" << col << " PHONES " << col << "\n";
            std::cout << setw(50) << "" << botLeftCorner << line(8) << botRightCorner << "\n\n";
            std::cout << setw(47) << "" << "1. Search by name" << "\n";
            std::cout << setw(47) << "" << "2. Search by brand" << "\n";
            std::cout << setw(47) << "" << "3. Search by processor" << "\n";
            std::cout << setw(47) << "" << "4. Search by RAM-ROM" << "\n"; 
            // std::cout << setw(47) << "" << "5. Search by display" << "\n";
            // std::cout << setw(47) << "" << "6. Search by camera" << "\n";
            std::cout << setw(47) << "" << "5. Search by price" << "\n";
            std::cout << setw(47) << "" << "6. Go back" << "\n\n";
            std::cout << setw(45) << "" << "Your choice: ";
            std::cin >> choice;
            if(choice != "1" && choice != "2" && choice != "3" && choice != "4" && choice != "5" && choice != "6") {
                std::cout << setw(45) << "" << "Invalid choice!\n";
                std::system("pause");
            } else break;
        }
        
        if(choice == "1") {   // search by name
            string name;
            std::cout << setw(45) << "" << "Enter phone name: ";
            std::cin.ignore();
            std::getline(std::cin, name);
            for(int i = 0; i < name.length(); ++i) {
                name[i] = tolower(name[i]);
            }
            bool checkExist = false;
            for(Node *k = this->pHead; k != nullptr; k = k->pNext) {
                string tmps = "";
                for(int j = 0; j < k->data.getPhoneName().length(); ++j){
                    tmps += tolower(k->data.getPhoneName()[j]);
                }
                if(tmps.find(name) != -1) {
                    checkExist = true;
                    k = nullptr;
                    break;
                }
            }
            if(checkExist) {
                std::cout << topLeftCorner << line(39); // phonename
                std::cout << topMid << line(13); // phoneID
                std::cout << topMid << line(9); // brand
                std::cout << topMid << line(27); // processor
                std::cout << topMid << line(12); // RAM_ROM
                std::cout << topMid << line(29); // display
                std::cout << topMid << line(13); // camera
                std::cout << topMid << line(13); // entryprice
                std::cout << topMid << line(12); // saleprice
                std::cout << topMid << line(8); // remaining amount
                std::cout << topRightCorner << "\n";
 
                std::cout << col << setw(14) << "" << setw(25) << left << "Phone name"; 
                std::cout << col << setw(3) << "" << setw(10) << left << "Phone ID";
                std::cout << col << setw(2) << "" << setw(7) << left << "Brand";
                std::cout << col << setw(9) << "" << setw(18) << left << "Processor";
                std::cout << col << setw(2) << "" << setw(10) << left << "RAM-ROM";
                std::cout << col << setw(11) << "" << setw(18) << left << "Display";
                std::cout << col << setw(3) << "" << setw(10) << left << "Camera";
                std::cout << col << setw(12) << right << "Entry price" << setw(1) << "" ;
                std::cout << col << setw(11) << right << "Sale price" << setw(1) << "" ;
                std::cout << col << setw(7) << right << "Amount" << setw(1) << "";
                std::cout << col << "\n";

                
                for(Node *tmp = this->pHead; tmp != nullptr; tmp = tmp->pNext) {
                    string tmps = "";
                    for(int j = 0; j < tmp->data.getPhoneName().length(); ++j){
                        tmps += tolower(tmp->data.getPhoneName()[j]);
                    }
                    if(tmps.find(name) != -1) {
                        std::cout << leftSide << line(39); // phonename
                        std::cout << midMid << line(13); // phoneID
                        std::cout << midMid << line(9); // brand
                        std::cout << midMid << line(27); // processor
                        std::cout << midMid << line(12); // RAM_ROM
                        std::cout << midMid << line(29); // display
                        std::cout << midMid << line(13); // camera
                        std::cout << midMid << line(13); // entryprice
                        std::cout << midMid << line(12); // saleprice
                        std::cout << midMid << line(8); // remaining amount
                        std::cout << rightSide << "\n";

                        std::cout << col << setw((39 - tmp->data.getPhoneName().length())/2) << "" << setw(39 - (39 - tmp->data.getPhoneName().length())/2) << left << tmp->data.getPhoneName(); 
                        std::cout << col << setw((13 - tmp->data.getPhoneID().length())/2) << "" << setw(13 - (13 - tmp->data.getPhoneID().length())/2) << left << tmp->data.getPhoneID();
                        std::cout << col << setw((9 - tmp->data.getBrand().length())/2) << "" << setw(9 - (9 - tmp->data.getBrand().length())/2) << left << tmp->data.getBrand();
                        std::cout << col << setw((27 - tmp->data.getProcessor().length())/2) << "" << setw(27 - (27 - tmp->data.getProcessor().length())/2) << left << tmp->data.getProcessor();
                        std::cout << col << setw((12 - tmp->data.getRAM_ROM().length())/2) << "" << setw(12 - (12 - tmp->data.getRAM_ROM().length())/2) << left << tmp->data.getRAM_ROM();
                        std::cout << col << setw((29 - tmp->data.getDisplay().length())/2) << "" << setw(29 - (29 - tmp->data.getDisplay().length())/2) << left << tmp->data.getDisplay();
                        std::cout << col << setw((13 - tmp->data.getCamera().length())/2) << "" << setw(13 - (13 - tmp->data.getCamera().length())/2) << left << tmp->data.getCamera();
                        std::cout << col << setw(13 - (13 - to_string(tmp->data.getEntryPrice()).length())/2) << right << tmp->data.getEntryPrice() << setw((13 - to_string(tmp->data.getEntryPrice()).length())/2) << "" ;
                        std::cout << col << setw(12 - (12 - to_string(tmp->data.getSalePrice()).length())/2) << right << tmp->data.getSalePrice() << setw((12 - to_string(tmp->data.getSalePrice()).length())/2) << "" ;
                        std::cout << col << setw(8 - (8 - to_string(tmp->data.getRemainingAmount()).length())/2) << right << tmp->data.getRemainingAmount() << setw((8 - to_string(tmp->data.getRemainingAmount()).length())/2) << "" ;
                        std::cout << col << "\n";
                    }
                }
                std::cout << botLeftCorner << line(39); // phone name
                std::cout << botMid << line(13); //phone id
                std::cout << botMid << line(9); // brand
                std::cout << botMid << line(27); // processor
                std::cout << botMid << line(12); //ramrom
                std::cout << botMid << line(29); //display
                std::cout << botMid << line(13); //camera
                std::cout << botMid << line(13); // entryprice
                std::cout << botMid << line(12); // sale price
                std::cout << botMid << line(8); // remaining amount
                std::cout << botRightCorner << "\n";
                
            } else {
                std::cout << setw(45) << "" << "No phones found!\n";
                //std::system("pause");
                //continue;
            }
            std::system("pause");
        } else if(choice == "2") {  // search by brand
            string brand;
            std::cout << setw(45) << "" << "Enter phone brand: ";
            std::cin.ignore();
            std::getline(std::cin, brand);
            for(int i = 0; i < brand.length(); ++i) {
                brand[i] = tolower(brand[i]);
            }
            bool checkExist = false;
            for(Node *k = this->pHead; k != nullptr; k = k->pNext) {
                string tmps = "";
                for(int j = 0; j < k->data.getBrand().length(); ++j){
                    tmps += tolower(k->data.getBrand()[j]);
                }
                if(tmps.find(brand) != -1) {
                    checkExist = true;
                    k = nullptr;
                    break;
                }
            }

            if(checkExist) {
                std::cout << topLeftCorner << line(39); // phonename
                std::cout << topMid << line(13); // phoneID
                std::cout << topMid << line(9); // brand
                std::cout << topMid << line(27); // processor
                std::cout << topMid << line(12); // RAM_ROM
                std::cout << topMid << line(29); // display
                std::cout << topMid << line(13); // camera
                std::cout << topMid << line(13); // entryprice
                std::cout << topMid << line(12); // saleprice
                std::cout << topMid << line(8); // remaining amount
                std::cout << topRightCorner << "\n";
 
                std::cout << col << setw(14) << "" << setw(25) << left << "Phone name"; 
                std::cout << col << setw(3) << "" << setw(10) << left << "Phone ID";
                std::cout << col << setw(2) << "" << setw(7) << left << "Brand";
                std::cout << col << setw(9) << "" << setw(18) << left << "Processor";
                std::cout << col << setw(2) << "" << setw(10) << left << "RAM-ROM";
                std::cout << col << setw(11) << "" << setw(18) << left << "Display";
                std::cout << col << setw(3) << "" << setw(10) << left << "Camera";
                std::cout << col << setw(12) << right << "Entry price" << setw(1) << "" ;
                std::cout << col << setw(11) << right << "Sale price" << setw(1) << "" ;
                std::cout << col << setw(7) << right << "Amount" << setw(1) << "";
                std::cout << col << "\n";

                
                for(Node *tmp = this->pHead; tmp != nullptr; tmp = tmp->pNext) {
                    string tmps = "";
                    for(int j = 0; j < tmp->data.getBrand().length(); ++j){
                        tmps += tolower(tmp->data.getBrand()[j]);
                    }
                    if(tmps.find(brand) != -1) {
                        std::cout << leftSide << line(39); // phonename
                        std::cout << midMid << line(13); // phoneID
                        std::cout << midMid << line(9); // brand
                        std::cout << midMid << line(27); // processor
                        std::cout << midMid << line(12); // RAM_ROM
                        std::cout << midMid << line(29); // display
                        std::cout << midMid << line(13); // camera
                        std::cout << midMid << line(13); // entryprice
                        std::cout << midMid << line(12); // saleprice
                        std::cout << midMid << line(8); // remaining amount
                        std::cout << rightSide << "\n";

                        std::cout << col << setw((39 - tmp->data.getPhoneName().length())/2) << "" << setw(39 - (39 - tmp->data.getPhoneName().length())/2) << left << tmp->data.getPhoneName(); 
                        std::cout << col << setw((13 - tmp->data.getPhoneID().length())/2) << "" << setw(13 - (13 - tmp->data.getPhoneID().length())/2) << left << tmp->data.getPhoneID();
                        std::cout << col << setw((9 - tmp->data.getBrand().length())/2) << "" << setw(9 - (9 - tmp->data.getBrand().length())/2) << left << tmp->data.getBrand();
                        std::cout << col << setw((27 - tmp->data.getProcessor().length())/2) << "" << setw(27 - (27 - tmp->data.getProcessor().length())/2) << left << tmp->data.getProcessor();
                        std::cout << col << setw((12 - tmp->data.getRAM_ROM().length())/2) << "" << setw(12 - (12 - tmp->data.getRAM_ROM().length())/2) << left << tmp->data.getRAM_ROM();
                        std::cout << col << setw((29 - tmp->data.getDisplay().length())/2) << "" << setw(29 - (29 - tmp->data.getDisplay().length())/2) << left << tmp->data.getDisplay();
                        std::cout << col << setw((13 - tmp->data.getCamera().length())/2) << "" << setw(13 - (13 - tmp->data.getCamera().length())/2) << left << tmp->data.getCamera();
                        std::cout << col << setw(13 - (13 - to_string(tmp->data.getEntryPrice()).length())/2) << right << tmp->data.getEntryPrice() << setw((13 - to_string(tmp->data.getEntryPrice()).length())/2) << "" ;
                        std::cout << col << setw(12 - (12 - to_string(tmp->data.getSalePrice()).length())/2) << right << tmp->data.getSalePrice() << setw((12 - to_string(tmp->data.getSalePrice()).length())/2) << "" ;
                        std::cout << col << setw(8 - (8 - to_string(tmp->data.getRemainingAmount()).length())/2) << right << tmp->data.getRemainingAmount() << setw((8 - to_string(tmp->data.getRemainingAmount()).length())/2) << "" ;
                        std::cout << col << "\n";
                    }
                }
                std::cout << botLeftCorner << line(39); // phone name
                std::cout << botMid << line(13); //phone id
                std::cout << botMid << line(9); // brand
                std::cout << botMid << line(27); // processor
                std::cout << botMid << line(12); //ramrom
                std::cout << botMid << line(29); //display
                std::cout << botMid << line(13); //camera
                std::cout << botMid << line(13); // entryprice
                std::cout << botMid << line(12); // sale price
                std::cout << botMid << line(8); // remaining amount
                std::cout << botRightCorner << "\n";
            } else {
                std::cout << setw(45) << "" << "No phones found!\n";
                //std::system("pause");
                //continue;
            }
            std::system("pause");
        } else if (choice == "3") { // search by processor
            string processor;
            std::cout << setw(45) << "" << "Enter phone processor: ";
            std::cin.ignore();
            std::getline(std::cin, processor);
            for(int i = 0; i < processor.length(); ++i) {
                processor[i] = tolower(processor[i]);
            }
            bool checkExist = false;
            for(Node *k = this->pHead; k != nullptr; k = k->pNext) {
                string tmps = "";
                for(int j = 0; j < k->data.getProcessor().length(); ++j){
                    tmps += tolower(k->data.getProcessor()[j]);
                }
                if(tmps.find(processor) != -1) {
                    checkExist = true;
                    k = nullptr;
                    break;
                }
            }

            if(checkExist) {
                std::cout << topLeftCorner << line(39); // phonename
                std::cout << topMid << line(13); // phoneID
                std::cout << topMid << line(9); // brand
                std::cout << topMid << line(27); // processor
                std::cout << topMid << line(12); // RAM_ROM
                std::cout << topMid << line(29); // display
                std::cout << topMid << line(13); // camera
                std::cout << topMid << line(13); // entryprice
                std::cout << topMid << line(12); // saleprice
                std::cout << topMid << line(8); // remaining amount
                std::cout << topRightCorner << "\n";
 
                std::cout << col << setw(14) << "" << setw(25) << left << "Phone name"; 
                std::cout << col << setw(3) << "" << setw(10) << left << "Phone ID";
                std::cout << col << setw(2) << "" << setw(7) << left << "Brand";
                std::cout << col << setw(9) << "" << setw(18) << left << "Processor";
                std::cout << col << setw(2) << "" << setw(10) << left << "RAM-ROM";
                std::cout << col << setw(11) << "" << setw(18) << left << "Display";
                std::cout << col << setw(3) << "" << setw(10) << left << "Camera";
                std::cout << col << setw(12) << right << "Entry price" << setw(1) << "" ;
                std::cout << col << setw(11) << right << "Sale price" << setw(1) << "" ;
                std::cout << col << setw(7) << right << "Amount" << setw(1) << "";
                std::cout << col << "\n";

                
                for(Node *tmp = this->pHead; tmp != nullptr; tmp = tmp->pNext) {
                    string tmps = "";
                    for(int j = 0; j < tmp->data.getProcessor().length(); ++j){
                        tmps += tolower(tmp->data.getProcessor()[j]);
                    }
                    if(tmps.find(processor) != -1) {
                        std::cout << leftSide << line(39); // phonename
                        std::cout << midMid << line(13); // phoneID
                        std::cout << midMid << line(9); // brand
                        std::cout << midMid << line(27); // processor
                        std::cout << midMid << line(12); // RAM_ROM
                        std::cout << midMid << line(29); // display
                        std::cout << midMid << line(13); // camera
                        std::cout << midMid << line(13); // entryprice
                        std::cout << midMid << line(12); // saleprice
                        std::cout << midMid << line(8); // remaining amount
                        std::cout << rightSide << "\n";

                        std::cout << col << setw((39 - tmp->data.getPhoneName().length())/2) << "" << setw(39 - (39 - tmp->data.getPhoneName().length())/2) << left << tmp->data.getPhoneName(); 
                        std::cout << col << setw((13 - tmp->data.getPhoneID().length())/2) << "" << setw(13 - (13 - tmp->data.getPhoneID().length())/2) << left << tmp->data.getPhoneID();
                        std::cout << col << setw((9 - tmp->data.getBrand().length())/2) << "" << setw(9 - (9 - tmp->data.getBrand().length())/2) << left << tmp->data.getBrand();
                        std::cout << col << setw((27 - tmp->data.getProcessor().length())/2) << "" << setw(27 - (27 - tmp->data.getProcessor().length())/2) << left << tmp->data.getProcessor();
                        std::cout << col << setw((12 - tmp->data.getRAM_ROM().length())/2) << "" << setw(12 - (12 - tmp->data.getRAM_ROM().length())/2) << left << tmp->data.getRAM_ROM();
                        std::cout << col << setw((29 - tmp->data.getDisplay().length())/2) << "" << setw(29 - (29 - tmp->data.getDisplay().length())/2) << left << tmp->data.getDisplay();
                        std::cout << col << setw((13 - tmp->data.getCamera().length())/2) << "" << setw(13 - (13 - tmp->data.getCamera().length())/2) << left << tmp->data.getCamera();
                        std::cout << col << setw(13 - (13 - to_string(tmp->data.getEntryPrice()).length())/2) << right << tmp->data.getEntryPrice() << setw((13 - to_string(tmp->data.getEntryPrice()).length())/2) << "" ;
                        std::cout << col << setw(12 - (12 - to_string(tmp->data.getSalePrice()).length())/2) << right << tmp->data.getSalePrice() << setw((12 - to_string(tmp->data.getSalePrice()).length())/2) << "" ;
                        std::cout << col << setw(8 - (8 - to_string(tmp->data.getRemainingAmount()).length())/2) << right << tmp->data.getRemainingAmount() << setw((8 - to_string(tmp->data.getRemainingAmount()).length())/2) << "" ;
                        std::cout << col << "\n";
                    }
                }
                std::cout << botLeftCorner << line(39); // phone name
                std::cout << botMid << line(13); //phone id
                std::cout << botMid << line(9); // brand
                std::cout << botMid << line(27); // processor
                std::cout << botMid << line(12); //ramrom
                std::cout << botMid << line(29); //display
                std::cout << botMid << line(13); //camera
                std::cout << botMid << line(13); // entryprice
                std::cout << botMid << line(12); // sale price
                std::cout << botMid << line(8); // remaining amount
                std::cout << botRightCorner << "\n";
            } else {
                std::cout << setw(45) << "" << "No phones found!\n";
                //continue;
            }
            std::system("pause");

        } else if(choice == "4") {  // search by RAM_ROM
            string RAM, ROM;
            std::cout << setw(45) << "" << "Enter RAM(GB): ";
            std::cin >> RAM;
            bool checkLegal = true;
            for(int i = 0; i < RAM.length(); ++i) {
                if(RAM[i] < '0' || RAM[i] > '9') {
                    checkLegal = false;
                    break;
                }
            }
            if(!checkLegal) {
                std::cout << setw(45) << "" << "Invalid information!\n";
                std::system("pause");
                continue;
            }
            std::cout << setw(45) << "" << "Enter ROM(GB): ";
            std::cin >> ROM;
            for(int i = 0; i < ROM.length(); ++i) {
                if(ROM[i] < '0' || ROM[i] > '9') {
                    checkLegal = false;
                    break;
                }
            }
            if(!checkLegal) {
                std::cout << setw(45) << "" << "Invalid information!\n";
                std::system("pause");
                continue;
            }

            
            string RAM_ROM = RAM + "GB-" + ROM + "GB"; 
            bool checkExist = false;
            for(Node *k = this->pHead; k != nullptr; k = k->pNext) {
                if(k->data.getRAM_ROM() == RAM_ROM) {
                    checkExist = true;
                    k = nullptr;
                    break;
                }
            }

            if(checkExist) {
                std::cout << topLeftCorner << line(39); // phonename
                std::cout << topMid << line(13); // phoneID
                std::cout << topMid << line(9); // brand
                std::cout << topMid << line(27); // processor
                std::cout << topMid << line(12); // RAM_ROM
                std::cout << topMid << line(29); // display
                std::cout << topMid << line(13); // camera
                std::cout << topMid << line(13); // entryprice
                std::cout << topMid << line(12); // saleprice
                std::cout << topMid << line(8); // remaining amount
                std::cout << topRightCorner << "\n";
 
                std::cout << col << setw(14) << "" << setw(25) << left << "Phone name"; 
                std::cout << col << setw(3) << "" << setw(10) << left << "Phone ID";
                std::cout << col << setw(2) << "" << setw(7) << left << "Brand";
                std::cout << col << setw(9) << "" << setw(18) << left << "Processor";
                std::cout << col << setw(2) << "" << setw(10) << left << "RAM-ROM";
                std::cout << col << setw(11) << "" << setw(18) << left << "Display";
                std::cout << col << setw(3) << "" << setw(10) << left << "Camera";
                std::cout << col << setw(12) << right << "Entry price" << setw(1) << "" ;
                std::cout << col << setw(11) << right << "Sale price" << setw(1) << "" ;
                std::cout << col << setw(7) << right << "Amount" << setw(1) << "";
                std::cout << col << "\n";

                
                for(Node *tmp = this->pHead; tmp != nullptr; tmp = tmp->pNext) {
                    if(tmp->data.getRAM_ROM() == RAM_ROM) {
                        std::cout << leftSide << line(39); // phonename
                        std::cout << midMid << line(13); // phoneID
                        std::cout << midMid << line(9); // brand
                        std::cout << midMid << line(27); // processor
                        std::cout << midMid << line(12); // RAM_ROM
                        std::cout << midMid << line(29); // display
                        std::cout << midMid << line(13); // camera
                        std::cout << midMid << line(13); // entryprice
                        std::cout << midMid << line(12); // saleprice
                        std::cout << midMid << line(8); // remaining amount
                        std::cout << rightSide << "\n";

                        std::cout << col << setw((39 - tmp->data.getPhoneName().length())/2) << "" << setw(39 - (39 - tmp->data.getPhoneName().length())/2) << left << tmp->data.getPhoneName(); 
                        std::cout << col << setw((13 - tmp->data.getPhoneID().length())/2) << "" << setw(13 - (13 - tmp->data.getPhoneID().length())/2) << left << tmp->data.getPhoneID();
                        std::cout << col << setw((9 - tmp->data.getBrand().length())/2) << "" << setw(9 - (9 - tmp->data.getBrand().length())/2) << left << tmp->data.getBrand();
                        std::cout << col << setw((27 - tmp->data.getProcessor().length())/2) << "" << setw(27 - (27 - tmp->data.getProcessor().length())/2) << left << tmp->data.getProcessor();
                        std::cout << col << setw((12 - tmp->data.getRAM_ROM().length())/2) << "" << setw(12 - (12 - tmp->data.getRAM_ROM().length())/2) << left << tmp->data.getRAM_ROM();
                        std::cout << col << setw((29 - tmp->data.getDisplay().length())/2) << "" << setw(29 - (29 - tmp->data.getDisplay().length())/2) << left << tmp->data.getDisplay();
                        std::cout << col << setw((13 - tmp->data.getCamera().length())/2) << "" << setw(13 - (13 - tmp->data.getCamera().length())/2) << left << tmp->data.getCamera();
                        std::cout << col << setw(13 - (13 - to_string(tmp->data.getEntryPrice()).length())/2) << right << tmp->data.getEntryPrice() << setw((13 - to_string(tmp->data.getEntryPrice()).length())/2) << "" ;
                        std::cout << col << setw(12 - (12 - to_string(tmp->data.getSalePrice()).length())/2) << right << tmp->data.getSalePrice() << setw((12 - to_string(tmp->data.getSalePrice()).length())/2) << "" ;
                        std::cout << col << setw(8 - (8 - to_string(tmp->data.getRemainingAmount()).length())/2) << right << tmp->data.getRemainingAmount() << setw((8 - to_string(tmp->data.getRemainingAmount()).length())/2) << "" ;
                        std::cout << col << "\n";
                    }
                }
                std::cout << botLeftCorner << line(39); // phone name
                std::cout << botMid << line(13); //phone id
                std::cout << botMid << line(9); // brand
                std::cout << botMid << line(27); // processor
                std::cout << botMid << line(12); //ramrom
                std::cout << botMid << line(29); //display
                std::cout << botMid << line(13); //camera
                std::cout << botMid << line(13); // entryprice
                std::cout << botMid << line(12); // sale price
                std::cout << botMid << line(8); // remaining amount
                std::cout << botRightCorner << "\n";
            } else {
                std::cout << setw(45) << "" << "No phones found!\n";
                //continue;
            }
            std::system("pause");
            
        } else if(choice == "5") { // search by price

            std::cout << setw(45) << "" << "1. Entry price" << "\n";
            std::cout << setw(45) << "" << "2. Sale price" << "\n";
            string choice;
            if(choice != "1" && choice != "2") {
                std::cout << setw(45) << "" << "Invalid choice!\n"; 
                std::system("pause");
                continue;
            } else if(choice == "1") { // entry price
                string sprice, eprice;
                std::cout << setw(45) << "" << "Price from: ";
                std::cin >> sprice;
                bool checkLegal = true;
                for(int i = 0; i < sprice.length(); ++i) {
                    if(sprice[i] < '0' || sprice[i] > '9') {
                        checkLegal = true;
                        break;
                    }
                }
                if(!checkLegal) {
                    cout << setw(45) << "" << "Invalid price!\n";
                    std::system("pause");
                    continue;
                }
                
                std::cout << setw(51) << "" << "to: ";
                std::cin >> eprice;
                
                if(!checkLegal) {
                    cout << setw(45) << "" << "Invalid price!\n";
                    std::system("pause");
                    continue;
                }

                int isprice = stoi(sprice), ieprice = stoi(eprice);
                bool checkExist = false;
                for(Node* tmp = this->pHead; tmp != nullptr; tmp = tmp->pNext) {
                    if(tmp->data.getEntryPrice() >= isprice && tmp->data.getEntryPrice() <= ieprice) {
                        checkExist = true;
                        break;
                    }
                }
                if(checkExist) {
                    std::cout << topLeftCorner << line(39); // phonename
                    std::cout << topMid << line(13); // phoneID
                    std::cout << topMid << line(9); // brand
                    std::cout << topMid << line(27); // processor
                    std::cout << topMid << line(12); // RAM_ROM
                    std::cout << topMid << line(29); // display
                    std::cout << topMid << line(13); // camera
                    std::cout << topMid << line(13); // entryprice
                    std::cout << topMid << line(12); // saleprice
                    std::cout << topMid << line(8); // remaining amount
                    std::cout << topRightCorner << "\n";
    
                    std::cout << col << setw(14) << "" << setw(25) << left << "Phone name"; 
                    std::cout << col << setw(3) << "" << setw(10) << left << "Phone ID";
                    std::cout << col << setw(2) << "" << setw(7) << left << "Brand";
                    std::cout << col << setw(9) << "" << setw(18) << left << "Processor";
                    std::cout << col << setw(2) << "" << setw(10) << left << "RAM-ROM";
                    std::cout << col << setw(11) << "" << setw(18) << left << "Display";
                    std::cout << col << setw(3) << "" << setw(10) << left << "Camera";
                    std::cout << col << setw(12) << right << "Entry price" << setw(1) << "" ;
                    std::cout << col << setw(11) << right << "Sale price" << setw(1) << "" ;
                    std::cout << col << setw(7) << right << "Amount" << setw(1) << "";
                    std::cout << col << "\n";

                    
                    for(Node *tmp = this->pHead; tmp != nullptr; tmp = tmp->pNext) {
                        
                        if(tmp->data.getEntryPrice() >= isprice && tmp->data.getEntryPrice() <= ieprice) {
                            std::cout << leftSide << line(39); // phonename
                            std::cout << midMid << line(13); // phoneID
                            std::cout << midMid << line(9); // brand
                            std::cout << midMid << line(27); // processor
                            std::cout << midMid << line(12); // RAM_ROM
                            std::cout << midMid << line(29); // display
                            std::cout << midMid << line(13); // camera
                            std::cout << midMid << line(13); // entryprice
                            std::cout << midMid << line(12); // saleprice
                            std::cout << midMid << line(8); // remaining amount
                            std::cout << rightSide << "\n";

                            std::cout << col << setw((39 - tmp->data.getPhoneName().length())/2) << "" << setw(39 - (39 - tmp->data.getPhoneName().length())/2) << left << tmp->data.getPhoneName(); 
                            std::cout << col << setw((13 - tmp->data.getPhoneID().length())/2) << "" << setw(13 - (13 - tmp->data.getPhoneID().length())/2) << left << tmp->data.getPhoneID();
                            std::cout << col << setw((9 - tmp->data.getBrand().length())/2) << "" << setw(9 - (9 - tmp->data.getBrand().length())/2) << left << tmp->data.getBrand();
                            std::cout << col << setw((27 - tmp->data.getProcessor().length())/2) << "" << setw(27 - (27 - tmp->data.getProcessor().length())/2) << left << tmp->data.getProcessor();
                            std::cout << col << setw((12 - tmp->data.getRAM_ROM().length())/2) << "" << setw(12 - (12 - tmp->data.getRAM_ROM().length())/2) << left << tmp->data.getRAM_ROM();
                            std::cout << col << setw((29 - tmp->data.getDisplay().length())/2) << "" << setw(29 - (29 - tmp->data.getDisplay().length())/2) << left << tmp->data.getDisplay();
                            std::cout << col << setw((13 - tmp->data.getCamera().length())/2) << "" << setw(13 - (13 - tmp->data.getCamera().length())/2) << left << tmp->data.getCamera();
                            std::cout << col << setw(13 - (13 - to_string(tmp->data.getEntryPrice()).length())/2) << right << tmp->data.getEntryPrice() << setw((13 - to_string(tmp->data.getEntryPrice()).length())/2) << "" ;
                            std::cout << col << setw(12 - (12 - to_string(tmp->data.getSalePrice()).length())/2) << right << tmp->data.getSalePrice() << setw((12 - to_string(tmp->data.getSalePrice()).length())/2) << "" ;
                            std::cout << col << setw(8 - (8 - to_string(tmp->data.getRemainingAmount()).length())/2) << right << tmp->data.getRemainingAmount() << setw((8 - to_string(tmp->data.getRemainingAmount()).length())/2) << "" ;
                            std::cout << col << "\n";
                        }
                    }
                    std::cout << botLeftCorner << line(39); // phone name
                    std::cout << botMid << line(13); //phone id
                    std::cout << botMid << line(9); // brand
                    std::cout << botMid << line(27); // processor
                    std::cout << botMid << line(12); //ramrom
                    std::cout << botMid << line(29); //display
                    std::cout << botMid << line(13); //camera
                    std::cout << botMid << line(13); // entryprice
                    std::cout << botMid << line(12); // sale price
                    std::cout << botMid << line(8); // remaining amount
                    std::cout << botRightCorner << "\n";
                } else {
                    std::cout << setw(45) << "" << "No phones found!\n";
                    //std::system("pause");
                    //continue;
                }
            } else if(choice == "2") {   // sale price
                string sprice, eprice;
                std::cout << setw(45) << "" << "Price from: ";
                std::cin >> sprice;
                bool checkLegal = true;
                for(int i = 0; i < sprice.length(); ++i) {
                    if(sprice[i] < '0' || sprice[i] > '9') {
                        checkLegal = true;
                        break;
                    }
                }
                if(!checkLegal) {
                    cout << setw(45) << "" << "Invalid price!\n";
                    std::system("pause");
                    continue;
                }
                
                std::cout << setw(51) << "" << "to: ";
                std::cin >> eprice;
                
                if(!checkLegal) {
                    cout << setw(45) << "" << "Invalid price!\n";
                    std::system("pause");
                    continue;
                }

                int isprice = stoi(sprice), ieprice = stoi(eprice);
                bool checkExist = false;
                for(Node* tmp = this->pHead; tmp != nullptr; tmp = tmp->pNext) {
                    if(tmp->data.getSalePrice() >= isprice && tmp->data.getSalePrice() <= ieprice) {
                        checkExist = true;
                        break;
                    }
                }
                if(checkExist) {
                    std::cout << topLeftCorner << line(39); // phonename
                    std::cout << topMid << line(13); // phoneID
                    std::cout << topMid << line(9); // brand
                    std::cout << topMid << line(27); // processor
                    std::cout << topMid << line(12); // RAM_ROM
                    std::cout << topMid << line(29); // display
                    std::cout << topMid << line(13); // camera
                    std::cout << topMid << line(13); // entryprice
                    std::cout << topMid << line(12); // saleprice
                    std::cout << topMid << line(8); // remaining amount
                    std::cout << topRightCorner << "\n";
    
                    std::cout << col << setw(14) << "" << setw(25) << left << "Phone name"; 
                    std::cout << col << setw(3) << "" << setw(10) << left << "Phone ID";
                    std::cout << col << setw(2) << "" << setw(7) << left << "Brand";
                    std::cout << col << setw(9) << "" << setw(18) << left << "Processor";
                    std::cout << col << setw(2) << "" << setw(10) << left << "RAM-ROM";
                    std::cout << col << setw(11) << "" << setw(18) << left << "Display";
                    std::cout << col << setw(3) << "" << setw(10) << left << "Camera";
                    std::cout << col << setw(12) << right << "Entry price" << setw(1) << "" ;
                    std::cout << col << setw(11) << right << "Sale price" << setw(1) << "" ;
                    std::cout << col << setw(7) << right << "Amount" << setw(1) << "";
                    std::cout << col << "\n";

                    
                    for(Node *tmp = this->pHead; tmp != nullptr; tmp = tmp->pNext) {
                        
                        if(tmp->data.getSalePrice() >= isprice && tmp->data.getSalePrice() <= ieprice) {
                            std::cout << leftSide << line(39); // phonename
                            std::cout << midMid << line(13); // phoneID
                            std::cout << midMid << line(9); // brand
                            std::cout << midMid << line(27); // processor
                            std::cout << midMid << line(12); // RAM_ROM
                            std::cout << midMid << line(29); // display
                            std::cout << midMid << line(13); // camera
                            std::cout << midMid << line(13); // entryprice
                            std::cout << midMid << line(12); // saleprice
                            std::cout << midMid << line(8); // remaining amount
                            std::cout << rightSide << "\n";

                            std::cout << col << setw((39 - tmp->data.getPhoneName().length())/2) << "" << setw(39 - (39 - tmp->data.getPhoneName().length())/2) << left << tmp->data.getPhoneName(); 
                            std::cout << col << setw((13 - tmp->data.getPhoneID().length())/2) << "" << setw(13 - (13 - tmp->data.getPhoneID().length())/2) << left << tmp->data.getPhoneID();
                            std::cout << col << setw((9 - tmp->data.getBrand().length())/2) << "" << setw(9 - (9 - tmp->data.getBrand().length())/2) << left << tmp->data.getBrand();
                            std::cout << col << setw((27 - tmp->data.getProcessor().length())/2) << "" << setw(27 - (27 - tmp->data.getProcessor().length())/2) << left << tmp->data.getProcessor();
                            std::cout << col << setw((12 - tmp->data.getRAM_ROM().length())/2) << "" << setw(12 - (12 - tmp->data.getRAM_ROM().length())/2) << left << tmp->data.getRAM_ROM();
                            std::cout << col << setw((29 - tmp->data.getDisplay().length())/2) << "" << setw(29 - (29 - tmp->data.getDisplay().length())/2) << left << tmp->data.getDisplay();
                            std::cout << col << setw((13 - tmp->data.getCamera().length())/2) << "" << setw(13 - (13 - tmp->data.getCamera().length())/2) << left << tmp->data.getCamera();
                            std::cout << col << setw(13 - (13 - to_string(tmp->data.getEntryPrice()).length())/2) << right << tmp->data.getEntryPrice() << setw((13 - to_string(tmp->data.getEntryPrice()).length())/2) << "" ;
                            std::cout << col << setw(12 - (12 - to_string(tmp->data.getSalePrice()).length())/2) << right << tmp->data.getSalePrice() << setw((12 - to_string(tmp->data.getSalePrice()).length())/2) << "" ;
                            std::cout << col << setw(8 - (8 - to_string(tmp->data.getRemainingAmount()).length())/2) << right << tmp->data.getRemainingAmount() << setw((8 - to_string(tmp->data.getRemainingAmount()).length())/2) << "" ;
                            std::cout << col << "\n";
                        }
                    }
                    std::cout << botLeftCorner << line(39); // phone name
                    std::cout << botMid << line(13); //phone id
                    std::cout << botMid << line(9); // brand
                    std::cout << botMid << line(27); // processor
                    std::cout << botMid << line(12); //ramrom
                    std::cout << botMid << line(29); //display
                    std::cout << botMid << line(13); //camera
                    std::cout << botMid << line(13); // entryprice
                    std::cout << botMid << line(12); // sale price
                    std::cout << botMid << line(8); // remaining amount
                    std::cout << botRightCorner << "\n";
                } else {
                    std::cout << setw(45) << "" << "No phones found!\n";
                    //continue;
                }
            }
            std::system("pause");
        } else if(choice == "6") { // go back
            return;
        }


        //std::system("pause");

       


    }
























    // int index=-1;
    // for (Node *k=this->pHead;k!=NULL;k=k->pNext)
    // {
    //      if (k->data.getPhoneID()==m)
    //     {
    //         index=1;
    //         k->data.showForStaff();
    //         break;
    //     }
    // }

    
    // if (index==-1) std::cout << "PhoneID does not exist!\n";
    // std::cout<<endl;

}
const string& PhoneManager::getPhoneID(int index) {
    static string s;
    if(index < 0 || index > this->n) {
        return s;
    }
    Node *phone = this->pHead;
    while(index--) {
        phone = phone->pNext;
    }
    return phone->data.getPhoneID();
   // return (this->p + index)->getPhoneID();
}
void PhoneManager::Show()
{
    std::cout << topLeftCorner << line(7); //order
    std::cout << topMid << line(39); // phonename
	std::cout << topMid << line(13); // phoneID
	std::cout << topMid << line(9); // brand
	std::cout << topMid << line(27); // processor
	std::cout << topMid << line(12); // RAM_ROM
	std::cout << topMid << line(29); // display
	std::cout << topMid << line(13); // camera
	std::cout << topMid << line(13); // entryprice
	std::cout << topMid << line(12); // saleprice
	std::cout << topMid << line(8); // remaining amount
	std::cout << topRightCorner << "\n";
	
    std::cout << col << setw(1) << "" << setw(6) << left << "Order";
	std::cout << col << setw(14) << "" << setw(25) << left << "Phone name"; 
	std::cout << col << setw(3) << "" << setw(10) << left << "Phone ID";
	std::cout << col << setw(2) << "" << setw(7) << left << "Brand";
	std::cout << col << setw(9) << "" << setw(18) << left << "Processor";
	std::cout << col << setw(2) << "" << setw(10) << left << "RAM-ROM";
	std::cout << col << setw(11) << "" << setw(18) << left << "Display";
	std::cout << col << setw(3) << "" << setw(10) << left << "Camera";
	std::cout << col << setw(12) << right << "Entry price" << setw(1) << "" ;
	std::cout << col << setw(11) << right << "Sale price" << setw(1) << "" ;
	std::cout << col << setw(7) << right << "Amount" << setw(1) << "";
    std::cout << col << "\n";

    Node *tmp = this->pHead;
    int i = 0;
    while(tmp != nullptr) {
        std::cout << leftSide << line(7); // order
        std::cout << midMid << line(39); // phonename
		std::cout << midMid << line(13); // phoneID
		std::cout << midMid << line(9); // brand
		std::cout << midMid << line(27); // processor
		std::cout << midMid << line(12); // RAM_ROM
		std::cout << midMid << line(29); // display
		std::cout << midMid << line(13); // camera
		std::cout << midMid << line(13); // entryprice
		std::cout << midMid << line(12); // saleprice
		std::cout << midMid << line(8); // remaining amount
		std::cout << rightSide << "\n";
		
        std::cout << col << setw((7 - to_string(i + 1).length())/2) << "" << setw(7 - (7 - to_string(i + 1).length())/2) << left << i + 1; ++i;
		std::cout << col << setw((39 - tmp->data.getPhoneName().length())/2) << "" << setw(39 - (39 - tmp->data.getPhoneName().length())/2) << left << tmp->data.getPhoneName(); 
		std::cout << col << setw((13 - tmp->data.getPhoneID().length())/2) << "" << setw(13 - (13 - tmp->data.getPhoneID().length())/2) << left << tmp->data.getPhoneID();
		std::cout << col << setw((9 - tmp->data.getBrand().length())/2) << "" << setw(9 - (9 - tmp->data.getBrand().length())/2) << left << tmp->data.getBrand();
		std::cout << col << setw((27 - tmp->data.getProcessor().length())/2) << "" << setw(27 - (27 - tmp->data.getProcessor().length())/2) << left << tmp->data.getProcessor();
		std::cout << col << setw((12 - tmp->data.getRAM_ROM().length())/2) << "" << setw(12 - (12 - tmp->data.getRAM_ROM().length())/2) << left << tmp->data.getRAM_ROM();
		std::cout << col << setw((29 - tmp->data.getDisplay().length())/2) << "" << setw(29 - (29 - tmp->data.getDisplay().length())/2) << left << tmp->data.getDisplay();
		std::cout << col << setw((13 - tmp->data.getCamera().length())/2) << "" << setw(13 - (13 - tmp->data.getCamera().length())/2) << left << tmp->data.getCamera();
		std::cout << col << setw(13 - (13 - to_string(tmp->data.getEntryPrice()).length())/2) << right << tmp->data.getEntryPrice() << setw((13 - to_string(tmp->data.getEntryPrice()).length())/2) << "" ;
		std::cout << col << setw(12 - (12 - to_string(tmp->data.getSalePrice()).length())/2) << right << tmp->data.getSalePrice() << setw((12 - to_string(tmp->data.getSalePrice()).length())/2) << "" ;
		std::cout << col << setw(8 - (8 - to_string(tmp->data.getRemainingAmount()).length())/2) << right << tmp->data.getRemainingAmount() << setw((8 - to_string(tmp->data.getRemainingAmount()).length())/2) << "" ;
		std::cout << col << "\n";

        tmp = tmp->pNext;
    }
    std::cout << botLeftCorner << line(7); 
    std::cout << botMid << line(39); // phone name
	std::cout << botMid << line(13); //phone id
	std::cout << botMid << line(9); // brand
	std::cout << botMid << line(27); // processor
	std::cout << botMid << line(12); //ramrom
	std::cout << botMid << line(29); //display
	std::cout << botMid << line(13); //camera
	std::cout << botMid << line(13); // entryprice
	std::cout << botMid << line(12); // sale price
	std::cout << botMid << line(8); // remaining amount
	std::cout << botRightCorner << "\n";


    std::system("pause");
    

}
void PhoneManager::ShowTable() {

//	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//	SetConsoleTextAttribute(hConsole, 3);
            
    Node *phone = this->pHead;
    
    int cnt = 1;

	std::cout << setw(15) << "" << topLeftCorner << line(25 * 5 + 4) << topRightCorner << "\n"; 
	std::cout << setw(15) << "" << col << setw(44) << "" << "       ____  ____        ___     __       " << setw(43) << "" << col << "\n";	
	std::cout << setw(15) << "" << col << setw(44) << "" << "      /\\__ \\/ ___\\      /\\__\\   /__\\" << setw(49) << "" << col << "\n";
	std::cout << setw(15) << "" << col << setw(44) << "" << "     / /  \\  /   /     / /  /__//  /     " << setw(44) << "" << col << "\n";
	std::cout << setw(15) << "" << col << setw(44) << "" << "    / /    \\/   /     / /  /___/  /      " << setw(44) << "" << col << "\n";
	std::cout << setw(15) << "" << col << setw(44) << "" << "   / /  /\\     /     / /  ____   /       " << setw(44) << "" << col << "\n";
	std::cout << setw(15) << "" << col << setw(44) << "" << "  / /  /  \\   /     / /  /   /  /        " << setw(44) << "" << col << "\n";
	std::cout << setw(15) << "" << col << setw(44) << "" << "  \\/__/    \\_/      \\/__/   /__/       " << setw(46) << "" << col << "\n";
	std::cout << setw(15) << "" << col << setw(25 * 5 + 4) << "" << col << "\n";
	std::cout << setw(15) << "" << col << setw(44) << "" << "     M O B I L E    S T O R E             " << setw(43) << "" << col << "\n";
	std::cout << setw(15) << "" << col << setw(25 * 5 + 4) << "" << col << "\n";
	std::cout << setw(15) << "" << botLeftCorner << line(25 * 5 + 4) << botRightCorner << "\n";


	//std::cout << setw(45) << "" << topLeftCorner << line(20 * 5 + 4) << topRightCorner << "\n";
    std::cout << setw(15) << "" << topLeftCorner << line(25) << topMid << line(25) << topMid << line(25) << topMid << line(25) << topMid << line(25) << topRightCorner << "\n";
	
	for(int i = 0; i < this->n / 5; ++i) {
        std::cout << setw(15) << "";
        for(int j = 0; j < 5; ++j) {
            std::cout << col << setw(3) << right << cnt << ". " << setw(20) << left << phone->data.getPhoneName();
            phone = phone->pNext;
            ++cnt;
        }
        std::cout << col << "\n";
        std::cout << setw(15) << "" << leftSide << line(25) << midMid << line(25) << midMid << line(25) << midMid << line(25) << midMid << line(25) << rightSide << "\n";
    }
    std::cout << setw(15) << "";
    for(int i = 0; i < this->n % 5; ++i) {
        std::cout << col << setw(3) << right << cnt << ". " << setw(20) << left << phone->data.getPhoneName();
        ++cnt;
        phone = phone->pNext;
    }
    
    for(int i = 0; i < 5 - this->n % 5; ++i) {
        cout << col << setw(25) << "";
    }

    std::cout << col << "\n";
    std::cout << setw(15) << "" << botLeftCorner << line(25) << botMid << line(25) << botMid << line(25) << botMid << line(25) << botMid << line(25) << botRightCorner << "\n";


	//std::cout << setw(45) << "" << botLeftCorner << line(20 * 5 + 4) << botRightCorner << "\n";
//	SetConsoleTextAttribute(hConsole, 7);
// 	for(int t = 0; t < 6; ++t) {
//         cout << setw(45) << "" << leftSide << line(10) << midMid << line(10) << midMid << line(10) << midMid << line(10) << midMid << line(10) << rightSide << "\n";
//         cout << setw(45) << "";
//         stringstream ss1(phone->data.getPhoneName());
//         cout << col << " ";
//         for(int i = 0; i < 2; ++i) {
//             string tmp; ss1 >> tmp;
//             cout << tmp << " ";
//         }
//         phone = phone->pNext;
        
//         stringstream ss2(phone->data.getPhoneName());
//         cout << col << " ";
//         for(int i = 0; i < 2; ++i) {
//             string tmp; ss2 >> tmp;
//             cout << setw(9) << left << tmp;
//         }
//         phone = phone->pNext;

//         stringstream ss3(phone->data.getPhoneName());
//         cout << col << " ";
//         for(int i = 0; i < 2; ++i) {
//             string tmp; ss3 >> tmp;
//             cout << setw(9) << left << tmp;
//         }
//         phone = phone->pNext;

//         stringstream ss4(phone->data.getPhoneName());
//         cout << col << " ";
//         for(int i = 0; i < 2; ++i) {
//             string tmp; ss4 >> tmp;
//             cout << setw(9) << left << tmp;
//         }
//         phone = phone->pNext;

//         stringstream ss5(phone->data.getPhoneName());
//         cout << col << " ";
//         for(int i = 0; i < 2; ++i) {
//             string tmp; ss5 >> tmp;
//             cout << setw(9) << left << tmp;
//         }
//         phone = phone->pNext;
//         cout << col << "\n";

//         cout << setw(45) << "";
        
//         cout << col << " ";
//         string tmp1;
//         int l1 = 9;
//         while (ss1 >> tmp1) {
//             cout << tmp1 << " ";
//             l1 -= tmp1.length() + 1;
//         }
//         cout << setw(l1) << ""; 

//         cout << col << " ";
//         string tmp2;
//         int l2 = 9;
//         while (ss2 >> tmp2) {
//             cout << tmp2 << " ";
//             l2 -= tmp2.length() + 1;
//         }
//         cout << setw(l2) << ""; 
        
//         cout << col << " ";
//         string tmp3;
//         int l3 = 9;
//         while (ss1 >> tmp3) {
//             cout << tmp3 << " ";
//             l3 -= tmp3.length() + 1;
//         }
//         cout << setw(l3) << ""; 
        
//         cout << col << " ";
//         string tmp4;
//         int l4 = 9;
//         while (ss1 >> tmp4) {
//             cout << tmp4 << " ";
//             l4 -= tmp4.length() + 1;
//         }
//         cout << setw(l4) << ""; 

//         cout << col << " ";
//         string tmp5;
//         int l5 = 9;
//         while (ss1 >> tmp5) {
//             cout << tmp5 << " ";
//             l5 -= tmp5.length() + 1;
//         }
//         cout << setw(l5) << ""; 

//         cout << col << "\n";
//    }





	// cout << col << setw(10) << left << phone->data.getPhoneName(); phone = phone->pNext;
    // stringstream ss3;    
	// cout << col << setw(10) << left << phone->data.getPhoneName(); phone = phone->pNext;
	// stringstream ss4;
    // cout << col << setw(10) << left << phone->data.getPhoneName(); phone = phone->pNext;
	// stringstream ss5;
    // cout << col << setw(10) << left << phone->data.getPhoneName(); phone = phone->pNext;
	// cout << col << "\n";
	
	
	// cout << setw(45) << "";
	// cout << col << setw(10) << left << phone->data.getPhoneName(); phone = phone->pNext;
	// cout << col << setw(10) << left << phone->data.getPhoneName(); phone = phone->pNext;
	// cout << col << setw(10) << left << phone->data.getPhoneName(); phone = phone->pNext;
	// cout << col << setw(10) << left << phone->data.getPhoneName(); phone = phone->pNext;
	// cout << col << setw(10) << left << phone->data.getPhoneName(); phone = phone->pNext;
	// cout << col << "\n";
	
	// cout << setw(45) << "";
	// cout << col << setw(10) << left << phone->data.getPhoneName(); phone = phone->pNext;
	// cout << col << setw(10) << left << phone->data.getPhoneName(); phone = phone->pNext;
	// cout << col << setw(10) << left << phone->data.getPhoneName(); phone = phone->pNext;
	// cout << col << setw(10) << left << phone->data.getPhoneName(); phone = phone->pNext;
	// cout << col << setw(10) << left << phone->data.getPhoneName(); phone = phone->pNext;
	// cout << col << "\n";

	// cout << setw(45) << "";
	// cout << col << setw(10) << left << phone->data.getPhoneName(); phone = phone->pNext;
	// cout << col << setw(10) << left << phone->data.getPhoneName(); phone = phone->pNext;
	// cout << col << setw(10) << left << phone->data.getPhoneName(); phone = phone->pNext;
	// cout << col << setw(10) << left << phone->data.getPhoneName(); phone = phone->pNext;
	// cout << col << setw(10) << left << phone->data.getPhoneName(); phone = phone->pNext;
	// cout << col << "\n";
	
	// cout << setw(45) << "";
	// cout << col << setw(10) << left << phone->data.getPhoneName(); phone = phone->pNext;
	// cout << col << setw(10) << left << phone->data.getPhoneName(); phone = phone->pNext;
	// cout << col << setw(10) << left << phone->data.getPhoneName(); phone = phone->pNext;
	// cout << col << setw(10) << left << phone->data.getPhoneName(); phone = phone->pNext;
	// cout << col << setw(10) << left << phone->data.getPhoneName(); phone = phone->pNext;
	// cout << col << "\n";
	
	// cout << setw(45) << "";
	// cout << col << setw(10) << left << phone->data.getPhoneName(); phone = phone->pNext;
	// cout << col << setw(10) << left << phone->data.getPhoneName(); phone = phone->pNext;
	// cout << col << setw(10) << left << phone->data.getPhoneName(); phone = phone->pNext;
	// cout << col << setw(10) << left << phone->data.getPhoneName(); phone = phone->pNext;
	// cout << col << setw(10) << left << phone->data.getPhoneName(); phone = phone->pNext;
	// cout << col << "\n";
	
	
	// cout << setw(45) << "" << botLeftCorner << line(10) << botMid << line(10) << botMid << line(10) << botMid << line(10) << botMid << line(10) << botRightCorner << "\n";
	
	
    
    
    
    
    
    
    
    
    
    
    // for (int i=0;i<this->n;i+=2)
    // {
    //     cout<< setw(2) << right << i + 1 <<". " << setw(40) << left << k->data.getPhoneName()  << "" << i + 2 << ". " << k->pNext->data.getPhoneName() << "\n";
    // }
    // if(n & 1) {
    //     cout << this->n << ". " << (this->p + this->n - 1)->getPhoneName() << endl;
    // }
    // int d=0;
    // for (Node *k=this->pHead;k!=NULL;k=k->pNext)
    // {
    //     cout<< setw(2) << right << d + 1 <<". " << setw(40) << left << k->data.getPhoneName()  << "" << d + 2 << ". " << k->pNext->data.getPhoneName() << "\n";
    //     d+=2;
    //     k=k->pNext;
    // } 
    // if(n & 1) {
    //     cout << this->n << ". " << this->pTail->data.getPhoneName() << endl;
    // }  
}
void PhoneManager::Shopping(Order& order) { 
    
    
    
    // sửa lại setremaningamount(int,int)



    while(true) {
        std::cout << setw(30) << "" << "Choose what you want to purchase\n";
        this->ShowTable();
        std::cout << "\n";
        std::cout << setw(45) << "" << "Enter 'exit' to exit!\n";
        std::cout << setw(45) << "" << "Your choice: ";
        string choice;
        std::cin >> choice;
        int ichoice = stringToInt(choice);
        if(choice == "exit") {
            //cout << "exit shopping\n";
            //system("pause");
            break;
        } else if(ichoice < 1 || ichoice > this->GetLength()) {
            std::cout << setw(45) << "" << "Invalid choice, please re-enter!\n";
            std::system("pause");
        } else {

            this->Show(ichoice-1); 

            std::cout << setw(45) << "" << "Amount: ";
            string samount; std::cin >> samount;
            int amount = stringToInt(samount);
            //ShoppingList sp(phoneManager.getPhoneID(choice - 1),amount); 
            
            if(amount > 0) {
                if(amount > this->getRemainingAmount(ichoice-1)) {
                    cout << setw(45) << "" << "Remaining amount is not enough\n"; 
                    //std::system("pause");
                } else {
                    if(order.searchCart(this->getPhoneID(ichoice-1))) {
                        order.addToCart(this->getPhoneID(ichoice-1),amount);
                    } else {
                        order.addToCart(Goods(this->getPhoneID(ichoice - 1),amount));
                    }
                    this->setRemainingAmount(ichoice-1,amount);
                    long long price = this->getPhonePrice(ichoice-1) *(long long)amount;
                    order.setTotalPrice(order.getTotalPrice() + price);
                    cout << setw(45) << "" << "Add to cart successfully!\n";
                    //std::system("pause");

                }
            } else {
                cout << setw(45) << "" << "Invalid amount!\n";
            }
            std::system("pause");
        }
        //system("pause");
        std::system("cls");
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
    static int i;
    if(index < 0 || index > this->n) {
        return i;
    }
    Node *phone = this->pHead;
    while(index--) {
        phone = phone->pNext;
    }
    return phone->data.getSalePrice();
}
const int& PhoneManager::getEntryPrice(int index) {
    static int i;
    if(index < 0 || index > this->n) {
        return i;
    }
    Node *phone = this->pHead;
    while(index--) {
        phone = phone->pNext;
    }
    return phone->data.getEntryPrice();
}
const int& PhoneManager::getRemainingAmount(int index) {
    static int i;
    if(index < 0 || index > this->n) {
        return i;
    }
    Node *phone = this->pHead;
    while(index--) {
        phone = phone->pNext;
    }
    return phone->data.getRemainingAmount();
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
	while(std::getline(readfile,tmpline)) {
		
		string id = "", name = "", brand = "", processor = "", RAM_ROM = "", display = "", camera = "";
		int entryprice = 0, saleprice = 0, remainingAmount = 0;
		
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
        while(tmpline[i] != '/') {
            remainingAmount = remainingAmount*10 + tmpline[i] - 48;
            ++i;
        }

        this->Add(Phone(name,id,brand,processor,RAM_ROM,display,camera,entryprice,saleprice,remainingAmount));


    }
    readfile.close();
}
void PhoneManager::UpdateFile() {
    fstream editfile("Phone.txt", ios::out);
    int d=0;
    for (Node *k=this->pHead;k!=NULL;k=k->pNext) {
        string s = k->data.getPhoneName() + "/" + k->data.getPhoneID() + "/" + k->data.getBrand() + "/" + k->data.getProcessor() + "/" + k->data.getRAM_ROM() + "/" + k->data.getDisplay() + "/" + k->data.getCamera() + "/" + to_string(k->data.getEntryPrice()) + "/" + to_string(k->data.getSalePrice()) + "/" + to_string(k->data.getRemainingAmount()) + "/" ;
        if(d != this->n-1) editfile << s << "\n";
        else editfile << s;
        d++;
    }
    editfile.close();
}
void PhoneManager::Menu() {
    //std::system("cls");
    while(true) {
        string choice;
        while(true) {
            std::system("cls");
            std::cout << setw(50) << "" << topLeftCorner << line(8) << topRightCorner << "\n";
	        std::cout << setw(50) << "" << col << " PHONES " << col << "\n";
	        std::cout << setw(50) << "" << botLeftCorner << line(8) << botRightCorner << "\n\n";
            // std::cout << setw(25) << "" << "PHONES" << "\n\n";
            //this->Show();
            std::cout << setw(47) << "" << "1. Add phone" << "\n"; // nhap day du thong tin cua phone
            std::cout << setw(47) << "" << "2. Delete phone" << "\n"; // nhap phoneid
            std::cout << setw(47) << "" << "3. Search phone" << "\n"; // nhap phoneid
            std::cout << setw(47) << "" << "4. Update phone" << "\n";
            std::cout << setw(47) << "" << "5. Show all phones" << "\n";
            std::cout << setw(47) << "" << "6. Go back" << "\n\n";
            
            std::cout << setw(45) << "" << "Your choice: ";
            cin >> choice;
            if(choice != "1" && choice != "2" && choice != "3" && choice != "4" && choice != "5" && choice != "6") {
                std::cout << "Invalid choice, please re-enter!\n";
                std::system("pause");
                std::system("cls"); 
            } else break;
        }
        if(choice == "1") {
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	        SetConsoleTextAttribute(hConsole, grey); 
            cout << setw(45) << "" <<"Enter 'exit' to exit!\n";
	        SetConsoleTextAttribute(hConsole, brightwhite); 
            string phoneName;
            std::cout << setw(45) << "" << "Enter phone name: ";
            cin.ignore();
            getline(cin, phoneName);

            if(phoneName == "exit") {
                continue;
            }

            bool exist = false;
            Node* tmp = this->pHead;
            while(tmp != nullptr) {
                if(tmp->data.getPhoneName() == phoneName) {
                    exist = true;
                    break;
                }
                tmp = tmp->pNext;
            }
            if(!exist) {
                string phoneID, brand, processor, RAM_ROM, display, camera; 
                int entryPrice, salePrice, amount;
                std::cout << setw(45) << "" << "Enter phone id: ";
                getline(cin, phoneID);
                std::cout << setw(45) << "" << "Enter brand: ";
                getline(cin,brand);
                std::cout << setw(45) << "" << "Enter processor: ";
                getline(cin, processor);
                std::cout << setw(45) << "" << "Enter RAM/ROM: ";
                getline(cin, RAM_ROM);
                std::cout << setw(45) << "" << "Enter display: ";
                getline(cin, display);
                std::cout << setw(45) << "" << "Enter camera: ";
                getline(cin, camera);
                std::cout << setw(45) << "" << "Enter entry price: ";
                cin >> entryPrice;
                std::cout << setw(45) << "" << "Enter sale price: ";
                cin >> salePrice;
                std::cout << setw(45) << "" << "Enter amount: ";
                cin >> amount;
                
                this->Add(Phone(phoneName, phoneID, brand, processor, RAM_ROM, display, camera, entryPrice, salePrice, amount));
                HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	            SetConsoleTextAttribute(hConsole, brightgreen);
                std::cout << "\n" << setw(45) << "" << "Add successfully!\n";
	            SetConsoleTextAttribute(hConsole, brightwhite); 
            } else {
                std::cout << setw(45) << "" << "Phone exists";
            }
            std::system("pause");
        } else if (choice == "2") {
            this->Show();
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	        SetConsoleTextAttribute(hConsole, grey); 
            cout << setw(45) << "" <<"Enter 'exit' to exit!\n";
	        SetConsoleTextAttribute(hConsole, brightwhite); 
            string s;
            std::cout << setw(45) << "" << "Enter ID: ";
            cin >> s;
            if(s == "exit") {
                continue;
            }


            HANDLE hConsole1 = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hConsole1, brightyellow);
            cout << setw(45) << "" << "Confirm (Y/N): ";    
            SetConsoleTextAttribute(hConsole1, brightwhite); 
            string confirm; cin >> confirm;
            if(confirm == "Y") {
                this->Delete(s);
                std::system("pause");
            } else if(confirm != "N") {
                HANDLE hConsole2 = GetStdHandle(STD_OUTPUT_HANDLE);
	            SetConsoleTextAttribute(hConsole2, brightred);
                cout << setw(45) << "" << "Invalid choice!\n";
	            SetConsoleTextAttribute(hConsole2, brightwhite); 
                std::system("pause");
            }
        } else if(choice == "3") {
            this->Search();
        } else if (choice == "4") {
            this->Update();
        } else if(choice == "5") {
            this->Show();
        } else {
            std::system("cls");
            break;  
        }
        //std::system("pause");
        std::system("cls");
    }
    
}

const PhoneManager& PhoneManager::operator=(const PhoneManager& v )
{
    if (this != &v) {
        //this->n=v.n;
        Node *k;  
        while (this->pHead!=NULL)
        {
            k=this->pHead;
            this->pHead=this->pHead->pNext;
            delete k;
            this->n--;
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