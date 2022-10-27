#include "Admin.h"
#include <iomanip>
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
void Admin::calTurnover() {
    int month, year;
    cout << "Enter month: "; cin >> month;
    cout << "Enter year: "; cin >> year;
    long long totalTurnover = 0;
    for(int i = 0; i < this->manageOrder.GetLength(); ++i) {
        if(this->manageOrder.GetMonth(i) == month && this->manageOrder.GetYear(i) == year) {
            totalTurnover += this->manageOrder.GetTotalPrice(i);
        }
    }
    cout << "Turnover in " << month << "/" << year << " is " << totalTurnover << "\n";  
}
void Admin::Menu() {
    while(true) {
        int choice;
        while(true) {
            cout << setw(20) << "" << "Choose what you want to manage" << "\n\n";
            cout << setw(22) << "" << "1. Staffs" << "\n";
            cout << setw(22) << "" << "2. Phones" << "\n";
            cout << setw(22) << "" << "3. Trades" << "\n";
            cout << setw(22) << "" << "4. Calculate turnover" << "\n";
            cout << setw(22) << "" << "5. Go back" << "\n\n";
            cout << setw(20) << "" << "Your choice: ";
            cin >> choice;
            if(choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5) {
                cout << "Invalid choice, please re-enter!\n";
                system("pause");
                system("cls"); 
            } else break;
        }
        
        if(choice == 1) {
            this->manageStaff.Menu();
        } else if(choice == 2) {
            this->managePhone.Menu();
        } else if(choice == 3) {
            this->manageOrder.Menu();
        } else if(choice == 4) {
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
