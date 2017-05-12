#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    FILE *fp;
    int m1=10,m2=100,M1,M2;
    //char data[100]= {"我喜欢你","C语言"},str[1000];
    //scanf("%s",data);
    if((fp=fopen("date.txt","wb+"))==NULL)
    {
        printf("无法打开此文件\n");
        exit(0);
    }
    //fwrite(data,sizeof(char),strlen(data),fp);
    fprintf(fp,"%d,%d",m1,m2);


    fclose(fp);
    printf("已读入文件\n");

    if((fp=fopen("date.txt","r"))==NULL)
    {
        printf("无法打开此文件\n");
        exit(0);
    }
    /*if(fgets(str,20,fp)==NULL)
    {
        printf("fdadsa");
        exit(0);
    }
    printf("%s",str);*/
    fscanf(fp,"%d,%d",&M1,&M2);
    printf("%d,%d",M1,M2);
    fclose(fp);

    return 0;
}
