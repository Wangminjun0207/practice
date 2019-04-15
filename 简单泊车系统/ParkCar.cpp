#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "car.h"

extern int g_nCarNumber;
extern void WriteToFile(struct Car *head);

/*停车，返回一个结构体指针 */ 
struct Car *ParkCar(struct Car *head)
{
	struct Car *car,*p;
	char select;//是否继续添加学生信息 
	do
	{
		car = (struct Car *)malloc(sizeof(struct Car));//动态申请内存 
		if(NULL == car)
		{
			printf("申请内存出错！\n\a");
			exit(0);
		}
		printf("以下车位已经停车，请不要选择！\n\n");
		p = head;
		while(NULL != p)
		{
			printf("%s\t",p->parkingNumber);
			p = p->next;
		}
		printf("请选择车位：");
		scanf("%s",&car->parkingNumber);
		printf("请输入车牌号：");
		scanf("%s",&car->carNmber);
		printf("请输入车主姓名：");
		scanf("%s",&car->carHost);
		printf("请输入车型：");
		scanf("%s",&car->carType);
		printf("请输入停车日期：");
		scanf("%s",&car->parkDate);
		printf("请输入停车时间：");
		scanf("%s",&car->parkTime);
		struct Car *p0,*p1,*p2;
		p1 = head;
		p0 = car;
		if(NULL == head)
		{
			head = p0;
			p0->next = NULL;
		}
		else
		{
			while((strcmp(p0->parkingNumber,p1->parkingNumber)>0) && (NULL != p1->next))
			{
				p2 = p1;
				p1 = p1->next;
			}
			if(strcmp(p0->parkingNumber,p1->parkingNumber)<=0)
			{
				if(head==p1)
					head = p0;
				else
					p2->next=p0;
				p0->next = p1;
			}
			else
			{
				p1->next = p0;
				p0->next = NULL;
			}
			printf("\n\n%s已经安全停车！\n\n",car->carNmber);
		} 
		g_nCarNumber = g_nCarNumber + 1;
		printf("\n是否还要继续停车？ ");
		scanf("%*c%c",&select); 
	}while(select=='y' || select=='Y');
	WriteToFile(head);
	return head;
}

