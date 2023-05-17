#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>
#pragma warning (disable : 4996)
using namespace std;


#pragma region 설명
// 효율적 - 생산적
// 재활용성
// 방어적
// 함수형 프로그래밍
// 카멜 파스칼 헝그리표기법

// 어디에 그릴것인지 - 버퍼 Buffer 2개
// front back Clear
// Transform Flipping // 화면 전환
// 커서 삭제
// 화면 출력

// 렌더링 Renderring

// Movement
// while(true) Render();
#pragma endregion

static HANDLE ScreenBuffer[2];
// HANDLE : 프로그램의 주소
static int screenIndex;

struct Vector2D
{
private:
	int x = 80, y = 25; // 플레이어의 좌표

public:
	Vector2D(int x, int y)
	{
		this->x = x;
		this->y = y;
	}

	void SetVector(int x, int y)
	{
		this->x = x;
		this->y = y;
	}

	int GetX() { return x; }
	int GetY() { return y; }

};

class PlayerInfo
{
private:
	char* player = nullptr;
	Vector2D* playerVec = nullptr;


public:
	PlayerInfo(Vector2D* vector, const char* str)
	{
		player = new char[128];

		strcpy(player, str);

		playerVec = new Vector2D(80, 25);
	}

	PlayerInfo(int x, int y, const char* str)
	{
		player = new char[128];

		strcpy(player, str);

		playerVec = new Vector2D(x,y);
	}

	void SetPlayer(const char* player) { strcpy(this->player, player); }
	void SetVector(int x, int y) { playerVec->SetVector(x, y); }

	char* GetPlayer() { return player; }
	Vector2D* GetVector() { return playerVec; }

	void ScreenPrint(Vector2D* vector);

	~PlayerInfo()
	{
		delete playerVec;
		playerVec = nullptr;
		delete[] player;
		player = nullptr;
	}

};

static PlayerInfo* player = new PlayerInfo(80, 46, "ㅁ");

#define SCREEN_WIDTH 160
#define SCREEN_HEIGHT 50


// Core
void CreateBuffer();
void Movement();
void ScreenTransform();
void ClearBuffer();
void DeleteBuffer();
void Render();

// Contents
void PlayerMaxVector();
void MapDraw(int x, int y, const char* str);


