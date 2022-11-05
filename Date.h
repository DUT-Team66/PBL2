#ifndef _DATE_
#define _DATE_

#include <iostream>
using namespace std;
class Date
{
    private:
        int day;
        int month;
        int year;
    public:
        Date();
        Date(int, int , int );
        Date (const Date&);
        ~Date();
        const int& getDay() const;
        const int& getMonth() const;
        const int& getYear() const;
        friend ostream& operator<<(ostream &, const Date&);
        friend istream& operator>>(istream& , Date& );
};
#endif 