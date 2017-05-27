#include "Gaussian.h"
#include "utils.h"


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

	if (iRow == 2)
	{
		iRow += 3;
	}
	else if (iRow == 3)
	{
		iRow += 6;
	}

	for (int i = 0; i < 4; i++)
	{
		m_vecfMatrix.at(iRow -1 + i) *= ReadFromEditBox(_hDlg, IDC_EDIT_MULTY);
		WriteToEditBox(_hDlg, m_vecMatrixEdits.at(iRow - 1 + i), m_vecfMatrix.at(iRow - 1 + i));
	}


}
