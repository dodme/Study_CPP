#include "Human.h"

int main()
{
	Human* h1 = new Human();

	h1->SetHumanInfo("Ã¶¼ö", 10, Human::Gender::Man, 2, 50);
	h1->PrintHumanInfo();

	delete h1;
	h1 = nullptr;




	return 0;
}