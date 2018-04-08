/**
 *作者：王敏军 
 *时间：2018-04-08 
 *描述：学生信息管理系统，包括添加学生、查询学生、编辑学生、
        删除学生、打印全部、退出程序的功能 
 */                                                          
#include <stdio.h>             
#include <stdlib.h>            
#include <windows.h>           
int g_nNumber=0;   //定义全局变量，存放学生人数 
/*
 *定义一个结构体，命名为student
 *成员有学号、姓名、性别、年龄、成绩
*/ 
struct student{
	int number;
	char name[20];
	char gerden[10];
	int age;
	float mark;
	struct student *next;
};

/*创建一个动态链表，用于存放学生信息*/ 
struct student *Creat()
{
	struct student *head,*p1,*p2;
	head=NULL;
	p1=p2=(	struct student *)malloc(sizeof(	struct student));
	printf("请依次输入学号、姓名、性别、年龄、成绩\n");
	scanf("%d%s%s%d%f",&p1->number,&p1->name,&p1->gerden,&p1->age,&p1->mark);
	while(p1->number!=0)
	{
		g_nNumber=g_nNumber+1;
		if(g_nNumber==1)
			head=p1;
		else
			p2->next=p1;
		p2=p1;	
		p1=(struct student *)malloc(sizeof(struct student));
//		printf("请依次输入学号、姓名、性别、年龄、成绩\n");
		scanf("%d%s%s%d%f",&p1->number,&p1->name,&p1->gerden,&p1->age,&p1->mark);
	}
	p2->next=NULL;
	free(p1); 
	return head;
 } 
 
/*删除一个学生信息，返回一个结构体指针 */ 
struct student *Delete(struct student *head)
{
	int num;
	printf("please input number :");
	scanf("%d",&num);
	struct student *p1,*p2;
	if(head==NULL)    //对指针进行判断，看是否为空 
	{
		printf("\nThe list is NULL!\n");
		return head;
	}
	p1=head;
	while(p1->number!=num && p1->next!=NULL)  //遍历链表，按照学号进行查找 
	{
		p2=p1;
		p1=p1->next;
	}
	if(p1->number==num)   //第一种情况：找到该学生 
	{
		if(p1==head)
		head=p1->next;
		else 
		p2->next=p1->next;
		free(p1);
		printf("Ddelete : %d\n",num);
		g_nNumber=g_nNumber-1;
	}
	else                //第二种情况：没有找到该学生
		printf("%d is not been found!\n");
	system("pause");
	return head;
}

/*插入一个学生信息，返回一个结构体指针 */ 
struct student *Insert(struct student *head)
{
	struct student *stud;
	stud=(	struct student *)malloc(sizeof(	struct student));//动态申请内存 
	printf("请依次输入学号、姓名、性别、年龄、成绩\n");
	scanf("%d%s%s%d%f",&stud->number,&stud->name,&stud->gerden,&stud->age,&stud->mark);
	struct student *p0,*p1,*p2;
	p1=head;
	p0=stud;
	if(head==NULL)
	{
		head = p0;
		p0->next=NULL;
	}
	else
	{
		while((p0->number>p1->number ) && (p1->next!=NULL))
		{
			p2=p1;
			p1=p1->next;
		}
		if(p0->number <= p1->number)
		{
			if(head==p1)
				head=p0;
			else
				p2->next=p0;
			p0->next=p1;
		}
		else
		{
			p1->next=p0;
			p0->next=NULL;
		}
	}
	printf("学号为 %d 的学生信息已经插入!\n",stud->number);
	system("pause");
	g_nNumber=g_nNumber+1;
	return head;
}

 /*查询一个学生信息，并且输出*/ 
 struct student Query(struct student *head)
 {
	struct student *p1;
	p1=head;
	int num;
	printf("Please input the student number you want to query :");
	scanf("%d",&num);
	while(p1->number!=num && p1->next!=NULL)
	{
		p1=p1->next;
	}
	if(p1->number==num)       //找到该学生，输出学生信息 
	{
		printf("学号	姓名	性别	年龄	成绩\n");
		printf("%d\t%s\t%s\t%d\t%.2f\n",p1->number,p1->name,p1->gerden,p1->age,p1->mark);
	}
	else                     //未找到该学生，输出错误信息 
		printf("%d is not been found!\n",num);
	system("pause");
 }
 
 /*编辑一个学生信息，返回一个结构体指针 */ 
struct student *Editor(struct student *head)
{
	struct student *p1;
	p1=head;
	int num;
	printf("Please input the student number you want to editor :");
	scanf("%d",&num);
	while(p1->number!=num && p1->next!=NULL)
	{
		p1=p1->next;
	}
	if(p1->number==num)
		{
			printf("请依次输入学号、姓名、性别、年龄、成绩\n");
			scanf("%d%s%s%d%f",&p1->number,&p1->name,&p1->gerden,&p1->age,&p1->mark);
			printf("The %d is  been editor!\n",num);
		}
	else
		printf("The %d is not been found!\n",num);
	system("pause");
	return head;
}

/*菜单界面，有以下六种功能*/ 
 int Interface()
 {
 	system("cls");
 	puts("1.添加学生");
 	puts("2.查询学生");
 	puts("3.编辑学生");
 	puts("4.删除学生");
 	puts("5.打印全部");
 	puts("6.退出程序");
 }
 
/*打印所有学生信息 */ 
struct student Output(struct student *head)
{
	struct student *p1;
	p1=head;
	printf("学号	姓名	性别	年龄	成绩\n");
	while(p1!=NULL)
	{
		printf("%d\t%s\t%s\t%d\t%.2f\n",p1->number,p1->name,p1->gerden,p1->age,p1->mark);
		p1=p1->next;
	}
	system("pause");
}

/*退出程序界面*/ 
int Exit()
{
	system("cls");
	puts("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t====================================" );
	puts("\t\t\t\t\t| 感谢您的使用，再见!              |");
	puts("\t\t\t\t\t| Thank you for your use, goodbye! |");
	puts("\t\t\t\t\t====================================\n\n\n\n\n\n\n\n\n\n\n\n");
	exit(0);
}

int main(int argc, char *argv[])
{	
	struct student *head,*head_1;
	int selectkey;
	head = Creat();
	do
	{
		Interface();
		printf("请选择您要实现的功能:"); 
 		scanf("%d",&selectkey);
		switch(selectkey)
		{
			case 1:system("cls");printf("添加学生\n\n");head_1=Insert(head);break;
			case 2:system("cls");printf("查询学生\n\n");Query(head);break;
			case 3:system("cls");printf("编辑学生\n\n");head_1=Editor(head);break;
			case 4:system("cls");printf("删除学生\n\n");head_1=Delete(head);break;
			case 5:system("cls");printf("打印全部\n\n");Output(head);break;
			case 6:system("cls");printf("退出程序\n\n");Exit();break;
		}
		if(selectkey==1 || selectkey==3 || selectkey==4)
			head = head_1;
	}while(selectkey != 6);
	return 0;
}
