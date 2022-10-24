#include <string>
#include <iostream>
using namespace std;

class KhachHang
{
    private: 
        string MaKH;
        string TenKH;
        string SDTKH;
        string DiaChiKH;
    
    public:

        KhachHang();
        ~KhachHang();
        void SetMaKH(const string& );
        const string& GetMaKH();
        void SetTenKH(const string& );
        const string& GetTenKH();
        void SetSDTKH(const string& );
        const string& GetSDTKH();
        void SetDiaChiKH(const string& );
        const string& GetDiaChiKH();
        void Show();
};
