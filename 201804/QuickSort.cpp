#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
int Ascending(int*);  
int Descending(int*);
int Interface();
int g_nNumber;
int g_nX;
int main(int argc, char *argv[])
{
	int *arr,n;
	srand(time(0)) ;
	printf("请输入数组长度：");
	scanf("%d",&g_nNumber);
	arr=(int *)malloc(g_nNumber*sizeof(int)); //申请内存 
	for(int i=0;i<g_nNumber-1;i++)
	arr[i]=rand()%9901+100;
	printf("原数组为：\n");
	for(int i=0;i<g_nNumber-1;i++)
	{
		printf("%d\t",arr[i]);
		if((i+1)%10 == 0)
		printf("\n");
	}
	printf("\n请输入你要插入的数字（100~10000）：");
	scanf("%d",&g_nX);
	do{
	system("cls");
	Interface();
	scanf("%d",&n);
	switch(n){
		case 1:Ascending(arr);break;
		case 2:Descending(arr);break;
		case 3:exit(1); 
		default:printf("选择的功能有误！\n");
	}
	printf("插入%d并排序后的数组为：\n",g_nX);
	for(int i=0;i<g_nNumber;i++)
	{
		printf("%7d",arr[i]);
		if((i+1)%10 == 0)
		printf("\n");
	}
	printf("\n");
	system("pause");
	}while(n==1 || n==2);
	return 0;
}

/* 进行升序排序 */ 
int Ascending(int *p)
{
	int temp;
	for(int i=1;i<=g_nNumber-2;i++)
	for(int j=0;j<g_nNumber-i-1;j++)
	{
		if(p[j]>p[j+1])
		{
			temp=p[j];
			p[j]=p[j+1];
			p[j+1]=temp;
		}
		else
		; 
	}
	int i=g_nNumber-2;
	while(i>=0 && p[i]>g_nX)
	{
		p[i+1]=p[i];
		i--;
	}
	p[i+1]=g_nX;
	return 0;
}

/*  进行降序排序  */
int Descending(int *p)
{
	int temp;
	for(int i=1;i<=g_nNumber-2;i++)
	for(int j=0;j<g_nNumber-i-1;j++)
	{
		if(p[j]<p[j+1])
		{
			temp=p[j];
			p[j]=p[j+1];
			p[j+1]=temp;
		}
		else
		; 
	}
	int i=g_nNumber-2;
	while(i>=0 && p[i]<g_nX)
	{
		p[i+1]=p[i];
		i--;
	}
	p[i+1]=g_nX;
	return 0;
}

//菜单界面 
int Interface()
{
	puts("请选择你要做的操作");
	puts("==================="); 
	puts("1.升序             ");
	puts("2.降序             ");
	puts("3.退出             ");
	puts("===================");
	return 0;
}

