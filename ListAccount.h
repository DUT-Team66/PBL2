
#ifndef _LISTACCOUNT_
#define _LISTACCOUNT_


#include <iostream>
#include "Account.h"
using namespace std;
class ListAccount {

    private:
        Account* p;
        int n;
    public:
        ListAccount();
		~ListAccount();
        void setData();
        void showData();
        void login();
};

#endif