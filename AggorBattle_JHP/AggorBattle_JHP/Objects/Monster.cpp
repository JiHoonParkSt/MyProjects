#include "framework.h"
#include "Monster.h"

Monster::Monster(int hp, int attack, string name)
: Creature(hp, attack, name)
{
}

Monster::~Monster()
{
}
