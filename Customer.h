#ifndef _CUSTOMER_
#define _CUSTOMER_

#include <string>
using namespace std;

class Customer {
    protected:
        string customerName;
        string customerPhoneNumber;
        string customerAddress;
    public:
        Customer(string ="", string="", string="");
        ~Customer();
        
        void setCustomerName(const string& );
        const string& getCustomerName() const;
        void setCustomerPhoneNumber(const string&);
        const string& getCustomerPhoneNumber() const;
        void setCustomerAddress(const string&);
        const string& getCustomerAddress() const;

       
        void Show();
};




#endif