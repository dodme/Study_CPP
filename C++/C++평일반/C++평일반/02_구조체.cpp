#include <iostream>
#include <cmath>
using namespace std;

// 2�������� ���� ������ �������ִ� ����ü
struct Vector2
{
	float x;
	float y;

	// Setter ������
	void SetVector2(int _x, int _y)
	{
		x = _x;
		y = _y;
	}

	// �� �� ������ �Ÿ�
	double Distance(Vector2 pos2)
	{
		return sqrt(pow((x - pos2.x), 2) + pow((y - pos2.y), 2));
	}

	// �ڱ��ڽ��� ��ǥ���� p2�� ���� ����(���⺤��?)
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