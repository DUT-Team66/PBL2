#include <iostream>
#include "OrderManager.h"
#include <string>
#include <iomanip>
using namespace std;
OrderManager::OrderManager()
{
    this->p = nullptr;
    this->n = 0;
}
OrderManager::~OrderManager()
{
    delete[] this->p;
}
void OrderManager::Add(const Order& s)
{
    if(this->n==0) {
        this->p = new Order[this->n+1];
        *(this->p+this->n) = s;
        this->n++;
    }
    else {
        Order *temp = new Order[this->n];
        for (int i=0;i<this->n;i++)
        {
            *(temp+i) = *(this->p+i);
        }
        delete[] this->p;
        this->p = new Order[this->n+1];
        for (int i=0;i<this->n;i++)  // còn phần tử cuối
            *(this->p+i)=*(temp+i);
        delete[] temp;
        *(this->p+this->n) = s;
        this->n++;
    }
}

void OrderManager::SearchByOrderID(string m)
{
    int index=-1;
    for (int i=0;i<this->n;i++)
    {
        if((this->p+i)->getID() == m)
        {
            index=i;
            break;
        }
    }
    if (index>=0) (this->p+index)->show();
    else cout<<"Khong co don hang nao!"<<endl;

}
void OrderManager::SearchByCustomerID(string m)
{
    int d=1;
    for (int i=0;i<this->n;i++)
    {
        if((this->p+i)->getCustomerID() == m)
        {
            cout<<"Don hang thu "<<d<<":"<<endl;
            d++;
            (this->p+i)->show();
            cout<<endl;
        }
    }
}
void OrderManager::SearchByStaffID(string m)
{   
    int d=1;
    for (int i=0;i<this->n;i++)
    {
        if((this->p+i)->getStaffID() == m)
        {
            cout<<"Don hang thu "<<d<<":"<<endl;
            d++;
            (this->p+i)->show();
            cout<<endl;
        }
    
    }     
}
void OrderManager::Show() //Show All
{
    for (int i=0;i<this->n;i++)
    {
        (this->p+i)->show();  
        cout<<endl;
    }
   
}
void OrderManager::Menu() {
    std::system("cls");
    while(true) {
        int choice;
        while(true) {
            
            cout << setw(25) << "" << "TRADES" << "\n\n\n";
            cout << setw(22) << "" << "1. Search by OrderID" << "\n"; //  nhap orderid
            cout << setw(22) << "" << "2. Search by CustomerID" << "\n"; // nhap customerid
            cout << setw(22) << "" << "3. Search by StaffID" << "\n"; // nhap customerid
            cout << setw(22) << "" << "4. Show all orders" << "\n";
            cout << setw(22) << "" << "5. Go back" << "\n\n";
            cout << setw(20) << "" << "Your choice: ";
            cin >> choice;
            if(choice != 1 && choice != 2 && choice !=3 && choice != 4 && choice != 5) {
                cout << "Invalid choice, please re-enter!\n";
                std::system("pause");
                std::system("cls"); 
            } else break;
        }
        if(choice == 1) {
            cout << "Enter orderID you want to search: ";
            string id; cin >> id;
            for(int i = 0; i < this->n; ++i) {
                if((this->p + i)->getID() == id) {
                    (this->p + i)->show();
                    break;
                }
            }
        } else if (choice == 2) {
            cout << "Enter customerID you want to search: ";
            string id; cin >> id;
            for(int i = 0; i < this->n; ++i) {
                if((this->p + i)->getCustomerID() == id) {
                    cout << i + 1 << "/\n";
                    (this->p + i)->show();
                }
            }
        } else if (choice == 3) {
            cout << "Enter staffID you want to search: ";
            string id; cin >> id;
            for(int i = 0; i < this->n; ++i) {
                if((this->p + i)->getStaffID() == id) {
                    cout << i + 1 << "/\n";
                    (this->p + i)->show();
                }
            }
        } else if(choice == 4) {
            this->Show();
        } else {
            std::system("cls");
            break;  
        } 
        std::system("pause");
        std::system("cls");
    }
}