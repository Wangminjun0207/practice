'''
匿名函数的使用，创建简单的函数
函数本身也是变量，也可以当做函数参数使用
'''
def fun(a, b, opt):
    print("a=",a)
    print("b=",b)
    print("result=",opt(a,b))

fun(1, 2, lambda x,y:x+y)
