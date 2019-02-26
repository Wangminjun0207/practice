##HuangRongWords.py
print("今有物不知其数，三三数之剩二，五五数之剩三，七七数之剩二， 问几何？")
number = int(input("请输入你认为的数："))
if number%3 == 2 and number%5 == 3 and number%7 == 2:
    print(number,"符合今有物不知其数，三三数之剩二，五五数之剩三，七七数之剩二")
