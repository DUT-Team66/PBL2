#ifndef _CART_
#define _CART_
#include "Goods.h"

class Cart {
    private:
        Goods *p;
    public:
        Cart();
        ~Cart();
        Goods*& getGoods();
        
        bool searchCart(string);
        void add(Goods*&); // thêm mới 
        void add(string, int); // cộng dồn


        //void Show();

};


#endif