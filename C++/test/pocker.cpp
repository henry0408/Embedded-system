#include "pocker.h"

Pocker::Pocker(string p, string c)
{
    point = p;
    color = c;
}

Pocker::Pocker(string c)
{
    color = c;
}

string Pocker::toString()
{
    return color+point;
}
