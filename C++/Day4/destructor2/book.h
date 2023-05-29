/*设计一个Book类  包含图书的书名，作者成员 其中：书名和作者用字符型指针
        char* name;
        char* author;
1.构造函数为作者及书名指针开辟空间并将传入的 书名和作者拷贝到数组中
        Book(const char* name,const char* author)
        没有空间， 分配字符数组空间，strcpy();
2.一个析构函数，删除书名和作者数组delete[] name
3.成员函数print()输出数据 书名和作者

*/

#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <cstring>

using namespace std;

class Book
{
private:
    char* name;
    char* author;
public:
    Book(const char* name,const char* author);
    ~Book();
    void print();
};

#endif // BOOK_H
