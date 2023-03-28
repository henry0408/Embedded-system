/*�ֶ�����һ������*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Arr
{
    int *pBase;     //��һ��Ԫ��
    int len;        //�����ɵ����Ԫ�ظ����������ڴ���䣩
    int cnt;        //��ǰ������ЧԪ�ظ���
};

void init_arr(struct Arr * pArr, int length);

bool is_empty(struct Arr *pArr);        //��Ч����Ϊ0��Ϊ��

bool is_full(struct Arr *pArr);

void show_arr(struct Arr * pArr);

bool append_arr(struct Arr *pArr, int num);

bool insert_arr(struct Arr *pArr, int pos, int num);    //posֵ��1��ʼ���±�Ϊ0Ϊ��һ��Ԫ�أ�

bool delete_arr(struct Arr *pArr, int pos, int * pVal);             //pos��1��ʼ��ɾ��֮�󻹿��Է���ɾ����ֵ

void reverse_arr(struct Arr *pArr);                     //��������

void sort_arr(struct Arr *pArr);
//int get();

int main (void)
{
    struct Arr arr;
    init_arr(&arr, 6);     //ע�⣺ֻ�ܴ���ַ
    
    show_arr(&arr);         //ע�⣺����ֱ�Ӵ�arr��������
    append_arr(&arr, 8);
    append_arr(&arr, 2);
    append_arr(&arr, 13);
    append_arr(&arr, -1);
    append_arr(&arr, -3);
    append_arr(&arr, 9);
    show_arr(&arr);

    insert_arr(&arr, 1, 99);
    show_arr(&arr);

    int val;        //���ڴ��ɾ����Ԫ�ص���ֵ        
    delete_arr(&arr, 1, &val);
    printf("The num you delete is %d\n",val);
    show_arr(&arr);

    reverse_arr(&arr);
    show_arr(&arr);

    sort_arr(&arr);
    show_arr(&arr);
    
    return 0;
}

void init_arr(struct Arr * pArr, int length)
{
    pArr->pBase = (int*)malloc(sizeof(int)*length);
    if (pArr->pBase == NULL)            //�������ʧ��
    {
        printf("Fail to allocate\n");
        exit(-1);                       //��ֹ��������
    }
    else
    {
        pArr->len = length;
        pArr->cnt = 0;
    }
    return;
}

bool is_empty(struct Arr *pArr)
{
    if (pArr->cnt == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}


bool is_full(struct Arr *pArr)
{
    if(pArr ->cnt == pArr ->len)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void show_arr(struct Arr * pArr)
{
    if(is_empty(pArr))          //���Ϊ��
    {
        printf("Is empty\n");
    }
    else
    {
        for (int i = 0; i<pArr->cnt; i++)
        {
            printf("%d ",pArr->pBase[i]);    //�ص㣡������
        }
        printf("\n");
    }
    return;
}

bool append_arr(struct Arr *pArr, int num)
{
    if(is_full(pArr))       //����
    {
        return false;
    }
    else
    {
        pArr->pBase[pArr->cnt] = num;
        (pArr->cnt) ++;
        return true;
    }
}

bool insert_arr(struct Arr *pArr, int pos, int val)     //posΪ�����λ�ã���pos��index������������Ԫ�������һλ
{
    if(is_full(pArr))
    {
        return false;
    }
    if(pos<1 || pos >pArr->cnt+1)
    {
        return false;
    }
    
    for (int i = (pArr->cnt) -1; i>=pos-1; i--)
    {
        pArr->pBase[i+1] = pArr->pBase[i];
    }
    pArr->pBase[pos-1] = val;
    (pArr->cnt)++;
    return true;
}

bool delete_arr(struct Arr *pArr, int pos, int * pVal)
{
    if(is_empty(pArr))
    {
        return false;
    }

    if(pos<1 || pos>pArr->cnt)
    {
        return false;
    }

    *pVal = pArr->pBase[pos-1];
    for (int i = pos; i<pArr->cnt; i++)         //ɾ����Ԫ�غ��������Ԫ����ǰ��һλ
    {
        pArr->pBase[i-1] = pArr->pBase[i];
    }
    pArr->cnt --;
    return true;
}


void reverse_arr(struct Arr *pArr)          //����һ�����飬ǰ�벿��Ԫ�غͺ�벿��Ԫ��һһ�滻
{
    int temp;
    for (int i = 0; i< (pArr->cnt)/2; i++)
    {
        temp = pArr->pBase[i];
        pArr->pBase[i] = pArr->pBase[pArr->cnt-i-1];
        pArr->pBase[pArr->cnt-i-1] = temp;
    }
    return;
}


void sort_arr(struct Arr *pArr)                 //ð������
{
    int temp;
    for (int i = 0; i<pArr->cnt-1; i++)
    {
        for (int j = 0; j<pArr->cnt-1-i; j++)
        {
            if (pArr->pBase[j] > pArr->pBase[j+1])
            {
                temp = pArr->pBase[j];
                pArr->pBase[j] = pArr->pBase[j+1];
                pArr->pBase[j+1] = temp;
            }
        }
    }
    return;
}
