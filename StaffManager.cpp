#include <iostream>
#include "StaffManager.h"
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;
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
            this->p = 0;
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
                (this->p + i)->setName(gender);
            }
            if(dob != "") {
                (this->p + i)->setName(dob);
            }
            if(phoneNumber != "") {
                (this->p + i)->setName(phoneNumber);
            }
            if(address != "") {
                (this->p + i)->setName(address);
            }
            check = true;
            break;
        }
    }
    if(!check) cout << "Staff ID does not exist!\n";
}
void StaffManager::Show()
{
    for (int i = 0; i < this->n; i++)
    {
        cout << i + 1 << ". ";
        (this->p + i)->show(); // Show ni của class SV
    }
}
const int& StaffManager::GetLength() const {
    return this->n;
}
const string& StaffManager::getStaffID(int index) const {
    return (this->p + index)->getID();
}
void StaffManager::LoadData() {
    fstream readfile("Staff.txt", ios::in);
	string tmpline;
	while(getline(readfile,tmpline)) {
		
		string name = "", id = "", gender = "", dob = "", phonenumber = "", address = "";
	
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
		
        this->Add(Staff(name,id, gender, dob, phonenumber, address));
    }
    readfile.close();
}
void StaffManager::Menu() {
    std::system("cls");
    while(true) {
        int choice;
        while(true) {
            
            cout << setw(25) << "" << "STAFFS" << "\n\n\n";
            cout << setw(22) << "" << "1. Add a staff" << "\n"; // nhap day du thong tin cua staff
            cout << setw(22) << "" << "2. Delete a staff" << "\n"; // nhap staffid
            cout << setw(22) << "" << "3. Search a staff" << "\n"; // nhap staffid
            cout << setw(22) << "" << "4. Update a staff" << "\n"; // nhap day du thong tin cua staff, neu khong doi nhap N/A
            cout << setw(22) << "" << "5. Show all staffs" << "\n";
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
            Staff s;
            s.setInfo();
            this->Add(s);
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
const StaffManager& StaffManager::operator=(const StaffManager& v )
{
    if (this != &v) {
        this->n=v.n;
        delete[] this->p;
        this->p = new int[this->n];
        for (int i=0;i<this->n;i++)
            (*this)[i] = *(v.p+i); 
    }
    return *this;
}
