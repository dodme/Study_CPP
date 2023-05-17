#include <iostream>
#include <cmath>
using namespace std;

// 2차원상의 점의 정보를 가지고있는 구조체
struct Vector2
{
	float x;
	float y;

	// Setter 설정자
	void SetVector2(int _x, int _y)
	{
		x = _x;
		y = _y;
	}

	// 두 점 사이의 거리
	double Distance(Vector2 pos2)
	{
		return sqrt(pow((x - pos2.x), 2) + pow((y - pos2.y), 2));
	}

	// 자기자신의 좌표에서 p2를 향한 방향(방향벡터?)
};


int main()
{
	Vector2 pos1;
	pos1.SetVector2(10, 20);

	Vector2 pos2;
	pos2.SetVector2(20, 30);

	cout << pos1.Distance(pos2) << endl;

	return 0;
}