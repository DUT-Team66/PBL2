
#ifndef _ADMIN_
#define _ADMIN_

#include "StaffManager.h"
#include "ThongKe.h"

//#include "AccountManager.h"

class Admin : public Staff {
    private:
        StaffManager manageStaff;
        //AccountManager manageAccount;
        vector<ThongKe> thongKe;
    public:
        Admin();
        Admin(string,string, string, string,string,string,string,string);
        ~Admin();

        void setStaffManager(const StaffManager&);
        const StaffManager& getStaffManager() const;
        //void setAccountManager(const AccountManager&);
        long long Import(); // nhap hang hoa
        void ThongKe();
        //void calProfit(); // loi nhuan
        void Menu(); // admin route
        void LoadThongKe(); // chua viet cpp
        void UpdateThongKe();
        void UpdateAllFiles(); // update phone.txt, staff.txt, account.txt
};
#endif