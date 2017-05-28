#pragma once

#include <Windows.h>
#include <math.h>
#include "resource.h"

class CTransformation
{
public:
	~CTransformation();

	static CTransformation& GetInstance();

	//void SetResultantMat(HWND _hDlg);
	void ApplyScaling(HWND _hDlg);
	void ApplyTranslation(HWND _hDlg);
	void ApplyRotation(HWND _hDlg);
	void PrintIdentatyMatrix(HWND _hDlg);

private:

	CTransformation();
	CTransformation(const CTransformation& _kr);
	CTransformation& operator=(const CTransformation& _kr);

	void WriteToDialogBoxCMFormat(HWND _hDlg);
	void WriteToDialogBoxRMFormat(HWND _hDlg);
	void CreateIdentatyMatrix(float _rgMatrix[4][4]);
	void MultiplyMatrix(HWND _hDlg, float _rgInputMat[4][4]);
	void SetMatrix(float _rgMatrixA[4][4], float _rgMatrixB[4][4]);

	float m_rgfResultantMat[4][4];
	float m_rgfUserInputMat[4][4];
	float m_rgfTempMat[4][4];

protected:
	static CTransformation* s_pTransformation;
};

