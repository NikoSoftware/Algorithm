#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char t[1000];

void PreOrderTraverse(int index)
{
    if(t[index-1]=='#')
    return;
    printf("%c",t[index-1]);
    PreOrderTraverse(index*2);
    PreOrderTraverse(index*2+1);
}
void InOrderTraverse(int index)
{
     if(t[index-1]=='#')
    return;
    InOrderTraverse(index*2);
    printf("%c",t[index-1]);
    InOrderTraverse(index*2+1);
}
void PostOrderTraverse(int index)
{
     if(t[index-1]=='#')
    return;
    PostOrderTraverse(index*2);
    PostOrderTraverse(index*2+1);
    printf("%c",t[index-1]);
}
int main()
{
    while(scanf("%s",t)!=EOF)
    {
        PreOrderTraverse(1);
        printf("\n");
        InOrderTraverse(1);
        printf("\n");
        PostOrderTraverse(1);
        printf("\n");
        printf("\n");
    }
      return 0;
}
