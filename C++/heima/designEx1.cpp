/*设计案例1：判断两个立方体体积是否相等*/

#include <iostream>

using namespace std;

class Cube
{
private:
    int length;

public:
    void setV(int len)
    {
        length = len;
    }
    int getV()
    {
        return length*length*length;
    }
    bool isSame(Cube& c)
    {
        if(this->getV() == c.getV() )
        {
            return true;
        }
        return false;
    }
};


int main(int argc, char const *argv[])
{
    /* code */
    Cube c1;
    c1.setV(10);
    cout<<c1.getV()<<endl;

    Cube c2;
    c2.setV(100);
    if(c1.isSame(c2))
    {
        cout<<"same"<<endl;
    }
    else
    {
        cout<<"not same"<<endl;
    }


    return 0;
}
