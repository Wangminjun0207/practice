/*
 *1、源程序运行时间记录（人工计时即可）； 
 *2、适当修改代码加快运行时间。提供修改后的代码，和修改后的运行时间； 
 *3、（谨慎：请先保存当前所有需要保存的数据）删除代码中的if(p) delete[] p;一
 *    行，再次运行程序，观察内存变化情况，对结果进行分析。如果效果不明显，请加大CTEST数组的大小，加大循环次数后再测试。
 */
 

/*
 *修改前的代码如下 
 
#include <iostream>
using namespace std;
class CTEST
{
	char c[20000];
	int x[6000];
};
CTEST f(CTEST t) {return t;}
int main()
{
	CTEST *p,t1,t2;
	for(int i=0;i<2000;++i)
		for(int j=0;j<2000;++j)
			t2=f(t1);
	for(int i=0;i<20;++i)
	{
		p=new CTEST[10];
		if(p) 
			delete[] p;
	}
}
 */ 
 
/*
 *修改后的代码
 */
 
#include <iostream>
using namespace std;
class CTEST
{
	char c[20000];
	int x[6000];
};
CTEST f(CTEST t) {return t;}
int main()
{
	CTEST *p,t1,t2;
	for(int i=0;i<2000;++i)
		for(int j=0;j<2000;++j)
			t2=t1;
	for(int i=0;i<20;++i)
	{
		p=new CTEST[10];
		if(p) 
			delete[] p;
	}
} 
 
 
