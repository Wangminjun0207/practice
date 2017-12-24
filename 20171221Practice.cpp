#include<stdio.h>
#include<string.h>
void multiply(char a[],char b[],char c[])
{
	int i,j,m,n,sum,t;
	m=strlen(a);
	n=strlen(b);
	for(i=0;i<m;i++)
		a[i]-='0';
	for(j=0;j<n;j++)
		b[j]-='0';
	c[m+n]='\0';
	for(i=m+n-1;i>=0;i--)
	{
		for(int k=n-1;k>=0;k--)
		{
			t=0;
			for(int p=m-1;p>=0;p--)
			{
				sum=0;
				sum=a[p]*b[k];
				c[i]=((c[i]+sum+t)%10+'0');
				t=sum/10;
				i--;
			}
		}
	}
}
int main()
{
	char a[100];
	char b[100];
	char c[200]; 
	gets(a);
	gets(b);
	multiply(a,b,c);
	puts(c);
	return 0;
 } 
