 #include "Predefine.h"
 
 /*����ѧ�Ų�ѯһ��ѧ����Ϣ���������*/ 
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
	if(p1->number==num)       //�ҵ���ѧ�������ѧ����Ϣ 
	{
		printf("ѧ��	����	�Ա�	����	�ɼ�	����֤����\n");
		printf("%d\t%s\t%s\t%d\t%.2f\t%s\n",p1->number,p1->name,p1->gerden,p1->age,p1->mark,p1->ID);
	}
	else                     //δ�ҵ���ѧ�������������Ϣ 
		printf("%d is not been found!\n",num);
	system("pause");
 }
 
/*����������ѯһ��ѧ����Ϣ���������*/ 
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
	if(strcmp(name,p1->name)==0)       //�ҵ���ѧ�������ѧ����Ϣ 
	{
		printf("ѧ��	����	�Ա�	����	�ɼ�	����֤����\n");
		printf("%d\t%s\t%s\t%d\t%.2f\t%s\n",p1->number,p1->name,p1->gerden,p1->age,p1->mark,p1->ID);
	}
	else                     //δ�ҵ���ѧ�������������Ϣ 
		printf("%s is not been found!\n",name);
	system("pause");
 }

/*���ճɼ���ѯһ��ѧ����Ϣ���������*/ 
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
	if(p1->mark==score)       //�ҵ���ѧ�������ѧ����Ϣ 
	{
		printf("ѧ��	����	�Ա�	����	�ɼ�	����֤����\n");
		printf("%d\t%s\t%s\t%d\t%.2f\t%s\n",p1->number,p1->name,p1->gerden,p1->age,p1->mark,p1->ID);
	}
	else                     //δ�ҵ���ѧ�������������Ϣ 
		printf(" Is not been found!\n");
	system("pause");
 }
