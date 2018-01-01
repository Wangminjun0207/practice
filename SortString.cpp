#include<stdio.h>
#include<string.h>
void sort(char *p[],int n)
{
	int i,j,k;
	char *ps;
	for(i=0;i<n-1;i++)
	{
		k=i;
		for(j=1+i;j<n;j++)
		if(strcmp(p[k],p[j])<0)
		k=j;
		if(k!=j);
		{
			ps=p[k];
			p[k]=p[i];
			p[i]=ps;
		}
	}
}
int main()
{
	char a[10][20];
	char *p[10];
	int n=10;
	printf("ÇëÊäÈëÊ®¸ö×Ö·û´®£º\n");
	for(int i=0;i<n;i++)
	scanf("%s",a[i]);
	for(int i=0;i<n;i++)
	p[i]=a[i];
	sort(p,n);
	printf("ÅÅÐòºóµÄ×Ö·û´®£º\n");
	for(int i=0;i<n;i++)
	puts(p[i]);
	return 0;
}

