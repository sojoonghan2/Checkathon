#pragma once

const ULONG				MAX_SAMPLE_COUNT = 50;

class CTimer {
private:
	bool				m_bHardwareHasPerformanceCounter;	// ��ǻ�Ͱ� Performance Counter�� ������ �ִ� ��
	float				m_fTimeScale;						// Scale Counter�� ��
	float				m_fTimeElapsed;						// ������ ������ ���� ������ �ð�
	__int64				m_nCurrentTime;						// ���� �ð�
	__int64				m_nLastTime;						// ������ ������ �ð�
	__int64				m_nPerformanceFrequency;			// PerformanceFrequency
	float				m_fFrameTime[MAX_SAMPLE_COUNT];		// ������ �ð��� �����ϱ� ���� �迭
	ULONG				m_nSampleCount;						// ������ ������ ��
	unsigned long		m_nCurrentFrameRate;				// ���� ������ ����Ʈ
	unsigned long		m_nFramesPerSecond;					// �ʴ� ������ ��
	float				m_fFPSTimeElapsed;					// ������ ����Ʈ ��� �ҿ� �ð�
	bool				m_bStopped;							// �����ִ��� Ȯ��

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