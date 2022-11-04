#ifndef _GOODS_
#define _GOODS_
#include <string>
using namespace std;
class Goods {
    private:
        string phoneID;
        int amount;
        Goods *next;
    public:
        Goods();
        Goods(string, int);
        ~Goods();
        const string& getPhoneID() const;
        const int& getAmount() const;
        void setAmount(const int&);
        void show();
        void setNextGoods(Goods*&);
        Goods*& getNextGoods();
};





#endif