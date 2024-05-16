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
	virtual void MoveUP(int yPos);
	virtual void MoveDown(int yPos);
	virtual void MoveLeft(int xPos);
	virtual void MoveRight(int xPos);

	virtual void LoadBit(int bit_num, HINSTANCE m_hInstance, int IDB_BITMAP);
	virtual void ReleaseBits();

	virtual void Animate(float fElapsedTime);
	virtual void Draw(HDC hDCFrameBuffer, HDC m_memdcBack, HBITMAP oldBit2);
};

