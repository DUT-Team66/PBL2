#include <string>
#include <iostream>
using namespace std;
class DienThoai
{
    private: 
        string MaDT;//a
        string TenDT;//b
        string Hang;//c
        string RAM_ROM; // d
        string Chip;//e
        string Pin; // g
        string ManHinh; //h 
        int GiaNhap;//x
        int GiaBan;//y
        int SoLuong;//z
    public:
        DienThoai();
        DienThoai(string, string, string, string,string, string, string, int, int, int);
        ~DienThoai();
        void SetMaDT(const string& );
        const string& GetMaDT();

        void SetTenDT(const string& );
        const string& GetTenDT();


        void SetHang(const string& );
        const string& GetHang();

        void SetRAM_ROM(const string& );
        const string& GetRAM_ROM();


        void SetChip(const string& );
        const string& GetChip();

        void SetPin(const string& );
        const string& GetPin();

        void SetManHinh(const string& );
        const string& GetManHinh();

        void Show1();  // Cua khach hang
        void Show2();   // Cua nhan vien va quan li

};
