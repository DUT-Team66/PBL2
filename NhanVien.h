#include <string>
#include <iostream>
using namespace std;

class NhanVien
{
    private: 
        string MaNV;
        string TenNV;
        string NgaySinh;
        string DiaChiNV;
        string SDTNV;
        string GioiTinh;
        string Luong;    
    public:

        NhanVien();
        NhanVien(string, string, string, string, string, string,string);
        ~NhanVien();
        void SetMaNV(const string& );
        const string& GetMaNV();
        void SetTenNV(const string& );
        const string& GetTenNV();
        void SetNgaySinh(const string& );
        const string& GetNgaySinh();
        void SetDiaChiNV(const string& );
        const string& GetDiaChiNV();
        void SetSDTNV(const string& );
        const string& GetSDTNV();
        void SetGioiTinh(const string& );
        const string& GetGioiTinh();
        void SetLuong(const string& );
        const string& GetLuong();
        void Show();
};
