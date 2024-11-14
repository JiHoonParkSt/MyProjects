#include "framework.h"
#include "Knight.h"

Knight::Knight(int hp, int attack, string name)
:Player(hp, attack, name)
, _maxHp(hp)
{
}

Knight::~Knight()
{
}

void Knight::Attack(Creature* other)
{
	cout << this->_name << "이(가) " << other->GetName() << "에게 공격을 시도합니다." << endl;

	float ratio = (float)_hp / (float)_maxHp;
	if (ratio >= 0.5f)
	{
		other->TakeDamage(this, this->_attack);
	}
	else if (ratio < 0.5f)
	{
		cout << "체력이 적은 Knight의 2연속 공격" << endl;
		other->TakeDamage(this, this->_attack * 2.0f);
	}
}
