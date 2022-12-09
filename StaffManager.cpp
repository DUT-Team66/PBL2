#include <iostream>
#include "StaffManager.h"
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>
#include "Table.h"
#include <conio.h>
#include <windows.h>
using namespace std;

string compact(string s)
{
    string res = "";

    if (s[0] >= 'A' && s[0] <= 'Z')
    {
        stringstream ss(s);
        string tmp;
        while (ss >> tmp)
        {
            res += tolower(tmp[0]);
        }
        tmp = "";
        for (int i = s.length() - 1; s[i] >= 'a' && s[i] <= 'z'; --i)
        {
            tmp = s[i] + tmp;
        }
        res += tmp;
    }
    else
    {
        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] != '-')
            {
                res += s[i];
            }
        }
    }
    return res;
}
StaffManager::StaffManager()
{
   
}
StaffManager::~StaffManager()
{
    
}
void StaffManager::Add(const Staff &s)
{
    this->list.Add(s);
}
void StaffManager::Delete(string s)
{
    this->list.Delete(s);
}
void StaffManager::Search()
{
    while (true)
    {
        string choice;
        while (true)
        {
            std::system("cls");
            std::cout << setw(50) << "" << topLeftCorner << line(8) << topRightCorner << "\n";
            std::cout << setw(50) << "" << col << " STAFFS " << col << "\n";
            std::cout << setw(50) << "" << botLeftCorner << line(8) << botRightCorner << "\n\n";
            std::cout << setw(47) << ""
                      << "1. Search by ID"
                      << "\n";
            std::cout << setw(47) << ""
                      << "2. Search by name"
                      << "\n";
            std::cout << setw(47) << ""
                      << "3. Search by gender"
                      << "\n";
            std::cout << setw(47) << ""
                      << "4. Search by year of birth"
                      << "\n";
            std::cout << setw(47) << ""
                      << "5. Search by phone number"
                      << "\n";
            // std::cout << setw(35) << "" << "6. Search by address" << "\n";
            // std::cout << setw(35) << "" << "7. Search by salary" << "\n"; // salary from ... to ...
            std::cout << setw(47) << ""
                      << "6. Go back"
                      << "\n\n";
            std::cout << setw(45) << ""
                      << "Your choice: ";
            std::cin >> choice;
            if (choice != "1" && choice != "2" && choice != "3" && choice != "4" && choice != "5" && choice != "6")
            {
                std::cout << setw(45) << ""
                          << "Invalid choice!\n";
                std::system("pause");
            }
            else
                break;
        }

        if (choice == "1")
        { // id
            string id;
            std::cout << setw(45) << ""
                      << "Enter staff ID: ";
            std::cin >> id;
            bool checkLegal = true;
            for (int i = 0; i < id.length(); ++i)
            {
                if (id[i] < '0' || id[i] > '9')
                {
                    checkLegal = false;
                    break;
                }
            }
            if (!checkLegal)
            {
                std::cout << setw(45) << ""
                          << "Staff ID must have 12 digits!\n";
                std::system("pause");
                continue;
            }
            bool checkexist = false;
            for (Node<Staff> *tmp = this->list.HeadNode(); tmp != nullptr; tmp = tmp->NextNode())
            {
                if (tmp->Data().getID() == id)
                {
                    checkexist = true;
                    break;
                }
            }
            if (checkexist)
            {
                std::cout << topLeftCorner << line(30); // staff name
                std::cout << topMid << line(14);        // staffID
                std::cout << topMid << line(8);         // gender
                std::cout << topMid << line(12);        // dob
                std::cout << topMid << line(14);        // phonenumber
                std::cout << topMid << line(26);        // address
                std::cout << topMid << line(13);        // salary
                std::cout << topMid << line(11);        // username
                std::cout << topMid << line(10);        // password
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

                for (Node<Staff> *tmp = this->list.HeadNode(); tmp != nullptr; tmp = tmp->NextNode())
                {
                    if (id == tmp->Data().getID())
                    {
                        std::cout << leftSide << line(30);
                        std::cout << midMid << line(14);
                        std::cout << midMid << line(8);
                        std::cout << midMid << line(12);
                        std::cout << midMid << line(14);
                        std::cout << midMid << line(26);
                        std::cout << midMid << line(13);
                        std::cout << midMid << line(11);
                        std::cout << midMid << line(10);
                        std::cout << rightSide << "\n";

                        std::cout << col << setw((30 - tmp->Data().getName().length()) / 2) << "" << setw(30 - (30 - tmp->Data().getName().length()) / 2) << left << tmp->Data().getName();
                        std::cout << col << setw((14 - tmp->Data().getID().length()) / 2) << "" << setw(14 - (14 - tmp->Data().getID().length()) / 2) << left << tmp->Data().getID();
                        std::cout << col << setw((8 - tmp->Data().getGender().length()) / 2) << "" << setw(8 - (8 - tmp->Data().getGender().length()) / 2) << left << tmp->Data().getGender();
                        std::cout << col << setw((12 - tmp->Data().getDob().length()) / 2) << "" << setw(12 - (12 - tmp->Data().getDob().length()) / 2) << left << tmp->Data().getDob();
                        std::cout << col << setw((14 - tmp->Data().getPhoneNumber().length()) / 2) << "" << setw(14 - (14 - tmp->Data().getPhoneNumber().length()) / 2) << left << tmp->Data().getPhoneNumber();
                        std::cout << col << setw(26 - (26 - tmp->Data().getAddress().length()) / 2) << right << tmp->Data().getAddress() << setw((26 - tmp->Data().getAddress().length()) / 2) << "";
                        std::cout << col << setw(13 - (13 - to_string(tmp->Data().getSalary()).length()) / 2) << right << tmp->Data().getSalary() << setw((13 - to_string(tmp->Data().getSalary()).length()) / 2) << "";
                        std::cout << col << setw(11 - (11 - tmp->Data().getUsername().length()) / 2) << right << tmp->Data().getUsername() << setw((11 - tmp->Data().getUsername().length()) / 2) << "";
                        std::cout << col << setw(10 - (10 - tmp->Data().getPassword().length()) / 2) << right << tmp->Data().getPassword() << setw((10 - tmp->Data().getPassword().length()) / 2) << "";
                        std::cout << col << "\n";
                    }
                }
                std::cout << botLeftCorner << line(30); // staff name
                std::cout << botMid << line(14);        // staffID
                std::cout << botMid << line(8);         // gender
                std::cout << botMid << line(12);        // dob
                std::cout << botMid << line(14);        // phonenumber
                std::cout << botMid << line(26);        // address
                std::cout << botMid << line(13);        // salary
                std::cout << botMid << line(11);        // username
                std::cout << botMid << line(10);        // password
                std::cout << botRightCorner << "\n";
            }
            else
            {
                std::cout << setw(45) << ""
                          << "No staffs found!\n";
                // std::system("pause");
            }
            std::system("pause");
        }
        else if (choice == "2")
        { // name
            string name;
            std::cout << setw(45) << ""
                      << "Enter staff name: ";
            std::cin.ignore();
            std::getline(std::cin, name);
            for (int i = 0; i < name.length(); ++i)
            {
                name[i] = tolower(name[i]);
            }
            bool checkExist = false;
            for (Node<Staff> *tmp = this->list.HeadNode(); tmp != nullptr; tmp = tmp->NextNode())
            {
                string tmps = "";
                for (int j = 0; j < tmp->Data().getName().length(); ++j)
                {
                    tmps += tolower(tmp->Data().getName()[j]);
                }
                if (tmps.find(name) != -1)
                {
                    checkExist = true;
                    tmp = nullptr;
                    break;
                }
            }

            if (checkExist)
            {
                std::cout << topLeftCorner << line(30); // staffname
                std::cout << topMid << line(14);        // staffID
                std::cout << topMid << line(8);         // gender
                std::cout << topMid << line(12);        // dob
                std::cout << topMid << line(14);        // phonenumber
                std::cout << topMid << line(26);        // address
                std::cout << topMid << line(13);        // salary
                std::cout << topMid << line(11);        // username
                std::cout << topMid << line(10);        // password
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

                for (Node<Staff> *tmp = this->list.HeadNode(); tmp != nullptr; tmp = tmp->NextNode())
                {
                    string tmps = "";
                    for (int j = 0; j < tmp->Data().getName().length(); ++j)
                    {
                        tmps += tolower(tmp->Data().getName()[j]);
                    }
                    if (tmps.find(name) != -1)
                    {
                        std::cout << leftSide << line(30);
                        std::cout << midMid << line(14);
                        std::cout << midMid << line(8);
                        std::cout << midMid << line(12);
                        std::cout << midMid << line(14);
                        std::cout << midMid << line(26);
                        std::cout << midMid << line(13);
                        std::cout << midMid << line(11);
                        std::cout << midMid << line(10);
                        std::cout << rightSide << "\n";

                        std::cout << col << setw((30 - tmp->Data().getName().length()) / 2) << "" << setw(30 - (30 - tmp->Data().getName().length()) / 2) << left << tmp->Data().getName();
                        std::cout << col << setw((14 - tmp->Data().getID().length()) / 2) << "" << setw(14 - (14 - tmp->Data().getID().length()) / 2) << left << tmp->Data().getID();
                        std::cout << col << setw((8 - tmp->Data().getGender().length()) / 2) << "" << setw(8 - (8 - tmp->Data().getGender().length()) / 2) << left << tmp->Data().getGender();
                        std::cout << col << setw((12 - tmp->Data().getDob().length()) / 2) << "" << setw(12 - (12 - tmp->Data().getDob().length()) / 2) << left << tmp->Data().getDob();
                        std::cout << col << setw((14 - tmp->Data().getPhoneNumber().length()) / 2) << "" << setw(14 - (14 - tmp->Data().getPhoneNumber().length()) / 2) << left << tmp->Data().getPhoneNumber();
                        std::cout << col << setw(26 - (26 - tmp->Data().getAddress().length()) / 2) << right << tmp->Data().getAddress() << setw((26 - tmp->Data().getAddress().length()) / 2) << "";
                        std::cout << col << setw(13 - (13 - to_string(tmp->Data().getSalary()).length()) / 2) << right << tmp->Data().getSalary() << setw((13 - to_string(tmp->Data().getSalary()).length()) / 2) << "";
                        std::cout << col << setw(11 - (11 - tmp->Data().getUsername().length()) / 2) << right << tmp->Data().getUsername() << setw((11 - tmp->Data().getUsername().length()) / 2) << "";
                        std::cout << col << setw(10 - (10 - tmp->Data().getPassword().length()) / 2) << right << tmp->Data().getPassword() << setw((10 - tmp->Data().getPassword().length()) / 2) << "";
                        std::cout << col << "\n";
                    }
                }
                std::cout << botLeftCorner << line(30); // staff name
                std::cout << botMid << line(14);        // staffID
                std::cout << botMid << line(8);         // gender
                std::cout << botMid << line(12);        // dob
                std::cout << botMid << line(14);        // phonenumber
                std::cout << botMid << line(26);        // address
                std::cout << botMid << line(13);        // salary
                std::cout << botMid << line(11);        // username
                std::cout << botMid << line(10);        // password
                std::cout << botRightCorner << "\n";
            }
            else
            {
                std::cout << setw(45) << ""
                          << "No staffs found!\n";
                // std::system("pause");
                // continue;
            }
            std::system("pause");
        }
        else if (choice == "3")
        { // gender
            string gender;
            std::cout << setw(45) << ""
                      << "Enter gender: ";
            std::cin >> gender;
            for (int i = 0; i < gender.length(); ++i)
            {
                gender[i] = tolower(gender[i]);
            }
            if (gender == "male" || gender == "female")
            {
                gender[0] = toupper(gender[0]);
                bool checkExist = false;
                for (Node<Staff> *tmp = this->list.HeadNode(); tmp != nullptr; tmp = tmp->NextNode())
                {
                    if (gender == tmp->Data().getGender())
                    {
                        checkExist = true;
                        break;
                    }
                }
                if (checkExist)
                {
                    std::cout << topLeftCorner << line(30); // staffname
                    std::cout << topMid << line(14);        // staffID
                    std::cout << topMid << line(8);         // gender
                    std::cout << topMid << line(12);        // dob
                    std::cout << topMid << line(14);        // phonenumber
                    std::cout << topMid << line(26);        // address
                    std::cout << topMid << line(13);        // salary
                    std::cout << topMid << line(11);        // username
                    std::cout << topMid << line(10);        // password
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

                    for (Node<Staff> *tmp = this->list.HeadNode(); tmp != nullptr; tmp = tmp->NextNode())
                    {
                        if (gender == tmp->Data().getGender())
                        {
                            std::cout << leftSide << line(30);
                            std::cout << midMid << line(14);
                            std::cout << midMid << line(8);
                            std::cout << midMid << line(12);
                            std::cout << midMid << line(14);
                            std::cout << midMid << line(26);
                            std::cout << midMid << line(13);
                            std::cout << midMid << line(11);
                            std::cout << midMid << line(10);
                            std::cout << rightSide << "\n";

                            std::cout << col << setw((30 - tmp->Data().getName().length()) / 2) << "" << setw(30 - (30 - tmp->Data().getName().length()) / 2) << left << tmp->Data().getName();
                            std::cout << col << setw((14 - tmp->Data().getID().length()) / 2) << "" << setw(14 - (14 - tmp->Data().getID().length()) / 2) << left << tmp->Data().getID();
                            std::cout << col << setw((8 - tmp->Data().getGender().length()) / 2) << "" << setw(8 - (8 - tmp->Data().getGender().length()) / 2) << left << tmp->Data().getGender();
                            std::cout << col << setw((12 - tmp->Data().getDob().length()) / 2) << "" << setw(12 - (12 - tmp->Data().getDob().length()) / 2) << left << tmp->Data().getDob();
                            std::cout << col << setw((14 - tmp->Data().getPhoneNumber().length()) / 2) << "" << setw(14 - (14 - tmp->Data().getPhoneNumber().length()) / 2) << left << tmp->Data().getPhoneNumber();
                            std::cout << col << setw(26 - (26 - tmp->Data().getAddress().length()) / 2) << right << tmp->Data().getAddress() << setw((26 - tmp->Data().getAddress().length()) / 2) << "";
                            std::cout << col << setw(13 - (13 - to_string(tmp->Data().getSalary()).length()) / 2) << right << tmp->Data().getSalary() << setw((13 - to_string(tmp->Data().getSalary()).length()) / 2) << "";
                            std::cout << col << setw(11 - (11 - tmp->Data().getUsername().length()) / 2) << right << tmp->Data().getUsername() << setw((11 - tmp->Data().getUsername().length()) / 2) << "";
                            std::cout << col << setw(10 - (10 - tmp->Data().getPassword().length()) / 2) << right << tmp->Data().getPassword() << setw((10 - tmp->Data().getPassword().length()) / 2) << "";
                            std::cout << col << "\n";
                        }
                    }

                    std::cout << botLeftCorner << line(30); // staff name
                    std::cout << botMid << line(14);        // staffID
                    std::cout << botMid << line(8);         // gender
                    std::cout << botMid << line(12);        // dob
                    std::cout << botMid << line(14);        // phonenumber
                    std::cout << botMid << line(26);        // address
                    std::cout << botMid << line(13);        // salary
                    std::cout << botMid << line(11);        // username
                    std::cout << botMid << line(10);        // password
                    std::cout << botRightCorner << "\n";
                }
                else
                {
                    std::cout << setw(45) << ""
                              << "No staffs found!\n";
                    // std::system("pause");
                }
            }
            else
            {
                std::cout << setw(45) << ""
                          << "Gender must be 'male' or 'female'!\n";
                // std::system("pause");
            }
            std::system("pause");
        }
        else if (choice == "4")
        { // year of birth
            string year;
            std::cout << setw(45) << ""
                      << "Enter year of birth: ";
            std::cin >> year;
            bool checkLegal = true;
            for (int i = 0; i < year.length(); ++i)
            {
                if (year[i] < '0' || year[i] > '9')
                {
                    checkLegal = false;
                }
            }
            if (checkLegal)
            {
                if (stoi(year) < 0 || stoi(year) > 2022)
                {
                    checkLegal = false;
                }
            }
            bool checkExist = false;
            if (checkLegal)
            {
                for (Node<Staff> *tmp = this->list.HeadNode(); tmp != nullptr; tmp = tmp->NextNode())
                {
                    if (year == tmp->Data().getDob().substr(6))
                    {
                        checkExist = true;
                        break;
                    }
                }
            }
            else
            {
                std::cout << setw(45) << ""
                          << "Year of birth must be between 0 and 2022!\n";
                std::system("pause");
                continue;
            }
            if (checkExist)
            {
                std::cout << topLeftCorner << line(30); // staffname
                std::cout << topMid << line(14);        // staffID
                std::cout << topMid << line(8);         // gender
                std::cout << topMid << line(12);        // dob
                std::cout << topMid << line(14);        // phonenumber
                std::cout << topMid << line(26);        // address
                std::cout << topMid << line(13);        // salary
                std::cout << topMid << line(11);        // username
                std::cout << topMid << line(10);        // password
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

                for (Node<Staff> *tmp = this->list.HeadNode(); tmp != nullptr; tmp = tmp->NextNode())
                {
                    if (year == tmp->Data().getDob().substr(6))
                    {

                        std::cout << leftSide << line(30);
                        std::cout << midMid << line(14);
                        std::cout << midMid << line(8);
                        std::cout << midMid << line(12);
                        std::cout << midMid << line(14);
                        std::cout << midMid << line(26);
                        std::cout << midMid << line(13);
                        std::cout << midMid << line(11);
                        std::cout << midMid << line(10);
                        std::cout << rightSide << "\n";

                        std::cout << col << setw((30 - tmp->Data().getName().length()) / 2) << "" << setw(30 - (30 - tmp->Data().getName().length()) / 2) << left << tmp->Data().getName();
                        std::cout << col << setw((14 - tmp->Data().getID().length()) / 2) << "" << setw(14 - (14 - tmp->Data().getID().length()) / 2) << left << tmp->Data().getID();
                        std::cout << col << setw((8 - tmp->Data().getGender().length()) / 2) << "" << setw(8 - (8 - tmp->Data().getGender().length()) / 2) << left << tmp->Data().getGender();
                        std::cout << col << setw((12 - tmp->Data().getDob().length()) / 2) << "" << setw(12 - (12 - tmp->Data().getDob().length()) / 2) << left << tmp->Data().getDob();
                        std::cout << col << setw((14 - tmp->Data().getPhoneNumber().length()) / 2) << "" << setw(14 - (14 - tmp->Data().getPhoneNumber().length()) / 2) << left << tmp->Data().getPhoneNumber();
                        std::cout << col << setw(26 - (26 - tmp->Data().getAddress().length()) / 2) << right << tmp->Data().getAddress() << setw((26 - tmp->Data().getAddress().length()) / 2) << "";
                        std::cout << col << setw(13 - (13 - to_string(tmp->Data().getSalary()).length()) / 2) << right << tmp->Data().getSalary() << setw((13 - to_string(tmp->Data().getSalary()).length()) / 2) << "";
                        std::cout << col << setw(11 - (11 - tmp->Data().getUsername().length()) / 2) << right << tmp->Data().getUsername() << setw((11 - tmp->Data().getUsername().length()) / 2) << "";
                        std::cout << col << setw(10 - (10 - tmp->Data().getPassword().length()) / 2) << right << tmp->Data().getPassword() << setw((10 - tmp->Data().getPassword().length()) / 2) << "";
                        std::cout << col << "\n";
                    }
                }
                std::cout << botLeftCorner << line(30); // staff name
                std::cout << botMid << line(14);        // staffID
                std::cout << botMid << line(8);         // gender
                std::cout << botMid << line(12);        // dob
                std::cout << botMid << line(14);        // phonenumber
                std::cout << botMid << line(26);        // address
                std::cout << botMid << line(13);        // salary
                std::cout << botMid << line(11);        // username
                std::cout << botMid << line(10);        // password
                std::cout << botRightCorner << "\n";
            }
            else
            {
                std::cout << setw(45) << ""
                          << "No staffs found!\n";
                // std::system("pause");
                // continue;
            }
            std::system("pause");
        }
        else if (choice == "5")
        { // phone number
            string phoneNumber;
            std::cout << setw(45) << ""
                      << "Enter phone number: ";
            std::cin >> phoneNumber;
            bool checkLegal = true;
            if (phoneNumber.length() != 10)
            {
                checkLegal = false;
            }
            for (int i = 0; i < phoneNumber.length(); ++i)
            {
                if (phoneNumber[i] < '0' || phoneNumber[i] > '9')
                {
                    checkLegal = false;
                    break;
                }
            }
            bool checkExist = false;
            if (checkLegal)
            {
                for (Node<Staff> *tmp = this->list.HeadNode(); tmp != nullptr; tmp = tmp->NextNode())
                {
                    if (phoneNumber == tmp->Data().getPhoneNumber())
                    {
                        checkExist = true;
                        break;
                    }
                }
            }
            else
            {
                std::cout << setw(45) << ""
                          << "Phone number must have 10 digits!\n";
                std::system("pause");
                continue;
            }
            if (checkExist)
            {
                std::cout << topLeftCorner << line(30); // staffname
                std::cout << topMid << line(14);        // staffID
                std::cout << topMid << line(8);         // gender
                std::cout << topMid << line(12);        // dob
                std::cout << topMid << line(14);        // phonenumber
                std::cout << topMid << line(26);        // address
                std::cout << topMid << line(13);        // salary
                std::cout << topMid << line(11);        // username
                std::cout << topMid << line(10);        // password
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

                for (Node<Staff> *tmp = this->list.HeadNode(); tmp != nullptr; tmp = tmp->NextNode())
                {
                    if (phoneNumber == tmp->Data().getPhoneNumber())
                    {
                        std::cout << leftSide << line(30);
                        std::cout << midMid << line(14);
                        std::cout << midMid << line(8);
                        std::cout << midMid << line(12);
                        std::cout << midMid << line(14);
                        std::cout << midMid << line(26);
                        std::cout << midMid << line(13);
                        std::cout << midMid << line(11);
                        std::cout << midMid << line(10);
                        std::cout << rightSide << "\n";

                        std::cout << col << setw((30 - tmp->Data().getName().length()) / 2) << "" << setw(30 - (30 - tmp->Data().getName().length()) / 2) << left << tmp->Data().getName();
                        std::cout << col << setw((14 - tmp->Data().getID().length()) / 2) << "" << setw(14 - (14 - tmp->Data().getID().length()) / 2) << left << tmp->Data().getID();
                        std::cout << col << setw((8 - tmp->Data().getGender().length()) / 2) << "" << setw(8 - (8 - tmp->Data().getGender().length()) / 2) << left << tmp->Data().getGender();
                        std::cout << col << setw((12 - tmp->Data().getDob().length()) / 2) << "" << setw(12 - (12 - tmp->Data().getDob().length()) / 2) << left << tmp->Data().getDob();
                        std::cout << col << setw((14 - tmp->Data().getPhoneNumber().length()) / 2) << "" << setw(14 - (14 - tmp->Data().getPhoneNumber().length()) / 2) << left << tmp->Data().getPhoneNumber();
                        std::cout << col << setw(26 - (26 - tmp->Data().getAddress().length()) / 2) << right << tmp->Data().getAddress() << setw((26 - tmp->Data().getAddress().length()) / 2) << "";
                        std::cout << col << setw(13 - (13 - to_string(tmp->Data().getSalary()).length()) / 2) << right << tmp->Data().getSalary() << setw((13 - to_string(tmp->Data().getSalary()).length()) / 2) << "";
                        std::cout << col << setw(11 - (11 - tmp->Data().getUsername().length()) / 2) << right << tmp->Data().getUsername() << setw((11 - tmp->Data().getUsername().length()) / 2) << "";
                        std::cout << col << setw(10 - (10 - tmp->Data().getPassword().length()) / 2) << right << tmp->Data().getPassword() << setw((10 - tmp->Data().getPassword().length()) / 2) << "";
                        std::cout << col << "\n";
                    }
                }
                std::cout << botLeftCorner << line(30); // staff name
                std::cout << botMid << line(14);        // staffID
                std::cout << botMid << line(8);         // gender
                std::cout << botMid << line(12);        // dob
                std::cout << botMid << line(14);        // phonenumber
                std::cout << botMid << line(26);        // address
                std::cout << botMid << line(13);        // salary
                std::cout << botMid << line(11);        // username
                std::cout << botMid << line(10);        // password
                std::cout << botRightCorner << "\n";
            }
            else
            {
                std::cout << setw(45) << ""
                          << "No staffs found!\n";
                // std::system("pause");
            }
            std::system("pause");
        }
        else if (choice == "6")
        { // go back
            return;
        }

        // std::system("pause");
    }
}
void StaffManager::Update() // chu y: Update co the cap nhat nhieu cai
{

    while (true)
    {
        std::system("cls");
        std::cout << setw(50) << "" << topLeftCorner << line(8) << topRightCorner << "\n";
        std::cout << setw(50) << "" << col << " STAFFS " << col << "\n";
        std::cout << setw(50) << "" << botLeftCorner << line(8) << botRightCorner << "\n\n";
        this->Show();

        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, grey);
        std::cout << setw(45) << ""
             << "Enter 'exit' to exit!\n";
        SetConsoleTextAttribute(hConsole, brightwhite);
        string id;
        std::cout << setw(45) << ""
                  << "Enter staff id: ";
        std::cin >> id;

        if (id == "exit")
        {
            return;
        }

        bool checkExist = false;
        Node<Staff> *staff = this->list.HeadNode();
        while (staff != nullptr)
        {
            if (staff->Data().getID() == id)
            {
                checkExist = true;
                break;
            }
            staff = staff->NextNode();
        }

        if (checkExist)
        {
            while (true)
            {
                std::system("cls");
                std::cout << setw(50) << "" << topLeftCorner << line(8) << topRightCorner << "\n";
                std::cout << setw(50) << "" << col << " STAFFS " << col << "\n";
                std::cout << setw(50) << "" << botLeftCorner << line(8) << botRightCorner << "\n";

                staff->Data().show();

                std::cout << setw(47) << ""
                          << "1. Update name\n";
                std::cout << setw(47) << ""
                          << "2. Update gender\n";
                std::cout << setw(47) << ""
                          << "3. Update day of birth\n";
                std::cout << setw(47) << ""
                          << "4. Update phone number\n";
                std::cout << setw(47) << ""
                          << "5. Update address\n";
                std::cout << setw(47) << ""
                          << "6. Update salary\n";
                std::cout << setw(47) << ""
                          << "7. Go back\n\n";

                string choice;
                std::cout << setw(45) << ""
                          << "Your choice: ";
                std::cin >> choice;

                // label:
                // std::system("cls");

                // std::cout << setw(50) << "" << topLeftCorner << line(8) << topRightCorner << "\n";
                // std::cout << setw(50) << "" << col << " STAFFS " << col << "\n";
                // std::cout << setw(50) << "" << botLeftCorner << line(8) << botRightCorner << "\n";

                // staff->data.show();

                // std::cout << setw(47) << "" << "1. Update name\n";
                // std::cout << setw(47) << "" << "2. Update gender\n";
                // std::cout << setw(47) << "" << "3. Update day of birth\n";
                // std::cout << setw(47) << "" << "4. Update phone number\n";
                // std::cout << setw(47) << "" << "5. Update address\n";
                // std::cout << setw(47) << "" << "6. Update salary\n";
                // std::cout << setw(47) << "" << "7. Go back\n\n";
                // std::cout << setw(45) << "" << "Your choice: " << choice << "\n";

                if (choice == "1") { // update name
                    string name;
                    std::cout << setw(45) << ""
                              << "Enter staff name: ";
                    std::cin.ignore();
                    std::getline(std::cin, name);
                    staff->Data().setName(name);
                    std::cout << setw(45) << ""
                              << "Update successfully!\n";
                    std::system("pause");
                }
                else if (choice == "2") { // update gender
                    string gender;

                    std::cout << setw(45) << ""
                              << "Enter staff gender: ";
                    std::cin >> gender;
                    for (int i = 0; i < gender.length(); ++i)
                    {
                        gender[i] = tolower(gender[i]);
                    }
                    if (gender != "male" && gender != "female")
                    {
                        std::cout << "Invalid gender, gender must be 'Male' or 'Female'!\n";
                        // goto label;
                    }
                    else
                    {
                        staff->Data().setGender(gender);
                        std::cout << setw(45) << ""
                                  << "Update successfully!\n";
                    }

                    std::system("pause");
                }
                else if (choice == "3") { // update dob
                    string dob;
                    std::cout << setw(45) << ""
                              << "Enter staff day of birth(dd-mm-yyyy): ";
                    std::cin >> dob;
                    bool checkLegal = false;
                    if (dob[0] >= '0' && dob[0] <= '9' && dob[1] >= '0' && dob[1] <= '9' && dob[2] == '-' && dob[3] >= '0' && dob[3] <= '9' && dob[4] >= '0' && dob[4] <= '9' && dob[5] == '-' && dob[6] >= '0' && dob[6] <= '9' && dob[7] >= '0' && dob[7] <= '9' && dob[8] >= '0' && dob[8] <= '9' && dob[9] >= '0' && dob[9] <= '9')
                    {
                        int day = stoi(dob.substr(0, 2)), month = stoi(dob.substr(3, 2)), year = stoi(dob.substr(6));
                        if (year >= 1900 || year <= 2022)
                        {
                            if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
                            {
                                if (day >= 1 && day <= 31)
                                {
                                    checkLegal = true;
                                }
                            }
                            else if (month == 4 || month == 6 || month == 9 || month == 11)
                            {
                                if (day >= 1 && day <= 30)
                                {
                                    checkLegal = true;
                                }
                            }
                            else if (month == 2)
                            {
                                if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
                                {
                                    if (day >= 1 && day <= 29)
                                    {
                                        checkLegal = true;
                                    }
                                }
                                else
                                {
                                    if (day >= 1 && day <= 28)
                                    {
                                        checkLegal = true;
                                    }
                                }
                            }
                        }
                    }
                    if (checkLegal)
                    {
                        staff->Data().setDob(dob);
                        staff->Data().setPassword(compact(dob));
                        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                        SetConsoleTextAttribute(hConsole, brightgreen);
                        std::cout << setw(45) << "" << "Update successfully!\n";
                        SetConsoleTextAttribute(hConsole, brightwhite);  
                    }
                    else
                    {
                        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                        SetConsoleTextAttribute(hConsole, brightred);
                        std::cout << setw(45) << "" << "Invalid input data, please re-enter!\n";
                        SetConsoleTextAttribute(hConsole, brightwhite); 
                        // goto label;
                    }
                    std::system("pause");
                }
                else if (choice == "4")
                { // update phone number
                    string phoneNumber;

                    std::cout << setw(45) << ""
                              << "Enter staff phone number: ";
                    std::cin >> phoneNumber;
                    bool checkLegal = true;
                    for (int i = 0; i < phoneNumber.length(); ++i)
                    {
                        if (phoneNumber[i] < '0' || phoneNumber[i] > '9')
                        {
                            checkLegal = false;
                            break;
                        }
                    }
                    if (!checkLegal || phoneNumber.length() != 10)
                    {
                        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                        SetConsoleTextAttribute(hConsole, brightred);
                        std::cout << setw(45) << "" << "Invalid phone number, phone number must have 10 digits!\n";
                        SetConsoleTextAttribute(hConsole, brightwhite); 
                        // goto label;
                    }
                    else
                    {
                        staff->Data().setPhoneNumber(phoneNumber);
                         HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                        SetConsoleTextAttribute(hConsole, brightgreen);
                        std::cout << setw(45) << "" << "Update successfully!\n";
                        SetConsoleTextAttribute(hConsole, brightwhite); 
                    }
                    std::system("pause");
                }
                else if (choice == "5")
                { // update address
                    string address;
                    std::cout << setw(45) << ""
                              << "Enter staff address: ";
                    std::cin.ignore();
                    std::getline(std::cin, address);

                    stringstream ss(address);
                    string num;
                    ss >> num;
                    bool check = false;
                    for (int i = 0; i < num.length(); ++i)
                    {
                        if (num[i] >= '0' && num[i] <= '9')
                        {
                            check = true;
                        }
                    }
                    string str;
                    ss >> str;
                    bool check1 = false;
                    for (int i = 0; i < str.length(); ++i)
                    {
                        if ((str[i] >= 'a' && str[i] <= 'z') || str[i] >= 'A' && str[i] <= 'Z')
                        {
                            check1 = true;
                        }
                    }
                    if (!check1 || !check)
                    {
                         HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                        SetConsoleTextAttribute(hConsole, brightred);
                        std::cout << setw(45) << "" << "Invalid address!" << endl;
                        SetConsoleTextAttribute(hConsole, brightwhite); 
                        // goto label;
                    }
                    else
                    {
                        staff->Data().setAddress(address);
                         HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                        SetConsoleTextAttribute(hConsole, brightgreen);
                        std::cout << setw(45) << "" << "Update successfully!\n";
                        SetConsoleTextAttribute(hConsole, brightwhite); 
                    }
                    std::system("pause");
                }
                else if (choice == "6")
                { // update salary
                    string salary;
                    std::cout << setw(45) << ""
                              << "Enter staff salary: ";
                    std::cin >> salary;
                    bool checkLegal = true;
                    for (int i = 0; i < salary.length(); ++i)
                    {
                        if (salary[i] < '0' || salary[i] > '9')
                        {
                            checkLegal = false;
                            break;
                        }
                    }

                    if (checkLegal)
                    {
                        staff->Data().setSalary(stoi(salary));
                         HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                        SetConsoleTextAttribute(hConsole, brightgreen);
                        std::cout << setw(45) << "" << "Update successfully!\n";
                        SetConsoleTextAttribute(hConsole, brightwhite); 
                    }
                    else
                    {
                         HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                        SetConsoleTextAttribute(hConsole, brightred);
                        std::cout << setw(45) << "" << "Salary must only contain digits!\n";
                        SetConsoleTextAttribute(hConsole, brightwhite); 
                        // goto label;
                    }
                    std::system("pause");
                }
                else if (choice == "7")
                { // go back
                    break;
                }
                else
                {
                     HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleTextAttribute(hConsole, brightred);
                    std::cout << setw(45) << "" << "Invalid choice, please re-enter!\n";
                    SetConsoleTextAttribute(hConsole, brightwhite); 
                    std::cin.ignore(32767, '\n');
                    std::system("pause");
                }
            }
        }
        else
        {
             HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hConsole, brightred);
            std::cout << setw(45) << "" << "Staff ID does not exist!\n";
            SetConsoleTextAttribute(hConsole, brightwhite); 
            std::system("pause");
        }
    }
}
void StaffManager::Show() 
{

    std::cout << topLeftCorner << line(7); // order
    std::cout << topMid << line(30);       // staff name
    std::cout << topMid << line(14);       // staffID
    std::cout << topMid << line(8);        // gender
    std::cout << topMid << line(12);       // dob
    std::cout << topMid << line(14);       // phonenumber
    std::cout << topMid << line(26);       // address
    std::cout << topMid << line(13);       // salary
    std::cout << topMid << line(11);       // username
    std::cout << topMid << line(10);       // password
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

    int i = 1;
    for (Node<Staff> *tmp = this->list.HeadNode(); tmp != nullptr; tmp = tmp->NextNode())
    {
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

        std::cout << col << setw((7 - to_string(i).length()) / 2) << "" << setw(7 - (7 - to_string(i).length()) / 2) << left << i;
        ++i;
        std::cout << col << setw((30 - tmp->Data().getName().length()) / 2) << "" << setw(30 - (30 - tmp->Data().getName().length()) / 2) << left << tmp->Data().getName();
        std::cout << col << setw((14 - tmp->Data().getID().length()) / 2) << "" << setw(14 - (14 - tmp->Data().getID().length()) / 2) << left << tmp->Data().getID();
        std::cout << col << setw((8 - tmp->Data().getGender().length()) / 2) << "" << setw(8 - (8 - tmp->Data().getGender().length()) / 2) << left << tmp->Data().getGender();
        std::cout << col << setw((12 - tmp->Data().getDob().length()) / 2) << "" << setw(12 - (12 - tmp->Data().getDob().length()) / 2) << left << tmp->Data().getDob();
        std::cout << col << setw((14 - tmp->Data().getPhoneNumber().length()) / 2) << "" << setw(14 - (14 - tmp->Data().getPhoneNumber().length()) / 2) << left << tmp->Data().getPhoneNumber();
        std::cout << col << setw(26 - (26 - tmp->Data().getAddress().length()) / 2) << right << tmp->Data().getAddress() << setw((26 - tmp->Data().getAddress().length()) / 2) << "";
        std::cout << col << setw(13 - (13 - to_string(tmp->Data().getSalary()).length()) / 2) << right << tmp->Data().getSalary() << setw((13 - to_string(tmp->Data().getSalary()).length()) / 2) << "";
        std::cout << col << setw(11 - (11 - tmp->Data().getUsername().length()) / 2) << right << tmp->Data().getUsername() << setw((11 - tmp->Data().getUsername().length()) / 2) << "";
        std::cout << col << setw(10 - (10 - tmp->Data().getPassword().length()) / 2) << right << tmp->Data().getPassword() << setw((10 - tmp->Data().getPassword().length()) / 2) << "";
        std::cout << col << "\n";
    }
    std::cout << botLeftCorner << line(7); // order
    std::cout << botMid << line(30);       // staff name
    std::cout << botMid << line(14);       // staffID
    std::cout << botMid << line(8);        // gender
    std::cout << botMid << line(12);       // dob
    std::cout << botMid << line(14);       // phonenumber
    std::cout << botMid << line(26);       // address
    std::cout << botMid << line(13);       // salary
    std::cout << botMid << line(11);       // username
    std::cout << botMid << line(10);       // password
    std::cout << botRightCorner << "\n";
}
int StaffManager::GetLength() const
{
    return this->list.size();   
}
const string &StaffManager::getStaffName(int index)
{
    static string s;
    if (index < 0 || index > this->list.size())
    {
        return s;
    }
    Node<Staff> *staff = this->list.HeadNode();
    while (index--)
    {
        staff = staff->NextNode();
    }
    return staff->Data().getName();
}
const string &StaffManager::getStaffID(int index)
{
    static string s;
    if (index < 0 || index > this->list.size())
    {
        return s;
    }
    Node<Staff> *staff = this->list.HeadNode();
    while (index--)
    {
        staff = staff->NextNode();
    }
    return staff->Data().getID();
}
const string &StaffManager::getStaffGender(int index)
{
    static string s;
    if (index < 0 || index > this->list.size())
    {
        return s;
    }
    Node<Staff> *staff = this->list.HeadNode();
    while (index--)
    {
        staff = staff->NextNode();
    }
    return staff->Data().getGender();
}
const string &StaffManager::getStaffDob(int index)
{
    static string s;
    if (index < 0 || index > this->list.size());
    {
        return s;
    }
    Node<Staff> *staff = this->list.HeadNode();
    while (index--)
    {
        staff = staff->NextNode();
    }
    return staff->Data().getDob();
}
const string &StaffManager::getStaffPhoneNumber(int index)
{
    static string s;
    if (index < 0 || index > this->list.size())
    {
        return s;
    }
    Node<Staff> *staff = this->list.HeadNode();
    while (index--)
    {
        staff = staff->NextNode();
    }
    return staff->Data().getPhoneNumber();
}
const string &StaffManager::getStaffAddress(int index)
{
    static string s;
    if (index < 0 || index > this->list.size())
    {
        return s;
    }
    Node<Staff> *staff = this->list.HeadNode();
    while (index--)
    {
        staff = staff->NextNode();
    }
    return staff->Data().getAddress();
}
void StaffManager::LoadData()
{
    fstream readfile("Staff.txt", ios::in);
    string tmpline;
    while (getline(readfile, tmpline))
    {

        string name = "", id = "", gender = "", dob = "", phonenumber = "", address = "", username = "", password = "";

        int i = 0;
        while (tmpline[i] != '/')
        {
            name += tmpline[i];
            ++i;
        }
        ++i;
        while (tmpline[i] != '/')
        {
            id += tmpline[i];
            ++i;
        }
        ++i;
        while (tmpline[i] != '/')
        {
            gender += tmpline[i];
            ++i;
        }
        ++i;
        while (tmpline[i] != '/')
        {
            dob += tmpline[i];
            ++i;
        }
        ++i;
        while (tmpline[i] != '/')
        {
            phonenumber += tmpline[i];
            ++i;
        }
        ++i;
        while (tmpline[i] != '/')
        {
            address += tmpline[i];
            ++i;
        }
        ++i;
        while (tmpline[i] != '/')
        {
            username += tmpline[i];
            ++i;
        }
        ++i;
        while (tmpline[i] != '/')
        {
            password += tmpline[i];
            ++i;
        }
        ++i;
        this->Add(Staff(name, id, gender, dob, phonenumber, address, username, password));
    }
    readfile.close();
}
void StaffManager::UpdateFile()
{
    fstream editfile("Staff.txt", ios::out);
    int d = 0;
    for (Node<Staff> *tmp = this->list.HeadNode(); tmp != nullptr; tmp = tmp->NextNode())
    {
        string s = tmp->Data().getName() + "/" + tmp->Data().getID() + "/" + tmp->Data().getGender() + "/" + tmp->Data().getDob() + "/" + tmp->Data().getPhoneNumber() + "/" + tmp->Data().getAddress() + "/" + tmp->Data().getUsername() + "/" + tmp->Data().getPassword() + "/";
        if (d != this->list.size() - 1)
            editfile << s << "\n";
        else
            editfile << s;
        d++;
    }
    editfile.close();
}
void StaffManager::Menu()
{
    std::system("cls");
    while (true)
    {
        string choice;
        while (true)
        {
            std::system("cls");
            std::cout << setw(50) << "" << topLeftCorner << line(8) << topRightCorner << "\n";
            std::cout << setw(50) << "" << col << " STAFFS " << col << "\n";
            std::cout << setw(50) << "" << botLeftCorner << line(8) << botRightCorner << "\n\n";

            cout << setw(47) << ""
                 << "1. Add a staff"
                 << "\n"; // nhap day du thong tin cua staff
            cout << setw(47) << ""
                 << "2. Delete a staff"
                 << "\n"; // nhap staffid
            cout << setw(47) << ""
                 << "3. Search a staff"
                 << "\n"; // nhap staffid
            cout << setw(47) << ""
                 << "4. Update a staff"
                 << "\n"; // nhap day du thong tin cua staff, neu khong doi nhap N/A
            cout << setw(47) << ""
                 << "5. Show all staffs"
                 << "\n";
            cout << setw(47) << ""
                 << "6. Go back"
                 << "\n\n";

            cout << setw(45) << ""
                 << "Your choice: ";
            cin >> choice;
            if (choice != "1" && choice != "2" && choice != "3" && choice != "4" && choice != "5" && choice != "6")
            {
                cout << setw(45) << ""
                     << "Invalid choice, please re-enter!\n";
                std::system("pause");
                std::system("cls");
            }
            else
                break;
        }
        if (choice == "1")
        {
            if (this->list.size() == 10)
            {
                HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(hConsole, brightred);
                std::cout << setw(45) << ""
                          << "Full of staffs!\n";
                SetConsoleTextAttribute(hConsole, brightwhite);
                std::system("pause");
                continue;
            }

            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hConsole, grey);
            cout << setw(45) << ""
                 << "Enter 'exit' to exit!\n";
            SetConsoleTextAttribute(hConsole, brightwhite);
            string id;
            cout << setw(45) << ""
                 << "Enter ID: ";
            cin >> id;
            if (id == "exit")
            {
                continue;
            }
            bool checkLegal = true;
            for (int i = 0; i < id.length(); ++i)
            {
                if (id[i] < '0' || id[i] > '9')
                {
                    checkLegal = true;
                    break;
                }
            }
            if (!checkLegal || id.length() != 12)
            {
                HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(hConsole, brightred);
                cout << setw(45) << ""
                     << "Invalid id!"
                     << "\n";
                SetConsoleTextAttribute(hConsole, brightwhite);
                system("pause");
                continue;
            }
            Node<Staff> *tmp = this->list.HeadNode();
            bool checkExist = false;
            while (tmp != nullptr)
            {
                if (tmp->Data().getID() == id)
                {
                    checkExist = true;
                    break;
                }
                tmp = tmp->NextNode();
            }
            if (!checkExist)
            {
                string name, gender, dob, phoneNumber, address;
                cin.ignore();

                cout << setw(45) << ""
                     << "Enter name: ";
                getline(cin, name);

                while (true)
                {
                    std::system("cls");
                    std::cout << setw(50) << "" << topLeftCorner << line(8) << topRightCorner << "\n";
                    std::cout << setw(50) << "" << col << " STAFFS " << col << "\n";
                    std::cout << setw(50) << "" << botLeftCorner << line(8) << botRightCorner << "\n\n";

                    cout << setw(47) << ""
                         << "1. Add a staff"
                         << "\n"; // nhap day du thong tin cua staff
                    cout << setw(47) << ""
                         << "2. Delete a staff"
                         << "\n"; // nhap staffid
                    cout << setw(47) << ""
                         << "3. Search a staff"
                         << "\n"; // nhap staffid
                    cout << setw(47) << ""
                         << "4. Update a staff"
                         << "\n"; // nhap day du thong tin cua staff, neu khong doi nhap N/A
                    cout << setw(47) << ""
                         << "5. Show all staffs"
                         << "\n";
                    cout << setw(47) << ""
                         << "6. Go back"
                         << "\n\n";

                    cout << setw(45) << ""
                         << "Your choice: " << 1 << "\n";
                    cout << setw(45) << ""
                         << "Enter ID: " << id << "\n";
                    cout << setw(45) << ""
                         << "Enter name: " << name << "\n";
                    cout << setw(45) << ""
                         << "Enter gender: ";
                    cin >> gender;
                    for (int i = 0; i < gender.length(); ++i)
                    {
                        gender[i] = tolower(gender[i]);
                    }
                    if (gender != "male" && gender != "female")
                    {
                        cout << setw(45) << ""
                             << "Invalid gender, gender must be 'Male' or 'Female'"
                             << "\n";
                        std::system("pause");
                    }
                    else
                        break;
                }
                gender[0] = toupper(gender[0]);

                while (true)
                {
                    std::system("cls");
                    std::cout << setw(50) << "" << topLeftCorner << line(8) << topRightCorner << "\n";
                    std::cout << setw(50) << "" << col << " STAFFS " << col << "\n";
                    std::cout << setw(50) << "" << botLeftCorner << line(8) << botRightCorner << "\n\n";

                    cout << setw(47) << ""
                         << "1. Add a staff"
                         << "\n"; // nhap day du thong tin cua staff
                    cout << setw(47) << ""
                         << "2. Delete a staff"
                         << "\n"; // nhap staffid
                    cout << setw(47) << ""
                         << "3. Search a staff"
                         << "\n"; // nhap staffid
                    cout << setw(47) << ""
                         << "4. Update a staff"
                         << "\n"; // nhap day du thong tin cua staff, neu khong doi nhap N/A
                    cout << setw(47) << ""
                         << "5. Show all staffs"
                         << "\n";
                    cout << setw(47) << ""
                         << "6. Go back"
                         << "\n\n";

                    cout << setw(45) << ""
                         << "Your choice: " << 1 << "\n";
                    cout << setw(45) << ""
                         << "Enter ID: " << id << "\n";
                    cout << setw(45) << ""
                         << "Enter name: " << name << "\n";
                    cout << setw(45) << ""
                         << "Enter gender: " << gender << "\n";
                    cout << setw(45) << ""
                         << "Enter day of birth(dd-mm-yyyy): ";
                    cin >> dob;
                    bool checkLegal = false;
                    if (dob.length() == 10)
                    {
                        if (dob[0] >= '0' && dob[0] <= '9' && dob[1] >= '0' && dob[1] <= '9' && dob[2] == '-' && dob[3] >= '0' && dob[3] <= '9' && dob[4] >= '0' && dob[4] <= '9' && dob[5] == '-' && dob[6] >= '0' && dob[6] <= '9' && dob[7] >= '0' && dob[7] <= '9' && dob[8] >= '0' && dob[8] <= '9' && dob[9] >= '0' && dob[9] <= '9')
                        {
                            int day = stoi(dob.substr(0, 2)), month = stoi(dob.substr(3, 2)), year = stoi(dob.substr(6));
                            if (year >= 1900 && year <= 2022)
                            {
                                if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
                                {
                                    if (day >= 1 && day <= 31)
                                    {
                                        checkLegal = true;
                                    }
                                }
                                else if (month == 4 || month == 6 || month == 9 || month == 11)
                                {
                                    if (day >= 1 && day <= 30)
                                    {
                                        checkLegal = true;
                                    }
                                }
                                else if (month == 2)
                                {
                                    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
                                    {
                                        if (day >= 1 && day <= 29)
                                        {
                                            checkLegal = true;
                                        }
                                    }
                                    else
                                    {
                                        if (day >= 1 && day <= 28)
                                        {
                                            checkLegal = true;
                                        }
                                    }
                                }
                            }
                        }
                    }
                    if (!checkLegal)
                    {
                        cout << setw(45) << ""
                             << "Invalid input data, day of birth should be dd-mm-yyyy!\n";
                        std::system("pause");
                    }
                    else
                        break;
                }

                while (true)
                {
                    std::system("cls");
                    std::cout << setw(50) << "" << topLeftCorner << line(8) << topRightCorner << "\n";
                    std::cout << setw(50) << "" << col << " STAFFS " << col << "\n";
                    std::cout << setw(50) << "" << botLeftCorner << line(8) << botRightCorner << "\n\n";

                    cout << setw(47) << ""
                         << "1. Add a staff"
                         << "\n"; // nhap day du thong tin cua staff
                    cout << setw(47) << ""
                         << "2. Delete a staff"
                         << "\n"; // nhap staffid
                    cout << setw(47) << ""
                         << "3. Search a staff"
                         << "\n"; // nhap staffid
                    cout << setw(47) << ""
                         << "4. Update a staff"
                         << "\n"; // nhap day du thong tin cua staff, neu khong doi nhap N/A
                    cout << setw(47) << ""
                         << "5. Show all staffs"
                         << "\n";
                    cout << setw(47) << ""
                         << "6. Go back"
                         << "\n\n";

                    cout << setw(45) << ""
                         << "Your choice: " << 1 << "\n";
                    cout << setw(45) << ""
                         << "Enter ID: " << id << "\n";
                    cout << setw(45) << ""
                         << "Enter name: " << name << "\n";
                    cout << setw(45) << ""
                         << "Enter gender: " << gender << "\n";
                    cout << setw(45) << ""
                         << "Enter day of birth(dd-mm-yyyy): " << dob << "\n";
                    cout << setw(45) << ""
                         << "Enter phone number: ";
                    cin >> phoneNumber;

                    bool checkLegal = true;
                    for (int i = 0; i < phoneNumber.length(); ++i)
                    {
                        if (phoneNumber[i] < '0' || phoneNumber[i] > '9')
                        {
                            checkLegal = false;
                            break;
                        }
                    }
                    if (!checkLegal || phoneNumber.length() != 10)
                    {
                        cout << setw(45) << ""
                             << "Invalid phone number, phone number must contain 10 digits!\n";
                        std::system("pause");
                    }
                    else
                        break;
                }

                while (true)
                {
                    std::system("cls");
                    std::cout << setw(50) << "" << topLeftCorner << line(8) << topRightCorner << "\n";
                    std::cout << setw(50) << "" << col << " STAFFS " << col << "\n";
                    std::cout << setw(50) << "" << botLeftCorner << line(8) << botRightCorner << "\n\n";

                    cout << setw(47) << ""
                         << "1. Add a staff"
                         << "\n"; // nhap day du thong tin cua staff
                    cout << setw(47) << ""
                         << "2. Delete a staff"
                         << "\n"; // nhap staffid
                    cout << setw(47) << ""
                         << "3. Search a staff"
                         << "\n"; // nhap staffid
                    cout << setw(47) << ""
                         << "4. Update a staff"
                         << "\n"; // nhap day du thong tin cua staff, neu khong doi nhap N/A
                    cout << setw(47) << ""
                         << "5. Show all staffs"
                         << "\n";
                    cout << setw(47) << ""
                         << "6. Go back"
                         << "\n\n";

                    cout << setw(45) << ""
                         << "Your choice: " << 1 << "\n";
                    cout << setw(45) << ""
                         << "Enter ID: " << id << "\n";
                    cout << setw(45) << ""
                         << "Enter name: " << name << "\n";
                    cout << setw(45) << ""
                         << "Enter gender: " << gender << "\n";
                    cout << setw(45) << ""
                         << "Enter day of birth(dd-mm-yyyy): " << dob << "\n";
                    cout << setw(45) << ""
                         << "Enter phone number: " << phoneNumber << "\n";
                    cout << setw(45) << ""
                         << "Enter address: ";
                    cin.ignore();
                    getline(cin, address);
                    stringstream ss(address);
                    string num;
                    ss >> num;
                    bool check = false;
                    for (int i = 0; i < num.length(); ++i)
                    {
                        if (num[i] >= '0' && num[i] <= '9')
                        {
                            check = true;
                        }
                    }
                    string str;
                    ss >> str;
                    bool check1 = false;
                    for (int i = 0; i < str.length(); ++i)
                    {
                        if ((str[i] >= 'a' && str[i] <= 'z') || str[i] >= 'A' && str[i] <= 'Z')
                        {
                            check1 = true;
                        }
                    }
                    if (!check1 || !check)
                    {
                        cout << setw(45) << ""
                             << "Invalid address!" << endl;
                        std::system("pause");
                    }
                    else
                        break;
                }

                this->Add(Staff(name, id, gender, dob, phoneNumber, address, compact(name), compact(dob)));
                HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(hConsole, brightgreen);
                std::cout << "\n" << setw(45) << "" << "Add successfully!\n";
                SetConsoleTextAttribute(hConsole, brightwhite); 
            }
            else
            {
                cout << setw(45) << ""
                     << "Staff exists!\n";
                tmp->Data().show();
            }
            std::system("pause");
        }
        else if (choice == "2")
        {
            this->Show();
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hConsole, grey);
            cout << setw(45) << ""
                 << "Enter 'exit' to exit!\n";
            SetConsoleTextAttribute(hConsole, brightwhite);
            string id;
            cout << setw(45) << ""
                 << "Enter ID: ";
            cin >> id;
            if (id == "exit")
            {
                continue;
            }
            bool checkLegal = true;
            for (int i = 0; i < id.length(); ++i)
            {
                if (id[i] < '0' || id[i] > '9')
                {
                    checkLegal = true;
                    break;
                }
            }
            if (!checkLegal || id.length() != 12)
            {
                cout << setw(45) << ""
                     << "Invalid id!"
                     << "\n";
                system("pause");
                continue;
            }
            string confirm;
            cout << setw(45) << ""
                 << "Confirm (Y/N): ";
            cin >> confirm;
            if (confirm == "Y")
            {
                this->Delete(id);
                std::system("pause");
            }
            else if (confirm != "N")
            {
                cout << setw(45) << ""
                     << "Invalid choice!\n";
                std::system("pause");
            }
        }
        else if (choice == "3")
        {
            this->Search();
            // std::system("pause");
        }
        else if (choice == "4")
        {
            this->Show();
            this->Update();
            // std::system("pause");
        }
        else if (choice == "5")
        {
            this->Show();
            std::system("pause");
        }
        else
        {
            std::system("cls");
            break;
        }
        // std::system("pause");
        std::system("cls");
    }
}
void StaffManager::Login(bool &isAdmin, bool &isStaff)
{

    while (true)
    {
        string username, password;
        std::cout << setw(50) << ""
                  << "----LOGIN---- "
                  << "\n\n";
        std::cout << setw(47) << ""
                  << "Username: ";
        cin >> username;
        std::cout << "\n";
        if (username == "exit")
        {
            break;
        }
        std::cout << setw(47) << ""
                  << "Password: ";
        // cin >> password;
        char x = 'a';
        while (x != '\n')
        {
            x = getch();
            if (x == 13)
                break;
            else if (x == 8 && password.size() != 0)
            {
                password.pop_back();
                std::cout << "\b"
                          << " \b";
            }
            else if (x != 8)
            {
                password += x;
                std::cout << '*';
            }
        }

        std::cout << "\n";
        if ((username == "admin" && password == "admin") || (username == "daisuki" && password == "nxhphuc"))
        {
            isAdmin = true;
        }
        else
        {
            for (Node<Staff> *tmp = this->list.HeadNode(); tmp != nullptr; tmp = tmp->NextNode())
            {
                if (username == tmp->Data().getUsername() && password == tmp->Data().getPassword())
                {
                    isStaff = true;
                    break;
                }
            }
        }
        std::cout << "\n";
        if (isStaff || isAdmin)
        {
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hConsole, brightgreen);
            cout << setw(47) << ""
                 << "Login successfully!\n";
            SetConsoleTextAttribute(hConsole, brightwhite);
            break;
        }
        else
        {
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hConsole, 12);
            cout << setw(47) << ""
                 << "Invalid login information!\n";
            SetConsoleTextAttribute(hConsole, 15);
        }
        std::system("pause");
        std::system("cls");
    }
}
// const StaffManager &StaffManager::operator=(const StaffManager &v)
// {
//     if (this != &v)
//     {
//         // this->n=v.n;
//         Node<Staff> *k;
//         while (this->list.HeadNode() != NULL)
//         {
//             k = this->list.HeadNode();
//             this->list.HeadNode() = this->list.HeadNode()->NextNode();
//             delete k;
//         }
//         this->list.TailNode() = NULL;
//         for (Node<Staff> *tmp = this->list.HeadNode(); tmp != nullptr; tmp = tmp->NextNode())
//         {
//             this->Add(tmp->Data());
//         }
//     }
//     return *this;
// }