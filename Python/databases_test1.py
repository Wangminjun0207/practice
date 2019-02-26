'''
从数据库取出数据的测试
'''
import pymysql

# 打开数据库连接
db = pymysql.connect(host="localhost",user="root",password="123456",db="wmj",charset="utf8")
# 使用cursor()方法获取操作游标
cursor = db.cursor()
try:
	# 执行sql语句，读取多条数据
	sql = "select * from book where name = '零基础学Python'"
	# 一次读取多条数据
	cursor.execute(sql)
	# 提交数据
	db.commit()
	# 读取多条数据存入元组
	data = cursor.fetchall()
	# 遍历序列输出多条数据
	for dt in data:
		print(dt)
	# 关闭游标对象
	cursor.close()
except:
	# 发生错误回滚
	db.rollback()
	print("数据库读取失败！")

# 关闭数据库连接
db.close()