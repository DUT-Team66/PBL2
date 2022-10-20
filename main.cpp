#include <iostream>
#include <iomanip>
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
Account::Account() {
	this->account = "";
	this->password = "";
}
Account::Account(string account, string password)
{
	this->account = account;
	this->password = password;
}
void Account::setData() 
{
    //cout << "Username: ";
    cin >> this->account;
    //cout << "Password: ";
    cin >> this->password;
}
void Account::showData()
{
    cout << "Username: " << this->account << "\n";
    cout << "Password: " << this->password << "\n";
}
class ListAccount {
    private:
        Account* data;
        int length;
    public:
        ListAccount();
		~ListAccount();
        void setData();
        void showData();



};
ListAccount::ListAccount() {
	this-> data = nullptr;
	this->length = 0;
}
ListAccount::~ListAccount() {
	delete[] this->data;
}
void ListAccount::setData() 
{
	//Account acc("admin", "admin");
	Account* acc = new Account[1];
	acc->setData
	
	this->length++;

	
    // cin >> this->length;
    // for(int i = 1; i < this->length; ++i) {
	// 	Account tmp;
	// 	tmp.setData();
	// 	//*(this->data + i) = tmp;
	// 	tmp.showData();

	// }
	
	string name, pass;

	while(cin >> name && cin >> pass) {
		Account tmp(name, pass);
		*(this->data + this->length) = tmp;
		this->length++;
		tmp.showData();
	}

}
void ListAccount::showData()
{
    for(int i = 0; i < this->length; ++i) {
        data[i].showData();
    }
}
int main()
{
    freopen("account.txt","r",stdin);
	
	ListAccount listAccount;
	listAccount.setData();
    //listAccount.showData();
}

/*
int main()
{
	// choose role 
	cout << setw(25) << "" << "NH MOBILE STORE" << "\n\n\n";
	cout << setw(20) << "" << "You are: " << "\n\n"; 
	cout << setw(22) << "" << "1. Staff" << "\n\n";
	cout << setw(22) << "" << "2. Customer" << "\n\n";  
	
	int role; 
	do {
		cout << setw(20) << "" << "Your choice: ";
		cin >> role;
		
	} while(1);
	// can xu li role khong hop le
	
	
	
	
	// enter staff account
	string username, password;
	cout << setw(20) << "" << "Enter your account" << "\n\n";
	cout << setw(22) << "" << "Username: ";
	cin >> username;
	cout << "\n";
	cout << setw(22) << "" << "Password: ";
	cin >> password;
	cout << "\n";
	// can xu li dung sai tai khoan
	
	
	
	
	//admin route--------------------------------------------------
	cout << setw(20) << "" << "Choose what you want to manage" << "\n\n";
	cout << setw(22) << "" << "1. Staffs" << "\n";
	cout << setw(22) << "" << "2. Phones" << "\n";
	cout << setw(22) << "" << "3. Trades" << "\n\n";
	cout << setw(20) << "" << "Your choice: ";
	int thingToManage1; cin >> thingToManage1;   
	
	//--------------------------------------------------------------
	
	
	
	
	//staff route--------------------------------------------------
	cout << setw(20) << "" << "Choose what you want to manage" << "\n\n";
	cout << setw(22) << "" << "1. Phones" << "\n";
	cout << setw(22) << "" << "2. Trades" << "\n\n";
	cout << setw(20) << "" << "Your choice: ";
	int thingToManage2; cin >> thingToManage2; 
	
	//--------------------------------------------------------------
	
	
	// STAFFS-------------------------------------------------------
	cout << setw(25) << "" << "STAFFS" << "\n\n\n";
	cout << setw(22) << "" << "1. Add staff" << "\n"; // nhap day du thong tin cua staff
	cout << setw(22) << "" << "2. Delete staff" << "\n"; // nhap staffid
	cout << setw(22) << "" << "3. Search staff" << "\n"; // nhap staffid
	cout << setw(22) << "" << "4. Update staff" << "\n"; // nhap day du thong tin cua staff, neu khong doi nhap N/A
	cout << setw(22) << "" << "5. Show all staffs" << "\n\n";
	cout << setw(20) << "" << "Your choice: ";
	int sAction; cin >> sAction;
	
	cout << setw(20) << "" << "StaffID: ";
	string staffid; cin >> staffid;
	
	
	//--------------------------------------------------------------
	
	
	
	
	// PHONES-------------------------------------------------------
	cout << setw(25) << "" << "PHONES" << "\n\n\n";
	cout << setw(22) << "" << "1. Add phone" << "\n"; // nhap day du thong tin cua phone
	cout << setw(22) << "" << "2. Delete phone" << "\n"; // nhap phoneid
	cout << setw(22) << "" << "3. Search phone" << "\n"; // nhap phoneid
	cout << setw(22) << "" << "4. Show all phones" << "\n\n";
	cout << setw(20) << "" << "Your choice: ";
	int pAction; cin >> pAction;
	
	cout << setw(20) << "" << "PhoneID: ";
	string phoneid; cin >> phoneid;
	
	//--------------------------------------------------------------
	
	
	
	
	// TRADERS------------------------------------------------------
	
	cout << setw(25) << "" << "TRADES" << "\n\n\n";
	cout << setw(22) << "" << "1. Search by OrderID" << "\n"; //  nhap orderid
	cout << setw(22) << "" << "2. Search by CustomerID" << "\n"; // nhap customerid
  	cout << setw(22) << "" << "3. Show all staffs" << "\n\n"; 
	cout << setw(20) << "" << "Your choice: ";
	int tAction; cin >> tAction;
	
	cout << setw(20) << "" << "OrderID: ";
	string orderid; cin >> orderid;
	cout << setw(20) << "" << "CustomerID: ";
	string customerid; cin >> customerid;
	
	//--------------------------------------------------------------
	
	
	
	
	
	// GetCustomerInformation----------------------------------------
	
	cout << setw(20) << "" << "Enter your information" << "\n\n";
	
	cout << setw(22) << "" << "Name: ";
	string customerName; getline(cin, customerName);
	
	cout << setw(22) << "" << "ID: ";
	string customerID; cin >> customerID;
	
	cout << setw(22) << "" << "Phone number: ";
	string customerPhoneNumber; cin >> customerPhoneNumber;
	
	cout << setw(22) << "" << "Address: ";
	cin.ignore();
	string customerAddress; getline(cin, customerAddress);
	
 	
	
	
	//--------------------------------------------------------------
	
	
	
	
	// ShoppingTime-------------------------------------------------
	
	cout << setw(20) << "" << "Choose what you want to purchase" << "\n\n\n";
	
	
	
 	// List of phones ( use for loop?)
 		
 		
 	//
		 
		  
	
	cout << setw(20) << "" << "Your choice: ";
	int choice; cin >> choice;
	
	
	cout << setw(20) << "" << "Amount: ";
	int amount; cin >> amount; 
	
 	//--------------------------------------------------------------
	
	
	
	
	
	
	
	
	
	
	
	
	
}
*/