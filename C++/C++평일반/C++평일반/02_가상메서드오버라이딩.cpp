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

		if (shapes[i]) // �޸𸮰� ��ȿ���� Ȯ���մϴ�.
		{
			delete shapes[i];
			shapes[i] = nullptr;
		}
	}

	return 0;
}