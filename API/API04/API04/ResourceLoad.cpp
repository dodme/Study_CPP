#include <Windows.h>
#include "resource.h"

#include <iostream>
using namespace std;
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

// WndProc���� ����ϱ����� Main�� Instance��ü���簪
HINSTANCE g_Instance;

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPreInstance,
	LPSTR lpszCmdParam, int nCmdShow)
{
	g_Instance = hInstance;

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

	hWnd = CreateWindow(WndClass.lpszClassName, TEXT("API ����ȣ~"),
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
	HDC hdc;
	PAINTSTRUCT ps;

	static HBITMAP braveGirls;

	// ���� �׸���

	static int xPos, yPos, endXPos, endYPos;

	static BOOL isDraw = FALSE;

	switch (msg)
	{
	case WM_CREATE:
		braveGirls = LoadBitmap(g_Instance, MAKEINTRESOURCE(IDB_BITMAP1));
		return 0;

	case WM_LBUTTONDOWN:
		isDraw = TRUE;
		xPos = LOWORD(lParam);
		yPos = HIWORD(lParam);
		endXPos = LOWORD(lParam);
		endYPos = HIWORD(lParam);

		return 0;

	case WM_MOUSEMOVE:
		if (isDraw)
		{
			hdc = GetDC(hWnd);

			SetROP2(hdc, R2_NOT);

			MoveToEx(hdc, xPos, yPos, NULL);
			LineTo(hdc, endXPos, endYPos);

			endXPos = LOWORD(lParam);
			endYPos = HIWORD(lParam);

			MoveToEx(hdc, xPos, yPos, NULL);
			LineTo(hdc, endXPos, endYPos);

			ReleaseDC(hWnd, hdc);
		}
		return 0;

	case WM_LBUTTONUP:
		isDraw = FALSE;

		//hdc = GetDC(hWnd);

		//MoveToEx(hdc, xPos, yPos, NULL);
		//LineTo(hdc, endXPos, endYPos);

		//ReleaseDC(hWnd, hdc);

		return 0;

	case WM_PAINT:
	{
		hdc = BeginPaint(hWnd, &ps);
		HDC memDC = CreateCompatibleDC(hdc);
		// CreateCompatibleDC : �Ű������� ���� hdc�� �޸𸮻� ������ �����մϴ�.
		// DC�� �ϳ��� ���α׷��� 1�� �ۿ� �����Ҽ� ���� ������ �������� ������Ų �޸� DC��
		// �ݵ�� ���� ����� �Ѵ�.

		HBITMAP oldBBGirls = (HBITMAP)SelectObject(memDC, braveGirls);

		BITMAP bitmapInfo;
		GetObject(braveGirls, sizeof(BITMAP), &bitmapInfo);

		// BitBlt() : bitmap�� ��� ���� ��ŵ�ϴ�.
		// ��, �̹����� Ȯ��, ��� �� �Ұ��� �մϴ�.
		BitBlt(hdc, 10, 10, bitmapInfo.bmWidth, bitmapInfo.bmHeight, memDC, 0, 0, SRCCOPY);

		SelectObject(memDC, oldBBGirls);
		DeleteDC(memDC);


		EndPaint(hWnd, &ps);
		return 0;
	}

	case WM_DESTROY:
		DeleteObject(braveGirls);
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}