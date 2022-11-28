/*
    
    -test + fixbug

*/






#include <iostream>
#include <iomanip>
//#include "AccountManager.h"
#include "OrderManager.h"
#include "PhoneManager.h"
#include "StaffManager.h"
#include "CustomerManager.h"
#include "Staff.h"
#include "Customer.h"
#include "Admin.h"
#include "rand.h"
#include <cstring>
#include "Table.h"
#include <windows.h>
#include <ctime>
#include <sstream>
using namespace std;


int main()
{
    //system("Color 0F");
    //SetConsoleCP(437); 
    SetConsoleOutputCP(437); // hien thi ki tu ascii
    
    StaffManager staffManager;
	staffManager.LoadData();
    ///staffManager.Show();
    //cout << staffManager.GetLength() << "\n";
    PhoneManager phoneManager;
	phoneManager.LoadData();
    //phoneManager.Show();
    //cout << phoneManager.GetLength() << "\n";
    
    CustomerManager customerManager;
    customerManager.LoadData();
    
    OrderManager orderManager;
    orderManager.LoadData();

    Staff staff;
    staff.setOrderManager(orderManager);
    staff.setPhoneManager(phoneManager);
    staff.setCustomerManager(customerManager);

    Admin admin("Katou Megumi","048203000396","Female","23/09/2012","0766772943","97 Hai Son", "admin" , "admin");
    admin.setOrderManager(orderManager);
    admin.setPhoneManager(phoneManager);
    admin.setStaffManager(staffManager);
    admin.setCustomerManager(customerManager);
    admin.LoadThongKe();

    //std::system("pause");
    std::system("cls");

    // for(int i = 0;i < 10;++i) {
    //     cout << i + 1 << ". " << staffManager.getStaffID(i) << "\n";
    // }
    // choose role
    while (true)
    { 
        string choice;
        while(true) {
            title();
            // cout << setw(50) << "" << topLeftCorner << line(17) << topRightCorner << "\n";
	        // cout << setw(50) << "" << col << " NH MOBILE STORE " << col << "\n";
	        // cout << setw(50) << "" << botLeftCorner << line(17) << botRightCorner << "\n\n\n";
            //cout << setw(25) << "" << "NH MOBILE STORE" << "\n\n\n";
            std::cout << setw(45) << "" << "Select role: " << "\n"; 
            std::cout << setw(47) << "" << "1. Staff" << "\n";
            std::cout << setw(47) << "" << "2. Customer" << "\n";
            std::cout << setw(47) << "" << "3. Exit" << "\n\n";
            std::cout << setw(45) << "" << "Your choice: ";
            std::cin >> choice;
            if (choice != "1" && choice != "2" && choice != "3")
            {
                std::cout << "Please re-enter!\n";
                std::system("pause");
                
            } else break;
            std::system("cls");
            // can xu li role khong hop le
        }
        std::system("cls");
        
        
        if (choice == "1")
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

        else if (choice == "2")
        {
            
            Customer customer;
            customerManager.setInfo(customer);
            // while (true)
            // {
            //     customer.setInfo();   

            //     string choice;

            //     std::cout << "\t\t\tEnter B to re-enter information" << endl;
            //     std::cout << "\t\t\tEnter C to continue" << endl;
            //     while (true) {
                
            //         std::cout << "\t\t\tYour choice: ";
            //         std::cin >> choice;
            //         if(choice != "B" && choice != "C"){
            //             std::cout << "\t\t\tInvalid choice, please re-enter!\n";
            //         } else break;
            //     }
            //     if (choice == "B") {
            //         std::system("cls");
            //     } // Chỉnh sửa lại thông tin
            //     else if (choice == "C")
            //         break;  // Thoát khỏi vòng lặp vì nhập đúng thông tin
            
            // }

            
            //enter1: đến cái bảng đầu tiên
            std::system("cls");
    
            Order order;
            phoneManager.Shopping(order);
                // Trường hợp chắc chắn mua
                // Sẽ thêm 1 đơn hàng
            // while(true) {
            //     std::cout << setw(30) << "" << "Choose what you want to purchase\n";
            //     phoneManager.ShowTable();
            //     std::cout << "\n";
            //     std::cout << setw(45) << "" << "Enter 'exit' to exit!\n";
            //     std::cout << setw(45) << "" << "Your choice: ";
            //     string choice;
            //     std::cin >> choice;
            //     int ichoice = stringToInt(choice);
            //     if(choice == "exit") {
            //         //cout << "exit shopping\n";
            //         //system("pause");
            //         break;
            //     } else if(ichoice < 1 || ichoice > phoneManager.GetLength()) {
            //         std::cout << setw(45) << "" << "Invalid choice, please re-enter!\n";
            //         std::system("pause");
            //     } else {

            //         phoneManager.Show(ichoice-1); 

            //         std::cout << setw(45) << "" << "Amount: ";
            //         int amount; std::cin >> amount;
                    
            //         //ShoppingList sp(phoneManager.getPhoneID(choice - 1),amount); 
                    
            //         if(amount != 0) {
            //             if(amount > phoneManager.getRemainingAmount(ichoice-1)) {
            //                 cout << setw(45) << "" << "Remaining amount is not enough\n"; 
            //                 std::system("pause");
            //             } else {
            //                 if(order.searchCart(phoneManager.getPhoneID(ichoice-1))) {
            //                     order.addToCart(phoneManager.getPhoneID(ichoice-1),amount);
            //                 } else {
            //                     order.addToCart(Goods(phoneManager.getPhoneID(ichoice - 1),amount));
            //                 }
            //                 phoneManager.setRemainingAmount(ichoice-1,amount);
            //                 long long price = phoneManager.getPhonePrice(ichoice-1) *(long long)amount;
            //                 order.setTotalPrice(order.getTotalPrice() + price);
            //                 cout << setw(45) << "" << "Add to cart successfully!\n";
            //                 std::system("pause");

            //             }
            //         }
            //     }
            //     //system("pause");
            //     std::system("cls");
            // }
                
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
                
                order.setCustomerPhoneNumber(customer.getCustomerPhoneNumber());
                //cout << 4 << endl;
                
                string staffID = ""; // Mã nhân viên random
                randStaffID(staffManager,staffID);
                
                //cout << 5 <<endl;
                order.setStaffID(staffID);


                // current date/time based on current system
                time_t now = time(0);
                // convert now to string form
                tm *ltm = localtime(&now);

                // print various components of tm structure.
                // cout << "Day: "<< ltm->tm_mday << endl;
                // cout << "Month: "<< 1 + ltm->tm_mon<< endl;
                // cout << "Year:" << 1900 + ltm->tm_year<<endl;
                order.setPurchaseDay(Date(ltm->tm_mday, 1 + ltm->tm_mon, 1900 + ltm->tm_year));

                std::system("cls");
                
                order.show();
                // In ra hóa đơn
                orderManager.Add(order);    
                customerManager.Add(customer);
                admin.UpdateDoanhThuLoiNhuan(order);
                admin.setOrderManager(orderManager);
                admin.setPhoneManager(phoneManager);
                admin.setCustomerManager(customerManager);
                staff.setOrderManager(orderManager);
                staff.setPhoneManager(phoneManager);
                staff.setCustomerManager(customerManager);
            }  else {
                cout << setw(45) << "" << "SEE YOU NEXT TIMES!\n";
            }
            
            std::system("pause");
        } else if(choice == "3") {
            std::cout << setw(45) << "" << "GOOD BYE!\n";
            break;
        }
        std::system("cls");
    } 
    
    admin.UpdateAllFiles();
    //staff.UpdateAllFiles();
    customerManager.UpdateFile();
    orderManager.UpdateFile();
    return 0;
}

