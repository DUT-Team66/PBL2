
#ifndef _STAFFMANAGER_
#define _STAFFMANAGER_

#include "Staff.h"
class StaffManager
{
    private: 
        Staff *p;
        int n;
    public:
        
        StaffManager();
        ~StaffManager();
        
        void Add(const Staff& );
        void Delete(string);
        void Search(string);
        int IndexOf(int);
        void Update(int);
        void Show();

        void SetData();
};


#endif