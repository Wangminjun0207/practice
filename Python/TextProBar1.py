#TextProBarV1.py
##文本进度条 简单的开始
import time
scale = 10
print("------begining------")
for i in range(scale + 1):
    a = '*' * i
    b = '.' * (scale - i)
    c = (i/scale)*100
    print("{: ^3.0f}%[{}->{}]".format(c, a, b))
    time.sleep(0.1)
print("------ending------")
