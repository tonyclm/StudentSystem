#include <stdio.h>
#include <stdlib.h>

void login();
void add();
void select();

inline void fls_stdin();

int student[100] = {0};
int student_num = 0;

int main()
{
	login();
	return 0;
}

void login()
{
	system("cls");
	puts("****** 欢迎来到学生信息管理系统 ******\n");
	puts("**************************************");
	puts("** 1. 添加记录 ");
	puts("** 2. 显示记录 ");
	puts("** 0. 退出程序 ");
	printf("\n请选择需要进行的操作: ");

	int chic;
	scanf("%d", &chic);
	switch(chic)
	{
		case 1:
			add(); break;
		case 2:
			select(); break;
		default:
			system("exit");
	}
}

void add()
{
	int mask = 0;
	for(int i = student_num; i < 100; i++)
	{
		system("cls");
		puts("** 添加记录 **\n");
		printf("> 学生编号 #%d：", i+1);
		scanf("%d", &mask);
		student[i] = mask;
		student_num++;
		printf("\n--您已输入%d位学生, 是否继续操作？[输入'N'即可退出]: ",  student_num);
		fls_stdin();
		char c = getchar();
		if(c == 'N') 
			break;
		else if(c == '\n')
			continue; 
		else  
			fls_stdin();
			continue; 
	}

	login();
}

void select()
{
	while(1) 
	{
		system("cls");
		puts("** 显示记录 **\n");
		printf("> 请输入学生编号: ");
		int num;
		scanf("%d", &num);
		if(0 >= num || num > 100) continue;
		puts("\n******* 查询结果 *******");
		printf("--- 学生编号: %d\n", num);
		printf("--- 成绩: %d\n", student[num-1]);
		printf("\n是否继续查询？[输入'N'即可退出]: ");
		fls_stdin();
		char c = getchar();
		if(c == 'N')
			break;
		else if(c == '\n')
			continue; 
		else 
			fls_stdin();
			continue; 
	}

	login();
}

inline void fls_stdin()
{
	while(getchar() != '\n') 
		continue;
}
