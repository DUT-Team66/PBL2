#include <iostream>
#include "PhoneManager.h"
#include <string>
#include <fstream>
#include <iomanip>
#include "Table.h"
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
void PhoneManager::Update(string m){
    bool check = false;
    cin.ignore();
    for (Node *k=this->pHead;k!=NULL;k=k->pNext) {
        if(k->data.getPhoneID()==m) {
            string phoneName, phoneID, brand, processor, RAM_ROM, display, camera ;
            int entryPrice, salePrice, remainingAmount; 
            std::cout<<"Enter phonename: ";
            getline(cin, phoneName);
            std::cout << "Enter phoneID: ";
            getline(cin,phoneID);
            std::cout << "Enter brand: ";
            getline(cin,brand);
            std::cout << "Enter processor: ";
            getline(cin, processor);
            std::cout<<"Enter RAM/ROM: ";
            getline(cin,RAM_ROM);
            std::cout<<"Enter display: ";
            getline(cin,display);
            std::cout<<"Enter camera: ";
            getline(cin,camera);
            std::cout<<"Enter entryprice: ";
            cin>>entryPrice;
            std::cout<<"Enter saleprice: ";
            cin>>salePrice;
            std::cout<<"Enter remainingamount: ";
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
            std::cout << "Update successfully!\n";
            check = true;
            break;  
        }
    }
    if(!check) std::cout << "PhoneID does not exist!" << "\n";
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

    
    if (index==-1) std::cout << "PhoneID does not exist!\n";
    std::cout<<endl;

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
        std::cout << leftSide << line(7); 
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
    std::cout << botMid << line(39); // staff name
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
        string choice;
        while(true) {
            
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
            string phoneName;
            cin.ignore();
            bool exist = false;
            std::cout << setw(45) << "" << "Enter phone name: ";
            getline(cin, phoneName);
            Node* tmp = this->pHead;
            while(tmp != nullptr) {
                if(tmp->data.getPhoneName() == phoneName) {
                    exist = true;
                    break;
                }
            }
            if(!exist) {
                string phoneID, brand, processor, RAM_ROM, display, camera; 
                int entryPrice, salePrice;
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
                
                
                this->Add(Phone(phoneName, phoneID, brand, processor, RAM_ROM, display, camera, entryPrice, salePrice));
                std::cout << setw(45) << "" << "\nAdd successfully!\n";
            } else {
                std::cout << setw(45) << "" << "Phone exists";
            }
        } else if (choice == "2") {
            this->Show();
            string s;
            std::cout << setw(45) << "" << "Enter ID: ";
            cin >> s;
            this->Delete(s);
        } else if(choice == "3") {
            string s;
            std::cout << setw(45) << "" << "Enter ID:";
            cin >> s;
            this->Search(s);
        } else if (choice == "4") {
            string s; 
            std::cout << setw(45) << "" << "Enter ID: ";
            cin >> s;
            this->Update(s);
        } else if(choice == "5") {
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