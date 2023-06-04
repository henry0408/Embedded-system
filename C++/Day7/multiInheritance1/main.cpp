/*
 *
 * 1.设计一个圆类Circle(半径r)
2.一个桌子类Table(高度h和颜色color)
3.再设计一个圆桌类RoundTable  它从前两个类派生
要求：  输出一个圆桌的高度 颜色  和面积
*/

#include <iostream>
#include "roundtable.h"

using namespace std;

int main()
{
    RoundTable rt(10,20,"red");
    rt.show();
    return 0;
}

