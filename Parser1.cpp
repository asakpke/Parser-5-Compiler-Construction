// Parser1.cpp: implementation of the CParser class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Parser.h"
#include "Parser1.h"
#include "ParserDlg.h"
//#include "ParserDlg.cpp"
#include "MsgDlg.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CParser::CParser()
{

}

CParser::~CParser()
{

}

//CString CParser::ParseProject(CString sProject)
CString CParser::ParseProject(CString sProject)
{
	m_sProgress = "ParseProject " + sProject + "\r\n";
	//CString sFile = "x"; // = "temp";
	//CString sRetVal = "true";

	//CParserDlg *dlg = (CParserDlg*)GetParent(this);
	//HWND *hwnd = GetParent(this);
	//CObject *obj = GetParent(this);

	//FILE *mfpProject;
	//int nsLen;
	//MessageBox(m_sPjtFile);
// / *
	m_fpProject = fopen(sProject, "r");
	if(m_fpProject == NULL)
	{
		//MessageBox("Project file opening error");
		//CMsgDlg mdlg("Error in opening project file");
		//mdlg.DoModal();
		//return "Error in opening project file";
		return "Error in opening project file";
		//ExitPjt();
	}
// * /	

	while(1)
	{
		m_sFile = GetNextFile();
		//nsLen = sFile.GetLength();
		if(m_sFile == "") // empty mean file not found
			break;
		// process file
		//sRetVal = ParseFile(sFile);

		WinExec("Notepad " + m_sFile, SW_SHOW);

		ParseFile();

		//CMsgDlg mdlg(sRetVal);

		//mdlg.DoModal();		
	}
	fclose(m_fpProject);

	//CString sErrors = "no error found";
	//if(m_sErrors.IsEmpty() == FALSE)
		//sErrors = m_sErrors;


	//CMsgDlg mdlg(sErrors);
	//mdlg.DoModal();
	//m_sProgress = m_sProgress + "END ParseProject " + sProject;

	//return "PROGRESS\r\n" + m_sProgress + "\r\nERRORS\r\n" + sErrors;
	return m_sProgress;
	//return sRetVal; //
} // ParseProject()

		//CMsgDlg mdlg(sFile + " starts with " + sRetVal);
		//CString sMsg = sFile + " starts with " + sRetVal;
		//mdlg.SetMsg(sFile + " starts with " + sRetVal);
		//mdlg.DoModal();
		//mdlg.Create("OK");
		//MessageBox(sFile);

CString CParser::GetNextFile()
{
	CString sFile;
	char ch = 'x';
	int nsLen;

	do
	{
// / *		
		sFile = "";
		while(ch != '=' && ch != EOF)
		{
			ch = getc(m_fpProject);
			nsLen = sFile.GetLength();
			sFile.Insert(nsLen, ch);
		}		
		sFile.Delete(nsLen);
// * /

		if(sFile == "Form" || sFile == "UserControl" || sFile == "PropertyPage" 
			|| sFile == "Designer")
		{ // file which has name after =
			sFile = "";
			while(ch != '\n' && ch != EOF)
			{
				ch = getc(m_fpProject);				
				if(ch != '\n' && ch != EOF)
				{
					nsLen = sFile.GetLength();
					sFile.Insert(nsLen, ch);
				}
			}
			//CAboutDlg adlg("ok form");
			break; // do while(ch != EOF);
		}
		else if(sFile == "Module" || sFile == "Class")
		{ // which has name after = after ' '			
			sFile = "";
			while(ch != ' ' && ch != EOF)
			{
				ch = getc(m_fpProject);
				//if(ch == EOF)
					//break;
			}

			while(ch != EOF)
			{
				ch = getc(m_fpProject);
				if(ch == '\n' || ch == EOF)
					break;				
				nsLen = sFile.GetLength();
				sFile.Insert(nsLen, ch);				
			}
			break; // do while(ch != EOF);
		}
		else
			while(ch != '\n' && ch != EOF)
				ch = getc(m_fpProject);
	} while(ch != EOF);		

	return sFile;
} // GetNextFile

//CString CParser::ParseFile(CString sFile)
void CParser::ParseFile()
{
	m_sProgress = m_sProgress + GetTabs(1) + "ParseFile " 
		+ m_sFile + "\r\n";

	if(OpenFile() == false)			
		return;	
	
	if(SkipFileExtraCode() == false)
		return;

	// now we have read 1st token of source code
	//sRetVal = ParseProcedure();
	CString sToken = m_oToken.GetCurrentToken();

	if(sToken == "Option")
		ParseStatementOption(2);

	sToken = m_oToken.GetCurrentToken();
	if(sToken == "Dim")
		ParseStatementDimList(2);	

	ParseProcedureList();
	m_oToken.CloseSourceFile();
} // ParseFile()

/*
	if(sRetVal != "true")
	{
		m_oToken.CloseSourceFile();
		return sRetVal;
	}
*/
/*
	if(sRetVal != "true")
	{
		m_oToken.CloseSourceFile();
		return sRetVal;
	}
*/
	//CString sRetVal,sRetVal2 = "true";

	//sRetVal = OpenFile(sFile);	
/*
	if(sRetVal != "true")
	{
		m_oToken.CloseSourceFile();
		return sRetVal;
	}
*/
/*	
	while(!m_oToken.IsEOF())
	{
		sRetVal = ParseProcedure();
		if(sRetVal != "true")
			if(sRetVal2 != "true")
				sRetVal2 = sRetVal2 + ", " + sRetVal;
			else
				sRetVal2 = sRetVal;
	}
*/
	

	//return sRetVal2; // "Start = " + sToken;
	//m_sProgress = m_sProgress + "\tEND ParseFile " + m_sFile + "\r\n";

/*
	//FILE *fpFile;
	CString sToken;
	int nsLen;
	char ch = 'x';
	//bool bLineFirstToken = false;
	//bool b = false;
	//CString sRetVal;
	bool bFindAttrib = false;

	m_fpFile = fopen(sFile, "r");
	if(m_fpFile == NULL)	
		return "File: " + sFile + " does not exists";
// / *
	while(1) // skip extra lines i.e file attribute which is not source code
	{		
		sToken = "";
		while(ch != ' ' && ch != EOF)
		{			
			ch = getc(m_fpFile);
			while(ch == '\n')
				ch = getc(m_fpFile);
			nsLen = sToken.GetLength();
			sToken.Insert(nsLen, ch);
		}		
		sToken.Delete(nsLen);
		if(sToken == "Attribute")			
			bFindAttrib = true;
		else if(bFindAttrib == true)// && sToken != "Attribute")
			break;

		while(ch != '\n' && ch != EOF)
			ch = getc(m_fpFile);
		//if(bFindAttrib == true)
			//break;
	}		
	//fclose(m_fpFile);
*/	

//CString CParser::ParseProcedure()
void CParser::ParseProcedure(int nProcedureNo)
{
	int nTabs = 3;
	CString snProcedureNo;
	snProcedureNo.Format("%d",nProcedureNo);
	m_sProgress = m_sProgress + GetTabs(nTabs) 
		+ "ParseProcedure # " + snProcedureNo + "\r\n";
	//CString sRetVal,sRetVal2 = "true";

	//sRetVal = ParseProcedureHead();
	ParseProcedureHead();
	//if(sRetVal != "true")
		//sRetVal2 = sRetVal;

	//sRetVal = ParseProcedureBody();
	ParseProcedureBody();

	// false mean don't ParseProcedurePropertyType 
	// i.e. Let/Get
	ParseProcedureTail(nTabs+1);	
} // ParseProcedure()
/*
	if(sRetVal != "true")
		if(sRetVal2 != "true")
			sRetVal2 = sRetVal2 + ", " + sRetVal;
		else
			sRetVal2 = sRetVal;

	return sRetVal2;
*/
	//m_sProgress = m_sProgress + "\t\tEND ParseProcedure\r\n";

/*
		if(ch == '\n')
		{
			sToken = "";
			bLineFirstToken = true;
			continue;
		}
		//else if(ch == ' ' && bFindStart == true)
			//break;
		else if(ch == ' ') // && sToken == "Attribute")
			bLineFirstToken = false

			//break;
			//bFindStart = true;
		else if(ch != EOF)
		{
			nsLen = sToken.GetLength();
			sToken.Insert(nsLen, ch);
		}

		if(bLineFirstToken == true && sToken != "Attribute")
			break;
*/
/*		
		sFile = "";
		while(ch != EOF)
		{
			ch = getc(m_fpProject);
			if(ch == '\n')
			{
				sFile = "";
				continue;
			}
			else if(ch == '=')
				break;		
			else if(ch != EOF)
			{
				nsLen = sFile.GetLength();
				sFile.Insert(nsLen, ch);
			}
		}
*/

//CString CParser::ParseProcedureHead()
void CParser::ParseProcedureHead()
{
	m_sProgress = m_sProgress + GetTabs(4) 
		+ "ParseProcedureHead\r\n";
	//CString sRetVal,sRetVal2="true";

	//sRetVal = ParseProcedureScope();
	ParseProcedureScope();

	ParseProcedureStatic();

	ParseProcedureType(5);

	ParseID(5);

	ParseProcedureStartBracket();	

	ParseArgumentList();

	ParseProcedureEndBracket();	
	
	ParseProcedureReturn();

} // ParseProcedureHead()
/*	
	if(sRetVal != "true" || sRetVal != "none")
		if(sRetVal2 != "true")
			sRetVal2 = sRetVal2 + ", " + sRetVal;
		else
			sRetVal2 = sRetVal;
*/
	
	//if(sRetVal == "true"
	//sRetVal = ParseProcedureStatic();

	//return sRetVal2;

//CString CParser::ParseProcedureBody()
void CParser::ParseProcedureBody()
{
	int nTabs = 4;
	m_sProgress = m_sProgress + GetTabs(nTabs) 
		+ "ParseProcedureBody\r\n";

	ParseStatementList(nTabs+1);
}
/*
	m_sProgress = m_sProgress + GetTabs(nTabs+1) 
		+ "Token = " + m_oToken.GetCurrentToken() + "\r\n";
	m_sProgress = m_sProgress + GetTabs(nTabs+1) 
		+ "Prev Token = " + m_oToken.GetPrevToken() + "\r\n";
*/
/* 
	/////////////////////////////////////////////////////////////
	//	create function ParseBlock() 
		{
			while(token != "end")
			{	
				ParseStatement();
			}
		}
	/////////////////////////////////////////////////////////////
*/

//CString CParser::ParseProcedureScope()
void CParser::ParseProcedureScope()
{	
	int nTabs = 5;
	// dont' need to read token because we have read 1st token	
	CString sToken = m_oToken.GetCurrentToken();
	m_sProgress = m_sProgress + GetTabs(nTabs) + 
		"ParseProcedureScope " + sToken + "\r\n";
	if(sToken == "Public" || sToken == "Private")
	{
		m_oToken.GetNextToken();
		return;
	}

	if(IsProcedureStatic(sToken) == false && IsProcedureType(sToken) == false)
	{
		//m_sErrors = m_sErrors + "Error in file "+ m_sFile + 
		//		"\'s parsing procedure scope\r\n";
		m_sProgress = m_sProgress + GetTabs(nTabs+1) + GetErrorString();// + "\r\n";

		m_oToken.GetNextToken();

		//mdlg.DoModal();
	}

	//return "Error in parsing procedure scope";
}

void CParser::ParseProcedureStatic()
{
	int nTabs = 5;
	CString sToken = m_oToken.GetCurrentToken();
	m_sProgress = m_sProgress + GetTabs(nTabs) + 
		"ParseProcedureStatic " + sToken + "\r\n";
	if(IsProcedureStatic(sToken))
	{
		m_oToken.GetNextToken();
		return;
	}

	if(IsProcedureType(sToken) == false)
	{
		//m_sErrors = m_sErrors + "Error in file "+ m_sFile + 
		//		"\'s parsing procedure static\r\n";
		m_sProgress = m_sProgress + GetTabs(nTabs+1) + GetErrorString(); // + "\r\n";
		m_oToken.GetNextToken();
	}
	//return "true";
}

void CParser::ParseProcedureType(int nTabs,bool bParseProcedurePropertyType)
{	
	//int nTabs = 5;
	CString sToken = m_oToken.GetCurrentToken();
	m_sProgress = m_sProgress + GetTabs(nTabs) + 
		"ParseProcedureType " + sToken + "\r\n";
	if(IsProcedureType(sToken) == false)
	{	
		//m_sErrors = m_sErrors + "Error in file "+ m_sFile + 
		//		"\'s parsing procedure type\r\n";
		m_sProgress = m_sProgress + GetTabs(nTabs+1) 
			+ GetErrorString(); // + "\r\n";
	}
	else if(sToken == "Property" 
		&& bParseProcedurePropertyType == true)
	{				
		sToken = m_oToken.GetNextToken();		
		ParseProcedurePropertyType();		
	}

	m_oToken.GetNextToken();	
}

void CParser::ParseID(int nTabs)
{	
	CString sToken = m_oToken.GetCurrentToken();
	m_sProgress = m_sProgress + GetTabs(nTabs) + 
		"ParseID " + sToken + "\r\n";
	//ETokenType tt = m_oToken.GetCurrentTokenType();
	//CString stt = m_oToken.GetCurrentTokenTypeInString();
	if(IsID() == false)
		m_sProgress = m_sProgress + GetTabs(nTabs+1) 
			+ GetErrorString();
	//if(tt != ttFunction)		
	//else
		//m_sProgress = m_sProgress + "\t\t\t\t\tNOT function\r\n";
	m_oToken.GetNextToken();
}

// note this function is only valid for current token
bool CParser::IsID()
{
	ETokenType tt = m_oToken.GetCurrentTokenType();

	if(tt == ttFunction || tt == ttNames)
		//|| tt < nTotalReserveWords)
		return true;

	return false;
}

void CParser::ParseArgumentList()
{	
	int nTabs = 5;
	CString sToken = m_oToken.GetCurrentToken();
	m_sProgress = m_sProgress + GetTabs(nTabs) + 
		"ParseArgumentList\r\n";
	ETokenType tt = m_oToken.GetCurrentTokenType();
	CString stt = m_oToken.GetCurrentTokenTypeInString();

	// arg list may be empty
	if(sToken == ")")
		return;

	while(sToken != ")")
	//while(1)
	{
		ParseArgument();

		sToken = m_oToken.GetCurrentToken();

		if(sToken == ")")
			break;
		else if(sToken != ",")		
		{
			m_sProgress = m_sProgress + GetTabs(nTabs+1) +
				GetErrorString();
			while(sToken != ",")
			{
				sToken = m_oToken.GetNextToken();
				if(sToken == ")")
					break;
			}

		}

		// skip Comma
		if(sToken == ",")
			m_oToken.GetNextToken();													
	}

	//return "true";
} // ParseArgumentList()

// EOF
/*
				if(sToken == "")
				{
					m_sProgress = m_sProgress + GetTabs(5) +
					GetErrorString();
					return;
				}
*/				

//m_sProgress = m_sProgress + "\t\t\t\t\tToken      = " + sToken + "\r\n";
		//m_sProgress = m_sProgress + "\t\t\t\t\tToken Type = " + stt + "\r\n";

void CParser::ParseArgument()
{
	int nTabs = 6;
	m_sProgress = m_sProgress + GetTabs(nTabs) + 
		"ParseArgument\r\n";	

	ParseArgumentScope();	

	ParseID(nTabs+1);

	// parse As keyword
	ParseAsKeyword(nTabs+1);	

	ParseDataType(nTabs+1);
}

void CParser::ParseArgumentScope()
{	
	int nTabs = 7;
	CString sToken = m_oToken.GetCurrentToken();
	m_sProgress = m_sProgress + GetTabs(nTabs) + 
		"ParseArgumentScope " + sToken + "\r\n";

	if(sToken == "ByRef" || sToken == "ByVal")
	{
		m_oToken.GetNextToken();
		return;
	}

	if(IsID() == false)
	{
		m_sProgress = m_sProgress + GetTabs(nTabs+1) +
			GetErrorString();

		m_oToken.GetNextToken();
	}
}

void CParser::ParseAsKeyword(int nTabs)
{
	CString sToken = m_oToken.GetCurrentToken();
	m_sProgress = m_sProgress + GetTabs(nTabs) + 
		"ParseAsKeyword " + sToken + "\r\n";

	if(sToken != "As")
		m_sProgress = m_sProgress + GetTabs(nTabs+1) +
			GetErrorString();
		
	m_oToken.GetNextToken();
}

bool CParser::IsAsKeyword(CString sToken)
{
	if(sToken == "As")
		return true;

	return false;
}

void CParser::ParseDataType(int nTabs)
{	
	CString sToken = m_oToken.GetCurrentToken();
	m_sProgress = m_sProgress + GetTabs(nTabs) + 
		"ParseDataType " + sToken;

	if(sToken == "Boolean" || sToken == "Byte" 
			|| sToken == "Currency" || sToken == "Date" 
			|| sToken == "Double" || sToken == "Integer" 
			|| sToken == "Long" || sToken == "Object" 
			|| sToken == "Single" || sToken == "String" 
			|| sToken == "Variant" || IsID() == true)
	{
		sToken = m_oToken.GetNextToken();
		if(sToken == ".")
		{
			sToken = m_oToken.GetNextToken();
			if(IsID() == false)
				m_sProgress = m_sProgress + GetTabs(nTabs+1) +
					GetErrorString();
			else
				m_sProgress = m_sProgress + "." + sToken;

			m_oToken.GetNextToken();
		}
		
		//return;
	}
	else if(sToken == "," || sToken == ")")
	{
		m_sProgress = m_sProgress + GetTabs(nTabs+1) +
			GetErrorString();
		//return;
	}
	else
	{
		m_sProgress = m_sProgress + GetTabs(nTabs+1) +
			GetErrorString();
		m_oToken.GetNextToken();
		//return;
	}	
	m_sProgress = m_sProgress + "\r\n";
}

void CParser::ParseProcedureReturn()
{
	int nTabs = 5;
	CString sToken = m_oToken.GetCurrentToken();
	m_sProgress = m_sProgress + GetTabs(nTabs) + 
		"ParseProcedureReturn\r\n";

	if(IsAsKeyword(sToken) == true)
	{
		ParseAsKeyword(nTabs+1);

		ParseDataType(nTabs+1);
	}	
	//m_oToken.GetNextToken();	
}

bool CParser::OpenFile()
{
	if(m_oToken.OpenSourceFile(m_sFile) == false)
		return false;
	//{		
		//mdlg.DoModal();
		//return sFile + ", file opening error";
	//}

	return true;
}

bool CParser::SkipFileExtraCode()
{
	//CString sStr;
	CString sToken;

	// get the 1st char to identify token type
	m_oToken.GetNextChar();

	// skip extra lines i.e file attribute which is not source code
	while(sToken != "Attribute") 
	{
		sToken = m_oToken.GetNextToken();

		if(sToken.IsEmpty())
		{
			//return "Error in skipping file extra code";
			//m_sErrors = m_sErrors + "Error in skipping file " + m_sFile + 
			//		"\'s extra code\r\n";
			//mdlg.DoModal();
			return false;
		}

		//sStr = sStr + sToken + "\r\n";
	}

	while(sToken == "Attribute") 
	{
		m_oToken.Skip2EndOfLine();
		sToken = m_oToken.GetNextToken();

		// it is EOF so return
		if(sToken.IsEmpty()) 
		{
			//return "Error in skipping file extra code";
			//m_sErrors = m_sErrors + "Error in skipping file " + m_sFile + 
					//"\'s extra code (2)\r\n";
			return false;
		}
	}

	//sStr = sStr + "\r\n\r\n" + sToken;

	//CMsgDlg dlg(sStr);
	//dlg.DoModal();
	return true;
}

bool CParser::IsProcedureStatic(CString sToken)
{
	if(sToken == "Static")
		return true;

	return false;
}

bool CParser::IsProcedureType(CString sToken)
{
	if(sToken == "Sub" || sToken == "Function" || sToken == "Property")
		return true;

	return false;
}

CString CParser::GetErrorString()
{
	//return "ERROR <<<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<<<\r\n";
	return "ERROR <<----------<<<----------<<<----------<<<----------<<<----------<<<----------<<<----------<<<<\r\n";
	//return "ERROR <--------------------<<\r\n";
}

void CParser::ParseProcedureStartBracket()
{
	int nTabs = 5;
	CString sToken = m_oToken.GetCurrentToken();
	m_sProgress = m_sProgress + GetTabs(nTabs) + 
		"ParseProcedureStartBracket " + sToken + "\r\n";
	if(sToken != "(")
		m_sProgress = m_sProgress + GetTabs(nTabs+1) + GetErrorString();

	m_oToken.GetNextToken();
}

void CParser::ParseProcedureEndBracket()
{
	int nTabs = 5;
	CString sToken = m_oToken.GetCurrentToken();
	m_sProgress = m_sProgress + GetTabs(nTabs) + 
		"ParseProcedureEndBracket " + sToken + "\r\n";
	if(sToken != ")")
		m_sProgress = m_sProgress + GetTabs(nTabs+1) + GetErrorString();

	m_oToken.GetNextToken();
}



CString CParser::GetTabs(int nTabs)
{
	CString sTabs;	

	for(int v=0; v < nTabs; v++)
		sTabs = sTabs + "     ";

	return sTabs;
}


void CParser::ParseProcedurePropertyType()
{
	int nTabs = 6;
	CString sToken = m_oToken.GetCurrentToken();

	m_sProgress = m_sProgress + GetTabs(nTabs) 
		+ "ParseProcedurePropertyType " + sToken + "\r\n";

	if(sToken != "Get" && sToken != "Let" )	
		m_sProgress = m_sProgress + GetTabs(nTabs+1) 
			+ GetErrorString(); // + "\r\n";		
}

void CParser::ParseStatementList(int nTabs)
{
	m_sProgress = m_sProgress + GetTabs(nTabs) 
		+ "ParseStatementList\r\n";
	CString sToken = m_oToken.GetCurrentToken();
	while(sToken != "End" && sToken != "Wend" && sToken != "")
	{
		ParseStatement(nTabs+1);
		sToken = m_oToken.GetCurrentToken();
	}
	//m_oToken.GetNextToken();
}

void CParser::ParseStatement(int nTabs)
{
	m_sProgress = m_sProgress + GetTabs(nTabs) 
		+ "ParseStatement\r\n";
	CString sToken = m_oToken.GetCurrentToken();
	ETokenType tt = m_oToken.GetCurrentTokenType();

	if(sToken == "MsgBox")
		ParseStatementMsgBox(nTabs+1);
	else if(sToken == "Dim")
		ParseStatementDim(nTabs+1);
	else if(sToken == "If")
		ParseStatementIf(nTabs+1);
	else if(sToken == "While")
		ParseStatementWhile(nTabs+1);
	else if(tt == ttNames) // it is a it/var name
	{
		//////////////////////////////////////////////////////////
		//
		//
		//	may be converted into parse expr
		//
		//
		////////////////////////////////////////////////////////////
		
		ParseStatementAssignment(nTabs+1);

/*
		m_sProgress = m_sProgress + GetTabs(nTabs+1) 
			+ "ttName " + sToken + "\r\n";

		m_oToken.GetNextToken();		
*/
	}
	else
	{		
		m_sProgress = m_sProgress + GetTabs(nTabs+1) 
			+ "Unknown statement " + sToken + "\r\n"
			+ GetTabs(nTabs+1+1) + GetErrorString(); //"Other statement " + sToken + "\r\n";
		m_oToken.GetNextToken();
	}
	//for
	//do-while	
	//expression
} // ParseStatement()
		// temp code to reach end (of if)
		//m_sProgress = m_sProgress + GetTabs(nTabs+1) 
		//	+ "If statement " + sToken + "\r\n";
		//while(sToken != "End" && sToken !="")		
		//	sToken = m_oToken.GetNextToken();
		// to skip end if
		//m_oToken.GetNextToken();
		//m_oToken.GetNextToken();

void CParser::ParseStatementMsgBox(int nTabs)
{
	CString sToken = m_oToken.GetCurrentToken();
	m_sProgress = m_sProgress + GetTabs(nTabs) 
		+ "ParseStatemenMsgBox " + sToken + "\r\n";

	m_oToken.GetNextToken();	
	ParseStatementMsgBoxPrompt(nTabs+1);	
}

void CParser::ParseStatementMsgBoxPrompt(int nTabs)
{
	CString sToken = m_oToken.GetCurrentToken();
	m_sProgress = m_sProgress + GetTabs(nTabs) 
		+ "ParseStatemenMsgBoxPrompt " + sToken + "\r\n";

	ETokenType tt = m_oToken.GetCurrentTokenType();
	if(tt != ttString && tt != ttNames)
	{
		m_sProgress = m_sProgress + GetTabs(nTabs+1) 
			+ GetErrorString();
	}
	m_oToken.GetNextToken();
}

void CParser::ParseStatementDim(int nTabs)
{
	//Dim Num As Integer
	CString sToken = m_oToken.GetCurrentToken();
	m_sProgress = m_sProgress + GetTabs(nTabs) 
		+ "ParseStatemenDim " + sToken + "\r\n";

	m_oToken.GetNextToken();
	ParseID(nTabs+1);	
	ParseAsKeyword(nTabs+1);
	ParseDataType(nTabs+1);
}

void CParser::ParseStatementIf(int nTabs)
{
	CString sToken = m_oToken.GetCurrentToken();
	m_sProgress = m_sProgress + GetTabs(nTabs) 
		+ "ParseStatemenIf " + sToken + "\r\n";	
/*
If condition Then
	[statements]
[ElseIf condition-n Then
	[elseifstatements] ...
[Else
	[elsestatements]]
End If	
*/	
	m_oToken.GetNextToken(); //skip current if token

	ParseCondition(nTabs+1);

	ParseStatementIfThen(nTabs+1);

	ParseStatementList(nTabs+1);
	//temp code to reach end (of if)		
	//while(sToken != "End" && sToken !="")		
		//sToken = m_oToken.GetNextToken();
	//skip end if
	//m_oToken.GetNextToken(); //skip end
	ParseStatementEnd(nTabs);
	m_oToken.GetNextToken(); //skip if
	
	//parse then
	//parse statement list
		//parse else if list (do it only if time possible)
	//parse end if		
}

void CParser::ParseProcedureList()
{
	int nProcedureNo = 1;
	m_sProgress = m_sProgress + GetTabs(2) 
		+ "ParseProcedureList\r\n";

	CString sToken = m_oToken.GetCurrentToken();	

	while(sToken != "")
	{
		ParseProcedure(nProcedureNo++);
		sToken = m_oToken.GetCurrentToken();		
	}
}

void CParser::ParseCondition(int nTabs)
{	
	m_sProgress = m_sProgress + GetTabs(nTabs) 
		+ "ParseCondition\r\n";

	ETokenType tt = m_oToken.GetCurrentTokenType();
	if(tt == ttNumber)
		ParseNumber(nTabs+1);
	else if(tt == ttString)
		ParseString(nTabs+1);
	else if(tt == ttNames)
		ParseID(nTabs+1);

	CString sToken = m_oToken.GetCurrentToken();
	if(sToken != "Then")
	{
		//parse conditional operators i,e < > == != etc
		ParseConditionalOperator(nTabs+1);


		//parse number/string/id
		ETokenType tt = m_oToken.GetCurrentTokenType();
		if(tt == ttNumber)
			ParseNumber(nTabs+1);
		else if(tt == ttString)
			ParseString(nTabs+1);
		else if(tt == ttNames)
			ParseID(nTabs+1);
	}
}

void CParser::ParseConditionalOperator(int nTabs)
{
	CString sToken = m_oToken.GetCurrentToken();
	m_sProgress = m_sProgress + GetTabs(nTabs) 
		+ "ParseConditionalOperator " + sToken + "\r\n";
	//condOpEqual,condOpLessThanEqual,condOpNotEqual,condOpLessThan
	//,condOpGreaterThanEqual,condOpGreaterThan
	ETokenType tt = m_oToken.GetCurrentTokenType();
	if(tt != condOpEqual && tt != condOpLessThanEqual 
		&& tt != condOpNotEqual && tt != condOpLessThan 
		&& tt != condOpGreaterThanEqual && tt != condOpGreaterThan)
	{
		m_sProgress = m_sProgress + GetTabs(nTabs+1) 
			+ GetErrorString();
	}

	m_oToken.GetNextToken();
}

void CParser::ParseNumber(int nTabs)
{
	CString sToken = m_oToken.GetCurrentToken();
	m_sProgress = m_sProgress + GetTabs(nTabs) 
		+ "ParseNumber " + sToken + "\r\n";

	ETokenType tt = m_oToken.GetCurrentTokenType();
	if(tt != ttNumber)
	{
		m_sProgress = m_sProgress + GetTabs(nTabs+1) 
			+ GetErrorString();
	}

	m_oToken.GetNextToken();
}

void CParser::ParseString(int nTabs)
{
	CString sToken = m_oToken.GetCurrentToken();
	m_sProgress = m_sProgress + GetTabs(nTabs) 
		+ "ParseString" + sToken + "\r\n";

	ETokenType tt = m_oToken.GetCurrentTokenType();
	if(tt != ttString)
	{
		m_sProgress = m_sProgress + GetTabs(nTabs+1) 
			+ GetErrorString();
	}

	m_oToken.GetNextToken();
}

void CParser::ParseStatementIfThen(int nTabs)
{
	CString sToken = m_oToken.GetCurrentToken();
	m_sProgress = m_sProgress + GetTabs(nTabs) 
		+ "ParseStatementIfThen " + sToken + "\r\n";

	if(sToken != "Then")
		m_sProgress = m_sProgress + GetTabs(nTabs+1) 
			+ GetErrorString();

	m_oToken.GetNextToken();
}

void CParser::ParseProcedureTail(int nTabs)
{
	m_sProgress = m_sProgress + GetTabs(nTabs) 
		+ "ParseProcedureTail\r\n";

	ParseStatementEnd(nTabs+1);
	ParseProcedureType(nTabs+1,false);
}

void CParser::ParseStatementEnd(int nTabs)
{
	CString sToken = m_oToken.GetCurrentToken();
	m_sProgress = m_sProgress + GetTabs(nTabs) 
		+ "ParseStatementEnd " + sToken + "\r\n";

	if(sToken != "End")
		m_sProgress = m_sProgress + GetTabs(nTabs+1) 
			+ GetErrorString();

	m_oToken.GetNextToken();
}

void CParser::ParseStatementWhile(int nTabs)
{
	CString sToken = m_oToken.GetCurrentToken();
	m_sProgress = m_sProgress + GetTabs(nTabs) 
		+ "ParseStatemenWhile " + sToken + "\r\n";	

	m_oToken.GetNextToken(); //skip current while token

	ParseCondition(nTabs+1);

	ParseStatementList(nTabs+1);
	
	ParseStatementWend(nTabs);	
}

void CParser::ParseStatementWend(int nTabs)
{
	CString sToken = m_oToken.GetCurrentToken();
	m_sProgress = m_sProgress + GetTabs(nTabs) 
		+ "ParseStatementWend " + sToken + "\r\n";

	if(sToken != "Wend")
		m_sProgress = m_sProgress + GetTabs(nTabs+1) 
			+ GetErrorString();

	m_oToken.GetNextToken();
}

void CParser::ParseStatementDimList(int nTabs)
{	
	m_sProgress = m_sProgress + GetTabs(nTabs) 
		+ "ParseStatementDimList\r\n";
	
	CString sToken = m_oToken.GetCurrentToken();
	while(sToken == "Dim")
	{
		ParseStatementDim(nTabs+1);
		sToken = m_oToken.GetCurrentToken();
	}
}

void CParser::ParseStatementOption(int nTabs)
{	
	CString sToken = m_oToken.GetCurrentToken();
	m_sProgress = m_sProgress + GetTabs(nTabs) 
		+ "ParseStatementOption " + sToken + "\r\n";

	sToken = m_oToken.GetNextToken();

	ParseStatementOptionExplicit(nTabs+1);
}

bool CParser::IsProcedureScope(CString sToken)
{
	if(sToken == "Public" && sToken == "Private")
		return true;

	return false;
}

void CParser::ParseStatementOptionExplicit(int nTabs)
{
	CString sToken = m_oToken.GetCurrentToken();
	m_sProgress = m_sProgress + GetTabs(nTabs) 
		+ "ParseStatementOptionExplicit " + sToken + "\r\n";
	
	if(sToken == "Explicit")
	{
		m_oToken.GetNextToken();
		return;
	}
	else if(sToken == "Dim" || IsProcedureScope(sToken) == true
			|| IsProcedureStatic(sToken) == true
			|| IsProcedureType(sToken) == true)
		m_sProgress = m_sProgress + GetTabs(nTabs+1) 
			+ GetErrorString();
	else
	{
		m_sProgress = m_sProgress + GetTabs(nTabs+1) 
			+ GetErrorString();

		m_oToken.GetNextToken();
	}
}

void CParser::ParseStatementAssignment(int nTabs)
{
	CString sToken = m_oToken.GetCurrentToken();
	m_sProgress = m_sProgress + GetTabs(nTabs) 
		+ "ParseStatementAssignment\r\n";
	

	ParseID(nTabs+1);

	ParseEqualSign(nTabs+1);

	ParseExpression(nTabs+1);
}

void CParser::ParseEqualSign(int nTabs)
{
	CString sToken = m_oToken.GetCurrentToken();
	m_sProgress = m_sProgress + GetTabs(nTabs) 
		+ "ParseEqualSign " + sToken + "\r\n";

	if(sToken == "=")
	{
		m_oToken.GetNextToken();
		return;
	}
	else
	{
		m_sProgress = m_sProgress + GetTabs(nTabs+1) 
			+ GetErrorString();

		ETokenType tt = m_oToken.GetCurrentTokenType();
		
		if(tt != ttFunction || tt != ttNames) //|| tt < nTotalReserveWords)				
			m_oToken.GetNextToken();		
	}
}

void CParser::ParseExpression(int nTabs)
{
	CString sToken = m_oToken.GetCurrentToken();
	m_sProgress = m_sProgress + GetTabs(nTabs) 
		+ "ParseExpression\r\n";

	ParseExpressionTerm(nTabs+1);

	ETokenType tt = m_oToken.GetCurrentTokenType();
	while(tt == opPlusMinus)
	{
		sToken = m_oToken.GetCurrentToken();
		m_sProgress = m_sProgress + GetTabs(nTabs+1) 
			+ "ParseOperatorPlusMinus " + sToken + "\r\n";

		m_oToken.GetNextToken();
		ParseExpressionTerm(nTabs+1);
		tt = m_oToken.GetCurrentTokenType();
	}
}

void CParser::ParseExpressionTerm(int nTabs)
{
	CString sToken = m_oToken.GetCurrentToken();
	m_sProgress = m_sProgress + GetTabs(nTabs) 
		+ "ParseExpressionTerm " + sToken + "\r\n";

	ParseExpressionFactor(nTabs+1);

	ETokenType tt = m_oToken.GetCurrentTokenType();
	while(tt == opMultiplyDivide)
	{
		sToken = m_oToken.GetCurrentToken();
		m_sProgress = m_sProgress + GetTabs(nTabs+1) 
			+ "ParseOperatorMultiplyDivide " + sToken + "\r\n";

		m_oToken.GetNextToken();
		ParseExpressionFactor(nTabs+1);
		tt = m_oToken.GetCurrentTokenType();
	}
}

void CParser::ParseExpressionFactor(int nTabs)
{
	CString sToken = m_oToken.GetCurrentToken();
	ETokenType tt = m_oToken.GetCurrentTokenType();
	m_sProgress = m_sProgress + GetTabs(nTabs) 
		+ "ParseExpressionFactor " + sToken + "\r\n";
	
	if(IsID() == true)
		ParseID(nTabs+1);
	else if(tt == ttNumber)	
		ParseNumber(nTabs+1);	
	else if(tt == ttFunctionStartBracket)
	{
		m_sProgress = m_sProgress + GetTabs(nTabs+1) 
		+ "ParseStartBarcket " + sToken + "\r\n";

		m_oToken.GetNextToken();

		ParseExpression(nTabs+1);

		sToken = m_oToken.GetCurrentToken();

		m_sProgress = m_sProgress + GetTabs(nTabs+1) 
		+ "ParseEndBarcket " + sToken + "\r\n";

		if(sToken != ")")
			m_sProgress = m_sProgress + GetTabs(nTabs+1) 
				+ GetErrorString();

		m_oToken.GetNextToken();
	}	
	//else if(tt == ttFunctionEndBracket)
	//{
		//m_oToken.GetNextToken();
		//return;
	//}
	else
	{
		m_sProgress = m_sProgress + GetTabs(nTabs+1) 
			+ GetErrorString();

		m_oToken.GetNextToken();
	}
}
