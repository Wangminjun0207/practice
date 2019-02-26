'''
数据库写入数据的测试
'''
import pymysql

# 打开数据库连接
db = pymysql.connect(host="localhost",user="root",password="123456",db="wmj",charset="utf8")
# 使用cursor()方法获取操作游标
cursor = db.cursor()
# 数据列表
data = [('零基础学Python','Python','79.80','2018-5-20'),
		('Python从入门到精通','Python','69.80','2018-6-18'),
		('零基础学PHP','PHP','44.98','2018-9-4'),
		('PHP项目开发实战入门','PHP','88.96','2016-8-11'),
		('零基础学Java','Java','39.98','2010-2-7'),
		]
try:
	# 执行sql语句，插入多条数据
	sql = "insert into book(name,category,price,public_time) values (%s,%s,%s,%s)"
	# 一次插入多条数据
	cursor.executemany(sql,data)
	# 遍历序列插入多条数据
	for dt in data:
		cursor.execute(sql,dt)
	# 提交数据
	db.commit()
except:
	# 发生错误回滚
	db.rollback()
	print("数据库写入失败！")

# 关闭数据库连接
db.close()