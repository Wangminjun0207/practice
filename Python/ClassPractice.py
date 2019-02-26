class Student:
	'''测试类属性，对象属性以及调用方法'''
	school = "swjtu"                   # 定义类属性
	_major = "computer"                # 定义类的保护属性
	__grade = 2                        # 定义类的私有属性
	def __init__(self, name, age, number):
		self.name = name
		self.age = age
		self.number = number
		self._high = "172CM"           # 定义实例的保护属性
		self.__weight = "70KG"         # 定义实例的私有属性
	
	@property                          # 将方法转换成属性
	def SelfIntroduce(self):
		print("我来自",Student.school,",我叫",self.name,"学号是",self.number,",今年",str(self.age),"岁。")
		
if __name__ == '__main__':
	student = Student("wmj", 20, "2017112381")
	student.SelfIntroduce
# 类的普通属性既可以通过类名调用，也可以通过实例调用
	print(Student.school)
	print(student.school)
# 类的保护属性既可以通过类名调用，也可以通过实例调用
	print(Student._major)
	print(student._major)
# 类的私有属性只能通过实例名._类名__私有属性访问
#	print(Student.__grade)
#	print(student.__grade)
	print(student._Student__grade)
# 实例的保护属性既只能通过实例调用
#	print(Student._high)
	print(student._high)
# 实例的私有属性只能通过实例名._类名__私有属性访问
#	print(student.__weight)
	print(student._Student__weight)