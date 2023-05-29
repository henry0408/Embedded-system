#include "book.h"

Book::Book(const char *name, const char *author)
{
    this->name = new char[strlen(name)+1];
    this->author = new char[strlen(author)+1];
    strcpy(this->name,name);
    strcpy(this->author,author);
}

Book::~Book()
{
    delete[] this->name;
    delete[] this->author;
}

void Book::print()
{
    cout<<"Book: "<<this->name<<" Author: "<<this->author<<endl;
}

