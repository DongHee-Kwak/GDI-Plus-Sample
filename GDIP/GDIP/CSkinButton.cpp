#include "pch.h"
#include "CSkinButton.h"


void CSkinButton::DrawBackground(Graphics* pG)
{
	CRect rect;
	GetClientRect(&rect);

	Gdiplus::SolidBrush brush(m_clrBackground);

	pG->FillRectangle(&brush, rect.left, rect.top, rect.right, rect.bottom);
}

void CSkinButton::DrawBorder(Graphics* pG)
{
	CRect rect;
	GetClientRect(&rect);

	Gdiplus::Pen pen(m_clrBroder, 1);
	pG->DrawRectangle(&pen, rect.left, rect.top, rect.Width(), rect.Height());
}

void CSkinButton::DrawText(Graphics* pG)
{
	CRect rect;
	GetClientRect(&rect);

	Gdiplus::FontFamily fontfam(_T("Arial"));
	Gdiplus::Font font(&fontfam, m_fSizeText, Gdiplus::FontStyleRegular, Gdiplus::UnitPixel);

	Gdiplus::StringFormat stringAlign;
	stringAlign.SetAlignment(Gdiplus::StringAlignmentCenter);
	stringAlign.SetLineAlignment(Gdiplus::StringAlignmentCenter);

	Gdiplus::SolidBrush brush(m_clrText);
	
	pG->DrawString(m_strText, m_strText.GetLength(), &font, Gdiplus::RectF((float)rect.left, (float)rect.top, (float)rect.Width(), (float)rect.Height()), &stringAlign, &brush);
}BEGIN_MESSAGE_MAP(CSkinButton, CButton)
ON_WM_PAINT()
END_MESSAGE_MAP()


void CSkinButton::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 여기에 메시지 처리기 코드를 추가합니다.
					   // 그리기 메시지에 대해서는 CButton::OnPaint()을(를) 호출하지 마십시오.
	CRect rect;
	GetClientRect(&rect);

	Graphics mainG(dc.GetSafeHdc());

	Bitmap bmp(rect.Width(), rect.Height());

	Graphics memG(&bmp);

	SolidBrush brush(m_clrBackground);
	memG.FillRectangle(&brush, 0, 0, rect.Width(), rect.Height());

	DrawBackground(&memG);
	DrawBorder(&memG);
	DrawText(&memG);

	mainG.DrawImage(&bmp, 0, 0);
}
