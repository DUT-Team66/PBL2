#include <string>
#include "StaffManager.h"
#include <cstdlib>
#include <time.h>
using namespace std;

void randOrderID(int length, string& result)
{
    srand(time(NULL));
    int i;
    char char_set[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

    for (i = 0; i < length; i++)
    {
        result += char_set[rand() % sizeof(char_set)];
    }
    // result[length] = 0;
}
void randStaffID(const StaffManager& staffManager,string& id) {
    //staffManager.Show();
    //cout << "staffmanager.length() = " << staffManager.GetLength() << "\n";
    srand(time(NULL));
    int index = rand()%(staffManager.GetLength());
    //int index = 6;
    //cout <<"index = "<< index << "\n";
    staffManager.getStaffID(index);
    //cout << "index = " << index << "\n";
    id = staffManager.getStaffID(index);
    //id = "10000000";
    //cout <<"index = " << index <<"\n";
    
}