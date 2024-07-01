#pragma once
#include "stdafx.h"

class CBackgroundObject {
private:
	HBITMAP					m_bit;
	int						m_i_bit;

public:
	CBackgroundObject() {}
	~CBackgroundObject() {}

	virtual void LoadBit(int m_bit_num, HINSTANCE m_hInstance, int m_i_bit);
	virtual void ReleaseBits();

	virtual void Draw(HDC m_memdcFront, HDC m_memdcBack, HBITMAP oldBit2);
};

class CGameObject {
protected:
	int						m_xPos;
	int						m_yPos;
	int						m_speed;

	HBITMAP*				m_bit;
	int*					m_i_bit;

public:
	RECT					m_Bbox;
	int						m_type;
	int						m_bit_num;
	int						m_now_bit;

public:
	CGameObject() {}
	~CGameObject() {}

	void SetPos(int xPos, int yPos) { m_xPos = xPos; m_yPos = yPos; }
	virtual void MoveUP(int yPos) { m_yPos -= yPos; }
	virtual void MoveDown(int yPos) { m_yPos += yPos; }
	virtual void MoveLeft(int xPos) { m_xPos -= xPos; }
	virtual void MoveRight(int xPos) { m_xPos += xPos; }

	virtual void LoadBit(int m_bit_num, HINSTANCE m_hInstance, std::vector<int> m_i_bit);
	virtual void LoadBit(int m_bit_num, HINSTANCE m_hInstance, int m_i_bit);
	virtual void ReleaseBits();

	virtual void Animate(float fElapsedTime);
	virtual void Draw(HDC m_memdcFront, HDC m_memdcBack, HBITMAP oldBit2);
	virtual void DrawBoundBox(HDC m_memdcFront, HDC m_memdcBack, HBITMAP oldBit2);

	virtual void UpdateBoundBox();
};

class CUIObject : public CGameObject {
public:
	virtual void Draw(HDC m_memdcFront, HDC m_memdcBack, HBITMAP oldBit2);
};

class CSpickObject : public CGameObject {
public:
	virtual void Draw(HDC m_memdcFront, HDC m_memdcBack, HBITMAP oldBit2);
};