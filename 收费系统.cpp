#include<stdio.h>
#include<string.h>
#include<stdio.h>
#include<time.h>
#include<windows.h>

int n=0,f;
float cout1,cout2,cout3;
char model[10][40]= {" ","����","����","С��"},q[10][50]= {"","���ͺ�����","��·������","����Ǯ����","��ʱ������"};
char m[10][100]={"","�������û�������ļ�(FILE)����������ÿ�ο���������Ҫ�����������ݡ�","�Դ˴����Ĳ��㾴���½�!"};
void Pos(short x,short y)//���ù��λ�ú���
{
    COORD pos;
    pos.X=x;
    pos.Y=y;
    HANDLE hOutput=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOutput,pos);
    return;
}//Pos


struct Node
{
    int size;//(1,2,3)�ֱ��Ӧ����(���У�С)���տ��ˣ��ף��ң�����
    float distance,price;
    long date;
} node[1000];



void write()
{
    Pos(20,2);
    printf("1.���ͣ�2.���ͣ�3.С��");
    Pos(20,5);
    printf("���ͺţ�");
    Pos(20,7);
    printf("·�̣�");
    Pos(20,9);
    printf("�۸�");
    Pos(30,5);
    scanf("%d",&node[n].size);
    while(node[n].size<=0||node[n].size>=4)
    {
        Pos(45,5);printf("����������������룡");
        Pos(30,5);printf("  ");
        Pos(30,5);scanf("%d",&node[n].size);
        Pos(40,5);printf("                          ");

    }
    Pos(33,5);
    printf("%s",model[node[n].size]);
    Pos(30,7);
    scanf("%f",&node[n].distance);
    Pos(35,7);
    printf("Km");
    node[n].price=(0.6-node[n].size*0.1)*node[n].distance;
    Pos(30,9);
    printf("%.2f Ԫ",node[n].price);

    //����ȡʱ��

    node[n].date = time((time_t*)NULL);
    struct tm *local;
    local=localtime(&node[n].date);
    Pos(16,11);
    printf("��ǰʱ��:  %d:%d:%d",local->tm_hour,local->tm_min,local->tm_sec);
    n++;
    Pos(30,13);printf("�������������");
    getchar();
    getchar();

}

//��ӡ
void Display(int x,int z)
{
    int cnt=x;
    while(cnt<z)
    {
        printf("���ͣ�%s\t",model[node[cnt].size]);
        printf("·�̣�%.2f km\t",node[cnt].distance);
        printf("�۸�%.2f Ԫ\t",node[cnt].price);
        struct tm *local2;
        local2=localtime(&node[cnt].date);
        printf("ʱ��: %d/%d/%d  %d:%d:%d\n",1900+local2->tm_year,local2->tm_mon+1, local2->tm_mday,local2->tm_hour,local2->tm_min,local2->tm_sec);
        cnt++;
    }
    printf("�������������");
    getchar();
    getchar();
}


//����
void Sort(int p)
{
    printf("\t\t\t\t%s\n\t",q[p]);
    if(n==0)
      {
           printf("�ڲ���ֵ\n");
        printf("�������������");
    getchar();
    getchar();
      }
    else if(n==1)
           Display(0,1);

    else
    {
        for(int i=0; i<n-1; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                switch(p)
                {
                case 1:
                    if(node[i].size>node[j].size)
                    {
                        struct Node tem=node[i];
                        node[i]=node[j];
                        node[j]=tem;
                    }
                    break;
                case 2:
                    if(node[i].distance<node[j].distance)
                    {
                        struct Node tem=node[i];
                        node[i]=node[j];
                        node[j]=tem;
                    }
                    break;
                case 3:
                    if(node[i].price<node[j].price)
                    {
                        struct Node tem=node[i];
                        node[i]=node[j];
                        node[j]=tem;
                    }
                    break;
                case 4:
                    if(node[i].date<node[j].date)
                    {
                        struct Node tem=node[i];
                        node[i]=node[j];
                        node[j]=tem;
                    }
                    break;

                }
            }
            Display(0,n);
        }

    }
}

void Sum()
{
    int cont=0;
    cout1=cout2=cout3=0;
    while(cont<n)
    {
        switch(node[cont].size)
        {
        case(1):
            cout1+=node[cont].price;
            break;
        case(2):
            cout2+=node[cont].price;
            break;
        case(3):
            cout3+=node[cont].price;
            break;
        }
        cont++;
    }
    printf("���ͳ�������: %.2f Ԫ\n���ͳ�������: %.2f Ԫ\nС�ͳ������룺%.2f Ԫ\n�����룺%.2f Ԫ\n",cout1,cout2,cout3,cout1+cout2+cout3);
    printf("�������������");
    getchar();
    getchar();

}
void moving(char *a)
{
    int n=strlen(a);
    for(int i=0; i<n; i++)
    {
        printf("%c",a[i]);
        Sleep(50);
    }
}
void image1()
{
    Pos(10,5);
    moving(m[1]);
    Pos(10,7);
    moving(m[2]);
    Pos(20,10);
    printf("�������������");
    getchar();
}
void image()
{
    printf("\n\n\n");
    printf("\t����������������������������������������������������������\t\n");
    printf("\t��                                                      ��\t\n");
    printf("\t��                     �����շ�ϵͳ                     ��\t\n");
    printf("\t��                                                      ��\t\n");
    printf("\t��                                                      ��\t\n");
    printf("\t��                     1.�����շ�                       ��\t\n");;
    printf("\t��                                                      ��\t\n");
    printf("\t��                     2.��������                       ��\t\n");
    printf("\t��                                                      ��\t\n");
    printf("\t��                     3.��������                       ��\t\n");
    printf("\t��                                                      ��\t\n");
    printf("\t��                     4.��ӡ��������                   ��\t\n");
    printf("\t��                                                      ��\t\n");
    printf("\t��                     0.�˳�����                       ��\t\n");
    printf("\t��                                                      ��\t\n");
    printf("\t����������������������������������������������������������\t\n");
    Pos(30,20);printf("������ѡ��");scanf("%d",&f);
}
int main()
{
     image1();
     system("cls");
    while(1)
    {
        int flag=0,p;
       image();
       system("cls");
       switch(f)
       {
           case 0:
           flag=1;
           break;
           case 1:
           write();
           break;
           case 2:
           printf("����������ķ�ʽ��1.�ͺţ�2.·�̣�3.�۸�4.ʱ��");
           Pos(30,1);printf("�����룺");scanf("%d",&p);
           system("cls");
           Sort(p);
           break;
           case 3:
           Sum();
           break;
           case 4:
           Display(0,n);
       }
       system("cls");
       if(flag==1)
       {
           printf("�������");
       break;
       }

    }




    return 0;
}
