#pragma once

#include <Windows.h>
#include <math.h>
#include "resource.h"

class CQuaternion
{
public:
	~CQuaternion();
	static CQuaternion& GetInstance();
	static void ResetInstance();

	void ApplyAddition(HWND _hDlg);
	void ApplySubtraction(HWND _hDlg, bool _bAMinusB);
	void ApplyMultiplication(HWND _hDlg, bool _bATimesB);
	void ApplyDotProduct(HWND _hDlg);
	void ApplyConjugate(HWND _hDlg, bool _bIsA);
	void ApplyMagnitude(HWND _hDlg, bool _bIsA);
	void ApplyInverse(HWND _hDlg, bool _bIsA);
	void ApplyScalar(HWND _hDlg, bool _bIsA);

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

