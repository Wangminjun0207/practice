#include <stdio.h>
int main()
{
unsigned long int a,n=1970,y=1,r=1,s=0,f=0,m=0,n1,y1,r1,s1,f1,m1;
printf("please input a ten digits:\n");
scanf("%ld",&a);
while(a>0)
  {
	if(a>999999999 && a<2000000000)
	{
		n1=a/31104000;
		y1=(a-n1*31104000)/2592000;
		r1=(a-n1*31104000-y1*2592000)/86400;
		s1=(a-n1*31104000-y1*2592000-r1*86400)/3600;
		f1=(a-n1*31104000-y1*2592000-r1*86400-s1*3600)/60;
		m1=a-n1*31104000-y1*2592000-r1*86400-s1*3600-f1*60;
		printf("%d-%d-%d %d:%d:%d\n",n+n1,y+y1,r+r1,s+s1,f+f1,m+m1);
		break;
	}
	else
	{
	printf("please again input a ten digits:\n");
	scanf("%ld",&a);
	}
  }
}
