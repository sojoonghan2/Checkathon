#include "Player.h"

void CPlayer::Draw(HDC hDCFrameBuffer, HDC m_memdcBack, HBITMAP oldBit2) {
	CGameObject::Draw(hDCFrameBuffer, m_memdcBack, oldBit2);
}

void CPlayer::Animate(float fElapsedTime) {
	CGameObject::Animate(fElapsedTime);
}