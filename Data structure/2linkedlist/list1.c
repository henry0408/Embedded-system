/*创建一个链表*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    int num;
    struct Node *pNext;
}NODE, *PNODE;


PNODE create_list();
void traverse_list(PNODE pHead);
bool is_empty(PNODE pHead);
int length_list(PNODE pHead);
void sort_list (PNODE pHead);
bool insert_list(PNODE pHead, int pos, int val);
bool delete_list(PNODE pHead, int pos, int* val); 


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
        //printf("%d ", p->num);
        p = p->pNext;
        cnt++;
    }
    //printf("\n");

    return cnt;
}

void sort_list (PNODE pHead)
{
    int len = length_list(pHead);       //先求出链表长度
    PNODE p, q;
    int i, j;
    for (i = 0, p = pHead->pNext; i < len-1; i++, p = p->pNext)
    {
        /* code */
        for (j = 0, q = pHead->pNext; j<len-1-i; j++, q = q->pNext)
        {
            if (q->num > q->pNext->num)
            {
                int t = q->num;
                q->num = q->pNext->num;
                q->pNext->num = t;
            }
        }
    }
    return;
}

//在pHead指向的链表的第pos个节点前面增加一个新的节点，值为val
//(但是同时可以实现，如果长度为5，可以在最后插入第六个节点)
bool insert_list(PNODE pHead, int pos, int val)
{
    //先让链表遍历到当前的pos-1的节点，叫做p
    int i = 0;
    PNODE p = pHead;        //初始为头节点
    while (p != NULL && i<pos-1)
    {
        p = p->pNext;
        i++;
    }
    if(i > pos-1 || p == NULL)      //如果pos值小于-1，或者pos值大于i+1（精髓所在）
    {
        return false;
    }

    //接着，开辟一个新的节点
    PNODE pNew = (PNODE)malloc(sizeof(NODE));
    pNew->num = val;
    if(pNew == NULL)
    {
        printf("fail to malloc\n");
        exit(-1);
    }
    //，让p节点指向新开辟的节点(好像不需要第三个节点)
    pNew->pNext = p->pNext;
    p->pNext = pNew;
}

bool delete_list(PNODE pHead, int pos, int* val)    //删除后把删除的值的地址也记录下来
{
    int i = 0;
    PNODE p = pHead;        //初始为头节点
    while (p->pNext != NULL && i<pos-1)
    {
        p = p->pNext;
        i++;
    }
    if(i > pos-1 || p->pNext == NULL)      //如果pos值小于-1，或者pos值大于i+1（精髓所在）
    {
        return false;
    }
    //建立一个新节点便于删除
    PNODE q = p->pNext;
    *val = q->num;
    p->pNext = q->pNext;
    //free(q);
    q = NULL;
}       

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

    sort_list(pHead);
    traverse_list(pHead); 

    insert_list(pHead, 4, 10);
    traverse_list(pHead); 

    int delete_num;
    int *p = &delete_num;
    int pos = 3;
    if(delete_list(pHead,pos, p))       //如果删除成功
    {
        printf("delete successfully\n");
        traverse_list(pHead); 
        printf("The num deleted is %d\n",*p);
    }
    //delete_list(pHead,pos, p);
    // traverse_list(pHead); 
    // printf("The num deleted is %d\n",*p);


    return 0;
}