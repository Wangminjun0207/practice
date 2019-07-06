'''
数据库写入数据的测试
'''
import pymysql

# 打开数据库连接
db = pymysql.connect(host="localhost",user="root",password="wmj123456",db="wmj",charset="utf8")
# 使用cursor()方法获取操作游标
cursor = db.cursor()
# 数据列表
data = [('零基础学Python','Python','79.80')]
try:
	# 执行sql语句，插入多条数据
	sql = "insert into book(name,category,price) values (%s,%s,%s)"
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