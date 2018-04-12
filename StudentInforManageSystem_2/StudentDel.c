#include "Predefine.h"
extern void WriteToFile(struct student *head);
extern int g_nNumber;
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
	WriteToFile(head);
	return head;
}

/*按照姓名删除一个学生信息，返回一个结构体指针 */ 
struct student *Delete_n(struct student *head)
{
	char name[20];
	printf("please input name :");
	scanf("%s",&name);
	struct student *p1,*p2;
	if(head==NULL)    //对指针进行判断，看是否为空 
	{
		printf("\nThe list is NULL!\n");
		return head;
	}
	p1=head;
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
	else                //第二种情况：没有找到该学生
		printf("%s is not been found!\n",name);
	system("pause");
	WriteToFile(head);
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
	WriteToFile(head);
	return head;
}
