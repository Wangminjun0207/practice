#include <stdio.h>
#include <string.h>
int main()
{
	int m,n,a,i,t;
	m=0,n=0,a=0;
	char ch[100];
	printf("情输入一串字符：\n");
	gets(ch);
	t=strlen(ch);
	for(i=0;i<t-1;i++)
	{
		if(ch[i]>='a' && ch[i]<='z')
		 	{
				m++;
				continue;
			}
		else if(ch[i]>='A' && ch[i]<='Z')
			 {
				n++;
				continue;
		   	 }
			else 
				a++;
			
	}
	printf("大写字母有：%d个\n小写字母有：%d个\n其他字符：%d个\n",n,m,a);
}
