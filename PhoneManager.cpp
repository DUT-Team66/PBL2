#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <windows.h>
#include <ctime>

#include "Table.h"
#include "PhoneManager.h"
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
    
}
PhoneManager::~PhoneManager()
{

}
int PhoneManager::GetLength() const
{
    return this->list.size();
}
void PhoneManager::Add(const Phone& s)
{
    this->list.Add(s);
}
void PhoneManager::Delete(string m)
{
    this->list.Delete(m);
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
        cin.clear();
        fflush(stdin);
        if(id == "exit") {
            return;
        } 
        bool checkExist = false;
        Node<Phone> *phone = this->list.HeadNode();
        while(phone != nullptr) {
            if(phone->Data().getID() == id) {
                checkExist = true;
                break;
            }
            phone = phone->NextNode();
        }

        if(checkExist) {
            while(true) {
                std::system("cls");
                std::cout << setw(50) << "" << topLeftCorner << line(8) << topRightCorner << "\n";
                std::cout << setw(50) << "" << col << " PHONES " << col << "\n";
                std::cout << setw(50) << "" << botLeftCorner << line(8) << botRightCorner << "\n\n";
                
                phone->Data().showForStaff();

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
                    phone->Data().setName(name);
                    std::cout << setw(45) << "" << "Update successfully" << "\n";
                    std::system("pause");
                } else if(choice == "2") { //brand
                    string brand;
                    std::cout << setw(45) << "" << "Enter new brand: ";
                    std::cin >> brand;
                    phone->Data().setBrand(brand);
                    std::cout << setw(45) << "" << "Update successfully\n";
                    std::system("pause"); 
                } else if(choice == "3") { // processor
                    string processor;
                    std::cout << setw(45) << "" << "Enter new processor: ";
                    std::cin.ignore();
                    std::getline(std::cin, processor);
                    phone->Data().setProcessor(processor);
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

                    
                    phone->Data().setRAM_ROM(RAM + "GB-" + ROM + "GB");
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
                        phone->Data().setSalePrice(stoi(price));
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
            cin.clear();
            fflush(stdin);
            if(choice != "1" && choice != "2" && choice != "3" && choice != "4" && choice != "5" && choice != "6") {
                std::cout << setw(45) << "" << "Invalid choice!\n";
                std::system("pause");
            } else break;
        }
        
        if(choice == "1") {   // search by name
            string name;
            std::cout << setw(45) << "" << "Enter phone name: ";
            std::getline(std::cin, name);
            for(int i = 0; i < name.length(); ++i) {
                name[i] = tolower(name[i]);
            }
            bool checkExist = false;
            for(Node<Phone> *k = this->list.HeadNode(); k != nullptr; k = k->NextNode()) {
                string tmps = "";
                for(int j = 0; j < k->Data().getName().length(); ++j){
                    tmps += tolower(k->Data().getName()[j]);
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

                
                for(Node<Phone> *tmp = this->list.HeadNode(); tmp != nullptr; tmp = tmp->NextNode()) {
                    string tmps = "";
                    for(int j = 0; j < tmp->Data().getName().length(); ++j){
                        tmps += tolower(tmp->Data().getName()[j]);
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

                        std::cout << col << setw((39 - tmp->Data().getName().length())/2) << "" << setw(39 - (39 - tmp->Data().getName().length())/2) << left << tmp->Data().getName(); 
                        std::cout << col << setw((13 - tmp->Data().getID().length())/2) << "" << setw(13 - (13 - tmp->Data().getID().length())/2) << left << tmp->Data().getID();
                        std::cout << col << setw((9 - tmp->Data().getBrand().length())/2) << "" << setw(9 - (9 - tmp->Data().getBrand().length())/2) << left << tmp->Data().getBrand();
                        std::cout << col << setw((27 - tmp->Data().getProcessor().length())/2) << "" << setw(27 - (27 - tmp->Data().getProcessor().length())/2) << left << tmp->Data().getProcessor();
                        std::cout << col << setw((12 - tmp->Data().getRAM_ROM().length())/2) << "" << setw(12 - (12 - tmp->Data().getRAM_ROM().length())/2) << left << tmp->Data().getRAM_ROM();
                        std::cout << col << setw((29 - tmp->Data().getDisplay().length())/2) << "" << setw(29 - (29 - tmp->Data().getDisplay().length())/2) << left << tmp->Data().getDisplay();
                        std::cout << col << setw((13 - tmp->Data().getCamera().length())/2) << "" << setw(13 - (13 - tmp->Data().getCamera().length())/2) << left << tmp->Data().getCamera();
                        std::cout << col << setw(13 - (13 - to_string(tmp->Data().getEntryPrice()).length())/2) << right << tmp->Data().getEntryPrice() << setw((13 - to_string(tmp->Data().getEntryPrice()).length())/2) << "" ;
                        std::cout << col << setw(12 - (12 - to_string(tmp->Data().getSalePrice()).length())/2) << right << tmp->Data().getSalePrice() << setw((12 - to_string(tmp->Data().getSalePrice()).length())/2) << "" ;
                        std::cout << col << setw(8 - (8 - to_string(tmp->Data().getRemainingAmount()).length())/2) << right << tmp->Data().getRemainingAmount() << setw((8 - to_string(tmp->Data().getRemainingAmount()).length())/2) << "" ;
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
            std::getline(std::cin, brand);
            for(int i = 0; i < brand.length(); ++i) {
                brand[i] = tolower(brand[i]);
            }
            bool checkExist = false;

            for(Node<Phone>* tmp = this->list.HeadNode(); tmp != nullptr; tmp = tmp->NextNode()) {
                string tmps = "";
                for(int j = 0; j < tmp->Data().getBrand().length(); ++j){
                    tmps += tolower(tmp->Data().getBrand()[j]);
                }
                if(tmps.find(brand) != -1) {
                    checkExist = true;
                    tmp = nullptr;
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

                
                for(Node<Phone> *tmp = this->list.HeadNode(); tmp != nullptr; tmp = tmp->NextNode()) {
                    string tmps = "";
                    for(int j = 0; j < tmp->Data().getBrand().length(); ++j){
                        tmps += tolower(tmp->Data().getBrand()[j]);
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

                        std::cout << col << setw((39 - tmp->Data().getName().length())/2) << "" << setw(39 - (39 - tmp->Data().getName().length())/2) << left << tmp->Data().getName(); 
                        std::cout << col << setw((13 - tmp->Data().getID().length())/2) << "" << setw(13 - (13 - tmp->Data().getID().length())/2) << left << tmp->Data().getID();
                        std::cout << col << setw((9 - tmp->Data().getBrand().length())/2) << "" << setw(9 - (9 - tmp->Data().getBrand().length())/2) << left << tmp->Data().getBrand();
                        std::cout << col << setw((27 - tmp->Data().getProcessor().length())/2) << "" << setw(27 - (27 - tmp->Data().getProcessor().length())/2) << left << tmp->Data().getProcessor();
                        std::cout << col << setw((12 - tmp->Data().getRAM_ROM().length())/2) << "" << setw(12 - (12 - tmp->Data().getRAM_ROM().length())/2) << left << tmp->Data().getRAM_ROM();
                        std::cout << col << setw((29 - tmp->Data().getDisplay().length())/2) << "" << setw(29 - (29 - tmp->Data().getDisplay().length())/2) << left << tmp->Data().getDisplay();
                        std::cout << col << setw((13 - tmp->Data().getCamera().length())/2) << "" << setw(13 - (13 - tmp->Data().getCamera().length())/2) << left << tmp->Data().getCamera();
                        std::cout << col << setw(13 - (13 - to_string(tmp->Data().getEntryPrice()).length())/2) << right << tmp->Data().getEntryPrice() << setw((13 - to_string(tmp->Data().getEntryPrice()).length())/2) << "" ;
                        std::cout << col << setw(12 - (12 - to_string(tmp->Data().getSalePrice()).length())/2) << right << tmp->Data().getSalePrice() << setw((12 - to_string(tmp->Data().getSalePrice()).length())/2) << "" ;
                        std::cout << col << setw(8 - (8 - to_string(tmp->Data().getRemainingAmount()).length())/2) << right << tmp->Data().getRemainingAmount() << setw((8 - to_string(tmp->Data().getRemainingAmount()).length())/2) << "" ;
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
            std::getline(std::cin, processor);
            for(int i = 0; i < processor.length(); ++i) {
                processor[i] = tolower(processor[i]);
            }
            bool checkExist = false;
            for(Node<Phone> *tmp = this->list.HeadNode(); tmp != nullptr; tmp = tmp->NextNode()) {
                string tmps = "";
                for(int j = 0; j < tmp->Data().getProcessor().length(); ++j){
                    tmps += tolower(tmp->Data().getProcessor()[j]);
                }
                if(tmps.find(processor) != -1) {
                    checkExist = true;
                    tmp = nullptr;
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

                
                for(Node<Phone> *tmp = this->list.HeadNode(); tmp != nullptr; tmp = tmp->NextNode()) {
                    string tmps = "";
                    for(int j = 0; j < tmp->Data().getProcessor().length(); ++j){
                        tmps += tolower(tmp->Data().getProcessor()[j]);
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

                        std::cout << col << setw((39 - tmp->Data().getName().length())/2) << "" << setw(39 - (39 - tmp->Data().getName().length())/2) << left << tmp->Data().getName(); 
                        std::cout << col << setw((13 - tmp->Data().getID().length())/2) << "" << setw(13 - (13 - tmp->Data().getID().length())/2) << left << tmp->Data().getID();
                        std::cout << col << setw((9 - tmp->Data().getBrand().length())/2) << "" << setw(9 - (9 - tmp->Data().getBrand().length())/2) << left << tmp->Data().getBrand();
                        std::cout << col << setw((27 - tmp->Data().getProcessor().length())/2) << "" << setw(27 - (27 - tmp->Data().getProcessor().length())/2) << left << tmp->Data().getProcessor();
                        std::cout << col << setw((12 - tmp->Data().getRAM_ROM().length())/2) << "" << setw(12 - (12 - tmp->Data().getRAM_ROM().length())/2) << left << tmp->Data().getRAM_ROM();
                        std::cout << col << setw((29 - tmp->Data().getDisplay().length())/2) << "" << setw(29 - (29 - tmp->Data().getDisplay().length())/2) << left << tmp->Data().getDisplay();
                        std::cout << col << setw((13 - tmp->Data().getCamera().length())/2) << "" << setw(13 - (13 - tmp->Data().getCamera().length())/2) << left << tmp->Data().getCamera();
                        std::cout << col << setw(13 - (13 - to_string(tmp->Data().getEntryPrice()).length())/2) << right << tmp->Data().getEntryPrice() << setw((13 - to_string(tmp->Data().getEntryPrice()).length())/2) << "" ;
                        std::cout << col << setw(12 - (12 - to_string(tmp->Data().getSalePrice()).length())/2) << right << tmp->Data().getSalePrice() << setw((12 - to_string(tmp->Data().getSalePrice()).length())/2) << "" ;
                        std::cout << col << setw(8 - (8 - to_string(tmp->Data().getRemainingAmount()).length())/2) << right << tmp->Data().getRemainingAmount() << setw((8 - to_string(tmp->Data().getRemainingAmount()).length())/2) << "" ;
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
            for(Node<Phone> *tmp = this->list.HeadNode(); tmp != nullptr; tmp = tmp->NextNode()) {
                if(tmp->Data().getRAM_ROM() == RAM_ROM) {
                    checkExist = true;
                    tmp = nullptr;
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

                
                for(Node<Phone> *tmp = this->list.HeadNode(); tmp != nullptr; tmp = tmp->NextNode()) {
                    if(tmp->Data().getRAM_ROM() == RAM_ROM) {
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

                        std::cout << col << setw((39 - tmp->Data().getName().length())/2) << "" << setw(39 - (39 - tmp->Data().getName().length())/2) << left << tmp->Data().getName(); 
                        std::cout << col << setw((13 - tmp->Data().getID().length())/2) << "" << setw(13 - (13 - tmp->Data().getID().length())/2) << left << tmp->Data().getID();
                        std::cout << col << setw((9 - tmp->Data().getBrand().length())/2) << "" << setw(9 - (9 - tmp->Data().getBrand().length())/2) << left << tmp->Data().getBrand();
                        std::cout << col << setw((27 - tmp->Data().getProcessor().length())/2) << "" << setw(27 - (27 - tmp->Data().getProcessor().length())/2) << left << tmp->Data().getProcessor();
                        std::cout << col << setw((12 - tmp->Data().getRAM_ROM().length())/2) << "" << setw(12 - (12 - tmp->Data().getRAM_ROM().length())/2) << left << tmp->Data().getRAM_ROM();
                        std::cout << col << setw((29 - tmp->Data().getDisplay().length())/2) << "" << setw(29 - (29 - tmp->Data().getDisplay().length())/2) << left << tmp->Data().getDisplay();
                        std::cout << col << setw((13 - tmp->Data().getCamera().length())/2) << "" << setw(13 - (13 - tmp->Data().getCamera().length())/2) << left << tmp->Data().getCamera();
                        std::cout << col << setw(13 - (13 - to_string(tmp->Data().getEntryPrice()).length())/2) << right << tmp->Data().getEntryPrice() << setw((13 - to_string(tmp->Data().getEntryPrice()).length())/2) << "" ;
                        std::cout << col << setw(12 - (12 - to_string(tmp->Data().getSalePrice()).length())/2) << right << tmp->Data().getSalePrice() << setw((12 - to_string(tmp->Data().getSalePrice()).length())/2) << "" ;
                        std::cout << col << setw(8 - (8 - to_string(tmp->Data().getRemainingAmount()).length())/2) << right << tmp->Data().getRemainingAmount() << setw((8 - to_string(tmp->Data().getRemainingAmount()).length())/2) << "" ;
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
            std::cout << setw(45) << "" << "Your choice: ";
            string choice;
            cin >> choice; 
            cin.clear();
            fflush(stdin);
            if(choice != "1" && choice != "2") {
                std::cout << setw(45) << "" << "Invalid choice!\n"; 
                std::system("pause");
                continue;
            } else if(choice == "1") { // entry price
                string sprice, eprice;
                std::cout << setw(45) << "" << "Price from: ";
                std::cin >> sprice;
                cin.clear();
                fflush(stdin);
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
                cin.clear();
                fflush(stdin);
                
                if(!checkLegal) {
                    cout << setw(45) << "" << "Invalid price!\n";
                    std::system("pause");
                    continue;
                }

                int isprice = stoi(sprice), ieprice = stoi(eprice);
                bool checkExist = false;
                for(Node<Phone> *tmp = this->list.HeadNode(); tmp != nullptr; tmp = tmp->NextNode()) {
                    if(tmp->Data().getEntryPrice() >= isprice && tmp->Data().getEntryPrice() <= ieprice) {
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

                    
                    for(Node<Phone> *tmp = this->list.HeadNode(); tmp != nullptr; tmp = tmp->NextNode()) {
                        
                        if(tmp->Data().getEntryPrice() >= isprice && tmp->Data().getEntryPrice() <= ieprice) {
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

                            std::cout << col << setw((39 - tmp->Data().getName().length())/2) << "" << setw(39 - (39 - tmp->Data().getName().length())/2) << left << tmp->Data().getName(); 
                            std::cout << col << setw((13 - tmp->Data().getID().length())/2) << "" << setw(13 - (13 - tmp->Data().getID().length())/2) << left << tmp->Data().getID();
                            std::cout << col << setw((9 - tmp->Data().getBrand().length())/2) << "" << setw(9 - (9 - tmp->Data().getBrand().length())/2) << left << tmp->Data().getBrand();
                            std::cout << col << setw((27 - tmp->Data().getProcessor().length())/2) << "" << setw(27 - (27 - tmp->Data().getProcessor().length())/2) << left << tmp->Data().getProcessor();
                            std::cout << col << setw((12 - tmp->Data().getRAM_ROM().length())/2) << "" << setw(12 - (12 - tmp->Data().getRAM_ROM().length())/2) << left << tmp->Data().getRAM_ROM();
                            std::cout << col << setw((29 - tmp->Data().getDisplay().length())/2) << "" << setw(29 - (29 - tmp->Data().getDisplay().length())/2) << left << tmp->Data().getDisplay();
                            std::cout << col << setw((13 - tmp->Data().getCamera().length())/2) << "" << setw(13 - (13 - tmp->Data().getCamera().length())/2) << left << tmp->Data().getCamera();
                            std::cout << col << setw(13 - (13 - to_string(tmp->Data().getEntryPrice()).length())/2) << right << tmp->Data().getEntryPrice() << setw((13 - to_string(tmp->Data().getEntryPrice()).length())/2) << "" ;
                            std::cout << col << setw(12 - (12 - to_string(tmp->Data().getSalePrice()).length())/2) << right << tmp->Data().getSalePrice() << setw((12 - to_string(tmp->Data().getSalePrice()).length())/2) << "" ;
                            std::cout << col << setw(8 - (8 - to_string(tmp->Data().getRemainingAmount()).length())/2) << right << tmp->Data().getRemainingAmount() << setw((8 - to_string(tmp->Data().getRemainingAmount()).length())/2) << "" ;
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
                cin.clear();
                fflush(stdin);
                bool checkLegal = true;
                for(int i = 0; i < sprice.length(); ++i) {
                    if(sprice[i] < '0' || sprice[i] > '9') {
                        checkLegal = true;
                        break;
                    }
                }
                if(!checkLegal) {
                    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleTextAttribute(hConsole, brightred);
                    cout << setw(45) << "" << "Invalid price!\n";
                    SetConsoleTextAttribute(hConsole, brightwhite); 
                    std::system("pause");
                    continue;
                }
                
                std::cout << setw(51) << "" << "to: ";
                std::cin >> eprice;
                cin.clear();
                fflush(stdin);
                if(!checkLegal) {
                    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleTextAttribute(hConsole, brightred);
                    cout << setw(45) << "" << "Invalid price!\n";
                    SetConsoleTextAttribute(hConsole, brightwhite); 
                    std::system("pause");
                    continue;
                }

                int isprice = stoi(sprice), ieprice = stoi(eprice);
                bool checkExist = false;
                for(Node<Phone> *tmp = this->list.HeadNode(); tmp != nullptr; tmp = tmp->NextNode()) {
                    if(tmp->Data().getSalePrice() >= isprice && tmp->Data().getSalePrice() <= ieprice) {
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

                    
                    for(Node<Phone> *tmp = this->list.HeadNode(); tmp != nullptr; tmp = tmp->NextNode()) {
                        
                        if(tmp->Data().getSalePrice() >= isprice && tmp->Data().getSalePrice() <= ieprice) {
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

                            std::cout << col << setw((39 - tmp->Data().getName().length())/2) << "" << setw(39 - (39 - tmp->Data().getName().length())/2) << left << tmp->Data().getName(); 
                            std::cout << col << setw((13 - tmp->Data().getID().length())/2) << "" << setw(13 - (13 - tmp->Data().getID().length())/2) << left << tmp->Data().getID();
                            std::cout << col << setw((9 - tmp->Data().getBrand().length())/2) << "" << setw(9 - (9 - tmp->Data().getBrand().length())/2) << left << tmp->Data().getBrand();
                            std::cout << col << setw((27 - tmp->Data().getProcessor().length())/2) << "" << setw(27 - (27 - tmp->Data().getProcessor().length())/2) << left << tmp->Data().getProcessor();
                            std::cout << col << setw((12 - tmp->Data().getRAM_ROM().length())/2) << "" << setw(12 - (12 - tmp->Data().getRAM_ROM().length())/2) << left << tmp->Data().getRAM_ROM();
                            std::cout << col << setw((29 - tmp->Data().getDisplay().length())/2) << "" << setw(29 - (29 - tmp->Data().getDisplay().length())/2) << left << tmp->Data().getDisplay();
                            std::cout << col << setw((13 - tmp->Data().getCamera().length())/2) << "" << setw(13 - (13 - tmp->Data().getCamera().length())/2) << left << tmp->Data().getCamera();
                            std::cout << col << setw(13 - (13 - to_string(tmp->Data().getEntryPrice()).length())/2) << right << tmp->Data().getEntryPrice() << setw((13 - to_string(tmp->Data().getEntryPrice()).length())/2) << "" ;
                            std::cout << col << setw(12 - (12 - to_string(tmp->Data().getSalePrice()).length())/2) << right << tmp->Data().getSalePrice() << setw((12 - to_string(tmp->Data().getSalePrice()).length())/2) << "" ;
                            std::cout << col << setw(8 - (8 - to_string(tmp->Data().getRemainingAmount()).length())/2) << right << tmp->Data().getRemainingAmount() << setw((8 - to_string(tmp->Data().getRemainingAmount()).length())/2) << "" ;
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
    //      if (k->Data().getID()==m)
    //     {
    //         index=1;
    //         k->Data().showForStaff();
    //         break;
    //     }
    // }

    
    // if (index==-1) std::cout << "PhoneID does not exist!\n";
    // std::cout<<endl;

}
const string& PhoneManager::getID(int index) {
    static string s;
    if(index < 0 || index > this->list.size()) {
        return s;
    }
    Node<Phone> *phone = this->list.HeadNode();
    while(index--) {
        phone = phone->NextNode();
    }
    return phone->Data().getID();
   // return (this->p + index)->getID();
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

    Node<Phone> *tmp = this->list.HeadNode();
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
		std::cout << col << setw((39 - tmp->Data().getName().length())/2) << "" << setw(39 - (39 - tmp->Data().getName().length())/2) << left << tmp->Data().getName(); 
		std::cout << col << setw((13 - tmp->Data().getID().length())/2) << "" << setw(13 - (13 - tmp->Data().getID().length())/2) << left << tmp->Data().getID();
		std::cout << col << setw((9 - tmp->Data().getBrand().length())/2) << "" << setw(9 - (9 - tmp->Data().getBrand().length())/2) << left << tmp->Data().getBrand();
		std::cout << col << setw((27 - tmp->Data().getProcessor().length())/2) << "" << setw(27 - (27 - tmp->Data().getProcessor().length())/2) << left << tmp->Data().getProcessor();
		std::cout << col << setw((12 - tmp->Data().getRAM_ROM().length())/2) << "" << setw(12 - (12 - tmp->Data().getRAM_ROM().length())/2) << left << tmp->Data().getRAM_ROM();
		std::cout << col << setw((29 - tmp->Data().getDisplay().length())/2) << "" << setw(29 - (29 - tmp->Data().getDisplay().length())/2) << left << tmp->Data().getDisplay();
		std::cout << col << setw((13 - tmp->Data().getCamera().length())/2) << "" << setw(13 - (13 - tmp->Data().getCamera().length())/2) << left << tmp->Data().getCamera();
		std::cout << col << setw(13 - (13 - to_string(tmp->Data().getEntryPrice()).length())/2) << right << tmp->Data().getEntryPrice() << setw((13 - to_string(tmp->Data().getEntryPrice()).length())/2) << "" ;
		std::cout << col << setw(12 - (12 - to_string(tmp->Data().getSalePrice()).length())/2) << right << tmp->Data().getSalePrice() << setw((12 - to_string(tmp->Data().getSalePrice()).length())/2) << "" ;
		std::cout << col << setw(8 - (8 - to_string(tmp->Data().getRemainingAmount()).length())/2) << right << tmp->Data().getRemainingAmount() << setw((8 - to_string(tmp->Data().getRemainingAmount()).length())/2) << "" ;
		std::cout << col << "\n";

        tmp = tmp->NextNode();
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

            
    Node<Phone> *phone = this->list.HeadNode();
    
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
	
	for(int i = 0; i < this->list.size() / 5; ++i) {
        std::cout << setw(15) << "";
        for(int j = 0; j < 5; ++j) {
            std::cout << col << setw(3) << right << cnt << ". " << setw(20) << left << phone->Data().getName();
            phone = phone->NextNode();
            ++cnt;
        }
        std::cout << col << "\n";
        std::cout << setw(15) << "" << leftSide << line(25) << midMid << line(25) << midMid << line(25) << midMid << line(25) << midMid << line(25) << rightSide << "\n";
    }
    std::cout << setw(15) << "";
    for(int i = 0; i < this->list.size() % 5; ++i) {
        std::cout << col << setw(3) << right << cnt << ". " << setw(20) << left << phone->Data().getName();
        ++cnt;
        phone = phone->NextNode();
    }
    
    for(int i = 0; i < 5 - this->list.size() % 5; ++i) {
        cout << col << setw(25) << "";
    }

    std::cout << col << "\n";
    std::cout << setw(15) << "" << botLeftCorner << line(25) << botMid << line(25) << botMid << line(25) << botMid << line(25) << botMid << line(25) << botRightCorner << "\n";

}
void PhoneManager::Shopping(Order& order) {     
    
    while(true) {
        std::cout << setw(30) << "" << "Choose what you want to purchase\n";
        this->ShowTable();
        std::cout << "\n";
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, grey);
        std::cout << setw(45) << "" << "Enter 'exit' to exit!\n";
        SetConsoleTextAttribute(hConsole, brightwhite);
        std::cout << setw(45) << "" << "Your choice: ";
        string choice;
        std::cin >> choice;
        int ichoice = stringToInt(choice);
        if(choice == "exit") {

            break;
        } else if(ichoice < 1 || ichoice > this->GetLength()) {
            std::cout << setw(45) << "" << "Invalid choice, please re-enter!\n";
            std::system("pause");
        } else {

            this->Show(ichoice-1); 

            std::cout << setw(45) << "" << "Amount: ";
            string samount; std::cin >> samount;
            int amount = stringToInt(samount);

            if(amount > 0) {
                if(amount > this->getRemainingAmount(ichoice-1)) {
                    cout << setw(45) << "" << "Remaining amount is not enough\n"; 
                    //std::system("pause");
                } else {
                    if(order.searchCart(this->getID(ichoice-1))) {
                        order.addToCart(this->getID(ichoice-1),amount);
                    } else {
                        order.addToCart(Goods(this->getID(ichoice - 1),amount));
                    }
                    this->setRemainingAmount(ichoice-1,amount);
                    long long price = this->getPhonePrice(ichoice-1) *(long long)amount;
                    order.setTotalPrice(order.getTotalPrice() + price);
                     HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleTextAttribute(hConsole, brightgreen);
                    cout << setw(45) << "" << "Add to cart successfully!\n";
                    SetConsoleTextAttribute(hConsole, brightwhite); 
                    //std::system("pause");

                }
            } else {
                HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	            SetConsoleTextAttribute(hConsole, brightred);
                cout << setw(45) << "" << "Invalid amount!\n";
	            SetConsoleTextAttribute(hConsole, brightwhite);
            }
            std::system("pause");
        }
        //system("pause");
        std::system("cls");
    }
}
void PhoneManager::Show(int index) {
    int pos=0;
    for (Node<Phone> *tmp = this->list.HeadNode(); tmp != nullptr; tmp = tmp->NextNode())
    {
        if (pos==index) 
        {
            tmp->Data().showForCustomer();
            break;
        }
        pos++;
    }
}
const int& PhoneManager::getPhonePrice(int index) {
    static int i;
    if(index < 0 || index > this->list.size()) {
        return i;
    }
    Node<Phone> *phone = this->list.HeadNode();
    while(index--) {
        phone = phone->NextNode();
    }
    return phone->Data().getSalePrice();
}
const int& PhoneManager::getEntryPrice(int index) {
    static int i;
    if(index < 0 || index > this->list.size()) {
        return i;
    }
    Node<Phone> *phone = this->list.HeadNode();
    while(index--) {
        phone = phone->NextNode();
    }
    return phone->Data().getEntryPrice();
}
const int& PhoneManager::getRemainingAmount(int index) {
    static int i;
    if(index < 0 || index > this->list.size()) {
        return i;
    }
    Node<Phone> *phone = this->list.HeadNode();
    while(index--) {
        phone = phone->NextNode();
    }
    return phone->Data().getRemainingAmount();
}
void PhoneManager::setRemainingAmount(int index, int amount) {
    int pos=0;
    for (Node<Phone> *tmp = this->list.HeadNode(); tmp != nullptr; tmp = tmp->NextNode())
    {
        if (pos==index) 
        {
            //return k->Data().getRemainingAmount();   
            tmp->Data().setRemainingAmount(tmp->Data().getRemainingAmount() - amount);
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
    for (Node<Phone> *tmp = this->list.HeadNode(); tmp != nullptr; tmp = tmp->NextNode()) {
        string s = tmp->Data().getName() + "/" + tmp->Data().getID() + "/" + tmp->Data().getBrand() + "/" + tmp->Data().getProcessor() + "/" + tmp->Data().getRAM_ROM() + "/" + tmp->Data().getDisplay() + "/" + tmp->Data().getCamera() + "/" + to_string(tmp->Data().getEntryPrice()) + "/" + to_string(tmp->Data().getSalePrice()) + "/" + to_string(tmp->Data().getRemainingAmount()) + "/" ;
        if(d != this->list.size()-1) editfile << s << "\n";
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
            cin.clear();
            fflush(stdin);
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
            string phoneID;
            std::cout << setw(45) << "" << "Enter phone id: ";
            getline(cin, phoneID);

            if(phoneID == "exit") {
                continue;
            }
            for(int i = 0; i < phoneID.length(); ++i) {
                phoneID[i] = tolower(phoneID[i]);
            }
            bool exist = false;
            Node<Phone> *tmp = this->list.HeadNode();
            while(tmp != nullptr) {
                if(tmp->Data().getID() == phoneID) {
                    exist = true;
                    break;
                }
                tmp = tmp->NextNode();
            }
            if(!exist) {
                string phoneName, brand, processor, RAM_ROM, display, camera; 
                int entryPrice, salePrice, amount;
                std::cout << setw(45) << "" << "Enter phone name: ";
                getline(cin, phoneName);
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
                HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	            SetConsoleTextAttribute(hConsole, brightyellow);
                std::cout << setw(45) << "" << "Phone exists!\n";
	            SetConsoleTextAttribute(hConsole, brightwhite);
                tmp->Data().showForStaff();
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
            cin.clear();
            fflush(stdin);
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
// const PhoneManager& PhoneManager::operator=(const PhoneManager& pm)
// {
    
//     this->list = pm.list;
//     return *this;
// }