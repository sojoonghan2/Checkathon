#pragma once
<<<<<<< HEAD

#include "GameObject.h"

class CPlayer : public CGameObject {

public:
	virtual void Draw(HDC hDCFrameBuffer, HDC m_memdcBack, HBITMAP oldBit2);

=======
class CPlayer {
private:
	int p_xPos;
	int p_yPos;
	int p_speed;

public:
	CPlayer() {
		p_xPos = 100;
		p_yPos = 100;
		p_speed = 10;
	}
	~CPlayer() {}
	void SetPos(int xPos, int yPos);
	void Move(int xPos);

	int getSpeed() const;
>>>>>>> dc3dd22715aa3b968f5cb432a07e0b34ede470c6
};

