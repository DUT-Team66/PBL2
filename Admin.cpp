#include "Admin.h"
#include <iomanip>
using namespace std;
void Admin::calTurnover() {
    
}
void Admin::Menu() {
    while(true) {
        int choice;
        while(true) {
            cout << setw(20) << "" << "Choose what you want to manage" << "\n\n";
            cout << setw(22) << "" << "1. Staffs" << "\n";
            cout << setw(22) << "" << "2. Phones" << "\n";
            cout << setw(22) << "" << "3. Trades" << "\n";
            cout << setw(22) << "" << "4. Go back" << "\n\n";
            cout << setw(20) << "" << "Your choice: ";
            cin >> choice;
            if(choice != 1 && choice != 2 && choice != 3 && choice != 4) {
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
        } else {
            break;
        }
    }
}
