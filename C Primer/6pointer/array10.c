#include <stdio.h>
#include <string.h>

int main(){
    char *str = "http://c.biancheng.net";
    int len = strlen(str), i;
   
    //ֱ������ַ���
    printf("%s\n", str);
    //ʹ��*(str+i)
    for(i=0; i<len; i++){
        printf("%c", *(str+i));
    }
    printf("\n");
    //ʹ��str[i]
    for(i=0; i<len; i++){
        printf("%c", str[i]);
    }
    printf("\n");

    return 0;
}