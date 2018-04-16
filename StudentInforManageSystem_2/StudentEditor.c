#include "Predefine.h"
extern void WriteToFile(struct student *head);
extern void Interface_3();
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


