#pragma once
#include "Machine.h"

class Computer : public Machine
{
	// Machine을(를) 통해 상속됨
	//virtual void PowerOnOff(Power power) override;
	virtual void Coding() abstract;
	virtual void Repair() override;
};
