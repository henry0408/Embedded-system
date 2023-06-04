#ifndef MANITO_H
#define MANITO_H

#include <iostream>
#include "developer.h"

class Manito : public Developer
{
public:
    Manito();
    void develop();
    ~Manito();
};

#endif // MANITO_H
