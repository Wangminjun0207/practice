/*代码不能执行*/ 

#include <iostream>   
using namespace std;  

//股票一 
class Stock1
{
	public:
		Stock(){}
		~Stock(){}
		//卖股票
		void Sell()
		{
			[股票1卖出]
		}
		//买股票
		void Buy()
		{
			[股票1买入]
		} 
}; 

//股票二
class Stock2
{
	//代码类似股票一略 
}; 

//股票三 
class Stock3
{
	//代码类似股票一略 
}; 

//国债一 
class NationalDebt1
{
	//代码类似股票一略 
}; 

//房地产一 
class Realty1
{
	//代码类似股票一略 
}; 

//基金类
class Fund
{
	Stock1 gu1;
	Stock2 gu2;
	Stock3 gu3;
	NationalDebt1 nd1;
	Realty1 rt1;
	public:
		Fund()
		{
			gu1 = new Stock1();
			gu2 = new Stock2();
			gu3 = new Stock3();
			nd1 = new NationalDebt1();
			rt1 = new Realty1();
		}
		void BuyFund()
		{
			gu1.Buy();
			gu2.Buy();
			gu3.Buy();
			nd1.Buy();
			rt1.Buy();
		}
		void SellFund()
		{
			gu1.Sell();
			gu2.Sell();
			gu3.Sell();
			nd1.Sell();
			rt1.Sell();
		}
}; 

int main()
{
	Fund jijin = new Fund();
	//基金购买
	jijin.BuyFund();
	 //基金赎回
	 jijin.BuyFund();
	return 0;
}
