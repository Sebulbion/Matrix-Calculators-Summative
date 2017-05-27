#include "Gaussian.h"
#include "utils.h"
#include <queue>


CGaussian::CGaussian()
{
	m_vecMatrixEdits.push_back(IDC_GAUSS_EDIT_11);
	m_vecMatrixEdits.push_back(IDC_GAUSS_EDIT_12);
	m_vecMatrixEdits.push_back(IDC_GAUSS_EDIT_13);
	m_vecMatrixEdits.push_back(IDC_GAUSS_EDIT_14);
	m_vecMatrixEdits.push_back(IDC_GAUSS_EDIT_21);
	m_vecMatrixEdits.push_back(IDC_GAUSS_EDIT_22);
	m_vecMatrixEdits.push_back(IDC_GAUSS_EDIT_23);
	m_vecMatrixEdits.push_back(IDC_GAUSS_EDIT_24);
	m_vecMatrixEdits.push_back(IDC_GAUSS_EDIT_31);
	m_vecMatrixEdits.push_back(IDC_GAUSS_EDIT_32);
	m_vecMatrixEdits.push_back(IDC_GAUSS_EDIT_33);
	m_vecMatrixEdits.push_back(IDC_GAUSS_EDIT_34);
}


CGaussian::~CGaussian()
{
}

void CGaussian::GetMatrix(HWND _hDlg)
{
	m_vecfMatrix.push_back(ReadFromEditBox(_hDlg, IDC_GAUSS_EDIT_11));
	m_vecfMatrix.push_back(ReadFromEditBox(_hDlg, IDC_GAUSS_EDIT_12));
	m_vecfMatrix.push_back(ReadFromEditBox(_hDlg, IDC_GAUSS_EDIT_13));
	m_vecfMatrix.push_back(ReadFromEditBox(_hDlg, IDC_GAUSS_EDIT_14));
	m_vecfMatrix.push_back(ReadFromEditBox(_hDlg, IDC_GAUSS_EDIT_21));
	m_vecfMatrix.push_back(ReadFromEditBox(_hDlg, IDC_GAUSS_EDIT_22));
	m_vecfMatrix.push_back(ReadFromEditBox(_hDlg, IDC_GAUSS_EDIT_23));
	m_vecfMatrix.push_back(ReadFromEditBox(_hDlg, IDC_GAUSS_EDIT_24));
	m_vecfMatrix.push_back(ReadFromEditBox(_hDlg, IDC_GAUSS_EDIT_31));
	m_vecfMatrix.push_back(ReadFromEditBox(_hDlg, IDC_GAUSS_EDIT_32));
	m_vecfMatrix.push_back(ReadFromEditBox(_hDlg, IDC_GAUSS_EDIT_33));
	m_vecfMatrix.push_back(ReadFromEditBox(_hDlg, IDC_GAUSS_EDIT_34));

}

void CGaussian::MultiplyMatrix(HWND _hDlg)
{

	int iRow = ReadFromEditBox(_hDlg, IDC_EDIT_MULTX);
	if (iRow < 1 || iRow > 3)
	{
		return;
	}
	else
	{
		iRow -= 1;
	}

	for (int i = 0; i < 4; i++)
	{
		m_vecfMatrix.at(iRow*4 + i) *= ReadFromEditBox(_hDlg, IDC_EDIT_MULTY);
		WriteToEditBox(_hDlg, m_vecMatrixEdits.at(iRow*4 + i), m_vecfMatrix.at(iRow*4 + i));
	}


}

void CGaussian::MultiAdd(HWND _hDlg)
{
	int iRowX = ReadFromEditBox(_hDlg, IDC_EDIT20) - 1;
	int iRowY = ReadFromEditBox(_hDlg, IDC_EDIT22) - 1;
	int iScalar = ReadFromEditBox(_hDlg, IDC_EDIT19);

	if (iRowX < 0 || iRowX > 2 || iRowY < 0 || iRowY > 2)
	{
		MessageBoxA(_hDlg, "Invalid row input!", "Error", MB_OK);
		return;
	}
	else if (iScalar == 0)
	{
		MessageBoxA(_hDlg, "Invalid scalar input!", "Error", MB_OK);
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		m_vecfMatrix.at(iRowX * 4 + i) *= iScalar;
		m_vecfMatrix.at(iRowY * 4 + i) += m_vecfMatrix.at(iRowX * 4 + i);
		WriteToEditBox(_hDlg, m_vecMatrixEdits.at(iRowY * 4 + i), m_vecfMatrix.at(iRowY * 4 + i));
	}

}

void CGaussian::Swap(HWND _hDlg)
{
	int iRowX = ReadFromEditBox(_hDlg, IDC_EDIT16) - 1;
	int iRowY = ReadFromEditBox(_hDlg, IDC_EDIT17) - 1;

	if (iRowX < 0 || iRowX > 2 || iRowY < 0 || iRowY > 2)
	{
		MessageBoxA(_hDlg, "Invalid row input!", "Error", MB_OK);
		return;
	}

	std::queue<float> vecTemp;

	for (int i = 0; i < 4; i++)
	{
		vecTemp.push(m_vecfMatrix.at(iRowX * 4 + i)); 
		m_vecfMatrix.at(iRowX * 4 + i) = m_vecfMatrix.at(iRowY * 4 + i);
		m_vecfMatrix.at(iRowY * 4 + i) = vecTemp.front();
		vecTemp.pop();
		WriteToEditBox(_hDlg, m_vecMatrixEdits.at(iRowX * 4 + i), m_vecfMatrix.at(iRowX * 4 + i));
		WriteToEditBox(_hDlg, m_vecMatrixEdits.at(iRowY * 4 + i), m_vecfMatrix.at(iRowY* 4 + i));
	}
	
}
