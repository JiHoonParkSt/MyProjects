#pragma once
class Archer : public Player
{
public:
	Archer(int hp, int attack, string name);
	~Archer();

	virtual void Attack(Creature* other) override;
};

