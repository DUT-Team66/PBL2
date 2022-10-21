
#ifndef _PHONEMANAGER_
#define _PHONEMANAGER_
#include "Phone.h"
class PhoneManager
{
    private: 
        Phone *p;
        int n;
    public:
        //Khong co SV
        PhoneManager();
        ~PhoneManager();
        int getlength();
        void Add(const Phone& s);
        void Delete(string);
        void Search(string);
        void Show();

        void SetData();
};
#endif