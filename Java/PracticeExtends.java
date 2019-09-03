/*class之间的继承用关键字extends
 *Java只有单继承，符合一个孩子一个爹
 *@2018/07/27
 *@wmj
 */

class A{
	int firstNumber;
	int secondNumber;
	
	int FunAdd(){
		return firstNumber + secondNumber;
	}
}
//class B继承class A 
class B extends A{
	int FunSub(){
		return firstNumber - secondNumber;
	}
}

class PracticeExtends{
	public static void main(String [] args){
		//基类对象的引用只能访问基类的变量和方法
		B b = new B();
		b.firstNumber = 4;
		b.secondNumber = 2;
		int sum = 0;
		sum = b.FunAdd();
		System.out.println(b.firstNumber+" + "+b.secondNumber+" = "+sum);
		sum = b.FunSub();
		System.out.println(b.firstNumber+" - "+b.secondNumber+" = "+sum);
	}
}