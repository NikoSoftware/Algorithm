//This is a game source code developed by Yellowman.
//Copyright (C) 2013.
//Yellowman All Rights Reserved.

#include<stdio.h>
#include<windows.h>
#include<time.h>
#include<stdlib.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")


struct Body//��������ṹ��
{
	short x,y;//�����������
	struct Body *next;//ָ����һ������ָ��
};

////////////////////ȫ�ֱ���/////////////////////////////////////

int z=0,c,d;
int len=sizeof(struct Body);//Body�ṹ����ռ�ֽ���

int score;//��ҵ÷�

int Food=0;//1-��ʳ��,0-ûʳ��
short food_x,food_y;//ʳ������

struct Body *body001;//��ͷָ��

char difficu='1';//�Ѷȵĵ��ڲ���

int dir=4;//��ͷ����1-up,2-down,3-left,4-right

int sleeptime=220;//ÿ���ƶ�֮���ͣ��ʱ��

int color=1;//����ɫ1Ϊ��2Ϊ��

int back=1;//����ɫ1Ϊ��2Ϊ��

int fcolor=1;//ʳ����ɫ

int count=0;//����ʳ��ĸ���

int stepdiff=4;//ʳ����ʧ�Ѷ�

////////////////////////��������/////////////////////////////////////
void Pos(short x,short y);//��ͼ����
void CreatMap();//��ͼ����
void PrintSnake();//��ӡ��
void CreatFood();//����ʳ��
void SnakeMove();//���ƶ�
int TouchWall();//���ɴ�ǽ
//void CrossWall();//���Դ�ǽ
int TouchSelf();//�Ƿ�ҧ���Լ�
void Init();//��Ϸ��ʼ��
void GameCircle();//��Ϸѭ��
void Pause();//��ͣ
void StartImage();//��Ϸ��ʼ
void EndImage();//��Ϸ����
void SnokeBack();//��Ϸ����



////////////////////////��������/////////////////////////////////////
void Pos(short x,short y)//���ù��λ�ú���
{
	COORD pos;
	pos.X=x;
	pos.Y=y;
	HANDLE hOutput=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOutput,pos);
	return;
}//Pos

void CreatMap()//��ӡ��ͼ
{
	int i;
	for(i=0;i<57;i+=2)//��ӡ���±߿�
	{
		Pos(i,0);
		printf("��");
		Pos(i,24);
		printf("��");
	}
	for(i=1;i<=24;i++)//��ӡ���ұ߿�
	{
		Pos(0,i);
		printf("��");
		Pos(56,i);
		printf("��");
	}
	for(i=24;i<=36;i+=2)
	{
		Pos(i,10);
		printf("��");
		//Pos(i,15);
		//printf("��");
	}
	/*for(i=8;i<23;i++)
	{
		Pos(23,i);
		printf("��");
	}*/
	return;
}//CreatMap

void PrintSnake()//��ӡ��
{
	int a=0;
	struct Body *p=body001;//�ṹ��ָ�붨��
	while(p!=NULL)//�ж��Ƿ�ָ����β ��= ������
	{
		//int a,b;
		Pos(p->x,p->y);//�ṹ��ָ��
		if(a==0)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_GREEN);//������ɫ
			printf("��");//������Ե���ͷ��ɫ������״
		}
		else
		{
			if(color==1)
			  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_RED);//ע�������ɫ
			if(color==2)
			  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_BLUE);
			printf("��");
		}
		p=p->next;
		a++;
	}//����ͷ��ӡ����β
	if(fcolor==1)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_RED);//API��ɫ����
	}
	if(fcolor==2)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_BLUE);
	}
	for(a=1;a<=2;a++)
    {
	   Pos(food_x,food_y);
		printf("��");
		Sleep(sleeptime/4);//����˯�������ǵ�������) time ����
		Pos(food_x,food_y);
		printf(" ");
		Sleep(sleeptime/4);
    }
	    Pos(food_x,food_y);
		printf("��");
		count++;//����
		if(count==stepdiff*15)//ʧ����ʧʱ��
		{
			Pos(food_x,food_y);
			printf(" ");
			Food=0;
			count=0;
		}
		CreatFood();
	if(back==1)
		 system("color 0A");//������ɫ
	if(back==2)
		 system("color 5A");
	return;
}


void CreatFood()//������ʳ��
{
	if(Food==0)
	{
        z++;
		srand((int)time(0));
		food_x=2+rand()%53;//x��ȡֵ��Χ[2,54]
		if(food_x%2==1)
			food_x--;
		food_y=1+rand()%23;//y��ȡֵ��Χ[1,23]
		Food=1;//1������ʳ�0����ûʳ��
		 if(z%2==0)//����
		{
			if(sleeptime>=110)
				sleeptime-=10;
			Pos(62,5);printf("�ٶ�:      ");
			Pos(62,5);printf("�ٶ�:%d",20+300-sleeptime);
		}
	}
	return;
}//CreatFood

void SnakeMove()//�����ƶ���ˢ�������ʳ�Ｐ������
{
	struct Body *p_food;//��һ����ʳ��
	struct Body *p_forward;//��һ��ûʳ��
	struct Body *q;//�����ƶ�һ��ʱ����ʱָ��
	p_forward=(struct Body *)malloc(len);
	if(1==dir)//�����ƶ�
	{
		if(body001->x==food_x && body001->y-1==food_y)//��һ����ʳ��
		{
			p_food=(struct Body *)malloc(len);
			p_food->x=food_x;
			p_food->y=food_y;
			p_food->next=body001;
			body001=p_food;
			score+=5;
			Pos(62,3);printf("����:%d",score);
			Food=0;
			CreatFood();
			Pos(62,7);printf("ʳ������:        ");
			Pos(62,7);printf("ʳ������:%u,%u",food_x,food_y);
		}
		else if(body001->x==c&&body001->y-1==d)
	    {
	       score+=10;
	       Pos(62,3);printf("����:%d",score);
	       Pos(c,d);printf(" ");

	       Pos(23,5);printf("��ϲ������10��");
	       Sleep(sleeptime*10);
           Pos(23,5);printf("              ");

	       p_forward->x=body001->x;//�����겻��
			p_forward->y=body001->y-1;//������-1
			p_forward->next=body001;
			body001=p_forward;
			q=body001;
			while((q->next)->next!=NULL)//ʹqָ�����ڶ������
				q=q->next;
			Pos((q->next)->x,(q->next)->y);//�ƶ���굽��β
			printf(" ");//ɾ����β
			free(q->next); //�ͷ���β
			q->next=NULL;//ʹ�����ڶ�������Ϊ�µ���β
			c=0;d=0;




	    }
		else//��һ��û��ʳ��
		{
			p_forward->x=body001->x;//�����겻��
			p_forward->y=body001->y-1;//������-1
			p_forward->next=body001;
			body001=p_forward;
			q=body001;
			while((q->next)->next!=NULL)//ʹqָ�����ڶ������
				q=q->next;
			Pos((q->next)->x,(q->next)->y);//�ƶ���굽��β
			printf(" ");//ɾ����β
			free(q->next); //�ͷ���β
			q->next=NULL;//ʹ�����ڶ�������Ϊ�µ���β

		}//else
	}

	if(2==dir)//�����ƶ�
	{

		if(body001->x==food_x && body001->y+1==food_y)//��һ����ʳ��
		{
			p_food=(struct Body *)malloc(len);
			p_food->x=food_x;
			p_food->y=food_y;
			p_food->next=body001;
			body001=p_food;
			score+=5;
			Pos(62,3);printf("����:%d",score);
			Food=0;
			CreatFood();
			Pos(62,7);printf("ʳ������:        ");
			Pos(62,7);printf("ʳ������:%u,%u",food_x,food_y);
		}
		else if(body001->x==c&&body001->y+1==d)
	    {
	       score+=10;
	       Pos(62,3);printf("����:%d",score);
	       Pos(c,d);printf(" ");

	       Pos(23,5);printf("��ϲ������10��");
	       Sleep(sleeptime*10);
           Pos(23,5);printf("              ");

	       p_forward->x=body001->x;//�����겻��
			p_forward->y=body001->y+1;//������+1
			p_forward->next=body001;
			body001=p_forward;
			q=body001;
			while((q->next)->next!=NULL)//ʹqָ�����ڶ������
				q=q->next;
			Pos((q->next)->x,(q->next)->y);//�ƶ���굽��β
			printf(" ");//ɾ����β
			free(q->next); //�ͷ���β
			q->next=NULL;//ʹ�����ڶ�������Ϊ�µ���β
			c=0;d=0;

	    }
		else//��һ��û��ʳ��
		{
			p_forward->x=body001->x;//�����겻��
			p_forward->y=body001->y+1;//������+1
			p_forward->next=body001;
			body001=p_forward;
			q=body001;
			while((q->next)->next!=NULL)//ʹqָ�����ڶ������
				q=q->next;
			Pos((q->next)->x,(q->next)->y);//�ƶ���굽��β
			printf(" ");//ɾ����β
			free(q->next); //�ͷ���β
			q->next=NULL;//ʹ�����ڶ�������Ϊ�µ���β
		}//else
	}

	if(3==dir)//�����ƶ�
	{
		if(body001->x-2==food_x && body001->y==food_y)//��һ����ʳ��
		{
			p_food=(struct Body *)malloc(len);
			p_food->x=food_x;
			p_food->y=food_y;
			p_food->next=body001;
			body001=p_food;
			score+=10;
			Pos(62,3);printf("����:%d",score);
			Food=0;
			CreatFood();
			Pos(62,7);printf("ʳ������:        ");
			Pos(62,7);printf("ʳ������:%u,%u",food_x,food_y);
		}
		else if(body001->x-2==c&&body001->y==d)
	    {
	       score+=5;
	       Pos(62,3);printf("����:%d",score);
	       Pos(c,d);printf(" ");

	       Pos(23,5);printf("��ϲ������10��");
	       Sleep(sleeptime*10);
           Pos(23,5);printf("              ");

	       p_forward->x=body001->x-2;//������-2
			p_forward->y=body001->y;//�����겻��
			p_forward->next=body001;
			body001=p_forward;
			q=body001;
			while((q->next)->next!=NULL)//ʹqָ�����ڶ������
				q=q->next;
			Pos((q->next)->x,(q->next)->y);//�ƶ���굽��β
			printf(" ");//ɾ����β
			free(q->next); //�ͷ���β
			q->next=NULL;//ʹ�����ڶ�������Ϊ�µ���β
			c=0;d=0;

	    }
		else//��һ��û��ʳ��
		{
			p_forward->x=body001->x-2;//������-2
			p_forward->y=body001->y;//�����겻��
			p_forward->next=body001;
			body001=p_forward;
			q=body001;
			while((q->next)->next!=NULL)//ʹqָ�����ڶ������
				q=q->next;
			Pos((q->next)->x,(q->next)->y);//�ƶ���굽��β
			printf(" ");//ɾ����β
			free(q->next); //�ͷ���β
			q->next=NULL;//ʹ�����ڶ�������Ϊ�µ���β
		}//else
	}

	if(4==dir)//�����ƶ�
	{
		if(body001->x+2==food_x && body001->y==food_y)//��һ����ʳ��
		{
			p_food=(struct Body *)malloc(len);
			p_food->x=food_x;
			p_food->y=food_y;
			p_food->next=body001;
			body001=p_food;
			score+=10;
			Food=0;
			Pos(62,3);printf("����:%d",score);
			CreatFood();
			Pos(62,7);printf("ʳ������:        ");
			Pos(62,7);printf("ʳ������:%u,%u",food_x,food_y);
		}
		else if(body001->x+2==c&&body001->y==d)
	    {
	       score+=12;
	       Pos(62,3);printf("����:%d",score);
	       Pos(c,d);printf(" ");

	       Pos(23,5);printf("��ϲ������10��");
	       Sleep(sleeptime*10);
           Pos(23,5);printf("              ");

	       p_forward->x=body001->x+2;//������=2
			p_forward->y=body001->y;//�����겻��
			p_forward->next=body001;
			body001=p_forward;
			q=body001;
			while((q->next)->next!=NULL)//ʹqָ�����ڶ������
				q=q->next;
			Pos((q->next)->x,(q->next)->y);//�ƶ���굽��β
			printf(" ");//ɾ����β
			free(q->next); //�ͷ���β
			q->next=NULL;//ʹ�����ڶ�������Ϊ�µ���β
			c=0;d=0;

	    }
		else//��һ��û��ʳ��
		{
			p_forward->x=body001->x+2;//������=2
			p_forward->y=body001->y;//�����겻��
			p_forward->next=body001;
			body001=p_forward;
			q=body001;
			while((q->next)->next!=NULL)//ʹqָ�����ڶ������
				q=q->next;
			Pos((q->next)->x,(q->next)->y);//�ƶ���굽��β
			printf(" ");//ɾ����β
			free(q->next); //�ͷ���β
			q->next=NULL;//ʹ�����ڶ�������Ϊ�µ���β
		}//else
	}
	Pos(62,9);printf("��ͷ����:        ");
	Pos(62,22);printf("ʳ������%d",z);
	Pos(62,9);printf("��ͷ����:%u,%u",body001->x,body001->y);//��ӡ��ͷ����
	if(z%3==0)
	{
	    Pos(food_x+2,food_y);printf("��");
	    c=food_x+2,d=food_y;
	    Pos(62,23);printf("%d,%d",c,d);


	}
	else
	Pos(food_x,food_y);printf("��");//��ӡʳ��
	PrintSnake();//��ӡ��
}//SnakeMove


int TouchWall()//���ɴ�ǽ
{
	if(body001->x==0 || body001->x==56 || body001->y==0 || body001->y==24)
		return 1;

		//else if(body001->x==23 && body001->y>=8 && body001->y<=23 )
		//return 1;

		else if(body001->x>=23 && body001->x<=36 && body001->y==10)
		return 1;

		//else if(body001->x>=23 && body001->x<=36 && body001->y==15)
		//return 1;
			else
		return 0;
}//TouchWall

/*void CrossWall()//���Դ�ǽ
{
	if(0==body001->x)//����ҳ�
	{
		body001->x=54;
		if(food_x==body001->x && food_y==body001->y)
			food_x-=2;
	}
	if(56==body001->x)//�ҽ����
	{
		body001->x=2;
		if(food_x==body001->x && food_y==body001->y)
			food_x+=2;
	}
	if(0==body001->y)//�Ͻ��³�
	{
		body001->y=23;
		if(food_x==body001->x && food_y==body001->y)
			food_y--;
	}
	if(24==body001->y)//�½��ϳ�
	{
		body001->y=1;
		if(food_x==body001->x && food_y==body001->y)
			food_y++;
	}
	return;
}*/

int TouchSelf()//�ж��Ƿ�ҧ���Լ�
{
	struct Body *p_tself;
	p_tself=body001;
	while(!p_tself->next==NULL)
	{
		p_tself=p_tself->next;
		if(p_tself->x==body001->x && p_tself->y==body001->y)
			return 1;
	}
	return 0;
}//TouchSelf

void Init()//��Ϸ��ʼ��
{
	CreatMap();//��ӡ��ͼ

	Pos(62,3);printf("����:%d",score);
	Pos(62,5);printf("�ٶ�:      ");
	Pos(62,5);printf("�ٶ�:%d",20+300-sleeptime);
	Pos(62,13);printf("F1 ����");
	Pos(62,15);printf("F2 ����");
	Pos(62,17);printf("�� �� �� ������");
	Pos(62,19);printf("SPACE ��ͣ/��ʼ");
	Pos(62,21);printf("ESC �˳�");

	struct Body *body002,*body003,*body004;//�����ĸ�ָ�������ָ��

	body001=(struct Body *)malloc(len);//����4������ṹ��
	body002=(struct Body *)malloc(len);
	body003=(struct Body *)malloc(len);
	body004=(struct Body *)malloc(len);

	body001->next=body002;//�����������������γ�����
	body002->next=body003;
	body003->next=body004;
	body004->next=NULL;

	Pos(body001->x=8,body001->y=8);printf("��");//�趨����ӡ����ĳ�ʼλ��
	Pos(body002->x=6,body002->y=8);printf("��");
	Pos(body003->x=4,body003->y=8);printf("��");
	Pos(body004->x=2,body004->y=8);printf("��");

    CreatFood();//��ӡʳ��
	Pos(62,7);printf("ʳ������:        ");
	Pos(62,7);printf("ʳ������:%u,%u",food_x,food_y);
}//Init

void Pause()
{
	while(1)
	{
		Sleep(220);
		if(GetAsyncKeyState(VK_SPACE))
			break;
	}
	return;
}//Pause

void GameCircle()//��Ϸѭ��
{
	while(1)
	{
		if (1== TouchWall() )//���ɴ�ǽ
		break;//ײǽGame Over

		//CrossWall();//���Դ�ǽ

		if(1== TouchSelf() )//�ж����Ƿ�ҧ���Լ�
			break;//ҧ���Լ�Game Over

		//�ж��û��İ�������
//		int dir=4;
		if(GetAsyncKeyState(VK_UP) && dir!=2)
			dir=1;
		else if(GetAsyncKeyState(VK_DOWN) && dir!=1)
			dir=2;
		else if(GetAsyncKeyState(VK_LEFT) && dir!=4)
			dir=3;
		else if(GetAsyncKeyState(VK_RIGHT) && dir!=3)
			dir=4;
		else if(GetAsyncKeyState(VK_ESCAPE))
			break;
		else if(GetAsyncKeyState(VK_SPACE))
			Pause();
		else if(GetAsyncKeyState(VK_F1))//����
		{
			if(sleeptime>=110)
				sleeptime-=10;
			Pos(62,5);printf("�ٶ�:      ");
			Pos(62,5);printf("�ٶ�:%d",20+300-sleeptime);
		}
		else if(GetAsyncKeyState(VK_F2))//����
		{
			if(sleeptime<=290)
				sleeptime+=10;
			Pos(62,5);printf("�ٶ�:      ");
			Pos(62,5);printf("�ٶ�:%d",20+300-sleeptime);
		}

		SnakeMove();//���ƶ�һ��

		//�趨�����ƶ�֮���ʱ����
	}//while
}//GameCircle

void StartImage()
{
	Pos(25,6);printf("\^.^��������������������~~~");
	Pos(32,11);printf("̰����1.0");
	Pos(21,23);printf("2013.Yellowman All Rights Reserved.");
	Pos(28,13);
	system("pause");
	system("cls");

	    Pos(15,5);printf("������������ʦ�ṩ̰���߸ı����");
    Pos(15,7);printf("�����ɫ�ʡ�ʳ��������ʱ�����ɱ�С�鲿�ֳ�Ա���");
    Pos(13,10);printf("���˸ı��У�");
    Pos(15,12);printf("��Ϊ�������");
    Pos(15,13);printf("���������ÿ��������ʳ��,̰���߼���10");
    Pos(15,14);printf("��ÿ��ʧ3��ʳ����֣��������һ��ʱ����ʳ�������ǿɼӷ�10\n");
    Pos(26,18);
    	int a,b=2014,i=28,j=19;
    while(1)
	{
	    printf("���������룺\n");
	    Pos(i,j++);scanf("%d",&a);
	    if(a==b)
	    break;
	    Pos(i,j++);printf("�������");
	}
	Pos(28,j);
    system("pause");
	system("cls");

    Pos(25,11);printf("̰�ԵĹ����в�Ҫҧ���Լ�Ŷ~");
	Pos(21,23);printf("2013.Yellowman All Rights Reserved.");
    Pos(25,13);

	system("pause");
	system("cls");
}//StartImage

void EndImage()
{
	system("cls");
	Pos(30,9);printf("Game Over!!!  ");
	Pos(30,11);printf("��ĵ÷֣�%d",score);
	Pos(20,23);printf("2013.Yellowman All Rights Reserved.");
	Pos(28,13);
	system("pause");
}//EndImage


/////////////////////////main����////////////////////////////////////////
int main(void)
{
	StartImage();//��ʼ����

	Init();//�����ʼ��

	GameCircle();//��Ϸѭ��

	EndImage();//��������

	return 0;
}//main
//This is the end of source code.

