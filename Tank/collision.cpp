#include "collision.h"

void gameBoundary()
{
	int i, j;

	//���嵱ǰ��Ļ��С��Ӧ����Ϸ�߽磻
	for (i = 0; i <= windowWidth; i++)
	{
		for (j = 0; j < 7; j++)
		{
			map[i][13-j] = 1;
			map[i][windowHeight-8+j]=1;
		}
	}

	for (i = 0; i <= windowHeight; i++)
	{

		for (j = 0; j < 7; j++)
		{
			map[10-j][i] = 1;
			map[mapWidth-10+j][i] = 1;
		}
	}
}

void tankBoundary(Tank tank)
{

}
