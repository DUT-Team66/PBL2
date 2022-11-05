#include <iostream>
#include "StaffManager.h"
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>
//#include "Table.h"
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
    this->pHead = nullptr;
    this->pTail=nullptr;
    this->n=0;
}
StaffManager::~StaffManager()
{
    delete this->pHead;
    delete this->pTail;
}
void StaffManager::Add(const Staff &s)
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
void StaffManager::Delete(string m)
{
    int index=-1;
    if (this->pHead->data.getID()==m)
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
        if (this->pTail->data.getID()==m)
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
                if (k->data.getID()==m)
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
        cout<<"StaffID does not exist!\n";
    }
}
void StaffManager::Search(string s)
{
    int index = -1;
    for (Node *k=this->pHead;k!=NULL;k=k->pNext)
    {
        if (k->data.getID() == s) {
            index = 1;
            k->data.show();
            break;
        }
    }

    if (index==-1) cout << "Staff ID does not exist!\n";
    cout<<endl;
}
// chu y: Update co the cap nhat nhieu cai
void StaffManager::Update(string id) 
{
    bool check = false;
    cin.ignore();
    for (Node *k=this->pHead;k!=NULL;k=k->pNext) {
        if(k->data.getID() == id) {
            string name, gender, dob, phonenumber, address;
            cout << "Enter name: ";
            getline(cin, name);
            cout << "Enter gender: ";
            getline(cin, gender);
            cout << "Enter dob: ";
            getline(cin, dob);
            cout << "Enter phonenumber: ";
            getline(cin, phonenumber);
            cout << "Enter address: ";
            getline(cin, address);
            if(name != "") {
                k->data.setName(name);
            }
            if(gender != "") {
                k->data.setGender(gender);
            }
            if(dob != "") {
                k->data.setDob(dob);
            }
            if(phonenumber != "") {
                k->data.setPhoneNumber(phonenumber);
            }
            if(address != "") {
                k->data.setAddress(address);
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
    int d=1;
    for (Node *k=this->pHead;k!=NULL;k=k->pNext)
    {
        cout << setw(2) << d<< ". ";
        d++;
        k->data.show(); 
    }
}
const int& StaffManager::GetLength() const {
    return this->n;
}
const string& StaffManager::getStaffName(int index) const {
    int pos=0;
    for (Node *k=this->pHead;k!=NULL;k=k->pNext)
    {
        if (pos==index) 
        {
            return k->data.getName();
        }
        pos++;
    }
    return "";
}

const string& StaffManager::getStaffID(int index) const {
    int pos=0;
    for (Node *k=this->pHead;k!=NULL;k=k->pNext)
    {
        if (pos==index) 
        {
            return k->data.getID();
        }
        pos++;
    }
    return "";
}
const string& StaffManager::getStaffGender(int index) const {
    int pos=0;
    for (Node *k=this->pHead;k!=NULL;k=k->pNext)
    {
        if (pos==index) 
        {
            return k->data.getGender();
        }
        pos++;
    }
    return "";
}
const string& StaffManager::getStaffDob(int index) const {
    int pos=0;
    for (Node *k=this->pHead;k!=NULL;k=k->pNext)
    {
        if (pos==index) 
        {
            return k->data.getDob();
        }
        pos++;
    }
    return "";
}
const string& StaffManager::getStaffPhoneNumber(int index) const {
    int pos=0;
    for (Node *k=this->pHead;k!=NULL;k=k->pNext)
    {
        if (pos==index) 
        {
            return k->data.getPhoneNumber();
        }
        pos++;
    }
    return "";
}
const string& StaffManager::getStaffAddress(int index) const {
    int pos=0;
    for (Node *k=this->pHead;k!=NULL;k=k->pNext)
    {
        if (pos==index) 
        {
            return k->data.getAddress();
        }
        pos++;
    }
    return "";
}
void StaffManager::LoadData() {
    fstream readfile("Staff.txt", ios::in);
	string tmpline;
	while(getline(readfile,tmpline)) {
		
		string name = "", id = "", gender = "", dob = "", phonenumber="", address = "", username = "", password = "";
	
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
    int d=0;
    for (Node *k=this->pHead;k!=NULL;k=k->pNext)
    {
        string s = k->data.getName() + "/" + k->data.getID() + "/" + k->data.getGender() + "/" + k->data.getDob() + "/" + k->data.getPhoneNumber() + "/" + k->data.getAddress() + "/" + k->data.getUsername() + "/" + k->data.getPassword() + "/";
        if(d != this->n-1)
            editfile << s << "\n";
        else editfile << s;
        d++;
    }
    editfile.close();


}
void StaffManager::Menu() {
    std::system("cls");
    while(true) {
        int choice;
        while(true) {
            // cout << setw(25) << "" << topLeftCorner << line(8) << topRightCorner << "\n";
	        // cout << setw(25) << "" << col << " STAFFS " << col << "\n";
	        // cout << setw(25) << "" << botLeftCorner << line(8) << botRightCorner << "\n\n";
            cout << setw(25) << "STAFFS" << "\n\n";
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
            s.setUsername(compact(s.getName()));
            s.setPassword(compact(s.getPassword()));
            this->Add(s);
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
void StaffManager::Login(bool& isAdmin, bool& isStaff) {
    
    while(true) {
        string username, password;
        cout << setw(20) << "" << "Enter your account" << "\n\n";
        cout << setw(22) << "" << "Username: ";
        cin >> username;
        cout << "\n";
        cout << setw(22) << "" << "Password: ";
        cin >> password;
        cout << "\n";
        if(username == "exit") {
            break;
        }
        else if(username == "admin" && password == "admin") {
            isAdmin = true;
        } else {
            for (Node *k=this->pHead;k!=NULL;k=k->pNext) {
                if(username == k->data.getUsername() && password == k->data.getPassword()) {
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