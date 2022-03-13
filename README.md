# MFC-CListCtrl

![image](https://user-images.githubusercontent.com/61898376/158050203-ad21f067-47f2-427b-a328-0f951fc6344f.png)

데이터 추가

![image](https://user-images.githubusercontent.com/61898376/158050351-fb5522ab-b6c8-42a7-9655-1997db7e830a.png)


데이터 삭제

![image](https://user-images.githubusercontent.com/61898376/158050367-4bf81e63-5e3a-4eac-988c-82018f464526.png)

입력 검사 

![image](https://user-images.githubusercontent.com/61898376/158050375-dbce914a-57bc-4c92-9c5e-5c413f45b9db.png)
----

준비


![image](https://user-images.githubusercontent.com/61898376/158050454-c2f6a3e5-5d66-4f15-9cdd-ace2ff7b263d.png)


CListCtrlDlg.cpp 
```
BOOL CListCtrlDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_list.SetExtendedStyle(LVS_EX_FULLROWSELECT );                         // 선택 시 row 전체를 보여줌
	m_list.SetExtendedStyle(m_list.GetExtendedStyle() | LVS_EX_GRIDLINES);  // 배경을 grid



	CRect rect;
	m_list.GetWindowRect(&rect);       // listControl의 크기


	CString listCols[] = { _T("학번"), _T("학과"), _T("학년") };   // column 내용
	
	int colLen = sizeof(listCols) / sizeof(CString);
	for (int i = 0; i < colLen; i++)
	{
		m_list.InsertColumn(i, listCols[i], LVCFMT_LEFT, rect.Width() / 3); // // column 내용 설정
	}

	m_list.InsertItem(0, _T("200058045"));             // sample item 설정 (학번 ) col = 0
	m_list.SetItemText(0, 1, _T("정보통신공학과"));    // sample item 내용 설정 (학과 )  col = 1
	m_list.SetItemText(0, 2, _T("4학년"));			    // sample item 내용 설정 (학년)  col = 2


	return TRUE;
}
```
```
void CListCtrlDlg::OnBnClickedButtonAdd()
{
	CString hakbon, hakwa, haknyon;

	m_editHakbon.GetWindowTextW(hakbon);     // edit 콘트롤 내용을 읽고 저장
	m_editHakwa.GetWindowTextW(hakwa);
	
	int comboCur = m_comboHaknyon.GetCurSel();   // 선택된 combobox 내용을 읽고 저장
	m_comboHaknyon.GetLBText(comboCur, haknyon);

	if (hakbon.IsEmpty() || hakwa.IsEmpty() || comboCur == -1)   // 입력에서 빠진 거 없는지 검사
	{
		AfxMessageBox(_T("입력 내용이 맞는지 확인해주세요"));
	}
	else 
	{
		int rowInd = m_list.GetItemCount();      // 제대로 입력되면 list 콘트롤에 저장
		m_list.InsertItem(rowInd, hakbon);
		m_list.SetItemText(rowInd, 1, hakwa);
		m_list.SetItemText(rowInd, 2, haknyon);

		m_editHakbon.SetWindowTextW(_T(""));
		m_editHakwa.SetWindowTextW(_T(""));
	}
	

}
```
```

void CListCtrlDlg::OnBnClickedButtonDelete()
{
	int cnt = m_list.GetItemCount();      
	for (int i = cnt - 1; i >= 0; i--)    // 모든 항목을 검사하여
	{  
		if (m_list.GetItemState(i, LVIS_SELECTED))  // 선택된 항목을 삭제
		{
			m_list.DeleteItem(i);
		}
	}
}
```


![image](https://user-images.githubusercontent.com/61898376/158050826-61bb1a4f-ede2-40d9-9e3c-f85d95c8f33e.png)
