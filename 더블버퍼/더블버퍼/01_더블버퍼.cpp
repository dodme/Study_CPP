#include "FrameWork.h"

int main()
{
	// = new PlayerInfo(80, 25, "ㄴㅇㄱ");
	CreateBuffer();

	while (true)
	{
		Render();
	}

	// 메모리 해제
	DeleteBuffer();
	delete player;
	player = nullptr;

	return 0;
}