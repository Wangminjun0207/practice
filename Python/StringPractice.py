str_english = "You must promise me that you'll survive, that you won't give up, no matter what happens, no matter how hopeless."
str_china = "你必须答应我你要活着，你不能放弃，无论发生什么，无论有多绝望。"

print(str_english + '---' + str_china) ##字符串拼接

length = len(str_china)		       ##计算字符串长度
print(str_china+'的长度是：' ,length)
length = len(str_english)
print(str_english+'的长度是：',length)
length = len(str_china.encode())		   ##计算字符串长度(Unicode)
print(str_china+'的长度是(Unicode)：' ,length)
length = len(str_china.encode('gbk'))	   ##计算字符串长度(GBK)
print(str_china+'的长度是(GBK)：' ,length)

print(str_china[2])					   ##截取第三个字符
print(str_china[:5])                   ##截取前五个字符
print(str_china[5:7])                  ##截取第六个到第七个字符
print(str_china[7:])                   ##截取第八个以后的字符
print(str_china[2:-1:3])               ##截取第三个以后的字符按照步长为3切片

str = str_english.split(',')           ##用‘，’分割字符串
print(str)

num = str_english.count('me', 0, -1)   ##统计字符串出现的次数
print(num)

num = str_english.find('me', 0, -1)    ##检索是否包含子字符串
print(num)

num = str_english.rfind('me', 0, -1)   ##检索是否包含子字符串(从右往左）
print(num)

temp = str_english.startswith('You', 0, -1)   ##判断是否以子字符串开头
print(temp)

temp = str_english.endswith('YOU')     ##判断是否以子字符串结尾
print(temp)

print("转换为大写字母：" + str_english) ##转换为大写字母
print("转换为小些字母：" + str_english) ##转换为小写字母

str_english = '##' + str_english + '**'
str = str_english.strip('*#')           ##去除字符串首尾特定字符
print(str)

str = str_english.lstrip('*#')           ##去除字符串首特定字符
print(str)

str = str_english.rstrip('*#')           ##去除字符串尾特定字符
print(str)
