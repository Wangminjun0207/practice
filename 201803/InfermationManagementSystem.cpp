/**
 *���ߣ������� 
 *ʱ�䣺2018-04-08 
 *������ѧ����Ϣ����ϵͳ����������ѧ������ѯѧ�����༭ѧ����
        ɾ��ѧ������ӡȫ�����˳�����Ĺ��� 
 */                            
                               
#include <stdio.h>             
#include <stdlib.h>            
#include <windows.h>           
int g_nNumber=0;   //����ȫ�ֱ��������ѧ������ 
/*
 *����һ���ṹ�壬����Ϊstudent
 *��Ա��ѧ�š��������Ա����䡢�ɼ�
*/ 
struct student{
	int number;
	char name[20];
	char gerden[10];
	int age;
	float mark;
	struct student *next;
};

/*����һ����̬���������ڴ��ѧ����Ϣ*/ 
struct student *Creat()
{
	struct student *head,*p1,*p2;
	head=NULL;
	p1=p2=(	struct student *)malloc(sizeof(	struct student));
	printf("����������ѧ�š��������Ա����䡢�ɼ�\n");
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
//		printf("����������ѧ�š��������Ա����䡢�ɼ�\n");
		scanf("%d%s%s%d%f",&p1->number,&p1->name,&p1->gerden,&p1->age,&p1->mark);
	}
	p2->next=NULL;
	free(p1); 
	return head;
 } 
 
/*ɾ��һ��ѧ����Ϣ������һ���ṹ��ָ�� */ 
struct student *Delete(struct student *head)
{
	int num;
	printf("please input number :");
	scanf("%d",&num);
	struct student *p1,*p2;
	if(head==NULL)    //��ָ������жϣ����Ƿ�Ϊ�� 
	{
		printf("\nThe list is NULL!\n");
		return head;
	}
	p1=head;
	while(p1->number!=num && p1->next!=NULL)  //��������������ѧ�Ž��в��� 
	{
		p2=p1;
		p1=p1->next;
	}
	if(p1->number==num)   //��һ��������ҵ���ѧ�� 
	{
		if(p1==head)
		head=p1->next;
		else 
		p2->next=p1->next;
		free(p1);
		printf("Ddelete : %d\n",num);
		g_nNumber=g_nNumber-1;
	}
	else                //�ڶ��������û���ҵ���ѧ��
		printf("%d is not been found!\n");
	system("pause");
	return head;
}

/*����һ��ѧ����Ϣ������һ���ṹ��ָ�� */ 
struct student *Insert(struct student *head)
{
	struct student *stud;
	stud=(	struct student *)malloc(sizeof(	struct student));//��̬�����ڴ� 
	printf("����������ѧ�š��������Ա����䡢�ɼ�\n");
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
	printf("ѧ��Ϊ %d ��ѧ����Ϣ�Ѿ�����!\n",stud->number);
	system("pause");
	g_nNumber=g_nNumber+1;
	return head;
}

 /*��ѯһ��ѧ����Ϣ���������*/ 
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
	if(p1->number==num)       //�ҵ���ѧ�������ѧ����Ϣ 
	{
		printf("ѧ��	����	�Ա�	����	�ɼ�\n");
		printf("%d\t%s\t%s\t%d\t%.2f\n",p1->number,p1->name,p1->gerden,p1->age,p1->mark);
	}
	else                     //δ�ҵ���ѧ�������������Ϣ 
		printf("%d is not been found!\n",num);
	system("pause");
 }
 
 /*�༭һ��ѧ����Ϣ������һ���ṹ��ָ�� */ 
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
			printf("����������ѧ�š��������Ա����䡢�ɼ�\n");
			scanf("%d%s%s%d%f",&p1->number,&p1->name,&p1->gerden,&p1->age,&p1->mark);
			printf("The %d is  been editor!\n",num);
		}
	else
		printf("The %d is not been found!\n",num);
	system("pause");
	return head;
}

/*�˵����棬���������ֹ���*/ 
 int Interface()
 {
 	system("cls");
 	puts("1.����ѧ��");
 	puts("2.��ѯѧ��");
 	puts("3.�༭ѧ��");
 	puts("4.ɾ��ѧ��");
 	puts("5.��ӡȫ��");
 	puts("6.�˳�����");
 }
 
/*��ӡ����ѧ����Ϣ */ 
struct student Output(struct student *head)
{
	struct student *p1;
	p1=head;
	printf("ѧ��	����	�Ա�	����	�ɼ�\n");
	while(p1!=NULL)
	{
		printf("%d\t%s\t%s\t%d\t%.2f\n",p1->number,p1->name,p1->gerden,p1->age,p1->mark);
		p1=p1->next;
	}
	system("pause");
}

/*�˳��������*/ 
int Exit()
{
	system("cls");
	puts("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t====================================" );
	puts("\t\t\t\t\t| ��л����ʹ�ã��ټ�!              |");
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
		printf("��ѡ����Ҫʵ�ֵĹ���:"); 
 		scanf("%d",&selectkey);
		switch(selectkey)
		{
			case 1:system("cls");printf("����ѧ��\n\n");head_1=Insert(head);break;
			case 2:system("cls");printf("��ѯѧ��\n\n");Query(head);break;
			case 3:system("cls");printf("�༭ѧ��\n\n");head_1=Editor(head);break;
			case 4:system("cls");printf("ɾ��ѧ��\n\n");head_1=Delete(head);break;
			case 5:system("cls");printf("��ӡȫ��\n\n");Output(head);break;
			case 6:system("cls");printf("�˳�����\n\n");Exit();break;
		}
		if(selectkey==1 || selectkey==3 || selectkey==4)
			head = head_1;
	}while(selectkey != 6);
	return 0;
}