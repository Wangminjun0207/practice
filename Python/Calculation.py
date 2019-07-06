# -*- coding:utf-8 -*-
import wx
class MyFrame(wx.Frame):
    def __init__(self,parent,id):
        wx.Frame.__init__(self,parent,id,title="简单计算器",size=(400,300))

        panel = wx.Panel(self)
        self.title = wx.StaticText(panel,label="请输入操作数和运算符",pos=(140,20))
        self.label_user = wx.StaticText(panel,label="操作数1：",pos=(40,50))
        self.text_user = wx.TextCtrl(panel,pos=(100,50),size=(235,25),style=wx.TE_LEFT)
        self.label_pwd = wx.StaticText(panel,label="操作数2：",pos=(40,90))
        self.text_password = wx.TextCtrl(panel,pos=(100,90),size=(235,25),style=wx.TE_LEFT)
        self.label_sym = wx.StaticText(panel,label="运算符 ：",pos=(40,130))
        self.text_sym = wx.TextCtrl(panel,pos=(100,130),size=(235,25),style=wx.TE_LEFT)
        self.label_result = wx.StaticText(panel,label="运算结果：",pos=(40,170))
        self.text_result = wx.TextCtrl(panel,pos=(100,170),size=(235,25),style=wx.TE_LEFT)

        self.bt_confirm = wx.Button(panel,label="确定",pos=(40,200))
        self.bt_confirm.Bind(wx.EVT_BUTTON,self.OnclickSubmit)
        self.bt_cancel = wx.Button(panel,label="取消",pos=(145,200))
        self.bt_cancel.Bind(wx.EVT_BUTTON,self.OnclickCancel)
        self.bt_clear = wx.Button(panel,label="清除",pos=(247,200))
        self.bt_clear.Bind(wx.EVT_BUTTON,self.OnclickCancel)
		
		
    def OnclickSubmit(self,event):
        message = ""
        result = ""
        username = self.text_user.GetValue()
        password = self.text_password.GetValue()
        sym = self.text_sym.GetValue()
        if username=="" or password == "":
            message = "操作数或者运算符不能为空"
            wx.MessageBox(message)
        elif sym=='+':
            result =  str(int(username)+int(password))
        elif sym=='-':
            result =  str(int(username)-int(password))
        elif sym=='*':
            result =  str(int(username)*int(password))
        elif sym=='/':
            if password=='0':
                message =  "分母不能为零"
                wx.MessageBox(message)
            else:
                result =  str(int(username)/int(password))
        else:
            message =  "目前不能提供这种运算，敬请期待"
            wx.MessageBox(message)
        self.text_result.SetValue(result)

    def OnclickCancel(self,event):
        self.text_user.SetValue("")
        self.text_password.SetValue("")
        self.text_sym.SetValue("")
        self.text_result.SetValue("")

if __name__ == '__main__':
    app = wx.App()
    frame = MyFrame(parent=None,id=-1)
    frame.Show()
    app.MainLoop()
