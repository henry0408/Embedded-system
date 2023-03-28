/*创建一个链表*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    int num;
    struct Node *pNext;
}NODE, *PNODE;

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

bool is_empty(PNODE pHead)
{
    if(pHead->pNext == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int length_list(PNODE pHead)
{
    int cnt = 0;
    //跟遍历数组思路一样
    PNODE p = pHead->pNext;

    //如果不为空
    while(p != NULL)
    {
        printf("%d ", p->num);
        p = p->pNext;
        cnt++;
    }
    printf("\n");

    return cnt;
}

bool insert_list(PNODE pHead, int pos, int val);

bool delete_list(PNODE pHead, int pos, int* val);       //删除后把删除的值的地址也记录下来

int main(void)
{
    PNODE pHead = NULL;
    pHead = create_list();
    traverse_list(pHead);       //遍历数组

    if(is_empty(pHead))
    {
        printf("The linkedlist is empty\n");
    }
    else
    {
        printf("The linkedlist is not empty\n");
    }

    int length = length_list(pHead);
    printf("The length of the list is %d\n", length);


    return 0;
}