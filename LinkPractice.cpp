#include <stdio.h>
#include <stdlib.h>
struct student
{
	int number;
	float score;
	struct student *next; 
};
int n=0; 
struct student *creat(void)
{
	struct student *head,*p1,*p2;
	head=NULL;
	p1=p2=(struct student *)malloc(sizeof(struct student));
	scanf("%d %f",&p1->number ,&p1->score);
	while(p1->number!=0)
	{
		n=n+1;
		if(n==1)
			head=p1;
		else
			p2->next=p1;
			p2=p1;
	p1=(struct student *)malloc(sizeof(struct student));
	scanf("%d %f",&p1->number ,&p1->score);	
	}
	p2->next=NULL;
	free(p1);
	return head; 
}
struct student *del(struct student *head,int number)
{
	struct student *p1,*p2;
	if(head==NULL)
	{
		printf("\nThe list is NULL\n");
		return head;
	}
	p1=head;
	while(p1->number!=number && p1->next!=NULL)
	{
		p2=p1;
		p1=p1->next;
	}
	if(p1->number==number)
	{
		if(p1==head)
		head=p1->next;
		else
		p2->next=p1->next;
		free(p1);
		printf("Delete:%d\n",number);
		n=n-1;
	}
	else
	printf("%d is not been found!\n",number);
	return head;
}
struct student *insert(struct student *head,struct student *stud)
{
	struct student *p,*p1,*p2;
	p1=head;
	p=stud;
	if(head==NULL)
	{
		head=p;
		p->next=NULL;
	}
	else
	{
		while(p->number>p1->number && p1->next!=NULL)
		{
			p2=p1;
			p1=p1->next;
		}
		if(p->number<=p1->number)
		{
			if(p1==head)
			head=p;
			else
			p2->next=p;
			p->next=p1;
		}

	else
	{
		p1->next=p;
		p->next=NULL;
	 } 
	}
	 n=n+1;
	 return head;
}
struct student print(struct student *head)
{
	struct student *p=head;
	printf("Á´±íÄÚÈİÎª£º\n");
	while(p!=NULL)
	{
		printf("The number:%d\tThe score:%f\n",p->number,p->score);
		p=p->next;	
	}
}
int main()
{
	struct student *head,*p;
	head=creat();
	print(head);
	p=del(head,201702);
	print(p);
	struct student stud,*p1;
	p1=&stud;
	p1->number=201702;
	p1->score=55;
	p=insert(p,p1);
	print(p);
	return 0;
}
