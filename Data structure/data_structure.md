数据结构和算法



# 1.衡量一个算法的标准

时间复杂度：程序大概要运行的次数



空间复杂度：算法执行过程中大概所占用的最大内存



# 2. 复习结构体以及结构体指针

```
struct Student
{
	int sid;
	char name[200];
	int age;
}

int main (void)
{
	struct Student st = {1000, "zhangsan", 23};
	stuct Student *pst;
	pst = &st;
	pst -> sid = 99;
}
```

注意：pst -> sid 等价于 (*pst).sid，等价于st.sid



```
*结构体变量作为指针在函数中传递*/

/*一个字节是一个地址，指针根据前面的类型来决定一共指向多少个字节
例如，int *p中，p指向4个字节；而char *p中，p指向一个字节；但p作为指针变量，永远占4个字节 */

#include <stdio.h>
#include <string.h>

struct Student
{
    /* data */
    int age;
    char sex;
    char name[100];
}; 

//此函数无效
void InputStudent(struct Student stu)
{
    stu.age = 10;
    strcpy(stu.name, "hangyu"); //注意，不能写成stu.name = "hangyu"
    stu.sex = 'M';
    return;
}

void InputStudent1(struct Student * pstu) //注意，不管指向的变量占多少字节，pstu都只占用4个
{
    (*pstu).age = 10;
    strcpy(pstu->name, "hangyu"); //注意，不能写成stu.name = "hangyu"
    pstu->sex = 'M';
    return;
}

int main (void)
{
    struct Student st1; //初始化

    InputStudent(st1); //此函数无效
    printf("The student's name is %s, age is %d, sex is %c\n", st1.name, st1.age, st1.sex);

    InputStudent1(&st1);
    printf("The student's name is %s, age is %d, sex is %c\n", st1.name, st1.age, st1.sex);
    return 0;
}
```



# 3. 数组复习（自己手动构建一个数组以及实现一些功能）

1. 初始化数组

   ```
   struct Arr
   {
       int *pBase;     //指向第一个元素
       int len;        //能容纳的最大元素个数（用于内存分配）
       int cnt;        //当前数组有效元素个数
   };
   ```

   

   ```
   void init_arr(struct Arr * pArr, int length)
   {
       pArr->pBase = (int*)malloc(sizeof(int)*length);
       if (pArr->pBase == NULL)            //如果分配失败
       {
           printf("Fail to allocate\n");
           exit(-1);                       //终止整个程序
       }
       else
       {
           pArr->len = length;
           pArr->cnt = 0;
       }
       return;
   }
   ```

2. 判断数组是否为空

   ```
   bool is_empty(struct Arr *pArr)
   {
       if (pArr->cnt == 0)
       {
           return true;
       }
       else
       {
           return false;
       }
   }
   ```

   

3. 判断数组是否满了

   ```
   bool is_full(struct Arr *pArr)
   {
       if(pArr ->cnt == pArr ->len)
       {
           return true;
       }
       else
       {
           return false;
       }
   }
   ```

   

4. 打印整个数组

   ```
   void show_arr(struct Arr * pArr)
   {
       if(is_empty(pArr))          //如果为空
       {
           printf("Is empty\n");
       }
       else
       {
           for (int i = 0; i<pArr->cnt; i++)
           {
               printf("%d ",pArr->pBase[i]);    //重点！！！！
           }
           printf("\n");
       }
       return;
   }
   ```

   pArr指向的是结构体，其中的pBase才是指向数组的

   

5. 在尾部加进元素

   ```
   bool append_arr(struct Arr *pArr, int num)
   {
       if(is_full(pArr))       //满了
       {
           return false;
       }
       else
       {
           pArr->pBase[pArr->cnt] = num;
           (pArr->cnt) ++;
           return true;
       }
   }
   ```

   

6. 在数组中插入元素

   ```
   //pos为插入的位置（第pos个index），其他所有元素向后移一位
   bool insert_arr(struct Arr *pArr, int pos, int val)     
   {
       if(is_full(pArr))
       {
           return false;
       }
       if(pos<1 || pos >pArr->cnt+1)
       {
           return false;
       }
       
       for (int i = (pArr->cnt) -1; i>=pos-1; i--)
       {
           pArr->pBase[i+1] = pArr->pBase[i];
       }
       pArr->pBase[pos-1] = val;
       (pArr->cnt)++;
       return true;
   }
   ```

   

7. 删除数组中的某个元素

8. 倒置整个数组

9. 数组从小到大排序





# 4. Typedef

目的：对一些类型可以自己取名字

```
#include <stdio.h>

typedef int ZHANGSAN;

int main(void)
{
	ZHANGSAN j = 20;
	printf("%d\n", j);
}
```

也可以

```
#include <stdio.h>

typedef struct Student
{
	int sid;
	char name[100];
	char sex;
}ST;

int main(void)
{
	struct Student st; //等价于ST st
	
	ST st2;
	st2.sid = 100;
	printf("%d\n", st2.sid);
}
```

或者

```
#include <stdio.h>

typedef struct Student
{
	int sid;
	char name[100];
	char sex;
} * PST;				//struct Student* == PST

int main(void)
{
	struct Student st;
	PST ps = &st;
	ps->sid = 100;
	printf("%d\n",st.sid);
}
```

再或者

```
#include <stdio.h>

typedef struct Student
{
	int sid;
	char name[100];
	char sex;
} * PST, ST;				//struct Student* == PST, struct Student == ST

int main(void)
{
	ST st;
	PST ps = &st;
	ps->sid = 100;
	printf("%d\n",st.sid);
}
```



# 5. 链表linkedlist

定义：n个节点，离散分配，彼此通过指针相互连接，每个节点只有一个前驱/后驱，首节点没有前驱节点，尾节点没有后驱节点



头节点目的：并不存放有效数据，只是方便对链表的操作（增删改查），类型和首节点一样

头指针：指向头节点的指针变量

首节点

尾节点

尾指针：指向尾节点的指针变量



确定一个链表需要一个参数：头指针，通过头指针可以推算出链表的全部信息



节点的定义：（一个节点的指针域，指向下一个节点整体）

```
typedef struct Node
{
	int num;
	struct Node * pNext;
}NODE, *PNODE;				//NODE == struct Node, PNODE == struct Node *
```



链表的分类：

单链表

双链表：每一个节点有两个指针域

 <img src="C:\Users\henry0408\AppData\Roaming\Typora\typora-user-images\image-20230327110453720.png" alt="image-20230327110453720" style="zoom:50%;" />

循环链表：能通过一个节点找到所有其他节点

非循环链表





链表操作

每一个节点有：num和pNext

1. 插入数值：q和p分别是指向两个节点的指针，q指向的节点要插入到原链表之间

   <img src="C:\Users\henry0408\AppData\Roaming\Typora\typora-user-images\image-20230327115417561.png" alt="image-20230327115417561" style="zoom:30%;" />

   方法1：定义临时变量r

   ```
   r = p->pNext; p->pNext = q; q->pNext = r;
   ```

   方法2：更好的：

   ```
   q->pNext = p->pNext;
   p->pNext = q;
   ```

   

2. 删除节点：要把p指向的节点的后面的节点删除

   相当于直接把p指向后面的节点

   ```
   p->pNext = p->pNext->pNext;		//这样写不对，因为没有free空间，会造成溢出
   ```

   正确写法：

   ```
   r = p->pNext;
   p->pNext = p->pNext->pNext;	
   free(r);
   ```

   

3. 



# 创建一个链表并且实现遍历方法

```
/*创建一个链表*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int num;
    struct Node *pNext;
}NODE, *PNODE;

```

创造链表：

<img src="C:\Users\henry0408\AppData\Roaming\Typora\typora-user-images\image-20230327195448896.png" alt="image-20230327195448896" style="zoom:55%;" />

```
PNODE create_list()             //创建非循环单链表，并将头节点赋给PNODE
{
    int len;
    int i;
    int val;

    //创建一个不存放有效数据的头节点，pHead是头指针
    PNODE pHead = (PNODE)malloc(sizeof(NODE));

    //pTail永远指向最后一个节点
    PNODE pTail = pHead;
    pTail->pNext = NULL;
    if (pHead == NULL)
    {
        printf("Fail\n");
        exit(-1);
    }

    printf("Please enter the length of the array: \n");
    scanf("%d", &len);

    for (i = 0; i< len; i++)
    {
        printf("Please enter the num: ");
        scanf("%d", &val);
        PNODE pNew = (PNODE)malloc(sizeof(NODE));
        if (pHead == NULL)
        {
            printf("Fail\n");
            exit(-1);
        }
        //尾插法创造新节点
        pNew->num = val;
        pTail->pNext = pNew;
        pNew->pNext = NULL;
        pTail = pNew;
    }
    return pHead;
}
```

遍历链表：

<img src="C:\Users\henry0408\AppData\Roaming\Typora\typora-user-images\image-20230327195856496.png" alt="image-20230327195856496" style="zoom:40%;" />

```
//遍历链表，用一个指针p，不断p=p->Next遍历到下一个节点
void traverse_list(PNODE pHead)
{
    PNODE p = pHead->pNext;

    //如果不为空
    while(p != NULL)
    {
        printf("%d ", p->num);
        p = p->pNext;
    }
    printf("\n");

    return;
}

int main(void)
{
    PNODE pHead = NULL;
    pHead = create_list();
    traverse_list(pHead);       //遍历数组

    return 0;
}
```



# 6. 栈Stack

先入后出

分类：1.静态栈 2.动态栈

静态栈是连续的，类似数组；动态栈类似链表

<img src="C:\Users\henry0408\AppData\Roaming\Typora\typora-user-images\image-20230417010912883.png" alt="image-20230417010912883" style="zoom:30%;" />

算法：出栈pop/压栈push



1. 初始化

   <img src="C:\Users\henry0408\AppData\Roaming\Typora\typora-user-images\image-20230417010937064.png" alt="image-20230417010937064" style="zoom:33%;" />

2. 入栈

   <img src="C:\Users\henry0408\AppData\Roaming\Typora\typora-user-images\image-20230417010946614.png" alt="image-20230417010946614" style="zoom:33%;" />

3. 遍历

   <img src="C:\Users\henry0408\AppData\Roaming\Typora\typora-user-images\image-20230417011004090.png" alt="image-20230417011004090" style="zoom:33%;" />

4. 出栈
