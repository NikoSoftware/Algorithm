#include<cstdio>
#include<cstring>
#include<math.h>
#define maxn 10000
struct StackOp
{
    char op[maxn];
    int top;
} stackop;
struct StackNum
{
    double num[maxn];
    int top;
} stacknum;
int GetLevel(char op)
{
    if(op=='+'||op=='-')
        return 1;
    if(op=='*'||op=='/')
        return 2;
    return 0;
}
void GetRpn(char *str,char *rpn)
{
    int len=strlen(str),cnt=0;
    bool isnum=false;
    stackop.top=0;
    if(str[len-1]=='=')
        len--;
    if(str[0]=='-')
    {
        rpn[cnt++]='0';
        rpn[cnt++]='#';
    }
    for(int i=0; i<len; i++)
    {
        if(str[i]>='0'&&str[i]<='9'||str[i]=='.')
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
            rpn[cnt++]='0';
            rpn[cnt++]='#';
        }
        if(str[i]=='(')
            stackop.op[stackop.top++]=str[i];
        else if(str[i]==')')
        {
            while(stackop.op[stackop.top-1]!='(')
            {
                rpn[cnt++]=stackop.op[stackop.top-1];
                stackop.top--;
            }
            stackop.top--;
        }
        else if(stackop.top&&GetLevel(str[i])<=GetLevel(stackop.op[stackop.top-1]))
        {
            while(stackop.top&&GetLevel(str[i])<=GetLevel(stackop.op[stackop.top-1]))
            {
                rpn[cnt++]=stackop.op[stackop.top-1];
                stackop.top--;
            }
            stackop.op[stackop.top++]=str[i];
        }
        else
            stackop.op[stackop.top++]=str[i];
    }
    if(isnum)
        rpn[cnt++]='#';
    while(stackop.top)
    {
        rpn[cnt++]=stackop.op[stackop.top-1];
        stackop.top--;
    }
    rpn[cnt]='\0';
}
double Add(double a,double b)
{
    return a+b;
}
double Sub(double a,double b)
{
    return a-b;
}
double Multi(double a,double b)
{
    return a*b;
}
double Div(double a,double b)
{
    return a/b;
}
double GetAns(char *rpn)
{
    int j=0,len=strlen(rpn),flag=0;
    stacknum.top=0;
    for(int i=0; i<len; i++)
    {
        if(rpn[i]>='0'&&rpn[i]<='9')
        {
            double num=0;
            while(rpn[i]!='#')
            {
                if(rpn[i]=='.')
                {
                    flag=1;
                    j=0;
                    i++;
                    continue;
                }
                if(flag==0)
                    num=num*10+rpn[i++]-'0';
                if(flag)
                {
                    j++;
                    num=num+(rpn[i++]-'0')*pow(0.1,j);
                }
            }
            flag=0;
            j=0;
            stacknum.num[stacknum.top++]=num;
        }
        else
        {
            double ans;
            double b=stacknum.num[stacknum.top-1];
            stacknum.top--;
            double a=stacknum.num[stacknum.top-1];
            stacknum.top--;
            switch(rpn[i])
            {
            case '+':
                ans=Add(a,b);
                break;
            case '-':
                ans=Sub(a,b);
                break;
            case '*':
                ans=Multi(a,b);
                break;
            case '/':
                ans=Div(a,b);
                break;
            }
            stacknum.num[stacknum.top++]=ans;
        }
    }
    return stacknum.num[0];
}
int main()
{
    int i,n;
    char rpn[maxn],str[maxn];
    while(scanf("%d",&n)!=EOF)
    {
        for(i=1; i<=n; i++)
        {
            scanf("%s",str);
            GetRpn(str,rpn);
            printf("Case #%d: %.2lf\n",i,GetAns(rpn));
        }

    }
    return 0;
}





