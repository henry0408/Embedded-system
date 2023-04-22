/*注意：这里我们规定好队列长度为6 （在init函数中）,也就是说只能存5个元素
(pQ->front+1)%6表示front向后移一位
(pQ->rare+1)%6表示rare向后移一位；
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Queue
{
    int *pBase;
    int front;
    int rare;
} QUEUE;

void init(QUEUE *pQ);
bool en_queue(QUEUE *pQ, int val);
void traverse_queue(QUEUE *pQ);
bool full_queue(QUEUE *pQ);
bool empty_queue(QUEUE *pQ);
bool out_queue(QUEUE *pQ, int* pVal);    //出队，并保留出队的元素的数值

int main()
{
    QUEUE Q;
    init(&Q);
    en_queue(&Q,1);
    en_queue(&Q,2);
    en_queue(&Q,3);
    en_queue(&Q,4);
    en_queue(&Q,5);
    en_queue(&Q,6);
    en_queue(&Q,7);
    traverse_queue(&Q);

    int val;
    if(out_queue(&Q, &val))
    {
        printf("Out queue successfully, the value is %d\n",val);
    }
    else
    {
        printf("Out queue unsuccessfully\n");
    }
    traverse_queue(&Q);
}

void init(QUEUE *pQ)
{
    pQ->pBase = (int*)malloc(sizeof(int)*6);
    pQ->front = 0;
    pQ->rare = 0;
}

bool full_queue(QUEUE *pQ)
{
    if( (pQ->rare+1)%6 == pQ->front )
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool en_queue(QUEUE *pQ, int val)
{
    if( full_queue(pQ) )
    {
        return false;
    }
    else
    {
        pQ->pBase[pQ->rare] = val;
        pQ->rare = (pQ->rare+1)%6;
        return true;
    }
}

void traverse_queue(QUEUE *pQ)
{
    int i = pQ->front;
    while(i != pQ->rare)
    {
        printf("%d ",pQ->pBase[i]);
        i = (i+1) % 6;
    }
    printf("\n");

    return;
}

bool empty_queue(QUEUE *pQ)
{
    if(pQ->front == pQ->rare)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool out_queue(QUEUE *pQ, int* pVal)
{
    if( empty_queue(pQ) )
    {
        return false;
    }
    else
    {
        *pVal = pQ->pBase[pQ->front];
        pQ->front = (pQ->front+1)%6;
        return true;
    }
}