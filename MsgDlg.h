#if !defined(AFX_MSGDLG_H__AA8EB751_50B4_4810_A6D3_AEEB321BC28D__INCLUDED_)
#define AFX_MSGDLG_H__AA8EB751_50B4_4810_A6D3_AEEB321BC28D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MsgDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMsgDlg dialog

class CMsgDlg : public CDialog
{
// Construction
public:
	void SetMsg(CString sMsg);
	CMsgDlg(CString sMsg,CWnd* pParent = NULL);
	CMsgDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CMsgDlg)
	enum { IDD = IDD_MSG_DLG };
	CString	m_sTXT_MSG;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMsgDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CMsgDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MSGDLG_H__AA8EB751_50B4_4810_A6D3_AEEB321BC28D__INCLUDED_)
