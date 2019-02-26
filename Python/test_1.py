'''
函数递归调用
'''

def foc(n):
    if n==1 or n==0:
        return 1
    else:
        return n*foc(n-1)

print(foc(10))
