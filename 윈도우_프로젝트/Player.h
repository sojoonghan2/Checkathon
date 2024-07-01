#pragma once

#include "GameObject.h"

class CPlayer : public CGameObject {
public:
	CPlayer();
	~CPlayer();

private:
	int						m_hp = 3;

	int						m_frameCounter = 0;
	int						m_frameDelay = 5;

public:
	virtual void Draw(HDC m_memdcFront, HDC m_memdcBack, HBITMAP oldBit2);
	virtual void Animate(float fElapsedTime);

	virtual void UpdateBoundBox();
};

