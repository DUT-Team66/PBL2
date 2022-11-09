#include "Admin.h"
#include <iomanip>
#include "Table.h"
using namespace std;

Admin::Admin() {

}
Admin::~Admin() {
    
}
Admin::Admin(string name, string id, string gender, string dob, string phoneNumber, string address, string username, string password) : Staff(name,id,gender,dob,phoneNumber,address,username,password) {
    this->salary = 15000000;
}
void Admin::setStaffManager(const StaffManager& staffManager) {
    this->manageStaff = staffManager;
}
const StaffManager& Admin::getStaffManager() const {
    return this->manageStaff;
}
// void Admin::setAccountManager(const AccountManager& accountManager) {
//     this->manageAccount = accountManager;
//}
void Admin::calTurnover() 
{
    int year;
    std::cout << "Enter year: "; 
    std::cin >> year;
    long long totalTurnover[13]={0};
    for(int i = 0; i < this->manageOrder.GetLength(); ++i)
    {
        if(this->manageOrder.GetYear(i) == year)
        {
            int month=this->manageOrder.GetMonth(i);
            totalTurnover[month]+=this->manageOrder.GetTotalPrice(i);
        }
    }
    for (int i=1;i<=12;i++)
    {
        cout << "Turnover in " << i << " is " << totalTurnover[i] << "\n";  
    }
}
void Admin::Thuchi()
{
    int year;
    cout << "Enter year: "; 
    cin >> year;
    long long Von[13];
    long long Doanhthu[13];
    long long Chiphikhac;
    long long Loinhuan[13];
    for(int i = 0; i < this->manageOrder.GetLength(); ++i)
    {
        if(this->manageOrder.GetYear(i) == year)
        {
            int month=this->manageOrder.GetMonth(i);
            Doanhthu[month]+=this->manageOrder.GetTotalPrice(i);
        }
    }
}
void Admin::Menu() {
    while(true) {
        string choice;
        while(true) {
            std::cout << setw(50) << "" << topLeftCorner << line(7) << topRightCorner << "\n";
            std::cout << setw(50) << "" << col << " ADMIN " << col << "\n";
            std::cout << setw(50) << "" << botLeftCorner << line(7) << botRightCorner << "\n\n";
            cout << setw(45) << "" << "Choose what you want to manage" << "\n\n";
            cout << setw(47) << "" << "1. Staffs" << "\n";
            cout << setw(47) << "" << "2. Phones" << "\n";
            cout << setw(47) << "" << "3. Trades" << "\n";
            cout << setw(47) << "" << "4. Revenue/Expense statistics" << "\n"; // thống kê thu chi
            cout << setw(47) << "" << "5. Go back" << "\n\n";
            cout << setw(45) << "" << "Your choice: ";
            cin >> choice;
            if(choice != "1" && choice != "2" && choice != "3" && choice != "4" && choice != "5") {
                cout << "Invalid choice, please re-enter!\n";
                system("pause");
                system("cls"); 
            } else break;
        }
        
        if(choice == "1") {
            this->manageStaff.Menu();
        } else if(choice == "2") {
            this->managePhone.Menu();
        } else if(choice == "3") {
            this->manageOrder.Menu();
        } else if(choice == "4") {
            this->calTurnover();
            system("pause");
            system("cls");
        } else break;
        
    }

}
void Admin::UpdateAllFiles() {
    Staff::UpdateAllFiles();
    this->manageStaff.UpdateFile();
    //this->manageAccount.UpdateFile();
}
