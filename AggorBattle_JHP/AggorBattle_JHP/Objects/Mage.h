#pragma once
class Mage : public Player
{
public:
	Mage(int hp, int attack, string name);
	~Mage();

	virtual void Attack(Creature* other) override;

private:
};

