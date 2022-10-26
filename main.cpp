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
    
    StaffManager staffManager;
	staffManager.LoadData();
    staffManager.Show();

    PhoneManager phoneManager;
	phoneManager.LoadData();
    phoneManager.Show();

    OrderManager orderManager;
    orderManager.LoadData();

    Staff staff;
    staff.setOrderManager(orderManager);
    staff.setPhoneManager(phoneManager);

    Admin admin("Katou Megumi","048203000396","Female","23/09/2012","0766772943","97 Hai Son", "admin" , "admin");
    admin.setOrderManager(orderManager);
    admin.setPhoneManager(phoneManager);
    admin.setStaffManager(staffManager);

    std::system("pause");
    std::system("cls");


    // choose role
    while (true)
    { 
        int choice;
        while(true) {
            std::cout << setw(25) << "" << "NH MOBILE STORE" << "\n\n\n";
            std::cout << setw(20) << "" << "Select role: " << "\n"; 
            std::cout << setw(22) << "" << "1. Staff" << "\n";
            std::cout << setw(22) << "" << "2. Customer" << "\n";
            std::cout << setw(22) << "" << "3. Exit" << "\n\n";
            std::cout << setw(20) << "" << "Your choice: ";
            std::cin >> choice;
            if (choice != 1 && choice != 2 && choice != 3)
            {
                std::cout << "Please re-enter!\n";
                std::system("pause");
                
            } else break;
            std::system("cls");
            // can xu li role khong hop le
        }
        std::system("cls");
        
        if(choice == 3) {
            std::cout << "Goodbye!\n";
            break;
        }
        else if (choice == 1)
        {
            // enter staff account
            
            bool isAdmin = false, isStaff = false;
            staffManager.Login(isAdmin, isStaff);   
            //
            std::system("pause");
            std::system("cls");

            if (isAdmin) {
                // admin route--------------------------------------------------
                admin.Menu();
                admin.UpdateAllFiles();
            }
            else if (isStaff) {
                staff.Menu();
                staff.UpdateAllFiles();
            } 
        }

        else if (choice == 2)
        {
            Customer customer;
            while (true)
            {
                customer.setInfo();   

                string choice;

                std::cout << "\t\tEnter B to re-enter information" << endl;
                std::cout << "\t\tEnter C to continue" << endl;
                while (true) {
                
                    std::cout << "\t\tYour choice: ";
                    std::cin >> choice;
                    if(choice != "B" && choice != "C"){
                        std::cout << "Invalid choice, please re-enter!\n";
                    } else break;
                }
                if (choice == "B") {
                    std::system("cls");
                } // Chỉnh sửa lại thông tin
                else if (choice == "C")
                    break;  // Thoát khỏi vòng lặp vì nhập đúng thông tin
            
            }

            
            //enter1: đến cái bảng đầu tiên
            std::system("cls");

            Order order;
            
                // Trường hợp chắc chắn mua
                // Sẽ thêm 1 đơn hàng
            while(true) {
                std::cout << "\t\tChoose what you want to purchase\n";
                phoneManager.ShowTable();
                
                std::cout << "Your choice: ";
                int choice;
                std::cin >> choice;

                if(choice == 0) {
                    break;
                } else if(choice < 0 || choice > phoneManager.GetLength()) {
                    std::cout << "Invalid choice, please re-enter!\n";
                } else {

                    phoneManager.Show(choice-1); 

                    std::cout << "Amount: ";
                    int amount; std::cin >> amount;
                    
                    ShoppingList sp(phoneManager.getPhoneID(choice - 1),amount); 
                    
                    if(amount != 0) {
                        if(amount > phoneManager.getRemainingAmount(choice-1)) {
                            cout << "Remaining amount is not enough\n"; 
                        } else {
                            order.addToShoppingList(sp);
                            phoneManager.setRemainingAmount(choice-1,amount);
                            int price = phoneManager.getPhonePrice(choice-1) * amount;
                            order.setTotalPrice(order.getTotalPrice() + price);
                        }
                    }
                }
                //system("pause");
                std::system("cls");
            }
                
            


            
            std::system("cls");
            string orderID;  // Tu dong cung cap ma don hang
            randOrderID(9, orderID);
            order.setID(orderID);
            //srand(time(NULL));
            
            order.setCustomerID(customer.getCustomerID());
            
            
            string staffID; // Mã nhân viên random
            randStaffID(staffManager,staffID);
            order.setStaffID(staffID);

            
            Date purchaseDay;
            std::cout << "Enter purchase day: ";
            std::cin >> purchaseDay;

            order.setPurchaseDay(purchaseDay);
            system("cls");
            
            order.show();
            // In ra hóa đơn
            
            orderManager.Add(order);
            admin.setOrderManager(orderManager);
            admin.setPhoneManager(phoneManager);
            staff.setOrderManager(orderManager);
            staff.setPhoneManager(phoneManager);
        
            std::system("pause");
        }
        std::system("cls");
    }
    
    orderManager.UpdateFile();
    return 0;
}

/*
    //staff route--------------------------------------------------
    std::cout << setw(20) << "" << "Choose what you want to manage" << "\n\n";
    std::cout << setw(22) << "" << "1. Phones" << "\n";
    std::cout << setw(22) << "" << "2. Trades" << "\n\n";
    std::cout << setw(20) << "" << "Your choice: ";
    int thingToManage2; std::cin >> thingToManage2;
    //--------------------------------------------------------------
    // STAFFS-------------------------------------------------------
    std::cout << setw(25) << "" << "STAFFS" << "\n\n\n";
    std::cout << setw(22) << "" << "1. Add staff" << "\n"; // nhap day du thong tin cua staff
    std::cout << setw(22) << "" << "2. Delete staff" << "\n"; // nhap staffid
    std::cout << setw(22) << "" << "3. Search staff" << "\n"; // nhap staffid
    std::cout << setw(22) << "" << "4. Update staff" << "\n"; // nhap day du thong tin cua staff, neu khong doi nhap N/A
    std::cout << setw(22) << "" << "5. Show all staffs" << "\n\n";
    std::cout << setw(20) << "" << "Your choice: ";
    int sAction; std::cin >> sAction;
    std::cout << setw(20) << "" << "StaffID: ";
    string staffid; std::cin >> staffid;
    //--------------------------------------------------------------
    // PHONES-------------------------------------------------------
    std::cout << setw(25) << "" << "PHONES" << "\n\n\n";
    std::cout << setw(22) << "" << "1. Add phone" << "\n"; // nhap day du thong tin cua phone
    std::cout << setw(22) << "" << "2. Delete phone" << "\n"; // nhap phoneid
    std::cout << setw(22) << "" << "3. Search phone" << "\n"; // nhap phoneid
    std::cout << setw(22) << "" << "4. Show all phones" << "\n\n";
    std::cout << setw(20) << "" << "Your choice: ";
    int pAction; std::cin >> pAction;
    std::cout << setw(20) << "" << "PhoneID: ";
    string phoneid; std::cin >> phoneid;
    //--------------------------------------------------------------
    // TRADERS------------------------------------------------------
    std::cout << setw(25) << "" << "TRADES" << "\n\n\n";
    std::cout << setw(22) << "" << "1. Search by OrderID" << "\n"; //  nhap orderid
    std::cout << setw(22) << "" << "2. Search by CustomerID" << "\n"; // nhap customerid
    std::cout << setw(22) << "" << "3. Show all staffs" << "\n\n";
    std::cout << setw(20) << "" << "Your choice: ";
    int tAction; std::cin >> tAction;
    std::cout << setw(20) << "" << "OrderID: ";
    string orderid; std::cin >> orderid;
    std::cout << setw(20) << "" << "CustomerID: ";
    string customerid; std::cin >> customerid;
    //--------------------------------------------------------------
    // GetCustomerInformation----------------------------------------
    std::cout << setw(20) << "" << "Enter your information" << "\n\n";
    std::cout << setw(22) << "" << "Name: ";
    string customerName; getline(std::cin, customerName);
    std::cout << setw(22) << "" << "ID: ";
    string customerID; std::cin >> customerID;
    std::cout << setw(22) << "" << "Phone number: ";
    string customerPhoneNumber; std::cin >> customerPhoneNumber;
    std::cout << setw(22) << "" << "Address: ";
    std::cin.ignore();
    string customerAddress; getline(std::cin, customerAddress);
    //--------------------------------------------------------------
    // ShoppingTime-------------------------------------------------
    std::cout << setw(20) << "" << "Choose what you want to purchase" << "\n\n\n";
    // List of phones ( use for loop?)
    //
    std::cout << setw(20) << "" << "Your choice: ";
    int choice; std::cin >> choice;
    std::cout << setw(20) << "" << "Amount: ";
    int amount; std::cin >> amount;
    //--------------------------------------------------------------
*/