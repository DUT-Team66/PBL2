#include <string>
#include "StaffManager.h"
using namespace std;

void randOrderID(int length, string& result)
{
    int i;
    char char_set[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

    for (i = 0; i < length; i++)
    {
        result += char_set[rand() % sizeof(char_set)];
    }
    // result[length] = 0;
}
void randStaffID(StaffManager staffManager,string& id) {
    int index = rand()%(staffManager.GetLength());
    id = staffManager.getStaffID(index);

}