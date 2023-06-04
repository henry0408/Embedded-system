/*定义一个抽象类形状Shape
纯虚函数：获得周长：int getPerimeter()=0;
        得到形状：string getType()=0;

子类三角形：Triangle
        属性：边长 a、b、c
         “三角形”

子类圆形：Circle
        属性：半径r
圆

子类正方形：Square
        属性：边长a
正方形

主函数：获取用户输入，"  1-三角形  2-正方形  3-圆"
*/


#include <iostream>

using namespace std;

class Shape
{
public:
    virtual int getPerimeter()=0;
    virtual string getType()=0;
};

class Triangle : Shape
{
private:
    int a, b, c;
public:
    Triangle(int a, int b, int c):a(a),b(b),c(c){}
    int getPerimeter()
    {
        return a+b+c;
    }
    string getType()
    {
        return "Triangle";
    }
};

class Circle : public Shape
{
private:
    int radius;
public:
    Circle(int r):radius(r){}
    int getPerimeter()
    {
        return 2*3.14*radius;
    }
    string getType()
    {
        return "Circle";
    }
};

class Square : public Shape
{
private:
    int a;
public:
    Square(int a):a(a){}
    int getPerimeter()
    {
        return 4*a;
    }
    string getType()
    {
        return "Square";
    }
};

int main()
{
    cout<<"Please enter the shape: "<<endl;
    int shape;
    cin>>shape;
    Shape *p;

    if(shape == 1)
    {
        p = new Triangle (2,3,4);
        cout<<p.getType()<<" "<<p.getPerimeter()<<endl;
    }
    else if(shape == 2)
    {
        p = new Square (2);
        cout<<p->getType()<<" "<<p.getPerimeter()<<endl;
    }
    else if(shape == 3)
    {
        p = new Circle (2);
        cout<<p->getType()<<" "<<p.getPerimeter()<<endl;
    }

    return 0;
}

