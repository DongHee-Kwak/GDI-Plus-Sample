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
	Gdiplus::Color m_clrBackground; // ��� ����
	Gdiplus::Color m_clrBroder; // �ܰ��� ����
	Gdiplus::Color m_clrText; // �ؽ�Ʈ ����
	float m_fSizeText; // �ؽ�Ʈ ũ��
	CString m_strText; // ���ڿ�

	void DrawBackground(Gdiplus::Graphics* pG); // ��� �׸���
	void DrawBorder(Gdiplus::Graphics* pG); // �ܰ��� �׸���
	void DrawText(Gdiplus::Graphics* pG); // �ؽ�Ʈ �׸���
public:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnPaint();
};

