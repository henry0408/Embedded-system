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

  ```
  int main()
  {
  	int a=100;
  	int &ref = a ;//1.引用必须初始化
  	
  	int b = 78;
  	ref = b;    //2.引用不可以改变方向，此行相当于使用b给变量a赋值
  	cout<<a<<endl;//78
  }
  ```

  

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

进一步理解引用：

```
int &a = b
```

相当于常量指针：

```
int *const a = b;
```

而常引用：const int &a=b就相当于 const int * const a=b。不仅仅是a这个地址不可修改，而且其指向的内存空间也不可修改



引用变量：

```
#include <iostream>
using namespace std;

int main()
{
	int a = 10;
	const int& b = a;// 对
	//b = 20;  // 错
	a = 30;	// 对
	cout<<a<<b<<endl;// 30 30
}
```



引用常量：

```
  #include<iostream>
using namespace std;

void main()
{
	//const引用 常量
	const int &c = 15;
	//编译器会给常量15开辟一片内存，并将引用名作为这片内存的别名
	//int &d=15			//报错
}
```





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





## 10. 重载Overload

函数名可以相同，提高复用性



### 10.1 满足条件：

* 同一个作用域下

* 函数名称相同

* 参数类型不同/个数不同/顺序不同



**注意：**返回值不可以作为函数重载的条件



```
void func()
{
	cout<<"func1"<<endl;
}

void func(int a)
{
	cout<<"func2"<<endl;
}

int main()
{
	func();
	func(10);
}
```



### 10.2 引用作为重载条件

```
void fun(int &a)
{
	cout<<"func1"<<endl;
}

void fun(const int &a)
{
	cout<<"func2"<<endl;
}

int main()
{
	int a = 10;
	func(a);		//调用func1
	
	func(10);		//调用func2
}
```

原因如下：

回顾：

```
int &a = 10;		//不合法

const &a = 10;		
//合法，编译器优化，相当于int &b = 10, const &a = b;
```



所以直接传入10，相当于传入一个常量，必须用const修饰



### 10.3 函数重载碰到默认参数

```
void fun(int a, int b=10)
{
	cout<<"func1"<<endl;
}

void fun(int a)
{
	cout<<"func2"<<endl;
}

int main()
{
	fun(10);		//报错，出现二义性
	fun(10,20);		//不报错
}
```





## 11. 函数的默认参数

[C++函数的默认参数详解 (biancheng.net)](http://c.biancheng.net/view/2204.html)



默认参数给值顺序：从右到左

最右的形参如果没有给值，则前面的都不能给值



```
int fun(int a, int b = 5, int c = 10)
{
	return a+b+c;
}
```

正确



```
int fun(int a, int b = 5, int c)
{
	return a+b+c;
}
```

报错。



实参给值顺序：从左到右



### 11.1 带函数声明时：

```
int fun(int a, int b = 5, int c = 10);

int fun(int a, int b = 5, int c = 10)
{
	return a+b+c;
}
```

报错



声明有默认参数，实现就不能有默认参数。

实现有默认参数，声明就不能有默认参数。

声明和实现只能有一个有默认参数



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



无参构造可以和有参构造形成overload，但是注意以下情况：

无参构造和默认参数的有参构造会造成冲突，不算重载overload:

<img src="C:\Users\henry0408\AppData\Roaming\Typora\typora-user-images\image-20230525161117153.png" alt="image-20230525161117153" style="zoom:50%;" />

这样会报错模糊：ambiguous，删去有参构造的默认参数即可



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
	Object(){};	//注意：必须写一个构造函数，只写拷贝构造会报错
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



声明时必须写一个构造函数，只写拷贝构造会报错



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



有显式构造，默认构造不存在；

有显式拷贝构造，默认拷贝构造依旧存在！！！



#### 15.1.2 区分构造与赋值

构造：调用拷贝构造函数

```
Object a(1);
Object b(1) = a;
```

赋值：（不会调用拷贝构造函数）

```
Object a(1);
Object b(2);
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
```



我们发现，如果参数是类的引用，则不会调用拷贝构造。原因是引用只是一个别名（地址相同），不会创建出一个新的对象。而值传递会创建一个临时变量（类），所以会调用拷贝构造函数。



#### 15.2.1 匿名对象作为构造函数参数

匿名对象，不会调用拷贝构造

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
    fun(Student("xh"));		//匿名对象，不会调用拷贝构造

}
```

输出：

```
create
xh
```





### 15.3 函数返回值是类的对象

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
    Student s("xq");	//栈空间
    return s;
}

Student fun1()
{
    Student *s = new Student("xl");		//堆空间
    return *s;
}

int main()
{
    fun();
    cout<<"--------------"<<endl;
    
    fun1();
}
```

输出：

```
create
--------------
create
copy
```

是否调用拷贝构造取决于声明周期。



在栈上创建，生命周期只有当前函数。而在堆上构造，生命周期大于函数（堆空间生命周期直到delete才结束）。



### 15.4 总结

格式：Person(const Person& other)

1. 创建对象

```
person p1 ;

person p2= p1;

person p3(p1);
```



2) 函数的参数是对象类型

```
void fun(person p)拷贝构造

fun(p1);

void fun(person& p)不调用拷贝构造

fun(p1);
```



3)返回值是对象

```
person fun(){

​	返回栈空间对象  --》 没有拷贝

​	返回堆空间对象  --》 调用拷贝

}
```



有显式构造，默认构造不存在；

有显式拷贝构造，默认拷贝构造依旧存在！！！



### 15.5 例题

#### 15.1.1

```
有如下类的定义：
class MyClass
{
 	int value;
public:
	MyClass(int n):value(n){}
	int getValue() {return value;}
};
则类 MyClass的构造函数的个数是：（  ）
A 1个       B 2个         C   3个       D    4个
```

答案：

```
B
分别是：有参显式构造，默认拷贝构造

注意，没有默认构造是因为有显式构造
```



有显式构造，默认构造不存在；

有显式拷贝构造，默认拷贝构造依旧存在！！！



#### 15.1.2

```
2.以下代码共调用多少次拷贝构造函数：  
Widget f(Widget u)  //1  
{  
   Widget v(u);  //2  4
   Widget w=v;  //3  5
   return w; //
}
int main(){
    Widget x;
    Widget y = f(f(x));  
}
A.1         B. 3        C. 5         D.  7
```

答案：

```
C（优选）和 D

七次的原因：
f(x):1次
v(u):1次
w = v:1次
return w:不算，因为在栈空间
f(w): 1次
v(u)：1次
w = v：一次
y = f(f(x))：一次

五次的原因：
第二次运行Widget f(Widget u)时，会被编译器优化掉
执行y = f(f(x))时，又会被优化掉
```



## add: 构造函数调用方法总结：

```
class A
{
public:
    A(int a)
    {
        cout<<"create"<<endl;
    }
    A(const A& other)
    {
        cout<<"copy"<<endl;
    }
};

int main()
{
    A a1 = A(10);   //显式有参构造
    A a2 = A(a1);

    A a3 = 10;      //隐式法
    A a4 = a3;

    A a5(a4);
}
```

输出：

create
copy
create
copy
copy



## 16. 私有构造函数和私有拷贝构造函数

私有构造函数：不能在类外创建对象

```
#include <iostream>
using namespace std;

class Person
{
private:
	int age;
private:
	Person(int age)
	{
		this->age = age;
		cout<<"构造"<<endl;
	}
public:
Person()
{}
public:
	Person(const Person& other):age(other.age)
	{
		cout<<"拷贝构造"<<endl;
	}

	void show()
	{
		cout<<this->age<<endl;
	}
};

int main()
{
	Person p(19);//报错  因为匹配到的构造函数是私有的
	Person p2;//不报错，因为去匹配的构造函数是公有的
}
```



私有拷贝构造函数：不能在类外复制对象

```
#include <iostream>
using namespace std;

class Person
{
private:
	int age;
public:
	Person(int age)
	{
		this->age = age;
		cout<<"构造"<<endl;
	}
private:
	Person(const Person& other):age(other.age)
	{
		cout<<"拷贝构造"<<endl;
	}
	void show()
	{
		cout<<this->age<<endl;
	}
};

int main()
{
	Person p(19);
	Person b = p;//报错 不能复制对象
}
```



## 17. 深拷贝和浅拷贝

### 17.1 浅拷贝

两个对象地址一样。

拷贝对象的时候，不对指针成员所指向的对象进行拷贝，两个对象的指针成员指向的是同一个对象



### 17.2 深拷贝





## 19 析构函数destructor

作用与构造函数相反，处理”清理“工作



没有返回值，名字必须与类名相同，**没有参数所以不能被重载**

```
~Person()
{
	cout<<”destructor"<<endl;
}
```

调用时机：对象脱离作用域时，自动被调用

主要负责释放内存



#### 19.1 作用域

可以定义`{}`划定作用域

```
#include<iostream>
using namespace std;

class A
{
public:

    int *p;
     A()
     {
         cout<<"A"<<endl;
         p = new int[4];
     }
	
	//析构函数
    ~A()//用于释放类内部分配的堆空间
    {
        //释放数组空间
         delete[] p;
    }
};
int main()
{
    //栈空间对象
    //作用域
    {
         A a;	
    }			//调用析构函数
   cout<<"0---------------"<<endl;

   //堆空间 手动释放
   A *p = new A;
   delete p;//调用析构函数
}
```

输出：

~~~~
A
0---------------
A
~~~~

发现调用了两次析构函数：

第一次：{A a}结束，说明作用域结束

第二次：delete p结束，说明堆空间变量的作用域结束



## 20. 匿名对象

```
类型(构造函数的参数列表)
```

匿名对象的生命周期非常的短(临时的值)



### 20.1 作用：

赋值，初始化，传参数



## 21. 类成员初始化顺序





## 22. const

常函数，常对象，常引用，常量



描述一下常函数与常对象？

常函数const修饰在形参列表的后面，常函数中的成员变量不能被修改。

常对象const可以修饰在类的前面或类的后面，对象中的成员属性不能被修改。



### 22.1 常量

变量被const修饰变为常量，值被初始化后，不能再修改。

```
const type variable = value;
```



### 22.2 常引用

见 8.6，可以指向常量也可以指向变量

指向之后，不可以改变指向，也不可以改变值。但变量本身可以修改值

```
int main()
{
	int a = 10;
	const int& b = a;// 对
	//b = 20;  // 错
	a = 30;	// 对
	cout<<a<<b<<endl;// 30 30
}
```

常引用初始化可以用表达式：

```
int main()
{	
	int a = 10;
	int& c = a + 2;		//  错
	const int& c = a + 2;// 对
	cout<<c<<endl; 
}
```





### 22.3 常函数

常函数只能调用常函数，常函数不能修改成员变量的值

```
#include <iostream>

using namespace std;

class Person
{
    int age;
public:
    Person(int age):age(age)
    {}

    //常函数，不可以修改成员变量
    void show() const
    {
        //age++;              //error
        setAge(1);				//也报错
        cout<<age<<endl;
    }

    void setAge(int a)
    {
        age += a;
    }

};

int main()
{
    Person p(18);
    p.show();
    return 0;
}
```



可以的用法：常函数只能调用常函数

```
#include <iostream>

using namespace std;

class Person
{
    int age;
public:
    Person(int age):age(age)
    {}

    //常函数，不可以修改成员变量
    void show() const
    {
        setAge();
        cout<<age<<endl;
    }

    void setAge() const
    {
        cout<<age<<endl;
    }

};

int main()
{
    Person p(18);
    p.show();
    return 0;
}
```



常函数可以和普通函数成为某种特殊意义的重载，同时存在时，普通对象优先调用普通的函数。

```
#include <iostream>

using namespace std;

class Person
{
    int age;
public:
    Person(int age):age(age)
    {}

    //常函数，不可以修改成员变量
    void show() const
    {

        cout<<age<<endl;
    }
    //普通函数
    void show()
    {
        age++;
        cout<<age<<endl;
    }

};

int main()
{
    Person p(18);
    p.show();
    return 0;
}
```

输出：

```
19
```





### 22.4 常对象

```
const 类名 对象名(实参)
类名 const 对象名(实参)
```

功能：希望对象所有成员的值不被修改



成员必须有初始值，只能调用常成员函数 (const修饰的常函数)

```
#include <iostream>

using namespace std;

class Person
{
    int age;
public:
    Person(int age):age(age)
    {}

    //常函数，不可以修改成员变量
    void show() const
    {
        cout<<age<<endl;
    }

    void setAge(int a)
    {
        age += a;
    }
    
    void add()
    {
    	cout<<age<<endl;
    }

};

int main()
{

    const Person p1(28);
    p1.show();
    //p1.setAge(2);       //使用时报错
    //p1.add();				//使用时报错
    return 0;
}
```



普通对象既可以调用普通函数，也可以调用常函数



### 22.3 打破const限制：mutable

mutable修饰的成员变量是可以在常函数中被修改的

```
#include <iostream>

using namespace std;

class Person
{
    mutable int age;
public:
    Person(int age):age(age)
    {}

    //常函数，不可以修改成员变量
    void show() const
    {
        age++;
        cout<<age<<endl;
    }
    //普通函数
    void show()
    {
        age++;
        cout<<age<<endl;
    }

};

int main()
{
    Person p(18);
    p.show();

    const Person p1(18);
    p1.show();
    return 0;
}
```

输出：

```
19
19
```



## 23. 友元friend

友元可以访问与其好友关系的对象中的private成员



### 23.1 特点

* 单项性

  ```
  class A
  {
  	friend class B
  };
  class B{};
  ```

  此时B可以访问A的私有，但A不能访问B的私有

  

* 不能传递

  ```
  class A
  {
  	friend class B
  };
  class B
  {
  	friend class C;
  };
  class C {};
  ```

  C可以访问B的私有，B可以访问A的私有。但C不能访问A的私有。

  

* 不能继承

  ```
  class A
  {
  	friend class B
  };
  class B{};
  
  class A继承了C
  ```

  B可以访问A的私有。但B不能访问C的私有



### 23.2 友元函数（友元全局函数）

格式：

```
类中声明：
friend void display(Person& p);

全局中实现
void display(Person& p)
{
    cout<<p.age<<endl;//12
}
```



例子：

```
#include <iostream>

using namespace std;

class Person
{
    friend void display(Person& p);     //友元函数声明
private:
    int age;
public:
    Person(int age):age(age){}
    void show()
    {
        cout<<age<<endl;
    }
};

//全局函数
void display(Person& p)
{
    cout<<p.age<<endl;
}

int main()
{
    Person p(10);
    display(p);
    return 0;
}
```

输出：10



```
#include <iostream>

using namespace std;

class Friend
{
    friend void setAge(Friend& f);
private:
    int age;
public:
    void setAge(int age){this->age = age;}
    void getAge()
    {
        cout<<age<<endl;
    }
};

void setAge(Friend& f)
{
    f.age = 20;
}

int main()
{
    Friend f;
    f.setAge(18);
    f.getAge();

    setAge(f);
    f.getAge();
}
```

输出：

```
18
20
```





#### 例题：

```
/*1.有个学生类Student
    包括：私有成员：姓名 成绩
        void setData(string name, int score)给成员变量赋值,没有初始化列表
        void show();
2.在main定义 student数组5个元素并赋值 Students[5]  使用匿名对象初始化
3.设计一个全局友元函数 比较两个学生的成绩的高低 int compare(Student& a, Student& b);
                    a的成绩>b的成绩 return 1; a<b return -1; 相等 0
4. 求出最高分和最低分的学生
*/


#include <iostream>

using namespace std;

class Student
{
    friend void set_info(Student &p,string name, int score);
    friend int compare(Student& a, Student& b);
private:
    string name;
    int score;
public:
    Student()
    {

    }
    void setData(string name,int score)
    {
        this->name = name;
        this->score = score;
    }

    void show()
    {
        cout<<name<<" "<<score<<endl;
    }
};

void set_info(Student &p,string name, int score)
{
    p.setData(name,score);
}

int compare(Student& a, Student& b)
{
    if(a.score>b.score)
    {
        return 1;
    }
    else if(a.score<b.score)
    {
        return -1;
    }
    else
        return 0;
}

int main()
{
    Student s[5] = {Student(),Student(),Student(),Student(),Student()};
    set_info(s[0],"aa",100);
    set_info(s[1],"bb",200);
    set_info(s[2],"cc",500);
    set_info(s[3],"dd",250);
    set_info(s[4],"ee",300);

    s[0].show();
    s[1].show();
    s[2].show();
    s[3].show();
    s[4].show();

    cout<< compare(s[0],s[1])<<endl;
    return 0;
}
```



### 23.3 友元类

```
friend class 类名
```



例子：

```
#include <iostream>
#include <string>
using namespace std;

//类的声明
class Teacher;
class Student
{
friend class Teacher;
private:
	string name;
	int score;
	void sleep()
	{
		cout<<"slepp"<<endl;
	}
public:
	Student(string name, int score):name(name),score(score){}
};

class Teacher
{
public:
	void look(Student& s)
	{
		cout<<s.name<<" "<<s.score<<endl;	//可以直接取得private
		s.sleep();
	}
};

int main()
{
	Teacher t;
	Student s("小张",19);
	t.look(s);
}
```





![image-20230530114902040](C:\Users\henry0408\AppData\Roaming\Typora\typora-user-images\image-20230530114902040.png)



#### 例题：

1.有个学生类Student 包括私有成员：姓名 成绩 ; Student构造函数对成员赋值
2.设计一个友元类Teacher 
	1)teacher类中包含 私有成员数组 Student s[5]; 构造函数对数组元素赋值
	2)teacher类对学生数组进行排序 公有成员函数sort(); 降序 冒泡排序
	3)teacher类输出成绩对应等级 公有函数show(); 
\>=90 优 80-89 良 70-79中 60-69 及格 <60不及格



student.h

```
#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
using namespace std;

class Student
{
    friend class Teacher;
private:
    string name;
    int score;

public:
    Student(string name, int score);
    ~Student();
};

#endif // STUDENT_H
```

student.cpp

```
#include "student.h"

Student::Student(string name, int score):name(name),score(score){}

Student::~Student()
{

}
```

teacher.h

```
/*2.设计一个友元类Teacher
    1)teacher类中包含 私有成员数组 Student s[5]; 构造函数对数组元素赋值
    2)teacher类对学生数组进行排序  公有成员函数sort(); 降序 冒泡排序
    3)teacher类输出成绩对应等级  公有函数show();
>=90 优 80-89 良  70-79中 60-69 及格  <60不及格
*/


#ifndef TEACHER_H
#define TEACHER_H

#include "student.h"

using namespace std;

class Teacher
{
private:
    Student *s[5];
public:
    Teacher()
    {
        s[0] = new Student("aa",90);
        s[1]= new Student("bb",80);
        s[2]= new Student("cc",70);
        s[3]= new Student("ddd",100);
        s[4]= new Student("eeee",95);
    }

    void swap(Student &a, Student &b);

    void sort();

    void show();

    ~Teacher();
};

#endif // TEACHER_H
```



**注意：**用 Student *s[5]，而不是Student s[5]的原因是：

当创建对象数组的时候直接就会给对象进行初始化（因为没有传递参数，默认调用无参构造函数）举例：person p[5] 调用5次无参构造函数。但由于我们没有定义Student(){}的构造函数，而Student(string name, int score){}的构造函数会覆盖默认构造函数。所以会报错。



teacher.cpp

```
#include "teacher.h"


void Teacher::swap(Student &a, Student &b)
{
    Student tmp = a;
    a = b;
    b = tmp;
}

void Teacher::sort()
{
    for(int i=0; i<5-1; i++)
    {
        for(int j = 0; j<5-1-i; j++)
        {
            if(s[j]->score<s[j+1]->score)
            {
                //swap(*s[j],*s[j+1]);	//如果使用swap函数
                Student *tmp = s[j];
                s[j] = s[j+1];
                s[j+1] = tmp;
            }
        }
    }
}

void Teacher::show()
{
    for(int i = 0; i<5; i++)
    {
        cout<<s[i]->name<<" "<<s[i]->score<<endl;
    }
}

Teacher::~Teacher()
{

}
```

main.cpp

```
#include <iostream>

#include "teacher.h"

#include <iostream>

using namespace std;

int main()
{
    Teacher t;

    t.show();

    t.sort();

    cout<<"----------"<<endl;

    t.show();

    return 0;
}
```



## 24. 异常捕获

### 24.1 什么是异常

异常是程序在执行期间产生的问题。C++ 异常是指在程序运行时发生的特殊情况，比如尝试除以零的操作。

```
if()
{
	throw ;
}

try
{

}
catch()
{

}
```





例子：

```
#include <iostream>

using namespace std;

class ExceptA
{
public:
    void show()
    {
        cout<<"exception A"<<endl;
    }
};

class ExceptB
{
public:
    void show()
    {
        cout<<"exception B"<<endl;
    }
};

int div(int a, int b)
{
    if(b == 0)
    {
        //throw b;        //抛出基本类型异常
        ExceptA a;
        throw a;           //抛出自定义异常
    }
    return a/b;
}

double div(double a, double b)
{
    if(b == 0)
    {
        //throw b;        //抛出基本类型异常
        ExceptB b;
        throw b;           //抛出自定义异常
    }
    return a/b;
}

int main()
{
    try
    {
        div(10,0);
        div(10.0,0.0);
    }
    catch(ExceptA e)
    {
        e.show();
    }

    catch(ExceptB e)
    {
        e.show();
    }


    return 0;
}
```

输出：(注意，只输出一次)

```
exception A
```



例子2：

三角形三条边能否构成三角形

```
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
```



## 25. 静态成员static



### 25.1 静态成员变量

在静态区。

属于整个类。静态成员变量只存储一份供**所有同类对象**使用

必须在**类外**单独初始化，而且只能全局进行。否则不会分配空间 编译报错



```
#include <iostream>
using namespace std;

class A
{
public:
   static int num;
};
//1.初始化之后，才会对变量分配空间 2.类外进行单独的初始化
int A::num = 10;

int main()
{
    //3.使用静态变量，可以直接只用 类::的方式 获取变量
   cout<<A::num<<endl;
 
    return 0;
}
```



### 25.2 静态成员函数

```
static int getNum()
{
}

//获取
类名::函数名()
```



不能使用this指针，所以

* 不能访问本类中的非静态成员
* 静态函数只能调用静态成员



```
#include <iostream>
using namespace std;

class A
{
public:
   static int num;
   int age;
   A(int n):age(n){}
   static int getNum()
   {
     //静态成员函数是不能使用this指针的，就不能使用类中普通的成员变量
     //静态函数只能访问静态的成员变量
     //cout<<this->age<<endl;
        return num;
    }
};

//1.初始化之后，才会对变量分配空间 2.类外进行单独的初始化
int A::num = 10;

int main()
{
    A a(25);
    //3.使用静态变量，可以直接只用 类::的方式 获取变量
   cout<<A::num<<endl;
   cout<<A::getNum()<<endl;
    return 0;
}
```



## 26. 单例模式

### 26.1 作用

作用：保证了一个类仅有一个实例，并提供了一个访问它的全局访问点

目的：为了保证类的实例对象只有一个

主要解决：一个全局使用的类 频繁的创建与销毁

关键： 构造函数和拷贝构造私有化



### 26.2 构造方法

1.私有构造函数和拷贝构造函数  不让类的外部创建对象

2.静态类指针   在静态成员函数中实现只创建一个对象的逻辑

3.静态成员函数返回类指针 用来实例化(new)对象



懒汉模式：什么时候想用，什么时候给

饿汉模式：



one.h

```
#ifndef ONE_H
#define ONE_H

class One
{
    //1.私有构造和拷贝
    One();
    One(const One& other);
    
    //2.静态类指针
    static One* instance;

    int num;
    
public:
    //3.静态函数：1.创建对象  2.返回静态指针
    //通过静态全局访问口  获取对象指针
    static One* getInstance();

    int getNum()
    {
        num++;
        return num;
    }
    void setNum(int n)
    {
        num = n;
    }

    ~One();
};
```



one.cpp

```
#include "one.h"
#include <cstdio>

//因为是static成员变量，所以类外单独进行初始化
One* One::instance = NULL;	//懒汉模式
//One* One::instance = new One;		//饿汉模式

One::One()
{
    num = 1;
}

One::One(const One &other)
{

}

One *One::getInstance()
{
    if(instance == NULL) //懒汉模式
        instance = new One;

   return instance;
}

One::~One()
{
    if(instance != NULL)
        delete instance;
}
```



main.cpp

```
#include <iostream>
#include "one.h"
using namespace std;
/*
 * 设计模式之单例模式

1.单例模式的作用与目的
    作用：保证了一个类仅有一个实例，并提供了一个访问它的全局访问点
    目的：为了保证类的实例对象只有一个
    主要解决：一个全局使用的类 频繁的创建于销毁
    关键： 构造函数和拷贝构造私有化
2、实现方法
    1.私有构造函数和拷贝构造函数   不让类的外部创建对象
    2.静态类指针     在静态成员函数中实现只创建一个对象的逻辑
    3.静态成员函数返回类指针  用来实例化(new)对象
 * */
int main()
{
  One* o1 = One::getInstance();
  o1->setNum(10);
  One* o2 = One::getInstance();

  One* o3 = One::getInstance();

  cout<<o1<<" "<<o2<<" "<<o3<<endl;
  cout<<o2->getNum()<<endl;
  cout<<o3->getNum()<<endl;

    return 0;
}
```





![image-20230531014335426](C:\Users\henry0408\AppData\Roaming\Typora\typora-user-images\image-20230531014335426.png)



## 27. 运算符重载



### 27.1 作用

如果类没有重载运算符，类的对象不能进行运算符的操作

运算符重载的本质是函数重载，函数名是以运算符的形式来命名，调用函数也是通过运算符来调用。



### 27.2 定义

#### 27.2.1 重载：

给运算符重新赋予新的含义，在类的内部定义的运算符重载和成员函数是一样的



#### 27.2.2 重载方法：

定义一个重载运算符的函数。在需要执行被重载的运算符时，系统会自动调用该函数



#### 27.2.3 格式

对于操作两个类：

```
返回值 operator 运算符 (const 类名&)
```

注意：const有时候不能用（见27.3中的三角形的例子），因为const类只能调用const类型的函数



```
返回值 operator 运算符 (变量类型 变量名)
```

* 参数个数由运算符本身决定
* 由运算符的左值调用运算符重载
* 如果没有重载运算符，类对象不能进行运算符操作



调用格式：

```
假设Person类中已有:
void operator +(const Person& other){};

Person p;
Person p2;

//调用
p.operator+(p2);	//成员函数一样，普通调用
p+p2;				//自动调用
```



#### 27.2.4 类型重定义

```
Person(string name, int age):name(name),age(age){}
bool operator == (Person &p1);
bool operator == (string s1);
bool operator == (int a1);
```

构成重载



### 27.3 加号+的重载

实现两个类相加

```
#include <iostream>

using namespace std;

class Person
{
    int age;
public:
    Person(int age):age(age){}
    void show()
    {
        cout<<age<<endl;
    }
    int operator +(const Person& o)
    {
        this->age += o.age;
        return this->age;
    }
};

int main()
{
    Person p(18);
    Person p1(20);
    cout<<(p+p1)<<endl; //38

    cout<<2+3<<endl;
}
```



#### 27.3.1 有时候不能使用const的原因

求两个三角形的周长和：

```
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
	int operator +(Triangle& o)		//注意不能写const Triangle& o
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
```

因为const修饰的类对象只能访问其中的const修饰的成员函数。所以如果加上，则报错。

修改：要么不写const，要么写const int getL()



### 27.4 ==的重载



```
#include <iostream>

using namespace std;

class Person
{
    string name;
    int age;
    
public:
    Person(string name, int age):name(name),age(age){}
    bool operator == (Person &p1);
    bool operator == (string s1);
    bool operator == (int a1);
};

bool Person::operator==(Person &p1)
{
    return this->age == p1.age;
}

bool Person::operator==(string s1)
{
    return this->name == s1;
}

bool Person::operator==(int a1)
{
    return this->age == a1;
}

int main()
{
    Person p1("aa",18);
    Person p2("bb",20);

    cout<<(p1==p2)<<endl;
    cout<<(p1=="aa")<<endl;
    cout<<(p1==20)<<endl;
    
}
```



### 27.5 =赋值运算符的重载

C++会对每个类默认重载赋值运算符，默认的逻辑是成员变量逐个赋值。



#### 27.5.1 拷贝构造和赋值运算区别：

拷贝构造只能用于已存在的类对象构造未存在的类对象。

```
Person p(10)；
Person p2(p);
```

而赋值运算可以用于已存在的两个对象之间赋值

```
Person p(10);
Person p2(20);
p = p2;
```



#### 27.5.2 实现

```
#include <iostream>
using namespace std;

class Person
{
    int age;
    string name;
public:
    Person(int a):age(a){
        cout<<"构造"<<endl;
    }
    Person(string name,int a):name(name),age(a)
    {}
    Person(const Person& o)
    {
        cout<<"拷贝"<<endl;
    }
   void operator=(Person& other)
    {
        cout<<"=重载"<<endl;
        this->age = other.age;
    }
   void operator =(int a)
   {
       cout<<"int..."<<endl;
       this->age = a;
   }
   void show()
   {
       cout<<age<<endl;
   }
};
int main()
{
    Person p(10);	//构造
    Person p1(20);	//构造

    Person p2(p);//创建新对象，拷贝
    p = p1;//两个已经存在的对象，调用赋值运算符的重载

    p.show();	//20
    p1.show();	//20

    p = 100;
    p.show();	//100
    
    Person p3 = p;		//拷贝

    return 0;
}
```



#### 27.5.3 系统默认赋值运算符

```
Person& operator=(const Person& other)
    {
        this->age = other.age;
        return *this;
    }
```



### 27.6 取地址&重载



### 不能重载的运算符(5个)

* 三目运算符
* sizeof()
* .    成员运算符
* ::
* .*
* ->*   成员指针运算符



## 28. 类继承



### 28.1



### 28.2 语法

创建一个子类（派生类）：class 子类名：继承方式 父类名

```
class A
{};

class B : public A
{

};
```

写public的原因：只有是公有的才能在类外创建一个对象



### 28.3 知识点

#### 28.3.1 如果子类和父类定义了同名变量

使用子类时，只会使用子类自己的变量



#### 28.3.2 父子类的创建顺序

1.当父类没有显示的定义构造，那么会调用父类默认的构造函数

2.父类显示的定义了构造，那么会调用父类显示的构造

3.先创建父类，后创建子类



以下代码证明了第2和3点：

```
#include <iostream>
using namespace std;

class Food
{
public:
     string chips;
    Food(string chips):chips(chips)
    {
        cout<<"food create"<<endl;
	}
	Food()
    {
        cout<<"food create2"<<endl;
    }
};


class KFC : public Food
{
string chips;
public://子类的初始化列表中，先创建父类，即调用父类的无参构造函数
    KFC(string chips):chips(chips)
    {
       // this->chips = chips;
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
```

输出：

```
food create2
kfc create
kfc: big mac
```



但如果写成：

```
class KFC : public Food
{
string chips;
public:
    KFC(string chips):Food("ham"),chips(chips)
    {
       // this->chips = chips;
        cout<<"kfc create"<<endl;
    }
    void show()
    {
        cout<<"kfc: "<<chips<<endl;
    }
};
```

则调用了父类的有参构造，输出的是

```
food create
kfc create
kfc: big mac
```



#### 28.3.3 如果子类中没有成员变量，而是使用父类的变量时

子类中赋值的变量时从父类中继承过来的

```
#include <iostream>
using namespace std;

class Food
{
public:
     string chips;
};
//kfc:子类  派生类  Food：基类 父类
class KFC : public Food
{
public:
    KFC(string chips)
    {
        this->chips = chips;
    }
    void show()
    {
        cout<<"kfc: "<<chips<<endl;
    }
};
int main()
{
    KFC kfc("hamburger");
    kfc.show();
    return 0;
}
```

输出：

```
kfc: hamburger
```



**注意：如果改成下面的参数列表的形式，则报错：**

```
#include <iostream>
using namespace std;

class Food
{
public:
     string chips;
};
//kfc:子类  派生类  Food：基类 父类
class KFC : public Food
{
public:
    KFC(string chips):chips(chips)
    void show()
    {
        cout<<"kfc: "<<chips<<endl;
    }
};
int main()
{
    KFC kfc("hamburger");
    kfc.show();
    return 0;
}
```

因为初始化列表是给当前类中的成员变量进行赋值



#### 28.3.4 子类的初始化列表，可以通过父类的构造函数来初始化父类的成员

##### 例子1：公用一个成员变量

```
#include <iostream>
using namespace std;

class Food
{
public:
    string chips;
    Food(string chips):chips(chips)
    {
        cout<<"food create"<<endl;
        cout<<"father: "<<chips<<endl;
    }
    Food()
    {
        cout<<"food create2"<<endl;
    }
};
class KFC : public Food
{
public://子类的初始化列表中，初始化父类的构造函数
    KFC(string chips):Food(chips) //父类的匿名对象
    {
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
```

输出：

```
food create
father: big mac
kfc create
kfc: big mac
```



##### 例子2：各自成员变量赋值

给子类赋值的时候，给父类赋值

```
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
    string chips;
public://子类的初始化列表中，初始化父类的构造函数
    KFC(string chips):Food("hamburger"),chips(chips) //父类的匿名对象
    {
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
```

**注意，因为我们要给两个类的同名对象分别赋值。所以此时KFC中，必须声明chips的成员变量。**

输出：

```
food create
hamburger
kfc create
kfc: big mac
```



#### 28.3.5 无成员子类可以给父类成员赋值吗？

```
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
```

输出：

```
food create
hamburger
kfc create
kfc: hamburger
```

与28.3.4例子1对比。



```
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
```

输出：

```
food create
hamburger
kfc create
kfc: big mac
```

相当于把父类继承过来的hamburger改成big mac



**注意：此时依然不能用构造函数列表传入chips，只能用this指针**

```
KFC(string chips):Food("hamburger"),chips(chips){}	//报错
```



### 28.4 继承权限

之前使用的都是public继承

```
class A
{}

class B : public A
{}
```



#### 29.1 继承访问方式的影响:

public继承：  子类继承后的访问权限不变

protected继承：  子类继承后，父类中的public变成protected，其它不变(protected:只有子类可以用)，类外不可用

private继承：   子类继承后，父类中的public和protected变成private，其他不变



回顾：

C++的访问权限都有什么？请描述？

|           | 本类 | 派生类 | 类外 |
| --------- | ---- | ------ | ---- |
| public    | T    | T      | T    |
| protected | T    | T      |      |
| private   | T    |        |      |



例子1：

```
class A
{
protected:
	int a;
public:
	A(int a):a(a){}
	void show(){
		cout<<a<<endl;
	}
};

class B : protected A
{
public:
	B(int a):A(a){}
};

int main(){
	B b(10);
	b.show(); //错误的 show函数是受保护权限的，类外不可以使用
}
```



例子2：

```
class A
{
protected:
    int a;
public:
    A(int a):a(a){}
    void show(){
        cout<<a<<endl;
    }
};

class B : protected A
{
public:
    B(int a):A(a){}
    void dis(){
        show();//子类中使用，没有问题的，本类可以使用受保护权限的函数
    }:
};

int main()
{
    B b(10);
    b.dis();
}
```



### 28.5 继承时的重定义redefine(遮蔽overwrite问题)

发生在派生类中的成员（成员变量/成员函数）与基类中的成员重名时。



遮蔽：在派生类中使用该成员，或者用派生类来访问该成员时，其实是派生类中新增的成员，不是从基类继承的。



#### 28.5.1 基类成员和派生类成员函数不构成重载

**不管函数的参数如何，只要名字一样就会造成遮蔽。**如果派生类有同名函数，那么就会遮蔽基类

```
class Base{
public:
    void func();
    void func(int);
};
void Base::func(){ cout<<"Base::func()"<<endl; }
void Base::func(int a){ cout<<"Base::func(int)"<<endl; }
```

```
class Derived: public Base{
public:
    void func(char *);
    void func(bool);
};
void Derived::func(char *str){ cout<<"Derived::func(char *)"<<endl; }
void Derived::func(bool is){ cout<<"Derived::func(bool)"<<endl; }
```

```
int main(){
    Derived d;
    d.func("c.biancheng.net");
    d.func(true);
    d.func();  //错误的 
    d.func(10);  //可以调用 bool
    d.Base::func();
    d.Base::func(100);
    return 0;
}
```

1）Base 类的func()、func(int)和 Derived 类的func(char *)、func(bool)四个成员函数的名字相同，参数列表不同，Derive 类的 func 遮蔽了 Base 类的 func，

 d.func();  

 没有匹配的函数，所以调用失败。
2）Base 类的两个 func 构成重载，而 Derive 类的两个 func 构成另外的重载。



```
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
    void show(int a)
    {
        cout<<"kfc: "<<chips<<a<<endl;
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
    kfc.show(78);			//报错，因为不构成重载，而构成遮蔽
    return 0;
}
```

报错，因为不构成重载，而构成遮蔽。kfc中虽然有两个show函数（一个继承，一个自己的），但是由于名字一样，自己的成员函数会把继承得到的成员函数覆盖。



## 29. 虚函数



### 29.1 定义

成员函数前加virtual关键字

```
virtual 函数返回值 函数名(参数)
```

 

目的：实现多态

C++的虚函数主要作用是“运行时多态”，

父类中提供虚函数的实现，为子类提供默认的函数实现。

子类可以重写父类的虚函数实现子类的特殊化。



### 29.2 重写override

至少两个类（一个父类一个子类），函数名相同，参数列表相同，返回值相同。但父类中该函数被virtual修饰。



子类中调用的是自己的show()

```
#include <iostream>
using namespace std;

class Person
{
public:
    //虚函数：virtual
    virtual void show()
    {
        cout<<"person  show..."<<endl;
    }
};
class Student : public Person
{
public:
    void show()
    {
        cout<<"stu  show..."<<endl;
    }
};
int main()
{
    Person p;
    p.show();
    Student stu;
    stu.show();

    return 0;
}
```

输出：

```
person show...
stu show...
```

不写virtual也是相同结果



### 29.3 C++重写、重载，重定义的区别？

|                      | 重写                    | 重载                       |
| -------------------- | ----------------------- | -------------------------- |
| 前提（涉及类的个数） | 发生在继承情况，2个以上 | 在同一个类中，1个          |
| 返回类型             | 必须相同                | 可以不同                   |
| 函数名               | 必须相同                | 必须相同                   |
| 参数列表             | 必须相同                | 必须不同（个数或类型不同） |

重定义：发生继承情况的两个类，函数名相同



### 29.4 重写的函数也是虚函数



```
class A{ 
public: 
	virtual void func1( ){ }	//虚函数
	void func2( ){ }  			//普通成员函数
}; 

class B:public A{ 
public: 
	void func1( ){cout<<“class B func 1“<<end1;}	//重写，虚函数
	virtual void func2( ){cout<<“class B func 2“<<end1;}//虚函数
};
```

下面正确的叙述是    C   。

A.  A::func2( )和B::func1( )都是虚函数 

B.  A::func2( )和B::func1( )都不是虚函数 

C.  B::func1( )是虚函数，而A::func2( )不是虚函数 

D.  B::func1( )不是虚函数，而A::func2( )是虚函数



2、在派生类中重新定义虚函数时，除了（ D ）方面都必须与基类中相应的虚函数保持一致。

A、参数个数  B、参数类型  C、函数名  D、函数体

只是没有virtual关键字，其他都相同





### 29.4 多态

#### 29.4.1 定义

 多态 指的是同一名字的事物可以完成不同的功能



分类：运行时多态和编译时多态

* 编译时多态

  函数的重载（包括运算符的重载）、对重载函数的调用，在编译时就能根据实参确定应该调用哪个函数，因此叫编译时的多态；

  

* 运行时多态

  继承、虚函数等概念有关



C++的虚函数主要作用是“运行时多态”，

父类中提供虚函数的实现，为子类提供默认的函数实现。

子类可以重写父类的虚函数实现子类的特殊化。



#### 29.4.3 多态构成的条件

· 必须存在继承关系；

· 继承关系中必须有同名的虚函数，并且它们是覆盖关系（函数原型相同）。

· 存在基类的指针，通过该指针调用虚函数。



重写，也可以叫 覆盖



#### 29.4.3 多态实现步骤

**1）父类指针指向子类对象**

```
父类* 指针 = new 子类();
```



**2）父类中包含虚函数**

若调用父类普通函数，则调用函数时依然是父类的方法;

若调用父类的虚函数，调用函数时调用的是子类重写之后的函数。



调用顺序：

1）看父类有没有虚函数

2）如果有，去子类中找有没有重写，有就执行子类重写的方法；

3）如果子类没有重写，就去执行父类的虚函数



基类指针可以按照基类的方式来做事，也可以按照派生类的方式来做事，

它有多种形态，或者说有多种表现方式，我们将这种现象称为**多态**。



##### 例子：

```

#include <iostream>
using namespace std;

//基类People
class People{
public:
    People(string name, int age): m_name(name), m_age(age){}
    void display(){
        cout<<m_name<<"今年"<<m_age<<"岁了，是个无业游民。"<<endl;
    }
protected:
    string m_name;
    int m_age;
};

//派生类Teacher
class Teacher: public People{
public:
    Teacher(string name, int age, int salary): People(name, age), m_salary(salary){}
    void display(){
        cout<<m_name<<"今年"<<m_age<<"岁了，是一名教师，每月有"<<m_salary<<"元的收入。"<<endl;
    }
private:
    int m_salary;
};

int main(){
    People *p = new People("啊啊", 23);
    p -> display();

    p = new Teacher("嘻嘻", 45, 8200);
    p -> display();

    return 0;
}
```

输出：

```
啊啊今年23岁了，是个无业游民。
嘻嘻今年45岁了，是个无业游民。
```

发现，我们的基类指针，只能调用派生类的成员变量，但不能调用派生类的成员函数。



更改：把基类中的display函数更改为virtual

```
virtual void display(){
        cout<<m_name<<"今年"<<m_age<<"岁了，是一名教师，每月有"<<m_salary<<"元的收入。"<<endl;
    }
```

输出：

```
啊啊今年23岁了，是个无业游民。
嘻嘻今年45岁了，是一名教师，每月有8200元的收入。
```



##### 借助引用也可以实现多态

```
int main(){
    People p("啊啊", 23);
	Teacher t("嘻嘻", 45, 8200);

    People &rp = p;
    People &rt = t;
    
    rp.display();
    rt.display();

    return 0;
}
```

由于引用类似于常量，只能在定义的同时初始化，不能再引用其他数据，所以必须要定义两个引用变量，一个用来引用基类对象，一个用来引用派生类对象。

当基类的引用指代基类对象时，调用的是基类的成员，而指代派生类对象时，调用的是派生类的成员。



不过引用不像指针灵活，指针可以随时改变指向，而引用只能指代固定的对象，在多态性方面缺乏表现力，所以谈及多态时一般是说指针。



## 30. 多重继承

从多个基类派生出一个新类



```
class 子类名: 继承方式 父类名1, 继承方式 父类名2
{
};
```

继承方式：公有，保护，私有



派生类创建函数顺序：以继承先后顺序为准，跟初始化列表无关



### 例子：

1.设计一个圆类Circle(半径r)

2.一个桌子类Table(高度h和颜色color)  

3.再设计一个圆桌类RoundTable  它从前两个类派生 

要求：  输出一个圆桌的高度 颜色  和面积



```
class Circle
{
protected:
	int r;
public:
	Circle(int r): r(r){}
};

class Table
{
protected:
	int height;
	string color;
public:
	Table(int height, string color):height(height),color(color){}
};


class RoundTable: public Cicle, public Table
{
public:
	RoundTable(int r, int height, string color):Circle(r),Table(height, color){}
	
	void show()
	{
		cout<<r<<" "<<height<<" "<<r*r*3.14f<<endl;
	}
};

int main()
{
	RoundTable rt(2,3,"white");
	rt.show();
}
 
```



### 同名成员问题（二义性）

多继承中会出现成员变量名相同的情况，需要加以作用域用来区分

```
class A
{
public:
	int m_a;
}

class B
{
public:
	int m_a;
}

class C: public A, public B
{
protected:
	int m_c, m_d;
}

int main()
{
	C c; 
	cout<<"m_a in A= "<<c.A::m_a <<endl;
	cout<<"m_a in B= "<<c.B::m_a <<endl;
}
```







## 31. 虚基类

以virtual声明的基类。使得继承共同基类时，只对共同的基类初始化一次。



### 31.1 菱形继承问题

两个派生类继承同一个基类。又有一个派生类同时继承这两个派生类。

![image-20230605020353749](C:\Users\henry0408\AppData\Roaming\Typora\typora-user-images\image-20230605020353749.png)

问题：

假设A是动物，有一个m_age的属性。B是羊，继承了m_age属性。C是驼，也继承了m_age属性。作为D（羊驼），也有m_age的属性。



* D会出现二义性的问题，不过可以用作用域解决

```
D d;
cout << d.B::m_age <<endl;
cout << d.C::m_age <<endl;
```

* D继承了两份A的数据，但其实只需要一份

```
```

