#ifndef _DIENTHOAI_
#define _DIENTHOAI_

#include <string>
#include <iostream>
using namespace std;
class DienThoai
{
    private: 
        string MaDT;
        string TenDT;
        string TenHang;

        
        string RAM_ROM; // GB
        
        string Chip;
        string Pin; // mAh
        string ManHinh; // 
        int GiaNhap;
        int GiaBan;
        int SoLuongConLai   ;
    public:

        DienThoai();
        DienThoai(string,string,string,string,string,string,string,int, int, int);
        ~DienThoai();

        /*
        void SetMaDT(const string& );
        const string& GetMADT();
        void SetTenDT(const string& );
        const string& GetTenDT();
        void SetTenHang(const string& );
        const string& GetTenHang();
        void SetGia(const int& );
        const int& GetGia();
        void SetLoai(const string& );
        const string& GetLoai();
        void SetRAM(const string& );
        const string& GetRAM();
        void SetROM(const string& );
        const string& GetROM();
        void SetPin(const string& );
        const string& GetPin();
        void SetSac(const string& );
        const string& GetSac();
        void SetTinhNang(const string& );
        const string& GetTinhNang();
        void SetSL(const int& );
        const int& GetSL();
        */
       void Show();


};


#endif