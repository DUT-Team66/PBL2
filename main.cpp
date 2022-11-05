#include <iostream>
#include <iomanip>
//#include "AccountManager.h"
#include "OrderManager.h"
#include "PhoneManager.h"
#include "StaffManager.h"
#include "Customer.h"
#include "Admin.h"
#include "rand.h"
#include <cstring>
//#include "Table.h"
using namespace std;


int main()
{
    
    StaffManager staffManager;
	staffManager.LoadData();
    ///staffManager.Show();
    //cout << staffManager.GetLength() << "\n";
    PhoneManager phoneManager;
	phoneManager.LoadData();
    //phoneManager.Show();
    //cout << phoneManager.GetLength() << "\n";
    OrderManager orderManager;
    orderManager.LoadData();

    Staff staff;
    staff.setOrderManager(orderManager);
    staff.setPhoneManager(phoneManager);

    Admin admin("Katou Megumi","048203000396","Female","23/09/2012","0766772943","97 Hai Son", "admin" , "admin");
    admin.setOrderManager(orderManager);
    admin.setPhoneManager(phoneManager);
    admin.setStaffManager(staffManager);

    //std::system("pause");
    std::system("cls");

    // for(int i = 0;i < 10;++i) {
    //     cout << i + 1 << ". " << staffManager.getStaffID(i) << "\n";
    // }
    // choose role
    while (true)
    { 
        int choice;
        while(true) {
            // cout << setw(25) << "" << topLeftCorner << line(17) << topRightCorner << "\n";
	        // cout << setw(25) << "" << col << " NH MOBILE STORE " << col << "\n";
	        // cout << setw(25) << "" << botLeftCorner << line(17) << botRightCorner << "\n\n\n";
            cout << setw(25) << "" << "NH MOBILE STORE" << "\n\n\n";
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
            std::cout << "SEE YOU NEXT TIMES!\n";
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
                staffManager = admin.getStaffManager();
                phoneManager = admin.getPhoneManager();
                staff.setPhoneManager(phoneManager); 
            }
            else if (isStaff) {
                staff.Menu();
                phoneManager = staff.getPhoneManager();
                admin.setPhoneManager(phoneManager);
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
                
                std::cout << setw(20) << "" << "Your choice: ";
                int choice;
                std::cin >> choice;

                if(choice == 0) {
                    //cout << "exit shopping\n";
                    //system("pause");
                    break;
                } else if(choice < 0 || choice > phoneManager.GetLength()) {
                    std::cout << "Invalid choice, please re-enter!\n";
                } else {

                    phoneManager.Show(choice-1); 

                    std::cout << "Amount: ";
                    int amount; std::cin >> amount;
                    
                    //ShoppingList sp(phoneManager.getPhoneID(choice - 1),amount); 
                    
                    if(amount != 0) {
                        if(amount > phoneManager.getRemainingAmount(choice-1)) {
                            cout << "Remaining amount is not enough\n"; 
                            system("pause");
                        } else {
                            if(order.searchShoppingList(phoneManager.getPhoneID(choice-1))) {
                                order.addToShoppingList(phoneManager.getPhoneID(choice-1),amount);      //?????
                            } else {
                                order.addToShoppingList(ShoppingList(phoneManager.getPhoneID(choice - 1),amount));      //?????
                            }
                            phoneManager.setRemainingAmount(choice-1,amount);
                            long long price = phoneManager.getPhonePrice(choice-1) *(long long)amount;
                            order.setTotalPrice(order.getTotalPrice() + price);
                            cout << "Add to cart successfully!\n";
                            system("pause");

                        }
                    }
                }
                //system("pause");
                std::system("cls");
            }
                
            //staffManager.Show();
            //system("pause");
            
            std::system("cls");

            if(order.getShpllength() != 0){
                string orderID = "";  // Tu dong cung cap ma don hang
                //cout << 1 << endl;
                randOrderID(9, orderID);
                //cout << 2 << endl;
                order.setID(orderID);
                //cout << 3 << endl;
                
                order.setCustomerID(customer.getCustomerID());
                //cout << 4 << endl;
                
                string staffID = ""; // Mã nhân viên random
                randStaffID(staffManager,staffID);
                
                //cout << 5 <<endl;
                order.setStaffID(staffID);

                //cout << 6 << endl;
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
            }  else {
                cout << "GOOD BYE!\n";
            }
            
            std::system("pause");
        }
        std::system("cls");
    }
    
    admin.UpdateAllFiles();
    //staff.UpdateAllFiles();
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