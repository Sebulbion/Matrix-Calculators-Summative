#pragma once

#include <Windows.h>
#include <math.h>
#include "resource.h"

class CQuaternion
{
public:
	~CQuaternion();
	static CQuaternion& GetInstance();

	void ApplyAddition(HWND _hDlg);
	void ApplySubtraction(HWND _hDlg, bool _fAMinusB);
	void ApplyMultiplication(HWND _hDlg, bool _fATimesB);
	void ApplyDotProduct(HWND _hDlg);
	void ApplyConjugate(HWND _hDlg, bool _fIsA);
	void ApplyMagnitude(HWND _hDlg, bool _fIsA);

private:
	CQuaternion();
	CQuaternion(const CQuaternion& _kr);
	CQuaternion& operator=(const CQuaternion& _kr);

	void ReadInput(HWND _hDlg);

	float m_rgfQuaternionOne[4];
	float m_rgfQuaternionTwo[4];

protected:
	static CQuaternion* s_pQuaternion;
};

