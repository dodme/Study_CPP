#include <Windows.h>
#include "resource.h"

HINSTANCE g_hInstance;

enum State
{
	WAIT,
	RUN,
	PAUSE,
};

HWND hTimerDlg;

int setSec;
int nowSec;
State state = State::WAIT;

BOOL CALLBACK TimerProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPreInstance, LPSTR lpszCmdParam, int nCmdShow)
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

	hWnd = CreateWindow(WndClass.lpszClassName, TEXT("API의 마지막"), WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, 800, 640, NULL, NULL, hInstance, NULL);

	ShowWindow(hWnd, nCmdShow);

	while (GetMessage(&msg, NULL, NULL, NULL))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (int)msg.wParam;
}


BOOL CALLBACK TimerProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_CREATE:
	{
		hTimerDlg = NULL;

		CreateWindow(TEXT("button"), TEXT("열어줘~열어줘~"), WS_CHILD | WS_VISIBLE,
			10, 10, 100, 100, hWnd, (HMENU)IDC_BUTTON_OPENTIMER, g_hInstance, NULL);

		return 0;
	}

	case WM_COMMAND:
	{
		switch (LOWORD(wParam))
		{
		case IDC_BUTTON_OPENTIMER:
		{
			if (!IsWindow(hTimerDlg))
			{
				//IsWindow : hWnd가 존재하는지(유효한지) 확인합니다.
				hTimerDlg = CreateDialog(g_hInstance,
					MAKEINTRESOURCE(IDD_DIALOG1), hWnd, (DLGPROC)TimerProc);

				ShowWindow(hTimerDlg, SW_SHOW);
			}
			break;
		}
		}

		return 0;
	}

	case WM_DESTROY:
		if (IsWindow(hTimerDlg))
		{
			DestroyWindow(hTimerDlg);
			hTimerDlg = NULL;
		}

		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	TCHAR TimeStr[256];

	switch (msg)
	{
	case WM_INITDIALOG:
		state = State::WAIT;
		return FALSE;

	case WM_COMMAND:
	{
		switch (LOWORD(wParam))
		{
		case IDC_BUTTON_START:
			setSec = GetDlgItemInt(hWnd, IDC_EDIT_SEC, NULL, FALSE);

			if (setSec <= 0)
			{
				MessageBox(hWnd, TEXT("시간이 음수냐?"), TEXT("에코궁씀"), MB_OK);
				return FALSE;
			}

			nowSec = setSec;

			SetTimer(hWnd, 0, 1000, NULL);

			state = State::RUN;

			break;

		case IDC_BUTTON_PAUSE:

			switch (state)
			{
			case State::PAUSE:
				SetWindowText(GetDlgItem(hWnd, IDC_BUTTON_PAUSE), TEXT("일시정지"));
				SetTimer(hWnd, 0, 1000, NULL);
				state = State::RUN;
				break;

			case State::RUN:
				SetWindowText(GetDlgItem(hWnd, IDC_BUTTON_PAUSE), TEXT("재시작"));
				KillTimer(hWnd, 0);
				state = State::PAUSE;
				break;
			}

			break;

		case IDC_BUTTON_CLOSE:
			if (state == State::RUN) KillTimer(hWnd, 0);
			DestroyWindow(hTimerDlg);
			hTimerDlg = NULL;
			break;
		}

		return FALSE;
	}

	case WM_TIMER:
		nowSec--;

		wsprintf(TimeStr, TEXT("남은시간 : %d초"), nowSec);
		SetDlgItemText(hWnd, IDC_STATIC_COUNT, TimeStr);

		if (nowSec <= 0)
		{
			if (IsDlgButtonChecked(hWnd, IDC_CHECK_ALARM) == BST_CHECKED)
			{
				MessageBeep(0);
			}
			KillTimer(hWnd, 0);
			state = State::WAIT;
			MessageBox(hWnd, TEXT("빼앰"), TEXT("일어나세요 용사여"), MB_OK);
		}

		return FALSE;
	}

	return FALSE;
}