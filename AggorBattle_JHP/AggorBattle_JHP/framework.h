#pragma once


#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>

using namespace std;

#include "Manager/SoundManager.h"

#include "Objects/Creature.h"

#include "Objects/Player.h"
#include "Objects/Knight.h"
#include "Objects/Archer.h"
#include "Objects/Mage.h"

#include "Objects/Monster.h"
#include "Objects/Goblin.h"
#include "Objects/HopGoblin.h"

#include "World/World.h"

#define SOUND SoundManager::GetInstance()