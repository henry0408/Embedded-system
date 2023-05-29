#include <iostream>

using namespace std;

class Rect
{
private:
    int width;
    int height;
public:
    Rect(int w=0, int h=0)
    {
        width = w;
        height = h;
    }

    void show()
    {
        int p;
        p = 2*(width+height);
        cout<<p<<endl;
    }
};

int main(int argc, char const *argv[])
{
    
    int width, height;
    cout<<"height: "<<endl;
    cin>>height;
    cout<<"width: "<<endl;
    cin>>width;
    Rect rec(width,height);
    rec.show();

    Rect rec1;
    rec1.show();
    return 0;
}
