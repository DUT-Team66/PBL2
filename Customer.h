
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
        Customer(string ="", string="", string="", string="");
        ~Customer();
        
        void setCustomerID(const string& );
        const string& getCustomerID() const;
        void setCustomerName(const string& );
        const string& getCustomerName() const;
        void setCustomerPhoneNumber(const string&);
        const string& getCustomerPhoneNumber() const;
        void setCustomerAddress(const string&);
        const string& getCustomerAddress() const;

        void setInfo();    

        void Show();
};




#endif
