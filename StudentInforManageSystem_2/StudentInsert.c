#include "Predefine.h"
extern void WriteToFile(struct student *head);
extern int g_nNumber;
/*插入一个学生信息，返回一个结构体指针 */ 
struct student *Insert(struct student *head)
{
	struct student *stud;
	stud = (struct student *)malloc(sizeof(	struct student));//动态申请内存 
	if(NULL == stud)
	{
		printf("申请内存出错！\n\a");
		exit(0);
	}
	printf("请依次输入学号、姓名、性别、年龄、成绩、身份证号码\n");
	scanf("%d%s%s%d%f%s",&stud->number,&stud->name,&stud->gerden,&stud->age,&stud->mark,&stud->ID);
	struct student *p0,*p1,*p2;
	p1 = head;
	p0 = stud;
	if(NULL == head)
	{
		head = p0;
		p0->next = NULL;
	}
	else
	{
		while((p0->number>p1->number ) && (NULL != p1->next))
		{
			p2 = p1;
			p1 = p1->next;
		}
		if(p0->number <= p1->number)
		{
			if(head==p1)
				head = p0;
			else
				p2->next=p0;
			p0->next = p1;
		}
		else
		{
			p1->next = p0;
			p0->next = NULL;
		}
	}
	printf("学号为 %d 的学生信息已经插入!\n",stud->number);
	WriteToFile(head);
	system("pause");
	g_nNumber = g_nNumber + 1;
	return head;
}
