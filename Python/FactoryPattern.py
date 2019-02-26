# 定义运算类
class Operation:
	'''包含两个运算数和运算符'''
	_numberA = 0
	_numberB = 0
	def GetResult(self):
		self.result = 0
		return result
		
# 定义加法类，继承运算类
class OperationAdd(Operation):
	# 重写GetResult方法
	def GetResult(self):
		self.result = 0
		result = self._numberA + self._numberB
		return result

# 定义减法类，继承运算类
class OperationSub(Operation):
	# 重写GetResult方法
	def GetResult(self):
		self.result = 0
		result = self._numberA - self._numberB
		return result

# 定义乘法类，继承运算类		
class OperationMul(Operation):
	# 重写GetResult方法
	def GetResult(self):
		self.result = 0
		result = self._numberA * self._numberB
		return result
		
# 定义除法类，继承运算类
class OperationDiv(Operation):
	# 重写GetResult方法
	def GetResult(self):
		self.result = 0
		if Operation._numberB == 0:
			raise ZeroDivisionError("分母不能为零！")
		result = self._numberA - self._numberB
		return result

# 定义简单工厂类	
class Factory:
	def __init__(self):
		pass
	def creatOperation(self, operation):
		if operation == "+":
			self.oper = OperationAdd()
		elif operation == "-":
			self.oper = OperationSub()
		elif operation == "*":
			self.oper = OperationMul()
		else:
			self.oper = OperationDiv()
		return self.oper
		
if __name__ == '__main__':
	try:
		factory = Factory()
		operation = input("请输入运算符：")
		if operation in ['+', '-', '*', '/']:
			pass
		else:
			raise TypeError("操作符输入错误！")
		oper = factory.creatOperation(operation)
		oper._numberA = float(input("请输入第一个运算数："))
		oper._numberB = float(input("请输入第二个运算数："))
		result = oper.GetResult()
		print(result)
	except ZeroDivisionError as zeroDivisionError:
		print("异常1：",zeroDivisionError)
	except TypeError as typeError:
		print("异常2：",typeError)
	except ValueError as valueError:
		print("异常3：",valueError)
	else:
		print("运算正常！")
	finally:
		print("进行了一次运算！")