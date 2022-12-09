
#ifndef _STAFFMANAGER_
#define _STAFFMANAGER_

#include "Staff.h"
#include "MyLib.h"

class StaffManager
{
    private: 
        List<Staff> list;
    public:
        
        StaffManager();
        ~StaffManager();
        
        //----------------
        void Add(const Staff&);
        void Delete(string);
        void Search();
        void Update();
        void Show();
        const string& getStaffName(int);
        const string& getStaffID(int);
        const string& getStaffGender(int);
        const string& getStaffDob(int);
        const string& getStaffPhoneNumber(int);
        const string& getStaffAddress(int);
        //-----------------
        int GetLength() const;
        void LoadData(); // load data from file
        void UpdateFile(); // edit file
        void Menu(); // manage staff choice
        void Login(bool&,bool&);
        const StaffManager& operator=(const StaffManager& );
};
#endif