#pragma once

#include "stdafx.h"
#include "GameObject.h"
#include "Player.h"


class CScene {
private:
	int							m_ObjectsNum = 0;

	CGameObject**				m_Objects = NULL;

	CPlayer*					m_pPlayer;

	CBackgroundObject*			m_pBackground;

	CUIObject*					m_OUI;

	CUIObject*					m_XUI;

public:
	CScene(CPlayer* player);
	virtual ~CScene();

	void LoadObjectBit(HINSTANCE hInstance);

	virtual void Draw(HDC m_memdcFront, HDC m_memdcBack, HBITMAP oldBit2);

	virtual void BuildObjects();
	virtual void ReleaseObjects();
	virtual void ReleaseBits();
};

