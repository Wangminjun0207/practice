#include <stdio.h>
#include <stdlib.h>
#include "Predefine.h"
extern struct student *Delete_N(struct student *head);
extern struct student *Delete_n(struct student *head);
extern struct student *Delete_s(struct student *head);
extern void Query_N(struct student *head);
extern void Query_n(struct student *head);
extern void Query_s(struct student *head);
extern struct student *Insert(struct student *head);
extern struct student *Editor(struct student *head);
extern void Output(struct student *head);
extern void Statistic_g(struct student *head);
extern void Statistic_a(struct student *head);
extern void Interface();
extern void Interface_1();
extern void Interface_2();
extern void Exit();
int main(int argc, char *argv[])
{
	struct student *head,*head_1;
	int selectkey;
	int selectkey_1;
	head = NULL;
	do
	{
		Interface();
		printf("请选择您要实现的功能:"); 
 		scanf("%d",&selectkey);
		switch(selectkey)
		{
			case 1:system("cls");printf("添加学生\n\n");head_1=Insert(head);break;
			case 2:system("cls");printf("查询学生\n\n");
				   Interface_1();
				   scanf("%d",&selectkey_1);
				   switch(selectkey_1)
				   {
						case 1:system("cls");printf("按照学号查询\n\n");Query_N(head);break;
					    case 2:system("cls");printf("按照姓名查询\n\n");Query_n(head);break;
						case 3:system("cls");printf("按照成绩查询\n\n");Query_s(head);break;
				   } 
				   break;
			case 3:system("cls");printf("编辑学生\n\n");head_1=Editor(head);break;
			case 4:system("cls");printf("删除学生\n\n");			   
				   Interface_1();
				   scanf("%d",&selectkey_1);
				   switch(selectkey_1)
				   {
						case 1:system("cls");printf("按照学号删除\n\n");head_1=Delete_N(head);break;
					    case 2:system("cls");printf("按照姓名删除\n\n");head_1=Delete_n(head);break;
						case 3:system("cls");printf("按照成绩删除\n\n");head_1=Delete_s(head);break;
				   } 
				   break;
			case 5:system("cls");printf("打印全部\n\n");Output(head);break;
			case 6:system("cls");printf("人数统计\n\n");
			       Interface_2();
				   scanf("%d",&selectkey_1);
				   switch(selectkey_1)
				   {
						case 1:system("cls");printf("按照人数统计\n\n");printf("总共有 %d 人！\n\n",g_nNumber);system("pause");break;
					    case 2:system("cls");printf("按照性别统计\n\n");Statistic_g(head);break;
						case 3:system("cls");printf("按照年龄统计\n\n");Statistic_a(head);break;
				   } 
				   break;
			case 7:system("cls");printf("退出程序\n\n");Exit();break;
		}
		if(selectkey==1 || selectkey==3 || selectkey==4)
			head = head_1;
	}while(selectkey != 7);
	return 0;
}
