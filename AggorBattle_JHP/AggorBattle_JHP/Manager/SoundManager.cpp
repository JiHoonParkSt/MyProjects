#include "framework.h"
#include "SoundManager.h"

SoundManager* SoundManager::_instance = nullptr;

SoundManager::SoundManager()
{
	_sound = "Sound";
}
