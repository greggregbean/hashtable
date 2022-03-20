#include "hashtable.h"

int main()
{
    hashtable htb(HASHTABELSIZE, hashCounter);
    htb.htbInsert("Mama");
}