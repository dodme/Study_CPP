#pragma once
#include "Machine.h"

class Computer : public Machine
{
	// Machine��(��) ���� ��ӵ�
	//virtual void PowerOnOff(Power power) override;
	virtual void Coding() abstract;
	virtual void Repair() override;
};
