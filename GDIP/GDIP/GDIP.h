
// GDIP.h: PROJECT_NAME 애플리케이션에 대한 주 헤더 파일입니다.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH에 대해 이 파일을 포함하기 전에 'pch.h'를 포함합니다."
#endif

#include "resource.h"		// 주 기호입니다.

#define MAX_BTN 5
#define BTN_ID_1 10001
#define BTN_ID_2 10002
#define BTN_ID_3 10003
#define BTN_ID_4 10004
#define BTN_ID_5 10005

// CGDIPApp:
// 이 클래스의 구현에 대해서는 GDIP.cpp을(를) 참조하세요.
//


class CGDIPApp : public CWinApp
{
public:
	CGDIPApp();

// 재정의입니다.
public:
	virtual BOOL InitInstance();

// 구현입니다.

	DECLARE_MESSAGE_MAP()

public:
	CButton** m_pBtn;
};

extern CGDIPApp theApp;
