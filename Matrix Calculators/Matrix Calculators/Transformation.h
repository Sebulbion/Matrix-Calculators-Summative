#pragma once

#include <Windows.h>
#include "resource.h"

class CTransformation
{
public:
	~CTransformation();

	static CTransformation& GetInstance();

	//void SetResultantMat(HWND _hDlg);
	void ApplyScaling(HWND _hDlg);
	void CreateIdentatyMatrix(float _rgMatrix[4][4]);

private:

	CTransformation();
	CTransformation(const CTransformation& _kr);
	CTransformation& operator=(const CTransformation& _kr);
	void WriteToDialogBoxCMFormat(HWND _hDlg);

	void MultiplyMatrix(HWND _hDlg, float _rgInputMat[4][4]);
	float m_rgfResultantMat[4][4] = {
		{ 1,0,0,0 },
		{ 0,1,0,0 },
		{ 0,0,1,0 },
		{ 0,0,0,1 } };

	float m_rgfTempMat[4][4] = {
		{ 1,0,0,0 },
		{ 0,1,0,0 },
		{ 0,0,1,0 },
		{ 0,0,0,1 } };

protected:
	static CTransformation* s_pTransformation;
};

