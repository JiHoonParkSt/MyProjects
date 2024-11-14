#include "framework.h"
#include "HopGoblin.h"

HopGoblin::HopGoblin(int hp, int attack, string name)
: Goblin(hp, attack, name)
{
}

HopGoblin::~HopGoblin()
{
}

void HopGoblin::Attack(Creature* other)
{
	cout << this->_name << "이가 " << other->GetName() << "에게 공격을 시도합니다." << endl;
	other->TakeDamage(this, this->_attack);
}

void HopGoblin::RangeAttack()
{
	auto removeIter = std::remove_if(_playerAggroTable.begin(), _playerAggroTable.end(), [](const PlayerInfo& player) -> bool
		{
			if (player._player->IsDead() == true)
				return true;
			return false;
		});

	_playerAggroTable.erase(removeIter, _playerAggroTable.end());

	std::sort(_playerAggroTable.begin(), _playerAggroTable.end(), [](const PlayerInfo& aPlayer, const PlayerInfo& bPlayer) -> bool
		{
			if (aPlayer._totalDamage > bPlayer._totalDamage)
				return true;
			return false;
		});

	for (int i = 0; i < 4; i++)
	{
		if (i >= _playerAggroTable.size())
			break;
		Creature* curPlayer = _playerAggroTable[i]._player;
		this->Attack(curPlayer);
	}
}

void HopGoblin::TakeDamage(Creature* attacker, int amount)
{
	auto iter = std::find_if(_playerAggroTable.begin(), _playerAggroTable.end(), [attacker] (const PlayerInfo& info) -> bool
	{
			if (info._player == attacker)
				return true;
			return false;
	});

	if (iter == _playerAggroTable.end())
	{
		PlayerInfo curInfo;
		curInfo._player = attacker;
		curInfo._totalDamage = amount;

		_playerAggroTable.push_back(curInfo);
	}
	else
		iter->_totalDamage += amount;

	int afterHp = _hp - amount;
	SetHp(afterHp);
	cout << _name << "이 " << attacker->GetName() << "에게 " << amount << "만큼의 데미지를 입었습니다." << endl;
}

