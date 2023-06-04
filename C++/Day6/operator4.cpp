/*计算两个三角形周长和*/

#include <iostream>

using namespace std;

class Triangle
{
	int a,b,c;
public:
	Triangle(int a, int b, int c):a(a),b(b),c(c){}
	int getL()	//计算周长
	{
		return a+b+c;
	}
	int operator +(Triangle& o)
	{
		return this->getL()+o.getL();
	}
};

int main()
{
	Triangle t(1,1,1);
	Triangle t2(1,1,1);
	
	cout<<(t+t2)<<endl;
}