#include <windows.h>
#include <stdio.h>

/*菜单界面，有以下六种功能*/ 
void Interface()
 {
 	system("cls");
 	puts("1.停车");
 	puts("2.取车");
 	puts("3.查询记录");
 	puts("4.停车场情况查询");
 	puts("0.退出程序");
 	printf("请选择服务："); 
 }
 
 
 
 /*退出程序界面*/ 
void Exit()
{
	system("cls");
	puts("\n\n\n\n\n\n\n\n\n\n\t\t\t\t====================================" );
	puts("\t\t\t\t| 感谢您的使用，再见!              |");
	puts("\t\t\t\t| Thank you for your use, goodbye! |");
	puts("\t\t\t\t====================================\n\n\n\n\n\n\n\n\n\n\n\n");
	exit(1);
}
