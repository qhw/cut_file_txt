// Cut_File.h : main header file for the CUT_FILE application
//

#if !defined(AFX_CUT_FILE_H__3994B52B_A8F9_4EF7_A8F7_363FBBDBAF79__INCLUDED_)
#define AFX_CUT_FILE_H__3994B52B_A8F9_4EF7_A8F7_363FBBDBAF79__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCut_FileApp:
// See Cut_File.cpp for the implementation of this class
//

class CCut_FileApp : public CWinApp
{
public:
	CCut_FileApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCut_FileApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCut_FileApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CUT_FILE_H__3994B52B_A8F9_4EF7_A8F7_363FBBDBAF79__INCLUDED_)
