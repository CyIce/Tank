#include "collision.h"

void gameBoundary()
{
	int i, j;

	//定义当前屏幕大小对应的游戏边界；
	for (i = 0; i <= windowWidth; i++)
	{
		map[i][0] = 3;
		for (j = 0; j <= 1; j++)
		{			
			map[i][windowHeight - j] = 3;
		}
	}

	for (i = 0; i <= windowHeight; i++)
	{
		map[0][i] = 3;
		map[mapWidth][i] = 3;
	}
}

void tankBoundary(Tank tank)
{
	int i, j;

	for (i = 1; i <= 19; i++)
	{
		for (j = 1; j <= 19; j++)
		{
			map[tank.position.x + i][tank.position.y + j] = tank.type;
		}
	}

}

void changeTankBoundary(Tank *tank)
{
	int i;

	if (tank->direction == 0)
	{
		for (i = 1; i <= 19; i++)
		{
			map[tank->position.x + i][tank->position.y] = 0;
			map[tank->position.x + i][tank->position.y + 19] = tank->type;
		}
	}
	else if (tank->direction == 90)
	{
		for (i = 1; i <= 19; i++)
		{
			map[tank->position.x + 19][tank->position.y +i] = tank->type;
			map[tank->position.x][tank->position.y + i] = 0;
		}
	}
	else if (tank->direction == 180)
	{
		for (i = 1; i <= 19; i++)
		{
			map[tank->position.x + i][tank->position.y + 1] = tank->type;
			map[tank->position.x + i][tank->position.y + 20] = 0;
		}
	}
	else if (tank->direction == 270)
	{
		for (i = 1; i <= 19; i++)
		{
			map[tank->position.x + 1][tank->position.y + i] = tank->type;
			map[tank->position.x + 20][tank->position.y + i] = 0;
		}
	}
}

void shellBoundary(Shell * shell)
{
	if (shell->position.x > 0 && shell->position.y > 0 && shell->position.x < mapWidth && shell->position.y < windowHeight)
	{
		map[shell->position.x][shell->position.y] = 4;
	}

	shell->isAlive = GL_FALSE;

}
