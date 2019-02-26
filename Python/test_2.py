'''
feibo函数值计算，也是函数的递归调用
feibo(1) = 1
feibo(20 = 1
feibo(n) = feibo(n-1) + feibi(n-2) (n>2)
'''

def feibo(n):
    if n==0 or n==1:
        return 1
    else:
        return feibo(n-1) + feibo(n-2)


print(feibo(5))
for i in range(6,8):
    print(feibo(i)," ",end="")
