// #pragma once
#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>

#define HASHTABELSIZE 100

struct listEl
{
    char* word;
    listEl* next;
};

struct list
{
    listEl* head;
    int numOfEl;
    int hash;
};

class hashtable
{
    private:
        list* lists_;
        size_t size_;
        int (*hashCounter_) (char* word);

    public:
        hashtable(size_t size, int (*hashCounter) (char* word));
        ~hashtable();
};

int hashCounter(char* word);

#endif