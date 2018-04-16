#include "Predefine.h"

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
