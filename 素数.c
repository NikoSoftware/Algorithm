#include<stdio.h>
#include<math.h>
int prim(int k,int mod)
{
    if(mod>sqrt(k))
    {
        return 1;
    }
    if(k%mod==0)
    {
        return 0;
    }
    else
    return prim(k,mod+1);
}
int main()
{
    int k;
    while(scanf("%d",&k)!=EOF)
    {
        printf("%d",prim(k,2));
    }

}





