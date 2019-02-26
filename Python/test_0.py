'''
测试函数可变参数
'''

def fun(a, b ,*args, **kwargs):
        print("\n\na=",a)
        print("b=",b)
        print("args=",args)
        print("kwargs=",end="")
        for key, value in kwargs.items():
            print(key,"=",value," " ,end="")
			
c = [4, 5, 6]
d = {"m":6, "n":7, "p":8}
e = (3, 4, 5)
# 如果以具体值传入，变量、集合、字典类型会区分开
fun(1, 2, 3, 4, 5, m=6, n=7, p=8)
# 如果不用*标注，会认为是集合的一个元素
fun(1, 2, c, **d)
# 如果用*标注集合，用**标注字典，函数会区分开
fun(1, 2, 3, *c, **d)
fun(1, 2, *e, **d)
# 如果什么都不标注，函数同意认为可变参数是集合的一个元素，包括字典和序列都是一个参数
fun(1, 2, c, d)
fun(1, 2, e, d)
