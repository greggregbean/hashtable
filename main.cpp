#include "hashtable.h"

int main()
{
    hashtable htb(HASHTABELCAPACITY, hashCounter);
    htb.htbInsert("dede");
    htb.htbFind("df");
}