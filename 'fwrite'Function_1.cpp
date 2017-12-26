//This program can write structure to the file.
#include <stdio.h>
#include <string.h>
struct book_type
{
	char name[10];
	int price;
	char author[10];
}book[2];
int main()
{
	FILE *fp;
	int i;
	if((fp=fopen("C:\\file_date.txt","a"))==NULL)
	{
		printf("can not open the file!\n");
		exit(0);
	}
	for(i=0;i<2;i++)
	{
		scanf("%s%d%s",&book[i].name,&book[i].price,&book[i].author);
		fwrite(&book[i],sizeof(struct book_type),1,fp);

	}
	fclose(fp);
	return 0;
}
