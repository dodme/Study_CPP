#pragma once
#include <iostream>
#pragma warning (disable : 4996)
using namespace std;

typedef unsigned int uint;


class Human
{
public:
	enum Gender
	{
		Man,
		Woman
	};

	char name[256];
	uint age;
	Gender gender;
	uint stature;
	uint weight;

	void SetHumanInfo(const char* name, uint age,
		Gender gender, uint stature, uint weight);

	void PrintHumanInfo() const;
	// �Լ� const : �Լ� ���ο��� ��������� ���� �����ϰ���� ������!
	// �������� �Ǽ��� ������ �� �ִ�!
};