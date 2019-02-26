# -*- coding:utf-8 -*-
class Person:
	def set_name(self, _name):
		self.name = _name
	def show(self):
		print("decoration of " ,self.name, "!\n")

class Finery(Person):
	def decorate(self, _component):
		self.component = _component
	def show(self):
		if self.component != 0:
			self.component.show()
class TShirst(Finery):
	def show(self):
		print("TShirte  ",end="")
		super().show()

class BigTrouser(Finery):
	def show(self):
		print("BigTrouser  ",end="")
		super().show()

class Shoes(Finery):
	def show(self):
		print("shoes  ",end="")
		super().show()
if __name__ == '__main__':
	Mr_w = Person()
	Mr_w.set_name("Mr.W")
	print("the first decorate:\n")
	t_shirst = TShirst()
	shoes = Shoes()
	big_trouser = BigTrouser()
	shoes.decorate(Mr_w)
	t_shirst.decorate(shoes)
	big_trouser.decorate(t_shirst)
	big_trouser.show()
