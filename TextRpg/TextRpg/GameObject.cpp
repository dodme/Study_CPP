#include "GameObject.h"

void GameObject::SetStat(int hp, int damage, int def, int cri, int eva)
{
	stat.hp = hp;
	stat.damage = damage;
	stat.def = def;
	stat.cri = cri;
	stat.eva = eva;
}
