#pragma once

const ULONG				MAX_SAMPLE_COUNT = 50;

class CTimer {
private:
	bool				m_bHardwareHasPerformanceCounter;	// 컴퓨터가 Performance Counter를 가지고 있는 가
	float				m_fTimeScale;						// Scale Counter의 양
	float				m_fTimeElapsed;						// 마지막 프레임 이후 지나간 시간
	__int64				m_nCurrentTime;						// 현재 시간
	__int64				m_nLastTime;						// 마지막 프레임 시간
	__int64				m_nPerformanceFrequency;			// PerformanceFrequency
	float				m_fFrameTime[MAX_SAMPLE_COUNT];		// 프레임 시간을 누적하기 위한 배열
	ULONG				m_nSampleCount;						// 누적된 프레임 수
	unsigned long		m_nCurrentFrameRate;				// 현재 프레임 레이트
	unsigned long		m_nFramesPerSecond;					// 초당 프레임 수
	float				m_fFPSTimeElapsed;					// 프레임 레이트 계산 소요 시간
	bool				m_bStopped;							// 멈춰있는지 확인

public:
	CTimer();
	~CTimer();
	void Start() { }
	void Stop() { }
	void Reset();
	void Tick(float fLockFPS = 0.0f);
	unsigned long GetFrameRate(LPTSTR lpszString = NULL, int nCharacters = 0);
	float GetTimeElapsed();
};