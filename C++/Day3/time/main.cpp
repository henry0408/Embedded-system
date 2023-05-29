#include "mytime.h"

int main(int argc, char const *argv[])
{
    /* code */
    MyTimer t(23,59,59);
    t.getTime();

    MyTimer t1(22,59,59);
    t1.getTime();

    MyTimer t2(23,59,0);
    t2.getTime();
    
    return 0;
}
