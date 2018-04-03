#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int Guess()
{
	int guess;
	int magic;
	int counter = 0;
	srand(time(0));
	magic = rand()%11;
	do
	{
		counter++;
		printf("请输入您要猜的数字（ 0~10 ）：");
		scanf("%d",&guess);
		if(guess == magic)
		{
			printf("您猜对了！\n");
			break;
		}
		else if(guess > magic)
		{
			printf("您猜的太大了！\n");
			continue; 
		}
		else
		{
			printf("您猜的太小了！\n");
			continue; 
		}
	}while(counter < 5); 	
	return 0;
}

int Judge()
{
	return 0;
}
int main()
{
	Guess();
	Judge();
	return 0;
}
