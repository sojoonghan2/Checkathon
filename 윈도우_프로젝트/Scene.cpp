#include "Scene.h"
#include "stdafx.h"

CScene::CScene(CPlayer* player) {
	m_pPlayer = player;
}

CScene::~CScene() {
}

void CScene::Draw(HDC m_memdcFront, HDC m_memdcBack, HBITMAP oldBit2) {
	if (m_pBackground) m_pBackground->Draw(m_memdcFront, m_memdcBack, oldBit2);
	if (m_OUI) m_OUI->Draw(m_memdcFront, m_memdcBack, oldBit2);
	if (m_XUI) m_XUI->Draw(m_memdcFront, m_memdcBack, oldBit2);
}

void CScene::BuildObjects() {
	CBackgroundObject* background = new CBackgroundObject;
	m_pBackground = background;

	CUIObject* OUI = new CUIObject;
	OUI->SetPos(100, 100);
	m_OUI = OUI;

	CUIObject* XUI = new CUIObject;
	XUI->SetPos(550, 100);
	m_XUI = XUI;
}

void CScene::ReleaseObjects() {
	if (m_pBackground) {
		m_pBackground->ReleaseBits();
		delete m_pBackground;
	}
	if (m_OUI) {
		m_OUI->ReleaseBits();
		delete m_OUI;
	}
	if (m_XUI) {
		m_XUI->ReleaseBits();
		delete m_XUI;
	}
}

void CScene::LoadObjectBit(HINSTANCE hInstance) {
	int background_bit = 100;
	if (m_pBackground) m_pBackground->LoadBit(1, hInstance, background_bit);

	int OUI_bit = 200;
	if (m_OUI) m_OUI->LoadBit(1, hInstance, OUI_bit);

	int XUI_bit = 201;
	if (m_XUI) m_XUI->LoadBit(1, hInstance, XUI_bit);
}

void CScene::ReleaseBits() {

}