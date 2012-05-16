// Cut_FileDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Cut_File.h"
#include "Cut_FileDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCut_FileDlg dialog

CCut_FileDlg::CCut_FileDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCut_FileDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCut_FileDlg)
	m_long = 0;
	m_str = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCut_FileDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCut_FileDlg)
	DDX_Text(pDX, IDC_EDIT1, m_long);
	DDX_Text(pDX, IDC_EDIT, m_str);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCut_FileDlg, CDialog)
	//{{AFX_MSG_MAP(CCut_FileDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(LIULAN, OnLIULAN)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCut_FileDlg message handlers

BOOL CCut_FileDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
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
	m_long = 15;
	m_str = "请选择文件...";
	UpdateData(false);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCut_FileDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CCut_FileDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

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
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CCut_FileDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CCut_FileDlg::OnOK() 
{
	// TODO: Add extra validation here
		char str[20];
		char strtemp[20];
		int count = 1 ;
		UpdateData(true);
	//UpdateData(false);
		CFile file(m_str,CFile::modeRead);
		CFile fileWrite;
        
		char *ch;
		ch = new char[m_long *1024];
		DWORD dwFileLen;
		memset(ch,0,m_long * 1024);
		while( true )
		{
			dwFileLen = file.Read(ch,m_long * 1024);
			if(0 == dwFileLen)
				break;
			itoa(count,strtemp,10);
			//strcat(strtemp,".txt");
			if(count < 10)
			{
				itoa(0,str,10);
			}else
			{
				str[0]='\0';
			}
			strcat(str,strtemp);
			strcat(str,".txt");
			fileWrite.Open(str,CFile::modeCreate  | CFile::modeNoTruncate | CFile::modeWrite);
			count += 1;
			fileWrite.Write(ch,dwFileLen);
			fileWrite.Close();
		};
		delete ch;
	MessageBox("文件分割完毕！");
	CDialog::OnOK();
}

void CCut_FileDlg::OnLIULAN() 
{
	// TODO: Add your control notification handler code here
	CFileDialog fileDlg(true);
	CString str;
	fileDlg.m_ofn.lpstrFilter = "Text Files(*.txt)\0*.txt\0All Files(*.*)\0*.*\0\0";
	fileDlg.m_ofn.lpstrDefExt = "txt";
	if(fileDlg.DoModal() == IDOK)
	{
		m_str = fileDlg.GetFileName();
		UpdateData(false);
		UpdateData(true);
	}
}

