#include <iostream>
#include<stdio.h>
#include<string.h>
#include<string>
#include<map>

using namespace std;

map<string,int> s;

int main()
{
    int n;
    char a[100],data[100];
    while(scanf("%d",&n)!=EOF&&n!=0)
    {
        int max=0;
        for(int i=0;i<n;i++)
        {
            scanf("%s",data);
            s[data]++;
            if(s[data]>max)
            {
                max=s[data];
                strcpy(a,data);
            }
        }
        printf("%s\n",a);
        s.clear();
    }
    return 0;
}
