/*单项循环链表

尾节点指向首节点

*/
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>


typedef struct Node
{
    int num;
    struct Node *pNext;
}NODE, *PNODE;


PNODE init_list()
{
    int len;
    printf("Please enter the length of the list: ");
    scanf("%d",&len);

    PNODE head = (PNODE)malloc(sizeof(NODE));
    PNODE tail = head;
    tail->pNext = NULL;

    int val;
    int i;
    for(i = 0; i<len; i++)
    {
        printf("Please enter the val: ");
        scanf("%d",&val);
        PNODE new = (PNODE)malloc(sizeof(NODE));
        new->num = val;
        new->pNext = NULL;
        tail->pNext = new;
        tail = new;
    }
    tail->pNext = head->pNext;

    return head;
}

void traverse_list(PNODE pHead)
{
    PNODE p = pHead;
    PNODE q = pHead->pNext;

    //如果不为空
    
    while(q->pNext != p->pNext)
    {
        printf("%d ", q->num);
        q = q->pNext;
        
    }
    printf("%d\n",q->num);

    return;
}

PNODE kill(PNODE pHead, int num, int start)
{
    PNODE pnode = pHead->pNext;
    for(int i = 0; i<start; i++)
    {
        pnode = pnode->pNext;
    }
    //printf("%d\n",pnode->num);

    while(pnode != pnode->pNext)
    {
        for(int j = 0; j<num-2;j++)
        {
            pnode = pnode->pNext;
        }
        PNODE next = pnode->pNext;
        pnode->pNext = next->pNext;
        free(next);
    }
    // for(int j = 0; j<num-2;j++)
    // {
    //     pnode = pnode->pNext;
    // }
    // printf("%d\n",pnode->num);
    // PNODE next = pnode->pNext;
    // printf("%d\n",next->num);
    // pnode->pNext = next->pNext;
    return pnode;
}


int main()
{
    PNODE pHead = NULL;
    pHead = init_list();
    traverse_list(pHead);       //遍历数组
    PNODE final = kill(pHead,5,1);
    traverse_list(final); 
}