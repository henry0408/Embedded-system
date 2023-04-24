/*����һ������*/
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
        //printf("%d ", p->num);
        p = p->pNext;
        cnt++;
    }
    //printf("\n");

    return cnt;
}

void sort_list (PNODE pHead)
{
    int len = length_list(pHead);       //�����������
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

//��pHeadָ�������ĵ�pos���ڵ�ǰ������һ���µĽڵ㣬ֵΪval
//(����ͬʱ����ʵ�֣��������Ϊ5��������������������ڵ�)
bool insert_list(PNODE pHead, int pos, int val)
{
    //���������������ǰ��pos-1�Ľڵ㣬����p
    int i = 0;
    PNODE p = pHead;        //��ʼΪͷ�ڵ�
    while (p != NULL && i<pos-1)
    {
        p = p->pNext;
        i++;
    }
    if(i > pos-1 || p == NULL)      //���posֵС��-1������posֵ����i+1���������ڣ�
    {
        return false;
    }

    //���ţ�����һ���µĽڵ�
    PNODE pNew = (PNODE)malloc(sizeof(NODE));
    pNew->num = val;
    if(pNew == NULL)
    {
        printf("fail to malloc\n");
        exit(-1);
    }
    //����p�ڵ�ָ���¿��ٵĽڵ�(������Ҫ�������ڵ�)
    pNew->pNext = p->pNext;
    p->pNext = pNew;
}

bool delete_list(PNODE pHead, int pos, int* val)    //ɾ�����ɾ����ֵ�ĵ�ַҲ��¼����
{
    int i = 0;
    PNODE p = pHead;        //��ʼΪͷ�ڵ�
    while (p->pNext != NULL && i<pos-1)
    {
        p = p->pNext;
        i++;
    }
    if(i > pos-1 || p->pNext == NULL)      //���posֵС��-1������posֵ����i+1���������ڣ�
    {
        return false;
    }
    //����һ���½ڵ����ɾ��
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

    sort_list(pHead);
    traverse_list(pHead); 

    insert_list(pHead, 4, 10);
    traverse_list(pHead); 

    int delete_num;
    int *p = &delete_num;
    int pos = 3;
    if(delete_list(pHead,pos, p))       //���ɾ���ɹ�
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