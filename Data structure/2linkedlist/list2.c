/*��ͷ����*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node * pNext;
} linked_node_t;

int main()
{
    linked_node_t a = {11,NULL};
    linked_node_t b = {22,NULL};
    linked_node_t c = {33,NULL};
    linked_node_t d = {44,NULL};
    a.pNext = &b;
    b.pNext = &c;
    c.pNext = &d;

    linked_node_t *h = &a;
    while(h != NULL)        //����д��h->pNext
    {
        printf("%d ",h->data);
        h = h->pNext;
    }
    printf("\n");
}