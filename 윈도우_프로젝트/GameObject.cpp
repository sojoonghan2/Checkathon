#include "GameObject.h"

void CBackgroundObject::LoadBit(int m_bit_num, HINSTANCE m_hInstance, int m_i_bit) {
	m_bit = LoadBitmap(m_hInstance, MAKEINTRESOURCE(m_i_bit));
}

void CBackgroundObject::ReleaseBits() {
	DeleteObject(m_bit);
}

void CBackgroundObject::Draw(HDC m_memdcFront, HDC m_memdcBack, HBITMAP oldBit2) {
	oldBit2 = (HBITMAP)SelectObject(m_memdcBack, m_bit);
	StretchBlt(m_memdcFront, 0, 0, WINDOWLENGTH, WINDOWWIDTH, m_memdcBack, 0, 0, 300, 225, SRCCOPY);
}

void CGameObject::LoadBit(int m_bit_num, HINSTANCE m_hInstance, std::vector<int> m_i_bit) {
	m_bit = new HBITMAP[m_bit_num];
	for (int i{}; i < m_bit_num; ++i) {
		m_bit[i] = LoadBitmap(m_hInstance, MAKEINTRESOURCE(m_i_bit[i]));
	}
}

void CGameObject::LoadBit(int m_bit_num, HINSTANCE m_hInstance, int m_i_bit) {
	m_bit = new HBITMAP[m_bit_num];
	for (int i{}; i < m_bit_num; ++i) {
		m_bit[i] = LoadBitmap(m_hInstance, MAKEINTRESOURCE(m_i_bit));
	}
}

void CGameObject::ReleaseBits() {
	DeleteObject(m_bit);
	delete m_bit;
}

void CGameObject::Animate(float fElapsedTime) {

}

void CGameObject::Draw(HDC m_memdcFront, HDC m_memdcBack, HBITMAP oldBit2) {
	TransparentBlt(m_memdcFront, m_xPos, m_yPos, 100, 100, m_memdcBack, 0, 0, 100, 100, RGB(255, 255, 255));
}

void CGameObject::DrawBoundBox(HDC m_memdcFront, HDC m_memdcBack, HBITMAP oldBit2) {
	UpdateBoundBox();
	MoveToEx(m_memdcFront, m_Bbox.left, m_Bbox.top, NULL);
	LineTo(m_memdcFront, m_Bbox.right, m_Bbox.top);
	LineTo(m_memdcFront, m_Bbox.right, m_Bbox.bottom);
	LineTo(m_memdcFront, m_Bbox.left, m_Bbox.bottom);
	LineTo(m_memdcFront, m_Bbox.left, m_Bbox.top);
}

void CGameObject::UpdateBoundBox() {

}

void CUIObject::Draw(HDC m_memdcFront, HDC m_memdcBack, HBITMAP oldBit2) {
	oldBit2 = (HBITMAP)SelectObject(m_memdcBack, m_bit[0]);
	TransparentBlt(m_memdcFront, m_xPos, m_yPos, 300, 300, m_memdcBack, 0, 0, 300, 300, RGB(255, 255, 255));
}