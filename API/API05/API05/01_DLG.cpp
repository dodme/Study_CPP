#include <Windows.h>
#include "Define.h"

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

// WndProc에서 사용하기위한 Main의 Instance객체복사값
HINSTANCE g_hInstance;

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPreInstance,
	LPSTR lpszCmdParam, int nCmdShow)
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

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	static HWND hcb1;
	static HWND hcb2;
	static HWND hcb3;
	static HWND hcb4;

	static BOOL isEllipse = FALSE;
	HDC hdc;
	PAINTSTRUCT ps;

	RECT reDrawArea = { 200, 100, 400, 200 };

	static HWND hrb1;
	static HWND hrb2;
	static HWND hrb3;
	static HWND hrb4;
	static HWND hrb5;
	static HWND hrb6;

	static UINT shape = SHAPE_RECTANGLE;
	static COLORREF color = RGB(0, 0, 0);

	RECT reDrawArea2 = { 300, 210, 500, 510 };


	switch (msg)
	{
	case WM_CREATE:
	{
		{
			// > Button
			CreateWindow(TEXT("button"), TEXT("누르지마."),
				WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
				20, 20, 100, 25, hWnd, (HMENU)IDC_BUTTON_1,
				g_hInstance,NULL);

			CreateWindow(TEXT("button"), TEXT("쮸~~압"),
				WS_THICKFRAME | WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
				20, 50, 100, 30, hWnd, (HMENU)IDC_BUTTON_2, g_hInstance, NULL);
		}

		{
			// > Check Box
			hcb1 = CreateWindow(TEXT("button"), TEXT("원그려?"),
				WS_CHILD | WS_VISIBLE | BS_CHECKBOX,
				20, 80, 160, 25, hWnd, (HMENU)IDC_CHECKBOX_BUTTON_1,
				g_hInstance, NULL);
			hcb2 = CreateWindow(TEXT("button"), TEXT("종료할떄 인사해?"),
				WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX,
				20, 110, 180, 25, hWnd, (HMENU)IDC_CHECKBOX_BUTTON_2,
				g_hInstance, NULL);
			hcb3 = CreateWindow(TEXT("button"), TEXT("3 State"),
				WS_CHILD | WS_VISIBLE | BS_3STATE,
				20, 140, 160, 25, hWnd, (HMENU)IDC_CHECKBOX_BUTTON_3,
				g_hInstance, NULL);
			hcb4 = CreateWindow(TEXT("button"), TEXT("Auto 3 State"),
				WS_CHILD | WS_VISIBLE | BS_AUTO3STATE,
				20, 170, 160, 25, hWnd, (HMENU)IDC_CHECKBOX_BUTTON_4,
				g_hInstance, NULL);
		}

		{
			// Radio Group
			// 장식용임

			CreateWindow(TEXT("button"), TEXT("도형"),
				WS_CHILD | WS_VISIBLE | BS_GROUPBOX,
				5, 200, 120, 110, hWnd, (HMENU)IDC_RADIO_GROUP_1,
				g_hInstance, NULL);

			CreateWindow(TEXT("button"), TEXT("색상"),
				WS_CHILD | WS_VISIBLE | BS_GROUPBOX,
				145, 200, 120, 110, hWnd, (HMENU)IDC_RADIO_GROUP_2,
				g_hInstance, NULL);
		}

		{
			// Radio Button

			hrb1 = CreateWindow(TEXT("button"), TEXT("사각형"),
				WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,
				10, 215, 100, 30, hWnd, (HMENU)IDC_RADIO_BUTTON_1, g_hInstance, NULL);

			hrb2 = CreateWindow(TEXT("button"), TEXT("원"),
				WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,
				10, 245, 100, 30, hWnd, (HMENU)IDC_RADIO_BUTTON_2, g_hInstance, NULL);

			hrb3 = CreateWindow(TEXT("button"), TEXT("선"),
				WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,
				10, 275, 100, 30, hWnd, (HMENU)IDC_RADIO_BUTTON_3, g_hInstance, NULL);

			hrb4 = CreateWindow(TEXT("button"), TEXT("검정"),
				WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,
				150, 215, 100, 30, hWnd, (HMENU)IDC_RADIO_BUTTON_4, g_hInstance, NULL);

			hrb5 = CreateWindow(TEXT("button"), TEXT("빨강"),
				WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,
				150, 245, 100, 30, hWnd, (HMENU)IDC_RADIO_BUTTON_5, g_hInstance, NULL);

			hrb6 = CreateWindow(TEXT("button"), TEXT("파랑"),
				WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,
				150, 275, 100, 30, hWnd, (HMENU)IDC_RADIO_BUTTON_6, g_hInstance, NULL);

			CheckRadioButton(hWnd, IDC_RADIO_BUTTON_1, IDC_RADIO_BUTTON_3, IDC_RADIO_BUTTON_1);
			CheckRadioButton(hWnd, IDC_RADIO_BUTTON_4, IDC_RADIO_BUTTON_6, IDC_RADIO_BUTTON_4);
		}

		return 0;
	}

	case WM_COMMAND:
	{
		switch(LOWORD(wParam))
		{
		case IDC_BUTTON_1:
			MessageBox(hWnd, TEXT("Yes or Yes"), TEXT("API 즐겁지?"), MB_OK);
			break;

		case IDC_BUTTON_2:
			MessageBox(hWnd, TEXT("점심 나가서 먹을꺼 같애"), TEXT("핳ㅎ하하하ㅏㅏㅏㅏ하하핳하"), MB_OK);
			break;

		case IDC_CHECKBOX_BUTTON_1:
			if (SendMessage(hcb1, BM_GETCHECK, 0, 0) == BST_UNCHECKED)
			{
				SendMessage(hcb1, BM_SETCHECK, BST_CHECKED,0);

				isEllipse = TRUE;
			}
			else
			{
				SendMessage(hcb1, BM_SETCHECK, BST_UNCHECKED,0);

				isEllipse = FALSE;
			}
			InvalidateRect(hWnd, &reDrawArea, TRUE);
			break;

		case IDC_CHECKBOX_BUTTON_3:
			// Unchecked => checked => indeterminate
			break;

		case IDC_RADIO_BUTTON_1:
			shape = SHAPE_RECTANGLE;
			InvalidateRect(hWnd, &reDrawArea2, TRUE);
			break;

		case IDC_RADIO_BUTTON_2:
			shape = SHAPE_ELLIPSE;
			InvalidateRect(hWnd, &reDrawArea2, TRUE);
			break;

		case IDC_RADIO_BUTTON_3:
			shape = SHAPE_LINE;
			InvalidateRect(hWnd, &reDrawArea2, TRUE);
			break;

		case IDC_RADIO_BUTTON_4:
			color = RGB(0, 0, 0);
			InvalidateRect(hWnd, &reDrawArea2, TRUE);
			break;

		case IDC_RADIO_BUTTON_5:
			color = RGB(255, 0, 0);
			InvalidateRect(hWnd, &reDrawArea2, TRUE);
			break;

		case IDC_RADIO_BUTTON_6:
			color = RGB(0, 0, 255);
			InvalidateRect(hWnd, &reDrawArea2, TRUE);
			break;
		}

		return 0;
	}

	case WM_PAINT:
	{
		hdc = BeginPaint(hWnd, &ps);

		if (isEllipse)
		{
			Ellipse(hdc, 200, 100, 400, 200);
		}
		else
		{
			Rectangle(hdc, 200, 100, 400, 200);
		}

		HBRUSH brush = CreateSolidBrush(color);
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, brush);

		HPEN pen = CreatePen(PS_SOLID, 1, color);
		HPEN oldPen = (HPEN)SelectObject(hdc, pen);

		switch (shape)
		{
		case SHAPE_RECTANGLE:
			Rectangle(hdc, 300, 210, 500, 310);
			break;

		case SHAPE_ELLIPSE:
			Ellipse(hdc, 300, 210, 500, 310);
			break;

		case SHAPE_LINE:
			MoveToEx(hdc, 300, 210, NULL);
			LineTo(hdc, 500, 310);
			break;
		}

		DeleteObject(SelectObject(hdc, oldBrush));
		DeleteObject(SelectObject(hdc, oldPen));

		EndPaint(hWnd, &ps);
		return 0;
	}

	case WM_DESTROY:
		if (SendMessage(hcb2, BM_GETCHECK, 0, 0) == BST_CHECKED)
		{
			MessageBox(hWnd, TEXT("고생했다.."), TEXT("오늘은 여기까지.."), MB_OK);
		}

		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}