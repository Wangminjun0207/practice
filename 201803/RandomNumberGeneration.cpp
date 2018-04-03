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
	printf("\t\t\t输入抽奖的人数：");
	scanf("%d",&n);
	printf("\t\t\t输入随机数的下界Min：");
	scanf("%d",&Min);
	printf("\t\t\t输入随机数的上界Max：");
	scanf("%d",&Max);
	arr=(int *)malloc(n*sizeof(int));
	system("cls");
	do
	{
		for(i=0;i<n;i++)
		{
			arr[i]=rand()%(Max-Min+1)+Min;
			printf("\t\tp%d,his number is %d\n",i+1,arr[i]);
	 	} 
		g_nNumber=rand()%(Max-Min+1)+Min;
		puts("Press any key to draw lottry...");
		system("pause");
		//system("cls");
		for(i=0;i<n;i++)
		if(arr[i]==g_nNumber)
		{
			printf("\t\tThe winter is : p%d,his number is %d\n",i+1,arr[i]);
			flag++;
		}
		if(flag==0)
		{
			puts("\t\t============================================");
			printf("\t\tNo one wins,the valid lottery number is : %d\n",g_nNumber);
			puts("\t\t============================================");
		}
		else
		{
			puts("\t\t===================================");
			printf("\t\t The valid lottery number is : %d\n",g_nNumber);
			puts("\t\t===================================");
		}
		system("pause");
		system("cls");
	}while(flag==0);
	return 0;
}

