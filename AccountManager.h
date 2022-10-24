
#ifndef _ACCOUNTMANAGER_
#define _ACCOUNTMANAGER_


#include <iostream>
#include "Account.h"
using namespace std;
class AccountManager {

    private:
        Account* p;
        int n;
    public:
        AccountManager();
		~AccountManager();
        void Add(const Account&); 
        void Delete(string); // nhan vao ten staff
        void LoadData();
        void ShowData();
        void Login(bool&,bool&);
};

#endif