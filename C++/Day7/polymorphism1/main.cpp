/*main中创建Company对象，调用recruit()获得一个Developer*，
                         然后调用work()传入Developer参数*/

#include "company.h"

#include <iostream>

using namespace std;

int main()
{
    Company c;
    Developer *p = c.recruit();

    c.work(p);
    return 0;
}

