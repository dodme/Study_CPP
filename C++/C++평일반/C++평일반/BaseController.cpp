#include "BaseController.h"

BaseController::BaseController(int _hp, int _damage, int _moveSpeed, int _jumpSpeed)
{
	stat.hp = _hp;
	stat.damage = _damage;
	stat.moveSpeed = _moveSpeed;
	stat.jumpSpeed = _jumpSpeed;
}
