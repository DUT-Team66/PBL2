#include "DanhSachMua.h"
#include <string>
using namespace std;
class DonHang
{
    private: 
        string MaDH;
        string MaKH;
        string MaNV;
        DanhSachMua* DSM;
        int n; // Số các danh sách mua
        string NgayMua;
        int TongTien;
    public:
        DonHang();
        ~DonHang();
        void SetMaDH(const string& );
        const string& GetMaDH();

        
        void SetDSM(const DanhSachMua& );
        const string& GetDSM();
        void SetMaKH(const string& );
        const string& GetMaKH();
        void SetMaNV(const string& );
        const string& GetMaNV();
        void SetNgayMua(const string& );
        const string& GetNgayMua();
        void Show();
};
