#include <iostream>
using namespace std;

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

	void Distance(Vector2 vec)
	{
		int count = 1;
		while (1)
		{
			if ((((x - vec.x) % count) == 0) && (((y - vec.y) % count) == 0))
			{
				cout << ((x - vec.x) / count) << "," << 
					((y - vec.y) / count) << "방향으로" << count << "만킁 이동" << endl;
			}
			count++;
		}
	}
};

int main()
{



	return 0;
}