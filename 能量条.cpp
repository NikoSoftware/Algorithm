#include<stdio.h>
#include<windows.h>
//#include<time.h>

void image(int n)
{
    int i,j;
    float k;
    printf("\n\n\n\n");
    printf("\t\t\t\t�����������ء���\n");
        printf("\t����������������������������������������������������������\t\n");
        printf("\t��");
        for(i=0;i<n;i++)
        {
            printf("��");
        }
        printf(" %.lf%c",n*1.0/28*100,'%');
        printf("\n");
        printf("\t����������������������������������������������������������\t\n");

}
int main()
{
    int i;
    for(i=1;i<28;i++)
    {
        image(i);
        Sleep(1000);
        system("cls");
    }
    image(28);
    return 0;
}
