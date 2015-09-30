// Parser1.h: interface for the CParser class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PARSER1_H__323E8B87_B7BD_44E9_9127_02E1FF22423B__INCLUDED_)
#define AFX_PARSER1_H__323E8B87_B7BD_44E9_9127_02E1FF22423B__INCLUDED_

#include "Token.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CParser  
{
public:				
	CString ParseProject(CString sProject);
	CParser();
	virtual ~CParser();

private:
	void ParseExpressionFactor(int nTabs);
	void ParseExpressionTerm(int nTabs);
	void ParseExpression(int nTabs);
	void ParseEqualSign(int nTabs);
	void ParseStatementAssignment(int nTabs);
	void ParseStatementOptionExplicit(int nTabs);
	bool IsProcedureScope(CString sToken);
	void ParseStatementOption(int nTabs);
	void ParseStatementDimList(int nTabs);
	void ParseStatementWend(int nTabs);
	void ParseStatementWhile(int nTabs);
	void ParseStatementEnd(int nTabs);
	void ParseProcedureTail(int nTabs);
	void ParseStatementIfThen(int nTabs);
	void ParseString(int nTabs);
	void ParseNumber(int nTabs);
	void ParseConditionalOperator(int nTabs);
	void ParseCondition(int nTabs);
	void ParseProcedureList();
	void ParseStatementIf(int nTabs);
	void ParseStatementDim(int nTabs);
	void ParseStatementMsgBoxPrompt(int nTabs);
	void ParseStatementMsgBox(int nTabs);
	void ParseStatement(int nTabs);
	void ParseStatementList(int nTabs);
	bool IsAsKeyword(CString sToken);
	void ParseProcedurePropertyType();
	void ParseDataType(int nTabs);
	void ParseAsKeyword(int nTabs);
	CString GetTabs(int nTabs);
	bool IsID();
	void ParseArgumentScope();
	void ParseArgument();
	void ParseProcedureEndBracket();
	void ParseProcedureStartBracket();
	CString GetErrorString();
	CString m_sProgress;
	CString m_sFile;
	//CString m_sErrors;
	bool IsProcedureType(CString sToken);
	bool IsProcedureStatic(CString sToken);
	void ParseArgumentList();
	bool SkipFileExtraCode();
	bool OpenFile();
	void ParseProcedureReturn();
	void ParseID(int nTabs);
	void ParseProcedureType(int nTabs,bool bParseProcedurePropertyType = true);
	void ParseProcedureStatic();
	void ParseProcedureScope();
	CToken m_oToken;
	void ParseProcedure(int nProcedureNo);
	void ParseProcedureBody();
	void ParseProcedureHead();
	void ParseFile();
	FILE *m_fpProject;
	FILE *m_fpFile;
	CString GetNextFile();
};

#endif // !defined(AFX_PARSER1_H__323E8B87_B7BD_44E9_9127_02E1FF22423B__INCLUDED_)
