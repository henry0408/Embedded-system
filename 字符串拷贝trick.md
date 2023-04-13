# 字符串拷贝trick

失败的方案(1)：
```
char *a = "abcdefg";
*(a+3) = 'n';  //想修改第四个的值为n
printf("The change qian de a is:%s\n",a);
```

输出时会显示段错误：Segmentation fault (core dumped)//字符串存放的内存区域不同：前者存放在常量区，不可修改。

方式一的本质是定义了一个`char`型指针`str1`， 指向的是字符串常量`Hello world!`，因此`str1`所指向地址中的内容是不可更改的，即不能使用类似`str1[0] = 'h';`的语句对其进行赋值操作。但是指针`str1`仍然可以指向其他地址，例如可利用`str1 = str2;`语句将`str1`指向`str2`所指向的地址。 此外，字符串的结尾会被编译器自动加上结束符\0



成功方案(2):

```
char *b,*a;
b=new char[11];
strncpy(b,"string",8);
a=b;
*(++b)='h';
//*(a+3)='n';
printf("The change hou de b is %s and a is %s\n",b,a);
```

//字符串存放的内存区域为堆栈区，可以修改





成功方案(3):
```
char a[]="abcdef";
*(a+3)='n';
printf("The change qian de a is:%s\n",a);//字符串存放的内存区域为堆栈区，可以修改
```

方式二定义了以一个`char`型数组`a`，`str2`指向数组第一个元素所处内存的地址。此时内存空间是由栈分配的，地址一经分配就不能更改，因此`str2`不能再指向其他内存空间，但其所指向的内存空间中的内容是可以更改的，即可以使用类似`str2[0] = 'h';`的语句对其进行赋值操作。字符串的结尾也会被编译器自动加上结束符`\0`。



原因如下：
注意char *a="abcdef"与char a[]="abcdef"的区别：1、字符串存放的内存区域不同：前者存放在常量区，不可修改，后则存放在栈中，可以修改；2、变量a存放的内容不同：前者存放的是一个地址，而后者存放的是字符串"abcdef"，因此使用sizeof它们的结果是不同的，分别是4和7；此外关于new分配的对象数组的情形，以为是内存区中的修改。所以也是可以实现修改字符串的。

字符串遍历：

```
// 思路一：根据数组长度逐个遍历
void travel_str(void)
{
	int i = 0;
	char str[] = {"Hello World!"};
	int len = strlen(str); // 计算字符串大小
        
        // 逐个遍历
	for(i=0;i<len;i++)
	{
		printf("%c\n", str[i]);
	}
}

// 思路二：利用指针进行遍历
void travel_str(void)
{
	char str[] = {"Hello World!"};
	char *ch = str;
	
        // 不能直接采用原指针str遍历，因为此处的str不能改变其指向的地址。
        // 即使可以也会因为str指向了别处导致str原来指向的内存无法被释放，造成内存泄露。
	while(*ch != '\0') // 以'\0'作为字符串结束标志
	{
		printf("%c\n", *ch++);
	}
}
```

