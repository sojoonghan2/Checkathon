#include <windows.h>
#include <tchar.h>
#include <vector>

#include "GameFrameWork.h"

void CGameFramework::OnCreate(HINSTANCE hInstance, HWND hWnd) {

	m_hInstance = hInstance;
	m_hWnd = hWnd;

	BuildFrameBuffer();

	BuildObjects();
}

void CGameFramework::OnDestroy() {
	ReleaseObjects();

	if (m_memdcBack) ::DeleteObject(hBit);
	if (m_memdcFront) ::DeleteDC(m_memdcFront);
	if (m_memdcFront) ::DeleteDC(m_memdcBack);
}

void CGameFramework::BuildFrameBuffer() {
	::GetClientRect(m_hWnd, &m_rcClient);

	HDC hDC = ::GetDC(m_hWnd);

	m_memdcFront = ::CreateCompatibleDC(hDC);
	m_memdcBack = ::CreateCompatibleDC(m_memdcFront);
	hBit = CreateCompatibleBitmap(hDC, 1280, 800);
	::SelectObject(m_memdcFront, hBit);

	
	::ReleaseDC(m_hWnd, hDC);
	::SetBkMode(m_memdcFront, TRANSPARENT);
}

void CGameFramework::ClearFrameBuffer(DWORD dwColor) {
	HPEN hPen = ::CreatePen(PS_SOLID, 0, dwColor);
	HPEN hOldPen = (HPEN)::SelectObject(m_memdcFront, hPen);
	HBRUSH hBrush = ::CreateSolidBrush(dwColor);
	HBRUSH hOldBrush = (HBRUSH)::SelectObject(m_memdcFront, hBrush);

	::Rectangle(m_memdcFront, m_rcClient.left, m_rcClient.top, m_rcClient.right, m_rcClient.bottom);
	::SelectObject(m_memdcFront, hOldBrush);
	::SelectObject(m_memdcFront, hOldPen);
	::DeleteObject(hPen);
	::DeleteObject(hBrush);
}

void CGameFramework::PresentFrameBuffer() {
	HDC hDC = ::GetDC(m_hWnd);
	::BitBlt(hDC, m_rcClient.left, m_rcClient.top, m_rcClient.right - m_rcClient.left, m_rcClient.bottom - m_rcClient.top, m_memdcFront, m_rcClient.left, m_rcClient.top, SRCCOPY);
	::ReleaseDC(m_hWnd, hDC);
}

void CGameFramework::BuildObjects() {
	CPlayer* player = new CPlayer;
	player->SetPos(10, 10);
	m_pPlayer = player;

	m_pScene = new CScene(m_pPlayer);

	LoadObjectBit();
}

void CGameFramework::ReleaseObjects() {
	if (m_pScene) {
		m_pScene->ReleaseObjects();
		delete m_pScene;
	}

	if (m_pPlayer) {
		m_pPlayer->ReleaseBits();
		delete m_pPlayer;
	}
}

void CGameFramework::LoadObjectBit() {
	std::vector<int> player_bit;
	m_pPlayer->bit_num = 10;
	for (int i{}; i < m_pPlayer->bit_num; ++i) {
		player_bit.push_back(i + 101);
	}
	m_pPlayer->LoadBit(m_pPlayer->bit_num, m_hInstance, player_bit);
}

void CGameFramework::AnimateObjects() {

}

void CGameFramework::FrameAdvance() {
	m_Timer.Tick(60.0f);

	AnimateObjects();
	ProcessInput();

	ClearFrameBuffer(RGB(255, 255, 255));

	if(m_pPlayer) m_pPlayer->Draw(m_memdcFront, m_memdcBack, oldBit2);
	if(m_pScene) m_pScene->Draw(m_memdcFront, m_memdcBack, oldBit2);

	PresentFrameBuffer();

	// m_pszFrameRate에 왜 문자열이 안들어가는지 모르겠음
	m_Timer.GetFrameRate(m_pszFrameRate + 12, 37);
	::SetWindowText(m_hWnd, m_pszFrameRate);
}

void CGameFramework::ProcessInput() {
	if (GetAsyncKeyState(VK_LEFT)) {
		m_pPlayer->MoveLeft(300 * m_Timer.GetTimeElapsed());
	}
	if (GetAsyncKeyState(VK_RIGHT)) {
		m_pPlayer->MoveRight(300 * m_Timer.GetTimeElapsed());
	}
	if (GetAsyncKeyState(VK_UP)) {
		m_pPlayer->MoveUP(300 * m_Timer.GetTimeElapsed());
	}
	if (GetAsyncKeyState(VK_DOWN)) {
		m_pPlayer->MoveDown(300 * m_Timer.GetTimeElapsed());
	}
}

// 윈도우 마우스
void CGameFramework::OnProcessingMouseMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam) {
	switch (nMessageID) {
	case WM_RBUTTONDOWN:
	case WM_LBUTTONDOWN:
		break;
	case WM_LBUTTONUP:
	case WM_RBUTTONUP:
		break;
	case WM_MOUSEMOVE:
		break;
	default:
		break;
	}
}

// 윈도우 키보드
void CGameFramework::OnProcessingKeyboardMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam) {
	switch (nMessageID) {
	case WM_KEYDOWN:
		switch (wParam) {
		case VK_ESCAPE:
			::PostQuitMessage(0);
			break;
		case VK_RETURN:
			break;
		case VK_CONTROL:
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
}

LRESULT CALLBACK CGameFramework::OnProcessingWindowMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam) {
	switch (nMessageID) {
	case WM_ACTIVATE:
		break;
	case WM_SIZE:
		break;
	case WM_LBUTTONDOWN:
	case WM_RBUTTONDOWN:
	case WM_LBUTTONUP:
	case WM_RBUTTONUP:
	case WM_MOUSEMOVE:
		OnProcessingMouseMessage(hWnd, nMessageID, wParam, lParam);
		break;
	case WM_KEYDOWN:
	case WM_KEYUP:
		OnProcessingKeyboardMessage(hWnd, nMessageID, wParam, lParam);
		break;
	}
	return(0);
}