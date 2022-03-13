// ListCtrlDlg.cpp: 구현 파일
//

#include "pch.h"
#include "220306 radioBtns.h"
#include "afxdialogex.h"
#include "ListCtrlDlg.h"




// CListCtrlDlg 대화 상자

IMPLEMENT_DYNAMIC(CListCtrlDlg, CDialogEx)

CListCtrlDlg::CListCtrlDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_LISTCtrl, pParent)
{

}

CListCtrlDlg::~CListCtrlDlg()
{
}

void CListCtrlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Control(pDX, IDC_EDIT_HAKBON, m_editHakbon);
	DDX_Control(pDX, IDC_EDIT_HAKWA, m_editHakwa);
	DDX_Control(pDX, IDC_COMBO_HAKNYON, m_comboHaknyon);
}


BEGIN_MESSAGE_MAP(CListCtrlDlg, CDialogEx)
	ON_WM_CREATE()	
	ON_BN_CLICKED(IDC_BUTTON_DELETE, &CListCtrlDlg::OnBnClickedButtonDelete)
	ON_BN_CLICKED(IDC_BUTTON_ADD, &CListCtrlDlg::OnBnClickedButtonAdd)
END_MESSAGE_MAP()


// CListCtrlDlg 메시지 처리기


int CListCtrlDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialogEx::OnCreate(lpCreateStruct) == -1)
		return -1;


	return 0;
}


BOOL CListCtrlDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_list.SetExtendedStyle(LVS_EX_FULLROWSELECT );
	m_list.SetExtendedStyle(m_list.GetExtendedStyle() | LVS_EX_GRIDLINES);



	CRect rect;
	m_list.GetWindowRect(&rect);

	CString listCols[] = { _T("학번"), _T("학과"), _T("학년") };
	
	int colLen = sizeof(listCols) / sizeof(CString);
	for (int i = 0; i < colLen; i++)
	{
		m_list.InsertColumn(i, listCols[i], LVCFMT_LEFT, rect.Width() / 3);
	}

	m_list.InsertItem(0, _T("200058045"));
	m_list.SetItemText(0, 1, _T("정보통신공학과"));
	m_list.SetItemText(0, 2, _T("4학년"));


	return TRUE;
}


void CListCtrlDlg::OnEnChangeEdit2()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}



void CListCtrlDlg::OnBnClickedButtonAdd()
{
	CString hakbon, hakwa, haknyon;

	m_editHakbon.GetWindowTextW(hakbon);
	m_editHakwa.GetWindowTextW(hakwa);
	
	int comboCur = m_comboHaknyon.GetCurSel();
	m_comboHaknyon.GetLBText(comboCur, haknyon);

	if (hakbon.IsEmpty() || hakwa.IsEmpty() || comboCur == -1)   // 입력에서 빠진 거 없는지 검사
	{
		AfxMessageBox(_T("입력 내용이 맞는지 확인해주세요"));
	}
	else 
	{
		int rowInd = m_list.GetItemCount();
		m_list.InsertItem(rowInd, hakbon);
		m_list.SetItemText(rowInd, 1, hakwa);
		m_list.SetItemText(rowInd, 2, haknyon);

		m_editHakbon.SetWindowTextW(_T(""));
		m_editHakwa.SetWindowTextW(_T(""));
	}
	

}

void CListCtrlDlg::OnBnClickedButtonDelete()
{
	int cnt = m_list.GetItemCount();
	for (int i = cnt - 1; i >= 0; i--)
	{
		if (m_list.GetItemState(i, LVIS_SELECTED))
		{
			m_list.DeleteItem(i);
		}
	}
}

