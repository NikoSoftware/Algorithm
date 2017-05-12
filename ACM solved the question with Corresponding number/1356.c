#include<stdio.h>
struct F{
int year;
int m;
int d;

}num[1024];
int Year(int a){
if(a%400==0||(a%4==0&&a%100!=0))
return 1;
else
return 0;

}
int main(){
    int i,j,n=0;
    struct F a;
    int b[40]={31,28,31,30,31,30,31,31,30,31,30,31};
    scanf("%d%d%d",&a.year,&a.m,&a.d);
    for(i=0;i<a.m-1;i++){
    n +=b[i];
    }
    if(a.m>2)
    n+=a.d+Year(a.year);
    else
    n+=a.d;

    printf("%d\n",n);
    return 0;

}
