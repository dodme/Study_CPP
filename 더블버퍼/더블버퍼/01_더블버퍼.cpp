#include "FrameWork.h"

int main()
{
	// = new PlayerInfo(80, 25, "������");
	CreateBuffer();

	while (true)
	{
		Render();
	}

	// �޸� ����
	DeleteBuffer();
	delete player;
	player = nullptr;

	return 0;
}