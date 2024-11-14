#pragma once

struct PlayerInfo
{
	Creature* _player;
	int _totalDamage;
};

class HopGoblin : public Goblin
{
public:
	HopGoblin(int hp, int attack, string name);
	~HopGoblin();

	virtual void Attack(Creature* other) override;
	void RangeAttack();
	virtual void TakeDamage(Creature* attacker, int amount) override;

private:
	vector<PlayerInfo> _playerAggroTable;
};

