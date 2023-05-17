#include <Windows.h>

// API?
/// Windows32 API

// Main�� 2��
// winMain : ���α׷��� ����� ����
// wndProc : �۾�����
/// > ��Ƽ ����Ʈ ����
/// > â


// Windows �ü��
/// > �޼��� ��������̴�.*****
/// > �ȼ����� �׷��ȱ��.*****
/// > ���� �������� �ü��.
/// > ��Ƽ�׽�ŷ�� �����ϴ�.
/// > �������̽��� �ϰ�ȭ �Ǿ��ִ�.
/// > ���ҽ��� �з��Ǿ��ִ�.

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

// CALLBACK : ���ι��� �ƴ϶� �ü������ ������ �Լ�

// HANDLE : ���α׷��� �ּ�

// HWND(HANDLE WINDOW) : �ش� ���α׷��� �ּҸ� ��� ����

// WPARAM : 

// LPARAM : 

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPreInstance, LPSTR lpszCmdParam,
	int nCmdShow)
{
	HWND hWnd;
	MSG Msg;
	WNDCLASS WndClass;

	// ������ Ŭ���� ����
	/// ���࿵��
	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;

	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	WndClass.hInstance = hInstance;
	WndClass.lpfnWndProc = WndProc;
	WndClass.lpszClassName = TEXT("WndClass");
	WndClass.lpszMenuName = NULL;
	// Horizontal / Vertical
	WndClass.style = CS_HREDRAW | CS_VREDRAW;

	// ������ Ŭ���� ���
	RegisterClass(&WndClass);

	// ������ â ����
	hWnd = CreateWindow(WndClass.lpszClassName, TEXT("��� API���迡~"),
		WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 800, 640, NULL, NULL, hInstance, NULL);

	// ������â Ȱ��ȭ
	ShowWindow(hWnd, nCmdShow);

	// �޼��� ����ó��
	while (GetMessage(&Msg, NULL, NULL, NULL))
	{
		TranslateMessage(&Msg);

		DispatchMessage(&Msg);
	}
	
	return (int)Msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}
