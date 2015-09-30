// ParserDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Parser.h"
#include "ParserDlg.h"
#include "Parser1.h" // my parser class

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
	//CAboutDlg(CString sMsg);
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
// CParserDlg dialog

CParserDlg::CParserDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CParserDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CParserDlg)
	m_sTXT_PROGRESS = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CParserDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CParserDlg)
	DDX_Text(pDX, IDC_TXT_PROGRESS, m_sTXT_PROGRESS);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CParserDlg, CDialog)
	//{{AFX_MSG_MAP(CParserDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_GET_PJT_FILE, OnBtnGetPjtFile)
	ON_COMMAND(IDM_HELP_ABOUTPARSER, OnHelpAboutparser)
	ON_COMMAND(IDM_FILE_EXIT, OnFileExit)
	ON_BN_CLICKED(IDC_BTN_PARSE_PJT, OnBtnParsePjt)
	ON_BN_CLICKED(IDC_BTN_EXIT_PJT, OnBtnExitPjt)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CParserDlg message handlers

BOOL CParserDlg::OnInitDialog()
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
	//m_sTXT_PROGRESS.
	//m_sTXT_PROGRESS.
	//CString str;
	//str.Format("1\r\n2\r\n3");
	//m_sTXT_PROGRESS = "1\r\n2\r\n3";
	//UpdateData(FALSE);
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CParserDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CParserDlg::OnPaint() 
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
HCURSOR CParserDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CParserDlg::OnBtnGetPjtFile() 
{
	// TODO: Add your control notification handler code here
	CFileDialog fdlg(TRUE); 
	
	fdlg.m_ofn.lpstrFilter = "Visual Basic Project File\0*.vbp\0";

	CButton *btn;

	//fdlg.SetDefExt("(*.vbp)");		
//Select_File: // label for come back VB file selection if not selected
	if(fdlg.DoModal() == IDOK)
	{
// / *
		m_sProjectFile = fdlg.GetFileName();

		//WinExec("Notepad " + m_sTXT_PJT_FILE, SW_SHOW);
		//m_sTXT_PJT_FILE = fdlg.GetPathName();
		//m_sTXT_PJT_FILE = fdlg.GetFolderPath();
		//MessageBox("GetFileName = " + fdlg.GetFileName());
		//MessageBox("GetFileTitle = " + fdlg.GetFileTitle());
		//MessageBox("GetPathName = " + fdlg.GetPathName());
		//MessageBox("Folder Path = " + m_sTXT_PJT_FILE);

/*
		if(fdlg.GetFileExt() != "vbp")
		{
			MessageBox("Select only a Visual Basic (VB) project file (*.vbp). Your selected file is " + m_sTXT_PJT_FILE );
			goto Select_File;
			//return;
		}
*/
		
		//MessageBox("Your selected file is " + m_sPjtFile);		
		
		//UpdateData(FALSE);
		btn = (CButton*) GetDlgItem(IDC_BTN_PARSE_PJT);
		btn->EnableWindow(TRUE);
// * /
/*
		m_sPjtFile = fdlg.GetFileName();
		switch(m_sPjtFile)
		{
		case "vbp":
			MessageBox(m_sPjtFile);
			break;
			
		default:
			MessageBox("Select only a VB project file (*.vbp)");
		}
*/
	}
/*
	else
	{
		m_sTXT_PJT_FILE = "";
		btn = (CButton*) GetDlgItem(IDC_BTN_PARSE_PJT);
		btn->EnableWindow(FALSE);
	}
*/
}

void CParserDlg::OnHelpAboutparser() 
{
	// TODO: Add your command handler code here
	CAboutDlg dlgAbout;
	dlgAbout.DoModal();
}

void CParserDlg::OnFileExit() 
{
	// TODO: Add your command handler code here
	ExitPjt();
}

void CParserDlg::OnBtnParsePjt() 
{
	// TODO: Add your control notification handler code here	
	CParser parser;
	//CString sSuccess;

	//sSuccess = parser.ParseProject(m_sTXT_PJT_FILE);
	
	m_sTXT_PROGRESS = parser.ParseProject(m_sProjectFile);
	UpdateData(FALSE);
	

	//if(sSuccess != "true")
		//MessageBox(sSuccess);
	//parser.
/*
	bool bSuccess;

	bSuccess = ParseProject();

	if(bSuccess == false)
		MessageBox("Error in parsing project");
*/
}

void CParserDlg::ExitPjt()
{
	//fclose(m_fp_pjt);	
	//m_fp_pjt = NULL;
	EndDialog(0);
}

void CParserDlg::OnBtnExitPjt() 
{
	// TODO: Add your control notification handler code here
	ExitPjt();
}
/*
CString CParserDlg::GetNextFile()
{
	CString sFile;
	char ch;
	int nsLen;

	do
	{
		sFile = "";
		while(ch != EOF)
		{
			ch = getc(m_fp_pjt);
			if(ch == '\n')
			{
				sFile = "";
				continue;
			}
			if(ch == '=')
				break;		
			if(ch != EOF)
			{
				nsLen = sFile.GetLength();
				sFile.Insert(nsLen, ch);
			}
		}

		if(sFile == "Form" || sFile == "UserControl" || sFile == "PropertyPage" 
			|| sFile == "Designer")
		{ // file which has name after =
			sFile = "";
			while(ch != '\n' && ch != EOF)
			{
				ch = getc(m_fp_pjt);				
				if(ch != '\n' && ch != EOF)
				{
					nsLen = sFile.GetLength();
					sFile.Insert(nsLen, ch);
				}
			}
			break; // do while(ch != EOF);
		}
		else if(sFile == "Module" || sFile == "Class")
		{ // which has name after = after ' '			
			sFile = "";
			while(ch != ' ' && ch != EOF)
			{
				ch = getc(m_fp_pjt);
				//if(ch == EOF)
					//break;
			}

			while(ch != EOF)
			{
				ch = getc(m_fp_pjt);
				if(ch == '\n' || ch == EOF)
					break;				
				nsLen = sFile.GetLength();
				sFile.Insert(nsLen, ch);				
			}
			break; // do while(ch != EOF);
		}
	} while(ch != EOF);	

	return sFile;
}

bool CParserDlg::ParseProject()
{
	CString sFile; // = "temp";
	//int nsLen;
	//MessageBox(m_sPjtFile);
// / *
	m_fp_pjt = fopen(m_sPjtFile, "r");
	if(m_fp_pjt == NULL)
	{
		MessageBox("Project file opening error");
		return false;
		//ExitPjt();
	}
// * /	

	while(1)
	{
		sFile = GetNextFile();
		//nsLen = sFile.GetLength();
		if(sFile == "")
			return true;//break;
		// process file
		MessageBox(sFile);

	}
}

bool CParserDlg::ParseFile(CString sFile)
{

}

CAboutDlg::CAboutDlg(CString sMsg)
{
	//m_sTXT_MSG = sMsg;
	//UpdateData(FALSE);
}
*/
