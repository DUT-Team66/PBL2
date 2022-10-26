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
void randStaffID(StaffManager staffManager,string& id) {
    srand(time(NULL));
    int index = rand()%(staffManager.GetLength());
    // cout <<"index = "<< index << "\n";
    // staffManager.getStaffID(index);
    // cout << "index = " << index << "\n";
    id = staffManager.getStaffID(index);
    //cout <<"index = " << index <<"\n";
    
}