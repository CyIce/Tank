#include "collision.h"

void gameBoundary()
{
	int i, j;

	//定义当前屏幕大小对应的游戏边界；
	for (i = 0; i <= windowWidth; i++)
	{
		map[i][0] = 1;
		for (j = 0; j <= 10; j++)
		{			
			map[i][windowHeight - j] = 1;
		}
	}

	for (i = 0; i <= windowHeight; i++)
	{
		map[0][i] = 1;
		map[mapWidth][i] = 1;
	}
}

void tankBoundary(Tank tank)
{

}
