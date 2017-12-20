#include <stdio.h>
int main()
{
	int a;
	printf("请输入一个0~100之间有效的(整数)分数：\n");
	scanf("%d",&a);
	if (a<60)
	{
		printf("%d不及格！",a);
	}
	else
	{
		if (a<=80)
		{
			printf("%d是及格！",a);
		}
		else
		{
			if (a<=100)
			{
				printf("%d是优秀！",a);
			}
			else
			{
				printf("你输入的成绩有误！");
			}
		}
	}
	 
 } 
