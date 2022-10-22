#include <iostream>
#include <iomanip>
#include "ListAccount.h"
#include "QLDH.h"
#include "QLDT.h"
#include "QLKH.h"
#include "QLNV.h"
#include <cstring>
#include <cstdlib>
#include <time.h>
using namespace std;

void rand_text(int length, string& result)
{
    int i;
    char char_set[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

    for (i = 0; i < length; i++)
    {
        result[i] = char_set[rand() % sizeof(char_set)];
    }
    // result[length] = 0;
}
using namespace std;

QLDH dh;
QLDT dt;
QLKH kh;
QLNV nv;
ListAccount ac;

void QuanLyNhanVien()
{
    cout << setw(25) << "" << "STAFFS" << "\n\n\n";
    cout << setw(22) << "" << "1. Add staff" << "\n"; // nhap day du thong tin cua staff
    cout << setw(22) << "" << "2. Delete staff" << "\n"; // nhap staffid
    cout << setw(22) << "" << "3. Search staff" << "\n"; // nhap staffid
    cout << setw(22) << "" << "4. Update staff" << "\n"; // nhap day du thong tin cua staff, neu khong doi nhap N/A
    cout << setw(22) << "" << "5. Show all staffs" << "\n\n";
    cout << setw(20) << "" << "Your choice: ";
    int opt3;
    cin >> opt3;
    while (opt3!=1 && opt3!=2 && opt3!=3 && opt3!=4 && opt3!=5)
    {
        cout<<"\t\tPlease re-enter option: ";
        cin>>opt3;
    }
    if (opt3 == 1)
    {
        string MaNV;
        string TenNV;
        string NgaySinh;
        string DiaChiNV;
        string SDTNV;
        string GioiTinh;
        string Luong;
        cout << "Nhap ma nhan vien: ";
        getline(cin, MaNV);
        cout << "Nhap ten nhan vien: ";
        getline(cin, TenNV);
        cout << "Nhap ngay sinh: ";
        getline(cin, NgaySinh);
        cout << "Nhap dia chi nhan vien: ";
        getline(cin, DiaChiNV);
        cout << "Nhap so dien thoai nhan vien: ";
        getline(cin, SDTNV);
        cout << "Nhap gioi tinh: ";
        getline(cin, GioiTinh);
        cout << "Nhap luong: ";
        getline(cin, Luong);
        NhanVien s(MaNV, TenNV, NgaySinh, DiaChiNV, SDTNV, GioiTinh, Luong);
        nv.Add(s);
    }
    if (opt3 == 2 || opt3 == 3 || opt3 == 4)
    {
        string s;
        cout << "StaffID: ";
        cin >> s;
        // Kiểm tra xem mã nhân viên có trong list hay không
        while (nv.CheckMaNV(s)==0)
        {
            cout<<"\t\tPlease re-enter StaffID: ";
            cin>>s;
        }
        if (opt3 == 2)
            nv.Delete(s);
        if (opt3 == 3)
            nv.Search(s);
        if (opt3 == 4)
            nv.Update(s);
    }
    if (opt3 == 5)
        nv.Show();
}

void QuanLyDienThoai()
{
    cout << setw(25) << "" << "PHONES" << "\n\n\n";
    cout << setw(22) << "" << "1. Add phone" << "\n"; // nhap day du thong tin cua phone
    cout << setw(22) << "" << "2. Delete phone" << "\n"; // nhap phoneid
    cout << setw(22) << "" << "3. Search phone" << "\n"; // nhap phoneid
    cout << setw(22) << "" << "4. Show all phones" << "\n\n";
    cout << setw(20) << "" << "Your choice: ";
    int opt3;
    cin >> opt3;
    while (opt3!=1 && opt3!=2 && opt3!=3 && opt3!=4 )
    {
        cout<<"\t\tPlease re-enter option: ";
        cin>>opt3;
    }
    if (opt3 == 1)
    {
        string a, b, c, d, e, g, h;
        int x, y, z;
        cout << "Nhap ma dien thoai: ";
        cin >> a;
        cout << "Nhap ten dien thoai: ";
        cin >> b;
        cout << "Nhap ten hang: ";
        cin >> c;
        cout << "Nhap RAM va ROM: ";
        cin >> d;
        cout << "Nhap ten Chip: ";
        cin >> e;
        cout << "Nhap dung luong pin: ";
        cin >> g;
        cout << "Nhap man hinh: ";
        cin >> h;
        cout << "Nhap gia nhap vao: ";
        cin >> x;
        cout << "Nhap gia ban ra thi truong: ";
        cin >> y;
        cout << "Nhap so luong con lai trong kho: ";
        cin >> z;
        DienThoai s(a, b, c, d, e, g, h, x, y, z);
        dt.Add(s);
    }
    if (opt3 == 2 || opt3 == 3)
    {
        string s;
        cout << "PhoneID: ";
        cin >> s;

        while (dt.CheckMaDT(s)==0)
        {
            cout<<"\t\tPlease re-enter PhoneID: ";
            cin>>s;
        }

        if (opt3 == 2)
            nv.Delete(s);
        if (opt3 == 3)
            nv.Search(s);
    }
    if (opt3 == 4)
        dt.Show2();
}

void QuanLyDonHang()
{
    cout << "\t\t\tTRADES" << endl;
    cout << "\t\t\t1. SearchByMaDH" << endl;
    cout << "\t\t\t2. SearchByMaKH" << endl;
    cout << "\t\t\t3. SearchByMaNV" << endl;
    cout << "\t\t\t4. Show all trades" << endl;
    cout << endl;
    cout << "\t\t\tYour choice: ";
    int opt3;
    cin >> opt3;
    while (opt3!=1 && opt3!=2 && opt3!=3 && opt3!=4 )
    {
        cout<<"\t\tPlease re-enter option: ";
        cin>>opt3;
    }
    if (opt3 == 1)
    {
        string s;
        cout << "Nhap ma don hang: ";
        cin >> s;
        dh.SearchByMaDH(s);
    }
    if (opt3 == 2)
    {
        string s;
        cout << "Nhap ma khach hang: ";
        cin >> s;
        dh.SearchByMaKH(s);
    }
    if (opt3 == 3)
    {
        string s;
        cout << "Nhap ma nhan vien: ";
        cin >> s;
        dh.SearchByMaNV(s);
    }
    if (opt3 == 4)
    {
        dh.Show();
    }
}

// int main()
// {
//     freopen("account.txt", "r", stdin);
//     ListAccount listAccount;
//     listAccount.SetData();
//     listAccount.ShowData();
// }

int main()
{
    // choose role
    while (true)
    {
        string enter1;  // Enter1: Thoát khỏi vòng lặp 
        cout << setw(25) << ""
             << "NH MOBILE STORE"
             << "\n\n\n";
        cout << setw(20) << ""
             << "You are: "
             << "\n\n";
        cout << setw(22) << ""
             << "1. Staff"
             << "\n\n";
        cout << setw(22) << ""
             << "2. Customer"
             << "\n\n";

        int opt1;
        cin >> opt1;
        while (opt1 != 1 && opt1 != 2)
        {
            cout << "Please re-enter!" << endl;
            cin >> opt1;
        }
        // can xu li role khong hop le

        if (opt1 == 1)
        {
            // enter staff account
            string username, password;
            cout << setw(20) << ""
                 << "Enter your account"
                 << "\n\n";
            cout << setw(22) << ""
                 << "Username: ";
            cin >> username;
            cout << "\n";
            cout << setw(22) << ""
                 << "Password: ";
            cin >> password;
            cout << "\n";
            // can xu li dung sai tai khoan
            while (ac.CheckAccount(username, password) == 0)
            {
                cout << "Please re-enter your username and password " << endl;
                cout << setw(22) << ""
                     << "Username: ";
                cin >> username;
                cout << "\n";
                cout << setw(22) << ""
                     << "Password: ";
                cin >> password;
                cout << "\n";
            }
            if (ac.CheckAccount(username, password) == 1)
            {
                // admin route--------------------------------------------------
                cout << setw(20) << ""
                     << "Choose what you want to manage"
                     << "\n\n";
                cout << setw(22) << ""
                     << "1. Staffs"
                     << "\n";
                cout << setw(22) << ""
                     << "2. Phones"
                     << "\n";
                cout << setw(22) << ""
                     << "3. Trades"
                     << "\n\n";
                cout << setw(20) << ""
                     << "Your choice: ";
                int opt2;  // Lua chon thu 2
                cin >> opt2;
                while (opt2 != 1 && opt2 != 2 && opt2 != 3)
                {
                    cout << "Please re-enter option!" << endl; // Tieng anh
                    cin>>opt2;
                }
                if (opt2 == 1)
                {
                    QuanLyNhanVien();
                }
                if (opt2 == 2)
                {
                    QuanLyDienThoai();
                }
                if (opt2 == 3)
                {
                    QuanLyDonHang();
                }
            }
            else if (ac.CheckAccount(username, password) == 2)
            {
                int opt2;
                cin >> opt2;
                while (opt2 != 1 && opt2 != 2)
                {
                    cout << "Please re-enter option!" << endl; // Tieng anh
                }
                if (opt2 == 1)
                {
                    QuanLyDienThoai();
                }
                if (opt2 == 2)
                {
                    QuanLyDonHang();
                }
            }
        }

        else if (opt1 == 2)
        {
            string Name;
            string ID;
            string PhoneNumber;
            string Address;

            while (true)
            {
                cout << "\t\tEnter your information" << endl;
                cout << "\t\t\tName: ";
                getline(cin,Name);
                cout << "ID: ";
                getline(cin,ID);
                // while (kh.Check(ID)==1)
                // {
                //     cout<<"Please re-enter ID"<<endl;
                //     cout<<"ID: ";
                //     cin>>ID;
                // }
                cout << "Phone number: ";
                getline(cin,PhoneNumber);
                cout << "Address";
                getline(cin, Address);
                cout << "\t\tEnter B to go back" << endl;
                cout << "\t\tEnter C to continue" << endl;
                cout << "\t\tYour option:";
                string enter;
                cin >> enter;
                while (enter != "B" && enter != "C")
                {
                    cout << "Please re-enter: " << endl;
                    cin >> enter;
                }
                if (enter=="B") continue; // Chỉnh sửa lại thông tin
                if (enter == "C")
                    break;  // Thoát khỏi vòng lặp vì nhập đúng thông tin
            
            }

            cout << "\t\tChoose what you want to purchase" << endl;
            dt.Show1();
            // Khách hàng xem xong danh sách điện thoại sẽ mua tiếp hay ko
            cout << endl;
            cout << "\t\tEnter B to go back" << endl; // Trường hợp xem xong chán không biết mua gì
            cout << "\t\tEnter C to continue buying" << endl;

            //enter1: đến cái bảng đầu tiên
            cin >> enter1;  
            while (enter1 != "B" && enter1 != "C")
            {
                cout << "Please re-enter: " << endl;
                cin >> enter1;
            }
            if (enter1 == "B")
                break;
            DonHang s;
            int TongTien=0;
            while (true)
            {
                // Trường hợp chắc chắn mua
                // Sẽ thêm 1 đơn hàng
               
                cout << "\t\tYour choice: ";
                int opt2;
                cin >> opt2;
                while (opt2 < 0 || opt2 >= dt.Getlength())
                {
                    cout << "\t\tPlease re-enter option" << endl;
                }
                string MaDT=dt.LayMaDT(opt2);
                int sl;
                cin >> sl;
                while (dt.CheckSL(opt2, sl) == false || sl < 0)
                {
                    cout << "\t\tPlease re-enter amount" << endl;
                    cin >> sl;
                }
                DanhSachMua x(MaDT,sl);
                s.AddDSM(x);
                // Tinh tong tien
                TongTien+=dt.LayGiaBan(opt2)*sl;
                string enter2;   // Enter2: Tiếp tục mua hay không
                cout << "Enter D to finish" << endl;
                cout << "Enter C to continue buying" << endl; // Tiếng anh
                cout << "\t\tYour option:";
                cin >> enter2;
                while (enter2 != "D" && enter2 != "C")
                {
                    cout << "Please re-enter: " << endl;
                    cin >> enter2;
                }
                
                if (enter2 == "D")
                {

                    //MaDH: random
                    //MaKH=ID
                    //MaNV: tự nhập
                    //Danh sách mua: thêm vào
                    //Ngày mua: tự nhập
                    // Tổng tiền: tính

                    string MaDH;  // Tu dong cung cap ma don hang
                    srand(time(NULL));
                    rand_text(9, MaDH);
                    string MaKH = ID;  // MaKH la CCCD
                    string MaNV; // Mã nhân viên tự nhập
                    cin >> MaNV;
                    while (nv.CheckMaNV(MaNV) == 0) // 0: Khong co ma nhan vien  trong do
                    {
                        cout << "Please re-enter: ";
                        cin >> MaNV;
                    }
                    string NgayMua;
                    cin>>NgayMua;

                    s.SetMaDH(MaDH);
                    s.SetMaKH(MaKH);
                    s.SetMaNV(MaNV);
                    s.SetNgayMua(NgayMua);
                    s.SetTongTien(TongTien);

                    dh.Add(s); // Thêm đơn hàng vào quản lí đơn hàng
                    break; // thoát khỏi vòng true
                    
                }
                
            }
            s.Show();
            
            // In ra hóa đơn
            
        }
        string enter3;
        cin>>enter3;
        cout<<"Enter D to finish"<<endl;
        cout<<"Enter C to continue"<<endl;
        cout<<"Your choice: ";
        cin>>enter3;
        while (enter3 != "D" && enter3 != "C")
        {
            cout << "Please re-enter: " << endl;
            cin >> enter3;
        }
        if (enter3=="D") break; // Chỉnh sửa lại thông tin
        if (enter3 == "C") continue;  
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
