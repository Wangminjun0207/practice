#include "Predefine.h"

/* �����Ա����ͳ������*/
void Statistic_g(struct student *head)
{
	int nMale = 0; // ����������� 
	int nFemale = 0; // ���Ů������ 
	struct student *p1;
	if(head==NULL)    //��ָ������жϣ����Ƿ�Ϊ�� 
	{
		printf("\nThe list is NULL!\n");
		exit(0);
	}
	p1=head;
	while(p1!=NULL)  //���������������Ա����ͳ�� 
	{
		if(strcmp(p1->gerden,"male")==0)
			nMale++;
		else if(strcmp(p1->gerden,"female")==0)
			nFemale++;
		p1=p1->next;
	}
	printf("������ %d �ˣ�Ů���� %d ��!\n",nMale,nFemale);
	system("pause");
}

/* �����������ͳ������*/
void Statistic_a(struct student *head)
{
	int nAge_18 = 0; // ���18������� 
	int nAge_19 = 0;  //���19������� 
	int nAge_20 = 0; //���20������� 
	int nAge_another = 0;  //���������������� 
	struct student *p1;
	if(head==NULL)    //��ָ������жϣ����Ƿ�Ϊ�� 
	{
		printf("\nThe list is NULL!\n");
		exit(0);
	}
	p1=head;
	while(p1!=NULL)  //���������������������ͳ�� 
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
	printf("18����� %d �ˣ�19����� %d �ˣ�20����� %d �ˣ������������ %d ��!\n",
			nAge_18,nAge_19,nAge_20,nAge_another);
	system("pause");
}