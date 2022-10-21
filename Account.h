#ifndef _ACCOUNT_
#define _ACCOUNT_


#include <string>
using namespace std;
class Account {
    private:
        string username;
        string password;
    public:
        Account();
		Account(string,string);
        string getUsername();
        string getPassword();

        //void setData();
        void showData();
		
};

#endif