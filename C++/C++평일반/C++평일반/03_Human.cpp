#include "03_Human_h.h"


int main()
{
	Human* human = new Human();

	human->SetHumanInfo("����ȣ~", Man, 60, 190, 80);
	human->PrintHumanInfo();

	delete human;
	human = nullptr;



	return 0;
}