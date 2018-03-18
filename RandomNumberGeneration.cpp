#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include <windows.h>
int g_nNumber;
int main(int args,char *argv[])
{
	int n,i,Max,Min,flag=0;
	int *arr;
	srand(time(0)) ;
	printf("输入抽奖的人数：");
	scanf("%d",&n);
	printf("输入随机数的下界Min：");
	scanf("%d",&Min);
	printf("输入随机数的上界Max：");
	scanf("%d",&Max);
	arr=(int *)malloc(n*sizeof(int));
	system("cls");
	do
	{
		for(i=0;i<n;i++)
		{
			arr[i]=rand()%(Max-Min+1)+Min;
			printf("p%d,his number is %d\n",i,arr[i]);
	 	} 
		g_nNumber=rand()%(Max-Min+1)+Min;
		puts("Press any key to draw lottry...");
		system("pause");
		system("cls");
		for(i=0;i<n;i++)
		if(arr[i]==g_nNumber)
		{
			printf("The winter is : p%d,his number is %d\n",i,arr[i]);
			flag++;
		}
	}while(flag==0);
	printf("The valid loottery number is : %d\n",g_nNumber);
	return 0;
}
