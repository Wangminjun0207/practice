
// calculatorDlg.h : 头文件
//

#pragma once


//枚举运算符
enum CALCULATOR_FLAG{
	FLAG_JIA = 0,
	FLAG_JIAN,
	FLAG_CHENG,
	FLAG_CHU,
};

// CcalculatorDlg 对话框
class CcalculatorDlg : public CDialogEx
{
// 构造
public:
	CcalculatorDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_CALCULATOR_DIALOG };
	void SaveFirstValue();		//保存第一个输入值
	void Calculator();			//计算

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeIdbChecklistbox95();
	afx_msg void OnBnClickedButton0();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButtonadd();
	afx_msg void OnBnClickedButtonsub();
	afx_msg void OnBnClickedButtonmult();
	afx_msg void OnBnClickedButtondiv();
	afx_msg void OnBnClickedButtonequal();
	afx_msg void OnBnClickedButtonclear();
	
private:
	//编辑框内的字符串	
	CString mStr;
	//输入的两个值  
	int mNum1;
	int mNum2;
	//运算符号
	CALCULATOR_FLAG mFlag;
};
