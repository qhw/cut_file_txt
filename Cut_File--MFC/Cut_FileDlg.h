// Cut_FileDlg.h : header file
//

#if !defined(AFX_CUT_FILEDLG_H__15C56EA7_38B3_4ACB_8BD3_5D9F34ED7862__INCLUDED_)
#define AFX_CUT_FILEDLG_H__15C56EA7_38B3_4ACB_8BD3_5D9F34ED7862__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCut_FileDlg dialog

class CCut_FileDlg : public CDialog
{
// Construction
public:
	CCut_FileDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCut_FileDlg)
	enum { IDD = IDD_CUT_FILE_DIALOG };
	int		m_long;
	CString	m_str;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCut_FileDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCut_FileDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg void OnLIULAN();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CUT_FILEDLG_H__15C56EA7_38B3_4ACB_8BD3_5D9F34ED7862__INCLUDED_)
