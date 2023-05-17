#pragma once
#include "Vector2D.h"

/// Vector2
/// 이동
/// name, 이름 변경 가능
/// Stat
/// Idle - 대기 라는뜻
/// Attack
/// Die
/// Gunner는 어택중 총을 쏩니다.
/// Gunner는 점프 가능
/// 점프를 통해 슬라임 공격 회피 가능
/// Slime은 총총 뜁니다.



class GameObject
{
protected:
	char objectName[80];
	Vector2D vector;

public :
	void SetObjectName(const char* name);
};


