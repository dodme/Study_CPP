#include "Character.h"

Character::Character(const char* name, Job job)
{
	strcpy(this->name, name);
	this->job = job;
	switch(job)
	{
	case Warrior:
		SetStat(500, 100, 10, 15, 10);
		break;
	case Archer:
		SetStat(300, 150, 0, 30, 20);
		break;
	default:
		SetStat(1000, 300, 50, 50, 50);
		break;
	}
}

void Character::Battle(Monster* monster)
{
	srand(GetTickCount64());

	while (1)
	{
		if (stat.hp <= 0)
		{
			cout << "패배했습니다." << endl;
		}
		else if()
	}
}
