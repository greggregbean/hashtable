#include "hashtable.h"

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