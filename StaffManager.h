
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
        
        //----------------
        void Add(const Staff&);
        void Delete(string);
        void Search(string);
        void Update(string);
        void Show();
        //-----------------
        const int& GetLength() const;
        const string& getStaffID(int) const;
        void LoadData(); // load data from file
        void Menu(); // manage staff choice
        const StaffManager& operator=(const StaffManager& );
};


#endif
