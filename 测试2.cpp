#include<stdio.h>
int father[30000],num[30000],dis[30000];
 
int find(int x) 
{
     if(x!=father[x])  
    {
        int temp=father[x];
        father[x]=find(father[x]);
        dis[x]+= dis[temp];
            
    } 
     return father[x];
}   
//把a放在b上面；father_b改变；
void union_set(int a,int b) 
{
     
          int f_a=find(a),f_b=find(b);
          father[f_b]=f_a;
          dis[f_b]=num[f_a];
          num[f_a]+= num[f_b];
     
}  
int main() 
{
        int N,i,a,b;
         char ch[3];
        while(scanf("%d",&N)!=EOF)   
          {
            for(i=1; i<30000; i++) 
            father[i]=i,num[i]=1,dis[i]=0; 
                
           for(i=1; i<=N; i++)
            {
                  scanf("%s",ch);
                     if(*ch=='M')      
                    {
                 
                               scanf("%d%d",&a,&b);
                               union_set(a,b);
                      
                    } 
                       else        
                     {
                 
                               scanf("%d",&a);
                                int t=find(a);
                 
                               printf("%d\n",num[t]-dis[a]-1);
                            
            }        
        }     
    } 
} 



