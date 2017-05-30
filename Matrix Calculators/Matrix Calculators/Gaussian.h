
#pragma once

#include <vector>
#include <Windows.h>
#include "resource.h"

 

class CGaussian
{																
public:															
	CGaussian();
	~CGaussian();												
	void GetMatrix(HWND _hDlg);
	void MultiplyMatrix(HWND _hDlg);
	void MultiAdd(HWND _hDlg);
	void Swap(HWND _hDlg);


private:	

	std::vector<float> m_vecfMatrix;
	std::vector<size_t> m_vecMatrixEdits;

	//HWND m_hDlg;
};					  
					  