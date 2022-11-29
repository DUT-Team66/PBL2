
#ifndef _ADMIN_
#define _ADMIN_

#include "StaffManager.h"
#include "ThongKe.h"
#include <vector>
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
        void ShowThongKe();
        //void calProfit(); // loi nhuan
        void Menu(); // admin route
        void Import();
        void LoadThongKe(); // 
        void UpdateThongKe();
        void UpdateDoanhThuLoiNhuan(Order&);
        void UpdateAllFiles(); // update phone.txt, staff.txt, account.txt
};
#endif