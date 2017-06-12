#pragma once

#include <Windows.h>
#include "resource.h"

class CSlerp
{
public:

	CSlerp(HWND _dlgHandle);
	~CSlerp();
	void Normalize(float _toNormalize[4]);
	void ConvertToMatrix(int _iQuarternion);
	void GetQuarternions();
	void SlerpABT();
private:
	float m_rgfQuartonionA[4];
	float m_rgfQuartonionB[4];
	float m_rgfQuartonionSlerp[4];
	float m_fScalar;
	HWND m_dlgHandle;
};

