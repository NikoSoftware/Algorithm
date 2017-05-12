#include<stdio.h>
#include<string.h>
struct question
{
    char str[10000];
}a[10]={{"第一题：你是不是叫王X？y 是，n 不是。"},{"第二题：你有没有喜欢的男生？ y 有，n 没有。"},
{"第三题：他是不是叫XX？y 是，n 不是。"},{"第四题：他爱你，你爱不爱他？ y 爱，n 不爱。"},
{"第五题：他知道你爱他，所以想让你成为他的女人，永远爱你，保护你，你愿意吗？\ny 愿意，n不愿意。"}};
int main()
{
    struct question;
    int i=0;
     char n,m,e,j,z,ch,c[100];
    printf("******************************************************\n");
    printf("**  欢迎我的女神参加本次测试                        **\n**  方法是：通过按下'y','n' 来回答问题，然后回车键！**\n**  OK,开始测试！                                   **\n");
    printf("******************************************************\n\n");
    printf("o<^-^>o亲，按ENTER键开始测试之旅吧!\n");
    getchar();
    printf("第一题：你是不是叫XX？y 是，n 不是。\n");
        while(1)
       {
           scanf("%c",&n);
          if(n=='y')
          {
              printf("亲，你的回答正确哦，进入下一题吧!\n");
              i++;
              if(i==5)
              break;
              getchar();
              getchar();
              printf("%s\n",a[i].str);
          }
          else if(n=='n')
          printf("不好意思回答错误，请再次回答！\n");
       }
       getchar();
       getchar();
       printf("\n\n女神你好棒哦！全都答对了呀！\n他会照顾你一辈子哦！\n\n");
       getchar();
       getchar();
       printf("    ***  ***                          ***  ***         \n");
       printf("  ************~~ @              @ ~~************       \n");
       printf("   **********    ~~ @         @ ~~   **********        \n");
       printf("    ********       ~~ @    @ ~~       ********         \n");
       printf("      ****            ~~ ~~             ****           \n");
       getchar();
       getchar();
       printf("此软件由陈中勤制作\n");
       gets(c);



}


