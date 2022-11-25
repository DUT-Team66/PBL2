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
    bool checkExist = false;
    Node *tmp = this->pHead;
    while(tmp != nullptr) {
        if(tmp->data.getID() == m) {
            checkExist = true;
            cout << topLeftCorner << line(11); // orderid
            cout << topMid << line(14); //customerID
            cout << topMid << line(14); // staffID
            cout << topMid << line(14); // cart
            cout << topMid << line(13); //purchaseday
            cout << topMid << line(14); //totalprice
            cout << topRightCorner << "\n";
            
            cout << col << setw(2) << "" << setw(9) << left << "OrderID"; 
            cout << col << setw(2) << "" << setw(12) << left << "CustomerID";
            cout << col << setw(3) << "" << setw(11) << left << "StaffID";
            cout << col << setw(4) << "" << setw(10) << left << "Cart";
            cout << col << setw(1) << "" << setw(12) << left << "Purchaseday";
            cout << col << setw(2) << "" << setw(12) << left << "Totalprice";
            cout << col << "\n";

            cout << leftSide << line(11);
            cout << midMid << line(14);
            cout << midMid << line(14);
            cout << midMid << line(14);
            cout << midMid << line(13);
            cout << midMid << line(14);
            cout << rightSide << "\n";

            cout << col << setw((11 - tmp->data.getID().length())/2) << "" << setw(11 - (11 - tmp->data.getID().length())/2) << left << tmp->data.getID();
            cout << col << setw((14 - tmp->data.getCustomerPhoneNumber().length())/2) << "" << setw(14 - (14 - tmp->data.getCustomerPhoneNumber().length())/2) << left << tmp->data.getCustomerPhoneNumber();
            cout << col << setw((14 - tmp->data.getStaffID().length())/2) << "" << setw(14 - (14 - tmp->data.getStaffID().length())/2) << left << tmp->data.getStaffID();
            cout << col << setw(1) << "" << tmp->data.getGoods(0).getPhoneID() << "/" << to_string(tmp->data.getGoods(0).getAmount()) << setw(12 - tmp->data.getGoods(0).getPhoneID().length() - to_string(tmp->data.getGoods(0).getAmount()).length()) << "";
            cout << col << "  " << setw(0) << left << tmp->data.getPurchaseDay() << setw(10 - to_string(tmp->data.getPurchaseDay().getDay()).length() - to_string(tmp->data.getPurchaseDay().getMonth()).length() - to_string(tmp->data.getPurchaseDay().getYear()).length() - 1) << "";
            cout << col << setw(14 - (14 - to_string(tmp->data.getTotalPrice()).length())/2) << right << tmp->data.getTotalPrice() << setw((14 - to_string(tmp->data.getTotalPrice()).length())/2) << "";	
            cout << col << "\n";

            int n = tmp->data.getShpllength();
            for(int j = 1; j < n; ++j) {
                cout << col << setw(11) << "";
                cout << col << setw(14) << "";
                cout << col << setw(14) << ""; 
                cout << col << " " << setw(0) << left << tmp->data.getGoods(j).getPhoneID() << "/" << to_string(tmp->data.getGoods(j).getAmount()) << setw(12 - tmp->data.getGoods(j).getPhoneID().length() - to_string(tmp->data.getGoods(j).getAmount()).length()) << "";
                cout << col << setw(13) << "";
                cout << col << setw(14) << "";
                cout << col << "\n";
            }
            cout << botLeftCorner << line(11);
            cout << botMid << line(14); 
            cout << botMid << line(14); 
            cout << botMid << line(14); 
            cout << botMid << line(13);
            cout << botMid << line(14); 
            cout << botRightCorner << "\n";
            break;
        }
        tmp = tmp->pNext;
    }

    if(!checkExist) {
        std::cout << setw(45) << "" << " No orders found!\n";
    }

}
void OrderManager::SearchByCustomerPhoneNumber(string m)
{
    bool checkExist = false;
    Node *tmp = this->pHead;
    while(tmp != nullptr) {
        if(tmp->data.getCustomerPhoneNumber() == m) {
            checkExist = true;
            cout << topLeftCorner << line(11); // orderid
            cout << topMid << line(14); //customerID
            cout << topMid << line(14); // staffID
            cout << topMid << line(14); // cart
            cout << topMid << line(13); //purchaseday
            cout << topMid << line(14); //totalprice
            cout << topRightCorner << "\n";
            
            cout << col << setw(2) << "" << setw(9) << left << "OrderID"; 
            cout << col << setw(2) << "" << setw(12) << left << "CustomerID";
            cout << col << setw(3) << "" << setw(11) << left << "StaffID";
            cout << col << setw(4) << "" << setw(10) << left << "Cart";
            cout << col << setw(1) << "" << setw(12) << left << "Purchaseday";
            cout << col << setw(2) << "" << setw(12) << left << "Totalprice";
            cout << col << "\n";

            cout << leftSide << line(11);
            cout << midMid << line(14);
            cout << midMid << line(14);
            cout << midMid << line(14);
            cout << midMid << line(13);
            cout << midMid << line(14);
            cout << rightSide << "\n";

            cout << col << setw((11 - tmp->data.getID().length())/2) << "" << setw(11 - (11 - tmp->data.getID().length())/2) << left << tmp->data.getID();
            cout << col << setw((14 - tmp->data.getCustomerPhoneNumber().length())/2) << "" << setw(14 - (14 - tmp->data.getCustomerPhoneNumber().length())/2) << left << tmp->data.getCustomerPhoneNumber();
            cout << col << setw((14 - tmp->data.getStaffID().length())/2) << "" << setw(14 - (14 - tmp->data.getStaffID().length())/2) << left << tmp->data.getStaffID();
            cout << col << setw(1) << "" << tmp->data.getGoods(0).getPhoneID() << "/" << to_string(tmp->data.getGoods(0).getAmount()) << setw(12 - tmp->data.getGoods(0).getPhoneID().length() - to_string(tmp->data.getGoods(0).getAmount()).length()) << "";
            cout << col << "  " << setw(0) << left << tmp->data.getPurchaseDay() << setw(10 - to_string(tmp->data.getPurchaseDay().getDay()).length() - to_string(tmp->data.getPurchaseDay().getMonth()).length() - to_string(tmp->data.getPurchaseDay().getYear()).length() - 1) << "";
            cout << col << setw(14 - (14 - to_string(tmp->data.getTotalPrice()).length())/2) << right << tmp->data.getTotalPrice() << setw((14 - to_string(tmp->data.getTotalPrice()).length())/2) << "";	
            cout << col << "\n";

            int n = tmp->data.getShpllength();
            for(int j = 1; j < n; ++j) {
                cout << col << setw(11) << "";
                cout << col << setw(14) << "";
                cout << col << setw(14) << ""; 
                cout << col << " " << setw(0) << left << tmp->data.getGoods(j).getPhoneID() << "/" << to_string(tmp->data.getGoods(j).getAmount()) << setw(12 - tmp->data.getGoods(j).getPhoneID().length() - to_string(tmp->data.getGoods(j).getAmount()).length()) << "";
                cout << col << setw(13) << "";
                cout << col << setw(14) << "";
                cout << col << "\n";
            }
            cout << botLeftCorner << line(11);
            cout << botMid << line(14); 
            cout << botMid << line(14); 
            cout << botMid << line(14); 
            cout << botMid << line(13);
            cout << botMid << line(14); 
            cout << botRightCorner << "\n";
        }
        tmp = tmp->pNext;
    }

    if(!checkExist) {
        std::cout << setw(45) << "" << " No orders found!\n";
    }
}
void OrderManager::SearchByStaffID(string m)
{   
    bool checkExist = false;
    Node *tmp = this->pHead;
    while(tmp != nullptr) {
        if(tmp->data.getStaffID() == m) {
            checkExist = true;
            cout << topLeftCorner << line(11); // orderid
            cout << topMid << line(14); //customerID
            cout << topMid << line(14); // staffID
            cout << topMid << line(14); // cart
            cout << topMid << line(13); //purchaseday
            cout << topMid << line(14); //totalprice
            cout << topRightCorner << "\n";
            
            cout << col << setw(2) << "" << setw(9) << left << "OrderID"; 
            cout << col << setw(2) << "" << setw(12) << left << "CustomerID";
            cout << col << setw(3) << "" << setw(11) << left << "StaffID";
            cout << col << setw(4) << "" << setw(10) << left << "Cart";
            cout << col << setw(1) << "" << setw(12) << left << "Purchaseday";
            cout << col << setw(2) << "" << setw(12) << left << "Totalprice";
            cout << col << "\n";

            cout << leftSide << line(11);
            cout << midMid << line(14);
            cout << midMid << line(14);
            cout << midMid << line(14);
            cout << midMid << line(13);
            cout << midMid << line(14);
            cout << rightSide << "\n";

            cout << col << setw((11 - tmp->data.getID().length())/2) << "" << setw(11 - (11 - tmp->data.getID().length())/2) << left << tmp->data.getID();
            cout << col << setw((14 - tmp->data.getCustomerPhoneNumber().length())/2) << "" << setw(14 - (14 - tmp->data.getCustomerPhoneNumber().length())/2) << left << tmp->data.getCustomerPhoneNumber();
            cout << col << setw((14 - tmp->data.getStaffID().length())/2) << "" << setw(14 - (14 - tmp->data.getStaffID().length())/2) << left << tmp->data.getStaffID();
            cout << col << setw(1) << "" << tmp->data.getGoods(0).getPhoneID() << "/" << to_string(tmp->data.getGoods(0).getAmount()) << setw(12 - tmp->data.getGoods(0).getPhoneID().length() - to_string(tmp->data.getGoods(0).getAmount()).length()) << "";
            cout << col << "  " << setw(0) << left << tmp->data.getPurchaseDay() << setw(10 - to_string(tmp->data.getPurchaseDay().getDay()).length() - to_string(tmp->data.getPurchaseDay().getMonth()).length() - to_string(tmp->data.getPurchaseDay().getYear()).length() - 1) << "";
            cout << col << setw(14 - (14 - to_string(tmp->data.getTotalPrice()).length())/2) << right << tmp->data.getTotalPrice() << setw((14 - to_string(tmp->data.getTotalPrice()).length())/2) << "";	
            cout << col << "\n";

            int n = tmp->data.getShpllength();
            for(int j = 1; j < n; ++j) {
                cout << col << setw(11) << "";
                cout << col << setw(14) << "";
                cout << col << setw(14) << ""; 
                cout << col << " " << setw(0) << left << tmp->data.getGoods(j).getPhoneID() << "/" << to_string(tmp->data.getGoods(j).getAmount()) << setw(12 - tmp->data.getGoods(j).getPhoneID().length() - to_string(tmp->data.getGoods(j).getAmount()).length()) << "";
                cout << col << setw(13) << "";
                cout << col << setw(14) << "";
                cout << col << "\n";
            }
            cout << botLeftCorner << line(11);
            cout << botMid << line(14); 
            cout << botMid << line(14); 
            cout << botMid << line(14); 
            cout << botMid << line(13);
            cout << botMid << line(14); 
            cout << botRightCorner << "\n";
        }
        tmp = tmp->pNext;
    }

    if(!checkExist) {
        std::cout << setw(45) << "" << " No orders found!\n";
    }
}
long long OrderManager::calDoanhThu() {
    long long dt = 0;
    for(Node* tmp = this->pHead; tmp != nullptr; tmp = tmp->pNext) {
        if(tmp->data.getPurchaseDay().getMonth() == 11 && tmp->data.getPurchaseDay().getYear()) 
            dt += tmp->data.getTotalPrice();
    }
    return dt;
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

    Node *tmp = this->pHead;
    int i = 0;
    while(tmp != nullptr) {
        cout << leftSide << line(7);
		cout << midMid << line(11);
		cout << midMid << line(14);
		cout << midMid << line(14);
		cout << midMid << line(14);
		cout << midMid << line(13);
		cout << midMid << line(14);
		cout << rightSide << "\n";
		
        cout << col << setw((7 - to_string(i + 1).length())/2) << "" << setw(7 - (7 - to_string(i + 1).length())/2) << left << i + 1; ++i;
		cout << col << setw((11 - tmp->data.getID().length())/2) << "" << setw(11 - (11 - tmp->data.getID().length())/2) << left << tmp->data.getID();
		cout << col << setw((14 - tmp->data.getCustomerPhoneNumber().length())/2) << "" << setw(14 - (14 - tmp->data.getCustomerPhoneNumber().length())/2) << left << tmp->data.getCustomerPhoneNumber();
		cout << col << setw((14 - tmp->data.getStaffID().length())/2) << "" << setw(14 - (14 - tmp->data.getStaffID().length())/2) << left << tmp->data.getStaffID();
        cout << col << setw(1) << "" << tmp->data.getGoods(0).getPhoneID() << "/" << to_string(tmp->data.getGoods(0).getAmount()) << setw(12 - tmp->data.getGoods(0).getPhoneID().length() - to_string(tmp->data.getGoods(0).getAmount()).length()) << "";
		cout << col << "  " << setw(0) << left << tmp->data.getPurchaseDay() << setw(10 - to_string(tmp->data.getPurchaseDay().getDay()).length() - to_string(tmp->data.getPurchaseDay().getMonth()).length() - to_string(tmp->data.getPurchaseDay().getYear()).length() - 1) << "";
		cout << col << setw(14 - (14 - to_string(tmp->data.getTotalPrice()).length())/2) << right << tmp->data.getTotalPrice() << setw((14 - to_string(tmp->data.getTotalPrice()).length())/2) << "";	
		cout << col << "\n";

        int n = tmp->data.getShpllength();
        for(int j = 1; j < n; ++j) {
            cout << col << setw(7) << "";
			cout << col << setw(11) << "";
			cout << col << setw(14) << "";
			cout << col << setw(14) << ""; 
            cout << col << " " << setw(0) << left << tmp->data.getGoods(j).getPhoneID() << "/" << to_string(tmp->data.getGoods(j).getAmount()) << setw(12 - tmp->data.getGoods(j).getPhoneID().length() - to_string(tmp->data.getGoods(j).getAmount()).length()) << "";
			cout << col << setw(13) << "";
			cout << col << setw(14) << "";
			cout << col << "\n";
        }
        tmp = tmp->pNext;
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
        string customerPhonenumber = "";
        while(tmp[i] != '/') {
            customerPhonenumber += tmp[i];
            ++i;
        }
        ++i;
        order.setCustomerPhoneNumber(customerPhonenumber);
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
            
            order.addToCart(Goods(phoneID, amount));
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
            
            cout << setw(50) << "" << topLeftCorner << line(8) << topRightCorner << "\n";
	        cout << setw(50) << "" << col << " ORDERS " << col << "\n";
	        cout << setw(50) << "" << botLeftCorner << line(8) << botRightCorner << "\n\n";

            cout << setw(47) << "" << "1. Search by orderID" << "\n"; //  nhap orderid
            cout << setw(47) << "" << "2. Search by customer phone number" << "\n"; // nhap customerid
            cout << setw(47) << "" << "3. Search by staffID" << "\n"; // nhap customerid
            cout << setw(47) << "" << "4. Show all orders" << "\n";
            cout << setw(47) << "" << "5. Go back" << "\n\n";
            cout << setw(45) << "" << "Your choice: ";
            cin >> choice;
            if(choice != "1" && choice != "2" && choice != "3" && choice != "4" && choice != "5") {
                cout << "Invalid choice, please re-enter!\n";
                std::system("pause");
                std::system("cls"); 
            } else break;
        }
        if(choice == "1") {
            cout << setw(35) << "" << "Enter orderID you want to search: ";
            string id; cin >> id;
            this->SearchByOrderID(id);
            std::system("pause");
        } else if (choice == "2") {
            cout << setw(35) << "" << "Enter customer phone number you want to search: ";
            string phoneNumber; cin >> phoneNumber;
            this->SearchByCustomerPhoneNumber(phoneNumber);
            std::system("pause");
        } else if (choice == "3") {
            cout << setw(35) << "" << "Enter staffID you want to search: ";
            string id; cin >> id;
            this->SearchByStaffID(id);
            std::system("pause");
        } else if(choice == "4") {
            this->Show();
            std::system("pause");
        } else {
            std::system("cls");
            break;  
        } 
        // std::system("pause");
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
            Goods sp = k->data.getGoods(j);
            tmp1 += sp.getPhoneID() + " " + to_string(sp.getAmount()) + " ";
        }
        Date dmy = k->data.getPurchaseDay();
        string tmp2 = to_string(dmy.getDay()) + " " + to_string(dmy.getMonth()) + " " + to_string(dmy.getYear()) + " ";
        string s = k->data.getID() + "/" + k->data.getCustomerPhoneNumber() + "/" + k->data.getStaffID() + "/" + tmp1 + "/" + to_string(k->data.getShpllength()) + "/" + tmp2 + "/" + to_string(k->data.getTotalPrice()) + "/";
        if(d != this->n-1) editfile << s << "\n";
        else editfile << s;
        d++;
    }
    editfile.close();
}