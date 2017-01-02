#include "AI.h"

void enemyAI1(Tank *enemy,GLboolean b)
{
	if (b == GL_TRUE)
	{
		enemy->direction += 90;

		if (enemy->direction == 360)
		{
			enemy->direction = 0;
		}
		enemy->increment = direction[enemy->direction / 90];
	}


	if (clock() - enemy->time >= 1000)
	{
		enemy->time = clock();
		shellAdd(*enemy);
	}

}

void enemyAI2(Tank *enemy);

void enemyAI2(Tank * enemy)
{

}
