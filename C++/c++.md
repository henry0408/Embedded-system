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



#### 2.1.1 输出流会自动识别输出变量类型

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



### 2.2 输入流：cin

#### 2.2.1 输入流会自动识别输出变量类型

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



## 3. 命名空间的表示方法

### 3.1 使用std

```
using namespace std
```



### 3.2 自定义命名空间

#### 3.2.1 两个命名空间的标识符冲突



#### 3.2.2 命名空间标识符和全局变量冲突



#### 3.2.3 匿名命名空间



