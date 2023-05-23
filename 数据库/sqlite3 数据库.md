# sqlite3 数据库



## 1. 数据存储方式

* 直接存储
* 文件存储
* 数据库



## 2. 数据库分类

* 大型：Oracle
* 中型：sql server, mysql
* 小型：sqlite3



## 3. sqlite3 优势

	不需要配置，不需要安装和管理
	不需要一个单独的服务器进程或操作的系统（无服务器的）
	一个完整的SQLite数据库存储在一个单一的跨平台的磁盘文件上
	SQLite是非常小的，轻量级的数据库，完全配置时小于400KiB，省略可选功能配置时小于250KiB
	SQLite是一个自给自足的数据库，这也就意味着不需要任何外部的依赖
	SQLite事务是完全兼容ACID的，允许从多个进程或线程安全访问
	 SQLite支持SQL92（SQL2）标准的大多数查询语言的功能
	SQLite使用ANSI-C编写的，并提供了简单和易于使用的API
	SQLite可在UINX（Linux，Max OS-X,Android，iOS）和Windows（Win32，WinCE，WinRT）中运行



## 4. 一些概念

数据库文件: xxx.db 
数据表：描述某一事物的基本信息
记录：表里一行信息
字段：列名 



## 5. 操作sqlite3的方式

1）命令行SQL语句

2）sql脚本

3）c编程接口



## 6. 常量

* 字符串常量

  字符串用单引号括起来：'Jerry'

  如果字符串本身带引号，需要双写：Kenny’schicken需要写成：'Kenny''s chicken'

  

* 数值常量

  -1
  3.142
  6.0221415E23



## 7. 变量

| 类型          | 大小       |
| ------------- | ---------- |
| integer       | 32 bit     |
| float         | 32 bit     |
| varchar字符串 | n (<=4000) |



## 7. 数据库基本操作

### 7.1 创建数据库

```
sqlite3 doudou.db
```

如果不存在，则创建并打开；若已存在，则直接打开

### 7.2 求帮助

```
sqlite> .help
```



### 7.3 退出

```
sqlite> .quit
```



### 7.4 查看表

```
sqlite> .schema
```



### 7.5 创建表

```
create table 表名(变量名 类型，变量名 类型)
```

e.g. 创建一个名叫stu_info的表，其中包含两个字段，分别为age和name

```
sqlite> create table stu_info(age integer, name varchar(20));
```



### 7.6 插入数据

```
insert into 表名 values(值1，值2)
```

e.g. 向stu_info这个表中放入三个学生的信息

```
sqlite> insert into stu_info values(18, "xiaoming");
sqlite> insert into stu_info values(18, "xiaoli");
sqlite> insert into stu_info values(18, "xiaohong");
```



