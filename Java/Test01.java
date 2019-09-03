import java.util.Scanner;
public class Test01{
	public static void main(String[] args){
		int score;
		Scanner sc = new Scanner(System.in);
		System.out.print("请输入成绩：");
		score = sc.nextInt();
		if(score>=90){
			System.out.println("你输入的成绩等级为优！");
		}
		else if(score>=80 && score<90){
			System.out.println("你输入的成绩等级为良！");
		}
		else if(score>=60 && score<80){
			System.out.println("你输入的成绩等级为中！");
		}
		else{
			System.out.println("你输入的成绩等级为差！");
		}
		sc.close();
	}
}
		