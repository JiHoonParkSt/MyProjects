#include "framework.h"
#include "Archer.h"

Archer::Archer(int hp, int attack, string name)
: Player(hp, attack, name)
{
}

Archer::~Archer()
{
}

void Archer::Attack(Creature* other)
{
	cout << this->_name << "이가 " << other->GetName() << "에게 공격을 시도합니다." << endl;
	
		int randNum = rand() % 100;
	if (randNum <= 49)
	{
		cout << this->_name << "의 크리티컬 공격" << endl;
		other->TakeDamage(this, this->_attack * 2.0f);
	}
	else
		other->TakeDamage(this, this->_attack);
}