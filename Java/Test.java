/*
public class Test{
	// 定义多个转义字符并且输出
	public static void main(String[] args){
		char c1 = '\\';      // 反斜杠转义字符
		char c2 = '\'';      // 单引号转义字符
		char c3 = '\"';      // 双引号转义字符
		char c4 = '\u2605';  // 十六进制表示的字符
		char c5 = '\101';    // 八进制表示的字符
		char c6 = '\t';      // 制表符转义字符
		char c7 = '\n';      // 换行符转义字符
		System.out.println("[" + c1 + "]");
		System.out.println("[" + c2 + "]");
		System.out.println("[" + c3 + "]");
		System.out.println("[" + c4 + "]");
		System.out.println("[" + c5 + "]");
		System.out.println("[" + c6 + "]");
		System.out.println("[" + c7 + "]");
	}
} */

/*
import java.util.Scanner;
public class Test{
	// 用boolean类型变量记录登录用户的密码
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in); // 创建扫描器，获取控制台输入的值
		System.out.println("请输入6位密码：");
		int password = sc.nextInt();  // 将用户在控制台输入的数字赋值给整数类型
		boolean result = (password == 924867);
		System.out.println("用户的密码是否正确：" + result);
		sc.close(); // 关闭扫描器
	}
} */


/*
import java.util.Scanner;
import java.util.Arrays;
public class Test{
	// 数组分配
	public static void main(String[] args){
		int arr[] = new int[5];
		Arrays.fill(arr, 8);
		for(int x : arr)
			System.out.println(x);
	}
} */

import java.lang.String;
public class Test{
	// 字符串初始化方法
	public static void main(String[] args){
		String a = "时间就是金钱";           //直接引用字符串常量
		System.out.println("a = " + a);
		String b = new String("nnnn");       //  利构造方法实例
		String c = new String(b);            // 使用已有字符串变量实例
		System.out.println("b = " + b);
		System.out.println("c = " + c);
		char[] charArray = {'t', 'i', 'm', 'e'};
		String d = new String(charArray); // 使用字符数组初始化
		System.out.println("d = " + d);
		char[] charArray2 = {'时','间','就','是','金','钱'};
		String e = new String(charArray2, 4, 2);
		System.out.println("e = " + e);
	}
}