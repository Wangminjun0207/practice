#include "Predefine.h"

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
			printf("请依次输入学号、姓名、性别、年龄、成绩、身份证号码\n");
			scanf("%d%s%s%d%f%s",&p1->number,&p1->name,&p1->gerden,&p1->age,&p1->mark,&p1->ID);
			printf("The %d is  been editor!\n",num);
		}
	else
		printf("The %d is not been found!\n",num);
	system("pause");
	return head;
}

