# -*- coding:utf-8 -*-
# 定义超市收钱类
class CashSuper:
	'''定义一个收钱的方法，供子类重写'''
	def acceptCash(self, money):
		pass

# 定义打折类
class CashRebate(CashSuper):
	'''按照折扣进行收费'''
	moneyRebate = 0
	def cashRebate(self):
		CashRebate.moneyRebate = float(input("Rebate:"))
	def acceptCash(self, money):
		self.cashRebate()
		return money * CashRebate.moneyRebate

# 定义返现类
class CashReturn(CashSuper):
	'''按照相应返现规则进行返现'''
	moneyCondition = 0
	moneyReturn = 0
	def CashReturn(self):
		CashReturn.moneyCondition = float(input("Condition:"))
		CashReturn.moneyReturn = float(input("Return:"))
	def acceptCash(self, money):
		self.CashReturn()
		self.result = money
		if money >= CashReturn.moneyCondition:
			## 如果应付的钱是相应的倍数，返现也应该翻倍
			self.result = money - (money // CashReturn.moneyCondition) * CashReturn.moneyReturn
		return self.result

# 定义正常收费类		
class CashNormal(CashSuper):
	def acceptCash(self, money):
		return money

# 定义策略模式加工厂模式类
class CashContext:
	'''按照类型进行相应对象的创建'''
	def __init__(self, type):
		if type == "正常收费" or type == "Normal":
			self.cash_accept = CashNormal()
		elif type == "返钱" or type == "Return":
			self.cash_accept = CashReturn()
		elif type == "打折" or type == "Rebate":
			self.cash_accept = CashRebate()
	def getMoney(self, money):
		return self.cash_accept.acceptCash(money)
		
if __name__ == '__main__':
	try:
		type = input("请输入收费类型(打折/Rebate、返钱/Return、正常收费/Normal):")
		if type in ['正常收费','打折','返钱', 'Rebate', 'Return', 'Normal']:
			pass
		else:
			raise TypeError("没有此类收费标准！") # 如果输入的类型不存在，抛出typeerror异常
	except TypeError as t:
		# print(TypeError)   不会输出错误的解释信息
		print(t)
	else:
		cash_context = CashContext(type)
		print(cash_context.getMoney(int(input("请输入收费总额："))))
