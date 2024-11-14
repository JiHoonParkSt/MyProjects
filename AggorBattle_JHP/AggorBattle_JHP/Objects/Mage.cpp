#include "framework.h"
#include "Mage.h"

Mage::Mage(int hp, int attack, string name)
:Player(hp, attack, name)
{
}

Mage::~Mage()
{
}

void Mage::Attack(Creature* other)
{
	cout << this->_name << "이(가) " << other->GetName() << "에게 공격을 시도합니다." << endl;

	int randNum = rand() % 4;

	if (randNum == 0)
	{
		cout << this->_name << "의 강력한 3연속 공격" << endl;
		other->TakeDamage(this, this->_attack * 3.0f);
	}
	else
		other->TakeDamage(this, this->_attack);
}



