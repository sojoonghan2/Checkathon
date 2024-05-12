#pragma once
#include "Timer.h"
#include "Player.h"

class CGameFrameWork {
private:
	CTimer			Timer;
	CPlayer			Player;

public:
	CGameFrameWork() {}
	~CGameFrameWork() {}
	void onTimer(HWND hWnd, WPARAM wParam);
	void OnProcessingMouseMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam);
	void OnProcessingKeyboardMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam);
	LRESULT CALLBACK OnProcessingWindowMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam);
};

