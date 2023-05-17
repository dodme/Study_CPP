#pragma once
#include "Util.h"
#include "MonsterPattern.h"

void Battle(Warrior* warrior, Mage* mage, Crusader* crusader, Monster* monster);

void BuffEnd(Warrior* warrior, Crusader* crusader, Monster* monster,int burserkerTurn, int tauntTurn, int armorBreakTurn, int barrierBuff, int damageUpTurn, int turn);