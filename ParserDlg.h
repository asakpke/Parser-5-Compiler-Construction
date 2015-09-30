// ParserDlg.h : header file
//

#if !defined(AFX_PARSERDLG_H__F062D27D_E750_4477_A750_FD4C69F22D16__INCLUDED_)
#define AFX_PARSERDLG_H__F062D27D_E750_4477_A750_FD4C69F22D16__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CParserDlg dialog

class CParserDlg : public CDialog
{
// Construction
public:	
	//bool ParseFile(CString sFile);
	//bool ParseProject();
	CString GetNextFile();
	void ExitPjt();
	//FILE *m_fp_pjt;
	CParserDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CParserDlg)
	enum { IDD = IDD_PARSER_DIALOG };
	CString	m_sTXT_PROGRESS;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CParserDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CParserDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBtnGetPjtFile();
	afx_msg void OnHelpAboutparser();
	afx_msg void OnFileExit();
	afx_msg void OnBtnParsePjt();
	afx_msg void OnBtnExitPjt();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CString m_sProjectFile;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PARSERDLG_H__F062D27D_E750_4477_A750_FD4C69F22D16__INCLUDED_)
