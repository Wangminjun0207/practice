#include "Predefine.h"


/* 按照性别进行统计人数*/
void Statistic_g(struct student *head)
{
	int nMale = 0; // 存放男生人数 
	int nFemale = 0; // 存放女生人数 
	struct student *p1;
	if(NULL == head)    //对指针进行判断，看是否为空 
	{
		printf("\nThe list is NULL!\n");
		exit(0);
	}
	p1=head;
	while(NULL != p1)  //遍历链表，按照性别进行统计 
	{
		if(strcmp(p1->gerden,"male")==0)
			nMale++;
		else if(strcmp(p1->gerden,"female")==0)
			nFemale++;
		p1=p1->next;
	}
	printf("男生有 %d 人，女生有 %d 人!\n",nMale,nFemale);
	system("pause");
} 

/* 按照年龄进行统计人数*/
void Statistic_a(struct student *head)
{
	int nAge_18 = 0; // 存放18岁的人数 
	int nAge_19 = 0;  //存放19岁的人数 
	int nAge_20 = 0; //存放20岁的人数 
	int nAge_another = 0;  //存放其他年龄的人数 
	struct student *p1;
	/*
	* 一般情况下，如果需要和NULL做对比，用if(NULL == head)这样的方式，不要用if(head == NULL)这样的方式，因为有可能你会疏忽写成了if (head = NULL),这样就错了，而且查起来很恶心
	* 如果把NULL放前面，就会编译不过，因为不可能让 NULL = head,因此就少这样的低级错误。
	* add by wangpeng@2018/4/12
	*/
	
	if(NULL == head)    //对指针进行判断，看是否为空 
	{
		printf("\nThe list is NULL!\n");
		exit(0);
	}
	p1=head;
	while(NULL != p1)  //遍历链表，按照年龄进行统计 
	{
		if(p1->age==18)
			nAge_18++;
		else if(p1->age==19)
			nAge_19++; 
		else if(p1->age==20)
			nAge_20++;
		else
			nAge_another++;
		p1 = p1->next;
	}
	printf("18岁的有 %d 人，19岁的有 %d 人，20岁的有 %d 人，其他年龄的有 %d 人!\n",
			nAge_18,nAge_19,nAge_20,nAge_another);
	system("pause");
}
