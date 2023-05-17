#pragma once
#include <iostream>
using namespace std;
#pragma warning (disable : 4996)

class Machine
{
public:
	enum Power { On, Off };
	virtual void PowerOnOff(Power power) abstract;
	virtual void Repair() abstract;
};
