#include "NhanVien.h"
class QLNV
{
    private: 
        NhanVien *p;
        int n;
    public:
        //Khong co SV
        QLNV();
        ~QLNV();
        void Add(const NhanVien& s);
        void Delete(string);
        void Search(string);

        int IndexOf(string);
        void Update(string);
        void Show();
};
