file = open("write_test.txt",'w',encoding='utf-8')
str = "身份证号码"
file.write(str)
file.flush()          # 把缓冲区的内容写入文件
str = "622429199702035711"
file.write(str)
str = ["111","222"]
file.writelines(str)  # writelines()方法，写入字符串列表
file.close()
