/*链表的创建*/

#include <stdio.h>

struct Node
{
    int val;
    struct Node *pNext; //pNext存放的是下一个节点的地址，下一个节点的类型也是struct Node
};

int main (void)
{
    struct Node * pHead; //pHead用来存储头节点的地址

    pHead = CreateList();
    TraverseList(pHead);

    return 0;
}