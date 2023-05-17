#include "Rectangle.h"
#include "Ellipse.h"

int main()
{
	Shape** shapes = new Shape * [2]
	{
		new Rectangle(),
		new Ellipse()
	};

	for (int i = 0; i < 2; i++)
	{
		shapes[i]->Draw();

		if (shapes[i]) // 메모리가 유효한지 확인합니다.
		{
			delete shapes[i];
			shapes[i] = nullptr;
		}
	}

	return 0;
}