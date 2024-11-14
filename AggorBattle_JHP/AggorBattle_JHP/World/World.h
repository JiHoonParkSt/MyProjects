#pragma once
class World
{
public:
	World();
	~World();

	void Init();
	void Update();
	void CreatePlayers();

	bool End();

	bool IsPlayerAllDead();

private:
	Creature* _hopGoblin;
	vector<Creature*> _players;
};

