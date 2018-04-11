#include <stdio.h>
#include <stdlib.h>
#include <string.h>           
#include <windows.h> 

 /*
 *定义一个结构体，命名为student
 *成员有学号、姓名、性别、年龄、成绩
 */ 
struct student{
	int number;
	char name[20];
	char gerden[10];
	int age;
	float mark;
	char ID[20];
	struct student *next;
};

