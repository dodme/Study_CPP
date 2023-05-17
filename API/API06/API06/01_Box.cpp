#include <Windows.h>
#include "Header.h"

#include <iostream>
using namespace std;

#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")

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
	// Edit
	static HWND hEdit;
	static TCHAR editStr[256];
	static BOOL editIsEmpty = TRUE;

	// ListBox
	static HWND hListBox;
	static int selectIndex;
	static TCHAR selectString[256];
	static const TCHAR* Items[] = { TEXT("가붕이"),TEXT("우붕이"),TEXT("람붕이"),
	TEXT("다붕이"), TEXT("세붕이"), TEXT("문붕이"), TEXT("트붕이") };

	// ComboBox
	static HWND hComboBox;

	// Scroll Bar
	static HWND hsRed, hsGreen, hsBlue;
	static int colorRed, colorGreen, colorBlue;

	HDC hdc;
	PAINTSTRUCT ps;
	static HBRUSH brush, oldBrush;

	switch (msg)
	{
	case WM_CREATE:
	{
		{
			// Edit
			hEdit = CreateWindow(TEXT("edit"), TEXT("키미노..나마에와?"),
				WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL,
				10, 10, 200, 25, hwnd, (HMENU)IDC_EDIT, g_hInstance, NULL);
		}

		{
			hListBox = CreateWindow(TEXT("listBox"), NULL,
				WS_CHILD | WS_VISIBLE | WS_BORDER | LBS_NOTIFY,
				10, 40, 100, 200, hwnd, (HMENU)IDC_LISTBOX, g_hInstance, NULL);

			for (int i = 0; i < _countof(Items); i++)
			{
				SendMessage(hListBox, LB_ADDSTRING, 0, (LPARAM)Items[i]);
			}

		}

		{
			// Combo Box
			hComboBox = CreateWindow(TEXT("combobox"), NULL,
				WS_CHILD | WS_VISIBLE | WS_BORDER | CBS_DROPDOWN,
				120, 40, 100, 200, hwnd, (HMENU)IDC_COMBOBOX, g_hInstance, NULL);

			for (int i = 0; i < _countof(Items); i++)
			{
				SendMessage(hComboBox, CB_ADDSTRING, 0, (LPARAM)Items[i]);
			}
		}

		{
			hsRed = CreateWindow(TEXT("scrollbar"), NULL,
				WS_CHILD | WS_VISIBLE | SBS_HORZ,
				70, 250, 400, 20, hwnd, (HMENU)IDC_SCRRED, g_hInstance, NULL);

			hsGreen = CreateWindow(TEXT("scrollbar"), NULL,
				WS_CHILD | WS_VISIBLE | SBS_HORZ,
				70, 280, 400, 20, hwnd, (HMENU)IDC_SCRGREEN, g_hInstance, NULL);

			hsBlue = CreateWindow(TEXT("scrollbar"), NULL,
				WS_CHILD | WS_VISIBLE | SBS_HORZ,
				70, 310, 400, 20, hwnd, (HMENU)IDC_SCRBLUE, g_hInstance, NULL);

			SetScrollRange(hsRed, SB_CTL, 0, 255, FALSE);
			SetScrollRange(hsGreen, SB_CTL, 0, 255, FALSE);
			SetScrollRange(hsBlue, SB_CTL, 0, 255, FALSE);

			SetScrollPos(hsRed, SB_CTL, 0, FALSE);
			SetScrollPos(hsGreen, SB_CTL, 0, FALSE);
			SetScrollPos(hsBlue, SB_CTL, 0, FALSE);
		}

		CreateWindow(TEXT("static"), TEXT("R"), WS_CHILD | WS_VISIBLE,
			10, 250, 50, 25, hwnd, NULL, g_hInstance, NULL);

		CreateWindow(TEXT("static"), TEXT("G"), WS_CHILD | WS_VISIBLE,
			10, 280, 50, 25, hwnd, NULL, g_hInstance, NULL);

		CreateWindow(TEXT("static"), TEXT("B"), WS_CHILD | WS_VISIBLE,
			10, 310, 50, 25, hwnd, NULL, g_hInstance, NULL);

		return 0;
	}

	case WM_COMMAND:
	{
		switch (LOWORD(wParam))
		{
		case IDC_EDIT:
		{
			if (HIWORD(wParam) == EN_CHANGE) // Edit의 문자열이 변경되었다면
			{
				GetWindowText(hEdit, editStr, 256);

				SetWindowText(hwnd, editStr);
			}
			else if (HIWORD(wParam) == EN_SETFOCUS)
			{
				if (editIsEmpty)
				{
					SetWindowText(hEdit, NULL);
				}
			}
			else if (HIWORD(wParam) == EN_KILLFOCUS) // Focus를 잃었을때
			{
				GetWindowText(hEdit, editStr, 256);

				if (lstrlen(editStr) == 0)
				{
					editIsEmpty = TRUE;
					SetWindowText(hEdit, TEXT("키미노..나마에와?"));
				}
				else
					editIsEmpty = FALSE;
			}
			break;
		}

		case IDC_LISTBOX:
		{
			if (HIWORD(wParam) == LBN_SELCHANGE) // 사용자가 다른 항목으로 변경했다면
			{
				selectIndex = SendMessage(hListBox, LB_GETCURSEL, 0, 0);
				SendMessage(hListBox, LB_GETTEXT, selectIndex, (LPARAM)selectString);
				SetWindowText(hwnd, selectString);
			}
			break;
		}
		case IDC_COMBOBOX:
		{
			if (HIWORD(wParam) == CBN_SELCHANGE)
			{
				selectIndex = SendMessage(hComboBox, LB_GETCURSEL, 0, 0);
				SendMessage(hComboBox, CB_GETLBTEXT, selectIndex, (LPARAM)selectString);
				SetWindowText(hwnd, selectString);
			}

			break;
		}

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

		RECT reDrawArea = { 70, 340, 470, 540 };

		InvalidateRect(hwnd, &reDrawArea, FALSE);

		return 0;
	}

	case WM_PAINT:
	{
		hdc = BeginPaint(hwnd, &ps);
		brush = CreateSolidBrush(RGB(colorRed, colorGreen, colorBlue));
		oldBrush = (HBRUSH)SelectObject(hdc, brush);

		Rectangle(hdc, 70, 340, 470, 540);
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