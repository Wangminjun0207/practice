import sys
import time
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *
from PyQt5.QtCore import *

class Example(QWidget):
	def __init__(self):
		super().__init__()
		self.initUI()                      # 界面绘制交给initUI方法
	
	def initUI(self):
		self.setGeometry(300,300,1000,300) # 设置窗口的位置和大小
		self.setWindowTitle("马路&汽车")   # 设置窗口的标题
		# pix = QPixmap("E:/github/SRTP/photo/car.jpg")
		# label = QLabel(self)
		# label.setGeometry(50,50,350,200)
		# label.setPixmap(pix.scaled(200,130))
		# label.setPixmap(QPixmap(""))     # 移除label上的图片
		# QApplication.processEvents()     # 动态刷新，必须放在主线程内，自启线程无效果
		for i in range(10):
			pix = QPixmap("E:/github/SRTP/photo/car.jpg")
			label = QLabel(self)
			label.setGeometry(5*i,50,350,200)# 图片大小350x200
			label.setPixmap(pix)
			time.sleep(0.1)                # 延迟0.1S清楚图片(但是没有成功，只会执行最后一步的操作)
			label.setPixmap(QPixmap(""))   # 移除label上的图片

		# label.setGeometry(20,50,350,200)
		# label.setPixmap(pix)
		
		self.show()                        # 显示窗口
		
	def paintEvent(self,e):
		qp = QPainter()
		qp.begin(self)
		self.drawLines(qp)
		qp.end()
		
	def drawLines(self,qp):
		pen = QPen(Qt.black,2,Qt.SolidLine)
		qp.setPen(pen)
		qp.drawLine(0,20,1980,20)
		qp.drawLine(0,280,1980,280)
		
if __name__ == '__main__':
	app = QApplication(sys.argv)           # 创建运用程序和对象
	example = Example()
	sys.exit(app.exec_())