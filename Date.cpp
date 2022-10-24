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
ostream& operator<<(ostream& o, const Date& p) 
{
    o<<p.day<<"/"<<p.month<<"/"<<p.year; 
    return o; 
}
istream& operator>>(istream& in, Date& p)
{
    cout<<endl<<"\t\tDay: ";
    in>>p.day;
    cout<<"\t\tMonth: ";
    in >> p.month;
    cout<<"\t\tYear: ";
    in>>p.year;
    return in;
}