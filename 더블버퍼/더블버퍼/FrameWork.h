#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>
#pragma warning (disable : 4996)
using namespace std;


#pragma region ����
// ȿ���� - ������
// ��Ȱ�뼺
// �����
// �Լ��� ���α׷���
// ī�� �Ľ�Į ��׸�ǥ���

// ��� �׸������� - ���� Buffer 2��
// front back Clear
// Transform Flipping // ȭ�� ��ȯ
// Ŀ�� ����
// ȭ�� ���

// ������ Renderring

// Movement
// while(true) Render();
#pragma endregion

static HANDLE ScreenBuffer[2];
// HANDLE : ���α׷��� �ּ�
static int screenIndex;

struct Vector2D
{
private:
	int x = 80, y = 25; // �÷��̾��� ��ǥ

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

static PlayerInfo* player = new PlayerInfo(80, 46, "��");

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


