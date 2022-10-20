#include <string>
using namespace std;
class Account {
    private:
        string account;
        string password;
    public:
        Account();
		Account(string,string);
        void Login();
        void setData();
        void showData();
		
};