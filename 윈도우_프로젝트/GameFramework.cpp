#include <windows.h>

#include "GameFrameWork.h"

void CGameFramework::OnCreate(HINSTANCE hInstance, HWND hWnd) {
	m_hInstance = hInstance;
	m_hWnd = hWnd;

	BuildFrameBuffer();

	BuildObjects();
}

void CGameFramework::OnDestroy() {
	ReleaseObjects();

	if (m_memdcBack) ::DeleteObject(m_memdcBack);
	if (m_memdcFront) ::DeleteDC(m_memdcFront);
}

void CGameFramework::BuildFrameBuffer() {
	::GetClientRect(m_hWnd, &m_rcClient);

	HDC hDC = ::GetDC(m_hWnd);

	m_memdcFront = ::CreateCompatibleDC(hDC);
	m_memdcBack = ::CreateCompatibleDC(m_memdcFront);
	hBit = CreateCompatibleBitmap(hDC, 1280, 800);

	DeleteObject(hBit);
	DeleteDC(m_memdcBack);
	DeleteDC(m_memdcFront);
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
		delete m_pScene;
	}

	if (m_pPlayer) delete m_pPlayer;
}

void CGameFramework::LoadObjectBit() {
	//m_pPlayer->LoadBit(1, m_hInstance, 101);
}

void CGameFramework::AnimateObjects() {

}

void CGameFramework::FrameAdvance() {

	AnimateObjects();
	ClearFrameBuffer(RGB(255, 255, 255));

	PresentFrameBuffer();

	m_pScene->Draw(m_memdcFront, m_memdcBack, oldBit2);
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
		case VK_RIGHT:
			break;
		case VK_LEFT:
			break;
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

void CGameFramework::onTimer(HWND hWnd, WPARAM wParam) {
	m_Timer.onTimer(hWnd, wParam);
}
