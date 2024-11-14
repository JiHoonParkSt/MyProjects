#pragma once
class Knight : public Player
{
public:
	Knight(int hp, int attack, string name);
	~Knight();

	virtual void Attack(Creature* other) override;

private:
	int _maxHp;
};

