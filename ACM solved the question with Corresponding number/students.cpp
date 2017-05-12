/* ****************************************************
 * **           学生信息管理系统源程序代码           **
 * ****************************************************
 * **         版本：v1.0.0                           **
 * **         Copyright (c) 2014 FeoniX。            **
 * ****************************************************
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dos.h>
#include <conio.h>
#include <time.h>
#define N 50                 //学生记录最大数量
#define MaxPwdLen 20         //密码最大长度

struct student               //学生记录结构体定义
{
	int no;
	char name[20];
	char sex;
	int score[3];
	int sum;
	float average;
};

//函数声明
void SaveStu(struct student stu[], int count, int flag);  //保存数据，写入文件
void LoadStu(struct student stu[], int * stu_number);     //读取文件数据
void PassWord();                                        //密码验证
void Menu();                                            //显示主菜单
void InputStu(struct student stu[], int * stu_number);    //输入学生记录
void BrowseStu(struct student stu[], int * stu_number);   //浏览学生记录
void SortStu(struct student stu[], int * stu_number);     //排序学生记录
void SearchStu(struct student stu[], int * stu_number);   //查找学生记录
void DeleteStu(struct student stu[], int * stu_number);   //删除学生记录
void ModifyStu(struct student stu[], int * stu_number);   //修改学生记录
void CountScore(struct student stu[], int * stu_number);  //统计学生记录

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
		printf("不能打开文\n");
		return;
	}

	for (i = 0; i < count; i++)
		if (fwrite(&stu[i], sizeof(struct student), 1, fp) != 1)
		{
			printf("文件写错误\n");
		}

	fclose(fp);
}

void LoadStu(struct student stu[], int * stu_number)
{
	FILE * fp;
	int i = 0;

	if ((fp = fopen("Data\\data.dat", "rb")) == NULL)
	{
		printf("不能打开文件\n");
		return;
	}

	while (fread(&stu[i], sizeof(struct student), 1, fp) == 1 && i < N)
	{
		i++;
	}

	*stu_number = i;                  //重置学生记录个数

	if (feof(fp))
	{
		fclose(fp);
	}
	else
	{
		printf("文件读错误\n");
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
	system("title 登录");
	system("cls");

	for (i = 3; i >= 1; i--)
	{
		j = 0;
		printf("\n\n\n\n\t\t 请输入密码(你还有%d次机会):", i);

		while ((c = getch()) != '\r')
		{
			if (j < MaxPwdLen && isprint(c))
			{
				//sprint()函数限定只接收可显示字符
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
		passwd[j] = '\0';                        //添加字符串结束标志

		if (strcmp(passwd, initpwd) == 0)
		{
			system("cls");
			system("title 欢迎页面");
			printf("\n\n\n\n");
			printf("\t\t-----------------------------------------\n");
			printf("\t\t*                                       *\n");
			printf("\t\t*        欢迎使用学生信息管理系统       *\n");
			printf("\t\t*                                       *\n");
			printf("\t\t-----------------------------------------\n\n\t\t");
			start = time(NULL);            //延时2秒继续执行
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
				printf("\n\t\t 密码错误!请重新输入!\n");
				continue;
			}
	}

	if (i == 0)
	{
		system("cls");
		printf("\n\n\t\t 对不起!你无权使用该系统!\n\n\t\t");
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
	system("title 主菜单");
	printf("\n\n");
	printf("\t\t|-----------------------------------|\n");
	printf("\t\t|         学生信息管理系统          |\n");
	printf("\t\t|-----------------------------------|\n");
	printf("\t\t|         1---增加学生记录          |\n");
	printf("\t\t|         2---浏览学生记录          |\n");
	printf("\t\t|         3---查询学生记录          |\n");
	printf("\t\t|         4---排序学生记录          |\n");
	printf("\t\t|         5---删除学生记录          |\n");
	printf("\t\t|         6---修改学生记录          |\n");
	printf("\t\t|         7---统计学生记录          |\n");
	printf("\t\t|         0---退出系统              |\n");
	printf("\t\t|-----------------------------------|\n");
}

void InputStu(struct student stu[], int * stu_number)
{
	char ch = 'y';
	int i, count = 0;
	LoadStu(stu, stu_number);
	system("title 增加学生记录");

	while ((ch == 'y') || (ch == 'Y'))
	{
		system("cls");
		printf("\n\t\t--------------------增加学生记录------------------\n");
		printf("\n\n\t\t 请输入学生信息\n");
		printf("\n\t\t     学号：");
		scanf("%d", &stu[count].no);

		for (i = 0; i < *stu_number; i++)
			if (stu[count].no == stu[i].no)
			{
				printf("\n\t\t 该学号已使用，请重输：\n");
				printf("\n\t\t     学号：");
				scanf("%d", &stu[count].no);
			}

		printf("\n\t\t     姓名：");
		scanf("%s", &stu[count].name);
		printf("\n\t\t     性别：");
		scanf("\n%c", &stu[count].sex);
		printf("\n\t\t 语文成绩：");
		scanf("%3d", &stu[count].score[0]);
		printf("\n\t\t 数学成绩：");
		scanf("%3d", &stu[count].score[1]);
		printf("\n\t\t 英语成绩：");
		scanf("%3d", &stu[count].score[2]);
		stu[count].sum = stu[count].score[0] + stu[count].score[1] + stu[count].score[2];
		stu[count].average = (float)stu[count].sum / 3.0;
		printf("\n\n\t\t 是否输入下一个学生信息?(y/n)");
		scanf("\n%c", &ch);
		count++;
	}

	*stu_number = *stu_number + count;
	SaveStu(stu, count, 1);             //参数1表示以追加方式写入文件
	return;
}

void BrowseStu(struct student stu[], int * stu_number)
{
	int i, j, choose;
	struct student temp_stu[N], st;
	LoadStu(stu, stu_number);
	system("title 浏览学生记录");

	while (1)
	{
		system("cls");
		printf("\n");
		printf("\t|---------------------------------------------------------------|\n");
		printf("\t|                       浏览学生记录子菜单                      |\n");
		printf("\t|---------------------------------------------------------------|\n");
		printf("\t|                       1---按学号顺序浏览                      |\n");
		printf("\t|                       2---按名次顺序浏览                      |\n");
		printf("\t|                       0---返回主菜单                          |\n");
		printf("\t|---------------------------------------------------------------|\n");
		printf("\t    请选择浏览方式：");
		scanf("%d", &choose);

		switch (choose)
		{
			case 1:
				system("cls");
				printf("\n\n\t  按学号升序浏览如下：\n");
				printf("\n\t 学号\t 姓 名\t 性别\t语文\t数学\t英语\t总 分\t平 均 分\n\n");

				for (i = 0; i < *stu_number; i++)
				{
					printf("\t %d\t %s\t  %c\t %d\t %d\t %d\t %d\t %.2f\n\n", stu[i].no, stu[i].name, stu[i].sex, stu[i].score[0], stu[i].score[1], stu[i].score[2], stu[i].sum, stu[i].average);
				}

				printf("\n\t\t 浏览完毕，按任意键返回子菜单!");
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
				printf("\n\n\t  按名次升序浏览如下：\n");
				printf("\n\t名次\t学号\t姓  名\t性别\t语文\t数学\t英语\t总 分\t平 均 分\n");

				for (i = 0; i < *stu_number; i++)
				{
					printf("\t %d\t%d\t%s\t %c\t %d\t %d\t %d\t %d\t %.2f\n\n", i + 1, temp_stu[i].no, temp_stu[i].name, temp_stu[i].sex, temp_stu[i].score[0], temp_stu[i].score[1], temp_stu[i].score[2], temp_stu[i].sum, temp_stu[i].average);
				}

				printf("\n\t\t 浏览完毕，按任意键返回子菜单!");
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
	system("title 排序学生记录");

	for (i = 1; i < *stu_number; i++)
		for (j = 1; j <= *stu_number - i; j++)
			if (stu[j - 1].no > stu[j].no)
			{
				st = stu[j - 1];
				stu[j - 1] = stu[j];
				stu[j] = st;
			}

	system("cls");
	printf("\n\n\t\t********************排序学生记录********************\n");
	printf("\n\n\t  按学号升序排序后的学生记录如下：\n");
	printf("\n\t 学号\t姓  名\t性别\t语文\t数学\t英语\t总 分\t平 均 分\n\n");

	for (i = 0; i < *stu_number; i++)
	{
		printf("\t %d\t%s\t %c\t %d\t %d\t %d\t %d\t %.2f\n\n", stu[i].no, stu[i].name, stu[i].sex, stu[i].score[0], stu[i].score[1], stu[i].score[2], stu[i].sum, stu[i].average);
	}

	printf("\n\t\t 排序完毕，按任意键返回主菜单!");
	getch();
	SaveStu(stu, *stu_number, 0);
	return;
}

void SearchStu(struct student stu[], int * stu_number)
{
	int xh, i, num, choose, find;
	char ch, xm[20];

	LoadStu(stu, stu_number);
	system("title 查询学生记录");

	while (1)
	{
		system("cls");
		printf("\n");
		printf("\t|---------------------------------------------------------------|\n");
		printf("\t|                       查询学生记录子菜单                      |\n");
		printf("\t|---------------------------------------------------------------|\n");
		printf("\t|                         1---按学号查询                        |\n");
		printf("\t|                         2---按姓名查询                        |\n");
		printf("\t|                         0---返回主菜单                        |\n");
		printf("\t|---------------------------------------------------------------|\n");
		printf("\t    请选择查询方式：");
		scanf("%d", &choose);

		switch (choose)
		{
			case 1:
				printf("\n\t 请输入要查询的学生学号：");
				scanf("%d", &xh);

				for (i = 0; i < *stu_number; i++)
					if (stu[i].no == xh)
					{
						printf("\n\t 要查询的学生信息如下：\n");
						printf("\n\t 学号\t 姓 名\t 性别\t语文\t数学\t英语\t总 分\t平 均 分\n\n");
						printf("\t %d\t %s\t  %c\t %d\t %d\t %d\t %d\t %.2f\n\n", stu[i].no, stu[i].name, stu[i].sex, stu[i].score[0], stu[i].score[1], stu[i].score[2], stu[i].sum, stu[i].average);
						printf("\n\t 显示完毕，按任意键返回子菜单!");
						getch();
						break;
					}

				if (i == *stu_number)
				{
					printf("\n\t 要查询的学生不存在!按任意键返回子菜单!");
					getch();
				}

				break;

			case 2:
				printf("\n\t 请输入要查询的学生姓名：");
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
							printf("\n\t 要查询的学生信息如下：\n");
							printf("\n\t 学号\t 姓 名\t 性别\t语文\t数学\t英语\t总 分\t平 均 分\n\n");
						}

						printf("\t %d\t %s\t  %c\t %d\t %d\t %d\t %d\t %.2f\n\n", stu[i].no, stu[i].name, stu[i].sex, stu[i].score[0], stu[i].score[1], stu[i].score[2], stu[i].sum, stu[i].average);
					}
				}

				if (find)
				{
					printf("\n\t 显示完毕，按任意键返回子菜单!");
					getch();
				}
				else
				{
					printf("\n\t 要查询的学生不存在!按任意键返回子菜单!");
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
	system("title 删除学生记录");

	while ((ch == 'y') || (ch == 'Y'))
	{
		system("cls");
		printf("\n\t\t------------------------删除学生记录------------------------\n\n");
		printf("\t\t 请输入要删除的学生学号：");
		scanf("%d", &xh);

		for (i = 0; i < *stu_number; i++)
		{
			if (stu[i].no == xh)
			{
				printf("\n\t 要删除的学生信息如下：\n");
				printf("\n\t 学号\t 姓 名\t 性别\t语文\t数学\t英语\t总 分\t平 均 分\n\n");
				printf("\t %d\t %s\t  %c\t %d\t %d\t %d\t %d\t %.2f\n\n", stu[i].no, stu[i].name, stu[i].sex, stu[i].score[0], stu[i].score[1], stu[i].score[2], stu[i].sum, stu[i].average);
				break;
			}
		}

		if (i == *stu_number)
		{
			printf("\n\t\t要删除的学生不存在!\n");
		}
		else
		{
			printf("\n\t 确定删除吗(y/n)?：");
			scanf("\n%c", &ch);

			if (ch == 'y' || ch == 'Y')
			{
				for (j = i + 1; j < *stu_number; j++)
				{
					stu[j - 1] = stu[j];
				}

				printf("\n\t 该学生已被删除!\n");
				(*stu_number)--;
			}
		}

		printf("\n\t 是否继续删除其他学生(y/n)?:");
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
	system("title 修改学生记录");

	while (ch == 'y' || ch == 'Y')
	{
		system("cls");
		printf("\n\t --------------------------修改学生记录--------------------------\n\n");
		printf("\t 请输入要修改的学生学号：");
		scanf("%d", &xh);

		for (i = 0; i < *stu_number; i++)
		{
			if (stu[i].no == xh)
			{
				printf("\n\t 要修改的学生信息如下：\n");
				printf("\n\t 学号\t 姓 名\t 性别\t语文\t数学\t英语\t总 分\t平 均 分\n\n");
				printf("\t %d\t %s\t  %c\t %d\t %d\t %d\t %d\t %.2f\n\n", stu[i].no, stu[i].name, stu[i].sex, stu[i].score[0], stu[i].score[1], stu[i].score[2], stu[i].sum, stu[i].average);
				break;
			}
		}

		if (i == *stu_number)
		{
			printf("\n\t\t要修改的学生不存在!\n");
		}
		else
		{
			printf("\n\t 确定修改吗(y/n)?：");
			scanf("\n%c", &ch);

			while (ch == 'y' || ch == 'Y')
			{
				printf("\n\t 1.基本信息修改        2.学生成绩修改\n");
				printf("\n\t 请选择修改内容：");
				scanf("%d", &choose);

				switch (choose)
				{
					case 1:
						system("cls");
						printf("\n\t\t-------------请重新输入该生的基本信息-----------\n");
						printf("\n\t\t     学号：");
						scanf("%d", &stu[i].no);

						for (j = 0; j < *stu_number; j++)
							if (stu[i].no != xh && stu[i].no == stu[j].no)
							{
								printf("\n\t\t  该学号已存在，请重新输入!\n");
								printf("\n\t\t     学号：");
								scanf("%d", &stu[i].no);
							}

						printf("\n\t\t     姓名：");
						scanf("%s", &stu[i].name);
						printf("\n\t\t     性别：");
						scanf("\n%c", &stu[i].sex);
						break;

					case 2:
						system("cls");
						printf("\n\t\t-------------请重新输入该生的成绩信息-----------\n");
						printf("\n\t\t 语文成绩：");
						scanf("%3d", &stu[i].score[0]);
						printf("\n\t\t 数学成绩：");
						scanf("%3d", &stu[i].score[1]);
						printf("\n\t\t 英语成绩：");
						scanf("%3d", &stu[i].score[2]);
						stu[i].sum = stu[i].score[0] + stu[i].score[1] + stu[i].score[2];
						stu[i].average = (float)stu[i].sum / 3.0;
				}

				printf("\n\t\t 修改成功!是否继续修改该生的其他信息(y/n)?：");
				scanf("\n%c", &ch);
			}
		}

		printf("\n\t\t 是否继续修改其他学生的信息(y/n)?：");
		scanf("\n%c", &ch);
	}

	SaveStu(stu, *stu_number, 0);             //参数0表示以覆盖方式写入文件
	return;
}

void CountScore(struct student stu[], int * stu_number)
{
	int i, j, choose, sum[3], grade[3][5], min_score[3], max_score[3];
	float avg[3];
	LoadStu(stu, stu_number);
	system("title 统计学生成绩");

	while (1)
	{
		system("cls");
		printf("\n");
		printf("\t|---------------------------------------------------------------|\n");
		printf("\t|                       统计学生成绩子菜单                      |\n");
		printf("\t|---------------------------------------------------------------|\n");
		printf("\t|                 1---统计每门课程的总分和平均分                |\n");
		printf("\t|                 2---统计每门课程的最高分和最低分              |\n");
		printf("\t|                 3---统计每门课程各分数段人数                  |\n");
		printf("\t|                 0---返回主菜单                                |\n");
		printf("\t|---------------------------------------------------------------|\n");
		printf("\t    请选择统计方式：");
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

			printf("\t 语文课程总分为：%d,平均分为：%.2f\n", sum[0], avg[0]);
			printf("\t 数学课程总分为：%d,平均分为：%.2f\n", sum[1], avg[1]);
			printf("\t 英语课程总分为：%d,平均分为：%.2f\n", sum[2], avg[2]);
			printf("\n\n\t 统计完毕，按任意键返回子菜单!\n");
			getch();
		}
		else
			if (choose == 2)
			{
				for (j = 0; j < 3; j++) //min_score[3]和max_score[3]数组初始化
				{
					min_score[j] = 0;
					max_score[j] = 0;
				}

				for (j = 0; j < 3; j++)
				{
					if (*stu_number > 0)
					{
						min_score[j] = max_score[j] = stu[0].score[j];    //最高分最低分置初值
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

				printf("\t 语文课程的最低分：%d,最高分：%d\n", min_score[0], max_score[0]);
				printf("\t 数学课程的最低分：%d,最高分：%d\n", min_score[1], max_score[1]);
				printf("\t 英语课程的最低分：%d,最高分：%d\n", min_score[2], max_score[2]);
				printf("\n\n\t 统计完毕，按任意键返回子菜单!\n");
				getch();
			}
			else
				if (choose == 3)
				{
					for (i = 0; i < 3; i++)           //grade[3][5]数组初始化
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
					printf("\t 语文课程各分数段的人数如下：\n");
					printf("\t 90-100:%d | 80-90:%d | 70-80:%d | 60-70:%d | 60分一下:%d\n\n", grade[0][0], grade[0][1], grade[0][2], grade[0][3], grade[0][4]);
					printf("\t 数学课程各分数段的人数如下：\n");
					printf("\t 90-100:%d | 80-90:%d | 70-80:%d | 60-70:%d | 60分一下:%d\n\n", grade[1][0], grade[1][1], grade[1][2], grade[1][3], grade[1][4]);
					printf("\t 英语课程各分数段的人数如下：\n");
					printf("\t 90-100:%d | 80-90:%d | 70-80:%d | 60-70:%d | 60分一下:%d\n\n", grade[2][0], grade[2][1], grade[2][2], grade[2][3], grade[2][4]);
					printf("\n\n\t 统计完毕，按任意键返回子菜单!\n");
					getch();
				}
				else
					if (choose == 0)
					{
						break;    //结束循环
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
	system("title 学生信息管理系统");

	while (flag)
	{
		system("cls");
		Menu();
		printf("\t\t 请选择主菜单序号(0~7):");
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
				printf("\t* *                     感谢您的使用，再见!                   * *\n");
				printf("\t* *                                                           * *\n");
				printf("\t*****************************************************************\n");
				printf("\t*****************************************************************\n");
				Sleep(2000);
				flag = 0;
		}
	}
}
