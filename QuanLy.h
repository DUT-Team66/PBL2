#ifndef _QUANLY_
#define _QUANLY_
#include <string>
using namespace std;

template <typename T>
    class QuanLy {
        private : 
            T* list;
            int length;
        public:

            QuanLy(T*, int);
            ~QuanLy();
            void Add();
            void Show();
            void Search();
            void Update();
            void Delete();
    };

#endif
/*
    QuanLy<DienThoai> QuanLyDienThoai


*/
