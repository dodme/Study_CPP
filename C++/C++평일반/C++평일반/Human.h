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
	// 함수 const : 함수 내부에서 멤버변수의 값을 변경하고싶지 않을때!
	// 개발자의 실수를 방지할 수 있다!
};