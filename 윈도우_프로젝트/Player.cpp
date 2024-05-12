#include "Player.h"

<<<<<<< HEAD
void CPlayer::Draw(HDC hDCFrameBuffer, HDC m_memdcBack, HBITMAP oldBit2) {
	CGameObject::Draw(hDCFrameBuffer, m_memdcBack, oldBit2);
=======
void CPlayer::SetPos(int xPos, int yPos) {
	p_xPos = xPos;
	p_yPos = yPos;
}

void CPlayer::Move(int xPos) {
	p_xPos += xPos;
}

int CPlayer::getSpeed() const {
	return p_speed;
>>>>>>> dc3dd22715aa3b968f5cb432a07e0b34ede470c6
}