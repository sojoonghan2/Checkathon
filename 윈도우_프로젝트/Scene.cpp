#include "Scene.h"

CScene::CScene(CPlayer* player) {
	m_player = player;
}

CScene::~CScene() {
}

void CScene::Draw(HDC hDCFrameBuffer, HDC m_memdcBack, HBITMAP oldBit2) {
	
}

void CScene::BuildObjects() {

}

void CScene::ReleaseObjects() {

}

void CScene::ReleaseBits() {

}