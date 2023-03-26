数据结构和算法



# 衡量一个算法的标准

时间复杂度：程序大概要运行的次数



空间复杂度：算法执行过程中大概所占用的最大内存







# 复习结构体以及结构体指针

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

