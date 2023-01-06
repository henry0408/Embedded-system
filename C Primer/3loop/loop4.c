/*用do while解一元二次方程: ax^2 + bx + c = 0
delta = b^2 - 4ac
x1, x2 = (-b +- sqrt(b^2 - 4ac))/2a
*/

/*do while语句格式: do中的内容永远先执行一次
do{
    ...
}
while (){
    ...
}

*/


#include <stdio.h>
#include <math.h> //使用sqrt

int main (void)
{
    double a, b, c;

    double x1, x2;

    char ch;

    do{
        printf("The value of a is: \n");
        scanf("%lf", &a);

        printf("The value of b is: \n");
        scanf("%lf", &b);

        printf("The value of c is: \n");
        scanf("%lf", &c);

        double delta;
        delta = b*b - 4*a*c;

        if (delta == 0){
            x1 = (-b + sqrt(b*b - 4*a*c))/(2*a);
            printf("The value of x1 and x2 is %lf\n", x1);
        }
        else if (delta < 0){
            printf("No solution \n");
        }
        else{
            x1 = (-b + sqrt(b*b - 4*a*c))/(2*a);
            x2 = (-b - sqrt(b*b - 4*a*c))/(2*a);

            printf("The value of x1 is %lf\n", x1);
            printf("The value of x2 is %lf\n", x2);
        }
        //重点：此时scanf要加一个空格
        printf("Should we continue? (Y/N)");
        scanf(" %c", &ch);
    }while(ch == 'Y');

    return 0;
}