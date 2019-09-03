/*
 *第一个Java程序，遇到了好多问题
 *@2018/7/27
 *@wmj
 */

 //导入软件包，使用Scanner从键盘接收用户输入
import java.util.Scanner;

class Calculator{
	public static void main(String [] args){
		int firstNumber;
		int secondNumber;
		int Sum = 0;
		char operator;
		//创建引用
		Scanner sc = new Scanner(System.in);
		System.out.println("请输入数学表达式(a +/-/*// b):");
		//使用这个方法从键盘读入整形数字
		firstNumber = sc.nextInt();
		//使用这个方法从键盘读入字符，读入字符串用sc.nextLine();
		operator = sc.next().charAt(0);
		secondNumber = sc.nextInt();
		switch(operator)
		{
			case '+':Sum = firstNumber + secondNumber;break;
			case '-':Sum = firstNumber - secondNumber;break;
			case '*':Sum = firstNumber * secondNumber;break;
			case '/':Sum = firstNumber / secondNumber;break;
			default:break;
		}
		System.out.println(firstNumber+" "+operator+" "+secondNumber+" = "+Sum);
	}
}