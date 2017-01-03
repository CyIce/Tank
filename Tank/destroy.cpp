#include "destroy.h"

void destroyTank(GLint type)
{
	Tank *tank;

	tank = tankHead;

	while (tank != NULL)
	{
		if (tank->type == type)
		{
			int i, j;

			tank->isAlive = GL_FALSE;
			for (i = 1; i <= 19; i++)
			{
				for (j = 1; j <= 19; j++)
				{
					map[tank->position.x + i][tank->position.y + j] = 0;
				}
			}
			break;
		}

		tank = tank->next;
	}

	tankDelete();

	if (type == 1)
	{
		player1 = NULL;
	}
	else if (type == 2)
	{
		player2 = NULL;
	}
	else if (type == 3)
	{
		player1 = NULL;
		player2 = NULL;
	}

}
