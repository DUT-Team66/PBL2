#include "StaffManager.h"
#include "Staff.h"
class Admin : public Staff {
    private:
        StaffManager manageStaff;
    public:
        Admin();
        ~Admin();
        void Menu(); // admin route
        void calTurnover(); //Doanh thu
        //void calProfit(); // loi nhuan
};