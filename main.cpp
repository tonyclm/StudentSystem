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
	puts("****** ��ӭ����ѧ����Ϣ����ϵͳ ******\n");
	puts("**************************************");
	puts("** 1. ��Ӽ�¼ ");
	puts("** 2. ��ʾ��¼ ");
	puts("** 0. �˳����� ");
	printf("\n��ѡ����Ҫ���еĲ���: ");

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
		puts("** ��Ӽ�¼ **\n");
		printf("> ѧ����� #%d��", i+1);
		scanf("%d", &mask);
		student[i] = mask;
		student_num++;
		printf("\n--��������%dλѧ��, �Ƿ����������[����'N'�����˳�]: ",  student_num);
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
		puts("** ��ʾ��¼ **\n");
		printf("> ������ѧ�����: ");
		int num;
		scanf("%d", &num);
		if(0 >= num || num > 100) continue;
		puts("\n******* ��ѯ��� *******");
		printf("--- ѧ�����: %d\n", num);
		printf("--- �ɼ�: %d\n", student[num-1]);
		printf("\n�Ƿ������ѯ��[����'N'�����˳�]: ");
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
