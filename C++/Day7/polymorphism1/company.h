#ifndef COMPANY_H
#define COMPANY_H

#include "developer.h"
#include "manito.h"
#include "smallbird.h"

#include <cstdlib>
#include <ctime>

class Company
{
public:
    Company();
    Developer* recruit();

    void work(Developer*  p);

    ~Company();
};

#endif // COMPANY_H
