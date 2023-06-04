//#include <iostream>

//using namespace std;

//class Food
//{
//public:
//    string chips;
//    Food(string chips):chips(chips)
//    {
//        cout<<chips<<endl;
//        cout<<"father"<<endl;
//    }
//};

//class KFC: public Food
//{
//    string chips;
//public:
//    KFC(string chips):Food("big mac"),chips(chips)
//    {
//        cout<<"child"<<endl;
//    }
//    void show()
//    {
//        cout<<chips<<endl;
//    }
//};

//int main()
//{
//    KFC k("hamburger");
//    k.show();
//    return 0;
//}






//#include <iostream>
//using namespace std;

//class Food
//{
//public:
//     string chips;
//};
////kfc:子类  派生类  Food：基类 父类
//class KFC : public Food
//{
//    //string chips;
//public:
//    KFC(string chips)
//    {
//        this->chips = chips;
//    }
//    void show()
//    {
//        cout<<"kfc: "<<chips<<endl;
//    }
//};
//int main()
//{
//    KFC kfc("hamburger");
//    kfc.show();
//    return 0;

//}





//#include <iostream>
//using namespace std;

//class Food
//{
//public:
//     string chips;
//    Food(string chips):chips(chips)
//    {
//        cout<<"food create"<<endl;
//        cout<<"father: "<<chips<<endl;
//    }
//    Food()
//        {
//            cout<<"food create2"<<endl;
//        }
//};
//class KFC : public Food
//{
//public://子类的初始化列表中，初始化父类的构造函数
//    KFC(string chips):Food(chips) //父类的匿名对象
//    {
//       // this->chips = chips;
//        cout<<"kfc create"<<endl;
//    }
//    void show()
//    {
//        cout<<"kfc: "<<chips<<endl;
//    }
//};
//int main()
//{
//    KFC kfc("big mac");
//    kfc.show();
//    return 0;
//}






//#include <iostream>
//using namespace std;

////1.当父类没有显示的定义构造，那么会调用父类默认的构造函数
////2.父类显示的定义了构造，那么会调用父类显示的无参的构造
////3.先创建父类，后创建子类
//class Food
//{
//public:
//     string chips;
//    Food(string chips):chips(chips)
//    {
//        cout<<"food create"<<endl;
//}
//Food()
//    {
//        cout<<"food create2"<<endl;
//    }
//};
////添加继承关系：冒号: 继承权限 父类
////kfc:子类  派生类  Food：基类 父类
//class KFC : public Food
//{
//string chips;
//public://子类的初始化列表中，先创建父类，即调用父类的无参构造函数
//    KFC(string chips):Food("ham"),chips(chips)
//    {
//       // this->chips = chips;
//        cout<<"kfc create"<<endl;
//    }
//    void show()
//    {
//        cout<<"kfc: "<<chips<<endl;
//    }
//};
//int main()
//{
//    KFC kfc("big mac");
//    kfc.show();
//    return 0;
//}



//#include <iostream>
//using namespace std;

//class Food
//{
//public:
//    string chips;
//    Food(string chips):chips(chips)
//    {
//        cout<<"food create"<<endl;
//        cout<<chips<<endl;
//    }
//    Food()
//    {
//        cout<<"food create2"<<endl;
//    }
//};
//class KFC : public Food
//{
//    string chips;
//public://子类的初始化列表中，初始化父类的构造函数
//    KFC(string chips):Food("hamburger"),chips(chips) //父类的匿名对象
//    {
//        cout<<"kfc create"<<endl;
//    }
//    void show()
//    {
//        cout<<"kfc: "<<chips<<endl;
//    }
//};
//int main()
//{
//    KFC kfc("big mac");
//    kfc.show();
//    return 0;
//}



//#include <iostream>
//using namespace std;

//class Food
//{
//public:
//    string chips;
//    Food(string chips):chips(chips)
//    {
//        cout<<"food create"<<endl;
//        cout<<chips<<endl;
//    }
//    Food()
//    {
//        cout<<"food create2"<<endl;
//    }
//};
//class KFC : public Food
//{
//    //string chips;
//public://子类的初始化列表中，初始化父类的构造函数
//    KFC(string chips):Food("hamburger") //父类的匿名对象
//    {
//        cout<<"kfc create"<<endl;
//    }
//    void show()
//    {
//        cout<<"kfc: "<<chips<<endl;
//    }
//};
//int main()
//{
//    KFC kfc("big mac");
//    kfc.show();
//    return 0;
//}




#include <iostream>
using namespace std;

class Food
{
public:
    string chips;
    Food(string chips):chips(chips)
    {
        cout<<"food create"<<endl;
        cout<<chips<<endl;
    }
    Food()
    {
        cout<<"food create2"<<endl;
    }
};
class KFC : public Food
{
public://子类的初始化列表中，初始化父类的构造函数
    KFC(string chips):Food("hamburger") //父类的匿名对象
    {
        this->chips = chips;
        cout<<"kfc create"<<endl;
    }
    void show()
    {
        cout<<"kfc: "<<chips<<endl;
    }
};
int main()
{
    KFC kfc("big mac");
    kfc.show();
    return 0;
}
