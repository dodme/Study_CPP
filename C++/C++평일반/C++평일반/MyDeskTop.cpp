#include "MyDeskTop.h"

void MyDeskTop::PowerOnOff(Power power)
{
	cout << "������" << ((power == Power::On) ? "��" : "��") << "���ϴ�." << endl;
}

void MyDeskTop::Coding()
{
	for (int j = 0; j < 3; j++)
	{
		cout << "�ڵ���";
		for (int i = 0; i < 3; i++)
		{
			cout << ".";
		}
		system("cls");
	}

	cout << "�Ͼ�� ���¿���..." << endl;
}
