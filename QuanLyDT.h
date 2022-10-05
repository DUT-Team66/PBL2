#ifndef _QUANLYDT_
#define _QUANLYDT_

#include "QuanLy.h"
#include "DienThoai.h"
template <typename type>

class QLDT : public QuanLy
{
    private:
        DienThoai *dh;
        int n;
    public:
        QLDT();
        ~QLDT();

        void Add(DienThoai );
        void Show();
        void Search(string);  //Search
        void Update(string);
        void Delete(string);
};


#endif