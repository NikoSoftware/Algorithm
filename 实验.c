/*#include<stdio.h>
#include<string.h>
struct P
{
    int n;

}num[1024];
int Len;
void Ins(int x,int n)
{
    int i;
    for(i=Len-1;i>=x;i--)
        num[i+1].n=num[i].n;
    num[x].n=n;
    Len++;

}
void Del(int x)
{
    int i;
    for(i=x;i<Len-1;i++)
        num[i].n=num[i+1].n;
    Len--;

}
void Show()
{
    int i;
    for(i=0;i<Len-1;i++)
        printf("%d ",num[i].n);
    printf("%d\n",num[Len-1].n);
}
int main()
{
    int M;
    while(scanf("%d",&M)!=EOF)
    {
        char ope[8];
        scanf("%s",ope);
        if(strcmp(ope,"ins")==0)
        {
            int x,n;
            scanf(" %d%d",&x,&n);
            Ins(x-1,n);
        }
        else if(strcmp(ope,"del")==0)
        {
            int x;
            scanf("%d",&x);
            Del(x-1);
        }
        else
            Show();
    }
    return 0;
}*/
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
