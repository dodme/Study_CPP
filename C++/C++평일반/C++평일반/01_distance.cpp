#include <iostream>
using namespace std;

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

	void Distance(Vector2 vec)
	{
		int count = 1;
		while (1)
		{
			if ((((x - vec.x) % count) == 0) && (((y - vec.y) % count) == 0))
			{
				cout << ((x - vec.x) / count) << "," << 
					((y - vec.y) / count) << "��������" << count << "��ů �̵�" << endl;
			}
			count++;
		}
	}
};

int main()
{



	return 0;
}