//∫√À„∑®
#include<iostream>
#include<cstdio>
#include<cstring>

int num[4]= {0,5,3,1};
int box[7];

int main()
{


    while(1)
    {
        int tmp=0;
        for(int i=1; i<=6; i++)
        {
            scanf("%d",&box[i]);
            tmp+=box[i];
        }
        if(tmp==0)
            break;
        int ans=box[6]+box[5]+box[4]+(box[3]+3)/4;
        int a2=box[4]*5+num[box[3]%4];
        if(box[2]>a2)
            ans+=(box[2]-a2+8)/9;
        int a1=ans*36-box[6]*36-box[5]*25-box[4]*16-box[3]*9-box[2]*4;
        if(box[1]>a1)
            ans+=(box[1]-a1+35)/36;
        printf("%d\n",ans);
    }
    return 0;
}
