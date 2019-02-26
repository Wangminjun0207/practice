with open("read_test.txt",'r') as file:
	# file.seek(2)
	string = file.read(9)
	print(string)
	file.seek(0)
	string = file.readline()  # 读取一行文本内容
	print(string)
	file.seek(0)
	string = file.readlines() # 读取多行文本内容,按照序列输出
	for str in string:
		print(str)
	file.close()