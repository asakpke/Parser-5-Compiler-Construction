; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CParserDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Parser.h"

ClassCount=4
Class1=CParserApp
Class2=CParserDlg
Class3=CAboutDlg

ResourceCount=5
Resource1=IDD_PARSER_DIALOG
Resource2=IDR_MAINFRAME
Resource3=IDD_MSG_DLG
Resource4=IDD_ABOUTBOX
Class4=CMsgDlg
Resource5=IDM_MNU_PARSER

[CLS:CParserApp]
Type=0
HeaderFile=Parser.h
ImplementationFile=Parser.cpp
Filter=N
LastObject=CParserApp

[CLS:CParserDlg]
Type=0
HeaderFile=ParserDlg.h
ImplementationFile=ParserDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CParserDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=ParserDlg.h
ImplementationFile=ParserDlg.cpp
Filter=D
LastObject=IDC_TXT_MSG
BaseClass=CDialog
VirtualFilter=dWC

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=5
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Control5=IDC_STATIC,static,1342308352

[DLG:IDD_PARSER_DIALOG]
Type=1
Class=CParserDlg
ControlCount=5
Control1=IDC_BTN_GET_PJT_FILE,button,1342242816
Control2=IDC_BTN_PARSE_PJT,button,1476460544
Control3=IDC_BTN_EXIT_PJT,button,1342242816
Control4=IDC_TXT_PROGRESS,edit,1353779204
Control5=IDC_STATIC,static,1342308352

[MNU:IDM_MNU_PARSER]
Type=1
Class=CParserDlg
Command1=IDM_FILE_EXIT
Command2=IDM_HELP_ABOUTPARSER
CommandCount=2

[DLG:IDD_MSG_DLG]
Type=1
Class=CMsgDlg
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_TXT_MSG,edit,1353779204

[CLS:CMsgDlg]
Type=0
HeaderFile=MsgDlg.h
ImplementationFile=MsgDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC

