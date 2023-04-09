# Day13

## 1. Linux

“万物皆文件”：linux接打印机，这个打印机对于系统是一个文件



Linux是一个内核，而不是操作系统

Ubuntu才是用Linux内核的操作系统



### 1. 目录结构：

/(根目录) --  功能文件夹（目录文件）  ------ 普通文件 

1. /：根目录

   1. bin：可执行文件

   2. etc：配置文件

   3. mnt：挂载目录： 接入新硬件的时候用，例如U盘

   4. proc：进程

   5. boot：引导文件，引导计算机执行操作系统

   6. dev：设备文件

   7. home：用户目录：/home/linux

      1. 用户名
         1. 工作目录（~）
            1. Documents
            2. Downloads
            3. Desktop
            4. Music
            5. div
            6. ...

   8. lib：库文件(/lib/usr/lib)

   9. root：超级用户工作目录

   10. sbin：存放指令

       ​		

   ![image-20230403184917738](C:\Users\henry0408\AppData\Roaming\Typora\typora-user-images\image-20230403184917738.png)

   ```
   ctrl+alt + t		//快速打开一个terminal
   crtl + shift + +	//放大字体
   ctrl + -			//缩小字体
   ```

   

2. 工作目录

   ```
   cd ~
   ```

   

3. 绝对路径和相对路径

   <img src="C:\Users\henry0408\AppData\Roaming\Typora\typora-user-images\image-20230331133908386.png" alt="image-20230331133908386" style="zoom:67%;" />

### 2. 命令：

1. ls

   白色：  普通文件 

   绿色：  可执行文件 

   深蓝色： 目录文件  

   ```
   ls -a	//显示所有文件，包括隐藏文件（文件第一个字符是'.'的文件）
   ```

   ```
   ls -l	//显示文件的详情	
   ```

   可以查看当前文件的权限：

   属性    文件的所有者  文件所属组  文件大小  日期    时间  文件名称 

   <img src="C:\Users\henry0408\AppData\Roaming\Typora\typora-user-images\image-20230403185239309.png" alt="image-20230403185239309" style="zoom:67%;" />

   属性：一共10个字符，第一个字符是一部分，后9个字符是另一部分

   第一部分：-表示普通文件， d表示目录文件

   第二部分： 权限：  r  read   w  write   x  execute 

   ​	第一组：代表了文件owner 的使用权限

   ​	第二组：代表了文件所属组（同组用户权限 ）的使用权限

   ​	第三组：代表了 other 的使用权限  

   

   ```
   ls -a..	//列出上一级所有文件
   
   ls -a ~	//列出工作目录下所有的文件
   
   ls -l /		//列出根目录下的文件详情
   
   ls -l a.c		//列出a.c文件的详细信息
   ```

   

2. chmod： change mode，可以改变文件权限

   两种方法：

   1. chmod  +x  id.c 增加可执行权限，如果-x则为去除可执行权限。也可以同时写两个：+rw

   2. chmod  664  id.c  

      664 是3位8进制数，转成二进制 110 110 100，每一位对应一个权限，相当于：  rw-rw-r--
      
      

3. pwd:查看当前绝对路径

   

4. cd: 进入目录：change directionary

   ```
   cd /		//根目录
   cd ~		//用户工作目录
   cd .		//当前路径
   cd ..		//上一级路径
   cd -		//上一次进入的路径
   ```

   绝对路径：从根开始找

   相对路径：从当前位置的路径，从当前位置找

   <img src="C:\Users\henry0408\AppData\Roaming\Typora\typora-user-images\image-20230403190325514.png" alt="image-20230403190325514" style="zoom:50%;" />



5. touch:创建普通文件

   ```
   touch b.txt
   touch hello.c
   
   touch dr/b.c		//在dr文件夹里创建b.c
   ```

   如果touch已经有的文件，会改变它的修改时间。将来我们使用makefile编译时，没有修改的过的文件不参与编译。

   **不能在根目录下创建文件！！**

   可以同时创建多个：

   ```
   touch a.c b.txt c.c
   ```

   

6. 创建文件夹: mkdir

   ```
   mkdir folder
   mkdir sr sr/sr		//在sr目录下创建sr目录
   ```

   

7. 删除: rm

   ```
   rm a.c b.c		//可以同时删除多个文件
   rm -r AAA		//删除目录
   rm -r AAA dir Downloads		//可以删除多个目录
   rm -f *			//删除当前目录中所有文件
   ```

   

8. 移动/改名

   mv 文件名1（或文件夹名） 文件名2

   如果文件名2存在，并且是文件夹，那么就是移动；如果不存在就是改名

   ```
   mv Downloads test	//重命名
   mv test.c Downloads		//移动
   ```

9. 通配符

   1. 匹配多个字符

      ```
      ls *.c		//查看所有以.c结尾的文件
      ```

   2. 匹配一个字符

      ```
      ls ?.c
      // 查看任意名字是一个字符的.c文件。  a.c  b.c  test.c  能查看a.c b.c，不能查看test.c
      ```

   3. 匹配一位数字

      ```
      ls a[2-4].c			//查看a2.c, a3.c, a4.c
      ls a[^2-4].c			//查看出了a2, a3, a4以外的文件
      ```

   4. 组合使用

      ```
      ls ?[1-4].c			//查看所有前面有一个字符，第二位是1-4，以.c结尾的文件
      ```

10. 复制copy

   ```
   普通文件
   cp a.c b.c		//将a.c复制一份出来，新文件名字叫做b.c
   cp *.c Desktop/		//将所有的.c文件复制一份到Desktop目录中
   ```

   ```
   文件夹
   cp -r AA BB		//将AA文件夹复制一份出来，新的文件夹名叫做BB,AA中的文件也都被复制过去
   ```

11. 查看文件

    cat  file.c   文件**所有内容**直接显示在屏幕上。 

    more file.c   显示一屏信息。再向下看，需要按空格或者回车。直到看完所有内容，文件才全部写到终端。  q退出

    less file.c   显示一屏信息。可以按上下箭头来回查看。按q 退出当前模式。 q退出

    head file.c   默认打印出文件的前 10 行。 如果想指定行数。使用选项参数： head -15 file.c 

    tail file.c   默认打印出文件的后 10 行。 如果想指定行数。使用选项参数： tail -20 file.c 



# Day 14

## 1. 用户管理

超级用户：1个。 root   拥有最高权限。 

普通用户：多个。linux  拥有的权限十分有限。 安装文件、关机等都无法实现。  /home/linux 

1. 修改密码：

   ```
   sudo password
   ```

2. 切换用户

   ```
   su 用户名
   su root  			su linux  （你们电脑当前有一个linux用户）
   退回原用户： exit
   ```

3. 临时借用管理员权限

   ```
   临时借用管理员权限：  sudo + 命令 
   sudo touch /a.c    借用管理员权限在根目录下创建一个文件。
   ```

4. ```
   用户名@ 计算机名 : 路径 
   
   linux @  ubuntu  :  ~  $
   
   root  @  ubuntu  :/home/linux # 
   ```

5. 添加/删除用户

   ```
   添加： sudo adduser alice(用户名) 
   
   删除： sudo userdel -r alice (用户名) 
   ```

   ```
   用户信息： /etc/passwd    查看方法 vi /etc/passwd 
   
   用户密码： /etc/shadow    查看方法 sudo vi /etc/shadow  
   
   用户工作目录：  /home     ls /home 
   ```

   

## 2. 进程管理

1. 进程（Process）：程序运行，系统会为程序预备一些资源（内存、cpu。。。），是我们程序运行所需要的一些资源，也可以理解成程序运行的环境。
2. 线程（Thread）：是进程中运行逻辑的单位
3. 进程中至少有一个线程。任何线程不能脱离进程

单个CPU一次只能执行一个任务（进程），其他进程处于非运行状态。一或多个线程协同完成一个进程。进程的内存空间是共享的，每一个线程都可以共享这些内存。但是一个线程使用某些共享内存时，其他线程必须等它结束，才能使用这一块内存。



4. pid  : 进程id  (process id) 叫做进程号。 进程号由操作系统进行分配。用来识别唯一的进程。
5. ppid : 父进程id . (parent process id)  
6. init进程： 此进程 的进程id 为 1. 这个进程不可以被 kill 
7. 父子进程： 创建出新进程的进程就是父进程。 被创建出来的，叫做子进程。 
   					进程A在运行时创建了进程B，那么进程A就是进程B的父进程。B是A的子进程

8. 僵尸进程： 一个已经不再运行的进程。但是还没有消亡。还占用着系统资源。

9. 孤儿进程：正常情况下当父进程死掉的时候，会让子进程也死掉。当父进程死掉但是子进程没死，称之为孤儿进程。
10. 孤儿进程： 是一个没有父进程的进程。 他会被 init 进程领养。 

```
查看进程：       ps aux    ps -ef 

查看进程树：      pstree

杀掉进程：       kill     kill 2619   kill -9 2581 //必杀   kill -9 pid

ctrl + c  结束进程p  

ctrl + z  将进程暂停，并扔到后台。 

fg     将进程调回前台。 
```



## 3. 文件管理

1. find

   格式：find  路径  选项  选项值 

   ```
   find /usr -name stdlib.h
   ```

   find是搜索每个文件夹，慢。

2. which

   查找可执行文件，一般用来查找命令   （相比较而言，查找速度快。因为which 只在指定的路径下查找，查找的是可执行文件）

   which并不是在路径里搜索文件，它是去环境变量里找。(环境变量：就是一些可执行文件的路径，系统是通过环境变量找到可执行文件。)

   ```
   which ls
   ```

   

3. locate

   locate 与 find 不同: find 是去硬盘找，locate 只在 /var/lib/slocate 资料库中找

   locate 的速度比 find 快，它并不是真的查找，而是查数据库，一般文件数据库在 /var/lib/slocate/slocate.db 中，

   所以 locate 的查找并不是实时的，而是以数据库的更新为准，一般是系统自己维护，也可以手工升级数据库

   ```
   touch b.c
   sudo updatedb
   locate b.c
   ```



## 4. 压缩文件

1. 压缩： 

```
tar    cvfz     dir.tar.gz    dir 
```

```
tar 	cvfz 	fzip.tar.gz 	a1.c a2.c  
//显示压缩过程  压缩成fzip  压缩的文件是a1.c a2.c
```



2. 解压缩：

```
tar    xvfz    dir.tar.gz 			//默认解压到当前路径
```

```
tar  xzvf  test809.tar.gz  -C  test //解压到指定路径下
```

​		c 创建压缩文件

​        x 解压缩 

​		v 显示压缩过程

​		f 将多个文件打包生成一个文件

​		z 以gzip格式压缩   



## 5. 链接文件

ln

### 1） 硬链接

硬链接

```
ln   an.c  an.bak   // 根据物理编号inode 节点，建立连接
```

此时  an.c 和an.bak 是同一个文件的两个inode节点（文件节点）



创建文件的时候，文件名就是一个硬链接

```
touch a.c
```

此时，a.c会成为这个文件的第一个硬链接



<img src="https://pic1.zhimg.com/80/v2-407711a4a598b0eeb332c6e0be447ebc_720w.webp" alt="img" style="zoom:80%;" />



`ln` 指令默认创建的是硬链接，如果加入了`-s`参数，则会生成一个软链接。

由于 Linux 下的文件是通过索引节点（Inode）来识别文件，在 Linux 的文件系统中，保存在磁盘分区中的文件不管是什么类型都给它分配一个编号，称为索引节点号 (Inode Number)。

<img src="https://pic2.zhimg.com/v2-0e878477f63c5f56adaded564d68fb75_r.jpg" alt="img" style="zoom:67%;" />

在 Linux 中，多个文件名可以指向同一索引节点。

所以硬连接是指通过索引节点来进行的连接，即每一个硬链接都是一个指向对应区域的文件。

例子：

```
#1.为a.c 创建2个硬链接文件 an.bak  ann.bak
ln a.c  an.bak
ln a.c ann.bak
//注意，名字不一定非要是.bak结尾，可以.c

#2.修改a.c的内容 查看其他两个文件是否修改
vi a.c 在里面写点内容
cat an.bak
cat ann.bak

#3.修改an.bak的内容，查看a.c的文件是否修改
vi an.bak
cat a.c

#4.删除a.c，查看ann.bak文件是否受影响
rm a.c
cat an.bak
```

<img src="C:\Users\henry0408\AppData\Roaming\Typora\typora-user-images\image-20230409004131021.png" alt="image-20230409004131021" style="zoom:85%;" />

用`ls -li` 命令可以看到：第一串数字是文件的索引节点号 (Inode Number)。三个文件的索引节点号相同。



硬链接的作用是允许一个文件拥有多个有效路径名，这样用户就可以建立硬链接到重要文件,以防止“误删”的功能。只删除一个连接并不影响索引节点本身和其它的连接，只有当最后一个链接被删除后，文件的数据块及目录的连接才会被释放，也就是说，文件才会被真正删除



### 2） 软链接

相当于一个快捷方式，不会增加文件的链接数。如果源文件被删掉，此时软连接文件也失效。

<img src="https://pic4.zhimg.com/80/v2-679da10fd5e4193d0098e6d6a35d5e1b_720w.webp" alt="img" style="zoom: 67%;" />

这个文件包含了另一个文件的路径名，例如在上图中，`foo.txt` 就是 `bar.txt` 的软连接，`bar.txt` 是实际的文件，`foo.txt`包含的是对于 `bar.txt` 的 inode 的记录。

<img src="https://pic3.zhimg.com/80/v2-9abd33350e3bcb401f379752874f9b52_720w.webp" alt="img" style="zoom:80%;" />



## 6. 管道符 | ，以及grep关键字

作用： 前一个命令的输出，作为第二个命令的输入。



grep用来 在文本中查找关键字

```
cat test.c|grep for
```

查看test.c内容，将查看到的内容作为输入传给grep命令，grep命令会在输入中查找for关键字

```
# 查看demo.c的文件 结果中找while关键字
cat demo.c|grep while
```



查找根目录下是否存在 etc 这个文件。  

```
ls / ｜ grep etc
```

查找 /etc 下是否存在 passwd  这个文件。   

```
ls /etc | grep passwd
```

查找 所有进程中是否存在 bash 这个进程。  

```
ps aux | grep bash
```

查看 /etc/passwd 文件中，是否存在 daemon 这个用户。 

```
cat /etc/passwd | grep daemon
```

 

## 7. 重定向符号

把本应该输出的内容，存放到文件里

\> 

\>>

 

\>   重定向        会覆盖原来的内容

\>>  追加重定向      会在原有内容的后面追加新内容

<img src="C:\Users\henry0408\AppData\Roaming\Typora\typora-user-images\image-20230409152820348.png" alt="image-20230409152820348" style="zoom:50%;" />

示例：

1.将当前路径写入到file.txt

```shell
pwd > file.txt
```

2.将back文件夹下的所有文件名追加到file.txt中

```shell
ls back/ >> file.txt
```



## 8. 网络配置

### 1） 查看网络配置

ifconfig  

eth0  : 第一块物理网卡

Ethernet ：以太网

HWaddr 00:0c:29:82:8f:99  物理地址

inet addr:192.168.30.234  ipv4 地址  

Bcast:192.168.30.255    广播地址 

Mask:255.255.255.0     子网掩码       

inet6 addr: fe80::20c:29ff:fe82:8f99/64   ipv6 地址  

Local Loopback       本地环回

inet addr:127.0.0.1     本地环回地址



### 2）修改ip

sudo ifconfig eth0 192.168.40.199 

 

ip地址就是我们的计算机在网络上的身份标识。

ip本质上不是地址，而是一种底层的网络协议，ip地址是基于这种网络协议的地址。



### 3）ping测试连通性

ping 192.168.40.101

这个命令的目的是测试网络是否通畅。



# Day15

## 1. gcc编译器

gcc(是一个编译器, 是GNU组织主要的编译工具)

gcc 是一个跨平台(跨软件平台 和 硬件平台)的编译器。



跨平台：

代码可以通过不同的编译器编译到适合不同平台运行的程序。 



交叉编译：

在windows下开发了一款软件，只需要使用linux支持的编译器对代码进行编译，这个软件就可以在linux下运行。这个过程叫做交叉编译。

## 2. 编译命令

gcc默认生成的可执行文件叫a.out



-o可以指定生成文件的名称

例子：编译hello.c文件，生成可执行文件的名字叫hello，可执行文件的名字自己起名

```
gcc hello.c -o hello
```

或者

```
gcc -o hello hello.c
```

运行：

```
./hello
```



## 3. 编译步骤

四步：1）预处理，2）编译，3）汇编，4）链接

### 1）预处理

```
gcc -E demo.c -o demo.i 
```

-E是让编译器在预处理之后就退出，不进行后续编译过程



主要负责处理头文件和宏定义

#include <stdio.h>  将头文件 复制粘贴到include的位置（将stdio.h 文件中的内容插入到test.c中了）

#define 使用宏值去替换宏名

预处理后的文件可以cat查看



### 2）编译

将经过预处理文件（test.i）之后的程序转换成特定汇编（test.s）代码的过程，此时还没有生成机器码



在这个阶段中，gcc首先要检查代码的规范性、是否有语法错误等，以确定代码实际要做的工作，在检查无误后，gcc把代码编译成汇编代码。用户可以使用“-S”选项来进行查看，该选项生成汇编代码

```
gcc -S demo.c -o demo.s
```

编译到汇编的步骤，虽然不是二进制，但是语法和二进制一样



### 3）汇编

```
gcc -c demo.c
```

编译后自动生成demo.o文件

将c文件变成机器码文件（二进制文件）
此时生成的文件已经**无法查看**
但是不能运行，因为缺少一些必要的内容



### 4）链接

将该目标文件与其他目标文件、库文件、启动文件等链接起来生成可执行文件。附加的目标文件包括静态连接库和动态连接库。

```
gcc -o demo.out demo.c
```

链接之后的文件 要比汇编产生的.o的文件要大



![image-20230409163651125](C:\Users\henry0408\AppData\Roaming\Typora\typora-user-images\image-20230409163651125.png)



## 4. gcc编译多个文件

```
gcc del.c add.c main.c
```

![image-20230409163926827](C:\Users\henry0408\AppData\Roaming\Typora\typora-user-images\image-20230409163926827.png)

![image-20230409163951801](C:\Users\henry0408\AppData\Roaming\Typora\typora-user-images\image-20230409163951801.png)



##  5. shell脚本

### 1）什么是脚本

脚本语言不需要编译，脚本语言的解析器可以直接阅读脚本语言并按照指令执行。



解析器本身就是一个程序，被CPU执行的程序。脚本语言的特点注定脚本语言的执行效率不可能比编译型语言高。



编译型语言：C语言 C++语言

脚本语言：python  js——javascript



shell脚本：批量处理linux命令

shell脚本的解析器  bash	



### 2）创建脚本文件

```
vi test.sh
```

### 3）开头

告诉计算机，我接下写的东西 是一个脚本

后面有空格有时会有错误

```
#!bin/bash
```

### 4）运行脚本

```
chmod +x tesh.sh	//加入执行权限
./test.sh
```

### 5）变量

1.为了方便识别变量，变量名通常用大写字符
2.不能以数字开头，开头必须是字母或下划线
3.不能使用标点符号



 echo 表示输出 类似于printf

![image-20230409181143073](C:\Users\henry0408\AppData\Roaming\Typora\typora-user-images\image-20230409181143073.png)



### 6）位置参数以及预设变量

#### a）位置参数

当我们执行脚本时，后面可以直接传参数，这个参数可以在脚本中使用

如果想取到位置参数的值，直接用$0, $1, ...

![image-20230409181453799](C:\Users\henry0408\AppData\Roaming\Typora\typora-user-images\image-20230409181453799.png)

<img src="C:\Users\henry0408\AppData\Roaming\Typora\typora-user-images\image-20230409181504036.png" alt="image-20230409181504036" style="zoom:50%;" />

#### b）预设变量

$#   可以看参数的个数（没有0位参数）

$*	可以看所有的参数，用空格隔开，把所有的参数保存到预设变量中（没有0位参数）

![image-20230409181555305](C:\Users\henry0408\AppData\Roaming\Typora\typora-user-images\image-20230409181555305.png)

例如：请编写shell脚本: 创建目录文件，目录文件的名字由位置参数决定。创建完目录之后，在目录中再创建一个普通文件，名字也由位置参数决定。 

```
#.sh文件中
#!/bin/bash
mkdir $1
touch $1/$2
```



### 7）功能语句

1. 输出：echo
2. 输入：`read NAME1 NAME2` 或者`read -p "PLease enter num:" NAME1 NAME2`

注意：输入时不能按回车

![image-20230409182050423](C:\Users\henry0408\AppData\Roaming\Typora\typora-user-images\image-20230409182050423.png)

例子：创建一个目录文件，然后，在此目录下创建一个普通文件。 文件名字由输入决定。

要求 read 并定义变量（与之前用预设变量不同）

```
#!/bin/bash
read -p "please input:" DIRNAME FILENAME
mkdir $DIRNAME
touch $DIRNAME/$FILENAME
```



### 8）“ ”与' '

两者都表示字符串，或者什么也不写也是字符串:

" " 	表示不完全输出 用变量值替代变量 **等价于不写" "**

' '	表示完全输出 完全按照写的样子输出

![image-20230409183537237](C:\Users\henry0408\AppData\Roaming\Typora\typora-user-images\image-20230409183537237.png)

## 6. shell的计算

### 1）``:反引号

用来表示运算

![image-20230409183832873](C:\Users\henry0408\AppData\Roaming\Typora\typora-user-images\image-20230409183832873.png)

### 2）expr语句

运算表达式

![image-20230409183902296](C:\Users\henry0408\AppData\Roaming\Typora\typora-user-images\image-20230409183902296.png)

### 3）注意

1. 赋值时，等号两边一定不能有空格
2. 运算符两侧一定有空格
3. 乘法用`\*`或者`'*'`，因为*在linux中表示通配符

<img src="C:\Users\henry0408\AppData\Roaming\Typora\typora-user-images\image-20230409184716456.png" alt="image-20230409184716456" style="zoom:67%;" />



## 7. shell的if语句

### 1）格式

```
if [条件]
then  # if执行语句
	语句1
elif [条件]
then
	语句2
else   # else 没有then
	语句3
fi    #  fi 反着写表示结构结束
```

### 2）if判断的对象

可以是：字符串，数值，文件类型

**注意，判断时等号两侧要有空格**

`-a` 表示and语句



#### a）字符串

```
#!/bin/bash

if [ "abc" = "abc" ] #判断字符串相等 =只能判断字符串相等
then
	echo "equal"
else
	echo "no equal"
fi
```

判断字符是否为空`-z`

```
#!/bin/bash

read -p "please input:" STRING
if [ -z $STRING ] # -z 判断字符是否为空
then
	echo "empty"
else
	echo "no empty"
fi
```



#### b）数值

-eq  相等      equal

-ne  不等      not equal

-gt  大于       greater than

-ge  大于等于   greater equal

-lt  小于 		 less than

-le  小于等于    less equal

```
if [ $NUM -le 10 ]
then
   echo "小于等于"
fi
```



例子：输入一个数值，判定此数值是否是偶数。 

```
#!/bin/bash
read -p "Please enter a num: " NUM1
if [ `expr $NUM1 % 2` -eq 0 ]
then
	echo "yes"
else
	ehco "no"
fi
```



#### c）文件

-f filename    判断文件是否为普通文件   file

-d filename    判断文件是否为目录文件  directory

-e filename    判断文件是否存在 		exist

-L filename    判断文件是否为链接文件	link

-w filename    判断是否有写权限			write

-x filename    判断是否有执行权限    excute

-r filename    判断是否有读权限    read

<img src="C:\Users\henry0408\AppData\Roaming\Typora\typora-user-images\image-20230409200118101.png" alt="image-20230409200118101" style="zoom:67%;" />



### 3）case语句

```
case $(变量) in    # 判断变量的值
a) 				# a为可能的值
	语句
	;;			# 类似于break,在这里不能省略
b)
	语句
	;;
*)				#类似于default
	语句
	;;
 esac  # 结束标志 case反写
```

例子：实现计算功能

![image-20230409200353645](C:\Users\henry0408\AppData\Roaming\Typora\typora-user-images\image-20230409200353645.png)

![image-20230409200400169](C:\Users\henry0408\AppData\Roaming\Typora\typora-user-images\image-20230409200400169.png)



### 4）循环语句

#### a）for循环

```
for NAME in $(单词表)
do
	循环语句
done
```

例子

```
#!/bin/bash

LIST="zhang wang li zhao"
for NAME in $LIST
do
    echo $NAME
done
```

例子：

输出 根目录下的所有文件名称   使用for循环

首先使用ls /命令获得根目录下所有文件的名称

![image-20230409200716147](C:\Users\henry0408\AppData\Roaming\Typora\typora-user-images\image-20230409200716147.png)



#### b）while循环

```
while [ 条件 ]
do
	循环语句
done
```

例子：打印1-100的所有数字

```
#!/bin/bash
M=1
while [ $M -le 100 ]
do
	echo "M is $M"
	M=`expr $M + 1`
done
```

例子：用while实现创建temp1~temp9，9个文件夹

```
#!/bin/bash
NUM=1
while [ $NUM -le 9 ]
do
	mkdir temp$NUM
	NUM=`expr $NUM + 1`
done
```



#### c）break

break1：退出一层循环

break2：退出一层循环

![image-20230409220755188](C:\Users\henry0408\AppData\Roaming\Typora\typora-user-images\image-20230409220755188.png)

![image-20230409220821789](C:\Users\henry0408\AppData\Roaming\Typora\typora-user-images\image-20230409220821789.png)



## 8. 总结

用户 shell 内核 硬件的关系。

<img src="C:\Users\henry0408\AppData\Roaming\Typora\typora-user-images\image-20230409220922392.png" alt="image-20230409220922392" style="zoom:67%;" />

linux系统特点：

多用户

多任务    可以同时运行很多程序

方便移植    开源，我们可以自己对源代码进行删减，然后编译成符合我们需要的linux内核。



# Day 16

## 1. make （工程管理工具）

我们的一个项目中代码源文件是很多的，编译需要耗时，很耗时。我们需要工程管理工具提高我们的编译效率。

提高效率的大原则就是已经编译过的文件如果没有修改就不再编译



当前项目管理工具有很多，make只是其中一种，是linux下最常用的一种。

make :  工程管理工具。 make 命令。 编译项目

makefile : 是配置文件。 是 make 命令唯一读入的配置文件。 makefile文件里记载了我们需要编译的文件。

makefile 的名字是固定的。

Makefile或者写成makefile都可以。

当使用make命令时，make工具会找到makefile文件，根据文件中的描述对项目源文件进行编译。

![image-20230409222230127](C:\Users\henry0408\AppData\Roaming\Typora\typora-user-images\image-20230409222230127.png)

## 2. 文件编写规则

1. 目标名称：编译最终生成的产物
2. 依赖文件：编译所需要的文件

例如：main是目标，main.c，add.c，del.c是编译这个目标所依赖的文件

（注意：依赖文件不一定是.c文件，还可能是.o文件）

<img src="C:\Users\henry0408\AppData\Roaming\Typora\typora-user-images\image-20230409222933260.png" alt="image-20230409222933260" style="zoom:67%;" />

### 1）单文件编译

假设文件demo.c为：

```
#include <stdio.h>

int main()
{
	printf("hello world\n");
	return 0;
}
```

我们创建一个makefile

（注意：文件名必须是makefile或者Makefile）

makefile：

```
demo.out:doemo.c
	gcc demo.c -o demo.out
```

![image-20230409223238121](C:\Users\henry0408\AppData\Roaming\Typora\typora-user-images\image-20230409223238121.png)

执行：

```
make
```

![image-20230409223220682](C:\Users\henry0408\AppData\Roaming\Typora\typora-user-images\image-20230409223220682.png)

再次输入make：

![image-20230409223255987](C:\Users\henry0408\AppData\Roaming\Typora\typora-user-images\image-20230409223255987.png)

### 2）添加清除和重新编译的功能

```
demo.out:demo.c
	gcc dedmo.c -o demo.out
clean:
	rm demo.out
rebuild:clean demo.out
```

注意：rebuild相当于调用了前面的两个函数，一个是clean，另一个是demo.out。所以必须写在一行

### 3）多文件处理

假设有三个文件

![image-20230409225052346](C:\Users\henry0408\AppData\Roaming\Typora\typora-user-images\image-20230409225052346.png)

#### a）不标准写法

![image-20230409225127421](C:\Users\henry0408\AppData\Roaming\Typora\typora-user-images\image-20230409225127421.png)

修改了main.c以后，再次执行make，发现所有的文件都重新编译了，但是事实上只编译main.c就可以。所以现在的写法是有问题的。



改善方法：将源文件编译到汇编的步骤，生成二进制文件并等待链接

![image-20230409225214892](C:\Users\henry0408\AppData\Roaming\Typora\typora-user-images\image-20230409225214892.png)

#### b）改善写法

<img src="C:\Users\henry0408\AppData\Roaming\Typora\typora-user-images\image-20230409225754597.png" alt="image-20230409225754597" style="zoom:67%;" />

![image-20230409232152291](C:\Users\henry0408\AppData\Roaming\Typora\typora-user-images\image-20230409232152291.png)

#### c）简洁写法

所有的.c文件都生成对应的.o文件，所以可以用通配符

![image-20230409232257322](C:\Users\henry0408\AppData\Roaming\Typora\typora-user-images\image-20230409232257322.png)

但这样写，需要把项目单独创建一个文件夹。因为`gcc *.c`相当于把当前路径下所以.c文件都编译



### 4）添加变量

#### a）预设变量

$@  : 完整的目标名称 

$^  : 依赖文件 

$<  : 每个.o文件的依赖文件 

上面的简洁写法可以继续写成

```
a.out:main.o add.o del.o
	gcc -o $@ $^
.o:.c
	gcc $< -c
clean:
	rm *.o a.out
rebuild:clean a,out
```

![image-20230409234231201](C:\Users\henry0408\AppData\Roaming\Typora\typora-user-images\image-20230409234231201.png)



#### b）将目标等参数用变量替代

![image-20230409234344794](C:\Users\henry0408\AppData\Roaming\Typora\typora-user-images\image-20230409234344794.png)



## 3. gdb调试器

