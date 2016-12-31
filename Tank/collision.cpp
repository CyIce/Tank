#include "collision.h"

void gameBoundary()
{
	int i, j;

	//定义当前屏幕大小对应的游戏边界；
	for (i = 0; i <= windowWidth; i++)
	{
		map[i][0] = 3;
		for (j = 0; j <= 10; j++)
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

	for (i = 0; i <= 20; i++)
	{
		for (j = 0; j <= 20; j++)
		{
			map[tank.position.x + i][tank.position.y + j] = 1;
		}
	}

}

void changeTankBoundary(Tank tank)
{
	int i;

	if (tank.increment.x != 0)
	{
		for (i = 0; i <= 15; i++)
		{
			map[tank.position.x][i] = 0;
			map[tank.position.x + tank.increment.x * 20][i] = 1;
		}
	}
	else if (tank.increment.y != 0)
	{
		for (i = 0; i <= 15; i++)
		{
			map[i][tank.position.y] = 0;
			map[i][tank.position.y + tank.increment.y * 10] = 1;
		}
	}
}
