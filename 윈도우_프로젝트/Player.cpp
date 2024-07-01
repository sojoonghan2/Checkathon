#include "Player.h"
#include "stdafx.h"

CPlayer::CPlayer() {
	m_type = IDLE;
	m_Bbox.left = m_xPos;
	m_Bbox.right = m_xPos + 70;
	m_Bbox.top = m_yPos;
	m_Bbox.bottom = m_yPos + 125;
}

CPlayer::~CPlayer() {}

void CPlayer::Draw(HDC m_memdcFront, HDC m_memdcBack, HBITMAP oldBit2) {
    m_frameCounter++;

    if (m_frameCounter >= m_frameDelay) {
        m_frameCounter = 0;

        if (m_type == IDLE) {
            m_now_bit = 2;
        }
        else if (m_type == LEFTMOVE) {
            m_now_bit++;
            if (m_now_bit < 7 || m_now_bit > 10) {
                m_now_bit = 7;
            }
        }
        else if (m_type == RIGHTMOVE) {
            m_now_bit++;
            if (m_now_bit > 5) {
                m_now_bit = 0;
            }
        }
    }

    oldBit2 = (HBITMAP)SelectObject(m_memdcBack, m_bit[m_now_bit]);
    DrawBoundBox(m_memdcFront, m_memdcBack, oldBit2);
    TransparentBlt(m_memdcFront, m_xPos, m_yPos, 75, 125, m_memdcBack, 0, 0, 75, 125, RGB(255, 255, 255));
}

void CPlayer::Animate(float fElapsedTime) {
	CGameObject::Animate(fElapsedTime);
}

void CPlayer::UpdateBoundBox() {
    m_Bbox.left = m_xPos;
    m_Bbox.right = m_xPos + 70;
    m_Bbox.top = m_yPos;
    m_Bbox.bottom = m_yPos + 125;
}