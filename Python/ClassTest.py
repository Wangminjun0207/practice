class Test:
	'''
	测试代码
	'''
	one = 1
	two = 2
	three = 3
	
	def __init__(self):
	##定义特殊方法
		Test.one += 1
		Test.two += 1
		Test.three += 1
		print(Test.one, Test.two, Test.three)
	
	@property   
	##装饰器将一个方法转换成属性
	def test_(self):
	##定义普通方法
		print("这是test()")
		
		
	def _test(self):
	##定义保护方法
		print("这是_test(self)")
		
	def __test(self):
	##定义私有方法
		print("这是__test(self)")
		
test = Test()
test.test_
test._test()
test._Test__test()
test1 = Test()