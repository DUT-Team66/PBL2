#include <iostream>
#include "StaffManager.h"
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <conio.h>
#include "Table.h"
using namespace std;

string compact(string s) {
    string res = "";
    
    if(s[0] >= 'A' && s[0] <= 'Z') {
        stringstream ss(s);
        string tmp;
        while(ss >> tmp) {
            res += tolower(tmp[0]);
        }
        tmp = "";
        for(int i = s.length()-1; s[i] >= 'a' && s[i] <= 'z'; --i) {
            tmp = s[i] + tmp;
        }
        res += tmp;
    } else {
        for(int i = 0; i < s.length(); ++i) {
            if(s[i] != '-'){
                res += s[i];
            }
        }
    }
    return res;
}
StaffManager::StaffManager()
{
    this->p = nullptr;
    this->n = 0;
}
StaffManager::~StaffManager()
{
    delete[] this->p;
}
void StaffManager::Add(const Staff &s)
{
    if (this->n == 0)
    {
        this->p = new Staff[this->n + 1];
        *(this->p + this->n) = s;
        this->n++;
    }
    else
    {
        Staff *temp = new Staff[this->n];
        for (int i = 0; i < this->n; i++)   
        {
            *(temp + i) = *(this->p + i);
        }
        delete[] this->p;
        this->p = new Staff[this->n + 1];
        for (int i = 0; i < this->n; i++) // còn phần tử cuối
            *(this->p + i) = *(temp + i);
        delete[] temp;
        *(this->p + this->n) = s;
        this->n++;
        
    }
}
void StaffManager::Delete(string s)
{
    int index = -1;
    for (int i = 0; i < this->n; i++)
    {
        if ((this->p + i)->getID() == s)
        {
            index = i;
            break;
        }
    }

    // Chu y truong hop index=-1(khong tim duoc)

    if (index >= 0)
    {
        if (this->n == 1)
        {
            delete[] this->p;
            this->p = nullptr;
            this->n--;
        }
        else
        {
            Staff *temp = new Staff[this->n];
            for (int i = 0; i < this->n; i++) {
                *(temp + i) = *(this->p + i);
            }
            delete[] this->p;
            this->p = new Staff[this->n - 1];
            for (int i = 0; i < index; i++) {
                *(this->p + i) = *(temp + i);
            }
            for (int i = index; i < this->n - 1; i++) {
                *(this->p + i) = *(temp + i + 1);
            }
            delete[] temp;
            this->n--;
        }
        std::cout << "Delete successfully!\n";
    } else {
        std::cout << "Staff ID does not exist!\n";
    }
}
void StaffManager::Search()
{
    // int index = -1;
    // for (int i = 0; i < this->n; i++)
    // {
    //     if ((this->p + i)->getID() == s) {
    //         index = i;
    //         break;
    //     }
    // }

    // if (index >= 0)
    //     (this->p + index)->show();
    // else std::cout << "Staff ID does not exist!\n";

    std::system("cls");
    std::cout << setw(50) << "" << topLeftCorner << line(8) << topRightCorner << "\n";
    std::cout << setw(50) << "" << col << " STAFFS " << col << "\n";
    std::cout << setw(50) << "" << botLeftCorner << line(8) << botRightCorner << "\n\n";
    string choice; 
    std::cout << setw(47) << "" << "1. Search by ID" << "\n";
    std::cout << setw(47) << "" << "2. Search by name" << "\n";
    std::cout << setw(47) << "" << "3. Search by gender" << "\n";
    std::cout << setw(47) << "" << "4. Search by year of birth" << "\n"; 
    std::cout << setw(47) << "" << "5. Search by phone number" << "\n";
    //std::cout << setw(35) << "" << "6. Search by address" << "\n";
    //std::cout << setw(35) << "" << "7. Search by salary" << "\n"; // salary from ... to ...
    std::cout << setw(47) << "" << "6. Go back" << "\n";
    std::cout << setw(45) << "" << "Your choice: ";
    cin >> choice;
    if(choice != "1" && choice != "2" && choice != "3" && choice != "4" && choice != "5" && choice != "6") {
        std::cout << "Invalid choice!\n";
        std::system("pause");
    }

    

    if(choice == "1") {
        string id;
        cout << setw(47) << "" << "Enter staff ID: ";
        cin >> id;   
        std::cout << topLeftCorner << line(30); // staff name
        std::cout << topMid << line(14); //staffID
        std::cout << topMid << line(8); // gender
        std::cout << topMid << line(12); // dob
        std::cout << topMid << line(14); //phonenumber
        std::cout << topMid << line(26); //address
        std::cout << topMid << line(13); //salary
        std::cout << topMid << line(11); //username
        std::cout << topMid << line(10); // password
        std::cout << topRightCorner << "\n";
        

        std::cout << col << setw(9) << "" << setw(21) << left << "Staff name"; 
        std::cout << col << setw(3) << "" << setw(11) << left << "Staff ID";
        std::cout << col << setw(1) << "" << setw(7) << left << "Gender";
        std::cout << col << setw(4) << "" << setw(8) << left << "DOB";
        std::cout << col << setw(1) << "" << setw(13) << left << "Phone number";
        std::cout << col << setw(9) << "" << setw(17) << left << "Address";
        std::cout << col << setw(2) << "" << setw(11) << left << "Salary";
        std::cout << col << setw(2) << "" << setw(9) << left << "Username";
        std::cout << col << setw(1) << "" << setw(9) << left << "Password";
        std::cout << col << "\n";
        for(int i = 0; i < this->n; ++i) {
            if(id == (this->p + i)->getID()) {
                std::cout << midMid << line(30);
                std::cout << midMid << line(14);
                std::cout << midMid << line(8);
                std::cout << midMid << line(12);
                std::cout << midMid << line(14);
                std::cout << midMid << line(26);
                std::cout << midMid << line(13);
                std::cout << midMid << line(11);
                std::cout << midMid << line(10);
                std::cout << rightSide << "\n";
                
                (this->p + i)->show();
            }
        }
    } else if (choice == "2") {
        string name;
        cout << setw(47) << "" << "Enter staff name: ";
        cin >> name;
        std::cout << topLeftCorner << line(30); // staffname 
        std::cout << topMid << line(14); //staffID
        std::cout << topMid << line(8); // gender
        std::cout << topMid << line(12); // dob
        std::cout << topMid << line(14); //phonenumber
        std::cout << topMid << line(26); //address
        std::cout << topMid << line(13); //salary
        std::cout << topMid << line(11); //username
        std::cout << topMid << line(10); // password
        std::cout << topRightCorner << "\n";
        
        
        std::cout << col << setw(9) << "" << setw(21) << left << "Staff name"; 
        std::cout << col << setw(3) << "" << setw(11) << left << "Staff ID";
        std::cout << col << setw(1) << "" << setw(7) << left << "Gender";
        std::cout << col << setw(4) << "" << setw(8) << left << "DOB";
        std::cout << col << setw(1) << "" << setw(13) << left << "Phone number";
        std::cout << col << setw(9) << "" << setw(17) << left << "Address";
        std::cout << col << setw(2) << "" << setw(11) << left << "Salary";
        std::cout << col << setw(2) << "" << setw(9) << left << "Username";
        std::cout << col << setw(1) << "" << setw(9) << left << "Password";
        std::cout << col << "\n";

        for(int i = 0; i < name.length(); ++i) {
            name[i] = tolower(name[i]);
        }
        for(int i = 0; i < this->n; ++i) {
            string tmp = "";
            for(int j = 0; j < (this->p + i)->getName().length(); ++j){
                tmp += tolower((this->p + i)->getName()[j]);
            }
            if(tmp.find(name) != -1) {

                std::cout << midMid << line(30);
                std::cout << midMid << line(14);
                std::cout << midMid << line(8);
                std::cout << midMid << line(12);
                std::cout << midMid << line(14);
                std::cout << midMid << line(26);
                std::cout << midMid << line(13);
                std::cout << midMid << line(11);
                std::cout << midMid << line(10);
                std::cout << rightSide << "\n";

                (this->p + i)->show(); 
            }
        }
    } else if (choice == "3") {
        string gender;
        cout << setw(47) << "" << "Enter gender: ";
        cin >> gender;

        std::cout << topLeftCorner << line(30); // staffname 
        std::cout << topMid << line(14); //staffID
        std::cout << topMid << line(8); // gender
        std::cout << topMid << line(12); // dob
        std::cout << topMid << line(14); //phonenumber
        std::cout << topMid << line(26); //address
        std::cout << topMid << line(13); //salary
        std::cout << topMid << line(11); //username
        std::cout << topMid << line(10); // password
        std::cout << topRightCorner << "\n";
        
        
        std::cout << col << setw(9) << "" << setw(21) << left << "Staff name"; 
        std::cout << col << setw(3) << "" << setw(11) << left << "Staff ID";
        std::cout << col << setw(1) << "" << setw(7) << left << "Gender";
        std::cout << col << setw(4) << "" << setw(8) << left << "DOB";
        std::cout << col << setw(1) << "" << setw(13) << left << "Phone number";
        std::cout << col << setw(9) << "" << setw(17) << left << "Address";
        std::cout << col << setw(2) << "" << setw(11) << left << "Salary";
        std::cout << col << setw(2) << "" << setw(9) << left << "Username";
        std::cout << col << setw(1) << "" << setw(9) << left << "Password";
        std::cout << col << "\n";

        for(int i = 0; i < this->n; ++i){
            if(gender == (this->p + i)->getGender()) {

                std::cout << midMid << line(30);
                std::cout << midMid << line(14);
                std::cout << midMid << line(8);
                std::cout << midMid << line(12);
                std::cout << midMid << line(14);
                std::cout << midMid << line(26);
                std::cout << midMid << line(13);
                std::cout << midMid << line(11);
                std::cout << midMid << line(10);
                std::cout << rightSide << "\n";

                (this->p + i)->show();
            }
        }
    } else if (choice == "4") {
        string year;
        cout << setw(47) << "" << "Enter year of birth: ";
        cin >> year;
        
        std::cout << topLeftCorner << line(30); // staffname 
        std::cout << topMid << line(14); //staffID
        std::cout << topMid << line(8); // gender
        std::cout << topMid << line(12); // dob
        std::cout << topMid << line(14); //phonenumber
        std::cout << topMid << line(26); //address
        std::cout << topMid << line(13); //salary
        std::cout << topMid << line(11); //username
        std::cout << topMid << line(10); // password
        std::cout << topRightCorner << "\n";
        
        
        std::cout << col << setw(9) << "" << setw(21) << left << "Staff name"; 
        std::cout << col << setw(3) << "" << setw(11) << left << "Staff ID";
        std::cout << col << setw(1) << "" << setw(7) << left << "Gender";
        std::cout << col << setw(4) << "" << setw(8) << left << "DOB";
        std::cout << col << setw(1) << "" << setw(13) << left << "Phone number";
        std::cout << col << setw(9) << "" << setw(17) << left << "Address";
        std::cout << col << setw(2) << "" << setw(11) << left << "Salary";
        std::cout << col << setw(2) << "" << setw(9) << left << "Username";
        std::cout << col << setw(1) << "" << setw(9) << left << "Password";
        std::cout << col << "\n";

        for(int i = 0; i < this->n; ++i) {
            if((this->p + i)->getDob().substr(6) == year) {

                std::cout << midMid << line(30);
                std::cout << midMid << line(14);
                std::cout << midMid << line(8);
                std::cout << midMid << line(12);
                std::cout << midMid << line(14);
                std::cout << midMid << line(26);
                std::cout << midMid << line(13);
                std::cout << midMid << line(11);
                std::cout << midMid << line(10);
                std::cout << rightSide << "\n";

                (this->p + i)->show();
            }
        }
    } else if (choice == "5") {
        string phoneNumber;
        cout << setw(47) << "" << "Enter phone number: ";
        cin >> phoneNumber;

        std::cout << topLeftCorner << line(30); // staffname 
        std::cout << topMid << line(14); //staffID
        std::cout << topMid << line(8); // gender
        std::cout << topMid << line(12); // dob
        std::cout << topMid << line(14); //phonenumber
        std::cout << topMid << line(26); //address
        std::cout << topMid << line(13); //salary
        std::cout << topMid << line(11); //username
        std::cout << topMid << line(10); // password
        std::cout << topRightCorner << "\n";
        
        
        std::cout << col << setw(9) << "" << setw(21) << left << "Staff name"; 
        std::cout << col << setw(3) << "" << setw(11) << left << "Staff ID";
        std::cout << col << setw(1) << "" << setw(7) << left << "Gender";
        std::cout << col << setw(4) << "" << setw(8) << left << "DOB";
        std::cout << col << setw(1) << "" << setw(13) << left << "Phone number";
        std::cout << col << setw(9) << "" << setw(17) << left << "Address";
        std::cout << col << setw(2) << "" << setw(11) << left << "Salary";
        std::cout << col << setw(2) << "" << setw(9) << left << "Username";
        std::cout << col << setw(1) << "" << setw(9) << left << "Password";
        std::cout << col << "\n";

        for(int i = 0; i < this->n; ++i) {
            if(phoneNumber == (this->p + i)->getPhoneNumber()) {

                std::cout << midMid << line(30);
                std::cout << midMid << line(14);
                std::cout << midMid << line(8);
                std::cout << midMid << line(12);
                std::cout << midMid << line(14);
                std::cout << midMid << line(26);
                std::cout << midMid << line(13);
                std::cout << midMid << line(11);
                std::cout << midMid << line(10);
                std::cout << rightSide << "\n";

                (this->p + i)->show();
            }
        }
    } else if (choice == "6") {
        return;
    }


    std::cout << botLeftCorner << line(30); // staff name
	std::cout << botMid << line(14); //staffID
	std::cout << botMid << line(8); // gender
	std::cout << botMid << line(12); // dob
	std::cout << botMid << line(14); //phonenumber
	std::cout << botMid << line(26); //address
	std::cout << botMid << line(13); //salary
	std::cout << botMid << line(11); // username
	std::cout << botMid << line(10); // password
	std::cout << botRightCorner << "\n";

    //std::system("pause");
 }



// chu y: Update co the cap nhat nhieu cai
void StaffManager::Update(string id) 
{
    bool check = false;
    cin.ignore();
    for(int i = 0; i < this->n; ++i) {
        if((this->p + i)->getID() == id) {
            string name, gender, dob, phoneNumber, address;
            std::cout << "Enter name: ";
            getline(cin, name);
            std::cout << "Enter gender: ";
            getline(cin, gender);
            std::cout << "Enter dob: ";
            getline(cin, dob);
            std::cout << "Enter phone number: ";
            getline(cin, phoneNumber);
            std::cout << "Enter address: ";
            getline(cin, address);
            if(name != "") {
                (this->p + i)->setName(name);
            }
            if(gender != "") {
                (this->p + i)->setGender(gender);
            }
            if(dob != "") {
                (this->p + i)->setDob(dob);
            }
            if(phoneNumber != "") {
                (this->p + i)->setPhoneNumber(phoneNumber);
            }
            if(address != "") {
                (this->p + i)->setAddress(address);
            }
            check = true;
            break;
            std::cout << "Update successfully!\n";
        }
    }
    if(!check) std::cout << "Staff ID does not exist!\n";
}
void StaffManager::Show() const
{
    std::cout << topLeftCorner << line(7); // order   
    std::cout << topMid << line(30); // staff name
	std::cout << topMid << line(14); //staffID
	std::cout << topMid << line(8); // gender
	std::cout << topMid << line(12); // dob
	std::cout << topMid << line(14); //phonenumber
	std::cout << topMid << line(26); //address
	std::cout << topMid << line(13); //salary
	std::cout << topMid << line(11); //username
	std::cout << topMid << line(10); // password
	std::cout << topRightCorner << "\n";
	
    std::cout << col << setw(1) << "" << setw(6) << left << "Order";
	std::cout << col << setw(9) << "" << setw(21) << left << "Staff name"; 
	std::cout << col << setw(3) << "" << setw(11) << left << "Staff ID";
	std::cout << col << setw(1) << "" << setw(7) << left << "Gender";
	std::cout << col << setw(4) << "" << setw(8) << left << "DOB";
	std::cout << col << setw(1) << "" << setw(13) << left << "Phone number";
	std::cout << col << setw(9) << "" << setw(17) << left << "Address";
	std::cout << col << setw(2) << "" << setw(11) << left << "Salary";
	std::cout << col << setw(2) << "" << setw(9) << left << "Username";
	std::cout << col << setw(1) << "" << setw(9) << left << "Password";
	std::cout << col << "\n";
	
	for(int i = 0; i < this->n; ++i) {
		std::cout << leftSide << line(7); 
        std::cout << midMid << line(30);
		std::cout << midMid << line(14);
		std::cout << midMid << line(8);
		std::cout << midMid << line(12);
		std::cout << midMid << line(14);
		std::cout << midMid << line(26);
		std::cout << midMid << line(13);
		std::cout << midMid << line(11);
		std::cout << midMid << line(10);
		std::cout << rightSide << "\n";
		
        std::cout << col << setw((7 - to_string(i + 1).length())/2) << "" << setw(7 - (7 - to_string(i + 1).length())/2) << left << i + 1;
		std::cout << col << setw((30 - (this->p + i)->getName().length())/2) << "" << setw(30 - (30 - (this->p + i)->getName().length())/2) << left << (this->p + i)->getName();
		std::cout << col << setw((14 - (this->p + i)->getID().length())/2) << "" << setw(14 - (14 - (this->p + i)->getID().length())/2) << left << (this->p + i)->getID();
		std::cout << col << setw((8 - (this->p + i)->getGender().length())/2) << "" << setw(8 - (8 - (this->p + i)->getGender().length())/2) << left << (this->p + i)->getGender();
		std::cout << col << setw((12 - (this->p + i)->getDob().length())/2) << "" << setw(12 - (12 - (this->p + i)->getDob().length())/2) << left << (this->p + i)->getDob();
		std::cout << col << setw((14 - (this->p + i)->getPhoneNumber().length())/2) << "" << setw(14 - (14 - (this->p + i)->getPhoneNumber().length())/2) << left << (this->p + i)->getPhoneNumber();
		std::cout << col << setw(26 - (26 - (this->p + i)->getAddress().length())/2) << right << (this->p + i)->getAddress() << setw((26 - (this->p + i)->getAddress().length())/2) << "";
		std::cout << col << setw(13 - (13 - to_string((this->p + i)->getSalary()).length())/2) << right << (this->p + i)->getSalary() << setw((13 - to_string((this->p + i)->getSalary()).length())/2) << "";
		std::cout << col << setw(11 - (11 - (this->p + i)->getUsername().length())/2) << right << (this->p + i)->getUsername() << setw((11 - (this->p + i)->getUsername().length())/2) << "";
		std::cout << col << setw(10 - (10 - (this->p + i)->getPassword().length())/2) << right << (this->p + i)->getPassword() << setw((10 - (this->p + i)->getPassword().length())/2) << ""; 
		std::cout << col << "\n";
	}
	
	
	std::cout << botLeftCorner << line(7); // order 
    std::cout << botMid << line(30); // staff name
	std::cout << botMid << line(14); //staffID
	std::cout << botMid << line(8); // gender
	std::cout << botMid << line(12); // dob
	std::cout << botMid << line(14); //phonenumber
	std::cout << botMid << line(26); //address
	std::cout << botMid << line(13); //salary
	std::cout << botMid << line(11); // username
	std::cout << botMid << line(10); // password
	std::cout << botRightCorner << "\n";
	
    
}
const int& StaffManager::GetLength() const {
    return this->n;
}
const string& StaffManager::getStaffName(int index) const {
    return (this->p + index)->getName();
}
const string& StaffManager::getStaffID(int index) const {
    return (this->p + index)->getID();
}
const string& StaffManager::getStaffGender(int index) const {
    return (this->p + index)->getGender();
}
const string& StaffManager::getStaffDob(int index) const {
    return (this->p + index)->getDob();
}
const string& StaffManager::getStaffPhoneNumber(int index) const {
    return (this->p + index)->getPhoneNumber();
}
const string& StaffManager::getStaffAddress(int index) const {
    return (this->p + index)->getAddress();
}
void StaffManager::LoadData() {
    fstream readfile("Staff.txt", ios::in);
	string tmpline;
	while(getline(readfile,tmpline)) {
		
		string name = "", id = "", gender = "", dob = "", phonenumber = "", address = "", username = "", password = "";
	
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
			gender += tmpline[i];
			++i;
		}
		++i;
        while(tmpline[i] != '/') {
			dob += tmpline[i];
			++i;
		}
		++i;
        while(tmpline[i] != '/') {
			phonenumber += tmpline[i];
			++i;
		}
		++i;
        while(tmpline[i] != '/') {
			address += tmpline[i];
			++i;
		}
		++i;
        while(tmpline[i] != '/') {
            username += tmpline[i];
            ++i;
        }
        ++i;
        while(tmpline[i] != '/') {
            password += tmpline[i];
            ++i;
        }
        ++i;
        this->Add(Staff(name,id, gender, dob, phonenumber, address,username,password));
    }
    readfile.close();
}
void StaffManager::UpdateFile() {
    fstream editfile("Staff.txt", ios::out);
    for(int i = 0;i < this->n; ++i) {
        string s = (this->p + i)->getName() + "/" + (this->p + i)->getID() + "/" + (this->p + i)->getGender() + "/" + (this->p + i)->getDob() + "/" + (this->p + i)->getPhoneNumber() + "/" + (this->p + i)->getAddress() + "/" + (this->p + i)->getUsername() + "/" + (this->p + i)->getPassword() + "/";
        if(i != this->n-1)
            editfile << s << "\n";
        else editfile << s;
    }
    editfile.close();


}
void StaffManager::Menu() {
    std::system("cls");
    while(true) {
        string choice;
        while(true) {
            std::cout << setw(50) << "" << topLeftCorner << line(8) << topRightCorner << "\n";
	        std::cout << setw(50) << "" << col << " STAFFS " << col << "\n";
	        std::cout << setw(50) << "" << botLeftCorner << line(8) << botRightCorner << "\n\n";
            // std::cout << setw(25) << "STAFFS" << "\n\n";
            //this->Show();
            std::cout << setw(47) << "" << "1. Add a staff" << "\n"; // nhap day du thong tin cua staff
            std::cout << setw(47) << "" << "2. Delete a staff" << "\n"; // nhap staffid
            std::cout << setw(47) << "" << "3. Search a staff" << "\n"; // nhap staffid
            std::cout << setw(47) << "" << "4. Update a staff" << "\n"; // nhap day du thong tin cua staff, neu khong doi nhap N/A
            std::cout << setw(47) << "" << "5. Show all staffs" << "\n";
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
            string id;
            cin.ignore();
            bool exist = false;
            std::cout << setw(4) << "" << char(16) << "Enter ID: ";
            getline(cin, id);
            for(int i = 0;i < this->n; ++i) {
                if(id == (this->p + i)->getID()) {
                    exist = true;
                }
            }
            if(!exist) {
                string name, gender, dob, phoneNumber, address;
                std::cout << setw(4) << "" << char(16) << "Enter name: ";
                getline(cin, name);
                std::cout << setw(4) << "" << char(16) << "Enter gender: ";
                getline(cin, gender);
                std::cout << setw(4) << "" << char(16) << "Enter dob: ";
                getline(cin, dob);
                std::cout << setw(4) << "" << char(16) << "Enter phone number: ";
                getline(cin, phoneNumber);
                std::cout << setw(4) << "" << char(16) << "Enter address: ";
                getline(cin, address);
                
                this->Add(Staff(name, id, gender, dob, phoneNumber, address, compact(name), compact(dob)));
                std::cout << "Add successfully!\n";
            } else {
                std::cout << "Staff exists\n";
            }
        } else if (choice == "2") {
            this->Show();
            string s;
            std::cout << "Enter ID: ";
            cin >> s;
            this->Delete(s);
        } else if(choice == "3") {
            //this->Show();
            
            this->Search();
        } else if (choice == "4") {
            this->Show();
            string s;
            std::cout << "Enter ID: ";
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
void StaffManager::Login(bool& isAdmin, bool& isStaff) {
    
    while(true) {
        string username, password;
        std::cout << setw(35) << "" << "----LOGIN---- " << "\n\n";
        std::cout << setw(32) << "" << "Username: ";
        cin >> username;
        std::cout << "\n";
        if(username == "exit") {
            break;
        }
        std::cout << setw(32) << "" << "Password: ";
        //cin >> password;
        char x = 'a';
        while (x != '\n'){
            x = getch();
            if (x == 13) break;
            else if (x == 8 && password.size() != 0){
                password.pop_back();
                std::cout << "\b" << " \b";
            }
            else if (x != 8){
                password += x;
                std::cout << '*';
            }
        }
        
        std::cout << "\n";

        if(username == "admin" && password == "admin") {
            isAdmin = true;
        } else {
            for(int i = 0; i < this->n; ++i) {
                if(username == (this->p + i)->getUsername() && password == (this->p + i)->getPassword()) {
                    isStaff = true;
                    break;
                }
            }
        }
        if(isStaff || isAdmin)  {
            std::cout << "Login successfully!\n";
            break;
        } else {
            std::cout << "Invalid login information!\n";
        }
        system("pause"); 
        system("cls");
    }
}
const StaffManager& StaffManager::operator=(const StaffManager& v )
{
    if (this != &v) {
        this->n=v.n;
        delete[] this->p;
        this->p = new Staff[this->n];
        for (int i=0;i<this->n;i++)
            *(this->p + i) = *(v.p+i); 
    }
    return *this;
}