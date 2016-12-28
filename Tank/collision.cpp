#include "collision.h"

#include<stdio.h>
void boundary()
{
	int i, j;

	//清除上一次确定的游戏边界；
	for (i = 0; i <= 250; i++)
	{
		for (j = 0; j <= 480; j++)
		{
			if (map[i][j] == 1)
			{
				map[i][j] = 0;
			}
		}
	}

	printf("%d", windowWidth);
	//定义当前屏幕大小对应的游戏边界；
	for (int i = 0; i <= windowWidth; i++)
	{
		for (j = 0; j < 7; j++)
		{
			map[i][13-j] = 1;
	
			map[i][windowHeight-8+j]=1;
		}


	}
	for (int i = 0; i <= windowHeight; i++)
	{
		for (j = 0; j < 7; j++)
		{
			map[10-j][i] = 1;
			map[windowWidth-10+j][i] = 1;
		}

	}
}
