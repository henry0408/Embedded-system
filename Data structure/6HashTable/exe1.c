#include <stdio.h>
#include <string.h>

int main()
{
    char a[] = "asdfasdlifadshjklrgeopaewrfpawedfoplhaqerqwrweqrterfgd";

    int hash[26] = {0};
    for(int z = 0; z<26; z++)
    {
        printf("%d ",hash[z]);
    }
    printf("\n");
    
    for(int i = 0; i<strlen(a);i++)
    {
        int index = a[i] - 'a';
        printf("%d\n",index);
        hash[index]++;
    }

    for(int z = 0; z<26; z++)
    {
        printf("%d ",hash[z]);
    }
    printf("\n");

    int max = hash[0];
    int max_index = 0;
    for(int j = 1; j<26; j++)
    {
        if(hash[j]>max)
        {
            max = hash[j];
            max_index = j;
        }
    }
    printf("The max index is %d, has %d number\n", max_index, max);
}