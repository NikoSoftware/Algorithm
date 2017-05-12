#include<stdio.h>
#include<string.h>
int main()
{
    char s1[4][8], s[16];
    scanf("%s",s);
    int i, posi[3], k = 0,k1 = 0;
    for(i = 0; i < strlen(s); i++)
    {
        if(s[i] == '.')
        {
            s1[k][k1]='\0';
            k++;
            k1=0;
        }
        else
        {
            s1[k][k1++] = s[i];
        }
    }
    s1[k][k1]='\0';
    for(i = 0; i < k; i++)
        printf("%s\n",s1[i]);
    printf("%s\n",s1[k]);
    return 0;
}
