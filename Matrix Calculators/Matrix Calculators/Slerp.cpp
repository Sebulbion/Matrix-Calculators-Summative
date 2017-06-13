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
}

void CSlerp::ConvertToMatrix(int _iQuarternion)
{
	float *_toMatrix;

	if (_iQuarternion == 1)
	{
		_toMatrix = m_rgfQuartonionA;
		Normalize(_toMatrix);
	}
	else if (_iQuarternion == 2)
	{
		_toMatrix = m_rgfQuartonionB;
		Normalize(_toMatrix);
	}
	else
	{
		_toMatrix = m_rgfQuartonionSlerp;
		Normalize(_toMatrix);
	}

	float qw = _toMatrix[3];
	float qx = _toMatrix[0];
	float qy = _toMatrix[1];
	float qz = _toMatrix[2];


	WriteToEditBox(m_dlgHandle, IDC_EDIT34, (1 - 2 * qy*qy - 2 * qz*qz));
	WriteToEditBox(m_dlgHandle, IDC_EDIT35, (2 * qx*qy - 2 * qz*qw));
	WriteToEditBox(m_dlgHandle, IDC_EDIT36, (2 * qx*qz + 2 * qy*qw));
	WriteToEditBox(m_dlgHandle, IDC_EDIT37, 0);
	WriteToEditBox(m_dlgHandle, IDC_EDIT38, (2 * qx*qy + 2 * qz*qw));
	WriteToEditBox(m_dlgHandle, IDC_EDIT39, (1 - 2 * qx*qx - 2 * qz*qz));
	WriteToEditBox(m_dlgHandle, IDC_EDIT40, (2 * qy*qz - 2 * qx*qw));
	WriteToEditBox(m_dlgHandle, IDC_EDIT41, 0);
	WriteToEditBox(m_dlgHandle, IDC_EDIT42, (2 * qx*qz - 2 * qy*qw));
	WriteToEditBox(m_dlgHandle, IDC_EDIT43, (2 * qy*qz + 2 * qx*qw));
	WriteToEditBox(m_dlgHandle, IDC_EDIT44, (1 - 2 * qx*qx - 2 * qy*qy));
	WriteToEditBox(m_dlgHandle, IDC_EDIT45, 0);
	WriteToEditBox(m_dlgHandle, IDC_EDIT46, 0);
	WriteToEditBox(m_dlgHandle, IDC_EDIT47, 0);
	WriteToEditBox(m_dlgHandle, IDC_EDIT48, 0);
	WriteToEditBox(m_dlgHandle, IDC_EDIT49, 1);



}

void CSlerp::GetQuarternions()
{
	m_rgfQuartonionA[0] = ReadFromEditBox(m_dlgHandle, IDC_EDIT1);
	m_rgfQuartonionA[1] = ReadFromEditBox(m_dlgHandle, IDC_EDIT2);
	m_rgfQuartonionA[2] = ReadFromEditBox(m_dlgHandle, IDC_EDIT3);
	m_rgfQuartonionA[3] = ReadFromEditBox(m_dlgHandle, IDC_EDIT4);

	m_rgfQuartonionB[0] = ReadFromEditBox(m_dlgHandle, IDC_EDIT5);
	m_rgfQuartonionB[1] = ReadFromEditBox(m_dlgHandle, IDC_EDIT6);
	m_rgfQuartonionB[2] = ReadFromEditBox(m_dlgHandle, IDC_EDIT7);
	m_rgfQuartonionB[3] = ReadFromEditBox(m_dlgHandle, IDC_EDIT8);

	m_rgfQuartonionSlerp[0] = ReadFromEditBox(m_dlgHandle, IDC_EDIT10);
	m_rgfQuartonionSlerp[1] = ReadFromEditBox(m_dlgHandle, IDC_EDIT11);
	m_rgfQuartonionSlerp[2] = ReadFromEditBox(m_dlgHandle, IDC_EDIT12);
	m_rgfQuartonionSlerp[3] = ReadFromEditBox(m_dlgHandle, IDC_EDIT13);

	m_fScalar = ReadFromEditBox(m_dlgHandle, IDC_EDIT9);
}

void CSlerp::SlerpABT()
{
	float angle = 0;

	Normalize(m_rgfQuartonionA);
	Normalize(m_rgfQuartonionB);

	for (int i = 0; i < 4; i++)
	{
		angle += m_rgfQuartonionA[i] * m_rgfQuartonionB[i];
	}

	//angle = acos(angle);

	if (fabs(angle) > 0.9995)
	{
		for (int i = 0; i < 4; i++)
		{
			m_rgfQuartonionSlerp[i] = m_rgfQuartonionA[i] + (m_fScalar*(m_rgfQuartonionB[i] - m_rgfQuartonionA[i]));
		}
	}
	else
	{
		if (angle < 0.0f)
		{
			for (int i = 0; i < 4; i++)
			{
				m_rgfQuartonionB[i] = -m_rgfQuartonionB[i];
			}

			angle = -angle;
		}

		angle = acos(angle);

		for (int i = 0; i < 4; i++)
		{
			m_rgfQuartonionSlerp[i] = (m_rgfQuartonionA[i] * sin((1 - m_fScalar)*angle) / sin(angle)) + (m_rgfQuartonionB[i] * (sin(m_fScalar*angle) / sin(angle)));
		}
	}
	
	

	WriteToEditBox(m_dlgHandle, IDC_EDIT10, m_rgfQuartonionSlerp[0]);
	WriteToEditBox(m_dlgHandle, IDC_EDIT11, m_rgfQuartonionSlerp[1]);
	WriteToEditBox(m_dlgHandle, IDC_EDIT12, m_rgfQuartonionSlerp[2]);
	WriteToEditBox(m_dlgHandle, IDC_EDIT13, m_rgfQuartonionSlerp[3]);
}
