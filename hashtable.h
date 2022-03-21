#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <string.h>
#include <assert.h>
#include <fstream>

#define HASHTABELCAPACITY 100
#define NOTFOUNDINLST -1
#define NOTFOUNDINHTB -1

struct listEl
{
    const char* word;
    listEl* next;
};

struct list
{
    listEl* head;
    int hash;
    size_t numOfEl;
};

class hashtable
{
    private:
        list* lists_;
        size_t size_;
        int (*hashCounter_) (const char* word);

    public:
        hashtable(size_t size, int (*hashCounter) (const char* word));
        ~hashtable();
        void htbDump();
        listEl* htbInsert(const char* word);
        listEl* htbFind(const char* word);
        void graphDump(std::ofstream* textGraph);
        
};

int hashCounter(const char* word);
listEl* listFind(list lst, const char* word);
listEl* listInsert(list* lst, const char* word);
void listGraphDump(std::ofstream textGraph, list lst);

#endif