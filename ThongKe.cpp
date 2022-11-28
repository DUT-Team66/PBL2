#include "ThongKe.h"
#define ll long long

ThongKe::ThongKe(Date date, ll von, ll doanhthu, ll loinhuan) : date(date), von(von), doanhThu(doanhthu), loiNhuan(loinhuan) {

}
Date ThongKe::getDate() {
    return this->date;
}
void ThongKe::setDate(Date date) {
    this->date = date;
}
long long ThongKe::getDoanhThu() {
    return this->doanhThu;
}
void ThongKe::setDoanhThu(ll doanhthu) {
    this->doanhThu = doanhthu;
}
ll ThongKe::getVon() {
    return this->von;
}
void ThongKe::setVon(ll von) {
    this->von = von;
}
ll ThongKe::getLoiNhuan() {
    return this->loiNhuan;
}
void ThongKe::setLoiNhuan(ll loinhuan) {
    this->loiNhuan = loinhuan;
}
ll ThongKe::getTongLuongNV() {
    return this->tongLuongNV;
}
// void ThongKe::setTongLuongNV(ll tongluongnv) {
//     this->tongLuongNV = tongluongnv;
// } 
ll ThongKe::getChiPhiKhac() {
    return this->chiPhiKhac;
}
// void ThongKe::setChiPhiKhac(ll chiphikhac) {
//     this->chiPhiKhac = chiphikhac;
// }