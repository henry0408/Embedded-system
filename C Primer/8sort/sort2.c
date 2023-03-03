/*学生信息系统，动态按学生成绩排序

结构体数组
*/

# include <stdio.h>
# include <malloc.h>

struct Student
{
    int age;
    float score;
    char name[100];
};

int main (void)
{
    int len;
    struct Student* pArr;
    printf("Please enter the number of the student: \n");
    printf("len = ");
    scanf("%d", &len);

    // 动态构造一维数组
    pArr = (struct Student*)malloc(len*sizeof(struct Student));

    for(int i = 0; i<len; i++){
        printf("Please enter the %dth student info: \n",i+1);
        printf("age = ");
        scanf("%d", &pArr[i].age);
        printf("\n");

        printf("name = ");
        scanf("%s", pArr[i].name); //不需要加取地址符，因为name是数组名，本身就是数组第一个元素的地址
        printf("\n");

        printf("score = ");
        scanf("%f", &pArr[i].score);
        printf("\n");
    }

    //排序
    struct Student t;
    for (int i = 0; i<len-1; i++){
        for (int j = 0; j<len-1-i; j++){
            if (pArr[j].score > pArr[j+1].score){
                t = pArr[j];
                pArr[j] = pArr[j+1];
                pArr[j+1] = t;  
            }
        }
    }


    //输出
    for(int i = 0; i<len; i++){
        printf("Output the %dth student info: \n",i+1);
        printf("age = %d \n", pArr[i].age);

        printf("name = %s \n", pArr[i].name);

        printf("score = %f \n", pArr[i].score);
    }

    return 0;
}
