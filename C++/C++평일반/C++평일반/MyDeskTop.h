#pragma once
#include "Computer.h"

class MyDeskTop final : public Computer
{
public:


	// Computer��(��) ���� ��ӵ�
	virtual void PowerOnOff(Power power) override;

	virtual void Coding() override;

};