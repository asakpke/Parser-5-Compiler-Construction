// Parser.h : main header file for the PARSER application
//

#if !defined(AFX_PARSER_H__32A1F8EC_E552_4841_AA9D_F6EBE3C733D0__INCLUDED_)
#define AFX_PARSER_H__32A1F8EC_E552_4841_AA9D_F6EBE3C733D0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CParserApp:
// See Parser.cpp for the implementation of this class
//

class CParserApp : public CWinApp
{
public:
	CParserApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CParserApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CParserApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PARSER_H__32A1F8EC_E552_4841_AA9D_F6EBE3C733D0__INCLUDED_)
