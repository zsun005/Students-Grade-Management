; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CAboutDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "StudentScore.h"
LastPage=0

ClassCount=9
Class1=CStudentScoreApp
Class2=CStudentScoreDoc
Class3=CStudentScoreView
Class4=CMainFrame
Class7=CChildFrame
Class9=CAboutDlg

ResourceCount=21
Resource1=IDD_LOGINFRM
Resource2=IDD_STUDENTSCORE_FORM
Resource3=IDR_STUDENTYPE
Resource7=IDD_BMDIALOG
Resource8=IDR_StudentScoreTYPE
Resource9=IDD_EXAMSUBJECTVIEW
Resource10=IDR_MENU2
Resource11=IDR_MENU3
Resource12=IDD_EXAMVIEW
Resource13=IDR_MENU4
Resource14=IDD_SELEXAMNODIALOG
Resource15=IDD_ADDCLASSDIALOG
Resource16=IDD_EXAMSTUDENTVIEW
Resource17=IDD_ADDSTUDENTDIALOG
Resource18=IDR_MENU1
Resource19=IDD_ADDSUBJECTDIALOG
Resource20=IDD_ABOUTBOX
Resource21=IDR_MAINFRAME

[CLS:CStudentScoreApp]
Type=0
HeaderFile=StudentScore.h
ImplementationFile=StudentScore.cpp
Filter=N

[CLS:CStudentScoreDoc]
Type=0
HeaderFile=StudentScoreDoc.h
ImplementationFile=StudentScoreDoc.cpp
Filter=N

[CLS:CStudentScoreView]
Type=0
HeaderFile=StudentScoreView.h
ImplementationFile=StudentScoreView.cpp
Filter=D


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T


[CLS:CChildFrame]
Type=0
HeaderFile=ChildFrm.h
ImplementationFile=ChildFrm.cpp
Filter=M


[CLS:CAboutDlg]
Type=0
HeaderFile=StudentScore.cpp
ImplementationFile=StudentScore.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_144
Command2=ID_FILE_CLOSE
Command3=ID_APP_EXIT
Command4=ID_146
Command5=ID_149
Command6=ID_VIEW_TOOLBAR
Command7=ID_VIEW_STATUS_BAR
Command8=ID_APP_ABOUT
Command9=ID_145
CommandCount=9

[TB:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_146
Command2=ID_149
Command3=ID_APP_EXIT
CommandCount=3

[MNU:IDR_STUDENTYPE]
Type=1
Class=CStudentScoreView
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_CLOSE
Command4=ID_FILE_SAVE
Command5=ID_FILE_SAVE_AS
Command6=ID_FILE_PRINT
Command7=ID_FILE_PRINT_PREVIEW
Command8=ID_FILE_PRINT_SETUP
Command9=ID_FILE_MRU_FILE1
Command10=ID_APP_EXIT
Command11=ID_EDIT_UNDO
Command12=ID_EDIT_CUT
Command13=ID_EDIT_COPY
Command14=ID_EDIT_PASTE
Command15=ID_VIEW_TOOLBAR
Command16=ID_VIEW_STATUS_BAR
Command17=ID_WINDOW_NEW
Command18=ID_WINDOW_CASCADE
Command19=ID_WINDOW_TILE_HORZ
Command20=ID_WINDOW_ARRANGE
Command21=ID_APP_ABOUT
CommandCount=21

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_UNDO
Command5=ID_EDIT_CUT
Command6=ID_EDIT_COPY
Command7=ID_EDIT_PASTE
Command8=ID_EDIT_UNDO
Command9=ID_EDIT_CUT
Command10=ID_EDIT_COPY
Command11=ID_EDIT_PASTE
Command12=ID_NEXT_PANE
Command13=ID_PREV_PANE
CommandCount=13

[DLG:IDD_STUDENTSCORE_FORM]
Type=1
Class=CStudentScoreView
ControlCount=2
Control1=IDC_LIST1,SysListView32,1350633473
Control2=IDC_TREE1,SysTreeView32,1350639618

[MNU:IDR_StudentScoreTYPE]
Type=1
Class=?
Command1=ID_FILE_CLOSE
Command2=ID_VIEW_TOOLBAR
Command3=ID_VIEW_STATUS_BAR
Command4=ID_WINDOW_NEW
Command5=ID_WINDOW_CASCADE
Command6=ID_WINDOW_TILE_HORZ
Command7=ID_WINDOW_ARRANGE
Command8=ID_APP_ABOUT
CommandCount=8

[MNU:IDR_MENU1]
Type=1
Class=?
Command1=ID_LIST142
Command2=ID_138
Command3=ID_139
Command4=ID_Menu
CommandCount=4

[MNU:IDR_MENU2]
Type=1
Class=?
Command1=ID_153
Command2=ID_154
Command3=ID_155
Command4=ID_156
Command5=ID_157
CommandCount=5

[MNU:IDR_MENU3]
Type=1
Class=?
Command1=ID_159
Command2=ID_190
Command3=ID__161
CommandCount=3

[MNU:IDR_MENU4]
Type=1
Class=?
Command1=ID__163
CommandCount=1

[DLG:IDD_LOGINFRM]
Type=1
Class=?
ControlCount=8
Control1=IDC_EDIT1,edit,1350631584
Control2=IDOK,button,1342242817
Control3=IDCANCEL,button,1342242816
Control4=IDC_STATIC,button,1342177287
Control5=IDC_STATIC,static,1342177283
Control6=IDC_STATIC,static,1342308352
Control7=IDC_COMBO1,combobox,1344340226
Control8=IDC_STATIC,static,1342308352

[DLG:IDD_BMDIALOG]
Type=1
Class=?
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDC_BUTTON1,button,1342242816
Control3=IDCANCEL,button,1342242816

[DLG:IDD_EXAMVIEW]
Type=1
Class=?
ControlCount=12
Control1=IDC_STATIC1,static,1342308352
Control2=IDC_EDIT1,edit,1350631552
Control3=IDC_STATIC2,static,1342308352
Control4=IDC_DATETIMEPICKER1,SysDateTimePick32,1342242848
Control5=IDC_STATIC3,static,1342308352
Control6=IDC_COMBO1,combobox,1344340226
Control7=IDC_STATIC,static,1342308353
Control8=IDC_LIST1,SysListView32,1350633473
Control9=IDC_BUTTON1,button,1342242816
Control10=IDC_BUTTON2,button,1342242816
Control11=IDC_BUTTON3,button,1342242816
Control12=IDC_BUTTON4,button,1342242816

[DLG:IDD_SELEXAMNODIALOG]
Type=1
Class=?
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_LIST1,listbox,1352728835

[DLG:IDD_ADDCLASSDIALOG]
Type=1
Class=?
ControlCount=6
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_COMBO1,combobox,1344340226
Control5=IDC_STATIC,static,1342308352
Control6=IDC_LIST1,listbox,1352728843

[DLG:IDD_EXAMSTUDENTVIEW]
Type=1
Class=?
ControlCount=1
Control1=IDC_LIST1,SysListView32,1350633473

[DLG:IDD_ADDSTUDENTDIALOG]
Type=1
Class=?
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_LIST1,listbox,1352728843
Control4=IDC_STATIC,static,1342308352

[DLG:IDD_EXAMSUBJECTVIEW]
Type=1
Class=?
ControlCount=1
Control1=IDC_LIST1,SysListView32,1350633473

[DLG:IDD_ADDSUBJECTDIALOG]
Type=1
Class=?
ControlCount=8
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_COMBO1,combobox,1344340226
Control5=IDC_STATIC,static,1342308352
Control6=IDC_COMBO2,combobox,1344340226
Control7=IDC_STATIC,static,1342308352
Control8=IDC_EDIT1,edit,1350631552

