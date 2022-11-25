#ifndef _THONGKE_
#define _THONGKE_
#include "Date.h"
#include <iostream>
using namespace std;
class ThongKe {
    private:
        int month, year;
        long long doanhThu;
        long long von;
        long long loiNhuan;
        const long long tongLuongNV = 10*5000000;
        const long long chiPhiKhac = 10000000;
    public:
        ThongKe(int, int, long long,long long,long long);
        int getMonth();
        void setMonth(int);
        int getYear();
        void setYear(int);
        long long getDoanhThu();
        void setDoanhThu(long long);
        long long getVon();
        void setVon(long long);
        long long getLoiNhuan();
        void setLoiNhuan(long long);
        // long long getTongLuongNV();
        // void setTongLuongNV(long long);
        // long long getChiPhiKhac();
        // void setChiPhiKhac(long long);

};

#endif