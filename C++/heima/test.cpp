#include <iostream>
using namespace std;

int& test2()
{
	static int a = 10;	//静态变量，存在于全局区
	return a;
}
int main()
{
	int& ref =  test2();
	cout<<ref<<endl;	//10
	test2() = 1000;
	cout<<ref<<endl;	//1000
}