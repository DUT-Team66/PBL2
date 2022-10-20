#include <iostream>
#include <string>
#include "Account.h"
using namespace std;
class ListAccount {
    private:
        Account* p;
        int n;
    public:
        ListAccount();
		~ListAccount();
        void SetData();
        void ShowData();
};