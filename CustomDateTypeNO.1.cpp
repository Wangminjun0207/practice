#include <stdio.h>
int main()
{
	struct student
	{
		int number;
		char a[10];
		int score;
	 } stu[5];
	 int i;
	 char b[25];
	 for(i=0;i<5;i++)
		scanf("%d %s %d",&stu[i].number,&stu[i].a,&stu[i].score);
				printf("\n"); 
	for(i=0;i<5;i++)
printf("%d %s %d\n\n",stu[i].number,stu[i].a,stu[i].score);

}
