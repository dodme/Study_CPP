#include <iostream>
using namespace std;

// 함수

// 오버로딩 OverLoading
// 같은 이름의 함수를 중복정의하는것

// 오버로딩의 조건
/// 함수의 이름이 같아야한다!
/// 매개변수의 자료형이 다르거나, 갯수가 달라야한다

void Attack(int* hp)
{
	*hp -= 10;
}

void Attack(int* hp, int damage)
{
	*hp -= damage;
}

void Attack(int* hp, int damage, int def)
{
	*hp -= (damage - def);
}

void Attack(int* hp, float damage)
{
	*hp -= (int)damage;
}

int main()
{
	int hp = 100;

	Attack(&hp, 10);

	cout << hp << endl;

	return 0;
}


// 숙제!
/// 철수의 성적산출 프로그램
/// 철수의 국어 영어 수학 점수를 입력받아
/// 총점, 평균(실수, 정수), 최고점수 함수를 정의 하세요!