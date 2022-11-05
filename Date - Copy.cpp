#include "Date.h"
#include <iostream>
using namespace std;
Date::Date()
{
    this->day = 0;
    this->month = 0;
    this->year = 0;
}
Date::Date(int x, int y, int z)
: day(x), month(y), year(z)
{

}
Date::Date(const Date& x)
{
    this->day=x.day;
    this->month=x.month;
    this->year=x.year;
}
Date::~Date()
{

}
const int& Date::getDay() const {
    return this->day;
}
const int& Date::getMonth() const {
    return this->month;
}
const int& Date::getYear() const {
    return this->year;
}
ostream& operator<<(ostream& o, const Date& p) 
{
    o<<p.day<<"/"<<p.month<<"/"<<p.year; 
    return o; 
}
istream& operator>>(istream& in, Date& p)
{
    cout<<endl<<"Day: ";
    in>>p.day;
    cout<<"Month: ";
    in>>p.month;
    cout<<"Year: ";
    in>>p.year;
    return in;
}