#include <stdio.h>

int main(void)
{
    float weight;
    float value;

    printf("Please enter your weight in pounds: \n");

    scanf("%f", &weight);

    value = 1700.0 * weight * 14.5833;

    printf("Your weight in platinum is worth $%.2f. \n", value);

    return 0;
}
