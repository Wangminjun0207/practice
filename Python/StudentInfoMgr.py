# -*- coding:utf-8 -*-

class Student:
    
    ''' 学生类 '''
    def __init__(self,name='',ID='',gender=''):
        self.__name = name      # 姓名
        self.__ID = ID          # 学号
        self.__gender = gender  # 性别
        
    def setInfo(self,name='',ID='',gender=''):
        ''' 设置学生信息 '''
        self.__name = name      # 姓名
        self.__ID = ID          # 学号
        self.__gender = gender  # 性别
        
    def getName(self):
        ''' 获取学生姓名 '''
        return self.__name

    def getID(self):
        ''' 获取学生学号 '''
        return self.__ID
    
    def getGender(self):
        ''' 获取学生性别 '''
        return self.__gender
    
    def printInfo(self):
        ''' 输出学生信息 '''
        print("姓名：" + self.__name,end='')
        print("  学号：" + self.__ID,end='')
        print("  性别：" + self.__gender)

class StudentMgr:
    
    ''' 管理学生信息 '''
    
    def printStuInfo(self,List):
        ''' 输出学生信息 '''
        for index,student in enumerate(List):
            print(index," ",end='')
            student.printInfo()

    def changeStuInfo(self,List):
        ''' 修改学生信息 '''
        self.printStuInfo(List)
        flag = int(input("请选择要修改学生的序号："))
        if flag>=len(List):
            print("您输入的序号不存在,学生信息修改失败！\n")
        else:
            name = input("请输入要修改学生的姓名：")
            ID = input("请输入要修改学生的学号：")
            gender = input("请输入要修改学生的性别：")
            List[flag].setInfo(name,ID,gender)
            print("学生信息修改成功！\n")
            
    def searchStuInfo(self,List):
        ''' 查询学生信息 '''
        print("1.按照姓名查询")
        print("2.按照学号查询")
        print("请输入查询关键字：",end='')
        string = ''
        while True:
            flag = int(input())
            if flag==1:
                string = input("请输入姓名：")
                for student in List:
                    if string==student.getName():
                        student.printInfo()
                        return
                print("查找失败，没有这个学生！")
                break
            elif flag==2:
                string = input("请输入学号：")
                for student in List:
                    if string==student.getID():
                        student.printInfo()
                        return
                print("查找失败，没有这个学生！")
                break
            else:
                print("输入错误，请重新输入：",end='')
                continue
            
    def addStuInfo(self,List):
        ''' 添加学生信息 '''
        name = input("请输入姓名：")
        ID = input("请输入学号：")
        gender = input("请输入性别：")
        student = Student()
        student.setInfo(name,ID,gender)
        List.append(student)
        print("添加学生信息成功！")

    def delStuInfo(self,List):
        print("1.按照姓名删除")
        print("2.按照学号删除")
        print("请输入查询关键字：",end='')
        string = ''
        while True:
            flag = int(input())
            if flag==1:
                string = input("请输入姓名：")
                for student in List:
                    if string==student.getName():
                        List.remove(student)
                        print("删除学生信息成功！\n")
                        return
                print("删除失败，没有这个学生！")
                break
            elif flag==2:
                string = input("请输入学号：")
                for student in List:
                    if string==student.getID():
                        List.remove(student)
                        print("删除学生信息成功！\n")
                        return
                print("删除失败，没有这个学生！")
                break
            else:
                print("输入错误，请重新输入：",end='')
                continue

   
def Menu():
    ''' 菜单界面 '''
    print("=========================================")
    print("     1.初始学生信息       ")
    print("     2.修改学生信息       ")
    print("     3.查询学生信息       ")
    print("     4.输出学生信息       ")
    print("     5.添加学生信息       ")
    print("     6.删除学生信息       ")
    print("     7.退出管理系统       ")
    print("=========================================")
    print("请选择功能：",end='')

def Oprete(studentList):
    ''' 对学生信息进行管理 '''
    
    mgr = StudentMgr()   # 管理员
    
    while True:
        Menu()
        select = int(input())
        if select==7:
            print("您选择退出学生信息管理系统，拜拜！\n")
            break
        elif select==1:
            print("您选择 1.初始学生信息！\n")
            for it in range(5):
                studentList[it].setInfo(nameList[it],IDList[it],genderList[it])
            print("初始化学生信息成功！\n")
            continue
        elif select==2:
            print("您选择 2.修改学生信息！\n")
            mgr.changeStuInfo(studentList)
            continue
        elif select==3:
            print("您选择 3.查询学生信息! \n")
            mgr.searchStuInfo(studentList)
            continue
        elif select==4:
            print("您选择 4.输出学生信息！\n")
            mgr.printStuInfo(studentList)
            continue
        elif select==5:
            print("您选择 5.添加学生信息！\n")
            mgr.addStuInfo(studentList)
            continue
        elif select==6:
            print("您选择 5.删除学生信息！\n")
            mgr.delStuInfo(studentList)
            continue
        else:
            print("您的输入有误，请重新输入！\n")
            continue

################################ 主函数 ####################################
if __name__ == '__main__':
    
    ''' 初始化学生列表 '''
    studentList = []
    for it in range(5):
        studentList.append(Student())

    # 学生姓名列表
    nameList = ["程咬金","诸葛亮","赵子龙","狄仁杰","公孙离"]

    # 学生学号列表
    IDList = ["2017112300","2017112301","2017112302","2017112303","2017112304"]

    # 学生性别列表
    genderList = ["男","男","男","男","女"]

    # 管理学生信息
    Oprete(studentList)
    
