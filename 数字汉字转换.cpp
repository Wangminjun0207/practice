#include <stdio.h>
int main()
{
int a;
printf("please input a number:\n");
scanf("%d",&a);
switch(a)
{
	case 0:
	printf("零\n");
	break;
	case 1:
	printf("壹\n");
	break;
	case 2:
	printf("贰\n");
	break;
	case 3:
	printf("叁\n");
	break;
	case 4:
	printf("肆\n");
	break;
	case 5:
	printf("伍\n");
	break;
	case 6:
	printf("陆\n");
	break;
	case 7:
	printf("柒\n");
	break;
	case 8:
	printf("捌\n");
	break;
	case 9:
	printf("玖\n");
	break;
	default:
	printf("对不起，你输入的数字无法识别！\n");
	break;
}
}
