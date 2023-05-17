#include <Windows.h>
#include "Header.h"

HINSTANCE g_hInstance;

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

	hWnd = CreateWindow(WndClass.lpszClassName, TEXT("Shape Color"),
		WS_OVERLAPPEDWINDOW | WS_VSCROLL,
		CW_USEDEFAULT, CW_USEDEFAULT, 360, 370,
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
	static BOOL isEllipse = FALSE;

	static HWND hsRed, hsGreen, hsBlue;
	static int colorRed, colorGreen, colorBlue;

	static HWND hrb1;
	static HWND hrb2;

	HDC hdc;
	PAINTSTRUCT ps;
	TCHAR str[256];
	static HBRUSH brush, oldBrush;

	switch (msg)
	{
	case WM_CREATE:
	{
		{
			hrb1 = CreateWindow(TEXT("button"), TEXT("RECT"),
				WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,
				30, 160, 100, 20, hwnd, (HMENU)IDC_RADIO_BUTTON_1, g_hInstance, NULL);

			hrb2 = CreateWindow(TEXT("button"), TEXT("ELLIPSE"),
				WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,
				210, 160, 100, 20, hwnd, (HMENU)IDC_RADIO_BUTTON_2, g_hInstance, NULL);

			CheckRadioButton(hwnd, IDC_RADIO_BUTTON_1, IDC_RADIO_BUTTON_2, IDC_RADIO_BUTTON_1);
		}

		{
			hsRed = CreateWindow(TEXT("scrollbar"), NULL,
				WS_CHILD | WS_VISIBLE | SBS_HORZ,
				60, 225, 250, 20, hwnd, (HMENU)IDC_SCRRED, g_hInstance, NULL);

			hsGreen = CreateWindow(TEXT("scrollbar"), NULL,
				WS_CHILD | WS_VISIBLE | SBS_HORZ,
				60, 250, 250, 20, hwnd, (HMENU)IDC_SCRGREEN, g_hInstance, NULL);

			hsBlue = CreateWindow(TEXT("scrollbar"), NULL,
				WS_CHILD | WS_VISIBLE | SBS_HORZ,
				60, 275, 250, 20, hwnd, (HMENU)IDC_SCRBLUE, g_hInstance, NULL);

			SetScrollRange(hsRed, SB_CTL, 0, 255, FALSE);
			SetScrollRange(hsGreen, SB_CTL, 0, 255, FALSE);
			SetScrollRange(hsBlue, SB_CTL, 0, 255, FALSE);

			SetScrollPos(hsRed, SB_CTL, 0, FALSE);
			SetScrollPos(hsGreen, SB_CTL, 0, FALSE);
			SetScrollPos(hsBlue, SB_CTL, 0, FALSE);
		}

		return 0;
	}

	case WM_COMMAND:
	{
		switch (LOWORD(wParam))
		{
		case IDC_RADIO_BUTTON_1:
			isEllipse = FALSE;
			break;

		case IDC_RADIO_BUTTON_2:
			isEllipse = TRUE;
			break;
		}

		return 0;
	}

	case WM_HSCROLL:
	{
		int currentScrollPosition = GetScrollPos((HWND)lParam, SB_CTL);

		switch (LOWORD(wParam))
		{
		case SB_LINELEFT:
			currentScrollPosition = max(0, currentScrollPosition - 1);
			break;

		case SB_LINERIGHT:
			currentScrollPosition = min(255, currentScrollPosition + 1);
			break;

		case SB_PAGELEFT:
			currentScrollPosition = max(0, currentScrollPosition - 10);
			break;

		case SB_PAGERIGHT:
			currentScrollPosition = min(255, currentScrollPosition + 10);
			break;

		case SB_THUMBTRACK:
			currentScrollPosition = HIWORD(wParam);
			break;
		}

		if ((HWND)lParam == hsRed) colorRed = currentScrollPosition;
		else if ((HWND)lParam == hsGreen) colorGreen = currentScrollPosition;
		else if ((HWND)lParam == hsBlue) colorBlue = currentScrollPosition;

		SetScrollPos((HWND)lParam, SB_CTL, currentScrollPosition, TRUE);

		if (isEllipse)
		{
			RECT reDrawArea = { 200, 30, 300, 130 };
			InvalidateRect(hwnd, &reDrawArea, FALSE);
		}
		else
		{
			RECT reDrawArea = { 20, 30, 120, 130 };
			InvalidateRect(hwnd, &reDrawArea, FALSE);
		}


		return 0;
	}

	case WM_PAINT:
	{
		hdc = BeginPaint(hwnd, &ps);
		brush = CreateSolidBrush(RGB(colorRed, colorGreen, colorBlue));
		oldBrush = (HBRUSH)SelectObject(hdc, brush);

		TextOut(hdc, 45, 10, "사각형", strlen("사각형"));
		TextOut(hdc, 240, 10, "원", strlen("원"));
		TextOut(hdc, 15, 140, "색상을 설정할 도형을 선택하세요.", strlen("색상을 설정할 도형을 선택하세요."));

		// private void Update 마렵다...
		wsprintf(str, TEXT("[%d] [%d] [%d]"), colorRed, colorGreen, colorBlue);
		TextOut(hdc, 20, 190, str, strlen(str));

		Rectangle(hdc, 20, 30, 120, 130);
		Ellipse(hdc, 200, 30, 300, 130);

		DeleteObject(SelectObject(hdc, oldBrush));
		EndPaint(hwnd, &ps);

		return 0;
	}

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hwnd, msg, wParam, lParam);
}
