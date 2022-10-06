#ifndef _QUANLY_
#define _QUANLY_
#include <string>
using namespace std;
template <typename type>

class QuanLy
{
    protected:      

    public:
        //QuanLy();
        virtual ~QuanLy();
        virtual void Add(type) = 0;
        virtual void Show() = 0;
        virtual void Search(string) = 0;  //Search
        virtual void Update(string,type) = 0;
        virtual void Delete(string) = 0;
};

#endif
/*
    template <typename T>
    class QuanLy {
        private : 
            T* list;
            int length;
        public:
            QuanLy();
            ~QuanLy();
            void Add(T,int);
            void Show();
            void Search(T);
            void Update(T);
            void Delete(T);
    };


    


*/
