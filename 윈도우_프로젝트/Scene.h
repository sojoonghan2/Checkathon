#pragma once

#include <windows.h>

#include "GameObject.h"
#include "Player.h"


class CScene {
private:
	int							m_ObjectsNum = 0;

	CGameObject**				m_Objects = NULL;

	CPlayer*					m_player;

public:
	CScene(CPlayer* player);
	virtual ~CScene();

	virtual void Draw(HDC hDCFrameBuffer, HDC m_memdcBack, HBITMAP oldBit2);
};

