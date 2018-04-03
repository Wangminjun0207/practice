#include <stdio.h>
#include <math.h>
int main()
{
     float X1,Y1,X2,Y2,s;
     do
	 {
     scanf("%f%f%f%f",&X1,&Y1,&X2,&Y2);
	 s=sqrt((X1-X2)*(X1-X2)+(Y1-Y2)*(Y1-Y2));
	 printf("%.2f\n",s);
	 }
	  while(X1!='*');
	 return 0;
}
