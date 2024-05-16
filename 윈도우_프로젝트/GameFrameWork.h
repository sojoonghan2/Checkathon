#pragma once
#include "Timer.h"
#include "Player.h"
#include "Scene.h"

class CGameFramework {
private:
	HINSTANCE					m_hInstance = NULL;
	HWND						m_hWnd = NULL;

	RECT						m_rcClient;

	HDC							m_memdcFront = NULL;
	HDC							m_memdcBack = NULL;

	HBITMAP						hBit = NULL;
	HBITMAP						oldBit = NULL;
	HBITMAP						oldBit2 = NULL;

	CPlayer*					m_pPlayer = NULL;
	CScene*						m_pScene = NULL;

	CTimer						m_Timer;

public:
	CGameFramework() {}
	~CGameFramework() {}

	void OnCreate(HINSTANCE hInstance, HWND hWnd);
	void OnDestroy();

	void BuildFrameBuffer();
	void ClearFrameBuffer(DWORD dwColor);
	void PresentFrameBuffer();

	void BuildObjects();
	void ReleaseObjects();

	void LoadObjectBit();

	void AnimateObjects();
	void FrameAdvance();

	void onTimer(HWND hWnd, WPARAM wParam);
	void OnProcessingMouseMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam);
	void OnProcessingKeyboardMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam);
	LRESULT CALLBACK OnProcessingWindowMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam);
};

