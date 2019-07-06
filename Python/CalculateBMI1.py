#CalBMIv1.py
height  = eval(input("请输入身高（米）:  "))
weight  = eval(input("请输入体重（千克）:  "))
bmi = weight / pow(height, 2)
print("BMI 的数值为: {:.2f}".format(bmi))
who = ""
if bmi <18.5:
    who = "偏瘦"
elif 18.5 <= bmi <25:
    who = "正常"
elif 25<= bmi <30:
    who = "偏胖"
else:
    who = "肥胖"
print("BMI 指标为：国际'{0}'",format(who))
