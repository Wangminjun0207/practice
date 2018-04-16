/**
 *作者：王敏军 
 *时间：2018-04-08 
 *描述：学生信息管理系统，包括添加学生、查询学生、编辑学生、
        删除学生、打印全部、退出程序的功能 
 */   

#include <stdio.h>             
#include <stdlib.h> 
#include <string.h>           
#include <windows.h>           
int g_nNumber=0;   //定义全局变量，存放学生人数 
void Interface();
void Interface_1();
void Interface_2();
void Interface_3();
 
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
	char ID[20];
	struct student *next;
};


/*创建一个动态链表，用于存放学生信息*/ 
/*
struct student *Creat()
{
	struct student *head,*p1,*p2;
	head=NULL;
	p1=p2=(	struct student *)malloc(sizeof(	struct student));
	printf("请依次输入学号\t姓名\t性别\t年龄\t成绩\t身份证号码\n");
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
		scanf("%d%s%s%d%f",&p1->number,&p1->name,&p1->gerden,&p1->age,&p1->mark);
	}
	p2->next=NULL;
	free(p1); 
	return head;
 } 
*/

/*按照学号删除一个学生信息，返回一个结构体指针 */ 
struct student *Delete_N(struct student *head)
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

/*按照姓名删除一个学生信息，返回一个结构体指针 */ 
struct student *Delete_n(struct student *head)
{
	char name[20];
	int nNumber = 0;  //记录同名的人数 
	printf("please input name :");
	scanf("%s",&name);
	struct student *p1,*p2;
	if(head == NULL)   //对指针进行判断，看是否为空 
	{
		printf("\nThe list is NULL!\n");
		return head;
	}
	p1 = head;
	
	while( p1 != NULL)  //遍历链表，按照学号进行查找 ，统计同名人数 
	{
		if(strcmp(name,p1->name) == 0) 
			nNumber++;
		p1=p1->next;
	}
	if(nNumber == 1)
	{
		p1 = head;
		while((strcmp(name,p1->name)!=0) && p1->next!=NULL)  //遍历链表，按照学号进行查找 
		{
			p2=p1;
			p1=p1->next;
		}
		if((strcmp(name,p1->name)==0))   //第一种情况：找到该学生 
		{
			if(p1==head)
			head=p1->next;
			else 
			p2->next=p1->next;
			free(p1);
			printf("Ddelete : %s\n",name);
			g_nNumber=g_nNumber-1;
		}
		system("pause");
		return head;
	}
	else if(nNumber > 1)
		{
			while(nNumber != 0)
			{
				p1 = head; 
				while((strcmp(name,p1->name)!=0) && p1->next!=NULL)  //遍历链表，按照学号进行查找 
				{
					p2=p1;
					p1=p1->next;
				}
				if((strcmp(name,p1->name)==0))   //第一种情况：找到该学生 
				{
					if(p1==head)
					head=p1->next;
					else 
					p2->next=p1->next;
					free(p1);
					printf("Ddelete : %s\n",name);
					g_nNumber=g_nNumber-1;
				}
				nNumber--;
			 } 
			 system("pause");
			 return head;
		}
	else                //第二种情况：没有找到该学生
		printf("%s is not been found!\n",name);
	system("pause");
	return head;
}

/*按照成绩删除一个学生信息，返回一个结构体指针 */ 
struct student *Delete_s(struct student *head)
{
	float score;
	printf("please input score :");
	scanf("%f",&score);
	struct student *p1,*p2;
	if(head==NULL)    //对指针进行判断，看是否为空 
	{
		printf("\nThe list is NULL!\n");
		return head;
	}
	p1=head;
	while(p1->mark!=score && p1->next!=NULL)  //遍历链表，按照学号进行查找 
	{
		p2=p1;
		p1=p1->next;
	}
	if(p1->mark==score)   //第一种情况：找到该学生 
	{
		if(p1==head)
		head=p1->next;
		else 
		p2->next=p1->next;
		free(p1);
		printf("Ddelete : %f\n",score);
		g_nNumber=g_nNumber-1;
	}
	else                //第二种情况：没有找到该学生
		printf("%f is not been found!\n",score);
	system("pause");
	return head;
}

/*插入一个学生信息，返回一个结构体指针 */ 
struct student *Insert(struct student *head)
{
	struct student *stud;
	stud=(	struct student *)malloc(sizeof(	struct student));//动态申请内存 
	if(stud == NULL)
	{
		printf("申请内存出错！\n\a");
		exit(0);
	}
	printf("请依次输入学号、姓名、性别、年龄、成绩、身份证号码\n");
	scanf("%d%s%s%d%f%s",&stud->number,&stud->name,&stud->gerden,&stud->age,&stud->mark,&stud->ID);
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

 /*按照学号查询一个学生信息，并且输出*/ 
void Query_N(struct student *head)
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
		printf("学号	姓名	性别	年龄	成绩	身份证号码\n");
		printf("%d\t%s\t%s\t%d\t%.2f\t%s\n",p1->number,p1->name,p1->gerden,p1->age,p1->mark,p1->ID);
	}
	else                     //未找到该学生，输出错误信息 
		printf("%d is not been found!\n",num);
	system("pause");
 }
 
/*按照姓名查询一个学生信息，并且输出*/ 
void Query_n(struct student *head)
 {
	struct student *p1;
	p1=head;
	char name[20];
	printf("Please input the student name you want to query :");
	scanf("%s",&name);
	while((strcmp(name,p1->name)!=0) && p1->next!=NULL)
	{
		p1=p1->next;
	}
	if(strcmp(name,p1->name)==0)       //找到该学生，输出学生信息 
	{
		printf("学号	姓名	性别	年龄	成绩	身份证号码\n");
		printf("%d\t%s\t%s\t%d\t%.2f\t%s\n",p1->number,p1->name,p1->gerden,p1->age,p1->mark,p1->ID);
	}
	else                     //未找到该学生，输出错误信息 
		printf("%s is not been found!\n",name);
	system("pause");
 }

/*按照成绩查询一个学生信息，并且输出*/ 
void Query_s(struct student *head)
 {
	struct student *p1;
	p1=head;
	float score;
	printf("Please input the student score you want to query :");
	scanf("%f",&score);
	while(p1->mark!=score && p1->next!=NULL)
	{
		p1=p1->next;
	}
	if(p1->mark==score)       //找到该学生，输出学生信息 
	{
		printf("学号	姓名	性别	年龄	成绩	身份证号码\n");
		printf("%d\t%s\t%s\t%d\t%.2f\t%s\n",p1->number,p1->name,p1->gerden,p1->age,p1->mark,p1->ID);
	}
	else                     //未找到该学生，输出错误信息 
		printf(" Is not been found!\n");
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
		Interface_3(); 
		int selectkey;
		scanf("%d",&selectkey);
		switch(selectkey)
		{
			case 1:printf("请输入学号：");
				   scanf("%d",&p1->number); 
				   break; 
			case 2:printf("请输入姓名：");
				   scanf("%s",&p1->name);
				   break;
			case 3:printf("请输入性别：");
				   scanf("%s",&p1->gerden);
				   break;
			case 4:printf("请输入年龄：");
				   scanf("%d",&p1->age);
				   break;
			case 5:printf("请输入成绩：");
				   scanf("%f",&p1->mark);
				   break;
			case 6:	printf("请依次输入学号、姓名、性别、年龄、成绩、身份证号码\n");
					scanf("%d%s%s%d%f%s",&p1->number,&p1->name,&p1->gerden,&p1->age,&p1->mark,&p1->ID);
					break;
			case 7:printf("请输入身份证号码：");
				   scanf("%s%s%d%f%s",&p1->ID);
				   break;
			case 0:printf("取消修改！\n"); 
				   break;
		}
		if(selectkey != 0)
		printf("The %d is  been editor!\n",num);
	}
	else
		printf("The %d is not been found!\n",num);
	system("pause");
	return head;
}



/*菜单界面，有以下六种功能*/ 
void Interface()
 {
 	system("cls");
 	puts("1.添加学生");
 	puts("2.查询学生");
 	puts("3.编辑学生");
 	puts("4.删除学生");
 	puts("5.打印全部");
	puts("6.人数统计");
 	puts("7.退出程序");
 }

/*二级菜单界面，有以下三种功能*/ 
void Interface_1()
 {
 	system("cls");
 	puts("1.学号");
 	puts("2.姓名");
 	puts("3.成绩");
	puts("请选择需求：");
 }
 
 /*二级菜单界面，有以下三种功能*/ 
void Interface_2()
 {
 	system("cls");
 	puts("1.人数");
 	puts("2.性别");
 	puts("3.年龄");
	puts("请选择需求：");
 }
 
  /*二级菜单界面，有以下八种功能*/ 
 void Interface_3()
 {
 	 	puts("1.修改学号");
		puts("2.修改姓名");
		puts("3.修改性别");
		puts("4.修改年龄");
		puts("5.修改成绩");
		puts("6.修改全部");
		puts("7.修改身份证号码");
		puts("0.不做修改");
 }

/*打印所有学生信息 */ 
void Output(struct student *head)
{
	struct student *p1;
	p1=head;
	printf("学号	姓名	性别	年龄	成绩	身份证号码\n");
	while(p1!=NULL)
	{
		printf("%d\t%s\t%s\t%d\t%.2f\t%s\n",p1->number,p1->name,p1->gerden,p1->age,p1->mark,p1->ID);
		p1=p1->next;
	}
	system("pause");
}

/* 按照性别进行统计人数*/
void Statistic_g(struct student *head)
{
	int nMale = 0; // 存放男生人数 
	int nFemale = 0; // 存放女生人数 
	struct student *p1;
	if(head==NULL)    //对指针进行判断，看是否为空 
	{
		printf("\nThe list is NULL!\n");
		exit(0);
	}
	p1=head;
	while(p1!=NULL)  //遍历链表，按照性别进行统计 
	{
		if(strcmp(p1->gerden,"male")==0)
			nMale++;
		else if(strcmp(p1->gerden,"female")==0)
			nFemale++;
		p1=p1->next;
	}
	printf("男生有 %d 人，女生有 %d 人!\n",nMale,nFemale);
	system("pause");
}

/* 按照年龄进行统计人数*/
void Statistic_a(struct student *head)
{
	int nAge_18 = 0; // 存放18岁的人数 
	int nAge_19 = 0;  //存放19岁的人数 
	int nAge_20 = 0; //存放20岁的人数 
	int nAge_another = 0;  //存放其他年龄的人数 
	struct student *p1;
	if(head==NULL)    //对指针进行判断，看是否为空 
	{
		printf("\nThe list is NULL!\n");
		exit(0);
	}
	p1=head;
	while(p1!=NULL)  //遍历链表，按照年龄进行统计 
	{
		if(p1->age==18)
			nAge_18++;
		else if(p1->age==19)
			nAge_19++; 
		else if(p1->age==20)
			nAge_20++;
		else
			nAge_another++;
		p1=p1->next;
	}
	printf("18岁的有 %d 人，19岁的有 %d 人，20岁的有 %d 人，其他年龄的有 %d 人!\n",
			nAge_18,nAge_19,nAge_20,nAge_another);
	system("pause");
}

/*退出程序界面*/ 
int Exit()
{
	system("cls");
	puts("\n\n\n\n\n\n\n\n\n\n\t\t\t\t====================================" );
	puts("\t\t\t\t| 感谢您的使用，再见!              |");
	puts("\t\t\t\t| Thank you for your use, goodbye! |");
	puts("\t\t\t\t====================================\n\n\n\n\n\n\n\n\n\n\n\n");
	exit(0);
}

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

