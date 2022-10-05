#ifndef _QUANLIDH_
#define _QUANLIDH_

#include "QuanLy.h"
#include "DonHang.h"
template <typename type>


class QLDH : public QuanLy
{
    private:
        DonHang *dh;
        int n;
    public:
        QLDH();
        ~QLDH();

        void Add(DonHang );
        void Show();
        string Search(string);  
        void Update(string);
        void Delete(string);
};

#endif