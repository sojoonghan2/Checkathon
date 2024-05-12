#pragma once
#include <windows.h>

class CGameObject {
private:
	int						m_xPos;
	int						m_yPos;
	int						m_speed;

	HBITMAP*				m_bit;
	int						bit_num;

public:
	CGameObject() {}
	~CGameObject() {}
	void SetPos(int xPos, int yPos);
	void Move(int xPos);

	virtual void LoadBit(int bit_num, HINSTANCE m_hInstance, int IDB_BITMAP);
	virtual void Animate(float fElapsedTime);
	virtual void Draw(HDC hDCFrameBuffer, HDC m_memdcBack, HBITMAP oldBit2);
};

