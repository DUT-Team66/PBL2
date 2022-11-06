#ifndef _GOODS_
#define _GOODS_

#include <string>
using namespace std;
class Goods
{
    private:
        string phoneID;
        int amount;
    public:
        Goods();
        Goods(string,int);
        ~Goods();
        const string& getPhoneID() const;
        void setPhoneID(const string&);
        const int& getAmount() const;
        void setAmount(const int&);
        void show();
};
#endif