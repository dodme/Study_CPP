#include <Windows.h>
#include "Define.h"

HINSTANCE g_hInstance;

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE prehInstance, LPSTR lpszCmdParam, int nCmdShow)
{
	g_hInstance = hInstance;

	HWND hWnd;
	MSG msg;
	WNDCLASS WndClass;

	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	WndClass.hInstance = hInstance;
	WndClass.lpfnWndProc = WndProc;
	WndClass.lpszClassName = TEXT("WndClass");
	WndClass.lpszMenuName = NULL;
	WndClass.style = CS_HREDRAW | CS_VREDRAW;

	RegisterClass(&WndClass);

	hWnd = CreateWindow(WndClass.lpszClassName, TEXT("Shape Color"),
		WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 360, 370, NULL, NULL, hInstance, NULL);

	ShowWindow(hWnd, nCmdShow);

	while (GetMessage(&msg, NULL, NULL, NULL))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (int)msg.wParam;
}

void SetColorEdit(HWND edit, int r, int g, int b)
{
	TCHAR color[256];
	wsprintf(color, TEXT("[%d] [%d] [%d]"), r, g, b);
	SetWindowText(edit, color);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;

	static HWND hRadioShapeRectangle, hRadioShapeEllipse;
	static HWND hEditRectangleRGB, hEditEllipseRGB;
	static int rectR = 0, rectG = 0, rectB = 0;
	static int ellR = 0, ellG = 0, ellB = 0;
	static int* controllR, * controllG, * controllB;

	static HWND hsR, hsG, hsB;

	switch (msg)
	{
	case WM_CREATE:
	{
		{
			// static Text
			CreateWindow(TEXT("static"), TEXT("색상을 설정할 도형을 선택하세요."),
				WS_CHILD | WS_VISIBLE, 15, 140, 250, 30, hWnd, NULL, g_hInstance, NULL);
		}

		{
			// Radio
			hRadioShapeRectangle = CreateWindow(TEXT("button"), TEXT("RECT"),
				WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON | WS_GROUP, 30, 160, 60, 25, hWnd,
				(HMENU)IDC_RADIO_SHAPE_RECTANGLE, g_hInstance, NULL);


			hRadioShapeEllipse = CreateWindow(TEXT("button"), TEXT("RECT"),
				WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON, 210, 160, 60, 25, hWnd,
				(HMENU)IDC_RADIO_SHAPE_ELLIPSE, g_hInstance, NULL);

			CheckRadioButton(hWnd, IDC_RADIO_SHAPE_RECTANGLE, IDC_RADIO_SHAPE_ELLIPSE, IDC_RADIO_SHAPE_RECTANGLE);
		}

		{
			// Edit
			hEditRectangleRGB = CreateWindow(TEXT("edit"), NULL,
				WS_CHILD | WS_VISIBLE | ES_READONLY | ES_CENTER | WS_BORDER,
				20, 190, 110, 25, hWnd, (HMENU)IDC_RECTANGLE_EDIT_RGB, g_hInstance, NULL);

			hEditEllipseRGB = CreateWindow(TEXT("edit"), NULL,
				WS_CHILD | WS_VISIBLE | ES_READONLY | ES_CENTER | WS_BORDER,
				200, 190, 110, 25, hWnd, (HMENU)IDC_ELLIPSE_EDIT_RGB, g_hInstance, NULL);

			SetColorEdit(hEditRectangleRGB, rectR, rectG, rectB);
			SetColorEdit(hEditEllipseRGB, ellR, ellG, ellB);
		}

		{
			// Scroll
			hsR = hRadioShapeEllipse = CreateWindow(TEXT("scrollbar"), NULL,
				WS_CHILD | WS_VISIBLE | SBS_HORZ, 60, 225, 250, 20, hWnd,
				(HMENU)IDC_SCROLL_R, g_hInstance, NULL);

			hsG = hRadioShapeEllipse = CreateWindow(TEXT("scrollbar"), NULL,
				WS_CHILD | WS_VISIBLE | SBS_HORZ, 60, 250, 250, 20, hWnd,
				(HMENU)IDC_SCROLL_G, g_hInstance, NULL);

			hsB = hRadioShapeEllipse = CreateWindow(TEXT("scrollbar"), NULL,
				WS_CHILD | WS_VISIBLE | SBS_HORZ, 60, 275, 250, 20, hWnd,
				(HMENU)IDC_SCROLL_B, g_hInstance, NULL);

			SetScrollRange(hsR, SB_CTL, 0, 255, FALSE);
			SetScrollRange(hsG, SB_CTL, 0, 255, FALSE);
			SetScrollRange(hsB, SB_CTL, 0, 255, FALSE);
			SetScrollPos(hsR, SB_CTL, 0, FALSE);
			SetScrollPos(hsG, SB_CTL, 0, FALSE);
			SetScrollPos(hsB, SB_CTL, 0, FALSE);

			controllR = &rectR;
			controllG = &rectG;
			controllB = &rectB;
		}

		return 0;
	}

	case WM_COMMAND:
	{
		switch (LOWORD(wParam))
		{
		case IDC_RADIO_SHAPE_RECTANGLE:
			controllR = &rectR;
			controllG = &rectG;
			controllB = &rectB;
			break;

		case IDC_RADIO_SHAPE_ELLIPSE:
			break;
			controllR = &ellR;
			controllG = &ellG;
			controllB = &ellB;

		default:
			return 0;
		}

		SetScrollPos(hsR, SB_CTL, *controllR, FALSE);
		SetScrollPos(hsG, SB_CTL, *controllG, FALSE);
		SetScrollPos(hsB, SB_CTL, *controllB, FALSE);

		return 0;
	}

	case WM_PAINT:
	{
		hdc = BeginPaint(hWnd, &ps);
		HBRUSH brush = CreateSolidBrush(RGB(rectR, rectG, rectB));
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, brush);

		TextOut(hdc, 45, 10, TEXT("사각형"), 6);
		TextOut(hdc, 240, 10, TEXT("원"), 2);

		Rectangle(hdc, 20, 30, 120, 130);
		DeleteObject(SelectObject(hdc, oldBrush));

		brush = CreateSolidBrush(RGB(ellR, ellG, ellB));
		oldBrush = (HBRUSH)SelectObject(hdc, brush);

		Ellipse(hdc, 200, 30, 300, 130);


		DeleteObject(SelectObject(hdc, oldBrush));
		EndPaint(hWnd, &ps);
		return 0;
	}

	case WM_HSCROLL:
	{
		int scrollPos = GetScrollPos((HWND)lParam, SB_CTL);

		switch (LOWORD(wParam))
		{
		case SB_LINELEFT:
			scrollPos = max(0, scrollPos - 1);
			break;
		case SB_LINERIGHT:
			scrollPos = min(255, scrollPos + 1);
			break;
		case SB_PAGELEFT:
			scrollPos = max(0, scrollPos + 10);
			break;
		case SB_PAGERIGHT:
			scrollPos = min(255, scrollPos - 10);
			break;
		case SB_THUMBTRACK:
			scrollPos = HIWORD(wParam);
			break;
		}

		if ((HWND)lParam == hsR) *controllR = scrollPos;
		else if ((HWND)lParam == hsG) *controllG = scrollPos;
		else if ((HWND)lParam == hsB) *controllB = scrollPos;

		SetScrollPos((HWND)lParam, SB_CTL, scrollPos, TRUE);

		RECT reDrawArea = { 20, 30, 300, 130 };
		InvalidateRect(hWnd, &reDrawArea, FALSE);

		SetColorEdit(hEditRectangleRGB, rectR, rectG, rectB);
		SetColorEdit(hEditEllipseRGB, ellR, ellG, ellB);

		return 0;
	}

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}
