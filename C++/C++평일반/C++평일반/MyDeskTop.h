#pragma once
#include "Computer.h"

class MyDeskTop final : public Computer
{
public:


	// Computer을(를) 통해 상속됨
	virtual void PowerOnOff(Power power) override;

	virtual void Coding() override;

};