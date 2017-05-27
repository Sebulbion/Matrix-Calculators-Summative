#include "Transformation.h"

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



//void CTransformation::SetResultantMat(float _rgInputMat[4][4])
//{
//	for (size_t i = 0; i < 4; ++i)
//	{
//		for (size_t j = 0; j < 4; ++j)
//		{
//			m_rgfResultantMat[i][j] = _rgInputMat[i][j];
//		}
//	}
//}

void CTransformation::MultiplyMatrix(float _rgInputMat[4][4], float _rgResultMat[4][4])
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

	_rgResultMat = m_rgfResultantMat;
}

void CTransformation::ApplyScaling(float _X, float _Y, float _Z, float _rgResultMat[4][4])
{
	CreateIdentatyMatrix(m_rgfTempMat);
	m_rgfTempMat[0][3] = _X;
	m_rgfTempMat[1][3] = _Y;
	m_rgfTempMat[2][3] = _Z;

	MultiplyMatrix(m_rgfTempMat, _rgResultMat);
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
