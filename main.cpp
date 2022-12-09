/*
    
    -test + fixbug

        
*/






#include <iostream>
#include <iomanip>
#include <cstring>
#include <windows.h>
#include <ctime>
#include <sstream>
#include "OrderManager.h"
#include "PhoneManager.h"
#include "CustomerManager.h"
#include "StaffManager.h"
#include "Admin.h"
#include "rand.h"
#include "Table.h"
using namespace std;


int main()
{

    //SetConsoleCP(437); 
    SetConsoleOutputCP(437); // hien thi ki tu ascii
    
    StaffManager staffManager;
	staffManager.LoadData();

    PhoneManager phoneManager;
	phoneManager.LoadData();

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


    while (true)
    { 
        string choice;
        while(true) {
            title();
            std::cout << setw(45) << "" << "Select role: " << "\n"; 
            std::cout << setw(47) << "" << "1. Staff" << "\n";
            std::cout << setw(47) << "" << "2. Customer" << "\n";
            std::cout << setw(47) << "" << "3. Exit" << "\n\n";
            std::cout << setw(45) << "" << arrow << " Your choice: "; // co mui ten
            std::cin >> choice;
            cin.clear();
            fflush(stdin);
            if (choice != "1" && choice != "2" && choice != "3")
            {
                HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	            SetConsoleTextAttribute(hConsole, brightyellow);
                std::cout << setw(45) << "" << "Please re-enter!\n";
	            SetConsoleTextAttribute(hConsole, brightwhite); 
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
                admin.Menu();
            }
            else if (isStaff) {
                staff.Menu();
            } 
        }

        else if (choice == "2")
        {
            
            Customer customer;
            bool checkExist = customerManager.setInfo(customer);
            // return true if customer exist, otherwise false
            std::system("cls");
    
            Order order;
            phoneManager.Shopping(order);
                
            std::system("cls");

            if(order.getShpllength() != 0){
                string orderID = "";  // Tu dong cung cap ma don hang

                randOrderID(9, orderID);

                order.setID(orderID);

                
                order.setCustomerPhoneNumber(customer.getCustomerPhoneNumber());

                
                string staffID = ""; // Mã nhân viên random
                randStaffID(staffManager,staffID);
                

                order.setStaffID(staffID);

                // current date/time based on current system
                time_t now = time(0);
                // convert now to string form
                tm *ltm = localtime(&now);


                order.setPurchaseDay(Date(ltm->tm_mday, 1 + ltm->tm_mon, 1900 + ltm->tm_year));

                std::system("cls");
                
                order.show();
                // In ra hóa đơn
                orderManager.Add(order);    
                if(checkExist) customerManager.Add(customer);
                admin.UpdateDoanhThuLoiNhuan(order);

            }  else {
                HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(hConsole, brightyellow);
                cout << setw(45) << "" << "SEE YOU NEXT TIMES!\n";
                SetConsoleTextAttribute(hConsole, brightwhite); 
            }
            
            std::system("pause");
        } else if(choice == "3") {
            std::cout << "\n\n";
            std::cout << setw(45) << "" << "GOOD BYE!\n";
            break;
        }
        std::system("cls");
    } 
    
    admin.UpdateAllFiles();
    customerManager.UpdateFile();
    orderManager.UpdateFile();
    return 0;
}

