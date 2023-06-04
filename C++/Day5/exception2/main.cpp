#include <iostream>

using namespace std;

class myCheck
{
    int a,b,c;
public:
    myCheck(int a, int b, int c):a(a),b(b),c(c){}
    void show()
    {
        cout<<a<<" "<<b<<" "<<c<<" "<<"fail"<<endl;
    }
};

int check(int a, int b, int c)
{
    if(a+b<=c || a+c <=b || b+c <= a)
    {
        myCheck e(a,b,c);
        throw(e);

    }
    return a+b+c;
}

int main()
{
    while(1)
    {
        int a;
        int b;
        int c;

        cin>>a>>b>>c;

        try
        {
            cout<<check(a,b,c)<<endl;
        }
        catch(myCheck e)
        {
            e.show();
        }

    }

    return 0;
}

