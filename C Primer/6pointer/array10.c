#include <stdio.h>
#include <string.h>

int main(){
    char *str = "http://c.biancheng.net";
    int len = strlen(str), i;
   
    //直接输出字符串
    printf("%s\n", str);
    //使用*(str+i)
    for(i=0; i<len; i++){
        printf("%c", *(str+i));
    }
    printf("\n");
    //使用str[i]
    for(i=0; i<len; i++){
        printf("%c", str[i]);
    }
    printf("\n");

    return 0;
}