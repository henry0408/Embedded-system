# c++



## 1. 基本

### 1.1 编译命令：

```
g++ hello.cpp
```



### 1.2 头文件

```
#include <cstdio>
#include <cstdlib>
#include <iostream>
```



### 1.3 运算符重载

`>>` 和 `<<`

运算符重载，指向了数据流方向



## 2. 标准输入输出

### 2.1 输出流：cout

```
#include <iostream>

int main()
{
	//在这里<<不是移位的运算，被重新赋予了新的含义，就是把右边的内容放到输出流对象里。
	std::cout<<" hello world !"<<std::endl;   //等价于printf(“hello world\n”);
	return 0;
}
```

std：命名空间

cout：输出流 `cout<<输出的数据`

<<：输出流运算符

endl：换行，相当于`\n`

`::` 作用域运算符



如果不想换行可以写成：(空格隔开)

```
#include <iostream>

int main()
{
	std::cout<<" hello world !"<<" ";
	return 0;
}
```



#### 2.1.1 输出流会自动识别(多个)输出变量类型

```
#include <iostream>
int main()
{
	int a = 10;	
	char c = 'q';
	//std::cout会自动识别输出变量的类型
	std::cout<<a<<" "<<c<<std::endl;  //10 q换行
	//printf(“%d %c\n”,a,c);
	return 0;
}
```



#### 2.1.2 格式化输出

1. 两位整数：05

```
cout<<setfill('0')<<setw(2)<<5<<endl;
```



2. 指定多少位小数

   ```
   float a = 3.12;
   cout<<setiosflags(ios::fixed)<<setprecision(5)<<a<<endl;//3.12000
   ```

   



### 2.2 输入流：cin

#### 2.2.1 输入流会自动识别(多个)输入变量类型

```
#include <iostream>

int main()
{
	int age;
	std::cout<<"please input age:"<<std::endl;
	std::cin>>age;//scanf(“%d”,&age);
	std::cout<<age<<std::endl; //printf("%d\n",age);
}
```



#### 2.2.2 同时获取多个值

```
int age;
char f;
cin >> age >> f
```

例子

```
#include<iostream>

int main()
{
	std::cout<<"请输入一个age"<<std::endl;
	int age;
	char f;
	std::cin>>age>>f;//10-->age s-->f 
	std::cout<<"my age is"<<age<<" "<<f<<std::endl;
}
```



#### 2.2.3 cin输入字符串

**遇到空格就结束！！只取空格之前的，剩下的存在缓冲区**



例子1：

```
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	cin>>s;  //遇到空格输入结束
	cout<<s<<endl;
}
```

输入：

```
hangyu chen
```

输出：

```
hangyu
```



例子2：

```
#include <iostream>
#include <string> // Header file needed to use string objects
using namespace std;
int main()
{
    string name;
    string city;
    cout << "Please enter your name: ";
    cin >> name;
    cout << "Enter the city you live in: ";
    cin >> city;
    cout << "Hello, " << name << endl;
    cout << "You live in " << city << endl;
    return 0;
}
```

输入：

```
hangyu chen
```

输出：

```
Please enter your name: hangyu chen
Enter the city you live in: Hello, hangyu
You live in chen
```





### 2.3 getline输入字符串

遇到\n结束

c++中无法使用gets()函数

```
#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s;
	getline(cin,s);//参数1 从cin输入流获得字符串，参数2 读取到的字符串放到s里
	cout<<s<<endl;
}
```





ref: [C++ getline函数用法详解 (biancheng.net)](http://c.biancheng.net/view/1345.html)



## 3. 命名空间的表示方法

### 3.1 namespace作用

避免命名空间污染问题 （ 命名空间的作用只在起名上，发生同名冲突时，使用命名空间可以明确的找到变量的位置）

### 3.2 使用std

```
using namespace std
```



### 3.3 自定义命名空间

#### 3.3.1 两个命名空间的标识符中

当两个命名空间中有相同的标识符时，在使用这个标识符的时候必须把命名空间写在前面！

**例子1：**

```
/*namespace标识符冲突*/

#include <iostream>

using namespace std;

namespace MyStd
{
    int age = 18;
}

namespace YourStd
{
    int age = 19;
} // namespace YourStd

using namespace MyStd;
using namespace YourStd;

int main(int argc, char const *argv[])
{
    /* code */
    cout<< age<<endl;
    return 0;
}

```

报错：reference to 'age' is ambiguous



**改正：**

main函数中需要写成

```
cout<< YourStd::age<<endl;
cout<< MyStd::age<<endl;
```



#### 3.3.2 命名空间标识符和全局变量冲突(匿名命名空间)

局变量和空间中变量冲突时，全局变量被放到匿名命名空间中

```
/*namespace标识符冲突*/

#include <iostream>

using namespace std;

namespace MyStd
{
    int age = 18;
    char name[] = "hangyu";
}

using namespace MyStd;

int age = 20;

int main(int argc, char const *argv[])
{
    /* code */
    cout<< ::age<<endl;         //全局变量
    cout<< MyStd::age<<endl;
    //cout<< age<<endl;         //报错，ambiguous
    return 0;
}

```



#### 3.3.3 全局变量和局部变量冲突（匿名空间）

当全局变量和局部变量重名时，在函数中访问全局变量通过匿名命名空间

```c++
/*namespace标识符冲突*/

#include <iostream>

using namespace std;

namespace MyStd
{
    int age = 18;
    char name[] = "hangyu";
}
using namespace MyStd;

int age = 20;

int main(int argc, char const *argv[])
{
    /* code */
    int age = 21;
    cout<< ::age<<endl;         //全局变量
    cout<< MyStd::age<<endl;
    cout<< age<<endl; 
    return 0;
}
```

输出：

```
20
18
21
```



## 4. bool类型

非0为true，0为false；bool类型至少占一个字节

```c++
bool b1;
b1 = -10;
cout<<b1<<endl;	//1	
```

```c++
bool b5;
b5 = 0;
cout<<b5<<endl;   // 0
```

```c++
bool b3;
b3 = true;
cout<<b3<<endl;	//1
```



### 4.1 结合三步运算符

```
#include<iostream>
using namespace std;
int main()
{
	bool gender = true;// 真  1
	bool sex = false;  //  假  0

	cout<<(gender?"帅哥":"美女")<<endl;//
}
```



### 4.2 将bool换成字母/数字形式输出：boolalpha() /noboolalpha()

```
#include<iostream>
using namespace std;
int main()
{
	bool gender = true;
	bool sex = false;
	cout<<boolalpha<<gender<<endl;	//true
	cout<<sex<<endl;				//false
}
```

**因为执行一次boolalpha会导致后面所有的bool都以字母形式输出，所以我们（若需要）要把字母输出转回数字形式输出！！**



```
#include<iostream>
using namespace std;
int main()
{
	bool gender = true;
	bool sex = false;
	cout<<boolalpha<<gender<<endl;	//true
	cout<<sex<<endl;				//false
	
	bool c = true;
	cout<<noboolalpha<<c<<endl;		//1
}
```





## 5. 回顾：

### 5.1 整型存储/溢出



#### 5.1.1 unsigned char溢出

unsigned char 0~255

溢出后的数会以2^(8*sizeof(type))作模运算，也就是对256取模



#### 5.1.2 signed char溢出

signed char -128~127



[(33条消息) C语言中的整型溢出和移位溢出_c语言移位溢出_x简淡的博客-CSDN博客](https://blog.csdn.net/u013658041/article/details/78116449)



### 5.2 整数交换

异或法：

```
a = a^b;
b = a^b;
a = a^b;
```

第三个变量

```
int swap = a;
a = b;
b = swap;
```



### 5.3 const和#define区别



### 5.4 内存溢出/泄露/垃圾



## 6. 字符串类string

string类：**不是基本数据类型！！！是类类型，对象类型**

```
#include <string>
```

### 6.1 创建string对象的方法

```
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s1 = "hello world"; 
	//s1是string类型的对象，用字符串”hello world”初始化
	
	string s2("hello farsight");
	//s2是string类型的对象，用字符串”hello farsight”初始化
	
	string s3(s2);//s3是用s2复制的string类型对象
	
	string s4 = s3;//s4是用s3复制的string类型对象
		
	cout<<s1<<endl;//hello word
	cout<<s2<<endl;//hello farsight
	cout<<s3<<endl;//hello farsight
	cout<<s4<<endl;// hello farsight
}
```



```
string s3(4, 'K');  // s3 = "KKKK"

string s4("12345", 1, 3);  
//s4 = "234"，即 "12345" 的从下标 1 开始，长度为 3 的子串
```



错误写法：

```
string s1('K');
string s2(123);
```



### 6.2 风格转换: c_str()

string转换成C风格字符串

```
.c_str()
```



例子：

sprintf不能用于string类型参数，需要转换成C风格字符串

```
#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main()
{
	string s1 = "hello world";
	char buf[100];
	sprintf(buf,"s1 = %s",s1.c_str());//sprintf函数不接受string类型参数，但是我们又要将string类型格式化，所以这里需要将string类型对象转换成C风格字符串。
	cout<<buf<<endl;
}
```



### 6.3 赋值(=)

```
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s = "hello world";  
	string s2 = "hello farsight";
	s2  =  s; //使用s给s2赋值
	cout<<s2<<endl;//hello world
}
```



### 6.4 拼接(+)(+=)

**注意：string拼接只能拼接string**，如果需要拼接其他类型，需要先转换风格（sprintf）

```
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s1 = "hello";
	string s2 = " world";
	s1 += s2;//把s2的字符串追加到s1后面
	cout<<s1<<endl;//hello world

s1 += 1;//错误 string类型的拼接，只能拼接string类型或者C风格字符串
	//char buf[100];
	//sprintf(buf,"%s %d",s1.c_str(),1);
	//cout<<buf<<endl;//hello1
}
```



### 6.5 比较字符串大小

```
==, >, <, ...

返回true/false
```





### 6.6 判断是否为空：empty()

```
#include <iostream>
using namespace std;

int main()
{
	string s2 = "";
	cout<<s2.empty()<<endl;  //1
	
	string s3("");
	cout<<s3.empty()<<endl;  //1
}
```



### 6.7 判断string长度：.size()

```
string s3 = "hello world";   
cout<<s3.size()<<endl;  // 11
```



### 6.8 string类类型的大小: sizeof()

不同的编译器不一样？

4, 32, 28都可能



### 6.9 获取string中某一个字符

直接用下标



## 7. C++结构体

C++的结构体中可以写函数

```
struct Book
{
	char name[20];		//string name;
	char author[30];	//string author
	int price;
	//c++中的结构体中，可以写函数
	void show()
	{
		cout<<"hello"<<endl;
	}
};
```



主函数声明时不需要写struct关键字

```
int main(int argc, const char *argv[])
{
	//1.使用ｃ的方式初始化　
	//构造函数去初始化
	Book b = {"西游记","吴承恩",10};
	cout<<b.name<<" "<<b.price<<endl;

	//2.调用函数
	b.show();

	//3.定义指针ｐ　指向结构体ｂ
	Book *p = &b;
	cout<<p->name<<" "<<p->price<<endl;
	p->show();

	//4.整体赋值
	Book c = b;
	cout<<c.name<<" "<<c.price<<endl;

	//5.更改ｃ中name－－》tom
	//	c.name = "tom";//?
	strcpy(c.name,"tom");
	cout<<c.name<<endl;
	
	return 0;
}
```





## 8. 引用 Reference

### 8.1 概念

某个已存在变量的另一个名字

C++之所以增加引用类型， 主要是把它作为函数参数，以扩充函数传递数据的功能。



**引用可以看做是数据的一个别名，通过这个别名和原来的名字都能够找到这份数据。**

引用类似于 Windows 中的快捷方式，一个可执行程序可以有多个快捷方式，通过这些快捷方式和可执行程序本身都能够运行程序；引用还类似于人的绰号（笔名），使用绰号（笔名）和本名都能表示一个人。



### 8.2 特点整理

* 必须初始化

* 引用不能单独存在，也不能改变指向（引用的地址永远不变）

* 普通引用不能用常量或者临时值来初始化

  ```
  // int &p  =1;     //用常量初始化，报错
  
  int a = 10;
  int &p =a+1;       //用临时值初始化，报错
  ```

  



### 8.3 普通引用

只要a的引用（b）改变，那么a也改变。

```
int main(int ar0gc, char const *argv[])
{
    /* code */
    int a = 10;
    int &b = a;
    cout<<a<<endl;	//10
    cout<<b<<endl;	//10

    cout<<&a<<endl;
    cout<<&b<<endl;

    int c = 20;
    b =c;
    cout<<b<<endl;  //20，但只是赋值操作，指向没有改变
    cout<<&b<<endl; //没变

    cout<<a<<endl;      //20
    cout<<&a<<endl;     //没变
	
    return 0;
}
```



### 8.4 引用作为函数的参数

交换两个数

```
void swap(int& a, int& b)
{
	int t
    t = a；
    a = b;
    b = t;
}

int main()
{
	int m = 10, n = 20;
	swap(m, n);
	cout<<m<<" "<<n<<endl;
	return 0;
}
```

函数中的a和b就是在使用实参本身



### 8.5 作为函数的返回值

引用作为返回值，是返回变量本身，而不是一个临时的值，要保证变量的生命周期足够长。



```
#include<iostream>
using namespace std;

int& max(int& x)
{
	x = 90;
	return x;
}
int main()
{
	int a = 3;
	//如果返回值不是引用，是不能像下面这么赋值的！！
	max(a) = 8 ; //因为返回值是引用，不是一个临时的值，所以可以直接对返回值赋值 
	cout<<a<<endl;//返回值是a本身，所以上一行是对a赋值，所以这里输出8
}
```



**注意**，引用作为函数返回值时，不能返回局部数据（例如局部变量、局部对象、局部数组等）的引用。因为当函数调用完成后局部数据就会被销毁，有可能在下次使用时数据就不存在了

```
#include <iostream>
using namespace std;
int &plus10(int &r) {
    int m = r + 10;
    return m;  //返回局部数据的引用
}
int main() {
    int num1 = 10;
    int num2 = plus10(num1);
    cout << num2 << endl;
    int &num3 = plus10(num1);
    int &num4 = plus10(num3);
    cout << num3 << " " << num4 << endl;
    return 0;
}
```

我们期待的是

```
20
20 30
```

但不同编译器的结果不同，且会错误



### 8.6 常引用

const修饰的引用

#### 8.6.1 做形参

```
#include<iostream>
using namespace std;
void fun(const int &y)
{
	y = 90; //语法错误，引用是const修饰的，不能用引用去改变实参的值
}
int main()
{
	int a = 100;
	fun(a);
	cout<<a<<endl;
	return 0;
}
```



#### 8.6.2 常引用初始化

修饰常量/临时变量





## 9. 动态内存

### 9.1 new

```
int *p  = new int();        //不写()则会是随机值（未初始化）
cout<<*p<<endl;
cout<<p<<endl;

int*q = new int(10);        //可以直接赋值
cout<<*q<<endl;
cout<<q<<endl;
```



指针指向一个数组，长度为10个int

```
int *pia = new int[10]; // 每个元素都没有初始化

int *pia2 = new int[10] ();  // 每个元素初始化为0
```



### 9.2 delete 释放内存

delete之后去解引用还能访问到的原因：
delete操作只是释放掉了堆中的空间，并不会将指针p的值置为NULL；
所以p仍然指向堆中对应的位置，但是注意这个位置已经被回收了，可以随时分配给别的对象。所以delete之后最好置为NULL。

```
delete ptr;
ptr = NULL;
```





## 10. 重载



## 11. 函数的默认参数

[C++函数的默认参数详解 (biancheng.net)](http://c.biancheng.net/view/2204.html)



默认参数给值顺序：从右到左

最右的形参如果没有给值，则前面的都不能给值





实参给值顺序：从左到右



### 带函数声明时：



## 12. 类

### 12.1 类的定义

```
class Person
{
public:
	//成员变量　属性
	string name;
	int age ;
	int arr[4];  //栈空间数组
	int *p;  //指针指向数组空间
	void init()
	{
		//cin>>arr[i];
		//动态分配空间　进行赋值
		 p = new int[4];//堆空间
		for(int i = 0; i < 4; i++)
			cin>>p[i];
	}
	//输出函数，输出数组中　的所有值
	void print()
	{
		for(int i = 0; i < 4; i++)
			cout<<p[i]<<endl;
	}
	
	//释放空间函数　delete[] p;
	void release()
	{
		delete[] p;
	}
	
	//成员函数　行为 给成员变量ｎａｍｅ进行赋值
	void setName(string n)//小明
	{
		name = n;
	}
	void show()
	{
		//输出成员变量
		cout<<age<<endl;		
	}
};

//类外
int main()
{
	//2.栈空间　创建(实例化)类对象
	Person p;	
	//3.调用类成员　　进行赋值
	//p.name = "小明";
	//4.调用成员函数　进行赋值
	p.setName("小明");
	//cout<<p.name<<endl;
	p.show();

	p.init();
	p.print();
	p.release();
}
```

注意：

1. 如果成员变量/函数为声明public，则默认为private

2. 定义类时，不可以直接对成员变量初始化，只能通过函数形似传值（初始化）

   ```
   class Student
   {
   	string name = "hangyu";		//报错
   }
   ```

3. 构造函数必须是public



### 12.2 class和struct区别

class从struct扩展而来

1. 使用时机不同

   存储数据的轻量级对象时，首选struct；

   数据量大、逻辑复杂的大对象时，首选class

   抽象和多级别的对象层次时，class是最佳选择

   

2. 默认访问权限不同

   class不声明权限时默认为private，struct为public

​	

### 12.3 不同的访问权限

Public：公有，任何位置都可以访问

protected：派生类和类的内部可以访问

private，只有本类的内部可以访问

类的内部：类的成员函数

|           | 类的内部 | 派生类 | 全局   |
| --------- | -------- | ------ | ------ |
| public    | 可以     | 可以   | 可以   |
| protected | 可以     | 可以   | 不可以 |
| private   | 可以     | 不可以 | 不可以 |

**访问权限定的越小越好**：数据安全



### 12.4 面向对象的三大特征

封装，继承，多态

#### 12.4.1 封装

1）封装函数

将一系列重复性的代码封装成函数

2）封装类

将具有相同属性和行为的一系列对象封装成一个类。

多态，封装父类，通过子类继承并重写的方式，实现复杂逻辑的传递



例子：

创建一个类Product,成员变量name,price,使用set和get进行赋值与获取,在主函数创建两个产品对象并赋值，打印。

```
#include <iostream>
using namespace std;
class Product
{
private:
	string name;
	int price;
public:
	void setName(string n)
	{
		name = n;
	}
	string getName()
		{
		return name;
	}
	void setPrice(int p)
	{
		price = p;
	}
	int getPrice()
	{
		return price;
	}
};
int main()
{
	Product p1;
	p1.setName("手抓饼");
	p1.setPrice(6);

    //堆空间
    Product *p4 = new Product;
    p4->setName("香蕉");
    p4->setPrice(5);
    cout<<p4->getName()<<" "<<p4->getPrice()<<endl;
	delete p4;

	Product p2;
	p2.setName("烤冷面");
	p2.setPrice(7);

	cout<<p1.getName()<<" "<<p1.getPrice()<<endl;
	cout<<p2.getName()<<" "<<p2.getPrice()<<endl;

	return 0;
}
```



### 12.5 分文件定义类

#### 12.5.1 类外部实现成员变量

```
class Person
{
private:
	int age;
public:
	void setAge(int a);//类的内部只做函数的声明
	void show();
};

void Person::setAge(int a)//Person:: 告诉编译器，这是Person类中的成员函数
{
	age = a;
}

void Person::show()
{
	cout<<age<<endl;
}

int main()
{
	Person* p = new Person;
	p->setAge(18);
	p->show();
}
```



#### 12.5.2 分文件

三个文件：main.cpp, person.h, person.cpp

1) person.h负责声明类

   ```
   #ifndef PERSON_H
   #define PERSON_H
   
   class Person
   {
   private:
   	int age;
   public:
   	void setAge(int a);
   	void show();
   };
   
   #endif
   ```

   

2) person.cpp负责完成类中声明的函数

   ```
   #include "person.h"
   #include <iostream>
   
   using namespace std;
   
   void Person::setAge(int a)
   {
   	age = a;
   }
   
   void Person::show()
   {
   	cout<<age<<endl;
   }
   ```

   

3) main.cpp负责初始化类并完成功能

   ```
   #include <iostream>
   #include "person.h"
   
   int main()
   {
   	Person* p = new Person;
   	p->setAge(18);
   	p->show();
   }
   ```

   



### 12.6 构造函数constructor



[C++构造函数详解 (biancheng.net)](http://c.biancheng.net/view/2221.html)

回顾创造string时可以写作：

```
string s("hello");
```



```
#include <iostream>

using namespace std;

class Person
{
private:
    int age;
public:
    Person()
    {
        age = 18;
        cout<<"create1"<<endl;
    }
    Person(int a)
    {
        age = a;
        cout<<"create2"<<endl;
    }
    void show()
    {
        cout<<age<<endl;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    Person *p = new Person();
    p->show();

    Person *p1 = new Person(30);
    p1->show();

    Person p3;
    p3.show();

    Person p4(40);
    p4.show();

    return 0;
}
```

输出：

```
create1
18
create2
30
create1
18
create2
40
```



无参构造和默认参数的有参构造会造成冲突，不算重载overload:

<img src="C:\Users\henry0408\AppData\Roaming\Typora\typora-user-images\image-20230525161117153.png" alt="image-20230525161117153" style="zoom:50%;" />

这样会报错模糊：ambiguous



#### 构造函数的类外实现

```
Person::Person()
{
	age = 20;
	cout<<"cout1"<<endl;
}

Person::Person(int a)
{
	age = a;
	cout<<"cout2"<<endl;
}
```



### 12.7 初始化列表

顺序遵循成员变量定义的顺序

```
class CExample {
public:
    int a;
    float b;
    //构造函数初始化列表
    CExample(): a(0),b(8.8)
    {}
    //构造函数内部赋值
    CExample()
    {
        a=0;
        b=8.8;
    }
};
```

上面两种定义方式的效果相同。



如果外部实现成员函数：

```
Person(int a,string n);

Person::Person(int a,string n):age(a),name(n)
{
	cout<<"two,..."<<endl;
}
```





## vscode配置

多个cpp文件同时编译：

安装：C/C++ Runner

![image-20230525152907695](C:\Users\henry0408\AppData\Roaming\Typora\typora-user-images\image-20230525152907695.png)

运行：点击下方的齿轮按钮，之后点击旁边的运行

![image-20230525152823202](C:\Users\henry0408\AppData\Roaming\Typora\typora-user-images\image-20230525152823202.png)





## ifndef作用

a.h

```
#include <iostream>
#include "b.h"

int i = 5;
Boy b;

struct Girl
{
    int age;
};
```

b.h

```
#include <iostream>

struct Boy
{
    int age;
};
```

main.cpp

```
#include "a.h"
#include "b.h"
#include <iostream>

int main(int argc, char const *argv[])
{
    /* code */
    Boy c;
    c.age = 10;
    Girl g;
    g.age = 20;
    return 0;
}

```

报错：

![image-20230525154727635](C:\Users\henry0408\AppData\Roaming\Typora\typora-user-images\image-20230525154727635.png)

改正：

b.h中

```
#ifndef PERSON_H
#define PERSON_H
#include <iostream>

struct Boy
{
    int age;
};
#endif
```



## 13. Qt基本操作

创建一个项目

![image-20230527215145411](C:\Users\henry0408\AppData\Roaming\Typora\typora-user-images\image-20230527215145411.png)

![image-20230527215203572](C:\Users\henry0408\AppData\Roaming\Typora\typora-user-images\image-20230527215203572.png)

输入名称，路径

![image-20230527215239611](C:\Users\henry0408\AppData\Roaming\Typora\typora-user-images\image-20230527215239611.png)

源文件右键，添加新文件

![image-20230527215309746](C:\Users\henry0408\AppData\Roaming\Typora\typora-user-images\image-20230527215309746.png)

输入class name后：

![image-20230527215459974](C:\Users\henry0408\AppData\Roaming\Typora\typora-user-images\image-20230527215459974.png)

![image-20230527215535679](C:\Users\henry0408\AppData\Roaming\Typora\typora-user-images\image-20230527215535679.png)



切换运行的项目：

![image-20230529103908582](C:\Users\henry0408\AppData\Roaming\Typora\typora-user-images\image-20230529103908582.png)



class分文件定义，快速完成成员函数初始化：

![image-20230529140816114](C:\Users\henry0408\AppData\Roaming\Typora\typora-user-images\image-20230529140816114.png)

Ctrl+右键选中函数名，Refactor-->





## 14. this指针

```
/*Person类，包含私有属性：姓名name，性别bool gender，年龄age，另一个对象的指针 Person *lover;
        1.构造函数初始化成员变量 name gender
        2.成员函数setAge给年龄赋值
        3.成员函数marry(Person& other)    输出name"和"other.name"喜结良缘!";
        4.成员函数show(); 输出"大家好！我是"gender，name，今年"age;
                          输出"爱人是:"lover->name;
private:
        string name;
        bool gender;
        int age;
        Person *lover;手指头
 *
 */

#include <iostream>

using namespace std;

class Person
{
private:
    string name;
    bool gender;
    int age;
    Person *lover;
public:
    Person(string name, bool gender)
    {
        this->name = name;
        this->gender = gender;
    }

    void set_age(int age)
    {
        this->age = age;
    }

    void marry(Person *lover)
    {
        this->lover = lover;
        cout<<this->name<<" "<<lover->name<<" get married"<<endl;
    }

    void show()
    {
        cout<<"Hi, I am "<<this->name<<" age is: "<<this->age<<" my lover is: "<<this->lover->name<<endl;
    }
};


int main()
{
    cout << "Hello World!" << endl;

    Person p1("Jack", 1);
    Person p2("Alice",0);
    p1.marry(&p2);

    p1.set_age(20);
    p1.show();
    return 0;
}
```



使用引用：

![image-20230529103744252](C:\Users\henry0408\AppData\Roaming\Typora\typora-user-images\image-20230529103744252.png)



## 15. 拷贝构造函数copy constructor

是一种构造函数，函数名是类名，无返回值，参数形式固定

```
class Object
{
public:
	Object(const Object& other);	
}
```

以一个对象为蓝本，构建另一个对象：

```
Objeect b;
Object a(b);	//与Object a = b相同
```

此时，a是b的备份，两者内容完全相同



拷贝构造函数从来不显式调用，都是由编译器隐式地调用。

### 15.0 **三种拷贝构造函数的调用：**

* 定义对象时
* 函数的参数为类对象时
* 函数的返回值为类对象时



### 15.1 定义对象时

````
class Student
{
private:
	string name;
public:
	Student(string name)
	{
		this->name = name;
		cout<<"create"<<endl;	
	}
	Student(const Student& other)		//拷贝构造
	{
		this->name = other.name;
		cout<<"copy"<<endl;
	}
	void show()
	{
		cout<<name<<endl;
	}
};
````

```
int main()
{
    Student s1("xm");
	
	//栈空间
    Student s2 = s1;
    s2.show();

    Student s3(s1);
    s3.show();

    Student *s5 = new Student("tom");
    Student *s4 = new Student(*s5);		//堆空间

    Student *s6 = new Student(s1);		

    Student *s7 = s5;
    s7->show();			//不拷贝
}
```

输出：

```
create
-------------
copy
xm
-------------
copy
xm
-------------
create
tom
-------------
copy
tom
-------------
copy
xm
-------------
tom
-------------
```

理解此题，需要先了解15.1.1中的内容



#### 15.1.1 几种构造函数以及使用时机

**注意：**创建对象的时候，只会调用一个构造函数



* 默认构造函数：一个构造函数都没有

  ```
  class Student
  {
  private:
      string name;
  public:
      void show()
      {
          name = "hangyu";
          cout<<name<<endl;
      }
  };
  
  int main()
  {
      Student s1;
      s1.show();
      cout<<"-------------"<<endl;
  ```

  此时使用

  ```
  Student s2 = s1;
  ```

  会报错，因为默认拷贝构造函数不会使用。

  

* 显式构造函数：

  ```
  Person(int age, string name);
  ```



* 默认拷贝构造函数：

  没有显式拷贝构造函数时，编译器会自动生成一个拷贝构造函数，将各个成员变量赋值

  ```
  #include <iostream>
  
  using namespace std;
  
  class Student
  {
  private:
      string name;
  public:
      Student(string name)
      {
          this->name = name;
          cout<<"create"<<endl;	
      }
  
      void show()
      {
          cout<<name<<endl;
      }
  };
  
  int main()
  {
      Student s1("xm");
      cout<<"-------------"<<endl;
  
      Student s2 = s1;
      s2.show();
      cout<<"-------------"<<endl;
  }
  ```

  

* 显式拷贝构造函数

  如果显式的定义拷贝构造函数，并且运行时执行了拷贝构造函数，那么默认拷贝构造函数和默认构造函数都不会被调用了。

  

  写了拷贝构造的时候，默认的构造函数还在不？  不在了

  ```
  详情看15.1中的s2,s3,s4,s5,s6
  只输出copy
  ```





#### 15.1.2 区分构造与赋值

构造：调用拷贝构造函数

```
Object a;
Object b = a;
```

赋值：（不会调用拷贝构造函数）

```
Object a;
Object b;
b = a;
```





### 15.2 函数的参数为类对象时

```
#include <iostream>

using namespace std;

class Student
{
private:
    string name;
public:
    Student(string name)
    {
        this->name = name;
        cout<<"create"<<endl;	//隐式拷贝构造，如果有显式，则不调用
    }
    Student(const Student& other)		//拷贝构造
    {
        this->name = other.name;
        cout<<"copy"<<endl;
    }
    void show()
    {
        cout<<name<<endl;
    }
};


void fun(Student s)
{
    s.show();
}

void fun1(Student& s)
{
    s.show();
}

int main()
{
    Student s1("xm");
    cout<<"-----------------"<<endl;

    fun(s1);
    cout<<"-----------------"<<endl;

    fun1(s1);		//不调用拷贝构造，因为s1是已经存在的
    cout<<"-----------------"<<endl;

    fun(Student("xh"));

}
```

输出：

```
create
-----------------
copy
xm
-----------------
xm
-----------------
create
xh
```



我们发现，如果参数是类的引用，则不会调用拷贝构造。原因是引用只是一个别名（地址相同），不会创建出一个新的对象。而值传递会创建一个临时变量（类），所以会调用拷贝构造函数。



### 15.3

```
#include <iostream>

using namespace std;

class Student
{
private:
    string name;
public:
    Student(string name)
    {
        this->name = name;
        cout<<"create"<<endl;	//
    }
    Student(const Student& other)		//拷贝构造
    {
        this->name = other.name;
        cout<<"copy"<<endl;
    }
    void show()
    {
        cout<<name<<endl;
    }
};


Student fun()
{
    Student s("xq");
    return s;
}

Student fun1()
{
    Student *s = new Student("xl");
    return *s;
}

int main()
{
    fun();
    
    fun1();
}
```



是否调用拷贝构造取决于声明周期。在栈上创建，声明周期只有当前函数。而在栈上构造，生命周期大于函数。





## 16 析构函数destructor

