#pragma once
#include <windows.h>
#include <vector>

class CGameObject {
private:
	int						m_xPos;
	int						m_yPos;
	int						m_speed;

	HBITMAP*				m_bit;
	int*					m_i_bit;

public:
	int						bit_num;
	int						now_bit;

	CGameObject() {}
	~CGameObject() {}
	void SetPos(int xPos, int yPos);
	virtual void MoveUP(int yPos);
	virtual void MoveDown(int yPos);
	virtual void MoveLeft(int xPos);
	virtual void MoveRight(int xPos);

	virtual void LoadBit(int bit_num, HINSTANCE m_hInstance, std::vector<int> m_i_bit);
	virtual void ReleaseBits();

	virtual void Animate(float fElapsedTime);
	virtual void Draw(HDC hDCFrameBuffer, HDC m_memdcBack, HBITMAP oldBit2);
};

