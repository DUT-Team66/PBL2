

#include <string>
#include <iostream>
using namespace std;

class NhanVien
{
    private: 
        string manv;
        string HoTen;
        string NgaySinh;
        string DiaChi;
        string SDT;
        string GioiTinh;
        string SoCMDN;
        string luong; // luong moi nhan vien khac nhau dua tren so dien thoai ban duoc
    public:

        NhanVien();
        ~NhanVien();
        /*
        void SetMaNV(const string& );
        const string& GetMANV();
        void SetHoTen(const string& );
        const string& GetHoTen();
        void SetNgaySinh(const string& );
        const string& GetNgaySinh();
        void SetDiaChi(const string& );
        const string& GetDiaChi();
        void SetSDT(const string& );
        const string& GetSDT();
        void SetGioiTinh(const string& );
        const string& GetGioiTinh();
        void SetSoCMND(const string& );
        const string& GetSoCMND();
        */
       void Show();
};
