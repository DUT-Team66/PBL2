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
            void Add(T);
            void Show();
            void Search(T);
            void Update(T);
            void Delete(T);
    };

#endif
/*
    QuanLy<DienThoai> QuanLyDienThoai


*/