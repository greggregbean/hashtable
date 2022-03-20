#include "hashtable.h"

hashtable::hashtable(size_t capacity, int (*hashCounter) (const char* word))
{
    std::cout << "+++ CONSTRUCTOR +++ \n";
    size_ = 0;
    lists_ = new list [capacity];
    hashCounter_ = hashCounter;
    std::cout << "Construction has been complited \n";
}

hashtable::~hashtable()
{
    std::cout << "--- DISTRUCTOR --- \n";
    size_ = 0;
    delete [] lists_;
    std::cout << "Construction has been complited \n";
}

int hashCounter(const char* word)
{
    std::cout << "\nHASHCOUNTER \n";
    std::cout << "Word: " << word << std::endl; 
    int i = 0;
    int sum = 0;

    while(word[i] != '\0')
    {
        sum += (int) word[i];
        i++;
    }                                                                                                                                                                                                                                  

    std::cout << "It's hash: " << sum%100 << "\n" << std::endl;

    return sum % 100; 
}

void listInsert(list* lst, const char* word)
{
    listEl newWord;
    listEl* oldnext = lst -> head; 
    lst -> head = &newWord;
    newWord.next = oldnext;
    newWord.word = word; 
}

int hashtable::htbInsert(const char* word)
{
    // Считаем хэш
    float hash = this -> hashCounter_(word);

    // Ищем список с таким хэшом
    for(size_t i = 0; i <= this -> size_; i++)
    {
        if((this -> lists_[i]).hash == hash)
        {
            listInsert(&(this -> lists_[i]), word);
            return hash;
        }
    }

    // Если не нашли такой хэш, то создаём новый список
    (this -> lists_[size_]).hash = hash;
    listInsert(&(this -> lists_[size_]), word);  
    (this -> size_) ++;

    return hash;
}