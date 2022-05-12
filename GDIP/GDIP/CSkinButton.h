#pragma once
class CSkinButton : public CButton
{
public:
	CSkinButton();
	~CSkinButton();
public :
	void SetColorBackground(int a, int r, int g, int b);
	void SetColorBorder(int a, int r, int g, int b);
	void SetColorText(int a, int r, int g, int b);
	void SetSizeText(float size);
private :
	Gdiplus::Color m_clrBackground; // 배경 색상
	Gdiplus::Color m_clrBroder; // 외곽선 색상
	Gdiplus::Color m_clrText; // 텍스트 색상
	float m_fSizeText; // 텍스트 크기
	CString m_strText; // 문자열

	void DrawBackground(Gdiplus::Graphics* pG); // 배경 그리기
	void DrawBorder(Gdiplus::Graphics* pG); // 외곽선 그리기
	void DrawText(Gdiplus::Graphics* pG); // 텍스트 그리기
public:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnPaint();
};

