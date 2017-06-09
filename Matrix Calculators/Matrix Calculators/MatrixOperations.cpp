#include "MatrixOperations.h"
#include "utils.h"


CMatrixOperations::CMatrixOperations()
{
	m_vecMatrixEditsA.push_back(IDC_EDIT_A11);
	m_vecMatrixEditsA.push_back(IDC_EDIT_A12);
	m_vecMatrixEditsA.push_back(IDC_EDIT_A13);
	m_vecMatrixEditsA.push_back(IDC_EDIT_A14);
	m_vecMatrixEditsA.push_back(IDC_EDIT_A21);
	m_vecMatrixEditsA.push_back(IDC_EDIT_A22);
	m_vecMatrixEditsA.push_back(IDC_EDIT_A23);
	m_vecMatrixEditsA.push_back(IDC_EDIT_A24);
	m_vecMatrixEditsA.push_back(IDC_EDIT_A31);
	m_vecMatrixEditsA.push_back(IDC_EDIT_A32);
	m_vecMatrixEditsA.push_back(IDC_EDIT_A33);
	m_vecMatrixEditsA.push_back(IDC_EDIT_A34);
	m_vecMatrixEditsA.push_back(IDC_EDIT_A41);
	m_vecMatrixEditsA.push_back(IDC_EDIT_A42);
	m_vecMatrixEditsA.push_back(IDC_EDIT_A43);
	m_vecMatrixEditsA.push_back(IDC_EDIT_A44);

	m_vecMatrixEditsB.push_back(IDC_EDIT_B11);
	m_vecMatrixEditsB.push_back(IDC_EDIT_B12);
	m_vecMatrixEditsB.push_back(IDC_EDIT_B13);
	m_vecMatrixEditsB.push_back(IDC_EDIT_B14);
	m_vecMatrixEditsB.push_back(IDC_EDIT_B21);
	m_vecMatrixEditsB.push_back(IDC_EDIT_B22);
	m_vecMatrixEditsB.push_back(IDC_EDIT_B23);
	m_vecMatrixEditsB.push_back(IDC_EDIT_B24);
	m_vecMatrixEditsB.push_back(IDC_EDIT_B31);
	m_vecMatrixEditsB.push_back(IDC_EDIT_B32);
	m_vecMatrixEditsB.push_back(IDC_EDIT_B33);
	m_vecMatrixEditsB.push_back(IDC_EDIT_B34);
	m_vecMatrixEditsB.push_back(IDC_EDIT_B41);
	m_vecMatrixEditsB.push_back(IDC_EDIT_B42);
	m_vecMatrixEditsB.push_back(IDC_EDIT_B43);
	m_vecMatrixEditsB.push_back(IDC_EDIT_B44);

	m_vecMatrixEditsR.push_back(IDC_EDIT_R11);
	m_vecMatrixEditsR.push_back(IDC_EDIT_R12);
	m_vecMatrixEditsR.push_back(IDC_EDIT_R13);
	m_vecMatrixEditsR.push_back(IDC_EDIT_R14);
	m_vecMatrixEditsR.push_back(IDC_EDIT_R21);
	m_vecMatrixEditsR.push_back(IDC_EDIT_R22);
	m_vecMatrixEditsR.push_back(IDC_EDIT_R23);
	m_vecMatrixEditsR.push_back(IDC_EDIT_R24);
	m_vecMatrixEditsR.push_back(IDC_EDIT_R31);
	m_vecMatrixEditsR.push_back(IDC_EDIT_R32);
	m_vecMatrixEditsR.push_back(IDC_EDIT_R33);
	m_vecMatrixEditsR.push_back(IDC_EDIT_R34);
	m_vecMatrixEditsR.push_back(IDC_EDIT_R41);
	m_vecMatrixEditsR.push_back(IDC_EDIT_R42);
	m_vecMatrixEditsR.push_back(IDC_EDIT_R43);
	m_vecMatrixEditsR.push_back(IDC_EDIT_R44);
	
	for (int i = 0; i < 16; i++)
	{
		m_vecfMatrixR.push_back(0);
	}

}


CMatrixOperations::~CMatrixOperations()
{
}

void CMatrixOperations::GetMatrixA(HWND _hDlg)
{
	m_vecfMatrixA.push_back(ReadFromEditBox(_hDlg, IDC_EDIT_A11));
	m_vecfMatrixA.push_back(ReadFromEditBox(_hDlg, IDC_EDIT_A12));
	m_vecfMatrixA.push_back(ReadFromEditBox(_hDlg, IDC_EDIT_A13));
	m_vecfMatrixA.push_back(ReadFromEditBox(_hDlg, IDC_EDIT_A14));
	m_vecfMatrixA.push_back(ReadFromEditBox(_hDlg, IDC_EDIT_A21));
	m_vecfMatrixA.push_back(ReadFromEditBox(_hDlg, IDC_EDIT_A22));
	m_vecfMatrixA.push_back(ReadFromEditBox(_hDlg, IDC_EDIT_A23));
	m_vecfMatrixA.push_back(ReadFromEditBox(_hDlg, IDC_EDIT_A24));
	m_vecfMatrixA.push_back(ReadFromEditBox(_hDlg, IDC_EDIT_A31));
	m_vecfMatrixA.push_back(ReadFromEditBox(_hDlg, IDC_EDIT_A32));
	m_vecfMatrixA.push_back(ReadFromEditBox(_hDlg, IDC_EDIT_A33));
	m_vecfMatrixA.push_back(ReadFromEditBox(_hDlg, IDC_EDIT_A34));
	m_vecfMatrixA.push_back(ReadFromEditBox(_hDlg, IDC_EDIT_A41));
	m_vecfMatrixA.push_back(ReadFromEditBox(_hDlg, IDC_EDIT_A42));
	m_vecfMatrixA.push_back(ReadFromEditBox(_hDlg, IDC_EDIT_A43));
	m_vecfMatrixA.push_back(ReadFromEditBox(_hDlg, IDC_EDIT_A44));
}


void CMatrixOperations::GetMatrixB(HWND _hDlg)
{
	m_vecfMatrixB.push_back(ReadFromEditBox(_hDlg, IDC_EDIT_B11));
	m_vecfMatrixB.push_back(ReadFromEditBox(_hDlg, IDC_EDIT_B12));
	m_vecfMatrixB.push_back(ReadFromEditBox(_hDlg, IDC_EDIT_B13));
	m_vecfMatrixB.push_back(ReadFromEditBox(_hDlg, IDC_EDIT_B14));
	m_vecfMatrixB.push_back(ReadFromEditBox(_hDlg, IDC_EDIT_B21));
	m_vecfMatrixB.push_back(ReadFromEditBox(_hDlg, IDC_EDIT_B22));
	m_vecfMatrixB.push_back(ReadFromEditBox(_hDlg, IDC_EDIT_B23));
	m_vecfMatrixB.push_back(ReadFromEditBox(_hDlg, IDC_EDIT_B24));
	m_vecfMatrixB.push_back(ReadFromEditBox(_hDlg, IDC_EDIT_B31));
	m_vecfMatrixB.push_back(ReadFromEditBox(_hDlg, IDC_EDIT_B32));
	m_vecfMatrixB.push_back(ReadFromEditBox(_hDlg, IDC_EDIT_B33));
	m_vecfMatrixB.push_back(ReadFromEditBox(_hDlg, IDC_EDIT_B34));
	m_vecfMatrixB.push_back(ReadFromEditBox(_hDlg, IDC_EDIT_B41));
	m_vecfMatrixB.push_back(ReadFromEditBox(_hDlg, IDC_EDIT_B42));
	m_vecfMatrixB.push_back(ReadFromEditBox(_hDlg, IDC_EDIT_B43));
	m_vecfMatrixB.push_back(ReadFromEditBox(_hDlg, IDC_EDIT_B44));
}

void CMatrixOperations::WriteMatrix(HWND _hDlg)
{
	// Write A
	for (int i = 0; i < m_vecfMatrixA.size(); i++)
	{
		WriteToEditBox(_hDlg, m_vecMatrixEditsA.at(i), m_vecfMatrixA.at(i)+0); // Plus zero so negative zero
	}
	// Write B
	for (int i = 0; i < m_vecfMatrixB.size(); i++)
	{
		WriteToEditBox(_hDlg, m_vecMatrixEditsB.at(i), m_vecfMatrixB.at(i)+0);
	}
	// Write R
	for (int i = 0; i < m_vecfMatrixR.size(); i++)
	{
		WriteToEditBox(_hDlg, m_vecMatrixEditsR.at(i), m_vecfMatrixR.at(i)+0);
	}
}

void CMatrixOperations::Identity(bool _bIsA)
{
	std::vector<float>* tempMatrix;

	if (_bIsA)
	{
		tempMatrix = &m_vecfMatrixA;
	}
	else
	{
		tempMatrix = &m_vecfMatrixB;
	}

	for (int i = 0; i < tempMatrix->size(); i++)
	{
		if (i == 0 || i == 5 || i == 10 || i == 15)
		{
			tempMatrix->at(i) = 1;

		}
		else
		{
			tempMatrix->at(i) = 0;
		}
	}
	
}

int CMatrixOperations::Determinant(HWND _hDlg, bool _bIsA)
{
	float fTempMatrix[4][4];
	std::vector<float>* fInputMatrix;
	int k = 0;
	float fMinor[3][3];


	if (_bIsA)
	{
		fInputMatrix = &m_vecfMatrixA;
	}
	else
	{
		fInputMatrix = &m_vecfMatrixB;
	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			fTempMatrix[i][j] = fInputMatrix->at(k);
			k++;
		}
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			fMinor[i][j] = fTempMatrix[i+1][j+1];
		}
	}

	float fMinA = fTempMatrix[0][0] * Det3D(fMinor);

	// borked?

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (j == 0)
			{
				fMinor[i][j] = fTempMatrix[i+1][j];
			}
			else
			{
				fMinor[i][j] = fTempMatrix[i+1][j+1];
			}
		}
	}

	float fMinB = fTempMatrix[0][1] * Det3D(fMinor);

	

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (j == 2)
			{
				fMinor[i][j] = fTempMatrix[i+1][j+1];
			}
			else
			{
				fMinor[i][j] = fTempMatrix[i+1][j];
			}
		}
	}

	float fMinC = fTempMatrix[0][2] * Det3D(fMinor);

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			fMinor[i][j] = fTempMatrix[i+1][j];
		}
	}

	float fMinD = fTempMatrix[0][3] * Det3D(fMinor);

	if (_bIsA)
	{
		WriteToEditBox(_hDlg, IDC_EDIT_DetA, fMinA - fMinB + fMinC - fMinD);

	}
	else
	{
		WriteToEditBox(_hDlg, IDC_EDIT_DetB, fMinA - fMinB + fMinC - fMinD);
	}

	return fMinA - fMinB + fMinC - fMinD;

}

void CMatrixOperations::Transpose(bool _bIsA)
{
	std::vector<float>* tempMatrix;

	if (_bIsA)
	{
		tempMatrix = &m_vecfMatrixA;
	}
	else
	{
		tempMatrix = &m_vecfMatrixB;
	}

	float tempMatrix2DArray[4][4];

	int k = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			tempMatrix2DArray[j][i] = tempMatrix->at(k);
			k++;
		}
	}

	k = 0;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			tempMatrix->at(k) = tempMatrix2DArray[i][j];
			k++;
		}
	}
}

void CMatrixOperations::Inverse(HWND _hDlg, bool _bIsA)
{
	float D = Determinant(_hDlg,_bIsA);
	std::vector<float>* fvecInputMatrix;
	//std::vector<float>* fvecResultVector;


	if (_bIsA)
	{
		fvecInputMatrix = &m_vecfMatrixA;
	}
	else
	{
		fvecInputMatrix = &m_vecfMatrixB;
	}

	int k = 0;
	float fInputMatrix[4][4];
	float fResultMatrix[4][4];


	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			fInputMatrix[i][j] = fvecInputMatrix->at(k);
			k++;
		}
	}

	if (D == 0)
	{
		return;
	}
	else
	{
		fResultMatrix[0][0] = ((fInputMatrix[1][1] * fInputMatrix[2][2] * fInputMatrix[3][3]) + (fInputMatrix[1][2] * fInputMatrix[2][3] * fInputMatrix[3][1]) + (fInputMatrix[1][3] * fInputMatrix[2][1] * fInputMatrix[3][2])
			- (fInputMatrix[1][1] * fInputMatrix[2][3] * fInputMatrix[3][2]) - (fInputMatrix[1][2] * fInputMatrix[2][1] * fInputMatrix[3][3]) - (fInputMatrix[1][3] * fInputMatrix[2][2] * fInputMatrix[3][1])) / D;
		fResultMatrix[0][1] = ((fInputMatrix[0][1] * fInputMatrix[2][3] * fInputMatrix[3][2]) + (fInputMatrix[0][2] * fInputMatrix[2][1] * fInputMatrix[3][3]) + (fInputMatrix[0][3] * fInputMatrix[2][2] * fInputMatrix[3][1])
			- (fInputMatrix[0][1] * fInputMatrix[2][2] * fInputMatrix[3][3]) - (fInputMatrix[0][2] * fInputMatrix[2][3] * fInputMatrix[3][1]) - (fInputMatrix[0][3] * fInputMatrix[2][1] * fInputMatrix[3][2])) / D;
		fResultMatrix[0][2] = ((fInputMatrix[0][1] * fInputMatrix[1][2] * fInputMatrix[3][3]) + (fInputMatrix[0][2] * fInputMatrix[1][3] * fInputMatrix[3][1]) + (fInputMatrix[0][3] * fInputMatrix[1][1] * fInputMatrix[3][2])
			- (fInputMatrix[0][1] * fInputMatrix[1][3] * fInputMatrix[3][2]) - (fInputMatrix[0][2] * fInputMatrix[1][1] * fInputMatrix[3][3]) - (fInputMatrix[0][3] * fInputMatrix[1][2] * fInputMatrix[3][1])) / D;
		fResultMatrix[0][3] = ((fInputMatrix[0][1] * fInputMatrix[1][3] * fInputMatrix[2][2]) + (fInputMatrix[0][2] * fInputMatrix[1][1] * fInputMatrix[2][3]) + (fInputMatrix[0][3] * fInputMatrix[1][2] * fInputMatrix[2][1])
			- (fInputMatrix[0][1] * fInputMatrix[1][2] * fInputMatrix[2][3]) - (fInputMatrix[0][2] * fInputMatrix[1][3] * fInputMatrix[2][1]) - (fInputMatrix[0][3] * fInputMatrix[1][1] * fInputMatrix[2][2])) / D;
		fResultMatrix[1][0] = ((fInputMatrix[1][0] * fInputMatrix[2][3] * fInputMatrix[3][2]) + (fInputMatrix[1][2] * fInputMatrix[2][0] * fInputMatrix[3][3]) + (fInputMatrix[1][3] * fInputMatrix[2][2] * fInputMatrix[3][0])
			- (fInputMatrix[1][0] * fInputMatrix[2][2] * fInputMatrix[3][3]) - (fInputMatrix[1][2] * fInputMatrix[2][3] * fInputMatrix[3][1]) - (fInputMatrix[1][3] * fInputMatrix[2][0] * fInputMatrix[3][2])) / D;
		fResultMatrix[1][1] = ((fInputMatrix[0][0] * fInputMatrix[2][2] * fInputMatrix[3][3]) + (fInputMatrix[0][2] * fInputMatrix[2][3] * fInputMatrix[3][0]) + (fInputMatrix[0][3] * fInputMatrix[2][0] * fInputMatrix[3][2])
			- (fInputMatrix[0][0] * fInputMatrix[2][3] * fInputMatrix[3][2]) - (fInputMatrix[0][2] * fInputMatrix[2][0] * fInputMatrix[3][3]) - (fInputMatrix[0][3] * fInputMatrix[2][2] * fInputMatrix[3][0])) / D;
		fResultMatrix[1][2] = ((fInputMatrix[0][0] * fInputMatrix[1][3] * fInputMatrix[3][2]) + (fInputMatrix[0][2] * fInputMatrix[1][0] * fInputMatrix[3][3]) + (fInputMatrix[0][3] * fInputMatrix[1][2] * fInputMatrix[3][0])
			- (fInputMatrix[0][0] * fInputMatrix[1][2] * fInputMatrix[3][3]) - (fInputMatrix[0][2] * fInputMatrix[1][3] * fInputMatrix[3][0]) - (fInputMatrix[0][3] * fInputMatrix[1][0] * fInputMatrix[3][2])) / D;
		fResultMatrix[1][3] = ((fInputMatrix[0][0] * fInputMatrix[1][2] * fInputMatrix[2][3]) + (fInputMatrix[0][2] * fInputMatrix[1][3] * fInputMatrix[2][0]) + (fInputMatrix[0][3] * fInputMatrix[1][0] * fInputMatrix[2][2])
			- (fInputMatrix[0][0] * fInputMatrix[1][3] * fInputMatrix[2][2]) - (fInputMatrix[0][2] * fInputMatrix[1][0] * fInputMatrix[2][3]) - (fInputMatrix[0][3] * fInputMatrix[1][2] * fInputMatrix[2][0])) / D;
		fResultMatrix[2][0] = ((fInputMatrix[1][0] * fInputMatrix[2][1] * fInputMatrix[3][3]) + (fInputMatrix[1][1] * fInputMatrix[2][3] * fInputMatrix[3][0]) + (fInputMatrix[1][3] * fInputMatrix[2][0] * fInputMatrix[3][1])
			- (fInputMatrix[1][0] * fInputMatrix[2][3] * fInputMatrix[3][1]) - (fInputMatrix[1][1] * fInputMatrix[2][0] * fInputMatrix[3][3]) - (fInputMatrix[1][3] * fInputMatrix[2][1] * fInputMatrix[3][0])) / D;
		fResultMatrix[2][1] = ((fInputMatrix[0][0] * fInputMatrix[2][3] * fInputMatrix[3][1]) + (fInputMatrix[0][1] * fInputMatrix[2][0] * fInputMatrix[3][3]) + (fInputMatrix[0][3] * fInputMatrix[2][1] * fInputMatrix[3][0])
			- (fInputMatrix[0][0] * fInputMatrix[2][1] * fInputMatrix[3][3]) - (fInputMatrix[0][1] * fInputMatrix[2][3] * fInputMatrix[3][1]) - (fInputMatrix[0][3] * fInputMatrix[2][0] * fInputMatrix[3][1])) / D;
		fResultMatrix[2][2] = ((fInputMatrix[0][0] * fInputMatrix[1][1] * fInputMatrix[3][3]) + (fInputMatrix[0][1] * fInputMatrix[1][3] * fInputMatrix[3][0]) + (fInputMatrix[0][3] * fInputMatrix[1][0] * fInputMatrix[3][1])
			- (fInputMatrix[0][0] * fInputMatrix[1][3] * fInputMatrix[3][1]) - (fInputMatrix[0][1] * fInputMatrix[1][0] * fInputMatrix[3][3]) - (fInputMatrix[0][3] * fInputMatrix[1][1] * fInputMatrix[3][0])) / D;
		fResultMatrix[2][3] = ((fInputMatrix[0][0] * fInputMatrix[1][3] * fInputMatrix[2][1]) + (fInputMatrix[0][1] * fInputMatrix[1][0] * fInputMatrix[2][3]) + (fInputMatrix[0][3] * fInputMatrix[1][1] * fInputMatrix[2][0])
			- (fInputMatrix[0][0] * fInputMatrix[1][1] * fInputMatrix[2][3]) - (fInputMatrix[0][1] * fInputMatrix[1][3] * fInputMatrix[2][0]) - (fInputMatrix[0][3] * fInputMatrix[1][0] * fInputMatrix[2][1])) / D;
		fResultMatrix[3][0] = ((fInputMatrix[1][0] * fInputMatrix[2][2] * fInputMatrix[3][1]) + (fInputMatrix[1][1] * fInputMatrix[2][0] * fInputMatrix[3][2]) + (fInputMatrix[1][2] * fInputMatrix[2][1] * fInputMatrix[3][0])
			- (fInputMatrix[1][0] * fInputMatrix[2][1] * fInputMatrix[3][2]) - (fInputMatrix[1][1] * fInputMatrix[2][2] * fInputMatrix[3][0]) - (fInputMatrix[1][2] * fInputMatrix[2][0] * fInputMatrix[3][1])) / D;
		fResultMatrix[3][1] = ((fInputMatrix[0][0] * fInputMatrix[2][1] * fInputMatrix[3][2]) + (fInputMatrix[0][1] * fInputMatrix[2][2] * fInputMatrix[3][0]) + (fInputMatrix[0][2] * fInputMatrix[2][0] * fInputMatrix[3][1])
			- (fInputMatrix[0][0] * fInputMatrix[2][2] * fInputMatrix[3][1]) - (fInputMatrix[0][1] * fInputMatrix[2][0] * fInputMatrix[3][2]) - (fInputMatrix[0][2] * fInputMatrix[2][1] * fInputMatrix[3][0])) / D;
		fResultMatrix[3][2] = ((fInputMatrix[0][0] * fInputMatrix[1][2] * fInputMatrix[3][1]) + (fInputMatrix[0][1] * fInputMatrix[1][0] * fInputMatrix[3][2]) + (fInputMatrix[0][2] * fInputMatrix[1][1] * fInputMatrix[3][0])
			- (fInputMatrix[0][0] * fInputMatrix[1][1] * fInputMatrix[3][2]) - (fInputMatrix[0][1] * fInputMatrix[1][2] * fInputMatrix[3][0]) - (fInputMatrix[0][2] * fInputMatrix[1][0] * fInputMatrix[3][1])) / D;
		fResultMatrix[3][3] = ((fInputMatrix[0][0] * fInputMatrix[1][1] * fInputMatrix[2][2]) + (fInputMatrix[0][1] * fInputMatrix[1][2] * fInputMatrix[2][0]) + (fInputMatrix[0][2] * fInputMatrix[1][0] * fInputMatrix[2][1])
			- (fInputMatrix[0][0] * fInputMatrix[1][2] * fInputMatrix[2][1]) - (fInputMatrix[0][1] * fInputMatrix[1][0] * fInputMatrix[2][2]) - (fInputMatrix[0][2] * fInputMatrix[1][1] * fInputMatrix[2][0])) / D;
	}

	k = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			//fvecResultVector->at(k) = fResultMatrix[i][j];
			if (_bIsA)
			{
				m_vecfMatrixA.at(k) = fResultMatrix[i][j];

			}
			else
			{
				m_vecfMatrixB.at(k) = fResultMatrix[i][j];
			}
			k++;
		}
	}

	WriteMatrix(_hDlg);
}

void CMatrixOperations::ScalarMultiply(bool _bIsA, HWND _hDlg)
{
	std::vector<float>* tempMatrix;
	int iScalar; 

	if (_bIsA)
	{
		tempMatrix = &m_vecfMatrixA;
		iScalar = ReadFromEditBox(_hDlg, IDC_EDIT_AScaled);
	}
	else
	{
		tempMatrix = &m_vecfMatrixB;
		iScalar = ReadFromEditBox(_hDlg, IDC_EDIT_BScaled);

	}

	for (int i = 0; i < tempMatrix->size(); i++)
	{
		tempMatrix->at(i) *= iScalar;
	}


}

void CMatrixOperations::Addition()
{
	for (int i = 0; i < 16; i++)
	{
		m_vecfMatrixR.at(i) = m_vecfMatrixA.at(i) + m_vecfMatrixB.at(i);
	}
}

void CMatrixOperations::Subtraction(bool _bIsA)
{
	for (int i = 0; i < 16; i++)
	{
		if (_bIsA)
		{
			m_vecfMatrixR.at(i) = m_vecfMatrixA.at(i) - m_vecfMatrixB.at(i);

		}
		else
		{
			m_vecfMatrixR.at(i) = m_vecfMatrixB.at(i) - m_vecfMatrixA.at(i);
		}
	}
}

void CMatrixOperations::Multiply(bool _bIsA)
{
	int k = 0;
	float temp2DA[4][4];
	float temp2DB[4][4];
	float temp2DR[4][4];

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			temp2DA[i][j] = m_vecfMatrixA.at(k);
			k++;
		}
	}
	k = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			temp2DB[i][j] = m_vecfMatrixB.at(k);
			k++;
		}
	}

	int l = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				if(_bIsA == true)
				{
					m_vecfMatrixR.at(l) += (temp2DA[i][k] * temp2DB[k][j]);
				}
				else
				{
					m_vecfMatrixR.at(l) += (temp2DB[i][k] * temp2DA[k][j]);

				}
				
			}
			l++;

		}
	}
}

float CMatrixOperations::Det3D(float _rgfMatrix[3][3])
{
	float tempA = (_rgfMatrix[0][0] * ((_rgfMatrix[1][1] * _rgfMatrix[2][2]) - (_rgfMatrix[1][2] * _rgfMatrix[2][1])));
	float tempB = (_rgfMatrix[0][1] * ((_rgfMatrix[1][0] * _rgfMatrix[2][2]) - (_rgfMatrix[2][0] * _rgfMatrix[1][2])));
	float tempC = (_rgfMatrix[0][2] * ((_rgfMatrix[1][0] * _rgfMatrix[2][1]) - (_rgfMatrix[2][0] * _rgfMatrix[1][1])));

	return (tempA - tempB + tempC);
}
