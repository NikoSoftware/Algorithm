#include<stdio.h>
#include<string.h>
void tou()
{
    printf("********************");
    printf("欢迎我的女神参加本次测试\n方法是：通过按下'y','n' 来回答问题，然后回车键！\nOK,开始测试！");
    printf("********************");
    printf("o<^-^>o亲，按ENTER键开始测试之旅吧!\n\n");
}
int main()
{
    char n,m,i,e,j,z,ch;
    printf("***********************************************\n");
    printf("欢迎我的女神参加本次测试\n方法是：通过按下'y','n' 来回答问题，然后回车键！\nOK,开始测试！\n");
    printf("***********************************************\n\n");
    printf("o<^-^>o亲，按ENTER键开始测试之旅吧!\n\n\n");
    printf("第一题：你是不是性刘？y 是，n 不是。\n");
   while(n=getchar())
    {
        if(n=='y')
    printf("亲，你的回答正确哦，进入下一题吧！\n");
        if(n=='n')
    printf("不好意思回答错误，请再次回答吧！\n");
    printf("第二题：你有没有喜欢的男生？ y 有，n 没有。\n\n");
    while(scanf("%c",&m)!='y')
    {
        if(m=='y')
     printf("亲，你的回答正确哦，进入下一题吧！\n");
        if(m=='n')
     printf("不好意思回答错误，请再次回答吧！\n");
    }
    printf("第三题：他是不是叫XX？y 是，n 不是。\n");
    while( scanf("%c",&i)!='y')
    {
        if(i=='y')
    printf("亲，你的回答正确哦，进入下一题吧！\n");
        if(i=='n')
    printf("不好意思回答错误，请再次回答吧！\n");
    }
    printf("第四题：他爱你，你爱不爱他？ y 爱，n 不爱。\n");
    while(scanf("%c",&e)!='y')
        {
            if(e=='y')
    printf("亲，你的回答正确哦，进入下一题吧！\n");
        if(e=='n')
    printf("不好意思回答错误，请再次回答吧！\n");
        }
    printf("第五题：他知道你爱他，所以想让你成为他的女人，永远爱你，保护你，你愿意吗？\ny 愿意，n不愿意。\n");
        while( scanf("%c",&j)!='y')
    {
        if(j=='y')
    printf("\n\n女神你好棒哦！全都答对了呀！\n他会照顾你一辈子哦！\n");
        if(j=='n')
    printf("不好意思回答错误，请再次回答吧！\n");
    }
}
}
