import pygame
import sys
import random

score = 0

class Bird(object):
    """ 定义一个鸟类 """
    def __init__(self):
        """ 定义初始化方法 """
        self.birdRect = pygame.Rect(65,50,50,50) # 鸟的矩形
        # 定义鸟的三种状态
        self.birdStatus = [pygame.image.load("1.png"),
                           pygame.image.load("2.png"),
                           pygame.image.load("dead.png")]
        self.status = 1   # 默认飞行状态
        self.birdX = 120  # 默认横坐标
        self.birdY = 350  # 默认纵坐标
        self.jump = False # 默认小鸟自动降落
        self.jumpSpeed = 10 # 跳跃高度
        self.gravity = 0    # 重力
        self.dead = False   # 默认小鸟有生命

    def birdUpdate(self):
        if self.jump:
            # 小鸟跳跃
            self.jumpSpeed -= 1          # 速度递减，上升越来越慢
            self.birdY -= self.jumpSpeed # 鸟的Y坐标减小，鸟上升
        else:
            # 小鸟下坠
            # self.gravity += 0.2        # 重力递增，下降越来越快
            self.birdY += self.gravity # 鸟的Y坐标增大，鸟下降
        self.birdRect[1] = self.birdY  # 更改Y的位置

class Pipline(object):
    """ 定义一个管道类 """
    def __init__(self):
        """ 定义初始化方法 """
        self.wallx = 400    # 管道所在x轴坐标
        self.pineUp = pygame.image.load("pipelineUp.png")              # 加载上管道图片
        self.pineDown = pygame.image.load("pipelineDown.png")           # 加载下管道图片

    def updatePipline(self):
        """ 水平移动 """
        self.wallx -= 5  # 管道向左移
        if self.wallx < -80:
            global score   # 分数
            score += 1
            self.wallx = 400

def createMap():
    """ 定义创建地图的方法 """
    screen.fill((255,255,255))    # 填充颜色
    screen.blit(background,(0,0)) # 填入到背景

    # 显示小鸟
    if Bird.dead:         # 撞击管道
        Bird.status = 2
    elif Bird.jump:       # 起飞状态
        Bird.status = 1
    screen. blit(Bird.birdStatus[Bird.status],(Bird.birdX,Bird.birdY)) # 设置小鸟的坐标
    Bird.birdUpdate()             # 鸟移动

    # 显示管道
    screen.blit(Pipline.pineUp,(Pipline.wallx,-100)) # 上管道坐标位置
    screen.blit(Pipline.pineDown,(Pipline.wallx,500))# 下管道坐标位置
    Pipline.updatePipline()    # 管道移动

    # 显示分数
    screen.blit(font.render('Score:'+str(score),-1,(255,255,255)),(100,50)) # 设置颜色及坐标
    
    pygame.display.update()       # 更新显示


def checkDead():
    # 上方管子的矩形位置
    upRect = pygame.Rect(Pipline.wallx,-100,Pipline.pineUp.get_width()-10,Pipline.pineUp.get_height())

    # 下方管子的矩形位置
    downRect = pygame.Rect(Pipline.wallx,500,Pipline.pineDown.get_width()-10,Pipline.pineDown.get_height())

    # 检测小鸟与上下方管子是否碰撞
    if upRect.colliderect(Bird.birdRect) or downRect.colliderect(Bird.birdRect):
        Bird.dead = True
    # 检测小鸟是否飞出边界
    if not 0 <Bird.birdRect[1] < height:
        Bird.dead = True
        return True
    else:
        return False


def getResult():
    final_text1 = "Game Over"
    final_text2 = "You final score is: " +str(score)
    ft1_font = pygame.font.SysFont("Arial",70)        # 设置第一行文本字体
    ft1_surf = font.render(final_text1,1,(242,3,36))  # 设置第一行文本颜色
    ft2_font = pygame.font.SysFont("Arial",50)        # 设置第二行文本字体
    ft2_surf = font.render(final_text2,1,(253,177,6))  # 设置第二行文本颜色

    # 设置第一行文本显示位置
    screen.blit(ft1_surf,[screen.get_width()/2 - ft1_surf.get_width()/2,100])
    # 设置第二行文本显示位置
    screen.blit(ft2_surf,[screen.get_width()/2 - ft2_surf.get_width()/2,200])
    pygame.display.flip()



if __name__ == '__main__':
    pygame.init()                          # 初始化pygame
    pygame.font.init()                     # 初始化字体
    font = pygame.font.SysFont(None,50)    # 设置默认字体大小
    size = width, height = 400, 650        # 设置窗口
    screen = pygame.display.set_mode(size) # 显示窗口
    clock = pygame.time.Clock()            # 设置时钟
    Pipline = Pipline()                    # 实例化管道类
    Bird = Bird()                          # 实例化鸟类
    while True:
        clock.tick(60)
        # 轮循事件
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                sys.exit()
            if (event.type == pygame.KEYDOWN or event.type == pygame.MOUSEBUTTONDOWN)and not Bird.dead:
                Bird.jump = True          # 鸟跳跃
                Bird.gravity = 0          # 重置重力
                Bird.jumpSpeed = 10       # 重置飞行速度

        background = pygame.image.load("background.png") # 加载背景图片
        
        if checkDead():
            getResult()
        else:
            createMap()                       # 绘制地图
    pygame.quit()
