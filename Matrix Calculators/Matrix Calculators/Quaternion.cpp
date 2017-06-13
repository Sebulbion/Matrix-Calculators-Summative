#include "Quaternion.h"
#include "utils.h"

// Static variables
CQuaternion* CQuaternion::s_pQuaternion = 0;

CQuaternion::CQuaternion() :
	m_rgfQuaternionOne{ 0,0,0,0 },
	m_rgfQuaternionTwo{ 0,0,0,0 }
{

}

CQuaternion::~CQuaternion()
{
}

void CQuaternion::ReadInput(HWND _hDlg)
{
	m_rgfQuaternionOne[0] = ReadFromEditBox(_hDlg, IDC_EDIT1);
	m_rgfQuaternionOne[1] = ReadFromEditBox(_hDlg, IDC_EDIT2);
	m_rgfQuaternionOne[2] = ReadFromEditBox(_hDlg, IDC_EDIT3);
	m_rgfQuaternionOne[3] = ReadFromEditBox(_hDlg, IDC_EDIT4);

	m_rgfQuaternionTwo[0] = ReadFromEditBox(_hDlg, IDC_EDIT5);
	m_rgfQuaternionTwo[1] = ReadFromEditBox(_hDlg, IDC_EDIT6);
	m_rgfQuaternionTwo[2] = ReadFromEditBox(_hDlg, IDC_EDIT7);
	m_rgfQuaternionTwo[3] = ReadFromEditBox(_hDlg, IDC_EDIT8);
}

CQuaternion & CQuaternion::GetInstance()
{
	if (s_pQuaternion == 0)
	{
		s_pQuaternion = new CQuaternion();
	}

	return (*s_pQuaternion);
}

void CQuaternion::ResetInstance()
{
	delete s_pQuaternion;
	s_pQuaternion = nullptr;
}

void CQuaternion::ApplyAddition(HWND _hDlg)
{
	ReadInput(_hDlg);
	
	WriteToEditBox(_hDlg, IDC_EDIT10, m_rgfQuaternionOne[0] + m_rgfQuaternionTwo[0]);
	WriteToEditBox(_hDlg, IDC_EDIT11, m_rgfQuaternionOne[1] + m_rgfQuaternionTwo[1]);
	WriteToEditBox(_hDlg, IDC_EDIT12, m_rgfQuaternionOne[2] + m_rgfQuaternionTwo[2]);
	WriteToEditBox(_hDlg, IDC_EDIT13, m_rgfQuaternionOne[3] + m_rgfQuaternionTwo[3]);
}

void CQuaternion::ApplySubtraction(HWND _hDlg, bool _bAMinusB)
{
	ReadInput(_hDlg);

	// This calculates a-b and prints the result as ether positive or negative depending on the bool _bAMinusB (a-b = (b-a) * -1)
	WriteToEditBox(_hDlg, IDC_EDIT10, (m_rgfQuaternionOne[0] - m_rgfQuaternionTwo[0]) * (_bAMinusB? 1: -1));
	WriteToEditBox(_hDlg, IDC_EDIT11, (m_rgfQuaternionOne[1] - m_rgfQuaternionTwo[1]) * (_bAMinusB? 1: -1));
	WriteToEditBox(_hDlg, IDC_EDIT12, (m_rgfQuaternionOne[2] - m_rgfQuaternionTwo[2]) * (_bAMinusB? 1: -1));
	WriteToEditBox(_hDlg, IDC_EDIT13, (m_rgfQuaternionOne[3] - m_rgfQuaternionTwo[3]) * (_bAMinusB? 1: -1));
}

void CQuaternion::ApplyMultiplication(HWND _hDlg, bool _bATimesB)
{
	ReadInput(_hDlg);

	float fReal = 0;
	float fI = 0;
	float fJ = 0;
	float fK = 0;

	fReal += m_rgfQuaternionOne[0] * m_rgfQuaternionTwo[0];
	fReal -= m_rgfQuaternionOne[1] * m_rgfQuaternionTwo[1];
	fReal -= m_rgfQuaternionOne[2] * m_rgfQuaternionTwo[2];
	fReal -= m_rgfQuaternionOne[3] * m_rgfQuaternionTwo[3];

	fI += m_rgfQuaternionOne[0] * m_rgfQuaternionTwo[1];
	fI += m_rgfQuaternionOne[1] * m_rgfQuaternionTwo[0];
	

	fJ += m_rgfQuaternionOne[0] * m_rgfQuaternionTwo[2];
	fJ += m_rgfQuaternionOne[2] * m_rgfQuaternionTwo[0];
	

	fK += m_rgfQuaternionOne[0] * m_rgfQuaternionTwo[3];
	fK += m_rgfQuaternionOne[3] * m_rgfQuaternionTwo[0];
	

	if (_bATimesB)
	{
		fI += m_rgfQuaternionOne[2] * m_rgfQuaternionTwo[3];
		fI -= m_rgfQuaternionOne[3] * m_rgfQuaternionTwo[2];

		fJ += m_rgfQuaternionOne[3] * m_rgfQuaternionTwo[1];
		fJ -= m_rgfQuaternionOne[1] * m_rgfQuaternionTwo[3];

		fK += m_rgfQuaternionOne[1] * m_rgfQuaternionTwo[2];
		fK -= m_rgfQuaternionOne[2] * m_rgfQuaternionTwo[1];
	}
	else
	{
		fI -= m_rgfQuaternionOne[2] * m_rgfQuaternionTwo[3];
		fI += m_rgfQuaternionOne[3] * m_rgfQuaternionTwo[2];

		fJ -= m_rgfQuaternionOne[3] * m_rgfQuaternionTwo[1];
		fJ += m_rgfQuaternionOne[1] * m_rgfQuaternionTwo[3];

		fK -= m_rgfQuaternionOne[1] * m_rgfQuaternionTwo[2];
		fK += m_rgfQuaternionOne[2] * m_rgfQuaternionTwo[1];
	}

	WriteToEditBox(_hDlg, IDC_EDIT10, fReal);
	WriteToEditBox(_hDlg, IDC_EDIT11, fI);
	WriteToEditBox(_hDlg, IDC_EDIT12, fJ);
	WriteToEditBox(_hDlg, IDC_EDIT13, fK);
}

void CQuaternion::ApplyDotProduct(HWND _hDlg)
{
	ReadInput(_hDlg);
	float _fResult = 0;

	for (int i = 0; i < 4; i++)
	{
		_fResult += m_rgfQuaternionOne[i] * m_rgfQuaternionTwo[i];
	}
	
	WriteToEditBox(_hDlg, IDC_EDIT27, _fResult);
}

void CQuaternion::ApplyConjugate(HWND _hDlg, bool _bIsA)
{
	ReadInput(_hDlg);

	if (_bIsA)
	{
		WriteToEditBox(_hDlg, IDC_EDIT10, m_rgfQuaternionOne[0]);
		WriteToEditBox(_hDlg, IDC_EDIT11, -m_rgfQuaternionOne[1]);
		WriteToEditBox(_hDlg, IDC_EDIT12, -m_rgfQuaternionOne[2]);
		WriteToEditBox(_hDlg, IDC_EDIT13, -m_rgfQuaternionOne[3]);
	}
	else
	{
		WriteToEditBox(_hDlg, IDC_EDIT10, m_rgfQuaternionTwo[0]);
		WriteToEditBox(_hDlg, IDC_EDIT11, -m_rgfQuaternionTwo[1]);
		WriteToEditBox(_hDlg, IDC_EDIT12, -m_rgfQuaternionTwo[2]);
		WriteToEditBox(_hDlg, IDC_EDIT13, -m_rgfQuaternionTwo[3]);
	}
}

void CQuaternion::ApplyMagnitude(HWND _hDlg, bool _bIsA)
{
	ReadInput(_hDlg);

	if (_bIsA)
	{
		WriteToEditBox(_hDlg, IDC_EDIT9, std::sqrt(m_rgfQuaternionOne[0] * m_rgfQuaternionOne[0] + m_rgfQuaternionOne[1] * m_rgfQuaternionOne[1] +
			m_rgfQuaternionOne[2] * m_rgfQuaternionOne[2] + m_rgfQuaternionOne[3] * m_rgfQuaternionOne[3]));
	}
	else
	{
		WriteToEditBox(_hDlg, IDC_EDIT9, std::sqrt(m_rgfQuaternionTwo[0] * m_rgfQuaternionTwo[0] + m_rgfQuaternionTwo[1] * m_rgfQuaternionTwo[1] +
			m_rgfQuaternionTwo[2] * m_rgfQuaternionTwo[2] + m_rgfQuaternionTwo[3] * m_rgfQuaternionTwo[3]));
	}
}

void CQuaternion::ApplyInverse(HWND _hDlg, bool _bIsA)
{
	ReadInput(_hDlg);
	float fMagnitude;

	if (_bIsA)
	{
		fMagnitude = std::sqrt(m_rgfQuaternionOne[0] * m_rgfQuaternionOne[0] + m_rgfQuaternionOne[1] * m_rgfQuaternionOne[1] +
			m_rgfQuaternionOne[2] * m_rgfQuaternionOne[2] + m_rgfQuaternionOne[3] * m_rgfQuaternionOne[3]);

		WriteToEditBox(_hDlg, IDC_EDIT10, m_rgfQuaternionOne[0] / (fMagnitude * fMagnitude));
		WriteToEditBox(_hDlg, IDC_EDIT11, -m_rgfQuaternionOne[1] / (fMagnitude * fMagnitude));
		WriteToEditBox(_hDlg, IDC_EDIT12, -m_rgfQuaternionOne[2] / (fMagnitude * fMagnitude));
		WriteToEditBox(_hDlg, IDC_EDIT13, -m_rgfQuaternionOne[3] / (fMagnitude * fMagnitude));
	}
	else
	{
		fMagnitude = std::sqrt(m_rgfQuaternionTwo[0] * m_rgfQuaternionTwo[0] + m_rgfQuaternionTwo[1] * m_rgfQuaternionTwo[1] +
			m_rgfQuaternionTwo[2] * m_rgfQuaternionTwo[2] + m_rgfQuaternionTwo[3] * m_rgfQuaternionTwo[3]);

		WriteToEditBox(_hDlg, IDC_EDIT10, m_rgfQuaternionTwo[0] / (fMagnitude * fMagnitude));
		WriteToEditBox(_hDlg, IDC_EDIT11, -m_rgfQuaternionTwo[1] / (fMagnitude * fMagnitude));
		WriteToEditBox(_hDlg, IDC_EDIT12, -m_rgfQuaternionTwo[2] / (fMagnitude * fMagnitude));
		WriteToEditBox(_hDlg, IDC_EDIT13, -m_rgfQuaternionTwo[3] / (fMagnitude * fMagnitude));
	}
}

void CQuaternion::ApplyScalar(HWND _hDlg, bool _bIsA)
{
	ReadInput(_hDlg);

	if (_bIsA)
	{
		WriteToEditBox(_hDlg, IDC_EDIT10, m_rgfQuaternionOne[0] * ReadFromEditBox(_hDlg, IDC_EDIT14));
		WriteToEditBox(_hDlg, IDC_EDIT11, m_rgfQuaternionOne[1] * ReadFromEditBox(_hDlg, IDC_EDIT14));
		WriteToEditBox(_hDlg, IDC_EDIT12, m_rgfQuaternionOne[2] * ReadFromEditBox(_hDlg, IDC_EDIT14));
		WriteToEditBox(_hDlg, IDC_EDIT13, m_rgfQuaternionOne[3] * ReadFromEditBox(_hDlg, IDC_EDIT14));
	}
	else
	{
		WriteToEditBox(_hDlg, IDC_EDIT10, m_rgfQuaternionTwo[0] * ReadFromEditBox(_hDlg, IDC_EDIT14));
		WriteToEditBox(_hDlg, IDC_EDIT11, m_rgfQuaternionTwo[1] * ReadFromEditBox(_hDlg, IDC_EDIT14));
		WriteToEditBox(_hDlg, IDC_EDIT12, m_rgfQuaternionTwo[2] * ReadFromEditBox(_hDlg, IDC_EDIT14));
		WriteToEditBox(_hDlg, IDC_EDIT13, m_rgfQuaternionTwo[3] * ReadFromEditBox(_hDlg, IDC_EDIT14));
	}
}
