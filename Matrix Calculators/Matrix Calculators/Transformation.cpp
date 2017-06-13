#include "Transformation.h"
#include "utils.h"

// Static variables
CTransformation* CTransformation::s_pTransformation = 0;

CTransformation::CTransformation():
	m_rgfResultantMat{ 
		{ 1,0,0,0 },
		{ 0,1,0,0 },
		{ 0,0,1,0 },
		{ 0,0,0,1 } },

	m_rgfUserInputMat{
		{ 1,0,0,0 },
		{ 0,1,0,0 },
		{ 0,0,1,0 },
		{ 0,0,0,1 } },

		m_rgfTempMat{
		{ 1,0,0,0 },
		{ 0,1,0,0 },
		{ 0,0,1,0 },
		{ 0,0,0,1 } },
		m_rgfProjectionMat{ 
		{ 1,0,0,0 },
		{ 0,1,0,0 },
		{ 0,0,1,0 },
		{ 0,0,0,1 }
}
{
}


CTransformation::~CTransformation()
{
	delete s_pTransformation;
}

CTransformation & CTransformation::GetInstance()
{
	if (s_pTransformation == 0)
	{
		s_pTransformation = new CTransformation();
	}

	return (*s_pTransformation);
}



//void CTransformation::SetResultantMat(HWND _hDlg)
//{
//	for (size_t i = 0; i < 4; ++i)
//	{
//		for (size_t j = 0; j < 4; ++j)
//		{
//			m_rgfResultantMat[i][j] = ReadFromEditBox(_hDlg,;
//		}
//	}
//}

void CTransformation::WriteToDialogBoxCMFormat(HWND _hDlg)
{
	WriteToEditBox(_hDlg, IDC_EDIT8, m_rgfResultantMat[0][0]);
	WriteToEditBox(_hDlg, IDC_EDIT9, m_rgfResultantMat[0][1]);
	WriteToEditBox(_hDlg, IDC_EDIT10, m_rgfResultantMat[0][2]);
	WriteToEditBox(_hDlg, IDC_EDIT11, m_rgfResultantMat[0][3]);

	WriteToEditBox(_hDlg, IDC_EDIT12, m_rgfResultantMat[1][0]);
	WriteToEditBox(_hDlg, IDC_EDIT16, m_rgfResultantMat[1][1]);
	WriteToEditBox(_hDlg, IDC_EDIT18, m_rgfResultantMat[1][2]);
	WriteToEditBox(_hDlg, IDC_EDIT19, m_rgfResultantMat[1][3]);

	WriteToEditBox(_hDlg, IDC_EDIT20, m_rgfResultantMat[2][0]);
	WriteToEditBox(_hDlg, IDC_EDIT21, m_rgfResultantMat[2][1]);
	WriteToEditBox(_hDlg, IDC_EDIT22, m_rgfResultantMat[2][2]);
	WriteToEditBox(_hDlg, IDC_EDIT23, m_rgfResultantMat[2][3]);

	WriteToEditBox(_hDlg, IDC_EDIT24, m_rgfResultantMat[3][0]);
	WriteToEditBox(_hDlg, IDC_EDIT25, m_rgfResultantMat[3][1]);
	WriteToEditBox(_hDlg, IDC_EDIT26, m_rgfResultantMat[3][2]);
	WriteToEditBox(_hDlg, IDC_EDIT27, m_rgfResultantMat[3][3]);
}

void CTransformation::WriteToDialogBoxRMFormat(HWND _hDlg)
{
	WriteToEditBox(_hDlg, IDC_EDIT47, m_rgfResultantMat[0][0]);
	WriteToEditBox(_hDlg, IDC_EDIT48, m_rgfResultantMat[1][0]);
	WriteToEditBox(_hDlg, IDC_EDIT49, m_rgfResultantMat[2][0]);
	WriteToEditBox(_hDlg, IDC_EDIT50, m_rgfResultantMat[3][0]);

	WriteToEditBox(_hDlg, IDC_EDIT51, m_rgfResultantMat[0][1]);
	WriteToEditBox(_hDlg, IDC_EDIT52, m_rgfResultantMat[1][1]);
	WriteToEditBox(_hDlg, IDC_EDIT53, m_rgfResultantMat[2][1]);
	WriteToEditBox(_hDlg, IDC_EDIT54, m_rgfResultantMat[3][1]);

	WriteToEditBox(_hDlg, IDC_EDIT55, m_rgfResultantMat[0][2]);
	WriteToEditBox(_hDlg, IDC_EDIT56, m_rgfResultantMat[1][2]);
	WriteToEditBox(_hDlg, IDC_EDIT57, m_rgfResultantMat[2][2]);
	WriteToEditBox(_hDlg, IDC_EDIT58, m_rgfResultantMat[3][2]);

	WriteToEditBox(_hDlg, IDC_EDIT59, m_rgfResultantMat[0][3]);
	WriteToEditBox(_hDlg, IDC_EDIT60, m_rgfResultantMat[1][3]);
	WriteToEditBox(_hDlg, IDC_EDIT61, m_rgfResultantMat[2][3]);
	WriteToEditBox(_hDlg, IDC_EDIT62, m_rgfResultantMat[3][3]);
}

void CTransformation::MultiplyMatrix(HWND _hDlg, float _rgInputMat[4][4])
{
	SetMatrix(m_rgfTempMat, m_rgfResultantMat);
	for (size_t i = 0; i < 4; ++i)
	{
		for (size_t j = 0; j < 4; ++j)
		{
			m_rgfResultantMat[i][j] =
				_rgInputMat[i][0] * m_rgfTempMat[0][j] +
				_rgInputMat[i][1] * m_rgfTempMat[1][j] +
				_rgInputMat[i][2] * m_rgfTempMat[2][j] +
				_rgInputMat[i][3] * m_rgfTempMat[3][j];
		}
	}

	WriteToDialogBoxCMFormat(_hDlg);
	WriteToDialogBoxRMFormat(_hDlg);
}

void CTransformation::SetMatrix(float _rgMatrixA[4][4], float _rgMatrixB[4][4])
{
	for (size_t i = 0; i < 4; ++i)
	{
		for (size_t j = 0; j < 4; ++j)
		{
			_rgMatrixA[i][j] = _rgMatrixB[i][j];
		}
	}
}

void CTransformation::ApplyScaling(HWND _hDlg)
{
	CreateIdentatyMatrix(m_rgfUserInputMat);
	m_rgfUserInputMat[0][0] = ReadFromEditBox(_hDlg, IDC_EDIT1);
	m_rgfUserInputMat[1][1] = ReadFromEditBox(_hDlg, IDC_EDIT2);
	m_rgfUserInputMat[2][2] = ReadFromEditBox(_hDlg, IDC_EDIT3);

	MultiplyMatrix(_hDlg, m_rgfUserInputMat);
}

void CTransformation::ApplyTranslation(HWND _hDlg)
{
	CreateIdentatyMatrix(m_rgfUserInputMat);
	m_rgfUserInputMat[0][3] = ReadFromEditBox(_hDlg, IDC_EDIT4);
	m_rgfUserInputMat[1][3] = ReadFromEditBox(_hDlg, IDC_EDIT5);
	m_rgfUserInputMat[2][3] = ReadFromEditBox(_hDlg, IDC_EDIT6);

	MultiplyMatrix(_hDlg, m_rgfUserInputMat);
}

void CTransformation::ApplyRotation(HWND _hDlg)
{
	CreateIdentatyMatrix(m_rgfUserInputMat);

	float fMag = sqrt(
		pow(ReadFromEditBox(_hDlg, IDC_EDIT7), 2) +
		pow(ReadFromEditBox(_hDlg, IDC_EDIT28), 2) +
		pow(ReadFromEditBox(_hDlg, IDC_EDIT30), 2));

	float fX = ReadFromEditBox(_hDlg, IDC_EDIT7) / fMag;
	float fY = ReadFromEditBox(_hDlg, IDC_EDIT28) / fMag;
	float fZ = ReadFromEditBox(_hDlg, IDC_EDIT30) / fMag;
	float fCosTheta = cos(ReadFromEditBox(_hDlg, IDC_EDIT13));
	float fSinTheta = sin(ReadFromEditBox(_hDlg, IDC_EDIT13));

	m_rgfUserInputMat[0][0] = pow(fX, 2) * (1 - fCosTheta) + fCosTheta;
	m_rgfUserInputMat[0][1] = fX * fY * (1 - fCosTheta) - fZ * fSinTheta;
	m_rgfUserInputMat[0][2] = fX * fZ * (1 - fCosTheta) + fY * fSinTheta;

	m_rgfUserInputMat[1][0] = fX * fY * (1 - fCosTheta) + fZ * fSinTheta;
	m_rgfUserInputMat[1][1] = pow(fY, 2) * (1 - fCosTheta) + fCosTheta;
	m_rgfUserInputMat[1][2] = fY * fZ * (1 - fCosTheta) - fX * fSinTheta;

	m_rgfUserInputMat[2][0] = fX * fZ * (1 - fCosTheta) - fY * fSinTheta;
	m_rgfUserInputMat[2][1] = fY * fZ * (1 - fCosTheta) + fX * fSinTheta;
	m_rgfUserInputMat[2][2] = pow(fZ, 2) * (1 - fCosTheta) + fCosTheta;

	MultiplyMatrix(_hDlg, m_rgfUserInputMat);
}

void CTransformation::ApplyProjection(HWND _hDlg)
{
	CreateIdentatyMatrix(m_rgfUserInputMat);
	CreateIdentatyMatrix(m_rgfTempMat);

	float fMag = sqrt(
		pow(ReadFromEditBox(_hDlg, IDC_EDIT14), 2) +
		pow(ReadFromEditBox(_hDlg, IDC_EDIT29), 2) +
		pow(ReadFromEditBox(_hDlg, IDC_EDIT31), 2));

	m_rgfTempMat[3][2] = 1 / ReadFromEditBox(_hDlg, IDC_EDIT15);
	m_rgfTempMat[3][3] = 0;

	m_rgfUserInputMat[0][0] = 0;
	m_rgfUserInputMat[1][1] = 0;
	m_rgfUserInputMat[2][0] = ReadFromEditBox(_hDlg, IDC_EDIT14) / fMag;
	m_rgfUserInputMat[2][1] = ReadFromEditBox(_hDlg, IDC_EDIT29) / fMag;
	m_rgfUserInputMat[2][2] = ReadFromEditBox(_hDlg, IDC_EDIT31) / fMag;

	for (size_t i = 0; i < 4; ++i)
	{
		for (size_t j = 0; j < 4; ++j)
		{
			m_rgfProjectionMat[i][j] =
				m_rgfTempMat[i][0] * m_rgfUserInputMat[0][j] +
				m_rgfTempMat[i][1] * m_rgfUserInputMat[1][j] +
				m_rgfTempMat[i][2] * m_rgfUserInputMat[2][j] +
				m_rgfTempMat[i][3] * m_rgfUserInputMat[3][j];
		}
	}

	MultiplyMatrix(_hDlg, m_rgfProjectionMat);
}

void CTransformation::CreateIdentatyMatrix(float _rgMatrix[4][4])
{
	for (size_t i = 0; i < 4; ++i)
	{
		for (size_t j = 0; j < 4; ++j)
		{
			if (i == j)
			{
				_rgMatrix[i][j] = 1;
			}
			else
			{
				_rgMatrix[i][j] = 0;
			}
		}
	}
}

void CTransformation::PrintIdentityMatrix(HWND _hDlg)
{
	CreateIdentatyMatrix(m_rgfResultantMat);
	WriteToDialogBoxCMFormat(_hDlg);
	WriteToDialogBoxRMFormat(_hDlg);
}
