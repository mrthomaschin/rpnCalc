
// CalcDlg.h : header file
//

#pragma once
#include "afxwin.h"


// CCalcDlg dialog
class CCalcDlg : public CDialogEx
{
// Construction
public:
	CCalcDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALC_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void On_1_Clicked();
	CEdit m_editCtrl;
	double m_editValue;
	afx_msg void OnBnClickedButtonone();
	afx_msg void OnBnClickedButtontwo();
	afx_msg void OnBnClickedbuttonthree();
	afx_msg void OnBnClickedbuttonfour();
	afx_msg void OnBnClickedbuttonfive();
	afx_msg void OnBnClickedbuttonsix();
	afx_msg void OnBnClickedbuttonseven();
	afx_msg void OnBnClickedbuttoneight();
	afx_msg void OnBnClickedbuttonnine();
	afx_msg void OnBnClickedbuttonzero();
	afx_msg void OnBnClickedbuttonadd();
	afx_msg void OnBnClickedbuttonsubtract();
	afx_msg void OnBnClickedbuttonmultiply();
	afx_msg void OnBnClickedbuttondivide();
	afx_msg void OnBnClickedbuttonenter();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButtondot();

	void DigitAdd(CString symbol);
	void OperationFunction(CString type);
	void moveStack();

	afx_msg void OnBnClickedClearEntry();
	afx_msg void OnBnClickedMemoryPlus();
	afx_msg void OnBnClickedMemoryRecall();
	afx_msg void OnBnClickedMemoryClear();
	afx_msg void OnBnClickedRegCalc();
	afx_msg void OnBnClickedRpnCalc();
};
