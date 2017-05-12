#include<stdio.h>
#include<stdlib.h>  
#define size 20  
struct stacks  //定义一个临时存储空间结构体（栈） 
{
     
    int data[size];//数组   
    int top;//作为结构体标记 
} stack;
  
void main()
{
      
      int w[size];//定义数组  
     int V;
     
     int k=0;
     
     int i=0;
     
     int j=1;
     int number;
     
    int s=0;
       
    printf("\n请输入可供选择装入物品的个数：");
     scanf("%d",&number);
     
     printf("\n请输入各件物品的体积：");
      for(i=0; i<number; i++)
    {
        scanf("%d",&w[i]);    //把数组每个元素加起来  
         printf("\n可供选择的物品的总体s=%dn",s);
         printf("\n请输入背包的总体积：");
        scanf("%d",&V); 
    }//按次序给数组赋值  
     for(i=0; i<number; i++)
    {
         s=s+w[i];
    }
      if(V<0||V>s)
    {
        printf("\n输入背包体积错误");    //判断总体积必须大于0或小于物品总体积  
         printf("\n");
         
    }
      for(i=0; i<number; i++)
    {
        stack.data[i]=0;    //把结构体的data数组的每个元素初始化为0   
          stack.top=0;//初始化结构体标记为0 
    }
        do
    {
           while(V>0&&k<=number)//当V大于0并且k小于等于物品个数，则运行下面循环   {  
             
             
            if(V>=w[k])//每次循环判断V变量是否还大于每个元素 
            { 
                  int w[size];//定义数组  
                 int V;
                 int k=0;
                 int i=0;
                 int j=1;
                  
                 int number;
                 int s=0;
                   
                printf("\n请输入可供选择装入物品的个数：");
                 
                 scanf("%d",&number);
                 
                 printf("\n请输入各件物品的体积：");
                 
                  for(i=0; i<number; i++)
                {
                    scanf("%d",&w[i]);    //把数组每个元素加起来  
                     printf("\n可供选择的物品的总体s=%dn",s);
                      
                    printf("\n请输入背包的总体积：");
                      
                    scanf("%d",&V);
                     
                }//按次序给数组赋值  
                 for(i=0; i<number; i++)
                {
                     s=s+w[i];
                }
                  if(V<0||V>s)
                {
                    printf("\n输入背包体积错误");    //判断总体积必须大于0或小于物品总体积 
                      printf("\n");
                     
                }
                  for(i=0; i<number; i++)
                {
                    stack.data[i]=0;    //把结构体的data数组的每个元素初始化为0   
                      stack.top=0;//初始化结构体标记为0 
                }
                    do
                {
                       while(V>0&&k<=number)//当V大于0并且k小于等于物品个数，则运行下面循环 
                           {  
                               
                               
                              if(V>=w[k])//每次循环判断V变量是否还大于每个元素 
                                   { 
                                            stack.data[stack.top]=k;
                                          //符合条件的元素标识记录在结构体的数组中    
                                          stack.top++;
                                         
                                            V-=w[k];//每次循环就把V变量减去该次循环元素的体积数     
                                       } 
                                
                               
                              k++;
                               
                                  
                             }//循环结束 
                             if(V==0) //当v变量只等于0时输出结果   
                            {
                                printf("第%d个符合条件的解：",j);
                                 
                                   for(i=0; i<stack.top; i++)   
                                     
                                {
                                    printf("%d ",w[stack.data[i]]);
                                } 
                                  j++;
                                  
                                 
                                printf("\n");
                                 
                                       
                            }      k=stack.data[--stack.top];
                         stack.data[stack.top]=0;
                         V+=w[k];
                         k++;
                     
                         
                }
                while(!(stack.top==0&&k==number));//当k等于物品个数时候结束整个循环 } 
