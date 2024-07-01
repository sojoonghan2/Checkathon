#pragma comment(lib, "winmm.lib")

#include "stdafx.h"
#include "Timer.h"

CTimer::CTimer() {
	if (::QueryPerformanceFrequency((LARGE_INTEGER*)&m_nPerformanceFrequency)) {
		m_bHardwareHasPerformanceCounter = TRUE;
		::QueryPerformanceCounter((LARGE_INTEGER*)&m_nLastTime);
		m_fTimeScale = 1.0f / m_nPerformanceFrequency;
	}
	else {
		m_bHardwareHasPerformanceCounter = FALSE;
		m_nLastTime = ::timeGetTime();
		m_fTimeScale = 0.001f;
	}
	m_nSampleCount = 0;
	m_nCurrentFrameRate = 0;
	m_nFramesPerSecond = 0;
	m_fFPSTimeElapsed = 0.0f;
}

CTimer::~CTimer() {}

void CTimer::Tick(float fLockFPS) {
	if (m_bHardwareHasPerformanceCounter) {
		::QueryPerformanceCounter((LARGE_INTEGER*)&m_nCurrentTime);
	}
	else {
		m_nCurrentTime = ::timeGetTime();
	}

	// ���������� �� �Լ��� ȣ���� ���� ����� �ð��� ���
	float fTimeElapsed = (m_nCurrentTime - m_nLastTime) * m_fTimeScale;

	if (fLockFPS > 0.0f) {
		// �� �Լ��� �Ķ����(fLockFPS)�� 0���� ũ�� �� �ð���ŭ ȣ���� �Լ��� ��ٸ��� ��
		while (fTimeElapsed < (1.0f / fLockFPS)) {
			if (m_bHardwareHasPerformanceCounter) {
				::QueryPerformanceCounter((LARGE_INTEGER*)&m_nCurrentTime);
			}
			else {
				m_nCurrentTime = ::timeGetTime();
			}

			// ���������� �� �Լ��� ȣ���� ���� ����� �ð��� ���
			fTimeElapsed = (m_nCurrentTime - m_nLastTime) * m_fTimeScale;
		}
	}

	// ���� �ð��� m_nLastTime�� ����
	m_nLastTime = m_nCurrentTime;

	// ������ ������ ó�� �ð��� ���� ������ ó�� �ð��� ���̰� 1�ʺ���
	// ������ ���� ������ ó�� �ð��� m_fFrameTime[0]�� ����
	if (fabsf(fTimeElapsed - m_fTimeElapsed) < 1.0f) {
		::memmove(&m_fFrameTime[1], m_fFrameTime, (MAX_SAMPLE_COUNT - 1) *
			sizeof(float));
		m_fFrameTime[0] = fTimeElapsed;
		if (m_nSampleCount < MAX_SAMPLE_COUNT) m_nSampleCount++;
	}

	// �ʴ� ������ ���� 1 ������Ű�� ���� ������ ó�� �ð��� �����Ͽ� ����
	m_nFramesPerSecond++;
	m_fFPSTimeElapsed += fTimeElapsed;
	if (m_fFPSTimeElapsed > 1.0f) {
		m_nCurrentFrameRate = m_nFramesPerSecond;
		m_nFramesPerSecond = 0;
		m_fFPSTimeElapsed = 0.0f;
	}

	// ������ ������ ó�� �ð��� ����� ���Ͽ� ������ ó�� �ð��� ����
	m_fTimeElapsed = 0.0f;
	for (ULONG i = 0; i < m_nSampleCount; i++) m_fTimeElapsed += m_fFrameTime[i];
	if (m_nSampleCount > 0) m_fTimeElapsed /= m_nSampleCount;
}

unsigned long CTimer::GetFrameRate(LPTSTR lpszString, int nCharacters) {
	if (lpszString) {
		_itow_s(m_nCurrentFrameRate, lpszString, nCharacters, 10);
		wcscat_s(lpszString, nCharacters, _T(" FPS)"));
	}
	return(m_nCurrentFrameRate);
}

float CTimer::GetTimeElapsed() {
	return(m_fTimeElapsed);
}

void CTimer::Reset() {
	__int64 nPerformanceCounter;
	::QueryPerformanceCounter((LARGE_INTEGER*)&nPerformanceCounter);
	m_nLastTime = nPerformanceCounter;
	m_nCurrentTime = nPerformanceCounter;
	m_bStopped = false;
}