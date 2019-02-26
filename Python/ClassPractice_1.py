class Fruit:
	def __init__(self, color):
		Fruit.color = color						# 定义类的属性
	def harvest(self, color):
		print("水果是：" + color + "的！")
		print("水果已经收获！")
		print("水果原来是：" + Fruit.color + "的！")
class Apple(Fruit):
	color = "红色"
	def __init__(self, color):
		print("我是苹果！")
		super().__init__(color)
class Orange(Fruit):
	color = "橙色"
	def __init__(self,color):
		print("\n我是橙子！")
		super().__init__(color)
	# 重写harvest()方法代码
	def harvest(self, color):
		print("水果是：" + color + "的！")
		print("橙子已经收获！")
		print("水果原来是：" + Fruit.color + "的！")

if __name__ == '__main__':
	apple = Apple("l绿色")
	apple.harvest(apple.color)
	orange = Orange("1绿色")
	orange.harvest(orange.color)