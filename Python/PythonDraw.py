#PythonDraw.py
import turtle
turtle.setup(650, 350, 200, 200)#引入turtle标准库
turtle.penup()                  #别名turtle.pu()
turtle.forward(-250)            #别名turtle.fd()
turtle.pendown()                #别名turtle.pd()
turtle.pensize(25)
turtle.pencolor("purple")
turtle.setheading(-40)          #别名turtle.seth()
for i in range(4):
	turtle.circle(40, 80)
	turtle.circle(-40, 80)
turtle.circle(40, 80/2)
turtle.fd(40)
turtle.circle(16, 180)
turtle.fd(40 * 2/3)
turtle.done()                   #程序结束后留在窗口
