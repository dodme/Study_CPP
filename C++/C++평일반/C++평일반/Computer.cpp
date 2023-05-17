#include "Computer.h"
#include <Windows.h>

void Computer::Repair()
{
	cout << "수리합니다.." << endl;

	for (int i = 0; i < 3; i++)
	{
		cout << ".";
		_sleep(2000);
	}
	system("cls");
	cout << "수리가 끝났습니다.." << endl;

}
