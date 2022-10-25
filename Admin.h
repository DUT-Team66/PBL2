
#ifndef _ADMIN_
#define _ADMIN_

#include "StaffManager.h"

#include "AccountManager.h"

class Admin : public Staff {
    private:
        StaffManager manageStaff;
        AccountManager manageAccount;
    public:
        Admin();
        Admin(string,string, string, string,string,string,string,string);
        ~Admin();

        void setStaffManager(const StaffManager&);
        void setAccountManager(const AccountManager&);

        void Menu(); // admin route
        void calTurnover(); //Doanh thu
        //void calProfit(); // loi nhuan
        void UpdateAllFiles(); // update phone.txt, staff.txt, account.txt
};
#endif