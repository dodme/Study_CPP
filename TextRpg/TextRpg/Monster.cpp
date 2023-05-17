#include "Monster.h"

Monster::Monster(Job job)
{
	this->job = job;

	switch (job)
	{
	case Slime:
		strcpy(name, "Slime");
		SetStat(300, 30, 0, 0, 0);
		break;
	case Goblin:
		strcpy(name, "Goblin");
		SetStat(500, 50, 5, 10, 10);
		break;
	case Troll:
		strcpy(name, "Troll");
		SetStat(800, 100, 30, 20, 0);
		break;
	case Golem:
		strcpy(name, "Golem");
		SetStat(1000, 80, 50, 0, 10);
		break;
	case Dragon:
		strcpy(name, "Dragon");
		SetStat(5000, 300, 100, 40, 40);
		break;
	default:
		strcpy(name, "Unknown");
		SetStat(8000, 500, 300, 70, 70);
		break;
	}
}
