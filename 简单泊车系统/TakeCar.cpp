#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "car.h"

extern void WriteToFile(struct Car *head);
extern void WriteToFile_1(struct Car *car);
extern int g_nCarNumber;
 
/*按照车牌号取车，返回一个结构体指针 */ 
struct Car *TakeCar(struct Car *head)
{
	char Number[10];
	printf("请输入车牌号:");
	scanf("%s",&Number);
	struct Car *p1,*p2;
	if(head == NULL)   //对指针进行判断，看是否为空 
	{
		printf("\nThe list is NULL!\n");
		return head;
	}
		p1 = head;
		while((strcmp(Number,p1->carNmber)!=0) && p1->next!=NULL)  //遍历链表，按照车牌号进行查找 
		{
			p2=p1;
			p1=p1->next;
		}
		if((strcmp(Number,p1->carNmber)==0))   //找到该车 
		{
			printf("请输入取车日期：");
			scanf("%s",&p1->takeDate);
			printf("请输入取车时间：");
			scanf("%s",&p1->takeTime);
			printf("请输入停车费用：");
			scanf("%d",&p1->parkCarCost);
			WriteToFile_1(p1);
			if(p1==head)
			head=p1->next;
			else 
			p2->next=p1->next;
			free(p1);
			printf("已经取车 : %s\n",Number);
			g_nCarNumber=g_nCarNumber-1;
		}
	else                //没有找到该车 
		printf("%s is not been found!\n",Number);
	WriteToFile(head);
	system("pause");
	return head;
}
