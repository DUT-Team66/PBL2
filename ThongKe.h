#ifndef _THONGKE_
#define _THONGKE_
#include "Date.h"
#include <iostream>
using namespace std;
class ThongKe {
    private:
        Date date;
        long long von;
        long long doanhThu;
        long long loiNhuan;
        long long tongLuongNV = 10*5000000;
        long long chiPhiKhac = 10000000;
    public:
        ThongKe(Date, long long,long long,long long);
        Date getDate();
        void setDate(Date);
        long long getDoanhThu();
        void setDoanhThu(long long);
        long long getVon();
        void setVon(long long);
        long long getLoiNhuan();
        void setLoiNhuan(long long);
        long long getTongLuongNV();
        // void setTongLuongNV(long long);
        long long getChiPhiKhac();
        // void setChiPhiKhac(long long);

};

#endif