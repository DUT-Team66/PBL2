#include "Admin.h"
#include <iomanip>
#include "Table.h"
#include <vector>
#include <fstream>
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
long long Admin::Import() {
    long long total = 0;
    for(int i = 1; i <= this->managePhone.GetLength(); ++i) {
        total += (100 - this->managePhone.getRemainingAmount(i)) * this->managePhone.getPhonePrice(i);
    }
    return total;
}
void Admin::AddThongKe() {
    ThongKe tk(0,0,0,0,0);
    long long dt = 0;
    
}
void Admin::ShowThongKe()
{   

    cout << topLeftCorner << line(12); // date
    cout << topMid << line(13); // von
    cout << topMid << line(13); // doanh thu
    cout << topMid << line(13); // loi nhuan
    cout << topRightCorner << "\n";

    cout << col << setw(4) << "" << setw(8) << left << "Thang";
    cout << col << setw(5) << "" << setw(8) << left << "Von";
    cout << col << setw(2) << "" << setw(11) << left << "Doanh thu";
    cout << col << setw(2) << "" << setw(11) << left << "Loi nhuan";
    cout << col << "\n";
    
    for(int i = 0; i < thongKe.size(); ++i) {
        cout << leftSide << line(12);
        cout << topMid << line(13);
        cout << topMid << line(13);
        cout << topMid << line(13);
        cout << rightSide << "\n";

        string datestr = to_string(thongKe[i].getMonth()) + "/" + to_string(thongKe[i].getYear());
        cout << col << setw((12 - datestr.length())/2) << "" << setw(12 - (12 - datestr.length())/2) << datestr;
        cout << col << setw((13 - to_string(thongKe[i].getVon()).length())) << "" << setw(13 - (13 - to_string(thongKe[i].getVon()).length())) << thongKe[i].getVon();
        cout << col << setw((13 - to_string(thongKe[i].getDoanhThu()).length())) << "" << setw(13 - (13 - to_string(thongKe[i].getDoanhThu()).length())) << thongKe[i].getDoanhThu(); 
        cout << col << setw((13 - to_string(thongKe[i].getDoanhThu()).length())) << "" << setw(13 - (13 - to_string(thongKe[i].getDoanhThu()).length())) << thongKe[i].getDoanhThu(); 
        cout << col << "\n";
    }
    cout << botLeftCorner << line(12);
    cout << botMid << line(13);
    cout << botMid << line(13);
    cout << botMid << line(13);
    cout << botRightCorner << "\n";
    
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
            cout << setw(47) << "" << "4. Customers" << "\n";
            cout << setw(47) << "" << "5. Revenue/Expense statistics" << "\n"; // thống kê thu chi
            cout << setw(47) << "" << "6. Go back" << "\n\n";
            cout << setw(45) << "" << "Your choice: ";
            cin >> choice;
            if(choice != "1" && choice != "2" && choice != "3" && choice != "4" && choice != "5" && choice != "6") {
                cout << setw(45) << "" << "Invalid choice, please re-enter!\n";
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
            this->manageCustomer.Menu();
        } else if(choice == "5") {
            this->ShowThongKe();
            system("pause");
            system("cls");
        } else break;
        
    }

}
void Admin::LoadThongKe() {
    fstream readfile("Order.txt", ios::in);
    string tmp;
    while(getline(readfile, tmp)) {
        int i = 0;
        int month, year; long long von, doanhthu, loinhuan;
        while(tmp[i] != '-') {
            month = month*10 + tmp[i] - 48;
            ++i;
        }
        ++i;
        while(tmp[i] != '/') {
            year = year*10 + tmp[i] - 48;
            ++i;
        }
        ++i;
        while(tmp[i] != '/') {
            von = von*10 + tmp[i]-48;
            ++i;
        }
        ++i;
        while(tmp[i] != '/') {
            doanhthu = doanhthu*10 + tmp[i] -48;
            ++i;
        }
        ++i;
        while(tmp[i] != '/') {
            loinhuan = loinhuan*10 + tmp[i] - 48;
            ++i;
        }
        ++i;
        thongKe.push_back(ThongKe(month, year, von, doanhthu, loinhuan));
    }
}
void Admin:: UpdateThongKe() {
    fstream editfile("ThongKe.txt", ios::out);
    int d = 0;
    for(int i = 0; i < this->thongKe.size(); ++i) {
        string s = to_string(thongKe[i].getMonth()) + "-" + to_string(thongKe[i].getYear()) + "/" + to_string(thongKe[i].getVon()) + "/" + to_string(thongKe[i].getDoanhThu()) + "/" + to_string(thongKe[i].getLoiNhuan()) + "/";
        if(d != this->thongKe.size() - 1) {
            editfile << s << "\n";
        } else editfile << s;
        ++d;
    }
    editfile.close();

}
void Admin::UpdateAllFiles() {
    Staff::UpdateAllFiles();
    this->manageStaff.UpdateFile();
    this->UpdateThongKe();
    //this->manageAccount.UpdateFile();
}
