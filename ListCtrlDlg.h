#pragma once
#include "afxdialogex.h"


// CListCtrlDlg 대화 상자

class CListCtrlDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CListCtrlDlg)

public:
	CListCtrlDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CListCtrlDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_LISTCtrl };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.


public:

	DECLARE_MESSAGE_MAP()
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	
	
	CListCtrl m_list;
	virtual BOOL OnInitDialog();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnCbnSelchangeCombo1();
	CEdit m_editHakbon;
	CEdit m_editHakwa;
	CComboBox m_comboHaknyon;
	afx_msg void OnBnClickedButtonDelete();
	afx_msg void OnBnClickedButtonAdd();
};
