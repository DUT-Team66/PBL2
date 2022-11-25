#include "ThongKe.h"
#define ll long long

ThongKe::ThongKe(int month, int year, ll von, ll doanhthu, ll loinhuan) : month(month), year(year), doanhThu(doanhthu), von(von), loiNhuan(loinhuan){

}
int ThongKe::getMonth() {
    return this->month;
}
void ThongKe::setMonth(int month) {
    this->month = month;
}
int ThongKe::getYear() {
    return this->year;
}
void ThongKe::setYear(int year) {
    this->year = year;
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
// ll ThongKe::getTongLuongNV() {
//     return this->tongLuongNV;
// }
// void ThongKe::setTongLuongNV(ll tongluongnv) {
//     this->tongLuongNV = tongluongnv;
// } 
// ll ThongKe::getChiPhiKhac() {
//     return this->chiPhiKhac;
// }
// void ThongKe::setChiPhiKhac(ll chiphikhac) {
//     this->chiPhiKhac = chiphikhac;
// }