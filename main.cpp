#include "hashtable.h"

int main()
{
    hashtable htb(HASHTABELCAPACITY, hashCounter);
    htb.htbInsert("Mama");
    htb.htbInsert("Papa");
}