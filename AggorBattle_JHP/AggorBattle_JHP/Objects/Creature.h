#pragma once
class Creature
{
public:
	Creature();
	Creature(int hp, int attack, string name);
	~Creature();

	void PrintInfo();

	virtual void Attack(Creature* other);
	virtual void TakeDamage(Creature* attacker, int amount);

	bool IsDead() { return GetHp() <= 0; }
	const int& GetHp() { return _hp; }
	void SetHp(int hp);
	const string& GetName() { return _name; }

protected:
	int _hp;
	int _attack;
	string _name;
};

