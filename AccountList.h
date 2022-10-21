
#ifndef _ACCOUNTLIST_
#define _ACCOUNTLIST_


#include <iostream>
#include "Account.h"
using namespace std;
class AccountList {

    private:
        Account* p;
        int n;
    public:
        AccountList();
		~AccountList();
        void SetData();
        void showData();
        void login();
};

#endif