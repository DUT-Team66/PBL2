#include <iostream>
#include <iomanip>
#include "AccountManager.h"
#include "OrderManager.h"
#include "PhoneManager.h"
#include "StaffManager.h"
#include "Customer.h"
#include "Admin.h"
#include "rand.h"
#include <cstring>
#include <cstdlib>
#include <time.h>
using namespace std;


int main()
{

    OrderManager orderManager;
    Admin admin;
    Staff staff;

    AccountManager accountManager;
	accountManager.LoadData();
	
	StaffManager staffManager;
	staffManager.LoadData();

	PhoneManager phoneManager;
	phoneManager.LoadData();



    // choose role
    while (true)
    { 
        cout << setw(25) << "" << "NH MOBILE STORE" << "\n\n\n";
	    cout << setw(20) << "" << "You are: " << "\n\n"; 
	    cout << setw(22) << "" << "1. Staff" << "\n\n";
	    cout << setw(22) << "" << "2. Customer" << "\n\n";

        int choice;
        cin >> choice;
        while (choice != 1 && choice != 2)
        {
            cout << "Please re-enter!" << endl;
            cin >> choice;
        }
        // can xu li role khong hop le

        if (choice == 1)
        {
            // enter staff account
            bool isAdmin = false, isStaff = false;
            accountManager.Login(isAdmin, isStaff);   
            
            //
            if (isAdmin) {
                // admin route--------------------------------------------------
                admin.Menu();
            }
            else if (isStaff) {
                staff.Menu();
            } 
        }

        else if (choice == 2)
        {
            Customer customer;
            while (true)
            {
                customer.setInfo();   


                cout << "\t\tEnter B to go back" << endl;
                cout << "\t\tEnter C to continue" << endl;
                cout << "\t\tYour choice:";
                string choice;
                cin >> choice;
                while (choice != "B" && choice != "C")
                {
                    cout << "Please re-enter: " << endl;
                    cout << "\t\tYour choice:";
                    cin >> choice;
                }
                if (choice == "B") {
                    system("cls");
                } // Chỉnh sửa lại thông tin
                else if (choice == "C")
                    break;  // Thoát khỏi vòng lặp vì nhập đúng thông tin
            
            }

            
            //enter1: đến cái bảng đầu tiên
            
            Order order;
            
                // Trường hợp chắc chắn mua
                // Sẽ thêm 1 đơn hàng
            while(true) {
                cout << "\t\tChoose what you want to purchase\n";
                phoneManager.ShowTable();
                
                cout << "Your choice: ";
                int choice;
                cin >> choice;

                if(choice == 0) {
                    break;
                } else if(choice < 0 || choice > phoneManager.GetLength()) {
                    cout << "Invalid choice, please re-enter!\n";
                } else {

                    phoneManager.Show(choice-1); 

                    cout << "Amount: ";
                    int amount; cin >> amount;
                    
                    ShoppingList sp(phoneManager.getPhoneID(choice - 1),amount); 
                    
                    if(amount != 0) {
                        order.addToShoppingList(sp);
                        int price = phoneManager.getPhonePrice(choice-1) * amount;
                        order.setTotalPrice(order.getTotalPrice() + price);
                    }
                }
                //system("pause");
                system("cls");
            }
                
            


            

            string orderID;  // Tu dong cung cap ma don hang
            randOrderID(9, orderID);
            srand(time(NULL));
            
            order.setCustomerID(customer.getCustomerID());
            
            
            string staffID; // Mã nhân viên random
            randStaffID(staffManager,staffID);

            
            Date purchaseDay;
            cout << "Enter purchase day: ";
            cin >> purchaseDay;

            order.setPurchaseDay(purchaseDay);
                    
            
            orderManager.Add(order);
            order.show();
            // In ra hóa đơn
            
        }
        system("pause");
        
    }
    return 0;
}

/*
    //staff route--------------------------------------------------
    cout << setw(20) << "" << "Choose what you want to manage" << "\n\n";
    cout << setw(22) << "" << "1. Phones" << "\n";
    cout << setw(22) << "" << "2. Trades" << "\n\n";
    cout << setw(20) << "" << "Your choice: ";
    int thingToManage2; cin >> thingToManage2;
    //--------------------------------------------------------------
    // STAFFS-------------------------------------------------------
    cout << setw(25) << "" << "STAFFS" << "\n\n\n";
    cout << setw(22) << "" << "1. Add staff" << "\n"; // nhap day du thong tin cua staff
    cout << setw(22) << "" << "2. Delete staff" << "\n"; // nhap staffid
    cout << setw(22) << "" << "3. Search staff" << "\n"; // nhap staffid
    cout << setw(22) << "" << "4. Update staff" << "\n"; // nhap day du thong tin cua staff, neu khong doi nhap N/A
    cout << setw(22) << "" << "5. Show all staffs" << "\n\n";
    cout << setw(20) << "" << "Your choice: ";
    int sAction; cin >> sAction;
    cout << setw(20) << "" << "StaffID: ";
    string staffid; cin >> staffid;
    //--------------------------------------------------------------
    // PHONES-------------------------------------------------------
    cout << setw(25) << "" << "PHONES" << "\n\n\n";
    cout << setw(22) << "" << "1. Add phone" << "\n"; // nhap day du thong tin cua phone
    cout << setw(22) << "" << "2. Delete phone" << "\n"; // nhap phoneid
    cout << setw(22) << "" << "3. Search phone" << "\n"; // nhap phoneid
    cout << setw(22) << "" << "4. Show all phones" << "\n\n";
    cout << setw(20) << "" << "Your choice: ";
    int pAction; cin >> pAction;
    cout << setw(20) << "" << "PhoneID: ";
    string phoneid; cin >> phoneid;
    //--------------------------------------------------------------
    // TRADERS------------------------------------------------------
    cout << setw(25) << "" << "TRADES" << "\n\n\n";
    cout << setw(22) << "" << "1. Search by OrderID" << "\n"; //  nhap orderid
    cout << setw(22) << "" << "2. Search by CustomerID" << "\n"; // nhap customerid
    cout << setw(22) << "" << "3. Show all staffs" << "\n\n";
    cout << setw(20) << "" << "Your choice: ";
    int tAction; cin >> tAction;
    cout << setw(20) << "" << "OrderID: ";
    string orderid; cin >> orderid;
    cout << setw(20) << "" << "CustomerID: ";
    string customerid; cin >> customerid;
    //--------------------------------------------------------------
    // GetCustomerInformation----------------------------------------
    cout << setw(20) << "" << "Enter your information" << "\n\n";
    cout << setw(22) << "" << "Name: ";
    string customerName; getline(cin, customerName);
    cout << setw(22) << "" << "ID: ";
    string customerID; cin >> customerID;
    cout << setw(22) << "" << "Phone number: ";
    string customerPhoneNumber; cin >> customerPhoneNumber;
    cout << setw(22) << "" << "Address: ";
    cin.ignore();
    string customerAddress; getline(cin, customerAddress);
    //--------------------------------------------------------------
    // ShoppingTime-------------------------------------------------
    cout << setw(20) << "" << "Choose what you want to purchase" << "\n\n\n";
    // List of phones ( use for loop?)
    //
    cout << setw(20) << "" << "Your choice: ";
    int choice; cin >> choice;
    cout << setw(20) << "" << "Amount: ";
    int amount; cin >> amount;
    //--------------------------------------------------------------
*/