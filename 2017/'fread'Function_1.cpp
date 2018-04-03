//This program can read structuer to the file.
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
	if((fp=fopen("C:\\file_date.txt","rb"))==NULL)
	{
		printf("can not open the file!\n");
		exit(0);
	}
	for(i=0;i<2;i++)
	{
		
		fread(&book[i],sizeof(struct book_type),1,fp);
		printf("name:%s\tprice:%d\tauthor:%s\n",book[i].name,book[i].price,book[i].author);

	}
	fclose(fp);
	return 0;
}