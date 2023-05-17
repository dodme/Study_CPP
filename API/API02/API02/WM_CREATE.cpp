#include <Windows.h>

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPreInstance, LPSTR lpszCmdParam, int nCmdShow)
{
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

	hWnd = CreateWindow(WndClass.lpszClassName, TEXT("오늘도 재밌는 API"), WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, 800, 640, NULL, NULL, hInstance, NULL);

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
	// 두가지의 직업을 동시에 실행할 수 없다.
	// 도화지 DC(Device Context) HDC
	// 붓     GetStockObject()
	// 물감   WHITE_BRUSH

	static int xPos, yPos; // 문자열의 위치

	static TCHAR str[80]; // 사용자가 입력할 문자열
	int len = 0; // 입력한 문자열의 길이

	HDC hdc;
	PAINTSTRUCT ps;

	switch (msg)
	{
	case WM_CREATE: // 윈도우 창이 생성될 때 발생하는 메세지
		xPos = 400;
		yPos = 300;
		return 0;

	case WM_CHAR: // 문자입력 키가 눌렸을 때 발생하는 메세지
	{
		len = lstrlen(str);
		str[len] = (TCHAR)wParam;
		str[len + 1] = TEXT('\0');

		RECT reDrawRect = { xPos, yPos, xPos + 100, yPos + 100 };

		return InvalidateRect(NULL, &reDrawRect, TRUE);
	}

	case WM_KEYDOWN:
	{
		switch (wParam)
		{
		case VK_LEFT:
			xPos -= 8;
			InvalidateRect(hWnd, NULL, TRUE);
			return 0;

		case VK_RIGHT:
			xPos += 8;
			InvalidateRect(hWnd, NULL, TRUE);
			return 0;

		case VK_UP:
			yPos -= 8;
			InvalidateRect(hWnd, NULL, TRUE);
			return 0;

		case VK_DOWN:
			yPos += 8;
			InvalidateRect(hWnd, NULL, TRUE);
			return 0;

		case VK_ESCAPE:
			PostQuitMessage(0);
			return 0;
		}
	}

	case WM_LBUTTONDOWN:
		MessageBox(hWnd, TEXT("내용"), TEXT("캡션"), MB_RIGHT | MB_OKCANCEL);
		return 0;

	case WM_PAINT:
	{
		hdc = BeginPaint(hWnd, &ps); // DC 할당

		TextOut(hdc, xPos, yPos, str, lstrlen(str));

		EndPaint(hWnd, &ps); // DC 제거
		return 0;
	}

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
};