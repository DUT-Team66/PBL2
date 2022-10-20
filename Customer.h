
#ifndef _CUSTOMER_
#define _CUSTOMER_

#include <string>
using namespace std;

class Customer {
    protected:
        string customerID;
        string customerName;
        string customerPhoneNumber;
        string customerAddress;
    public:
        void BuyPhone();
        //void getInfor();    

};




#endif