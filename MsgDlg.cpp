// MsgDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Parser.h"
#include "MsgDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMsgDlg dialog


CMsgDlg::CMsgDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMsgDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMsgDlg)
	m_sTXT_MSG = _T("");
	//}}AFX_DATA_INIT
}


void CMsgDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMsgDlg)
	DDX_Text(pDX, IDC_TXT_MSG, m_sTXT_MSG);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMsgDlg, CDialog)
	//{{AFX_MSG_MAP(CMsgDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMsgDlg message handlers

// / *
CMsgDlg::CMsgDlg(CString sMsg,CWnd* pParent) // pParent = NULL
	: CDialog(CMsgDlg::IDD, pParent)
{
	CMsgDlg();
	m_sTXT_MSG = sMsg;
	//UpdateData();
}
// * /

void CMsgDlg::SetMsg(CString sMsg)
{
	m_sTXT_MSG = sMsg;
	//UpdateData();
}
