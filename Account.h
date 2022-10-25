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
        void setUsername(const string&);
        const string& getUsername() const;
        void setPassword(const string&);
        const string& getPassword() const;

        //void setData();
        void showData();
		
};

#endif