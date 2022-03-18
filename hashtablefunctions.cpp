#include "hashtable.h"

hashtable::hashtable(size_t size, int (*hashCounter) (char* word))
{
    std::cout << "+++ Construction +++ \n";
    size_ = size;
    lists_ = new list [size];
    hashCounter_ = hashCounter;
    std::cout << "Construction has been complited \n";
}

hashtable::~hashtable()
{
    std::cout << "--- Distruction --- \n";
    size_ = 0;
    delete [] lists_;
    std::cout << "Construction has been complited \n";
}

int hashCounter(char* word)
{
    int i = 0;

    int sum = 0;

    while(word[i] != '\0')
    {
        sum += (int) word[i];
        i++;
    }

    sum %= 100;

    return sum; 
}

/*int htbInsert(hashtable* htb, char* word)
{}*/