#include <iostream>
#include "OrderManager.h"
#include <string>
#include <iomanip>
#include <fstream>
#include "Table.h"
using namespace std;
OrderManager::OrderManager()
{
    this->pHead = nullptr;
    this->pTail=nullptr;
    this->n=0;
}
OrderManager::~OrderManager()
{
    delete this->pHead;
    delete this->pTail;
}
const int& OrderManager::GetLength() const {
    return this->n;
}
const int& OrderManager::GetMonth(int index)  
{
    static int i;
    if(index < 0 || index > this->n) {
        return i;
    }
    Node *order = this->pHead;
    while(index--) {
        order = order->pNext;
    }
    return order->data.getPurchaseDay().getMonth();
}
const int& OrderManager::GetYear(int index) const 
{
    static int i;
    if(index < 0 || index > this->n) {
        return i;
    }
    Node *order = this->pHead;
    while(index--) {
        order = order->pNext;
    }
    return order->data.getPurchaseDay().getYear();
}
const long long& OrderManager::GetTotalPrice(int index) const {
    static long long i;
    if(index < 0 || index > this->n) {
        return i;
    }
    Node *order = this->pHead;
    while(index--) {
        order = order->pNext;
    }
    return order->data.getTotalPrice();
}
void OrderManager::Add(const Order& s)
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
// 
void OrderManager::SearchByOrderID(string m)
{
    int index=-1;
     for (Node *k=this->pHead;k!=NULL;k=k->pNext)
    {
        if(k->data.getID() == m)
        {
            index=1;
            k->data.show();
            break;
        }
    }
    if (index==-1) cout<<"Order does not exist!"<< "\n";

}
void OrderManager::SearchByCustomerID(string m)
{
    bool check = 0;
    int d=0;
     for (Node *k=this->pHead;k!=NULL;k=k->pNext)
    {
        if(k->data.getCustomerID() == m)
        {
            check = 1;
            cout << d + 1 << ". ";
            k->data.show();
            cout<<endl;
            d++;
        }
    }
    if(!check) {
        cout << "Order does not exist!\n";
    }
}
void OrderManager::SearchByStaffID(string m)
{   
    bool check = false;
    int d=0;
     for (Node *k=this->pHead;k!=NULL;k=k->pNext)
    {
        if(k->data.getStaffID() == m)
        {
            check = true;
            cout << d + 1 << ". ";
            k->data.show();
            cout<<endl;
            d++;
        }
    
    }     
    if(!check) {
        cout << "Order does not exist!\n";
    }
}

void OrderManager::Show() //Show All
{
    int d=0;
     for (Node *k=this->pHead;k!=NULL;k=k->pNext)
    {
        cout << setw(2) << d + 1 << ". ";
        k->data.show(); 
        d++;
    }
   
}
void OrderManager::LoadData() {
    fstream readfile("Order.txt", ios::in);
    string tmp;
    while(getline(readfile, tmp)) {
        int i = 0;
        Order order;
        string orderID = "";
        while(tmp[i] != '/') {
            orderID += tmp[i];
            ++i;
        }
        ++i;
        order.setID(orderID);
        string customerID = "";
        while(tmp[i] != '/') {
            customerID += tmp[i];
            ++i;
        }
        ++i;
        order.setCustomerID(customerID);
        string staffID = "";
        while(tmp[i] != '/') {
            staffID += tmp[i];
            ++i;
        }
        ++i;
        order.setStaffID(staffID);
        while(tmp[i] != '/') {
            string phoneID = ""; int amount = 0;
            while(tmp[i] != ' ') {
                phoneID += tmp[i];
                ++i;
            }
            ++i;
            while(tmp[i] != ' ') {
                amount = amount*10 + tmp[i] - 48;
                ++i;
            }
            ++i;
            
            order.addToShoppingList(ShoppingList(phoneID, amount));
        }
        ++i;
        int shpllength = 0;
        while(tmp[i] != '/') {
            shpllength = shpllength*10 + tmp[i] - 48;
            ++i;
        }
        ++i;
        order.setShpllength(shpllength);

        int day = 0, month = 0, year = 0;
        while(tmp[i] != ' ') {
            day = day*10 + tmp[i]-48;
            ++i;
        }
        ++i;
        while(tmp[i] != ' ') {
            month = month*10 + tmp[i]-48;
            ++i;
        }
        ++i;
        while(tmp[i] != ' ') {
            year = year*10 + tmp[i]-48;
            ++i;
        }
        ++i;
        ++i;
        order.setPurchaseDay(Date(day,month,year));
        long long price = 0;
        while(tmp[i] != '/') {
            price = price*10 + tmp[i] - 48;
            ++i;
        }
        order.setTotalPrice(price);
        this->Add(order);
    }
}
void OrderManager::Menu() {
    std::system("cls");
    while(true) {
        int choice;
        while(true) {
            
            // cout << setw(25) << "" << topLeftCorner << line(8) << topRightCorner << "\n";
	        // cout << setw(25) << "" << col << " TRADES " << col << "\n";
	        // cout << setw(25) << "" << botLeftCorner << line(8) << botRightCorner << "\n\n";
            cout << setw(25) << "" << "TRADES" << "\n\n";
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
            for (Node *k=this->pHead;k!=NULL;k=k->pNext) {
                if(k->data.getID() == id) {
                    k->data.show();
                    break;
                }
            }
        } else if (choice == 2) {
            cout << "Enter customerID you want to search: ";
            string id; cin >> id;
            int d=0;
            for (Node *k=this->pHead;k!=NULL;k=k->pNext) {
                if(k->data.getCustomerID() == id) {
                    cout << d + 1 << "/\n";
                    k->data.show();
                    d++;
                }
            }
        } else if (choice == 3) {
            cout << "Enter staffID you want to search: ";
            string id; cin >> id;
            int d=0;
            for (Node *k=this->pHead;k!=NULL;k=k->pNext) {
                if(k->data.getStaffID() == id) {
                    cout << d + 1 << "/\n";
                    k->data.show();
                    d++;
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
const OrderManager& OrderManager::operator=(const OrderManager& v )
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
void OrderManager::UpdateFile() {
    fstream editfile("Order.txt", ios::out);
    int d=0;
    for (Node *k=this->pHead;k!=NULL;k=k->pNext) {
        string tmp1 = "";
        for(int j = 0; j < k->data.getShpllength(); ++j) {
            ShoppingList sp = k->data.getShoppingList(j);
            tmp1 += sp.getPhoneID() + " " + to_string(sp.getAmount()) + " ";
        }
        Date dmy = k->data.getPurchaseDay();
        string tmp2 = to_string(dmy.getDay()) + " " + to_string(dmy.getMonth()) + " " + to_string(dmy.getYear()) + " ";
        string s = k->data.getID() + "/" + k->data.getCustomerID() + "/" + k->data.getStaffID() + "/" + tmp1 + "/" + to_string(k->data.getShpllength()) + "/" + tmp2 + "/" + to_string(k->data.getTotalPrice()) + "/";
        if(d != this->n-1) editfile << s << "\n";
        else editfile << s;
        d++;
    }
    editfile.close();
}