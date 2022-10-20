#include "DonHang.h"
class QLDH
{
    private: 
        DonHang *p;
        int n;
    public:
        //Khong co SV
        QLDH();
        ~QLDH();
        void SearchByMaDH(string);
        void SearchByMaKH(string);
        void SearchByMaNV(string);
        void Add(const DonHang& s);
        void Show();
};
