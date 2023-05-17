#pragma once
#include "GameObject.h"

struct Stat
{
public:
	int hp;
	int damage;
	int moveSpeed;
	int jumpSpeed;
};

enum State
{
	Idle,
	Move,
	Jump,
	Attack,
	Die,
};

class BaseController : public GameObject
{
protected :
	Stat stat;
	State state = State::Idle;

public:
	Stat GetStat() { return stat; }
	State GetState() { return state; }
	int GetHp() { return stat.hp; }

	void SetStat(Stat _stat) { stat = _stat; }
	void SetState(State _state) { state = _state; }
	void SetHp(int hp) { stat.hp = hp; }
};

