#include "AI.h"
#include<stdio.h>
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

void enemyAI2(Tank *enemy)
{
	double distance1 = 100000, distance2 = 100000;
	Tank *target;

	if (gameState >= 3)
	{
		enemy->increment.x = 0;
		enemy->increment.y = 0;
		return;
	}


	if (player1 != NULL)
	{
		distance1 = pow((enemy->position.x - player1->position.x), 2) + pow((enemy->position.y - player1->position.y), 2);
	}

	if (player2 != NULL)
	{
		distance2 = pow((enemy->position.x - player2->position.x), 2) + pow((enemy->position.y - player2->position.y), 2);
	}

	if (player1 == NULL)
	{
		target = player2;
	}
	else if (player2 == NULL)
	{
		target = player1;
	}
	else
	{
		distance1 < distance2 ? target = player1 : target = player2;
	}



	if (enemy->position.x - target->position.x > 5)
	{
		enemy->direction = 270;
		enemy->increment = direction[3];
	}
	else if (enemy->position.x - target->position.x < -5)
	{
		enemy->direction = 90;
		enemy->increment = direction[1];
	}
	else if (enemy->position.y - target->position.y > 5)
	{
		enemy->direction = 180;
		enemy->increment = direction[2];
	}
	else if (enemy->position.y - target->position.y < -5)
	{
		enemy->direction = 0;
		enemy->increment = direction[0];
	}

	if (clock() - enemy->time >= 1000)
	{
		enemy->time = clock();
		shellAdd(*enemy);
	}

}
