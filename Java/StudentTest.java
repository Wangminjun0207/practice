/*
 *函数复写(override),this，super的使用
 *this()调用自身的构造函数，this.xxx()调用自身的普通方法
 *super()调用基类的构造函数，super.xxx()调用基类的普通方法
 *@201/7/28
 *@wmj
 */

class Person{
	String name;
	String gerden;
	int age;
	
	Person(){
		
	}
	Person(String name, String gerden, int age){
		//调用自身的无参数构造函数
		this();
		this.name = name;
		this.gerden = gerden;
		this.age = age;
	}
	void Sleep(){
		System.out.println("睡觉");
	}
	void Eat(){
		System.out.println("吃饭");
	}
}

class Student extends Person{
	String grade;
	String address;
	
	Student(String name, String gerden, int age,String grade, String address){
		//调用基类的构造函数
		super(name,gerden,age);
		this.grade = grade;
		this.address = address;
	}
	//函数复写
	void Sleep(){
		System.out.println("sleep");
	}
	void Eat(){
		System.out.println("eat");
	}
	void Study(){
		System.out.println("study");
	}
	void Introduce(){
		//调用复写后的方法
		this.Sleep();
		this.Eat();
		this.Study();
	}
}

class StudentTest{
	public static void main(String [] args){
		Student student = new Student("www","male",18,"colloge","chengdu");
		student.Introduce();
	}
}
