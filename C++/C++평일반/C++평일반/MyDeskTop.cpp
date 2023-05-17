#include "MyDeskTop.h"

void MyDeskTop::PowerOnOff(Power power)
{
	cout << "Àü¿øÀ»" << ((power == Power::On) ? "Ä×" : "²°") << "½À´Ï´Ù." << endl;
}

void MyDeskTop::Coding()
{
	for (int j = 0; j < 3; j++)
	{
		cout << "ÄÚµùÁß";
		for (int i = 0; i < 3; i++)
		{
			cout << ".";
		}
		system("cls");
	}

	cout << "ÇÏ¾é°Ô ºÒÅÂ¿ü´Ù..." << endl;
}
