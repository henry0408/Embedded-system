# Qt

## 1. 创建

1.打开QTCreator

2.Application--->QT Widgets Application--->choose

3.名称：项目名(不能有中文和特殊字符)--->创建路径：项目保存位置--->下一步

4.选择构建套件（默认）--->下一步

5.类信息

5.1基类：QMainWindow窗口类（选择），QDialog对话框类，QWidget控件类

5.2界面文件勾选，创建ui文件，可视化设计界面

![image-20230607210938919](C:\Users\henry0408\AppData\Roaming\Typora\typora-user-images\image-20230607210938919.png)

## 2. 初始化的几个文件

项目生成后会自动产生几个文件:

.pro文件

mainwindow.h

main.cpp

mainwindow.cpp

mainwindow.ui



### 2.1 pro文件

目的：负责qt的配置



当我们创建完项目后，进入.pro文件会看到

* QT    += core gui network//项目指定使用的模块 

  ​	core 核心模块 

  ​	gui 图形界面模块

​		   network // 网络模块

​			sql   // 数据库模块

​			opengl  // 图像处理

* TARGET：应用程序名称

* QT+= widgets   //控件模块

* TEMPLATE = app         //编译方法，表示生成应用程序/模块变量

​		常用的：app ，lib  静态库  动态库  		

* SOURCES += main.cpp\   //源文件

  mainwindow.cpp

* HEADERS  += mainwindow.h  //头文件

* FORMS：界面文件



注意：只修改最开始QT的地方，其他地方最好不要动

![image-20230607211038105](C:\Users\henry0408\AppData\Roaming\Typora\typora-user-images\image-20230607211038105.png)



### 2.2 mainwindow.h 

虽然MainWindow是自动生成的，但他属于Ui这个命名空间下的

```
namespace Ui {
class MainWindow;
}
```

作用：避免命名空间污染

**这个MainWindow和下面的MainWindow不是同一个类！！！**

Ui::MainWindow是QT 根据MainWindow.ui文件，自动生成的类。

这个类只负责辅助我们创建界面中的控件以及设置控件的属性。

这个类在我们构建项目的时候自动生成。



QT没有命名空间，因为所有的类名都是以Q开头，所以我们定义类的时候要避免Q开头。



```
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);	//explicit：禁止隐式转换
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};
```

MainWindow类是我们自定义的主窗口类，所以要继承QMainWindow才能具备主窗口的属性



#### 2.2.1 声明Q_OBJECT宏

必须写，不要删

- 实现内存管理机制（删除父类对象，子类对象会被带走）
- 实现信号与槽机制（各个空间Widgets之间可以相互通信） 



#### 2.2.2 Qt的内存管理机制，QObject类

1）以对象树的形式组织起来

​	当为一个对象创建子对象时，子对象会自动地添加到父对象的children()列表中。

​	父对象拥有子对象的所有权，比如父对象可以在自己的析构函数中删除它的孩子对象。

​	删除父对象时，所有的子对象也会被删除

![image-20230607221356018](C:\Users\henry0408\AppData\Roaming\Typora\typora-user-images\image-20230607221356018.png)

2）QObject类

QT项目中除了自定义的C++类，另一种则是QObject类

​	1）是所有qt类的基类，父类

​	2）实现内存管理机制

​	3）实现了信号与槽的机制

​	4）提供了处理机制（父子对象的内存管理机制）

​		每一个对象都有一个父对象，由父对象来负责子对象的内存管理。



#### 2.2.3 ui成员变量

ui指针：指向UI对象，界面中所有创建的控件对象都在UI对象里







### 2.3 mainwindow.cpp

```
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
```

初始化列表，给父类初始化



显示窗口的控件：

```
ui->setupUi(this)
```







### 2.4 main.cpp

```
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);	//创建应用程序开发类
    MainWindow w;				//创建窗口类
    w.show();					//显示窗口

    return a.exec();
}
```

执行循环事件：

```
a.exec()
```





## 3. 信号signal与槽slot

QT的核心机制：当一个对象的状态发生变化时，通过信号的方式通知其他对象，其他对象通过执行相应的槽函数来响应该信号。

信号与槽是QT提供的任意两个（QObject）对象之间的通信机制，常用来完成界面操作的响应。



### 3.1 观察者模式

目的：降低耦合性

![image-20230607232634955](C:\Users\henry0408\AppData\Roaming\Typora\typora-user-images\image-20230607232634955.png)

耦合性无法消除，一个类如果和项目中的其他类没有耦合性，那它就是多余的。

既然无法消除耦合性，我们要尽量降低耦合性。观察者模式专门用来降低耦合性。

![image-20230607232647857](C:\Users\henry0408\AppData\Roaming\Typora\typora-user-images\image-20230607232647857.png)

QT希望控件之间是相互独立的，这样才更有利于功能的扩展。



**例如：当我们点击QPushButton的时候，QPushButton就会发出一个信号。我们需要定义一个槽来接收一个信号，在槽中编写按钮要触发的逻辑。**

 

**槽是一个函数**，slots和函数的访问权限写在一起，slots要写在函数访问权限的右边。

普通函数可以怎么用，槽函数也可以怎么用。只不过在QT中槽函数还可以通过信号来调用。



### 3.2 信号

可以看作是一个请求或者一个动作的标志。比如click

1）信号是属于对象的

2）当对象的状态改变时，发射信号



### 3.3 槽

#### 3.3.1 本质

其实就是一个处理函数，是在对象中声明为slots：之下的函数及其实现

其信号槽工作的过程是：当一个对象发射一个信号的时候，则和其连接的对象的槽函数进行处理，等槽函数处理完成之后退出并执行接下来的内容



#### 3.3.2 定义方法

定义在类的成员函数中，我们可以调用类的成员函数一样来调用槽函数。



mainwindow.h

```
class MainWindow : public QMainWindow       //继承
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:       //槽函数
    void slot_btn();
    void slot_btn2();
    void slot_btn3();
    void slot_btn4();
    void slot_btn5();

private:
    Ui::MainWindow *ui;
    bool flag;      //标志位负责记录灯开/关
};
```



#### 3.3.3 实现方法

假设有两个label，名字分别叫做label, label_2

mainwindow.cpp

```
void MainWindow::slot_btn()
{
    //修改文本内容，把hello变成hello world
    ui->label->setText("hello world");
    ui->label_2->setText("hello world");
}
```



#### 3.3.4 槽函数 跟普通类的成员函数的区别：

槽函数可以跟 信号建立起关联，而普通的成员函数不可以





### 3.4 connect函数

把信号和槽连接起来



注意：写在构造函数中

```
connect();
//参数：
    //1. 信号发送者
    //2. 发送的信号
    //3. 接收者
    //4. 相应的槽函数
    //5：处理模式（一般不写，默认参数）
        AutoConnection,自动连接
        DirectConnection,直接连接
        QueuedConnection,队列连接
        BlockingQueuedConnection,阻塞队列连接
        UniqueConnection 唯一连接
```



mainwindow.cpp

假设有一个按钮叫做pushButton

```
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    flag = false;

    //一个按钮负责将两个label变成hello world
    //连接函数
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(slot_btn()));
}
```



### 3.5 槽函数中获取发送信号的对象

```
QObject* sender = QObject::sender();
```



### 3.6 转到槽

作用：自动连接，不需要connect函数

右键我们添加的pushbutton

<img src="C:\Users\henry0408\AppData\Roaming\Typora\typora-user-images\image-20230608104323052.png" alt="image-20230608104323052" style="zoom: 80%;" />

![image-20230608104340221](C:\Users\henry0408\AppData\Roaming\Typora\typora-user-images\image-20230608104340221.png)

直接在mainwindow.cpp中修改函数即可：(假设我们还有一个label)

![image-20230608104653795](C:\Users\henry0408\AppData\Roaming\Typora\typora-user-images\image-20230608104653795.png)



## 4. QString

创建一个控制台项目



### 4.1 QDebug类

Debug模式可以设置断点

引入头文件

```
#include <QDebug>
```



```
//像printf一样输出
int num = 10;
qDebug("num is %d",num);

//像cout一样输出
qDebug()<<num;
```



### 4.2 QString拼接+

```
QString s1 = "hello";
QString s2 = "world";
qDebug()<<s1+s2;
```

输出

```
"helloworld"
```



#### 追加append

```
s1.append(s2);
qDebug()<<s1;
```

效果和上面一样



#### 判断是否为空isEmpty

```
qDebug()<<s1.isEmpty()
```



#### 清空clear

```
s1.clear();
qDebug()<<s1;
```



#### 格式化

```
QString s3 = QString("%1 born in %2").arg("xm").arg(1990);
qDebug()<<s3;
```



#### 数字转字符串

```
QString s = QString().setNum(16);
	QString s1 = QString("%1").arg(16);
```



#### 字符串转换其他数据类型

```
toInt() toDouble() toFloat() toLong() toLongLong()
```

```
QString s6 = "123";
bool ok;
int hex =  s6.toInt(&ok,16);//把内容转换成十六进制 最后按十进制进行输出
if(ok)//转换是否成功  转换成功 返回值为true
{
    qDebug()<<hex;
}
int dec = s6.toInt(&ok);//参数2位默认10进制
qDebug()<<dec;
```





#### 字符串比较

直接用

```
> < >= <= ==
```



## 5. 常用的控件



### 5.1 MVC开发模式

QT的开发模式是MVC开发模式

M：Model 数据模型，用来封装数据

V：View 视图，负责界面文件

C：Controller控制，逻辑层的代码



ui文件就是对视图界面单独开发



### 5.2 Widget通用属性

enable：控件是否有效（灰色状态）

geometry:有x,y,宽度，高度属性，是窗口默认显示的坐标和大小

minimumSize和maxmunSize:设置窗口的最小和最大尺寸

font 为字体菜单，选择窗口默认字体和大小

cursor 设置鼠标位于窗口中时的显示方式，包括默认状态，选中，等待等。



### 5.3 QLabel标签

显示文字和图片的控件

 

Label一般用于显示一个提示性的字符串，或者显示图片

void setText(QString); 				设置label框内的文本

void hide(); 						  隐藏label框

void clear(); 						清空label框内所有内容 

 QString Text();            获取控件的文本内容



### Line Edit

设置密码隐藏：echomode设置为password



设置提示：placeholderText添加提示文字

![image-20230608140334126](C:\Users\henry0408\AppData\Roaming\Typora\typora-user-images\image-20230608140334126.png)![image-20230608140411665](C:\Users\henry0408\AppData\Roaming\Typora\typora-user-images\image-20230608140411665.png)



## 6. 界面切换





## QT的TCP客户端

.pro文件中加入network



```
#include <QTcpSocket>
#include <QHostAddress>
```





