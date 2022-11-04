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
StaffManager::StaffManager() {
    this->p = nullptr;

}
StaffManager::~StaffManager() {
    delete this->p;
}
void StaffManager::Add(Staff*& s) {
    Staff *tmp = this->p;
    while(tmp->getNextStaff() != nullptr) {
        tmp = tmp->getNextStaff();
    }
    tmp->setNextStaff(s);
    delete tmp;
}
void StaffManager::Delete(string id) {
    Staff *tmp = this->p;
    Staff *btmp = this->p;
    while(tmp != nullptr) {
        if(tmp->getID() == id) {
            btmp->setNextStaff(tmp->getNextStaff());
            delete tmp;
            break;
        }
        btmp = tmp;
        tmp = tmp->getNextStaff();
    }
    delete tmp;
    delete btmp;
}
void StaffManager::Search() {
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
        
        
        Staff *tmp = this->p;
        while(tmp != nullptr) {
            if(id == tmp->getID()) {
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
                
                tmp->show();
            }
            tmp = tmp->getNextStaff();
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

        Staff *tmp = this->p;
        
        while(tmp != nullptr) {
            string tmps = "";
            for(int j = 0; j < tmp->getName().length(); ++j){
                tmps += tolower(tmp->getName()[j]);
            }
            if(tmps.find(name) != -1) {

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

                tmp->show(); 
            }
            tmp = tmp->getNextStaff();
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


        Staff *tmp = this->p;

        while(tmp != nullptr) {
            if(gender == tmp->getGender()) {

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

                tmp->show();
            }
            tmp = tmp->getNextStaff();
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

        Staff *tmp = this->p;
        while(tmp != nullptr) {
            if(tmp->getDob().substr(6) == year) {

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

                tmp->show();
            }
            tmp = tmp->getNextStaff();
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


        Staff *tmp = this->p;
        while(tmp != nullptr) {
            if(phoneNumber == tmp->getPhoneNumber()) {

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

                tmp->show();
            }
            tmp = tmp->getNextStaff();
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
    
void StaffManager::Update() {
    while(true) {
        std::cout << setw(50) << "" << topLeftCorner << line(8) << topRightCorner << "\n";
        std::cout << setw(50) << "" << col << " STAFFS " << col << "\n";
        std::cout << setw(50) << "" << botLeftCorner << line(8) << botRightCorner << "\n";
        this->Show();

        string id; 
        std::cout << setw(45) << "" << "(Enter 'exit' to exit)\n\n";
        std::cout << setw(45) << "" << "Enter staff id: ";
        cin >> id;
        if(id == "exit") {
            return;
        }
        bool exist = false;
        Staff *tmp = this->p;
        while(tmp != nullptr) {
            if(tmp->getID() == id) {
                exist = true;
                break;
            }
        
        }


        if(exist) {
            while(true) {
                std::cout << setw(47) << "" << "1. Update name\n";
                std::cout << setw(47) << "" << "2. Update gender\n";
                std::cout << setw(47) << "" << "3. Update day of birth\n";
                std::cout << setw(47) << "" << "4. Update phone number\n";
                std::cout << setw(47) << "" << "5. Update address\n";
                std::cout << setw(47) << "" << "6. Update salary\n";
                std::cout << setw(47) << "" << "7. Go back\n\n";

                string choice;
                std::cout << setw(45) << "" << "Your choice: ";
                cin >> choice;

                label:
                std::system("cls");

                std::cout << setw(47) << "" << "1. Update name\n";
                std::cout << setw(47) << "" << "2. Update gender\n";
                std::cout << setw(47) << "" << "3. Update day of birth\n";
                std::cout << setw(47) << "" << "4. Update phone number\n";
                std::cout << setw(47) << "" << "5. Update address\n";
                std::cout << setw(47) << "" << "6. Update salary\n";
                std::cout << setw(47) << "" << "7. Go back\n\n";
                std::cout << setw(45) << "" << "Your choice: " << choice << "\n";
                


                if(choice == "1") {
                    string name;
                    std::cout << setw(45) << "" << "Enter staff name: ";
                    cin.ignore();
                    getline(cin,name);
                    tmp->setName(name);
                } else if(choice == "2") {
                    string gender;
                
                    try {    
                        std::cout << setw(45) << "" << "Enter staff gender: ";
                        cin >> gender;
                        for(int i = 0; i < gender.length(); ++i) {
                            gender[i] = tolower(gender[i]);
                        }
                        if(gender != "male" || gender != "female") {
                            throw int(1);
                        }
                    }
                    catch(int) {
                        cout << "Invalid gender, gender should be Male or Female!\n";
                        std::system("pause");  
                        goto label;
                    }
                    
                
                    tmp->setGender(gender); 
                
                } else if(choice == "3") {
                    string dob;
                    std::cout << setw(45) << "" << "Enter staff day of birth: ";
                    cin >> dob;
                    bool legal = false;
                    if(dob[0] >= '0' && dob[0] <= '9' && dob[1] >= '0' && dob[1] < '9' && dob[2] == '-' && dob[3] >= '0' && dob[3] <= '9' && dob[4] >= '0' && dob[4] < '9' && dob[5] == '-' && dob[6] >= '0' && dob[6] <= '9' && dob[7] >= '0' && dob[7] <= '9' && dob[8] >= '0' && dob[8] <= '9' && dob[9] >= '0' && dob[9] <= '9') {
                        int day = stoi(dob.substr(0,2)), month = stoi(dob.substr(3,2)), year = stoi(dob.substr(6));
                        if(year >= 1900 || year <= 2022) {
                            if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
                                if(day >= 1 && day < 31) {
                                    legal = true;
                                }
                            } else if( month == 4 || month == 6 || month == 9 || month == 11) {
                                if(day >= 1 && day <= 30) {
                                    legal = true;
                                }
                            } else if(month == 2) {
                                if(year % 400 == 0|| (year % 4 == 0 && year % 100 != 0)) {
                                    if(day >= 1 && day <= 29) {
                                        legal = true;
                                    }
                                } else {
                                    if(day >= 1 && day <= 28) {
                                        legal = true;
                                    }
                                }
                            }
                        }

                    }
                    if(legal) tmp->setDob(dob);
                    else {
                        cout << "Invalid input data, day of birth should be dd-mm-yyyy!\n";
                        std::system("pause");
                        goto label;
                    }

                    tmp->setDob(dob);
                } else if(choice == "4") {
                    string phoneNumber;
                    try {
                        std::cout << setw(45) << "" << "Enter staff phone number: ";
                        cin >> phoneNumber;
                        bool checkLegal = true;
                        for(int i = 0; i < phoneNumber.length(); ++i) {
                            if(phoneNumber[i] < '0' || phoneNumber[i] > '9') {
                                checkLegal = false;
                                break;
                            }
                        }
                        if(!checkLegal || phoneNumber.length() != 10) {
                            throw int(1);
                        }
                    }
                    catch (int) {
                        cout << "Invalid phone number, phone number must have 10 digits!\n";
                        std::system("cls");
                        goto label;
                    }

                    tmp->setPhoneNumber(phoneNumber);
                } else if(choice == "5") {
                    string address;
                    std::cout << setw(45) << "" << "Enter staff address: ";
                    cin >> address;
                    tmp->setAddress(address);
                } else if(choice == "6") {
                    int salary;
                    std::cout << setw(45) << "" << "Enter staff salary: ";
                    cin >> salary;
                    tmp->setSalary(salary);
                } else if(choice == "7") {
                    break;
                }
                std::cout << setw(45) << "" << "Update successfully!\n";
                std::system("pause");
                std::system("cls");
            }
        } else {
            cout << setw(45) << "" << "Staff ID does not exist!\n";
            std::system("pause");
        }
    }
}

void StaffManager::Show() const {
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
	

    Staff *tmp = this->p;
    int i = 0;
	while( tmp != nullptr) {
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
		
        std::cout << col << setw((7 - to_string(i + 1).length())/2) << "" << setw(7 - (7 - to_string(i + 1).length())/2) << left << i + 1; ++i;
		std::cout << col << setw((30 - tmp->getName().length())/2) << "" << setw(30 - (30 - tmp->getName().length())/2) << left << tmp->getName();
		std::cout << col << setw((14 - tmp->getID().length())/2) << "" << setw(14 - (14 - tmp->getID().length())/2) << left << tmp->getID();
		std::cout << col << setw((8 - tmp->getGender().length())/2) << "" << setw(8 - (8 - tmp->getGender().length())/2) << left << tmp->getGender();
		std::cout << col << setw((12 - tmp->getDob().length())/2) << "" << setw(12 - (12 - tmp->getDob().length())/2) << left << tmp->getDob();
		std::cout << col << setw((14 - tmp->getPhoneNumber().length())/2) << "" << setw(14 - (14 - tmp->getPhoneNumber().length())/2) << left << tmp->getPhoneNumber();
		std::cout << col << setw(26 - (26 - tmp->getAddress().length())/2) << right << tmp->getAddress() << setw((26 - tmp->getAddress().length())/2) << "";
		std::cout << col << setw(13 - (13 - to_string(tmp->getSalary()).length())/2) << right << tmp->getSalary() << setw((13 - to_string(tmp->getSalary()).length())/2) << "";
		std::cout << col << setw(11 - (11 - tmp->getUsername().length())/2) << right << tmp->getUsername() << setw((11 - tmp->getUsername().length())/2) << "";
		std::cout << col << setw(10 - (10 - tmp->getPassword().length())/2) << right << tmp->getPassword() << setw((10 - tmp->getPassword().length())/2) << ""; 
		std::cout << col << "\n";

        tmp = tmp->getNextStaff();
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
            std::cout << setw(4) << "" << char(16) << " Enter ID: ";
            std::getline(cin, id);
            
            Staff *tmp = this->p;
            while(tmp != nullptr) {
                if(tmp->getID() == id) {
                    exist = true;
                    break;
                }
            }
            delete tmp;

            if(!exist) {
                string name, gender, dob, phoneNumber, address;
                std::cout << setw(4) << "" << char(16) << "Enter name: ";
                std::getline(cin, name);
                std::cout << setw(4) << "" << char(16) << "Enter gender: ";
                std::getline(cin, gender);
                std::cout << setw(4) << "" << char(16) << "Enter dob: ";
                std::getline(cin, dob);
                std::cout << setw(4) << "" << char(16) << "Enter phone number: ";
                std::getline(cin, phoneNumber);
                std::cout << setw(4) << "" << char(16) << "Enter address: ";
                std::getline(cin, address);

                Staff *staff = new Staff{name, id, gender, dob, phoneNumber, address, compact(name), compact(dob)};
                this->Add(staff);
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
            this->Update();
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


const string& StaffManager::getStaffName(int index) const {
    Staff* tmp = this->p;
    while(index--) {
        tmp = tmp->getNextStaff();
    }
    return tmp->getName();
}
const string& StaffManager::getStaffID(int index) const {
    Staff* tmp = this->p;
    while(index--) {
        tmp = tmp->getNextStaff();
    }
    return tmp->getID();
}
const string& StaffManager::getStaffGender(int index) const {
    Staff* tmp = this->p;
    while(index--) {
        tmp = tmp->getNextStaff();
    }
    return tmp->getGender();
}
const string& StaffManager::getStaffDob(int index) const {
    Staff* tmp = this->p;
    while(index--) {
        tmp = tmp->getNextStaff();
    }
    return tmp->getDob();
}
const string& StaffManager::getStaffPhoneNumber(int index) const {
    Staff* tmp = this->p;
    while(index--) {
        tmp = tmp->getNextStaff();
    }
    return tmp->getPhoneNumber();
}
const string& StaffManager::getStaffAddress(int index) const {
    Staff* tmp = this->p;
    while(index--) {
        tmp = tmp->getNextStaff();
    }
    return tmp->getAddress();
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
            Staff* tmp = this->p;
            while(tmp != nullptr) {
                if(tmp->getUsername() == username && tmp->getPassword() == password) {
                    isStaff = true;
                    break;
                }
                tmp = tmp->getNextStaff();
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
        Staff *s = new Staff{name,id, gender, dob, phonenumber, address,username,password};
        this->Add(s);
    }
    readfile.close();
}
void StaffManager::UpdateFile() {
    fstream editfile("Staff.txt", ios::out);
    Staff* tmp = this->p;
    while(tmp != nullptr) {
    
        string s = tmp->getName() + "/" + tmp->getID() + "/" + tmp->getGender() + "/" + tmp->getDob() + "/" + tmp->getPhoneNumber() + "/" + tmp->getAddress() + "/" + tmp->getUsername() + "/" + tmp->getPassword() + "/";
        if(tmp->getNextStaff() != nullptr)
            editfile << s << "\n";
        else editfile << s;
        tmp = tmp->getNextStaff();
    
    }
    editfile.close();
}
const StaffManager& StaffManager::operator=(const StaffManager& s) {
    if(this != &s) {
        this->p = s.p;
    }
    return *this;
}