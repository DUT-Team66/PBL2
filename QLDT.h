#include "DienThoai.h"
class QLDT
{
    private: 
        DienThoai *p;
        int n;
    public:
        //Khong co SV
        QLDT();
        ~QLDT();
        int Getlength();
        void Add(const DienThoai& s);
        void Delete(string);
        void Search(string);
        void Show();
};
