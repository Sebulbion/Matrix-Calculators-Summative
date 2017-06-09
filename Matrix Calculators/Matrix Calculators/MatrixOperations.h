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
	int Determinant(HWND _hDlg,bool _bIsA);
	void Transpose(bool _bIsA);
	void Inverse(HWND _hDlg, bool _bIsA);
	void ScalarMultiply(bool _bIsA, HWND _hDlg);

	void Addition();
	void Subtraction(bool _bIsA);
	void Multiply(bool _bIsA); // _bIsA true = A*B

private:

	float Det3D(float _rgfMatrix[3][3]);

	std::vector<float> m_vecfMatrixA;
	std::vector<float> m_vecfMatrixB;
	std::vector<float> m_vecfMatrixR;
	std::vector<size_t> m_vecMatrixEditsA;
	std::vector<size_t> m_vecMatrixEditsB;
	std::vector<size_t> m_vecMatrixEditsR;


	//HWND m_hDlg;
};