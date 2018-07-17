
// calculatorDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "calculator.h"
#include "calculatorDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CcalculatorDlg 对话框



CcalculatorDlg::CcalculatorDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CcalculatorDlg::IDD, pParent), mStr(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CcalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, AFX_IDB_CHECKLISTBOX_95, mStr);
}

BEGIN_MESSAGE_MAP(CcalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(AFX_IDB_CHECKLISTBOX_95, &CcalculatorDlg::OnEnChangeIdbChecklistbox95)
	ON_BN_CLICKED(IDC_BUTTON_0, &CcalculatorDlg::OnBnClickedButton0)
	ON_BN_CLICKED(IDC_BUTTON_1, &CcalculatorDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON_2, &CcalculatorDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON_3, &CcalculatorDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON_4, &CcalculatorDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON_5, &CcalculatorDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON_6, &CcalculatorDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON_7, &CcalculatorDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON_8, &CcalculatorDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON_9, &CcalculatorDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTONAdd, &CcalculatorDlg::OnBnClickedButtonadd)
	ON_BN_CLICKED(IDC_BUTTONSub, &CcalculatorDlg::OnBnClickedButtonsub)
	ON_BN_CLICKED(IDC_BUTTONMult, &CcalculatorDlg::OnBnClickedButtonmult)
	ON_BN_CLICKED(IDC_BUTTONDiv, &CcalculatorDlg::OnBnClickedButtondiv)
	ON_BN_CLICKED(IDC_BUTTONEqual, &CcalculatorDlg::OnBnClickedButtonequal)
	ON_BN_CLICKED(IDC_BUTTONClear, &CcalculatorDlg::OnBnClickedButtonclear)
END_MESSAGE_MAP()


// CcalculatorDlg 消息处理程序

BOOL CcalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CcalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CcalculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CcalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CcalculatorDlg::OnEnChangeIdbChecklistbox95()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CcalculatorDlg::OnBnClickedButton0()
{
	UpdateData(TRUE);
	mStr += "0";
	UpdateData(FALSE);
}


void CcalculatorDlg::OnBnClickedButton1()
{
	UpdateData(TRUE);
	mStr += "1";
	UpdateData(FALSE);
}


void CcalculatorDlg::OnBnClickedButton2()
{
	UpdateData(TRUE);
	mStr += "2";
	UpdateData(FALSE);
}


void CcalculatorDlg::OnBnClickedButton3()
{
	UpdateData(TRUE);
	mStr += "3";
	UpdateData(FALSE);
}


void CcalculatorDlg::OnBnClickedButton4()
{
	UpdateData(TRUE);
	mStr += "4";
	UpdateData(FALSE);
}


void CcalculatorDlg::OnBnClickedButton5()
{
	UpdateData(TRUE);
	mStr += "5";
	UpdateData(FALSE);
}


void CcalculatorDlg::OnBnClickedButton6()
{
	UpdateData(TRUE);
	mStr += "6";
	UpdateData(FALSE);
}


void CcalculatorDlg::OnBnClickedButton7()
{
	UpdateData(TRUE);
	mStr += "7";
	UpdateData(FALSE);
}


void CcalculatorDlg::OnBnClickedButton8()
{
	UpdateData(TRUE);
	mStr += "8";
	UpdateData(FALSE);

}


void CcalculatorDlg::OnBnClickedButton9()
{
	UpdateData(TRUE);
	mStr += "9";
	UpdateData(FALSE);
}


void CcalculatorDlg::OnBnClickedButtonadd()
{
	SaveFirstValue();
	mFlag = FLAG_JIA;
}


void CcalculatorDlg::OnBnClickedButtonsub()
{
	SaveFirstValue();
	mFlag = FLAG_JIAN;
}


void CcalculatorDlg::OnBnClickedButtonmult()
{
	SaveFirstValue();
	mFlag = FLAG_CHENG;
}


void CcalculatorDlg::OnBnClickedButtondiv()
{
	SaveFirstValue();
	mFlag = FLAG_CHU;
}


void CcalculatorDlg::OnBnClickedButtonequal()
{
	Calculator();
}


void CcalculatorDlg::OnBnClickedButtonclear()
{
	UpdateData(TRUE);
	mStr = " ";
	mNum1 = 0;
	mNum2 = 0;
	mFlag = FLAG_JIA;
	UpdateData(FALSE);
}

//保存第一个输入值
void CcalculatorDlg::SaveFirstValue()
{
	UpdateData(TRUE);
	mNum1 = atoi(mStr);
	mStr = " ";
	UpdateData(FALSE);
}
//计算结果
void CcalculatorDlg::Calculator() 
{
	UpdateData(TRUE);
	mNum2 = atoi(mStr);
	int result = 0;
	switch (mFlag)
	{
	case FLAG_JIA:						//加  
		result = mNum1 + mNum2;
		break;
	case FLAG_JIAN:						//减 
		result = mNum1 - mNum2;
		break;
	case FLAG_CHENG:					//乘  
		result = mNum1 * mNum2;
		break;
	case FLAG_CHU:						//除  
		if (mNum2 == 0)
		{
			result = mNum1;
		}
		else
		{
			result = mNum1 / mNum2;
		}
		break;
	default:
		break;
	}

	mStr.Format("%d", result);
	UpdateData(FALSE);
	mNum1 = result;
	mNum2 = 0;
}
