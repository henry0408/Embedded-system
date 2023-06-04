#ifndef TABLE_H
#define TABLE_H

#include <iostream>

using namespace std;

class Table
{
protected:
    int height;
    string color;

public:
    Table(int h, string c);
    ~Table();
};

#endif // TABLE_H
