#include "Computer.h"
#include <Windows.h>

void Computer::Repair()
{
	cout << "�����մϴ�.." << endl;

	for (int i = 0; i < 3; i++)
	{
		cout << ".";
		_sleep(2000);
	}
	system("cls");
	cout << "������ �������ϴ�.." << endl;

}
