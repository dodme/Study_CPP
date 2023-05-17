#include <Windows.h>
#include "resource.h"

enum Gender { MAN, WOMAN };
Gender characterGender;

enum Job
{
	WARRIOR,
	MAGE,
	ARCHER,
	THIEF,
};

Job characterJob;

const TCHAR* jobName[] = { TEXT("전사"),TEXT("마법사"), TEXT("궁수"), TEXT("도적") };

HBITMAP manBitmap, womanBitmap, oldBitmap;
BITMAP manBitmapInfo, womanBitmapInfo;

HINSTANCE g_hInstance;

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
	TCHAR str[256];

	switch (msg)
	{
	case WM_CREATE:
		characterGender = Gender::WOMAN;
		characterJob = Job::WARRIOR;

		manBitmap = LoadBitmap(g_hInstance, MAKEINTRESOURCE(IDB_BITMAP1));
		womanBitmap = LoadBitmap(g_hInstance, MAKEINTRESOURCE(IDB_BITMAP2));

		GetObject(manBitmap, sizeof(BITMAP), &manBitmapInfo);
		GetObject(womanBitmap, sizeof(BITMAP), &womanBitmapInfo);

		return 0;

	case WM_KEYDOWN:
		if (GetAsyncKeyState(VK_SPACE))
		{
			if (DialogBox(g_hInstance, MAKEINTRESOURCE(IDD_DIALOG1), hwnd, (DLGPROC)DlgProc) == IDC_)
			{
				InvalidateRect(hwnd, NULL, FALSE);
			}
		}
		return 0;

	case WM_PAINT:
	{
		hdc = BeginPaint(hwnd, &ps);

		// wsprintf() : 2개의 문자열을 합성합니다.
		wsprintf(str, TEXT("캐릭터 성별 = %s"), (characterGender == Gender::MAN) ? TEXT("남자") : TEXT("여자"));
		TextOut(hdc, 10, 200, str, strlen(str));

		wsprintf(str, TEXT("캐릭터 직업 = %s"), jobName[characterJob]);
		TextOut(hdc, 10, 220, str, strlen(str));

		HDC memDC = CreateCompatibleDC(hdc);

		BITMAP bitmapInfo = (characterGender == Gender::MAN) ? manBitmapInfo : womanBitmapInfo;

		switch (characterGender)
		{
		case Gender::MAN:
			oldBitmap = (HBITMAP)SelectObject(memDC, manBitmap);
			break;

		case Gender::WOMAN:
			oldBitmap = (HBITMAP)SelectObject(memDC, womanBitmap);
			break;
		}

		BitBlt(hdc, 10, 10, bitmapInfo.bmWidth, bitmapInfo.bmHeight, memDC, 0, 0, SRCCOPY);

		SelectObject(memDC, oldBitmap);
		DeleteDC(memDC);

		EndPaint(hwnd, &ps);
		return 0;
	}

	case WM_DESTROY:
		DeleteObject(manBitmap);
		DeleteObject(womanBitmap);

		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hwnd, msg, wParam, lParam);
}

BOOL CALLBACK DlgProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_INITDIALOG:
		CheckDlgButton(hwnd, IDC_MALE, (characterGender == Gender::MAN) ? BST_CHECKED : BST_UNCHECKED);
		CheckRadioButton(hwnd, IDC_RADIO1, IDC_RADIO4, IDC_RADIO1 + characterJob);
		return FALSE;

	case WM_COMMAND:
	{
		switch (LOWORD(wParam))
		{
		case ID_OK:
		{
			HWND genderCheckBox = GetDlgItem(hwnd, IDC_MALE);

			characterGender =
				(SendMessage(genderCheckBox, BM_GETCHECK, 0, 0) == BST_CHECKED) ?
				characterGender = Gender::MAN : characterGender = Gender::WOMAN;

			if (IsDlgButtonChecked(hwnd, IDC_RADIO1) == BST_CHECKED) characterJob = Job::WARRIOR);
			if (IsDlgButtonChecked(hwnd, IDC_RADIO2) == BST_CHECKED) characterJob = Job::MAGE);
			if (IsDlgButtonChecked(hwnd, IDC_RADIO3) == BST_CHECKED) characterJob = Job::ARCHER);
			if (IsDlgButtonChecked(hwnd, IDC_RADIO4) == BST_CHECKED) characterJob = Job::THIEF);

			EndDialog(hwnd, IDOK);
			break;
		}

		case ID_CANCEL:
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