#include <math.h>
#include "Slerp.h"
#include "utils.h"




CSlerp::CSlerp(HWND _dlgHandle)
	:
	m_dlgHandle(_dlgHandle)
{

}


CSlerp::~CSlerp()
{
}

void CSlerp::Normalize(float _toNormalize[4])
{
	float iNormal = sqrt(pow(_toNormalize[0], 2) + pow(_toNormalize[1], 2) + pow(_toNormalize[2], 2) + pow(_toNormalize[3], 2));
	
	for (int i = 0; i < 4; i++)
	{
		_toNormalize[i] = _toNormalize[i] / iNormal;
	}

	/*iNormal = sqrt(pow(m_rgfQuartonionB[0], 2) + pow(m_rgfQuartonionB[1], 2) + pow(m_rgfQuartonionB[2], 2) + pow(m_rgfQuartonionB[3], 2));

	for (int i = 0; i < 4; i++)
	{
		m_rgfQuartonionB[i] = m_rgfQuartonionB[i] / iNormal;
	}

	iNormal = sqrt(pow(m_rgfQuartonionSlerp[0], 2) + pow(m_rgfQuartonionSlerp[1], 2) + pow(m_rgfQuartonionSlerp[2], 2) + pow(m_rgfQuartonionSlerp[3], 2));

	for (int i = 0; i < 4; i++)
	{
		m_rgfQuartonionSlerp[i] = m_rgfQuartonionSlerp[i] / iNormal;
	}*/
}

void CSlerp::ConvertToMatrix(int _iQuarternion)
{
	float *_toMatrix;

	if (_iQuarternion == 1)
	{
		_toMatrix = m_rgfQuartonionA;
		Normalize(_toMatrix);
	}
	float qw = _toMatrix[0];
	float qx = _toMatrix[1];
	float qy = _toMatrix[2];
	float qz = _toMatrix[3];

	float a1 = (1 - (2 * qy*qy) - (2 * qz*qz));


	WriteToEditBox(m_dlgHandle, IDC_EDIT34, a1);
}

void CSlerp::GetQuarternions()
{
	m_rgfQuartonionA[0] = ReadFromEditBox(m_dlgHandle, IDC_EDIT1);
	m_rgfQuartonionA[1] = ReadFromEditBox(m_dlgHandle, IDC_EDIT2);
	m_rgfQuartonionA[2] = ReadFromEditBox(m_dlgHandle, IDC_EDIT3);
	m_rgfQuartonionA[3] = ReadFromEditBox(m_dlgHandle, IDC_EDIT4);

}
