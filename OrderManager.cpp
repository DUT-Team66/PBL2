#include <iostream>
#include "OrderManager.h"
#include <string>
#include <iomanip>
#include <fstream>
#include "Table.h"
using namespace std;
OrderManager::OrderManager()
{

}
OrderManager::~OrderManager()
{

}
int OrderManager::GetLength() const {
    return this->list.size();
}
const int& OrderManager::GetMonth(int index)  
{
    static int i;
    if(index < 0 || index > this->list.size()) {
        return i;
    }
    Node<Order> *order = this->list.HeadNode();
    while(index--) {
        order = order->NextNode();
    }
    return order->Data().getPurchaseDay().getMonth();
}
const int& OrderManager::GetYear(int index)
{
    static int i;
    if(index < 0 || index > this->list.size()) {
        return i;
    }
    Node<Order> *order = this->list.HeadNode();
    while(index--) {
        order = order->NextNode();
    }
    return order->Data().getPurchaseDay().getYear();
}
const long long& OrderManager::GetTotalPrice(int index) {
    static long long i;
    if(index < 0 || index > this->list.size()) {
        return i;
    }
    Node<Order> *order = this->list.HeadNode();
    while(index--) {
        order = order->NextNode();
    }
    return order->Data().getTotalPrice();
}
void OrderManager::Add(const Order& s)
{
    this->list.Add(s);
}
void OrderManager::SearchByOrderID(string m)
{
    bool checkExist = false;
    Node<Order> *tmp = this->list.HeadNode();
    while(tmp != nullptr) {
        if(tmp->Data().getID() == m) {
            checkExist = true;
            std::cout << topLeftCorner << line(11); // orderid
            std::cout << topMid << line(14); //customerID
            std::cout << topMid << line(14); // staffID
            std::cout << topMid << line(14); // cart
            std::cout << topMid << line(13); //purchaseday
            std::cout << topMid << line(14); //totalprice
            std::cout << topRightCorner << "\n";
            
            std::cout << col << setw(2) << "" << setw(9) << left << "OrderID"; 
            std::cout << col << setw(2) << "" << setw(12) << left << "CustomerID";
            std::cout << col << setw(3) << "" << setw(11) << left << "StaffID";
            std::cout << col << setw(4) << "" << setw(10) << left << "Cart";
            std::cout << col << setw(1) << "" << setw(12) << left << "Purchaseday";
            std::cout << col << setw(2) << "" << setw(12) << left << "Totalprice";
            std::cout << col << "\n";

            std::cout << leftSide << line(11);
            std::cout << midMid << line(14);
            std::cout << midMid << line(14);
            std::cout << midMid << line(14);
            std::cout << midMid << line(13);
            std::cout << midMid << line(14);
            std::cout << rightSide << "\n";

            std::cout << col << setw((11 - tmp->Data().getID().length())/2) << "" << setw(11 - (11 - tmp->Data().getID().length())/2) << left << tmp->Data().getID();
            std::cout << col << setw((14 - tmp->Data().getCustomerPhoneNumber().length())/2) << "" << setw(14 - (14 - tmp->Data().getCustomerPhoneNumber().length())/2) << left << tmp->Data().getCustomerPhoneNumber();
            std::cout << col << setw((14 - tmp->Data().getStaffID().length())/2) << "" << setw(14 - (14 - tmp->Data().getStaffID().length())/2) << left << tmp->Data().getStaffID();
            std::cout << col << setw(1) << "" << tmp->Data().getGoods(0).getPhoneID() << "/" << to_string(tmp->Data().getGoods(0).getAmount()) << setw(12 - tmp->Data().getGoods(0).getPhoneID().length() - to_string(tmp->Data().getGoods(0).getAmount()).length()) << "";
            std::cout << col << "  " << setw(0) << left << tmp->Data().getPurchaseDay() << setw(10 - to_string(tmp->Data().getPurchaseDay().getDay()).length() - to_string(tmp->Data().getPurchaseDay().getMonth()).length() - to_string(tmp->Data().getPurchaseDay().getYear()).length() - 1) << "";
            std::cout << col << setw(14 - (14 - to_string(tmp->Data().getTotalPrice()).length())/2) << right << tmp->Data().getTotalPrice() << setw((14 - to_string(tmp->Data().getTotalPrice()).length())/2) << "";	
            std::cout << col << "\n";

            int n = tmp->Data().getShpllength();
            for(int j = 1; j < n; ++j) {
                std::cout << col << setw(11) << "";
                std::cout << col << setw(14) << "";
                std::cout << col << setw(14) << ""; 
                std::cout << col << " " << setw(0) << left << tmp->Data().getGoods(j).getPhoneID() << "/" << to_string(tmp->Data().getGoods(j).getAmount()) << setw(12 - tmp->Data().getGoods(j).getPhoneID().length() - to_string(tmp->Data().getGoods(j).getAmount()).length()) << "";
                std::cout << col << setw(13) << "";
                std::cout << col << setw(14) << "";
                std::cout << col << "\n";
            }
            std::cout << botLeftCorner << line(11);
            std::cout << botMid << line(14); 
            std::cout << botMid << line(14); 
            std::cout << botMid << line(14); 
            std::cout << botMid << line(13);
            std::cout << botMid << line(14); 
            std::cout << botRightCorner << "\n";
            break;
        }
        tmp = tmp->NextNode();
    }

    if(!checkExist) {
        std::cout << setw(45) << "" << " No orders found!\n";
    }

}
void OrderManager::SearchByCustomerPhoneNumber(string m)
{
    bool checkExist = false;
    Node<Order> *tmp = this->list.HeadNode();
    while(tmp != nullptr) {
        if(tmp->Data().getCustomerPhoneNumber() == m) {
            checkExist = true;
            std::cout << topLeftCorner << line(11); // orderid
            std::cout << topMid << line(14); //customerID
            std::cout << topMid << line(14); // staffID
            std::cout << topMid << line(14); // cart
            std::cout << topMid << line(13); //purchaseday
            std::cout << topMid << line(14); //totalprice
            std::cout << topRightCorner << "\n";
            
            std::cout << col << setw(2) << "" << setw(9) << left << "OrderID"; 
            std::cout << col << setw(2) << "" << setw(12) << left << "CustomerID";
            std::cout << col << setw(3) << "" << setw(11) << left << "StaffID";
            std::cout << col << setw(4) << "" << setw(10) << left << "Cart";
            std::cout << col << setw(1) << "" << setw(12) << left << "Purchaseday";
            std::cout << col << setw(2) << "" << setw(12) << left << "Totalprice";
            std::cout << col << "\n";

            std::cout << leftSide << line(11);
            std::cout << midMid << line(14);
            std::cout << midMid << line(14);
            std::cout << midMid << line(14);
            std::cout << midMid << line(13);
            std::cout << midMid << line(14);
            std::cout << rightSide << "\n";

            std::cout << col << setw((11 - tmp->Data().getID().length())/2) << "" << setw(11 - (11 - tmp->Data().getID().length())/2) << left << tmp->Data().getID();
            std::cout << col << setw((14 - tmp->Data().getCustomerPhoneNumber().length())/2) << "" << setw(14 - (14 - tmp->Data().getCustomerPhoneNumber().length())/2) << left << tmp->Data().getCustomerPhoneNumber();
            std::cout << col << setw((14 - tmp->Data().getStaffID().length())/2) << "" << setw(14 - (14 - tmp->Data().getStaffID().length())/2) << left << tmp->Data().getStaffID();
            std::cout << col << setw(1) << "" << tmp->Data().getGoods(0).getPhoneID() << "/" << to_string(tmp->Data().getGoods(0).getAmount()) << setw(12 - tmp->Data().getGoods(0).getPhoneID().length() - to_string(tmp->Data().getGoods(0).getAmount()).length()) << "";
            std::cout << col << "  " << setw(0) << left << tmp->Data().getPurchaseDay() << setw(10 - to_string(tmp->Data().getPurchaseDay().getDay()).length() - to_string(tmp->Data().getPurchaseDay().getMonth()).length() - to_string(tmp->Data().getPurchaseDay().getYear()).length() - 1) << "";
            std::cout << col << setw(14 - (14 - to_string(tmp->Data().getTotalPrice()).length())/2) << right << tmp->Data().getTotalPrice() << setw((14 - to_string(tmp->Data().getTotalPrice()).length())/2) << "";	
            std::cout << col << "\n";

            int n = tmp->Data().getShpllength();
            for(int j = 1; j < n; ++j) {
                std::cout << col << setw(11) << "";
                std::cout << col << setw(14) << "";
                std::cout << col << setw(14) << ""; 
                std::cout << col << " " << setw(0) << left << tmp->Data().getGoods(j).getPhoneID() << "/" << to_string(tmp->Data().getGoods(j).getAmount()) << setw(12 - tmp->Data().getGoods(j).getPhoneID().length() - to_string(tmp->Data().getGoods(j).getAmount()).length()) << "";
                std::cout << col << setw(13) << "";
                std::cout << col << setw(14) << "";
                std::cout << col << "\n";
            }
            std::cout << botLeftCorner << line(11);
            std::cout << botMid << line(14); 
            std::cout << botMid << line(14); 
            std::cout << botMid << line(14); 
            std::cout << botMid << line(13);
            std::cout << botMid << line(14); 
            std::cout << botRightCorner << "\n";
        }
        tmp = tmp->NextNode();
    }

    if(!checkExist) {
        std::cout << setw(45) << "" << " No orders found!\n";
    }
}
void OrderManager::SearchByStaffID(string m)
{   
    bool checkExist = false;
    Node<Order> *tmp = this->list.HeadNode();
    while(tmp != nullptr) {
        if(tmp->Data().getStaffID() == m) {
            checkExist = true;
            std::cout << topLeftCorner << line(11); // orderid
            std::cout << topMid << line(14); //customerID
            std::cout << topMid << line(14); // staffID
            std::cout << topMid << line(14); // cart
            std::cout << topMid << line(13); //purchaseday
            std::cout << topMid << line(14); //totalprice
            std::cout << topRightCorner << "\n";
            
            std::cout << col << setw(2) << "" << setw(9) << left << "OrderID"; 
            std::cout << col << setw(2) << "" << setw(12) << left << "CustomerID";
            std::cout << col << setw(3) << "" << setw(11) << left << "StaffID";
            std::cout << col << setw(4) << "" << setw(10) << left << "Cart";
            std::cout << col << setw(1) << "" << setw(12) << left << "Purchaseday";
            std::cout << col << setw(2) << "" << setw(12) << left << "Totalprice";
            std::cout << col << "\n";

            std::cout << leftSide << line(11);
            std::cout << midMid << line(14);
            std::cout << midMid << line(14);
            std::cout << midMid << line(14);
            std::cout << midMid << line(13);
            std::cout << midMid << line(14);
            std::cout << rightSide << "\n";

            std::cout << col << setw((11 - tmp->Data().getID().length())/2) << "" << setw(11 - (11 - tmp->Data().getID().length())/2) << left << tmp->Data().getID();
            std::cout << col << setw((14 - tmp->Data().getCustomerPhoneNumber().length())/2) << "" << setw(14 - (14 - tmp->Data().getCustomerPhoneNumber().length())/2) << left << tmp->Data().getCustomerPhoneNumber();
            std::cout << col << setw((14 - tmp->Data().getStaffID().length())/2) << "" << setw(14 - (14 - tmp->Data().getStaffID().length())/2) << left << tmp->Data().getStaffID();
            std::cout << col << setw(1) << "" << tmp->Data().getGoods(0).getPhoneID() << "/" << to_string(tmp->Data().getGoods(0).getAmount()) << setw(12 - tmp->Data().getGoods(0).getPhoneID().length() - to_string(tmp->Data().getGoods(0).getAmount()).length()) << "";
            std::cout << col << "  " << setw(0) << left << tmp->Data().getPurchaseDay() << setw(10 - to_string(tmp->Data().getPurchaseDay().getDay()).length() - to_string(tmp->Data().getPurchaseDay().getMonth()).length() - to_string(tmp->Data().getPurchaseDay().getYear()).length() - 1) << "";
            std::cout << col << setw(14 - (14 - to_string(tmp->Data().getTotalPrice()).length())/2) << right << tmp->Data().getTotalPrice() << setw((14 - to_string(tmp->Data().getTotalPrice()).length())/2) << "";	
            std::cout << col << "\n";

            int n = tmp->Data().getShpllength();
            for(int j = 1; j < n; ++j) {
                std::cout << col << setw(11) << "";
                std::cout << col << setw(14) << "";
                std::cout << col << setw(14) << ""; 
                std::cout << col << " " << setw(0) << left << tmp->Data().getGoods(j).getPhoneID() << "/" << to_string(tmp->Data().getGoods(j).getAmount()) << setw(12 - tmp->Data().getGoods(j).getPhoneID().length() - to_string(tmp->Data().getGoods(j).getAmount()).length()) << "";
                std::cout << col << setw(13) << "";
                std::cout << col << setw(14) << "";
                std::cout << col << "\n";
            }
            std::cout << botLeftCorner << line(11);
            std::cout << botMid << line(14); 
            std::cout << botMid << line(14); 
            std::cout << botMid << line(14); 
            std::cout << botMid << line(13);
            std::cout << botMid << line(14); 
            std::cout << botRightCorner << "\n";
        }
        tmp = tmp->NextNode();
    }

    if(!checkExist) {
        std::cout << setw(45) << "" << " No orders found!\n";
    }
}
void OrderManager::Show() //Show All
{
    std::cout << setw(15) << "" << topLeftCorner << line(7); // stt
	std::cout << topMid << line(11); // orderid
	std::cout << topMid << line(14); //customerID
	std::cout << topMid << line(14); // staffID
	std::cout << topMid << line(14); // cart
	std::cout << topMid << line(13); //purchaseday
	std::cout << topMid << line(14); //totalprice
	std::cout << topRightCorner << "\n";
	
	std::cout << setw(15) << "" << col << setw(1) << "" << setw(6) << left << "Order";
	std::cout << col << setw(2) << "" << setw(9) << left << "OrderID"; 
	std::cout << col << setw(2) << "" << setw(12) << left << "CustomerID";
	std::cout << col << setw(3) << "" << setw(11) << left << "StaffID";
	std::cout << col << setw(4) << "" << setw(10) << left << "Cart";
	std::cout << col << setw(1) << "" << setw(12) << left << "Purchaseday";
	std::cout << col << setw(2) << "" << setw(12) << left << "Totalprice";
	std::cout << col << "\n";

    Node<Order> *tmp = this->list.HeadNode();
    int i = 0;
    while(tmp != nullptr) {
        std::cout << setw(15) << "" << leftSide << line(7);
		std::cout << midMid << line(11);
		std::cout << midMid << line(14);
		std::cout << midMid << line(14);
		std::cout << midMid << line(14);
		std::cout << midMid << line(13);
		std::cout << midMid << line(14);
		std::cout << rightSide << "\n";
		
        std::cout << setw(15) << "" << col << setw((7 - to_string(i + 1).length())/2) << "" << setw(7 - (7 - to_string(i + 1).length())/2) << left << i + 1; ++i;
		std::cout << col << setw((11 - tmp->Data().getID().length())/2) << "" << setw(11 - (11 - tmp->Data().getID().length())/2) << left << tmp->Data().getID();
		std::cout << col << setw((14 - tmp->Data().getCustomerPhoneNumber().length())/2) << "" << setw(14 - (14 - tmp->Data().getCustomerPhoneNumber().length())/2) << left << tmp->Data().getCustomerPhoneNumber();
		std::cout << col << setw((14 - tmp->Data().getStaffID().length())/2) << "" << setw(14 - (14 - tmp->Data().getStaffID().length())/2) << left << tmp->Data().getStaffID();
        std::cout << col << setw(1) << "" << tmp->Data().getGoods(0).getPhoneID() << "/" << to_string(tmp->Data().getGoods(0).getAmount()) << setw(12 - tmp->Data().getGoods(0).getPhoneID().length() - to_string(tmp->Data().getGoods(0).getAmount()).length()) << "";
		std::cout << col << "  " << setw(0) << left << tmp->Data().getPurchaseDay() << setw(10 - to_string(tmp->Data().getPurchaseDay().getDay()).length() - to_string(tmp->Data().getPurchaseDay().getMonth()).length() - to_string(tmp->Data().getPurchaseDay().getYear()).length() - 1) << "";
		std::cout << col << setw(14 - (14 - to_string(tmp->Data().getTotalPrice()).length())/2) << right << tmp->Data().getTotalPrice() << setw((14 - to_string(tmp->Data().getTotalPrice()).length())/2) << "";	
		std::cout << col << "\n";

        int n = tmp->Data().getShpllength();
        for(int j = 1; j < n; ++j) {
            std::cout << setw(15) << "" << col << setw(7) << "";
			std::cout << col << setw(11) << "";
			std::cout << col << setw(14) << "";
			std::cout << col << setw(14) << ""; 
            std::cout << col << " " << setw(0) << left << tmp->Data().getGoods(j).getPhoneID() << "/" << to_string(tmp->Data().getGoods(j).getAmount()) << setw(12 - tmp->Data().getGoods(j).getPhoneID().length() - to_string(tmp->Data().getGoods(j).getAmount()).length()) << "";
			std::cout << col << setw(13) << "";
			std::cout << col << setw(14) << "";
			std::cout << col << "\n";
        }
        tmp = tmp->NextNode();
    } 
    std::cout << setw(15) << "" << botLeftCorner << line(7); 
	std::cout << botMid << line(11);
	std::cout << botMid << line(14); 
	std::cout << botMid << line(14); 
	std::cout << botMid << line(14); 
	std::cout << botMid << line(13);
	std::cout << botMid << line(14); 
	std::cout << botRightCorner << "\n";
    
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
            
            std::cout << setw(50) << "" << topLeftCorner << line(8) << topRightCorner << "\n";
	        std::cout << setw(50) << "" << col << " ORDERS " << col << "\n";
	        std::cout << setw(50) << "" << botLeftCorner << line(8) << botRightCorner << "\n\n";

            std::cout << setw(47) << "" << "1. Search by orderID" << "\n"; //  nhap orderid
            std::cout << setw(47) << "" << "2. Search by customer phone number" << "\n"; // nhap customerid
            std::cout << setw(47) << "" << "3. Search by staffID" << "\n"; // nhap customerid
            std::cout << setw(47) << "" << "4. Show all orders" << "\n";
            std::cout << setw(47) << "" << "5. Go back" << "\n\n";
            std::cout << setw(45) << "" << "Your choice: ";
            cin >> choice;
            if(choice != "1" && choice != "2" && choice != "3" && choice != "4" && choice != "5") {
                std::cout << "Invalid choice, please re-enter!\n";
                std::system("pause");
                std::system("cls"); 
            } else break;
        }
        if(choice == "1") {
            std::cout << setw(35) << "" << "Enter orderID you want to search: ";
            string id; cin >> id;
            this->SearchByOrderID(id);
            std::system("pause");
        } else if (choice == "2") {
            std::cout << setw(35) << "" << "Enter customer phone number you want to search: ";
            string phoneNumber; cin >> phoneNumber;
            this->SearchByCustomerPhoneNumber(phoneNumber);
            std::system("pause");
        } else if (choice == "3") {
            std::cout << setw(35) << "" << "Enter staffID you want to search: ";
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
// const OrderManager& OrderManager::operator=(const OrderManager& v )
// {
//     this->list = v.list;
//     return *this;
// }
void OrderManager::UpdateFile() {
    fstream editfile("Order.txt", ios::out);
    int d=0;
    for (Node<Order> *tmp = this->list.HeadNode(); tmp != nullptr; tmp = tmp->NextNode()) {
        string tmp1 = "";
        for(int j = 0; j < tmp->Data().getShpllength(); ++j) {
            Goods sp = tmp->Data().getGoods(j);
            tmp1 += sp.getPhoneID() + " " + to_string(sp.getAmount()) + " ";
        }
        Date dmy = tmp->Data().getPurchaseDay();
        string tmp2 = to_string(dmy.getDay()) + " " + to_string(dmy.getMonth()) + " " + to_string(dmy.getYear()) + " ";
        string s = tmp->Data().getID() + "/" + tmp->Data().getCustomerPhoneNumber() + "/" + tmp->Data().getStaffID() + "/" + tmp1 + "/" + to_string(tmp->Data().getShpllength()) + "/" + tmp2 + "/" + to_string(tmp->Data().getTotalPrice()) + "/";
        if(d != this->list.size() - 1) editfile << s << "\n";
        else editfile << s;
        d++;
    }
    editfile.close();
}