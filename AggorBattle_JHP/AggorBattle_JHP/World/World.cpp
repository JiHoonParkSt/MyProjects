#include "framework.h"
#include "World.h"

World::World()
{
	Init();
}

World::~World()
{
	delete _hopGoblin;

	for (int i = 0; i < _players.size(); i++)
	{
		delete _players[i];
	}
}

void World::Init()
{
	CreatePlayers();
	_hopGoblin = new HopGoblin(15000, 150, "HopGoblin");
}

void World::Update()
{
	cout << "=======�÷��̾��� ��=======" << endl;
	for (int i = 0; i < 10; i++)
	{
		_players[i]->Attack(_hopGoblin);
	}

	cout << "=====���� ȩ����� ü��=====" << endl;
	_hopGoblin->PrintInfo();

	cout << "=======ȩ����� ��=======" << endl;
	auto boss = dynamic_cast<HopGoblin*>(_hopGoblin);
	if (boss != nullptr)
		boss->RangeAttack();
}

void World::CreatePlayers()
{
	while (true)
	{
		bool End = false;
		for (int i = 0; i < 10; i++)
		{
			int chooseClassNum = (rand() % 3);
			int randHp = (rand() % 500) + 1000;
			int randAtk = (rand() % 50) + 50;

			if (i == 0)
			{
				Knight* k = (new Knight(1500, 100, "MyPlayer"));
				_players.push_back(k);
			}
			else
			{
				if (chooseClassNum == 0)
				{
					Knight* k1 = new Knight(randHp, randAtk, "Knight" + to_string(i));
					_players.push_back(k1);
				}
				else if (chooseClassNum == 1)
				{
					Archer* a = new Archer(randHp, randAtk, "Archer" + to_string(i));
					_players.push_back(a);
				}
				else
				{
					Mage* m = new Mage(randHp, randAtk, "Mage" + to_string(i));
					_players.push_back(m);
				}
				if (i == 9)
					End = true;
			}
		}
		if (End == true)
			break;
	}
}

bool World::End()
{
	if (_hopGoblin->IsDead())
	{
		cout << "ȩ����� ���������ϴ�. �÷��̾��� �¸��Դϴ�." << endl;
		return true;
	}
	else if (IsPlayerAllDead())
	{
		cout << "��� �÷��̾ ����߽��ϴ�. ȩ����� �¸��Դϴ�." << endl;
		return true;
	}
	return false;
}

bool World::IsPlayerAllDead()
{
	return std::all_of(_players.begin(), _players.end(), [](Creature* creature) -> bool
		{
			if (creature->IsDead() == false)
				return false;
			return true;
		});
}
