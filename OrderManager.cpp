#include <iostream>
#include "OrderManager.h"
#include <string>
#include <iomanip>
#include <fstream>
#include "Table.h"
using namespace std;
OrderManager::OrderManager()
{
    this->p = nullptr;

}
OrderManager::~OrderManager()
{
    delete[] this->p;
}
const int& OrderManager::GetLength() const {
    int n = 0;
    Order* tmp = this->p;
    while(tmp != nullptr) {
        ++n;
        tmp = tmp->getNextOrder();
    }
}
const int& OrderManager::GetMonth(int index) const {
    return (this->p + index)->getPurchaseDay().getMonth();
}
const int& OrderManager::GetYear(int index) const {
    return (this->p + index)->getPurchaseDay().getYear();
}
const long long& OrderManager::GetTotalPrice(int index) const {
    return (this->p + index)->getTotalPrice();
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
// 
void OrderManager::SearchByOrderID(string m)
{
    bool exist = false;
    Order* tmp = this->p;
    while(tmp != nullptr) {
        if(tmp->getID() == m) {
            exist = true;
            tmp->show();
        }
    }

}
void OrderManager::SearchByCustomerID(string m)
{
    bool check = 0;
    for (int i=0;i<this->n;i++)
    {
        if((this->p+i)->getCustomerID() == m)
        {
            check = 1;
            cout << i + 1 << ". ";
            (this->p+i)->show();
            cout<<endl;
        }
    }
    if(!check) {
        cout << "Order does not exist!\n";
    }
}
void OrderManager::SearchByStaffID(string m)
{   
    bool check = false;
    for (int i=0;i<this->n;i++)
    {
        if((this->p+i)->getStaffID() == m)
        {
            check = true;
            cout << i + 1 << ". ";
            (this->p+i)->show();
            cout<<endl;
        }
    
    }     
    if(!check) {
        cout << "Order does not exist!\n";
    }
}

void OrderManager::Show() //Show All
{

    cout << topLeftCorner << line(7); // stt
	cout << topMid << line(11); // orderid
	cout << topMid << line(14); //customerID
	cout << topMid << line(14); // staffID
	cout << topMid << line(14); // cart
	cout << topMid << line(13); //purchaseday
	cout << topMid << line(14); //totalprice
	cout << topRightCorner << "\n";
	
	cout << col << setw(1) << "" << setw(6) << left << "Order";
	cout << col << setw(2) << "" << setw(9) << left << "OrderID"; 
	cout << col << setw(2) << "" << setw(12) << left << "CustomerID";
	cout << col << setw(3) << "" << setw(11) << left << "StaffID";
	cout << col << setw(4) << "" << setw(10) << left << "Cart";
	cout << col << setw(1) << "" << setw(12) << left << "Purchaseday";
	cout << col << setw(2) << "" << setw(12) << left << "Totalprice";
	cout << col << "\n";
	
	for(int i = 0; i < this->n; ++i) {
		cout << leftSide << line(7);
		cout << midMid << line(11);
		cout << midMid << line(14);
		cout << midMid << line(14);
		cout << midMid << line(14);
		cout << midMid << line(13);
		cout << midMid << line(14);
		cout << rightSide << "\n";
		
        cout << col << setw((7 - to_string(i + 1).length())/2) << "" << setw(7 - (7 - to_string(i + 1).length())/2) << left << i + 1;
		cout << col << setw((11 - (this->p + i)->getID().length())/2) << "" << setw(11 - (11 - (this->p + i)->getID().length())/2) << left << (this->p + i )->getID();
		cout << col << setw((14 - (this->p + i)->getCustomerID().length())/2) << "" << setw(14 - (14 - (this->p + i)->getCustomerID().length())/2) << left << (this->p + i)->getCustomerID();
		cout << col << setw((14 - (this->p + i)->getStaffID().length())/2) << "" << setw(14 - (14 - (this->p + i)->getStaffID().length())/2) << left << (this->p + i)->getStaffID();
        cout << col << setw(1) << "" << (this->p + i)->getShoppingList(0).getPhoneID() << "/" << to_string((this->p + i)->getShoppingList(0).getAmount()) << setw(12 - (this->p + i)->getShoppingList(0).getPhoneID().length() - to_string((this->p + i)->getShoppingList(0).getAmount()).length()) << "";
		cout << col << "  " << setw(0) << left << (this->p + i)->getPurchaseDay() << setw(10 - to_string((this->p + i)->getPurchaseDay().getDay()).length() - to_string((this->p + i)->getPurchaseDay().getMonth()).length() - to_string((this->p + i)->getPurchaseDay().getYear()).length() - 1) << "";
		cout << col << setw(14 - (14 - to_string((this->p + i)->getTotalPrice()).length())/2) << right << (this->p + i)->getTotalPrice() << setw((14 - to_string((this->p + i)->getTotalPrice()).length())/2) << "";	
		cout << col << "\n";
		
		for(int j = 1; j < (this->p + i)->getShpllength(); ++j) {
			cout << col << setw(7) << "";
			cout << col << setw(11) << "";
			cout << col << setw(14) << "";
			cout << col << setw(14) << ""; 
            cout << col << " " << setw(0) << left << (this->p + i)->getShoppingList(j).getPhoneID() << "/" << to_string((this->p + i)->getShoppingList(j).getAmount()) << setw(12 - (this->p + i)->getShoppingList(j).getPhoneID().length() - to_string((this->p + i)->getShoppingList(j).getAmount()).length()) << "";
			cout << col << setw(13) << "";
			cout << col << setw(14) << "";
			cout << col << "\n";
		}
	}
	
	
	cout << botLeftCorner << line(7); 
	cout << botMid << line(11);
	cout << botMid << line(14); 
	cout << botMid << line(14); 
	cout << botMid << line(14); 
	cout << botMid << line(13);
	cout << botMid << line(14); 
	cout << botRightCorner << "\n";
    
   
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
        string choice;
        while(true) {
            
            cout << setw(35) << "" << topLeftCorner << line(8) << topRightCorner << "\n";
	        cout << setw(35) << "" << col << " TRADES " << col << "\n";
	        cout << setw(35) << "" << botLeftCorner << line(8) << botRightCorner << "\n\n";
            //cout << setw(25) << "" << "TRADES" << "\n\n";
            cout << setw(32) << "" << "1. Search by OrderID" << "\n"; //  nhap orderid
            cout << setw(32) << "" << "2. Search by CustomerID" << "\n"; // nhap customerid
            cout << setw(32) << "" << "3. Search by StaffID" << "\n"; // nhap customerid
            cout << setw(32) << "" << "4. Show all orders" << "\n";
            cout << setw(32) << "" << "5. Go back" << "\n\n";
            cout << setw(30) << "" << "Your choice: ";
            cin >> choice;
            if(choice != "1" && choice != "2" && choice != "3" && choice != "4" && choice != "5") {
                cout << "Invalid choice, please re-enter!\n";
                std::system("pause");
                std::system("cls"); 
            } else break;
        }
        if(choice == "1") {
            cout << "Enter orderID you want to search: ";
            string id; cin >> id;
            for(int i = 0; i < this->n; ++i) {
                if((this->p + i)->getID() == id) {
                    (this->p + i)->show();
                    break;
                }
            }
        } else if (choice == "2") {
            cout << "Enter customerID you want to search: ";
            string id; cin >> id;
            for(int i = 0; i < this->n; ++i) {
                if((this->p + i)->getCustomerID() == id) {
                    cout << i + 1 << "/\n";
                    (this->p + i)->show();
                }
            }
        } else if (choice == "3") {
            cout << "Enter staffID you want to search: ";
            string id; cin >> id;
            for(int i = 0; i < this->n; ++i) {
                if((this->p + i)->getStaffID() == id) {
                    cout << i + 1 << "/\n";
                    (this->p + i)->show();
                }
            }
        } else if(choice == "4") {
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
        delete[] this->p;
        this->p = new Order[this->n];
        for (int i=0;i<this->n;i++)
            *(this->p + i) = *(v.p+i); 
    }
    return *this;
}
void OrderManager::UpdateFile() {
    fstream editfile("Order.txt", ios::out);
    for(int i = 0; i < this->n; ++i) {
        string tmp1 = "";
        for(int j = 0; j < (this->p + i)->getShpllength(); ++j) {
            ShoppingList sp = (this->p + i)->getShoppingList(j);
            tmp1 += sp.getPhoneID() + " " + to_string(sp.getAmount()) + " ";
        }
        Date dmy = (this->p + i)->getPurchaseDay();
        string tmp2 = to_string(dmy.getDay()) + " " + to_string(dmy.getMonth()) + " " + to_string(dmy.getYear()) + " ";
        string s = (this->p + i)->getID() + "/" + (this->p + i)->getCustomerID() + "/" + (this->p + i)->getStaffID() + "/" + tmp1 + "/" + to_string((this->p + i)->getShpllength()) + "/" + tmp2 + "/" + to_string((this->p + i)->getTotalPrice()) + "/";
        if(i != this->n-1) editfile << s << "\n";
        else editfile << s;
    }
    editfile.close();
}