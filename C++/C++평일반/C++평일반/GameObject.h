#pragma once
#include "Vector2D.h"

/// Vector2
/// �̵�
/// name, �̸� ���� ����
/// Stat
/// Idle - ��� ��¶�
/// Attack
/// Die
/// Gunner�� ������ ���� ���ϴ�.
/// Gunner�� ���� ����
/// ������ ���� ������ ���� ȸ�� ����
/// Slime�� ���� �ݴϴ�.



class GameObject
{
protected:
	char objectName[80];
	Vector2D vector;

public :
	void SetObjectName(const char* name);
};


