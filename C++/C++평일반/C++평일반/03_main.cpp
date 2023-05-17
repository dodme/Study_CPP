#include "MyDeskTop.h"

int main()
{
	MyDeskTop* pc = new MyDeskTop();

	pc->PowerOnOff(Machine::Power::On);

	pc->Coding();
	pc->Repair();

	pc->PowerOnOff(Machine::Power::Off);

	delete pc;
	pc = nullptr;


	return 0;
}