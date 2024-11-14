#pragma once
class SoundManager
{
private:
	SoundManager();
	~SoundManager() {}

public:
	static void Create()
	{
		if (_instance != nullptr)
			_instance = new SoundManager();
	}

	static SoundManager* GetInstance()
	{
		return _instance;
	}

	static void Delete()
	{
		if (_instance != nullptr)
		{
			delete _instance;
			_instance = nullptr;
		}
	}

	void PrintSound() { cout << _sound << endl; }



	string _sound;
	static SoundManager* _instance;
};

