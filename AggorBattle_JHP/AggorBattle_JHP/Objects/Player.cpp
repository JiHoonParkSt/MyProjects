#include "framework.h"
#include "Player.h"

Player::Player()
:Creature()
{
}

Player::Player(int hp, int attack, string name)
:Creature(hp, attack, name)
{
}

Player::~Player()
{
}
