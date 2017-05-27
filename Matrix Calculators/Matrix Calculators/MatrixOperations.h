#pragma once

#include <vector>
#include <Windows.h>
#include "resource.h"



class CMatrixOperations
{
public:
	CMatrixOperations();
	~CMatrixOperations();
	void GetMatrix(HWND _hDlg);
	void Identity(bool _bIsA);
	void Determinant(bool _bIsA);
	void Transpose(bool _bIsA);
	void Inverse(bool _bIsA);
	void ScalarMultiply(bool _bIsA);
	
	void Addition();
	void Subtraction();
	void Multiply(bool _bIsA); // _bIsA true = A*B

private:

	std::vector<float> m_vecfMatrix;
	std::vector<size_t> m_vecMatrixEdits;

	//HWND m_hDlg;
};