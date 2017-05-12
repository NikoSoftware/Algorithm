#include<stdio.h>
int n,m;
int c;
void dfs(float cur,int f,int z)
{

        if(cur==0&&f==m)
            c++;
        else if(f<m)
            for(int i=z; i<=(cur/(m-f)); i++)
            {
                dfs(cur-i,f+1,i);
            }

}
int main()
{
    int k;
    while(scanf("%d",&k)!=EOF)
    {
        for(int i=0; i<k; i++)
        {
            c=0;
            scanf("%d%d",&n,&m);
            dfs(n,0,0);
            printf("%d\n",c);
        }
    }
    return 0;
}
