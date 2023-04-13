# 位移运算符trick

```
unsigned long val = 0; 
char a = 0x48; 
char b = 0x52; 
val = b << 8 | a; 
```

​	A 20992 		B 21064 			C 72 			D 0    答案：B

```
unsigned long val = 0; 
char a = 0x48; 
char b = 0x52; 
val = b << 8 | a; 
------------------
a 0100 1000
b 0101 0010 << 8   0101 0010  0000 0000
		   0100 1000
0101 0010  0000 0000

0101 0010  0100 1000
16384+4096+512+64+8=21064 
```

1. 规则

   丢弃最高位(***符号位同样丢弃***)，0补最低位

2. 在数字没有溢出的前提下，对于正数和负数，左移一位都相当于乘以2的1次方，左移n位就相当于乘以2的n次方

3. 如果移动的位数超过了该类型的最大位数，那么编译器会对移动的位数取模。如对int型移动33位，实际上只移动了33%32=1位



## 1. 右移运算符

1. 规则：符号位不变，左边补上符号位。
2. **按二进制形式把所有的数字向右移动对应的位数，低位移出(舍弃)，高位的空位补符号位，即正数补零，负数补1**









ref:

[(33条消息) 移位运算符＜＜ ＞＞ ＞＞＞的使用_移位运算符的使用_一只有理想的程序猿的博客-CSDN博客](https://blog.csdn.net/weixin_39674445/article/details/111684003?utm_medium=distribute.pc_relevant.none-task-blog-2~default~CTRLIST~default-1.no_search_link&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2~default~CTRLIST~default-1.no_search_link)



