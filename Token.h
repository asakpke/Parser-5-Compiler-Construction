// Token.h: interface for the CToken class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TOKEN_H__1C02BD4C_794C_44CC_B4E9_17D78876575B__INCLUDED_)
#define AFX_TOKEN_H__1C02BD4C_794C_44CC_B4E9_17D78876575B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MyHeader.h"

class CToken  
{
public:	
	bool IsLineFirstToken();
	CString GetCurrentTokenTypeInString();
	ETokenType GetCurrentTokenType();
	CString GetPrevToken();
	CString GetCurrentToken();
	bool IsEOF();
	void Skip2EndOfLine();
	CString GetMainToken();
	CToken();
	CToken(CString sSourceFile);
	virtual ~CToken();	
	bool OpenSourceFile(CString sSourceFile);	
	char GetNextChar();
	char GetCurrentChar();
	//ETokenType GetNextToken(CString *psToken,CString *psTokenType);
	CString GetNextToken(ETokenType *pttTokenType=NULL,CString *psTokenType=NULL);
	void CloseSourceFile();

private:		
	bool m_bIsLineFirstToken;
	void FindSymbol();
	
	//int m_nTotalResvWords;
	//POSITION m_posResvWordFindPosition;
	CStringList m_slReserveWords;
	CStringList m_slSymbols;
	CString m_sSourceFile;
	CString m_sNextTokenType;
	CString m_sNextToken;
	CString m_sPrevToken;
	CString m_sMainToken;	//new statement 1st token
	char m_cNextChar;
	FILE *m_fp;
	ETokenType m_eNextTokenType;
	ETokenType m_ePrevTokenType;
	ETokenType m_eMainTokenType;

	
	void GetTTString();
	void GetTTComments();
	void GetTTNames();
	void GetTTNumber();
	void FindResvWord();
	void AddResvWord();
};

#endif // !defined(AFX_TOKEN_H__1C02BD4C_794C_44CC_B4E9_17D78876575B__INCLUDED_)

/* old class code
// Token.h: interface for the CToken class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TOKEN_H__1B17303E_AA4C_4F5C_9852_A8BBDF7232FE__INCLUDED_)
#define AFX_TOKEN_H__1B17303E_AA4C_4F5C_9852_A8BBDF7232FE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CToken  
{
public:
	CToken();
	virtual ~CToken();

};

#endif // !defined(AFX_TOKEN_H__1B17303E_AA4C_4F5C_9852_A8BBDF7232FE__INCLUDED_)
 */
