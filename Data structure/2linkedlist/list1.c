/*����һ������*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    int num;
    struct Node *pNext;
}NODE, *PNODE;

PNODE create_list()             //������ѭ������������ͷ�ڵ㸳��PNODE
{
    int len;
    int i;
    int val;

    //����һ���������Ч���ݵ�ͷ�ڵ㣬pHead��ͷָ��
    PNODE pHead = (PNODE)malloc(sizeof(NODE));

    //pTail��Զָ�����һ���ڵ�
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
        //β�巨�����½ڵ�
        pNew->num = val;
        pTail->pNext = pNew;
        pNew->pNext = NULL;
        pTail = pNew;
    }
    return pHead;
}

//����������һ��ָ��p������p=p->Next��������һ���ڵ�
void traverse_list(PNODE pHead)
{
    PNODE p = pHead->pNext;

    //�����Ϊ��
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
    //����������˼·һ��
    PNODE p = pHead->pNext;

    //�����Ϊ��
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

bool delete_list(PNODE pHead, int pos, int* val);       //ɾ�����ɾ����ֵ�ĵ�ַҲ��¼����

int main(void)
{
    PNODE pHead = NULL;
    pHead = create_list();
    traverse_list(pHead);       //��������

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