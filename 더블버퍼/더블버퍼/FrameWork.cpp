#include "FrameWork.h"

#pragma region Core
void CreateBuffer()
{
	for (int i = 0; i < 2; i++)
	{
		ScreenBuffer[i] =
			CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 
				0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	}

	CONSOLE_CURSOR_INFO cci = { 0 };
	cci.dwSize = 1;
	cci.bVisible = FALSE;

	SetConsoleCursorInfo(ScreenBuffer[0], &cci);
	SetConsoleCursorInfo(ScreenBuffer[1], &cci);
}



void ScreenTransform()
{
	screenIndex = (screenIndex == 0) ? 1 : 0;
	SetConsoleActiveScreenBuffer(ScreenBuffer[screenIndex]);
}

void ClearBuffer()
{
	COORD cd = { 0,0 };
	DWORD dw;


	FillConsoleOutputCharacter(ScreenBuffer[screenIndex], ' ',SCREEN_WIDTH * SCREEN_HEIGHT, cd, &dw);
}

void DeleteBuffer()
{
	for (int i = 0; i < 2; i++)
	{
		CloseHandle(ScreenBuffer[i]);
	}
}

void Render()
{
	ClearBuffer();

	Movement();
	// player 竺舛
	player->ScreenPrint(player->GetVector());
	Vector2D vector = Vector2D(player->GetVector()->GetX(), player->GetVector()->GetY() + 1);
	player->ScreenPrint(&vector);

	MapDraw(0, (SCREEN_HEIGHT - 2), "しししししししししししししししししししししししししししししししししししししししししししししししししししししししししししししししししししししししししししししし");

	Sleep(50);

	ScreenTransform();
}


void PlayerInfo::ScreenPrint(Vector2D* vector)
{
	DWORD dw;
	COORD cursorPos = { vector->GetX(), vector->GetY() };

	SetConsoleCursorPosition(ScreenBuffer[screenIndex], cursorPos);
	WriteFile(ScreenBuffer[screenIndex], player, strlen(player), &dw, NULL);
}
#pragma endregion

#pragma region Contents
void Movement()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'w':
			player->SetVector(player->GetVector()->GetX(), player->GetVector()->GetY() - 1);
			break;

		case 's':
			player->SetVector(player->GetVector()->GetX(), player->GetVector()->GetY() + 1);
			break;

		case 'a':
			player->SetVector(player->GetVector()->GetX() - 1, player->GetVector()->GetY());
			break;

		case 'd':
			player->SetVector(player->GetVector()->GetX() + 1, player->GetVector()->GetY());
			break;
		}
		PlayerMaxVector();
	}
}

void PlayerMaxVector()
{
		if (player->GetVector()->GetX() < 1)
		{
			player->SetVector(1, player->GetVector()->GetY());
		}

		if (player->GetVector()->GetX() > (SCREEN_WIDTH - 2))
		{
			player->SetVector(SCREEN_WIDTH - 2, player->GetVector()->GetY());
		}

		if (player->GetVector()->GetY() < 1)
		{
			player->SetVector(player->GetVector()->GetX(), 1);
		}

		if (player->GetVector()->GetY() > (SCREEN_HEIGHT - 2))
		{
			player->SetVector(player->GetVector()->GetX(), SCREEN_HEIGHT - 2);
		}

}

void MapDraw(int x, int y, const char* str)
{
	DWORD dw;
	COORD cursorPos = { x, y };

	SetConsoleCursorPosition(ScreenBuffer[screenIndex], cursorPos);
	WriteFile(ScreenBuffer[screenIndex], str, strlen(str), &dw, NULL);
}


#pragma endregion