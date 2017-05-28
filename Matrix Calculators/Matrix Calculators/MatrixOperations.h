#pragma once

#include <vector>
#include <Windows.h>
#include "resource.h"



class CMatrixOperations
{
public:
	CMatrixOperations();
	~CMatrixOperations();
	void GetMatrixA(HWND _hDlg);
	void GetMatrixB(HWND _hDlg);
	void WriteMatrix(HWND _hDlg);
	void Identity(bool _bIsA);
	void Determinant(bool _bIsA);
	void Transpose(bool _bIsA);
	void Inverse(bool _bIsA);
	void ScalarMultiply(bool _bIsA, HWND _hDlg);
	
	void Addition();
	void Subtraction();
	void Multiply(bool _bIsA); // _bIsA true = A*B

private:

	std::vector<float> m_vecfMatrixA;
	std::vector<float> m_vecfMatrixB;
	std::vector<float> m_vecfMatrixR;
	std::vector<size_t> m_vecMatrixEditsA;
	std::vector<size_t> m_vecMatrixEditsB;
	std::vector<size_t> m_vecMatrixEditsR;


	//HWND m_hDlg;
};