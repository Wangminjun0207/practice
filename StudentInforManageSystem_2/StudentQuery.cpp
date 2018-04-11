 #include "Predefine.h"
 
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

