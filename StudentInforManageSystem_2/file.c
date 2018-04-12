 #include "Predefine.h"
 
 void WriteToFile(struct student *head)
 {
 	FILE *fp; // 指向文件的指针 
 	struct student *p;// 指向结构体struct的指针 
 	if(NULL == head)
 	{
 		printf("\nThe list is NULL!\n");
		exit(0);// 退出程序，包含 stdlib.h 头文件	 }
	}
 	if((fp = fopen("student_file.txt","wb"))==NULL) // 打开文件并且进行判断，是否打开 
 	{
 		printf("Can not open the file!\n");
 		exit(0);// 退出程序，包含 stdlib.h 头文件 
	}
	p = head;
	while(p != NULL)
	{
		fwrite(p,sizeof(struct student),1,fp);
		p = p->next;
	}; 
	fclose(fp);
	printf("File write finished!\n");
 }
 
 void ReadFromFile(struct student *head)
 {
 	FILE *fp;
  } 
