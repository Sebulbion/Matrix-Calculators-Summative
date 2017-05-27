#include "Transformation.h"
#include "utils.h"

// Static variables
CTransformation* CTransformation::s_pTransformation = 0;

CTransformation::CTransformation()
{
}


CTransformation::~CTransformation()
{
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

void CTransformation::MultiplyMatrix(HWND _hDlg, float _rgInputMat[4][4])
{
	for (size_t i = 0; i < 4; ++i)
	{
		for (size_t j = 0; j < 4; ++j)
		{
			m_rgfResultantMat[i][j] =
				m_rgfResultantMat[i][j] * _rgInputMat[i][j] +
				m_rgfResultantMat[i][(j + 1) % 4] * _rgInputMat[(j + 1) % 4][i] +
				m_rgfResultantMat[i][(j + 2) % 4] * _rgInputMat[(j + 2) % 4][i] +
				m_rgfResultantMat[i][(j + 3) % 4] * _rgInputMat[(j + 3) % 4][i];
		}
	}

	WriteToDialogBoxCMFormat(_hDlg);
}

void CTransformation::ApplyScaling(HWND _hDlg)
{
	CreateIdentatyMatrix(m_rgfTempMat);
	m_rgfTempMat[0][0] = ReadFromEditBox(_hDlg, IDC_EDIT1);
	m_rgfTempMat[1][1] = ReadFromEditBox(_hDlg, IDC_EDIT2);
	m_rgfTempMat[2][2] = ReadFromEditBox(_hDlg, IDC_EDIT3);

	MultiplyMatrix(_hDlg, m_rgfTempMat);
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
