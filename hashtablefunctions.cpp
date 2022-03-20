#include "hashtable.h"

hashtable::hashtable(size_t capacity, int (*hashCounter) (const char* word))
{
    std::cout << "+++ CONSTRUCTOR +++" << std::endl;

    size_ = 0;

    lists_ = new list [capacity];
    for (size_t i = 0; i <= capacity; i++)
    {
        (lists_[i]).head = nullptr;
        (lists_[i]).numOfEl = 0;
    }

    hashCounter_ = hashCounter;

    std::cout << "Construction has been complited \n" << std::endl;
}

hashtable::~hashtable()
{
    std::cout << "--- DISTRUCTOR ---" << std::endl;

    for (size_t i = 0; i <= this -> size_; i++)
    {
        listEl* next = (this -> lists_[i]).head;

        listEl* oldnext;

        while(next != nullptr)
        {
            oldnext = (*next).next;
            delete next;
            next = oldnext;
        }
    }

    size_ = 0;

    delete [] lists_;

    std::cout << "Distruction has been complited \n" << std::endl;
}

void listDump(list lst)
{
    listEl* next = lst.head;

    assert(next != nullptr);

    for(size_t i = 0; i < lst.numOfEl; i++)
    {
        std::cout << "[" << next << "] \"" << (*next).word << "\" (Next: " << (*next).next << ")" << "," << std::endl;
        next = (*next).next;
    }
}

void hashtable::htbDump()
{
    std::cout << "HTBDUMP (size = " << this -> size_ << "):\n" << std::endl;
    for (size_t i = 0; i < this -> size_; i++)
    {
        std::cout << "List [" << i << "] " << "(hash = " << (this ->lists_[i]).hash << ", numOfEl: " << (this -> lists_[i]).numOfEl << "): \n";
        listDump(this -> lists_[i]);
        std::cout << std::endl;
    }
}

int hashCounter(const char* word)
{ 
    int i = 0;
    int sum = 0;

    while (word[i] != '\0')
    {
        sum += (int) word[i];
        i++;
    }           

    return sum % 100; 
}

void listInsert(list* lst, const char* word)
{
    listEl* newWord = new listEl;
    listEl* oldnext = lst -> head; 
    lst -> head = newWord;
    newWord->next = oldnext;
    newWord->word = word; 
    (lst -> numOfEl) ++;
}

int hashtable::htbInsert(const char* word)
{
    std::cout << "HTBINSERT:\nWord: " << word << std::endl;

    // Считаем хэш
    float hash = this -> hashCounter_(word);
    std::cout << "It's hash: " << hash << "\n" << std::endl;

    // Ищем список с таким хэшом
    for (size_t i = 0; i <= this -> size_; i++)
    {
        if ((this -> lists_[i]).hash == hash)
        {
            listInsert(&(this -> lists_[i]), word);
            return hash;
        }
    }

    // Если не нашли такой хэш, то создаём новый список
    (this -> lists_[size_]).hash = hash;
    listInsert(&(this -> lists_[size_]), word);  
    (this -> size_) ++;

    this -> htbDump();

    return hash;
}