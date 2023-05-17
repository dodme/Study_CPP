#pragma once
#include "Monster.h"
#include "Warrior.h"
#include "Mage.h"
#include "Crusader.h"

int Random(int maxValue);

void PrintBattleInfo(Warrior* warrior, Mage* mage, Crusader* crusader, Monster* monster);

void Clear();

void Delay();