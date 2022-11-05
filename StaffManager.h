
#ifndef _STAFFMANAGER_
#define _STAFFMANAGER_

#include "Staff.h"
class StaffManager
{
    private: 
        struct Node{
            Staff data;
            Node* pNext;
        };
        Node *pHead;
        Node *pTail;
        int n;
    public:
        
        StaffManager();
        ~StaffManager();
        
        //----------------
        void Add(const Staff&);
        void Delete(string);
        void Search(string);
        void Update(string);
        void Show() const;
        const string& getStaffName(int) const;
        const string& getStaffID(int) const;
        const string& getStaffGender(int) const;
        const string& getStaffDob(int) const;
        const string& getStaffPhoneNumber(int) const;
        const string& getStaffAddress(int) const;
        //-----------------
        const int& GetLength() const;
        void LoadData(); // load data from file
        void UpdateFile(); // edit file
        void Menu(); // manage staff choice
        void Login(bool&,bool&);
        const StaffManager& operator=(const StaffManager& );
};
#endif