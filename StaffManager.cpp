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
        cout << "Delete successfully!\n";
    } else {
        cout << "Staff ID does not exist!\n";
    }
}
void StaffManager::Search(string s)
{
    int index = -1;
    for (int i = 0; i < this->n; i++)
    {
        if ((this->p + i)->getID() == s) {
            index = i;
            break;
        }
    }

    if (index >= 0)
        (this->p + index)->show();
    else cout << "Staff ID does not exist!\n";
}



// chu y: Update co the cap nhat nhieu cai
void StaffManager::Update(string id) 
{
    bool check = false;
    cin.ignore();
    for(int i = 0; i < this->n; ++i) {
        if((this->p + i)->getID() == id) {
            string name, gender, dob, phoneNumber, address;
            cout << "Enter name: ";
            getline(cin, name);
            cout << "Enter gender: ";
            getline(cin, gender);
            cout << "Enter dob: ";
            getline(cin, dob);
            cout << "Enter phone number: ";
            getline(cin, phoneNumber);
            cout << "Enter address: ";
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
            cout << "Update successfully!\n";
        }
    }
    if(!check) cout << "Staff ID does not exist!\n";
}
void StaffManager::Show() const
{
    cout << topLeftCorner << line(30); // staff name
	cout << topMid << line(14); //staffID
	cout << topMid << line(8); // gender
	cout << topMid << line(12); // dob
	cout << topMid << line(14); //phonenumber
	cout << topMid << line(26); //address
	cout << topMid << line(13); //salary
	cout << topMid << line(11); //username
	cout << topMid << line(10); // password
	cout << topRightCorner << "\n";
	
	cout << col << setw(9) << "" << setw(21) << left << "Staff name"; 
	cout << col << setw(3) << "" << setw(11) << left << "Staff ID";
	cout << col << setw(1) << "" << setw(7) << left << "Gender";
	cout << col << setw(4) << "" << setw(8) << left << "DOB";
	cout << col << setw(1) << "" << setw(13) << left << "Phone number";
	cout << col << setw(9) << "" << setw(17) << left << "Address";
	cout << col << setw(2) << "" << setw(11) << left << "Salary";
	cout << col << setw(2) << "" << setw(9) << left << "Username";
	cout << col << setw(1) << "" << setw(9) << left << "Password";
	cout << col << "\n";
	
	for(int i = 0; i < this->n; ++i) {
		cout << leftSide << line(30);
		cout << midMid << line(14);
		cout << midMid << line(8);
		cout << midMid << line(12);
		cout << midMid << line(14);
		cout << midMid << line(26);
		cout << midMid << line(13);
		cout << midMid << line(11);
		cout << midMid << line(10);
		cout << rightSide << "\n";
		
		cout << col << " " << setw(29) << left << (this->p + i)->getName();
		cout << col << " " << setw(13) << left << (this->p + i)->getID();
		cout << col << " " << setw(7) << left << (this->p + i)->getGender();
		cout << col << " " << setw(11) << left << (this->p + i)->getDob();
		cout << col << "  " << setw(12) << left << (this->p + i)->getPhoneNumber();
		cout << col << setw(25) << right << (this->p + i)->getAddress() << setw(1) << "";
		cout << col << setw(12) << right << (this->p + i)->getSalary() << setw(1) << "";
		cout << col << setw(10) << right << (this->p + i)->getUsername() << setw(1) << "";
		cout << col << setw(9) << right << (this->p + i)->getPassword() << setw(1) << ""; 
		cout << col << "\n";
	}
	
	
	cout << botLeftCorner << line(30); // staff name
	cout << botMid << line(14); //staffID
	cout << botMid << line(8); // gender
	cout << botMid << line(12); // dob
	cout << botMid << line(14); //phonenumber
	cout << botMid << line(26); //address
	cout << botMid << line(13); //salary
	cout << botMid << line(11);
	cout << botMid << line(10);
	cout << botRightCorner << "\n";
	
    
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
            cout << setw(50) << "" << topLeftCorner << line(8) << topRightCorner << "\n";
	        cout << setw(50) << "" << col << " STAFFS " << col << "\n";
	        cout << setw(50) << "" << botLeftCorner << line(8) << botRightCorner << "\n\n";
            // cout << setw(25) << "STAFFS" << "\n\n";
            this->Show();
            cout << setw(47) << "" << "1. Add a staff" << "\n"; // nhap day du thong tin cua staff
            cout << setw(47) << "" << "2. Delete a staff" << "\n"; // nhap staffid
            cout << setw(47) << "" << "3. Search a staff" << "\n"; // nhap staffid
            cout << setw(47) << "" << "4. Update a staff" << "\n"; // nhap day du thong tin cua staff, neu khong doi nhap N/A
            //cout << setw(47) << "" << "5. Show all staffs" << "\n";
            cout << setw(47) << "" << "5. Go back" << "\n\n";

            cout << setw(45) << "" << "Your choice: ";
            cin >> choice;
            if(choice != "1" && choice != "2" && choice != "3" && choice != "4" && choice != "5" ) {
                cout << "Invalid choice, please re-enter!\n";
                std::system("pause");
                std::system("cls"); 
            } else break;
        }
        if(choice == "1") {
            string id;
            cin.ignore();
            bool exist = false;
            cout << setw(4) << "" << char(16) << "Enter ID: ";
            getline(cin, id);
            for(int i = 0;i < this->n; ++i) {
                if(id == (this->p + i)->getID()) {
                    exist = true;
                }
            }
            if(!exist) {
                string name, gender, dob, phoneNumber, address;
                cout << setw(4) << "" << char(16) << "Enter name: ";
                getline(cin, name);
                cout << setw(4) << "" << char(16) << "Enter gender: ";
                getline(cin, gender);
                cout << setw(4) << "" << char(16) << "Enter dob: ";
                getline(cin, dob);
                cout << setw(4) << "" << char(16) << "Enter phone number: ";
                getline(cin, phoneNumber);
                cout << setw(4) << "" << char(16) << "Enter address: ";
                getline(cin, address);
                
                this->Add(Staff(name, id, gender, dob, phoneNumber, address, compact(name), compact(dob)));
                cout << "Add successfully!\n";
            } else {
                cout << "Staff exists\n";
            }
        } else if (choice == "2") {
            //this->Show();
            string s;
            cout << "Enter ID: ";
            cin >> s;
            this->Delete(s);
        } else if(choice == "3") {
            //this->Show();
            string s;
            cout << "Enter ID:";
            cin >> s;
            this->Search(s);
        } else if (choice == "4") {
            string s;
            cout << "Enter ID: ";
            cin >> s;
            this->Update(s);
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
        cout << setw(25) << "" << "----LOGIN---- " << "\n\n";
        cout << setw(22) << "" << "Username: ";
        cin >> username;
        cout << "\n";
        if(username == "exit") {
            break;
        }
        cout << setw(22) << "" << "Password: ";
        //cin >> password;
        char x = 'a';
        while (x != '\n'){
            x = getch();
            if (x == 13) break;
            else if (x == 8 && password.size() != 0){
                password.pop_back();
                cout << "\b" << " \b";
            }
            else if (x != 8){
                password += x;
                cout << '*';
            }
        }
        
        cout << "\n";

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
            cout << "Login successfully!\n";
            break;
        } else {
            cout << "Invalid login information!\n";
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