#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <string.h>
#include <assert.h>

#define HASHTABELCAPACITY 100

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
        int htbInsert(const char* word);
        
};

int hashCounter(const char* word);
void listInsert(list* lst, const char* word);

#endif