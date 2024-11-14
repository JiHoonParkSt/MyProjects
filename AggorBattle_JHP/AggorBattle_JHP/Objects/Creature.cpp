#include "framework.h"
#include "Creature.h"

Creature::Creature()
: _hp(0), _attack(0), _name("")
{
}

Creature::Creature(int hp, int attack, string name)
: _hp(hp), _attack(attack), _name(name)
{
}

Creature::~Creature()
{
}

void Creature::PrintInfo()
{
	cout << "NAME : " << this->_name << endl;
	cout << "HP : " << this->_hp << endl;
	cout << "ATTACK : " << this->_attack << endl;
}

void Creature::Attack(Creature* other)
{
	cout << this->_name << "이가 " << other->_name << "에게 공격을 시도합니다." << endl;
	SOUND->PrintSound();
	other->TakeDamage(this, this->_attack);
}

void Creature::TakeDamage(Creature* attacker, int amount)
{
	int afterHp = _hp - amount;
	SetHp(afterHp);
	cout << _name << "이가 " << attacker->_name << "에게 " << amount << "만큼의 데미지를 입었습니다." << endl;
}

void Creature::SetHp(int hp)
{
	if (_hp <= 0)
	{
		_hp = 0;
		return;
	}
	_hp = hp;
}

