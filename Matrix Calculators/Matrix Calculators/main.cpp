//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2016 Media Design School
//
// File Name	: 
// Description	: 
// Author		: Your Name
// Mail			: your.name@mediadesign.school.nz
//


#define WIN32_LEAN_AND_MEAN

#include <windows.h>   // Include all the windows headers.
#include <windowsx.h>  // Include useful macros.

#include "utils.h"
#include "resource.h"

#include "Gaussian.h"
#include "Transformation.h"
#include "MatrixOperations.h"
#include "Slerp.h"
#include "Quaternion.h"

#define WINDOW_CLASS_NAME L"WINCLASS1"

HMENU g_hMenu;
HWND g_hDlgMatrix, g_hDlgTransformation, g_hDlgGaussian, g_hDlgQuaternion, g_hDlgSLERP;
HWND g_ComboBox;		 // Handle to the combo box.

void GameLoop()
{
	//One frame of game logic occurs here...
}

LRESULT CALLBACK WindowProc(HWND _hwnd,
	UINT _msg,
	WPARAM _wparam,
	LPARAM _lparam)
{
	// This is the main message handler of the system.
	PAINTSTRUCT ps; // Used in WM_PAINT.
	HDC hdc;        // Handle to a device context.
	
	// What is the message?
	switch (_msg)
	{
	case WM_CREATE:
	{
		// Do initialization stuff here.

		// Return Success.
		return (0);
	}
		break;

	case WM_PAINT:
	{
		// Simply validate the window.
		hdc = BeginPaint(_hwnd, &ps);

		// You would do all your painting here...

		EndPaint(_hwnd, &ps);

		// Return Success.
		return (0);
	}
		break;

	case WM_COMMAND:
	{
		switch (LOWORD(_wparam))
		{
		case ID_EXIT:
		{
			CTransformation::ResetInstance();
			CQuaternion::ResetInstance();
			PostQuitMessage(0);
			break;
		}
		case ID_CALCULATOR_MATRIX:
		{
			ShowWindow(g_hDlgMatrix, SW_SHOWNORMAL);
			break;
		}
		case ID_CALCULATOR_TRANSFORMATION:
		{
			ShowWindow(g_hDlgTransformation, SW_SHOWNORMAL);
			break;

		}
			//open the matrix dialog
		case ID_CALCULATOR_GAUSSIAN:
		{
			ShowWindow(g_hDlgGaussian, SW_SHOWNORMAL);
			break;
		}
			//open the gaussian dialog
		case ID_CALCULATOR_QUATERNION:
		{
			ShowWindow(g_hDlgQuaternion, SW_SHOWNORMAL);
			break;
		}
			//open the quaternion dialog
		case ID_CALCULATOR_SLERP:
		{
			ShowWindow(g_hDlgSLERP, SW_SHOWNORMAL);
			break;
		}
		default:
			break;
		}
		return(0);
	}
		break;

	case WM_DESTROY:
	{
		CTransformation::ResetInstance();
		CQuaternion::ResetInstance();
		// Kill the application, this sends a WM_QUIT message.
		PostQuitMessage(0);

		// Return success.
		return (0);
	}
		break;

	default:break;
	} // End switch.

	// Process any messages that we did not take care of...

	return (DefWindowProc(_hwnd, _msg, _wparam, _lparam));
}

BOOL CALLBACK MatrixDlgProc(HWND _hwnd,
	UINT _msg,
	WPARAM _wparam,
	LPARAM _lparam)
{
	CMatrixOperations s_Matrix;

	switch (_msg)
	{
	case WM_COMMAND:
	{
		switch (LOWORD(_wparam))
		{
		case IDOK4:
		{
			s_Matrix.GetMatrixA(g_hDlgMatrix);
			s_Matrix.Identity(true);
			s_Matrix.WriteMatrix(g_hDlgMatrix);
			break;
		}
		case IDOK8:
		{
			s_Matrix.GetMatrixB(g_hDlgMatrix);
			s_Matrix.Identity(false);
			s_Matrix.WriteMatrix(g_hDlgMatrix);
			break;
		}
		case IDC_SWAP:
		{
			s_Matrix.GetMatrixA(g_hDlgMatrix);
			s_Matrix.GetMatrixB(g_hDlgMatrix);
			s_Matrix.Swap(g_hDlgMatrix);
			s_Matrix.WriteMatrix(g_hDlgMatrix);
			break;
		}
		case IDOK9:
		{
			s_Matrix.GetMatrixA(g_hDlgMatrix);
			s_Matrix.Transpose(true);
			s_Matrix.WriteMatrix(g_hDlgMatrix);
			break;
		}
		case IDOK11:
		{
			s_Matrix.GetMatrixB(g_hDlgMatrix);
			s_Matrix.Transpose(false);
			s_Matrix.WriteMatrix(g_hDlgMatrix);
			break;
		}
		case IDOK6:
		{
			s_Matrix.GetMatrixA(g_hDlgMatrix);
			s_Matrix.ScalarMultiply(true, g_hDlgMatrix);
			s_Matrix.WriteMatrix(g_hDlgMatrix);
			break;
		}
		case IDOK10:
		{
			s_Matrix.GetMatrixB(g_hDlgMatrix);
			s_Matrix.ScalarMultiply(false, g_hDlgMatrix);
			s_Matrix.WriteMatrix(g_hDlgMatrix);
			break;
		}
		case IDOK2:
		{
			s_Matrix.GetMatrixA(g_hDlgMatrix);
			s_Matrix.GetMatrixB(g_hDlgMatrix);
			s_Matrix.Multiply(true);
			s_Matrix.WriteMatrix(g_hDlgMatrix);
			break;
		}
		case IDOK5:
		{
			s_Matrix.GetMatrixA(g_hDlgMatrix);
			s_Matrix.GetMatrixB(g_hDlgMatrix);
			s_Matrix.Multiply(false);
			s_Matrix.WriteMatrix(g_hDlgMatrix);
			break;
		}
		case IDOK:
		{
			s_Matrix.GetMatrixA(g_hDlgMatrix);
			s_Matrix.GetMatrixB(g_hDlgMatrix);
			s_Matrix.Addition();
			s_Matrix.WriteMatrix(g_hDlgMatrix);
			break;
		}
		case IDC_A_MINUS_B:
		{
			s_Matrix.GetMatrixA(g_hDlgMatrix);
			s_Matrix.GetMatrixB(g_hDlgMatrix);
			s_Matrix.Subtraction(true);
			s_Matrix.WriteMatrix(g_hDlgMatrix);
			break;
		}
		case IDC_B_MINUS_A:
		{
			s_Matrix.GetMatrixA(g_hDlgMatrix);
			s_Matrix.GetMatrixB(g_hDlgMatrix);
			s_Matrix.Subtraction(false);
			s_Matrix.WriteMatrix(g_hDlgMatrix);
			break;
		}
		case IDC_DETA:
		{
			s_Matrix.GetMatrixA(g_hDlgMatrix);
			s_Matrix.Determinant(g_hDlgMatrix,true);
			break;
		}
		case IDC_DETB:
		{
			s_Matrix.GetMatrixB(g_hDlgMatrix);
			s_Matrix.Determinant(g_hDlgMatrix, false);
			break;
		}
		case IDCANCEL2:
		{
			s_Matrix.GetMatrixA(g_hDlgMatrix);
			s_Matrix.Inverse(g_hDlgMatrix, true);
			break;
		}
		case IDCANCEL3:
		{
			s_Matrix.GetMatrixB(g_hDlgMatrix);
			s_Matrix.Inverse(g_hDlgMatrix, false);
			break;
		}
		case IDC_APOW:
		{
			s_Matrix.GetMatrixA(g_hDlgMatrix);
			s_Matrix.Pow(true);
			s_Matrix.WriteMatrix(g_hDlgMatrix);
			break;
		}
		case IDC_BPOW:
		{
			s_Matrix.GetMatrixB(g_hDlgMatrix);
			s_Matrix.Pow(false);
			s_Matrix.WriteMatrix(g_hDlgMatrix);
			break;
		}
		default:
			break;
		}
		return TRUE;
		break;
	}
	case WM_CLOSE:
	{
		ShowWindow(_hwnd, SW_HIDE);
		return TRUE;
		break;
	}
	default:
		break;
	}
	return FALSE;
}

BOOL CALLBACK TransformationDlgProc(HWND _hwnd,
	UINT _msg,
	WPARAM _wparam,
	LPARAM _lparam)
{
	static CTransformation& traTransform = CTransformation::GetInstance();
	

	switch (_msg)
	{
	case WM_CLOSE:
	{
		ShowWindow(_hwnd, SW_HIDE);
		return TRUE;
		break;
	}
	case WM_COMMAND:
	{
		switch (LOWORD(_wparam))
		{
		case (IDC_BUTTON4):
		{
			switch (ComboBox_GetCurSel(g_ComboBox))		// Switch based on what compute mode is selected
			{
			case(0):
			{
				traTransform.PrintIdentityMatrix(g_hDlgTransformation);
				break;
			}
			case(1):
			{
				traTransform.ApplyProjection(g_hDlgTransformation);
				break;
			}
			case(2):
			{
				traTransform.ApplyRotation(g_hDlgTransformation);
				break;
			}
			case(3):
			{
				traTransform.ApplyScaling(g_hDlgTransformation);
				break;
			}
			case(4):
			{
				traTransform.ApplyTranslation(g_hDlgTransformation);
				break;
			}
			default:
				break;
			}
			break;
		}
		default:
			break;
		}
	}
	default:
		break;
	}
	return FALSE;
	
}


BOOL CALLBACK GaussianDlgProc(HWND _hwnd,
	UINT _msg,
	WPARAM _wparam,
	LPARAM _lparam)
{

	CGaussian s_Gaussian;

	switch (_msg)
	{
	case WM_CLOSE:
	{
		ShowWindow(_hwnd, SW_HIDE);
		return TRUE;
		break;
	}
	case WM_COMMAND:
	{
		switch (LOWORD(_wparam))
		{
			case IDC_BUTTON1:
			{
				s_Gaussian.GetMatrix(g_hDlgGaussian);
				s_Gaussian.MultiplyMatrix(g_hDlgGaussian);
				break;
			}
			case IDC_BUTTON2:
			{
				s_Gaussian.GetMatrix(g_hDlgGaussian);
				s_Gaussian.Swap(g_hDlgGaussian);
				break;
			}
			case IDC_BUTTON3:
			{
				s_Gaussian.GetMatrix(g_hDlgGaussian);
				s_Gaussian.MultiAdd(g_hDlgGaussian);
				break;
			}
			case IDC_BUTTON4:
			{
				s_Gaussian.GetMatrix(g_hDlgGaussian);
				//s_Gaussian.Automate(g_hDlgGaussian);
				break;
			}
			default:
			{
				break;
			}
		}
		break;
	}
	default:
		break;
	}
	return FALSE;
}


BOOL CALLBACK QuaternionDlgProc(HWND _hwnd,
	UINT _msg,
	WPARAM _wparam,
	LPARAM _lparam)
{
	static CQuaternion& quaQuaternion = CQuaternion::GetInstance();

	switch (_msg)
	{
	case WM_CLOSE:
	{
		ShowWindow(_hwnd, SW_HIDE);
		return TRUE;
		break;
	}
	case WM_COMMAND:
	{
		switch (LOWORD(_wparam))
		{
		case IDC_BUTTON1:
		{
			quaQuaternion.ApplyAddition(g_hDlgQuaternion);
			break;
		}
		case IDC_BUTTON2:
		{
			quaQuaternion.ApplyMultiplication(g_hDlgQuaternion, true);
			break;
		}
		case IDC_BUTTON3:
		{
			quaQuaternion.ApplyConjugate(g_hDlgQuaternion, true);
			break;
		}
		case IDC_BUTTON5:
		{
			quaQuaternion.ApplySubtraction(g_hDlgQuaternion, true);
			break;
		}
		case IDC_BUTTON6:
		{
			quaQuaternion.ApplySubtraction(g_hDlgQuaternion, false);
			break;
		}
		case IDC_BUTTON7:
		{
			quaQuaternion.ApplyMultiplication(g_hDlgQuaternion, false);
			break;
		}
		case IDC_BUTTON8:
		{
			quaQuaternion.ApplyDotProduct(g_hDlgQuaternion);
			break;
		}
		case IDC_BUTTON9:
		{
			quaQuaternion.ApplyConjugate(g_hDlgQuaternion, false);
			break;
		}
		case IDC_BUTTON10:
		{
			quaQuaternion.ApplyMagnitude(g_hDlgQuaternion, true);
			break;
		}
		case IDC_BUTTON11:
		{
			quaQuaternion.ApplyMagnitude(g_hDlgQuaternion, false);
			break;
		}
		case IDC_BUTTON12:
		{
			quaQuaternion.ApplyInverse(g_hDlgQuaternion, true);
			break;
		}
		case IDC_BUTTON13:
		{
			quaQuaternion.ApplyInverse(g_hDlgQuaternion, false);
			break;
		}
		case IDC_BUTTON14:
		{
			quaQuaternion.ApplyScalar(g_hDlgQuaternion, true);
			break;
		}
		case IDC_BUTTON15:
		{
			quaQuaternion.ApplyScalar(g_hDlgQuaternion, false);
			break;
		}
		default:
			break;
		}
		break;
	}
	default:
		break;
	}
	return FALSE;
}

BOOL CALLBACK SLERPDlgProc(HWND _hwnd,
	UINT _msg,
	WPARAM _wparam,
	LPARAM _lparam)
{
	CSlerp SlerpCalc(g_hDlgSLERP);

	switch (_msg)
	{
	case WM_CLOSE:
	{
		ShowWindow(_hwnd, SW_HIDE);
		return TRUE;
		break;
	}
	case WM_COMMAND:
	{
		switch (LOWORD(_wparam))
		{
		case IDC_BUTTON2:
		{
			SlerpCalc.GetQuarternions();
			SlerpCalc.ConvertToMatrix(1);
			//ShowWindow(_hwnd, SW_HIDE);
			break;
		}
		case IDC_BUTTON3:
		{
			SlerpCalc.GetQuarternions();
			SlerpCalc.ConvertToMatrix(2);
			//ShowWindow(_hwnd, SW_HIDE);
			break;
		}
		case IDC_BUTTON5:
		{
			SlerpCalc.GetQuarternions();
			SlerpCalc.SlerpABT();
			SlerpCalc.ConvertToMatrix(3);
			//ShowWindow(_hwnd, SW_HIDE);
			break;
		}
		case IDC_BUTTON1:
		{
			SlerpCalc.GetQuarternions();
			SlerpCalc.SlerpABT();
			break;
		}
		default:break;

		}
	}
	default:
		break;
	}
	return FALSE;
}

int WINAPI WinMain(HINSTANCE _hInstance,
	HINSTANCE _hPrevInstance,
	LPSTR _lpCmdLine,
	int _nCmdShow)
{
	WNDCLASSEX winclass; // This will hold the class we create.
	HWND hwnd;           // Generic window handle.
	MSG msg;             // Generic message.

	// First fill in the window class structure.
	winclass.cbSize = sizeof(WNDCLASSEX);
	winclass.style = CS_DBLCLKS | CS_OWNDC | CS_HREDRAW | CS_VREDRAW;
	winclass.lpfnWndProc = WindowProc;
	winclass.cbClsExtra = 0;
	winclass.cbWndExtra = 0;
	winclass.hInstance = _hInstance;
	winclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	winclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	winclass.hbrBackground =
		static_cast<HBRUSH>(GetStockObject(BLACK_BRUSH));
	winclass.lpszMenuName = NULL;
	winclass.lpszClassName = WINDOW_CLASS_NAME;
	winclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	// register the window class
	if (!RegisterClassEx(&winclass))
	{
		return (0);
	}

	//Laod the Menu
	g_hMenu = LoadMenu(_hInstance, MAKEINTRESOURCE(IDR_MENU1));

	// create the window
	hwnd = CreateWindowEx(NULL, // Extended style.
		WINDOW_CLASS_NAME,      // Class.
		L"Your Basic Window",   // Title.
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,
		0, 0,                    // Initial x,y.
		400, 100,                // Initial width, height.
		NULL,                   // Handle to parent.
		g_hMenu,                   // Handle to menu.
		_hInstance,             // Instance of this application.
		NULL);                  // Extra creation parameters.

	if (!(hwnd))
	{
		return (0);
	}

	//Create the modeless dialog boxes for the calculators
	//Matrix Calculator
	g_hDlgMatrix = CreateDialog(_hInstance, MAKEINTRESOURCE(IDD_DialogMatrix), hwnd, MatrixDlgProc);
	g_hDlgTransformation = CreateDialog(_hInstance, MAKEINTRESOURCE(IDD_DialogTransformations), hwnd, TransformationDlgProc);
	g_hDlgGaussian = CreateDialog(_hInstance, MAKEINTRESOURCE(IDD_DialogGaussian), hwnd, GaussianDlgProc);
	g_hDlgQuaternion = CreateDialog(_hInstance, MAKEINTRESOURCE(IDD_DialogQuaternion), hwnd, QuaternionDlgProc);
	g_hDlgSLERP = CreateDialog(_hInstance, MAKEINTRESOURCE(IDD_DialogSLERP), hwnd, SLERPDlgProc);

	g_ComboBox = GetDlgItem(g_hDlgTransformation, IDC_COMBO1);

	SendMessage(g_ComboBox, CB_ADDSTRING, 0, reinterpret_cast<LPARAM>(L"Identity"));
	SendMessage(g_ComboBox, CB_ADDSTRING, 0, reinterpret_cast<LPARAM>(L"Translate"));
	SendMessage(g_ComboBox, CB_ADDSTRING, 0, reinterpret_cast<LPARAM>(L"Scale/Skew"));
	SendMessage(g_ComboBox, CB_ADDSTRING, 0, reinterpret_cast<LPARAM>(L"Project"));
	SendMessage(g_ComboBox, CB_ADDSTRING, 0, reinterpret_cast<LPARAM>(L"Rotate"));
	ComboBox_SetCurSel(g_ComboBox, 0);

	// Enter main event loop
	while (true)
	{
		// Test if there is a message in queue, if so get it.
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			// Test if this is a quit.
			if (msg.message == WM_QUIT)
			{
				break;
			}

			if ((g_hDlgMatrix == 0 && g_hDlgTransformation == 0 && g_hDlgGaussian == 0 && g_hDlgQuaternion == 0 && g_hDlgSLERP == 0) ||
				(!IsDialogMessage(g_hDlgMatrix, &msg) && !IsDialogMessage(g_hDlgTransformation, &msg) && !IsDialogMessage(g_hDlgGaussian, &msg) && !IsDialogMessage(g_hDlgQuaternion, &msg) && !IsDialogMessage(g_hDlgSLERP, &msg)))
			{
				// Translate any accelerator keys.
				TranslateMessage(&msg);
				// Send the message to the window proc.
				DispatchMessage(&msg);
			}
		}

		// Main game processing goes here.
		GameLoop(); //One frame of game logic occurs here...
	}


	// Return to Windows like this...
	return (static_cast<int>(msg.wParam));
}


