#include<stdio.h>
#include<string.h>
#define maxn 10000
struct StackOp
{
    char op[maxn];
    int top;
} stackop;
struct  StackNum
{
    double num[maxn];
    int top;
} stacknum;
char GetRpn(char *str,char *rpn)
{
    int len=strlen(str),cnt=0;
    stackop.top=0;
    if(str[0]=='-')
    {
        rpn[cnt++]='0';
        rpn[cnt++]='#';
    }
    for(int i=0; i<len; i++)
    {
        if(str[i]>='0'&&str[i]<='9')
        {
            rpn[cnt++]=str[i];
            isnum=true;
            continue;
        }
        if(isnum)
        {
            rpn[cnt++]='#';
            isnum=false;
        }
        if(str[i]=='('&&str[i+1]=='-')
           {

           }
        else if(str[i]==')')
        {
            if(isnum)
                rpn[cnt++]='#';
            while(stackop.op[stack.top-1]!='(')
            {
                rpn[cnt++]=stackop.op[stackop.top-1];
                stack.top--;
            }
            stackop.top--;
        }
        else if(GetLevel(str[i])<=GetLevel(stackop.op[stackop.top-1]))
        {
            while(GetLevel(str[i])<=GetLevel(stackop.op[stackop.top-1]))
            {
                rpn[cnt++]=stackop.op[stack.top-1];
                stackop.op[stackop.top++]=str[i];
            }
            else
                stackop.op[stackop.top++]=str[i];
        }
        while(stackop.top)
        {
            rpn[cnt++]=stackop.op[stackop.top-1];
            stackop.top--;
        }
        rpn[cnt]
    }
}


int GetLevel(char op)
{
    if(op=='+'||op=='-')
        return 1;
    if(op=='*'||op=='/')
        return 2;
    return 0;
}

int main()
{
    char str[maxn],*rpn;
    scanf("%s",str);
    rpn=GetRpn(str);
    printf("%s\n",rpn);

    return 0;
}
