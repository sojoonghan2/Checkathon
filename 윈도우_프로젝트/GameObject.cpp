#include "GameObject.h"

void CGameObject::SetPos(int xPos, int yPos) {
	m_xPos = xPos;
	m_yPos = yPos;
}

void CGameObject::MoveUP(int yPos) {
	m_yPos -= yPos;
}

void CGameObject::MoveDown(int yPos) {
	m_yPos += yPos;
}

void CGameObject::MoveLeft(int xPos) {
	m_xPos -= xPos;
}

void CGameObject::MoveRight(int xPos) {
	m_xPos += xPos;
}

void CGameObject::LoadBit(int bit_num, HINSTANCE m_hInstance, int IDB_BITMAP) {
	m_bit = new HBITMAP();
	*m_bit = LoadBitmap(m_hInstance, MAKEINTRESOURCE(IDB_BITMAP));
}

void CGameObject::ReleaseBits() {
	DeleteObject(m_bit);
	delete m_bit;
}

void CGameObject::Animate(float fElapsedTime) {

}


void CGameObject::Draw(HDC m_memdcFront, HDC m_memdcBack, HBITMAP oldBit2) {
  
	oldBit2 = (HBITMAP)SelectObject(m_memdcBack, *m_bit);
	TransparentBlt(m_memdcFront, m_xPos, m_yPos, 100, 100, m_memdcBack, 0, 0, 100, 100, RGB(255, 255, 255));
}