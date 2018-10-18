# Microsoft Developer Studio Project File - Name="StudentScore" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=StudentScore - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "StudentScore.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "StudentScore.mak" CFG="StudentScore - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "StudentScore - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "StudentScore - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "StudentScore - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "StudentScore - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "StudentScore - Win32 Release"
# Name "StudentScore - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\AddClassDialog.cpp
# End Source File
# Begin Source File

SOURCE=.\AddStudentDialog.cpp
# End Source File
# Begin Source File

SOURCE=.\AddSubjectDialog.cpp
# End Source File
# Begin Source File

SOURCE=.\ADODB.cpp
# End Source File
# Begin Source File

SOURCE=.\BMDialog.cpp
# End Source File
# Begin Source File

SOURCE=.\ChildFrm.cpp
# End Source File
# Begin Source File

SOURCE=.\Exam.cpp
# End Source File
# Begin Source File

SOURCE=.\ExamDoc.cpp
# End Source File
# Begin Source File

SOURCE=.\ExamStudentDoc.cpp
# End Source File
# Begin Source File

SOURCE=.\ExamStudentView.cpp
# End Source File
# Begin Source File

SOURCE=.\ExamSubjectDoc.cpp
# End Source File
# Begin Source File

SOURCE=.\ExamSubjectView.cpp
# End Source File
# Begin Source File

SOURCE=.\ExamView.cpp
# End Source File
# Begin Source File

SOURCE=.\Loginfrm.cpp
# End Source File
# Begin Source File

SOURCE=.\MainFrm.cpp
# End Source File
# Begin Source File

SOURCE=.\SelExamNoDialog.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\StudentScore.cpp
# End Source File
# Begin Source File

SOURCE=.\StudentScore.rc
# End Source File
# Begin Source File

SOURCE=.\StudentScoreDoc.cpp
# End Source File
# Begin Source File

SOURCE=.\StudentScoreView.cpp
# End Source File
# Begin Source File

SOURCE=.\User.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\AddClassDialog.h
# End Source File
# Begin Source File

SOURCE=.\AddStudentDialog.h
# End Source File
# Begin Source File

SOURCE=.\AddSubjectDialog.h
# End Source File
# Begin Source File

SOURCE=.\ADODB.h
# End Source File
# Begin Source File

SOURCE=.\BMDialog.h
# End Source File
# Begin Source File

SOURCE=.\ChildFrm.h
# End Source File
# Begin Source File

SOURCE=.\Exam.h
# End Source File
# Begin Source File

SOURCE=.\ExamDoc.h
# End Source File
# Begin Source File

SOURCE=.\ExamStudentDoc.h
# End Source File
# Begin Source File

SOURCE=.\ExamStudentView.h
# End Source File
# Begin Source File

SOURCE=.\ExamSubjectDoc.h
# End Source File
# Begin Source File

SOURCE=.\ExamSubjectView.h
# End Source File
# Begin Source File

SOURCE=.\ExamView.h
# End Source File
# Begin Source File

SOURCE=.\Loginfrm.h
# End Source File
# Begin Source File

SOURCE=.\MainFrm.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\SelExamNoDialog.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\StudentScore.h
# End Source File
# Begin Source File

SOURCE=.\StudentScoreDoc.h
# End Source File
# Begin Source File

SOURCE=.\StudentScoreView.h
# End Source File
# Begin Source File

SOURCE=.\User.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\Classes1_32x32x16.ico
# End Source File
# Begin Source File

SOURCE=".\res\Key manager.ico"
# End Source File
# Begin Source File

SOURCE=.\res\Razor_32x32x256.ico
# End Source File
# Begin Source File

SOURCE=.\res\StudentScore.ico
# End Source File
# Begin Source File

SOURCE=.\res\StudentScore.rc2
# End Source File
# Begin Source File

SOURCE=.\res\StudentScoreDoc.ico
# End Source File
# Begin Source File

SOURCE=.\res\Toolbar.bmp
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
