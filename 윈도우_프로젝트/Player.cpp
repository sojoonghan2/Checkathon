#include "Player.h"

void CPlayer::SetPos(int xPos, int yPos) {
	p_xPos = xPos;
	p_yPos = yPos;
}

void CPlayer::Move(int xPos) {
	p_xPos += xPos;
}

int CPlayer::getSpeed() const {
	return p_speed;
}