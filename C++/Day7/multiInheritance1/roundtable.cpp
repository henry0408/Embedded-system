#include "roundtable.h"


RoundTable::RoundTable(int r, int height, string color):Circle(r),Table(height, color)
{

}


//输出一个圆桌的高度 颜色  和面积
void RoundTable::show()
{
    cout<<height <<" "<<color<<" "<<endl;
}

RoundTable::~RoundTable()
{

}

