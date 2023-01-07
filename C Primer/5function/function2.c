/*判断一个数字是不是素数
素数：只能被1和它本身整除
*/

#include <stdio.h>
#include <stdbool.h>

// 判断一个数字是不是素数
bool is_prime (int num){
    int i;
    for (i = 2; i<= num; i = i+1){ //这个不用担心最后i = num + 1会对if判断造成问题，因为直接break掉了，i最后不会再+1
        if (num % i == 0){ //如果只有本身可以整除，即为素数
            break;
        }
    }
    if (i == num){
        return true;
    }
    else{
        return false;
    }
}

// 打印出1到一个数字范围之内所有的素数
void print_all (int num)
{
    int i;

    for (i = 1; i<= num; i++){
        if (is_prime(i)){
            printf("%d\n", i);
        }
    }
}

int main (void)
{
    int num;
    scanf("%d", &num);
    
    print_all(num);

    return 0;
}