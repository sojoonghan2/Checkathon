#pragma once

#include "GameObject.h"

class CPlayer : public CGameObject {
public:
	virtual void Draw(HDC hDCFrameBuffer, HDC m_memdcBack, HBITMAP oldBit2);

};

