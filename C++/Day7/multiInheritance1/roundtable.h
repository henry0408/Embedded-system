#ifndef ROUNDTABLE_H
#define ROUNDTABLE_H
#include "circle.h"
#include "table.h"

class RoundTable : public Circle, public Table
{
public:
    RoundTable(int r, int height, string color);
    void show();

    ~RoundTable();
};

#endif // ROUNDTABLE_H
