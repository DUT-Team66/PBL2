#include "QuanLy.h"
#include "NhanVien.h"
template <typename type>

class QLNV : public QuanLy
{
    private:
        NhanVien *dt;
        int n;
    public:
        QLNV();
        ~QLNV();

        void Add(NhanVien);
        void Insert(NhanVien, string);
        void Show();
        string IndexOf(string);  //Search
        void Update(string);
        void Delete(string);
};