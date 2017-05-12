/* ****************************************************
 * **           ѧ����Ϣ����ϵͳԴ�������           **
 * ****************************************************
 * **         �汾��v1.0.0                           **
 * **         Copyright (c) 2014 FeoniX��            **
 * ****************************************************
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dos.h>
#include <conio.h>
#include <time.h>
#define N 50                 //ѧ����¼�������
#define MaxPwdLen 20         //������󳤶�

struct student               //ѧ����¼�ṹ�嶨��
{
	int no;
	char name[20];
	char sex;
	int score[3];
	int sum;
	float average;
};

//��������
void SaveStu(struct student stu[], int count, int flag);  //�������ݣ�д���ļ�
void LoadStu(struct student stu[], int * stu_number);     //��ȡ�ļ�����
void PassWord();                                        //������֤
void Menu();                                            //��ʾ���˵�
void InputStu(struct student stu[], int * stu_number);    //����ѧ����¼
void BrowseStu(struct student stu[], int * stu_number);   //���ѧ����¼
void SortStu(struct student stu[], int * stu_number);     //����ѧ����¼
void SearchStu(struct student stu[], int * stu_number);   //����ѧ����¼
void DeleteStu(struct student stu[], int * stu_number);   //ɾ��ѧ����¼
void ModifyStu(struct student stu[], int * stu_number);   //�޸�ѧ����¼
void CountScore(struct student stu[], int * stu_number);  //ͳ��ѧ����¼

void Create()
{
	FILE * fp;
	fp = fopen("Data\\first.txt" , "r");

	if (fp == NULL)
	{
		system("notepad Readme.txt");
		system("echo 1>Data\\first.txt");
	}

	else
	{
		fclose(fp);
	}
}

void SaveStu(struct student stu[], int count, int flag)
{
	FILE * fp;
	int i;

	if ((fp = flag ? fopen("Data\\data.dat", "ab") : fopen("Data\\data.dat", "wb")) == NULL)
	{
		printf("���ܴ���\n");
		return;
	}

	for (i = 0; i < count; i++)
		if (fwrite(&stu[i], sizeof(struct student), 1, fp) != 1)
		{
			printf("�ļ�д����\n");
		}

	fclose(fp);
}

void LoadStu(struct student stu[], int * stu_number)
{
	FILE * fp;
	int i = 0;

	if ((fp = fopen("Data\\data.dat", "rb")) == NULL)
	{
		printf("���ܴ��ļ�\n");
		return;
	}

	while (fread(&stu[i], sizeof(struct student), 1, fp) == 1 && i < N)
	{
		i++;
	}

	*stu_number = i;                  //����ѧ����¼����

	if (feof(fp))
	{
		fclose(fp);
	}
	else
	{
		printf("�ļ�������\n");
		fclose(fp);
	}

	return;
}

void PassWord(void)
{
	char passwd[MaxPwdLen + 1] = "", initpwd[MaxPwdLen + 1] = "123456";
	int i, j;
	char c;
	time_t start, end;
	system("title ��¼");
	system("cls");

	for (i = 3; i >= 1; i--)
	{
		j = 0;
		printf("\n\n\n\n\t\t ����������(�㻹��%d�λ���):", i);

		while ((c = getch()) != '\r')
		{
			if (j < MaxPwdLen && isprint(c))
			{
				//sprint()�����޶�ֻ���տ���ʾ�ַ�
				passwd[j++] = c;
				putchar('*');
			}
			else
				if (j > 0 && c == '\b')
				{
					j--;
					putchar('\b');
					putchar(' ');
					putchar('\b');
				}
		}

		putchar('\n');
		passwd[j] = '\0';                        //����ַ���������־

		if (strcmp(passwd, initpwd) == 0)
		{
			system("cls");
			system("title ��ӭҳ��");
			printf("\n\n\n\n");
			printf("\t\t-----------------------------------------\n");
			printf("\t\t*                                       *\n");
			printf("\t\t*        ��ӭʹ��ѧ����Ϣ����ϵͳ       *\n");
			printf("\t\t*                                       *\n");
			printf("\t\t-----------------------------------------\n\n\t\t");
			start = time(NULL);            //��ʱ2�����ִ��
			end = time(NULL);

			while (end - start < 2)
			{
				end = time(NULL);
			}

			break;
		}
		else
			if (i > 1)
			{
				system("cls");
				printf("\n\t\t �������!����������!\n");
				continue;
			}
	}

	if (i == 0)
	{
		system("cls");
		printf("\n\n\t\t �Բ���!����Ȩʹ�ø�ϵͳ!\n\n\t\t");
		start = time(NULL);
		end = time(NULL);

		while (end - start < 2)
		{
			end = time(NULL);
		}

		exit(0);
	}

	return;
}

void Menu()
{
	printf("\n\n\n\n\t\t Loading...");
	Sleep(2000);
	system("cls");
	system("title ���˵�");
	printf("\n\n");
	printf("\t\t|-----------------------------------|\n");
	printf("\t\t|         ѧ����Ϣ����ϵͳ          |\n");
	printf("\t\t|-----------------------------------|\n");
	printf("\t\t|         1---����ѧ����¼          |\n");
	printf("\t\t|         2---���ѧ����¼          |\n");
	printf("\t\t|         3---��ѯѧ����¼          |\n");
	printf("\t\t|         4---����ѧ����¼          |\n");
	printf("\t\t|         5---ɾ��ѧ����¼          |\n");
	printf("\t\t|         6---�޸�ѧ����¼          |\n");
	printf("\t\t|         7---ͳ��ѧ����¼          |\n");
	printf("\t\t|         0---�˳�ϵͳ              |\n");
	printf("\t\t|-----------------------------------|\n");
}

void InputStu(struct student stu[], int * stu_number)
{
	char ch = 'y';
	int i, count = 0;
	LoadStu(stu, stu_number);
	system("title ����ѧ����¼");

	while ((ch == 'y') || (ch == 'Y'))
	{
		system("cls");
		printf("\n\t\t--------------------����ѧ����¼------------------\n");
		printf("\n\n\t\t ������ѧ����Ϣ\n");
		printf("\n\t\t     ѧ�ţ�");
		scanf("%d", &stu[count].no);

		for (i = 0; i < *stu_number; i++)
			if (stu[count].no == stu[i].no)
			{
				printf("\n\t\t ��ѧ����ʹ�ã������䣺\n");
				printf("\n\t\t     ѧ�ţ�");
				scanf("%d", &stu[count].no);
			}

		printf("\n\t\t     ������");
		scanf("%s", &stu[count].name);
		printf("\n\t\t     �Ա�");
		scanf("\n%c", &stu[count].sex);
		printf("\n\t\t ���ĳɼ���");
		scanf("%3d", &stu[count].score[0]);
		printf("\n\t\t ��ѧ�ɼ���");
		scanf("%3d", &stu[count].score[1]);
		printf("\n\t\t Ӣ��ɼ���");
		scanf("%3d", &stu[count].score[2]);
		stu[count].sum = stu[count].score[0] + stu[count].score[1] + stu[count].score[2];
		stu[count].average = (float)stu[count].sum / 3.0;
		printf("\n\n\t\t �Ƿ�������һ��ѧ����Ϣ?(y/n)");
		scanf("\n%c", &ch);
		count++;
	}

	*stu_number = *stu_number + count;
	SaveStu(stu, count, 1);             //����1��ʾ��׷�ӷ�ʽд���ļ�
	return;
}

void BrowseStu(struct student stu[], int * stu_number)
{
	int i, j, choose;
	struct student temp_stu[N], st;
	LoadStu(stu, stu_number);
	system("title ���ѧ����¼");

	while (1)
	{
		system("cls");
		printf("\n");
		printf("\t|---------------------------------------------------------------|\n");
		printf("\t|                       ���ѧ����¼�Ӳ˵�                      |\n");
		printf("\t|---------------------------------------------------------------|\n");
		printf("\t|                       1---��ѧ��˳�����                      |\n");
		printf("\t|                       2---������˳�����                      |\n");
		printf("\t|                       0---�������˵�                          |\n");
		printf("\t|---------------------------------------------------------------|\n");
		printf("\t    ��ѡ�������ʽ��");
		scanf("%d", &choose);

		switch (choose)
		{
			case 1:
				system("cls");
				printf("\n\n\t  ��ѧ������������£�\n");
				printf("\n\t ѧ��\t �� ��\t �Ա�\t����\t��ѧ\tӢ��\t�� ��\tƽ �� ��\n\n");

				for (i = 0; i < *stu_number; i++)
				{
					printf("\t %d\t %s\t  %c\t %d\t %d\t %d\t %d\t %.2f\n\n", stu[i].no, stu[i].name, stu[i].sex, stu[i].score[0], stu[i].score[1], stu[i].score[2], stu[i].sum, stu[i].average);
				}

				printf("\n\t\t �����ϣ�������������Ӳ˵�!");
				getch();
				break;

			case 2:
				for (i = 0; i < *stu_number; i++)
				{
					temp_stu[i] = stu[i];
				}

				for (i = 1; i < *stu_number; i++)
					for (j = 1; j <= *stu_number - i; j++)
						if (temp_stu[j - 1].sum < temp_stu[j].sum)
						{
							st = temp_stu[j - 1];
							temp_stu[j - 1] = temp_stu[j];
							temp_stu[j] = st;
						}

				system("cls");
				printf("\n\n\t  ����������������£�\n");
				printf("\n\t����\tѧ��\t��  ��\t�Ա�\t����\t��ѧ\tӢ��\t�� ��\tƽ �� ��\n");

				for (i = 0; i < *stu_number; i++)
				{
					printf("\t %d\t%d\t%s\t %c\t %d\t %d\t %d\t %d\t %.2f\n\n", i + 1, temp_stu[i].no, temp_stu[i].name, temp_stu[i].sex, temp_stu[i].score[0], temp_stu[i].score[1], temp_stu[i].score[2], temp_stu[i].sum, temp_stu[i].average);
				}

				printf("\n\t\t �����ϣ�������������Ӳ˵�!");
				getch();
				break;

			case 0:
				return;
		}
	}

	return;
}

void SortStu(struct student stu[], int * stu_number)
{
	int i, j;
	struct student st;
	LoadStu(stu, stu_number);
	system("title ����ѧ����¼");

	for (i = 1; i < *stu_number; i++)
		for (j = 1; j <= *stu_number - i; j++)
			if (stu[j - 1].no > stu[j].no)
			{
				st = stu[j - 1];
				stu[j - 1] = stu[j];
				stu[j] = st;
			}

	system("cls");
	printf("\n\n\t\t********************����ѧ����¼********************\n");
	printf("\n\n\t  ��ѧ������������ѧ����¼���£�\n");
	printf("\n\t ѧ��\t��  ��\t�Ա�\t����\t��ѧ\tӢ��\t�� ��\tƽ �� ��\n\n");

	for (i = 0; i < *stu_number; i++)
	{
		printf("\t %d\t%s\t %c\t %d\t %d\t %d\t %d\t %.2f\n\n", stu[i].no, stu[i].name, stu[i].sex, stu[i].score[0], stu[i].score[1], stu[i].score[2], stu[i].sum, stu[i].average);
	}

	printf("\n\t\t ������ϣ���������������˵�!");
	getch();
	SaveStu(stu, *stu_number, 0);
	return;
}

void SearchStu(struct student stu[], int * stu_number)
{
	int xh, i, num, choose, find;
	char ch, xm[20];

	LoadStu(stu, stu_number);
	system("title ��ѯѧ����¼");

	while (1)
	{
		system("cls");
		printf("\n");
		printf("\t|---------------------------------------------------------------|\n");
		printf("\t|                       ��ѯѧ����¼�Ӳ˵�                      |\n");
		printf("\t|---------------------------------------------------------------|\n");
		printf("\t|                         1---��ѧ�Ų�ѯ                        |\n");
		printf("\t|                         2---��������ѯ                        |\n");
		printf("\t|                         0---�������˵�                        |\n");
		printf("\t|---------------------------------------------------------------|\n");
		printf("\t    ��ѡ���ѯ��ʽ��");
		scanf("%d", &choose);

		switch (choose)
		{
			case 1:
				printf("\n\t ������Ҫ��ѯ��ѧ��ѧ�ţ�");
				scanf("%d", &xh);

				for (i = 0; i < *stu_number; i++)
					if (stu[i].no == xh)
					{
						printf("\n\t Ҫ��ѯ��ѧ����Ϣ���£�\n");
						printf("\n\t ѧ��\t �� ��\t �Ա�\t����\t��ѧ\tӢ��\t�� ��\tƽ �� ��\n\n");
						printf("\t %d\t %s\t  %c\t %d\t %d\t %d\t %d\t %.2f\n\n", stu[i].no, stu[i].name, stu[i].sex, stu[i].score[0], stu[i].score[1], stu[i].score[2], stu[i].sum, stu[i].average);
						printf("\n\t ��ʾ��ϣ�������������Ӳ˵�!");
						getch();
						break;
					}

				if (i == *stu_number)
				{
					printf("\n\t Ҫ��ѯ��ѧ��������!������������Ӳ˵�!");
					getch();
				}

				break;

			case 2:
				printf("\n\t ������Ҫ��ѯ��ѧ��������");
				scanf("%s", xm);
				find = 0;
				num = 0;

				for (i = 0; i < *stu_number; i++)
				{
					if (strcmp(stu[i].name, xm) == 0)
					{
						find = 1;
						num++;

						if (num == 1)
						{
							printf("\n\t Ҫ��ѯ��ѧ����Ϣ���£�\n");
							printf("\n\t ѧ��\t �� ��\t �Ա�\t����\t��ѧ\tӢ��\t�� ��\tƽ �� ��\n\n");
						}

						printf("\t %d\t %s\t  %c\t %d\t %d\t %d\t %d\t %.2f\n\n", stu[i].no, stu[i].name, stu[i].sex, stu[i].score[0], stu[i].score[1], stu[i].score[2], stu[i].sum, stu[i].average);
					}
				}

				if (find)
				{
					printf("\n\t ��ʾ��ϣ�������������Ӳ˵�!");
					getch();
				}
				else
				{
					printf("\n\t Ҫ��ѯ��ѧ��������!������������Ӳ˵�!");
					getch();
				}

				break;

			case 0:
				return;
		}
	}

	return;
}

void DeleteStu(struct student stu[], int * stu_number)
{
	int xh, i, j;
	char ch = 'y';
	LoadStu(stu, stu_number);
	system("title ɾ��ѧ����¼");

	while ((ch == 'y') || (ch == 'Y'))
	{
		system("cls");
		printf("\n\t\t------------------------ɾ��ѧ����¼------------------------\n\n");
		printf("\t\t ������Ҫɾ����ѧ��ѧ�ţ�");
		scanf("%d", &xh);

		for (i = 0; i < *stu_number; i++)
		{
			if (stu[i].no == xh)
			{
				printf("\n\t Ҫɾ����ѧ����Ϣ���£�\n");
				printf("\n\t ѧ��\t �� ��\t �Ա�\t����\t��ѧ\tӢ��\t�� ��\tƽ �� ��\n\n");
				printf("\t %d\t %s\t  %c\t %d\t %d\t %d\t %d\t %.2f\n\n", stu[i].no, stu[i].name, stu[i].sex, stu[i].score[0], stu[i].score[1], stu[i].score[2], stu[i].sum, stu[i].average);
				break;
			}
		}

		if (i == *stu_number)
		{
			printf("\n\t\tҪɾ����ѧ��������!\n");
		}
		else
		{
			printf("\n\t ȷ��ɾ����(y/n)?��");
			scanf("\n%c", &ch);

			if (ch == 'y' || ch == 'Y')
			{
				for (j = i + 1; j < *stu_number; j++)
				{
					stu[j - 1] = stu[j];
				}

				printf("\n\t ��ѧ���ѱ�ɾ��!\n");
				(*stu_number)--;
			}
		}

		printf("\n\t �Ƿ����ɾ������ѧ��(y/n)?:");
		scanf("\n%c", &ch);
	}

	SaveStu(stu, *stu_number, 0);
	return;
}

void ModifyStu(struct student stu[], int * stu_number)
{
	int xh, i, j, choose;
	char ch = 'y';
	LoadStu(stu, stu_number);
	system("title �޸�ѧ����¼");

	while (ch == 'y' || ch == 'Y')
	{
		system("cls");
		printf("\n\t --------------------------�޸�ѧ����¼--------------------------\n\n");
		printf("\t ������Ҫ�޸ĵ�ѧ��ѧ�ţ�");
		scanf("%d", &xh);

		for (i = 0; i < *stu_number; i++)
		{
			if (stu[i].no == xh)
			{
				printf("\n\t Ҫ�޸ĵ�ѧ����Ϣ���£�\n");
				printf("\n\t ѧ��\t �� ��\t �Ա�\t����\t��ѧ\tӢ��\t�� ��\tƽ �� ��\n\n");
				printf("\t %d\t %s\t  %c\t %d\t %d\t %d\t %d\t %.2f\n\n", stu[i].no, stu[i].name, stu[i].sex, stu[i].score[0], stu[i].score[1], stu[i].score[2], stu[i].sum, stu[i].average);
				break;
			}
		}

		if (i == *stu_number)
		{
			printf("\n\t\tҪ�޸ĵ�ѧ��������!\n");
		}
		else
		{
			printf("\n\t ȷ���޸���(y/n)?��");
			scanf("\n%c", &ch);

			while (ch == 'y' || ch == 'Y')
			{
				printf("\n\t 1.������Ϣ�޸�        2.ѧ���ɼ��޸�\n");
				printf("\n\t ��ѡ���޸����ݣ�");
				scanf("%d", &choose);

				switch (choose)
				{
					case 1:
						system("cls");
						printf("\n\t\t-------------��������������Ļ�����Ϣ-----------\n");
						printf("\n\t\t     ѧ�ţ�");
						scanf("%d", &stu[i].no);

						for (j = 0; j < *stu_number; j++)
							if (stu[i].no != xh && stu[i].no == stu[j].no)
							{
								printf("\n\t\t  ��ѧ���Ѵ��ڣ�����������!\n");
								printf("\n\t\t     ѧ�ţ�");
								scanf("%d", &stu[i].no);
							}

						printf("\n\t\t     ������");
						scanf("%s", &stu[i].name);
						printf("\n\t\t     �Ա�");
						scanf("\n%c", &stu[i].sex);
						break;

					case 2:
						system("cls");
						printf("\n\t\t-------------��������������ĳɼ���Ϣ-----------\n");
						printf("\n\t\t ���ĳɼ���");
						scanf("%3d", &stu[i].score[0]);
						printf("\n\t\t ��ѧ�ɼ���");
						scanf("%3d", &stu[i].score[1]);
						printf("\n\t\t Ӣ��ɼ���");
						scanf("%3d", &stu[i].score[2]);
						stu[i].sum = stu[i].score[0] + stu[i].score[1] + stu[i].score[2];
						stu[i].average = (float)stu[i].sum / 3.0;
				}

				printf("\n\t\t �޸ĳɹ�!�Ƿ�����޸ĸ�����������Ϣ(y/n)?��");
				scanf("\n%c", &ch);
			}
		}

		printf("\n\t\t �Ƿ�����޸�����ѧ������Ϣ(y/n)?��");
		scanf("\n%c", &ch);
	}

	SaveStu(stu, *stu_number, 0);             //����0��ʾ�Ը��Ƿ�ʽд���ļ�
	return;
}

void CountScore(struct student stu[], int * stu_number)
{
	int i, j, choose, sum[3], grade[3][5], min_score[3], max_score[3];
	float avg[3];
	LoadStu(stu, stu_number);
	system("title ͳ��ѧ���ɼ�");

	while (1)
	{
		system("cls");
		printf("\n");
		printf("\t|---------------------------------------------------------------|\n");
		printf("\t|                       ͳ��ѧ���ɼ��Ӳ˵�                      |\n");
		printf("\t|---------------------------------------------------------------|\n");
		printf("\t|                 1---ͳ��ÿ�ſγ̵��ֺܷ�ƽ����                |\n");
		printf("\t|                 2---ͳ��ÿ�ſγ̵���߷ֺ���ͷ�              |\n");
		printf("\t|                 3---ͳ��ÿ�ſγ̸�����������                  |\n");
		printf("\t|                 0---�������˵�                                |\n");
		printf("\t|---------------------------------------------------------------|\n");
		printf("\t    ��ѡ��ͳ�Ʒ�ʽ��");
		scanf("%d", &choose);

		if (choose == 1)
		{
			for (j = 0; j < 3; j++)
			{
				sum[j] = 0;
				avg[j] = 0.0;
			}

			for (j = 0; j < 3; j++)
				for (i = 0; i < *stu_number; i++)
				{
					sum[j] = sum[j] + stu[i].score[j];
				}

			for (j = 0; j < 3; j++)
			{
				avg[j] = (float)sum[j] / 3.0;
			}

			printf("\t ���Ŀγ��ܷ�Ϊ��%d,ƽ����Ϊ��%.2f\n", sum[0], avg[0]);
			printf("\t ��ѧ�γ��ܷ�Ϊ��%d,ƽ����Ϊ��%.2f\n", sum[1], avg[1]);
			printf("\t Ӣ��γ��ܷ�Ϊ��%d,ƽ����Ϊ��%.2f\n", sum[2], avg[2]);
			printf("\n\n\t ͳ����ϣ�������������Ӳ˵�!\n");
			getch();
		}
		else
			if (choose == 2)
			{
				for (j = 0; j < 3; j++) //min_score[3]��max_score[3]�����ʼ��
				{
					min_score[j] = 0;
					max_score[j] = 0;
				}

				for (j = 0; j < 3; j++)
				{
					if (*stu_number > 0)
					{
						min_score[j] = max_score[j] = stu[0].score[j];    //��߷���ͷ��ó�ֵ
					}
					else
					{
						min_score[j] = max_score[j] = 0;    //.........
					}

					for (i = 1; i < *stu_number; i++)
					{
						if (stu[i].score[j] < min_score[j])
						{
							min_score[j] = stu[i].score[j];
						}

						if (stu[i].score[j] > max_score[j])
						{
							max_score[j] = stu[i].score[j];
						}
					}
				}

				printf("\t ���Ŀγ̵���ͷ֣�%d,��߷֣�%d\n", min_score[0], max_score[0]);
				printf("\t ��ѧ�γ̵���ͷ֣�%d,��߷֣�%d\n", min_score[1], max_score[1]);
				printf("\t Ӣ��γ̵���ͷ֣�%d,��߷֣�%d\n", min_score[2], max_score[2]);
				printf("\n\n\t ͳ����ϣ�������������Ӳ˵�!\n");
				getch();
			}
			else
				if (choose == 3)
				{
					for (i = 0; i < 3; i++)           //grade[3][5]�����ʼ��
						for (j = 0; j < 5; j++)
						{
							grade[i][j] = 0;
						}

					for (j = 0; j < 3; j++)
						for (i = 0; i < *stu_number; i++)
						{
							switch (stu[i].score[j] / 10)
							{
								case 10:
								case 9:
									grade[j][0]++;
									break;

								case 8:
									grade[j][1]++;
									break;

								case 7:
									grade[j][2]++;
									break;

								case 6:
									grade[j][3]++;
									break;

								default:
									grade[j][4]++;
									break;
							}
						}

					printf("\n\n");
					printf("\t ���Ŀγ̸������ε��������£�\n");
					printf("\t 90-100:%d | 80-90:%d | 70-80:%d | 60-70:%d | 60��һ��:%d\n\n", grade[0][0], grade[0][1], grade[0][2], grade[0][3], grade[0][4]);
					printf("\t ��ѧ�γ̸������ε��������£�\n");
					printf("\t 90-100:%d | 80-90:%d | 70-80:%d | 60-70:%d | 60��һ��:%d\n\n", grade[1][0], grade[1][1], grade[1][2], grade[1][3], grade[1][4]);
					printf("\t Ӣ��γ̸������ε��������£�\n");
					printf("\t 90-100:%d | 80-90:%d | 70-80:%d | 60-70:%d | 60��һ��:%d\n\n", grade[2][0], grade[2][1], grade[2][2], grade[2][3], grade[2][4]);
					printf("\n\n\t ͳ����ϣ�������������Ӳ˵�!\n");
					getch();
				}
				else
					if (choose == 0)
					{
						break;    //����ѭ��
					}
	}

	return;
}

int main(void)
{
	struct student stu[N];
	int stu_number = 0;
	int choose, flag = 1;
	system("color 02");
	Create();
	PassWord();
	system("title ѧ����Ϣ����ϵͳ");

	while (flag)
	{
		system("cls");
		Menu();
		printf("\t\t ��ѡ�����˵����(0~7):");
		scanf("%d", &choose);

		switch (choose)
		{
			case 1:
				InputStu(stu, &stu_number);
				break;

			case 2:
				BrowseStu(stu, &stu_number);
				break;

			case 3:
				SearchStu(stu, &stu_number);
				break;

			case 4:
				SortStu(stu, &stu_number);
				break;

			case 5:
				DeleteStu(stu, &stu_number);
				break;

			case 6:
				ModifyStu(stu, &stu_number);
				break;

			case 7:
				CountScore(stu, &stu_number);
				break;

			case 0:
				system("cls");
				system("color 0c");
				printf("\n\n\n\n\n");
				printf("\t*****************************************************************\n");
				printf("\t*****************************************************************\n");
				printf("\t* *                                                           * *\n");
				printf("\t* *                     ��л����ʹ�ã��ټ�!                   * *\n");
				printf("\t* *                                                           * *\n");
				printf("\t*****************************************************************\n");
				printf("\t*****************************************************************\n");
				Sleep(2000);
				flag = 0;
		}
	}
}
