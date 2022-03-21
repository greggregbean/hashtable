#include "hashtable.h"

int main()
{
    std::ofstream textGraph("textGraph.dot");
    hashtable htb(HASHTABELCAPACITY, hashCounter);
    htb.htbInsert("dede");
    htb.htbFind("df");
    htb.htbInsert("Mama");
    htb.htbInsert("Papa");
    htb.graphDump(&textGraph);
    textGraph.close();
}