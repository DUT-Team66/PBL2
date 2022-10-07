
#ifndef _ACCOUNT_
#define _ACCOUNT_

#include <string>
using namespace std;

class Account {
    protected:
        string account;
        string password;
    public:
        Account(string, string);
        void Login();
};
#endif

