
// CalcDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Calc.h"
#include "CalcDlg.h"
#include "afxdialogex.h"
#include <array>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

CString string1;
CString string2;
double num1 = 0;
double num2 = 0;
double memory = 0;
int count = 0;
boolean isRpn = false;

std::array<double, 10> stack;
double stackNum = 0;

CString operation;

class CAboutDlg : public CDialogEx
{

public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CCalcDlg dialog



CCalcDlg::CCalcDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CALC_DIALOG, pParent)
	, m_editValue(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalcDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_editCtrl);
	DDX_Text(pDX, IDC_EDIT1, m_editValue);
}

BEGIN_MESSAGE_MAP(CCalcDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(buttonOne, &CCalcDlg::OnBnClickedButtonone)
	ON_BN_CLICKED(ButtonTwo, &CCalcDlg::OnBnClickedButtontwo)
	ON_BN_CLICKED(buttonThree, &CCalcDlg::OnBnClickedbuttonthree)
	ON_BN_CLICKED(buttonFour, &CCalcDlg::OnBnClickedbuttonfour)
	ON_BN_CLICKED(buttonFive, &CCalcDlg::OnBnClickedbuttonfive)
	ON_BN_CLICKED(buttonSix, &CCalcDlg::OnBnClickedbuttonsix)
	ON_BN_CLICKED(buttonSeven, &CCalcDlg::OnBnClickedbuttonseven)
	ON_BN_CLICKED(buttonEight, &CCalcDlg::OnBnClickedbuttoneight)
	ON_BN_CLICKED(buttonNine, &CCalcDlg::OnBnClickedbuttonnine)
	ON_BN_CLICKED(buttonZero, &CCalcDlg::OnBnClickedbuttonzero)
	ON_BN_CLICKED(buttonAdd, &CCalcDlg::OnBnClickedbuttonadd)
	ON_BN_CLICKED(buttonSubtract, &CCalcDlg::OnBnClickedbuttonsubtract)
	ON_BN_CLICKED(buttonMultiply, &CCalcDlg::OnBnClickedbuttonmultiply)
	ON_BN_CLICKED(buttonDivide, &CCalcDlg::OnBnClickedbuttondivide)
	ON_BN_CLICKED(buttonEnter, &CCalcDlg::OnBnClickedbuttonenter)
	ON_BN_CLICKED(IDOK, &CCalcDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &CCalcDlg::OnBnClickedButtondot)
	ON_BN_CLICKED(IDC_BUTTON3, &CCalcDlg::OnBnClickedClearEntry)
	ON_BN_CLICKED(IDC_BUTTON5, &CCalcDlg::OnBnClickedMemoryPlus)
	ON_BN_CLICKED(IDC_BUTTON4, &CCalcDlg::OnBnClickedMemoryRecall)
	ON_BN_CLICKED(IDC_BUTTON2, &CCalcDlg::OnBnClickedMemoryClear)
	ON_BN_CLICKED(IDC_BUTTON6, &CCalcDlg::OnBnClickedRegCalc)
	ON_BN_CLICKED(IDC_BUTTON7, &CCalcDlg::OnBnClickedRpnCalc)
END_MESSAGE_MAP()


// CCalcDlg message handlers

BOOL CCalcDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCalcDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CCalcDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CCalcDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CCalcDlg::OnBnClickedButtonone()
{
	DigitAdd(CString("1")); //Calls function DigitAdd, adds a number string 
	
}


void CCalcDlg::OnBnClickedButtontwo()
{
	DigitAdd(CString("2")); //Calls function DigitAdd, adds a number string 
}


void CCalcDlg::OnBnClickedbuttonthree()
{
	DigitAdd(CString("3")); //Calls function DigitAdd, adds a number string 
}


void CCalcDlg::OnBnClickedbuttonfour()
{
	DigitAdd(CString("4"));
}


void CCalcDlg::OnBnClickedbuttonfive()
{
	DigitAdd(CString("5"));
}


void CCalcDlg::OnBnClickedbuttonsix()
{
	DigitAdd(CString("6"));
}


void CCalcDlg::OnBnClickedbuttonseven()
{
	DigitAdd(CString("7"));
}


void CCalcDlg::OnBnClickedbuttoneight()
{
	DigitAdd(CString("8"));
}


void CCalcDlg::OnBnClickedbuttonnine()
{
	DigitAdd(CString("9"));
}


void CCalcDlg::OnBnClickedbuttonzero()
{
	DigitAdd(CString("0"));
}

void CCalcDlg::OnBnClickedButtondot()
{
	DigitAdd(CString("."));
}
/*
Sets the operation to addition
*/
void CCalcDlg::OnBnClickedbuttonadd()
{
	if (isRpn == false) //Allows function to perform different tasks based on a boolean
	{
		if (count != 0 && num2 != 0)
		{
			OperationFunction(operation);
			SetDlgItemText(IDC_EDIT1, (LPCWSTR)string1);
		}

		operation = "+";
		count++;
	}
	else
	{
		stackNum = stack[0] + stack[1]; //Finds the sum of the bottom two numbers in the stack
		stack[0] = stackNum;

		moveStack(); //Bumps the stack down after the solution has been added to the stack
	}
}

/*
Sets the operation to subtraction
*/
void CCalcDlg::OnBnClickedbuttonsubtract()
{
	if (isRpn == false)
	{
		if (count != 0 && num2 != 0)
		{
			OperationFunction(operation);
			SetDlgItemText(IDC_EDIT1, (LPCWSTR)string1);
		}

		operation = "-";
		count++;
	}
	else
	{
		stackNum = stack[0] - stack[1];
		stack[0] = stackNum;

		moveStack(); //Bumps the stack down after the solution has been added to the stack
	}
}

/*
Sets the operation to multiplication
*/
void CCalcDlg::OnBnClickedbuttonmultiply()
{
	// TODO: Add your control notification handler code here
	if (isRpn == false)
	{
		if (count != 0 && num2 != 0)
		{
			OperationFunction(operation);
			SetDlgItemText(IDC_EDIT1, (LPCWSTR)string1);
		}

		operation = "*";
		count++;
	}
	else
	{
		stackNum = stack[0] * stack[1];
		stack[0] = stackNum;

		moveStack(); //Bumps the stack down after the solution has been added to the stack
	}
}

/*
Sets the operation to division
*/
void CCalcDlg::OnBnClickedbuttondivide()
{
	if (isRpn == false)
	{
		if (count != 0 && num2 != 0)
		{
			OperationFunction(operation);
			SetDlgItemText(IDC_EDIT1, (LPCWSTR)string1);
		}

		operation = "/";
		count++;
	}
	else
	{
		stackNum = stack[1] / stack[0];
		stack[0] = stackNum;

		moveStack(); //Bumps the stack down after the solution has been added to the stack
	}
}
/*
Moves the stack of the array down
*/
void CCalcDlg::moveStack()
{
	for (int a = 1; a < stack.size() - 1; a++)
		stack[a] = stack[a + 1];

	//Display
	string1.Format(_T("%0.2f"), stack[0]);
	SetDlgItemText(IDC_EDIT1, (LPCWSTR)string1);

	string1 = "";
}

/*
Acts as the equal button for a regular calculator, and enters a number into the stack as well
*/
void CCalcDlg::OnBnClickedbuttonenter()
{
	int counter = 0;

	if (isRpn == false)
	{
		OperationFunction(operation);
		SetDlgItemText(IDC_EDIT1, (LPCWSTR)string1);

		num1 = _ttof(string1);
	}
	else
	{
		for (int a = stack.size() - 2; a >= 0; a--)//bumps all values in stack up
			stack[a + 1] = stack[a];

		stack[0] = num1;//adds in the value to the bottom of the stack

		string1 = "";
	}
}
/*
Takes various strings with numbers and concatenates them into one string, then converts it into a double
*/
void CCalcDlg::DigitAdd(CString symbol)//Adds digits to int
{
	if (isRpn == false)
	{
		if (count == 0)//Creates two numbers, both reused each time the user performs and operation
		{
			string1 += symbol;//concatenation
			num1 = _ttof(string1);//string to double conversion

			SetDlgItemText(IDC_EDIT1, (LPCTSTR)string1);
		}
		else
		{
			string2 += symbol;
			num2 = _ttof(string2);

			SetDlgItemText(IDC_EDIT1, (LPCWSTR)string2);
		}
	}
	else
	{
		string1 += symbol;
		num1 = _ttof(string1);

		SetDlgItemText(IDC_EDIT1, (LPCTSTR)string1);
	}
}
/*
Perform operation based on the string sent (for regular calculator)
*/
void CCalcDlg::OperationFunction(CString type)
{
	if (type == "+")
	{
		num1 += num2;
	}
	else
		if (type == "-")
		{
			num1 -= num2;
		}
		else
			if (type == "*")
			{
				num1 = num1 * num2;
			}
			else
				if(type == "/")
				{
					num1 = num1 / num2;
				}

	string1.Format(_T("%0.2f"), num1);

	string2 = "";
	num2 = 0;
}

/*
Resets all values
*/
void CCalcDlg::OnBnClickedOk()//Resets all values
{
	// TODO: Add your control notification handler code here
	if (isRpn == false)
	{
		SetDlgItemInt(IDC_EDIT1, 0);
		count = 0;
		num1 = 0;
		num2 = 0;
		string1 = "";
		string2 = "";
	}
	else
	{
		SetDlgItemInt(IDC_EDIT1, 0);
		num1 = 0;
		string1 = "";
	}
}

/*
Clears only the entry of the user; keeps everything else entered
*/
void CCalcDlg::OnBnClickedClearEntry()
{
	// TODO: Add your control notification handler code here
	if (isRpn == false)
	{
		SetDlgItemInt(IDC_EDIT1, 0);
		if (count == 0)
		{
			num1 = 0;
			string1 = "";
		}
		else
		{
			num2 = 0;
			string2 = "";
		}
	}
	else
	{
		num1 = 0;
		string1 = "";
	}
}


void CCalcDlg::OnBnClickedMemoryPlus()
{
	// TODO: Add your control notification handler code here
	if (isRpn == false)
	{
		if (count == 0)
		{
			memory = num1;
			num1 = 0;

			string1 = "";
			SetDlgItemText(IDC_EDIT1, (LPCWSTR)string1);
		}
		else
		{
			memory = num2;
			num2 = 0;

			string2 = "";
			SetDlgItemText(IDC_EDIT1, (LPCWSTR)string2);
		}
	}
	else
	{
		memory = num1;
		num1 = 0;

		string1 = "";
		SetDlgItemText(IDC_EDIT1, (LPCWSTR)string1);
	}
}


void CCalcDlg::OnBnClickedMemoryRecall()
{
	if (isRpn == false)
	{
		if (count == 0)
		{
			num1 = memory;

			string1.Format(_T("%0.2f"), num1);
			SetDlgItemText(IDC_EDIT1, (LPCWSTR)string1);
		}
		else
		{
			num2 = memory;

			string2.Format(_T("%0.2f"), num2);
			SetDlgItemText(IDC_EDIT1, (LPCWSTR)string2);
		}
	}
	else
	{
		num1 = memory;

		string1.Format(_T("%0.2f"), num1);
		SetDlgItemText(IDC_EDIT1, (LPCWSTR)string1);
	}
}


void CCalcDlg::OnBnClickedMemoryClear()
{
	memory = 0;
}

/*
Type boolean
*/
void CCalcDlg::OnBnClickedRegCalc()
{
	isRpn = false;
}

/*
Typ boolean
*/
void CCalcDlg::OnBnClickedRpnCalc()
{
	isRpn = true;
}
