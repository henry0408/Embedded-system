#include <iostream>
#include "pocker.h"

using namespace std;

int main()
{
//    QTextCodec *codec = QTextCodec::codecForName("GBK");//或者"GBK",不分大小写
//    QTextCodec::setCodecForLocale(codec); //全局编码设置
    Pocker *pk[54];

    string my_color[4] = {"红桃","黑桃","梅花","方块"};
    string my_point[13] = { "A","2","3","4","5","6","7","8","9","10","J","Q","K"};

    int n = 0;
    for(int i = 0; i<4; i++)
    {
        for(int j = 0; j<13; j++)
        {
            Pocker *my_pk = new Pocker(my_point[j],my_color[i]);

            pk[n] = my_pk;
            n++;
        }
    }

    Pocker *king1 = new Pocker("大王");

    Pocker *king2 = new Pocker("小王");

    pk[52] = king1;
    pk[53] = king2;

    for(int i = 0; i<54; i++)
    {
        cout<<pk[i]->toString()<<endl;
    }

    return 0;
}

