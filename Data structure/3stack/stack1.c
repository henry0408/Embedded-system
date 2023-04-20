#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    int data;
    struct Node * pNext;
}NODE, *PNODE;

typedef struct Stack
{
    PNODE pTop;
    PNODE pBottom;
}STACK, *PSTACK;

void initStack(PSTACK);

void pushStack(PSTACK,int);

void traverseStack(PSTACK);

bool empty(PSTACK);

bool popStack(PSTACK, int*);      //int保存出栈的元素，bool判断是否出栈成功

int main()
{
    STACK S;
    initStack(&S);
    pushStack(&S, 1);
    pushStack(&S, 2);
    traverseStack(&S);      //倒序输出
    int num;
    if(popStack(&S,&num))
    {
        printf("Pop successfully, the value is %d\n",num);
    }
    else{
        printf("Pop unsuccessful\n");
    }
    traverseStack(&S);      //倒序输出
    return 0;
}

void initStack(PSTACK pS)
{
    pS->pTop = (PNODE)malloc(sizeof(NODE));
    if(NULL == pS->pTop)
    {
        printf("分配失败\n");
        exit(-1);
    }
    else
    {
        pS->pBottom = pS->pTop;
        pS->pTop->pNext = NULL;     //指针域为NULL
    }
}

void pushStack(PSTACK pS, int num)
{
    PNODE pNew = (PNODE)malloc(sizeof(NODE));
    pNew->pNext = pS->pTop;          //注意不能改成pBottom
    pNew->data = num;
    pS->pTop = pNew;

    return;
}

void traverseStack(PSTACK pS)
{
    PNODE p = pS->pTop;
    while (p != pS->pBottom)            //都指向头节点表示遍历结束
    {
        printf("%d ", p->data);
        p = p->pNext;
    }
    printf("\n");

    return;
}

bool empty(PSTACK pS)
{
    if(pS->pBottom == pS->pTop)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool popStack(PSTACK pS, int* pVal)
{
    if(empty(pS))
    {
        return false;
    }
    PNODE r = pS->pTop;
    *pVal = r->data;
    pS->pTop = r->pNext;
    free(r);
    return true;

}