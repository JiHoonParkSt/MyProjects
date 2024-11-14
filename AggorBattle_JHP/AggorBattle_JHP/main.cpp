#include "framework.h"

int main()
{
	srand(time(nullptr));

	World* world = new World();

	while (true)
	{
		world->Update();

		if (world->End())
			break;
	}

	delete world;

	return 0;
}