#include <stdio.h>
 int main()
{
	int a,n=1970,y=1,r=1,s=0,f=0,m=0,n1,y1,r1,s1,f1,m1,flag=1;
	printf("please input a ten digits:\n");
	scanf("%d",&a);
	while(1)
 {
		if(a<2000000000)
	{
	    flag=1;
		n1=a/31104000;//ji suan nian
		y1=(a-n1*31104000)/2592000;//ji suan yue
		r1=(a-n1*31104000-y1*2592000)/86400;//ji suan ri
		s1=(a-n1*31104000-y1*2592000-r1*86400)/3600;//ji suan shi
		f1=(a-n1*31104000-y1*2592000-r1*86400-s1*3600)/60;//ji suan fen
		m1=a-n1*31104000-y1*2592000-r1*86400-s1*3600-f1*60;//ji suan miao 
		printf("%d-%d-%d %d:%d:%d\n",n+n1,y+y1,r+r1,s+s1,f+f1,m+m1);//shu chu xxxx-xx-xx    xx:xx:xx:
	}
    else
	{
		printf("please again input a ten digits:\n");
		scanf("%d",&a);
		flag=0;
	}
	if(flag)
	break;
 } 
}
