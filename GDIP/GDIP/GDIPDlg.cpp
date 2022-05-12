
// GDIPDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "GDIP.h"
#include "GDIPDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CGDIPDlg 대화 상자



CGDIPDlg::CGDIPDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_GDIP_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGDIPDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CGDIPDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CGDIPDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON4, &CGDIPDlg::OnBnClickedButton4)

END_MESSAGE_MAP()


// CGDIPDlg 메시지 처리기

BOOL CGDIPDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CGDIPDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		// CDialogEx::OnPaint();

		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.
		Graphics g(dc);
		// Alpha 255, 빨간색 두께는 3pixel 인 Pen 생성.
		Gdiplus::Color test(255, 255, 0, 0);
		Pen pen(test, 3);
		Gdiplus::Point start(100, 100);
		Gdiplus::Point end(200, 200);
		// 직선을 (100, 100) 부터 (200, 200) 까지 그리기.
		g.DrawLine(&pen, start, end);

	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CGDIPDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CGDIPDlg::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	
}



void CGDIPDlg::OnBnClickedButton4()
{
	AfxMessageBox(_T("TEST!!"));
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
//https://luckygg.tistory.com/84