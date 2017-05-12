#include<stdio.h>
#include<iostream>
#include<queue>
using namespace std;

int num[10000];
int opt[10000];
int main()
{
	int i,j,k,tmp;
	int cnt,Case=0;
	while(scanf("%d",&tmp)!=EOF && tmp!=-1)
	{
		Case++;
		cnt=0;
		num[cnt++]=tmp;
		while(scanf("%d",&tmp)!=EOF && tmp!=-1)
		{
			num[cnt++]=tmp;
		}
		int max=1;
		for(i=0;i<cnt;i++)
		{
			opt[i]=1;
			for(j=0;j<i;j++)
			{
				if(num[i] < num[j] && opt[i] <= opt[j])
				{
					opt[i]=opt[j]+1;
				}
			}
			if(max < opt[i]) max=opt[i];
		}
		printf("Test #%d:\n  maximum possible interceptions: %d\n\n",Case,max);
	}
	return 1;
}
