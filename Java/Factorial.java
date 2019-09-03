/*
 *通过for循环求1！+ 2! + ... +20!
 *@2018/7/28
 *@wmj
 */

public class Factorial{
	static long Sum = 0;
	static long Fac = 1;
	public static void main(String [] args){
		for(int i = 1;i <= 20;i++)
		{
			//静态方法引用上文的静态变量，如果是非静态变量，则不能引用
			Fac *= i;
			Sum = Sum + Fac;
		}
		System.out.println("1！+ 2! + ... +20! = "+Sum);
	}
}

//通过两个for循环嵌套求1！+ 2! + ... +20!
/*public class Factorial{
	static long Sum = 0;
	static long Fac = 1;
	public static void main(String [] args){
		for(int i = 1;i <= 20;i++)
		{
			//静态方法引用上文的静态变量，如果是非静态变量，则不能引用
			Fac = 1;
			for(int j = 1;j <= i;j++)
			{
				Fac = Fac * j;
			}
			Sum = Sum + Fac;
		}
		System.out.println("1！+ 2! + ... +20! = "+Sum);
	}
}*/