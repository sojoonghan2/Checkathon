#include "GameObject.h"

void CGameObject::SetPos(int xPos, int yPos) {
	m_xPos = xPos;
	m_yPos = yPos;
}

void CGameObject::Move(int xPos) {
	m_xPos += xPos;
}

void CGameObject::LoadBit(int bit_num, HINSTANCE m_hInstance, int IDB_BITMAP) {
	m_bit = new HBITMAP();
	for (int i{}; i < bit_num; ++i) {
		*m_bit = LoadBitmap(m_hInstance, MAKEINTRESOURCE(IDB_BITMAP + i));
	}
}

void CGameObject::Animate(float fElapsedTime) {

}


// 여기서 선을 그리고 싶은데 선이 안그려짐 시발
void CGameObject::Draw(HDC m_memdcFront, HDC m_memdcBack, HBITMAP oldBit2) {
	HPEN hPen = ::CreatePen(PS_SOLID, 0, RGB(0, 0, 0));
	HPEN hOldPen = (HPEN)::SelectObject(m_memdcFront, hPen);

	hPen = CreatePen(PS_DOT, 1, RGB(0, 0, 0));
	hOldPen = (HPEN)SelectObject(m_memdcFront, hPen);

	MoveToEx(m_memdcFront, 0, 0, NULL);
	LineTo(m_memdcFront, 100, 100);

	::SelectObject(m_memdcFront, hOldPen);
	::DeleteObject(hPen);
}