#include "Predefine.h"

/*菜单界面，有以下六种功能*/ 
void Interface()
 {
 	system("cls");
 	puts("1.添加学生");
 	puts("2.查询学生");
 	puts("3.编辑学生");
 	puts("4.删除学生");
 	puts("5.打印全部");
	puts("6.人数统计");
 	puts("7.退出程序");
 }
 
 /*二级菜单界面，有以下三种功能*/ 
void Interface_1()
 {
 	system("cls");
 	puts("1.学号");
 	puts("2.姓名");
 	puts("3.成绩");
	puts("请选择需求：");
 }
 
 /*二级菜单界面，有以下三种功能*/ 
void Interface_2()
 {
 	system("cls");
 	puts("1.人数");
 	puts("2.性别");
 	puts("3.年龄");
	puts("请选择需求：");
 }
 
 /*退出程序界面*/ 
void Exit()
{
	system("cls");
	puts("\n\n\n\n\n\n\n\n\n\n\t\t\t\t====================================" );
	puts("\t\t\t\t| 感谢您的使用，再见!              |");
	puts("\t\t\t\t| Thank you for your use, goodbye! |");
	puts("\t\t\t\t====================================\n\n\n\n\n\n\n\n\n\n\n\n");
	exit(0);
}

