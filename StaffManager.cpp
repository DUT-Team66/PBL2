#include <iostream>
#include "StaffManager.h"
#include <string>
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
                *(p + i) = *(temp + i);
            }
            for (int i = index; i < this->n - 1; i++) {
                *(p + i) = *(temp + i + 1);
            }
            delete[] temp;
            this->n--;
        }
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
    cout << endl;
}

int StaffManager::IndexOf(string s) // ham them
{
    int index = -1;
    for (int i = 0; i < this->n; i++)
    {
        if ((this->p + i)->getSalary() == s)
        {
            index = i;
            break;
        }
    }
    return index;
}

// chu y: Update co the cap nhat nhieu cai
void StaffManager::Update(string m) // Cap nhat muc luong
{
    int index = IndexOf(m);
    if (index >= 0)
    {
        string g;
        cout << "Muc luong moi: ";
        cin >> g;
        (this->p + index)->setSalary(g);
    }
}
void StaffManager::Show()
{
    for (int i = 0; i < this->n; i++)
    {
        (this->p + i)->show(); // Show ni của class SV
    }
    cout << endl;
}