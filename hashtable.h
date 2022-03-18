#pragma once
#include <iostream>

#define HASHTABELSIZE 100

struct listEl
{
    int num;
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
        void (hashCounter*) (char* word);

    public:
        hashtable(size_t size, void (*hashCounter) (char* word))
        {
            std::cout << "+++ Construction +++ \n";
            size_ = size;
            lists_ = new list [size];
            has
            std::cout << "Construction has been complited \n";
        }

        ~hashtable()
        {
            size_ = 0;
            delete lists;
        }
};

/*typedef struct
{
    *list listData;
    size_t size;
    void (*hashCounter) (char* word);
}hashtable;*/