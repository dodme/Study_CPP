#include <Windows.h>
#include "resource.h"

// 다이얼로그?
/// > 모달 다이얼 로그
//// 다른 윈도우 프로그램으로 전환이 불가능(ex 경고창)
/// > 모델리스 다이얼 로그
//// 다른 윈도우 프로그램으로 전환이 가능

// 다이얼 로그를 사용하기 위해서는
// 새로운 다이얼로그 프로시저가 필요하다.


HINSTANCE g_hInstance;

TCHAR str[256];
int x, y;

BOOL CALLBACK DlgProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPreInstance,
	LPSTR lpszCmdParam, int nCmdShow)
{
	g_hInstance = hInstance;

	HWND hWnd;
	MSG msg;
	WNDCLASS WndClass;

	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;

	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	WndClass.hInstance = hInstance;
	WndClass.lpfnWndProc = WndProc;
	WndClass.lpszClassName = TEXT("WndClass");
	WndClass.lpszMenuName = NULL;

	RegisterClass(&WndClass);

	hWnd = CreateWindow(WndClass.lpszClassName, TEXT("Today Code.. Very Very Long"),
		WS_OVERLAPPEDWINDOW | WS_VSCROLL,
		CW_USEDEFAULT, CW_USEDEFAULT, 800, 640,
		NULL, NULL, hInstance, NULL);

	ShowWindow(hWnd, nCmdShow);

	while (GetMessage(&msg, NULL, NULL, NULL))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (int)msg.wParam;

}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;

	switch (msg)
	{
	case WM_CREATE:
		x = 100;
		y = 100;
		lstrcpy(str, TEXT("Enter The String"));

		return 0;

	case WM_PAINT:
	{
		hdc = BeginPaint(hwnd, &ps);

		TextOut(hdc, x, y, str, lstrlen(str));

		EndPaint(hwnd, &ps);
		return 0;
	}

	case WM_LBUTTONDOWN:
		if (DialogBox(g_hInstance, MAKEINTRESOURCE(IDD_DIALOG1), hwnd, DlgProc) == IDOK)
		{
			InvalidateRect(hwnd, NULL, TRUE);
		}
		return 0;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hwnd, msg, wParam, lParam);
}

BOOL CALLBACK DlgProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_INITDIALOG: // 다이얼 로그가 생성될때 발생하는 메세지
		SetDlgItemText(hwnd, IDC_STR, str);
		SetDlgItemInt(hwnd, IDC_X, x, FALSE);
		SetDlgItemInt(hwnd, IDC_Y, y, FALSE);
		return FALSE;

	case WM_COMMAND:
	{
		switch (LOWORD(wParam))
		{
		case IDC_OK:
			GetDlgItemText(hwnd, IDC_STR, str, _countof(str));

			x = GetDlgItemInt(hwnd, IDC_X, NULL, FALSE);
			y = GetDlgItemInt(hwnd, IDC_Y, NULL, FALSE);

			EndDialog(hwnd, IDOK);
			break;

		case IDC_CANCEL:
			EndDialog(hwnd, IDCANCEL);
			break;
		}

		return FALSE;
	}

	case WM_CLOSE:
		EndDialog(hwnd, IDCANCEL);
		return FALSE;
	}


	return FALSE;
}