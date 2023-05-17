#include <Windows.h>

// API?
/// Windows32 API

// Main문 2개
// winMain : 프로그램을 만드는 영역
// wndProc : 작업영역
/// > 멀티 바이트 형식
/// > 창


// Windows 운영체제
/// > 메세지 구동방식이다.*****
/// > 픽셀단위 그래픽기반.*****
/// > 가장 보편적인 운영체제.
/// > 멀티테스킹이 가능하다.
/// > 인터페이스가 일관화 되어있다.
/// > 리소스가 분래되어있다.

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

// CALLBACK : 메인문이 아니라 운영체제한테 보내는 함수

// HANDLE : 프로그램의 주소

// HWND(HANDLE WINDOW) : 해당 프로그램의 주소를 담는 형식

// WPARAM : 

// LPARAM : 

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPreInstance, LPSTR lpszCmdParam,
	int nCmdShow)
{
	HWND hWnd;
	MSG Msg;
	WNDCLASS WndClass;

	// 윈도우 클래스 설정
	/// 예약영역
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

	// 윈도우 클래스 등록
	RegisterClass(&WndClass);

	// 윈도우 창 생성
	hWnd = CreateWindow(WndClass.lpszClassName, TEXT("어서와 API세계에~"),
		WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 800, 640, NULL, NULL, hInstance, NULL);

	// 윈도우창 활성화
	ShowWindow(hWnd, nCmdShow);

	// 메세지 루프처리
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
