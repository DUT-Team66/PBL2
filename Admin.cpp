#include "Admin.h"
#include <iomanip>
#include "Table.h"
#include <vector>
#include <fstream>
#include <windows.h>
using namespace std;

Admin::Admin() {

}
Admin::~Admin() {
    
}
Admin::Admin(string name, string id, string gender, string dob, string phoneNumber, string address, string username, string password) : Staff(name,id,gender,dob,phoneNumber,address,username,password) {
    this->salary = 15000000;
}
void Admin::setStaffManager(StaffManager& staffManager) {
    this->manageStaff = &staffManager;
}
const StaffManager& Admin::getStaffManager() const {
    return *(this->manageStaff);
}
// void Admin::setAccountManager(const AccountManager& accountManager) {
//     this->manageAccount = accountManager;
//}


void Admin::ShowThongKe()
{   

    cout << setw(30) << "" << topLeftCorner << line(12); // date
    cout << topMid << line(16); // von
    cout << topMid << line(16); // doanh thu
    cout << topMid << line(16); // loi nhuan
    cout << topRightCorner << "\n";

    cout << setw(30) << "" << col << setw(4) << "" << setw(8) << left << "Thang";
    cout << col << setw(6) << "" << setw(10) << left << "Von";
    cout << col << setw(3) << "" << setw(13) << left << "Doanh thu";
    cout << col << setw(3) << "" << setw(13) << left << "Loi nhuan";
    cout << col << "\n";
    
    for(int i = 0; i < thongKe.size(); ++i) {
        cout << setw(30) << "" << leftSide << line(12);
        cout << midMid << line(16);
        cout << midMid << line(16);
        cout << midMid << line(16);
        cout << rightSide << "\n";

        string datestr = to_string(this->thongKe[i].getDate().getMonth()) + "/" + to_string(this->thongKe[i].getDate().getYear());
        cout << setw(30) << "" << col << setw((12 - datestr.length())/2) << "" << setw(12 - (12 - datestr.length())/2) << datestr;
        cout << col << setw((16 - to_string(this->thongKe[i].getVon()).length())/2) << "" << setw(16 - (16 - to_string(this->thongKe[i].getVon()).length())/2) << left << this->thongKe[i].getVon();
        cout << col << setw((16 - to_string(this->thongKe[i].getDoanhThu()).length())/2) << "" << setw(16 - (16 - to_string(thongKe[i].getDoanhThu()).length())/2) << left << thongKe[i].getDoanhThu(); 
        if(this->thongKe[i].getLoiNhuan() <= 0) cout << col << setw(8) << "" << setw(8) << left << 0;
        else cout << col << setw((16 - to_string(this->thongKe[i].getLoiNhuan()).length())/2) << "" << setw(16 - (16 - to_string(thongKe[i].getLoiNhuan()).length())/2) << left << thongKe[i].getLoiNhuan(); 
        cout << col << "\n";
    }
    cout << setw(30) << "" << botLeftCorner << line(12);
    cout << botMid << line(16);
    cout << botMid << line(16);
    cout << botMid << line(16);
    cout << botRightCorner << "\n";
    
}
void Admin::Menu() {
    while(true) {
        string choice;
        while(true) {
            std::system("cls");
            std::cout << setw(50) << "" << topLeftCorner << line(7) << topRightCorner << "\n";
            std::cout << setw(50) << "" << col << " ADMIN " << col << "\n";
            std::cout << setw(50) << "" << botLeftCorner << line(7) << botRightCorner << "\n\n";
            cout << setw(45) << "" << "Choose what you want to manage" << "\n\n";
            cout << setw(47) << "" << "1. Staffs" << "\n";
            cout << setw(47) << "" << "2. Phones" << "\n";
            cout << setw(47) << "" << "3. Trades" << "\n";
            cout << setw(47) << "" << "4. Customers" << "\n";
            cout << setw(47) << "" << "5. Import phones" << "\n";
            cout << setw(47) << "" << "6. Revenue/Expense statistics" << "\n"; // thống kê thu chi
            cout << setw(47) << "" << "7. Go back" << "\n\n";
            cout << setw(45) << "" << "Your choice: ";
            cin >> choice;
            if(choice != "1" && choice != "2" && choice != "3" && choice != "4" && choice != "5" && choice != "6" && choice != "7" ){
                cout << setw(45) << "" << "Invalid choice, please re-enter!\n";
                system("pause");
                system("cls"); 
            } else break;
        }
        
        if(choice == "1") {
            this->manageStaff->Menu();
        } else if(choice == "2") {
            this->managePhone->Menu();
        } else if(choice == "3") {
            this->manageOrder->Menu();
        } else if(choice == "4") {
            this->manageCustomer->Menu();
        } else if(choice == "5") {
            this->Import();
        } else if(choice == "6") {
            this->ShowThongKe();
            system("pause");
            system("cls");
        } else break;
        
    }

}
void Admin::Import() {

    string confirm; cout << setw(45) << "" << "Confirm (Y/N): ";
    cin >> confirm;
    if(confirm == "N") {
        return;
    } else if(confirm != "Y") {
        cout << setw(45) << "" << "Invalid choice!\n";
        std::system("pause");
        return;
    }
    long long total = 0;
    //cout << this->managePhone.GetLength() << "\n";
    for(int i = 0; i < this->managePhone->GetLength(); ++i) {
        total += (100 - this->managePhone->getRemainingAmount(i))* this->managePhone->getEntryPrice(i);
        //cout << i << "\n";
        this->managePhone->setRemainingAmount(i,this->managePhone->getRemainingAmount(i) - 100);
    }
    //cout << 1 << "\n";
    time_t now = time(0);
    // convert now to string form
    tm *ltm = localtime(&now);

    if(this->thongKe[this->thongKe.size()-1].getDate().getMonth() != 1 + ltm->tm_mon) {
        this->thongKe.push_back(ThongKe(Date(ltm->tm_mday,ltm->tm_mon + 1, 1900 + ltm->tm_year),total,0,0));
    } else {
        this->thongKe[this->thongKe.size()-1].setVon(this->thongKe[this->thongKe.size()-1].getVon() + total);
    }


    //cout << 2 << "\n";

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 10);
    cout << "\n";
    cout << setw(45) << "" << "IMPORT SUCCESSFULLY!" << "\n";
    SetConsoleTextAttribute(hConsole, 7);
    std::system("pause");
    std::system("cls");
}
void Admin::LoadThongKe() {
    fstream readfile("ThongKe.txt", ios::in);
    string tmp;
    while(getline(readfile, tmp)) {
        int i = 0;
        int month = 0, year = 0; long long von = 0, doanhthu = 0, loinhuan = 0;
        
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
            von = von*10 + tmp[i] - 48;
            ++i;
        }
        ++i;
        while(tmp[i] != '/') {
            doanhthu = doanhthu*10 + tmp[i] -48;
            ++i;
        }
        ++i;
        if(tmp[i] != '-') {
            while(tmp[i] != '/') {
                loinhuan = loinhuan*10 + tmp[i] - 48;
                ++i;
            }
        } else {
            ++i;
            while(tmp[i] != '/') {
                loinhuan = loinhuan*10 + tmp[i] - 48;
                ++i;
            }
            loinhuan *= -1;
        }
        ++i;
        this->thongKe.push_back(ThongKe(Date(0,month, year),von, doanhthu, loinhuan));
    }
    readfile.close();
}
void Admin:: UpdateThongKe() {
    fstream editfile("ThongKe.txt", ios::out);
    int d = 0;
    for(int i = 0; i < this->thongKe.size(); ++i) {
        string s = to_string(thongKe[i].getDate().getMonth()) + "-" + to_string(thongKe[i].getDate().getYear()) + "/" + to_string(thongKe[i].getVon()) + "/" + to_string(thongKe[i].getDoanhThu()) + "/" + to_string(thongKe[i].getLoiNhuan()) + "/";
        if(d != this->thongKe.size() - 1) {
            editfile << s << "\n";
        } else editfile << s;
        ++d;
    }
    editfile.close();

}
void Admin::UpdateDoanhThuLoiNhuan(Order& order) {
    this->thongKe[thongKe.size()-1].setDoanhThu(this->thongKe[thongKe.size()-1].getDoanhThu() + order.getTotalPrice());
    this->thongKe[thongKe.size()-1].setLoiNhuan(this->thongKe[this->thongKe.size()-1].getDoanhThu() - this->thongKe[this->thongKe.size()-1].getVon() - this->thongKe[this->thongKe.size()-1].getTongLuongNV() - this->thongKe[this->thongKe.size()-1].getChiPhiKhac());
}
void Admin::UpdateAllFiles() {
    Staff::UpdateAllFiles();
    this->manageStaff->UpdateFile();
    this->UpdateThongKe();
    //this->manageAccount.UpdateFile();
}
