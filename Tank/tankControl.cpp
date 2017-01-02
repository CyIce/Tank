#include "tankControl.h"

#include<stdio.h>
void tankAdd(Vector3i vec, GLint mark)
{
	Tank *tank = (Tank*)malloc(sizeof(Tank));

	if (tank == NULL)
	{
		return;
	}

	//记录坦克的种类；
	tank->type = mark;
	//初始化坦克的存在状态；
	tank->isAlive = GL_TRUE;
	//初始化坦克的位置；
	tank->position = vec;
	//初始化坦克下一步的位置；
	tank->increment = direction[1];
	//初始化坦克的方向；
	tank->direction = 0;
	//初始化坦克的边界；
	tankBoundary(*tank);

	if (tankHead == NULL)
	{
		tankHead = tank;
		tankTail = tank;
	}
	else
	{
		tankTail->next = tank;
		tankTail = tank;
	}

	tankTail->next = NULL;
}

void tankMoving(GLint value)
{
	int i, x, y;
	GLboolean bl = GL_FALSE;
	Tank *tankPoint;

	tankPoint = tankHead;

	while (tankPoint != NULL)
	{

		if (tankPoint->increment.x != 0)
		{
			if (tankPoint->direction == 90)
			{
				x = tankPoint->position.x + tankPoint->increment.x + 19;
			}
			else
			{
				x = tankPoint->position.x + tankPoint->increment.x;
			}


			if (x > 0)
			{
				GLboolean b = GL_TRUE;
				for (i = 1; i <= 19; i++)
				{
					int y = tankPoint->position.y + i;
					if (y <= 0)
					{
						if (tankPoint->type == 9)
						{
							bl = GL_TRUE;
						}
						break;
					}
					if (map[x][y] != 0)
					{
						b = GL_FALSE;

						if (tankPoint->type == 9)
						{
							bl = GL_TRUE;
						}

						break;
					}
				}

				if (b == GL_TRUE)
				{
					tankPoint->position.x += tankPoint->increment.x;
					changeTankBoundary(tankPoint);
				}

			}
			else if (tankPoint->type >= 8)
			{
				bl = GL_TRUE;
			}
		}
		else if (tankPoint->increment.y != 0)
		{
			if (tankPoint->direction == 0)
			{
				y = tankPoint->position.y + tankPoint->increment.y + 19;
			}
			else
			{
				y = tankPoint->position.y + tankPoint->increment.y;
			}


			if (y > 0)
			{
				GLboolean b = GL_TRUE;
				for (i = 1; i <= 19; i++)
				{
					int x = tankPoint->position.x + i;

					if (x <= 0)
					{
						if (tankPoint->type == 9)
						{
							bl = GL_TRUE;
						}
						break;
					}

					if (map[x][y] != 0)
					{
						b = GL_FALSE;

						if (tankPoint->type == 9)
						{
							bl = GL_TRUE;
						}

						break;
					}
				}

				if (b == GL_TRUE)
				{
					tankPoint->position.y += tankPoint->increment.y;
					changeTankBoundary(tankPoint);
				}
			}
			else if (tankPoint->type == 9)
			{
				bl = GL_TRUE;
			}
		}

		if (tankPoint->type == 9)
		{
			enemyAI1(tankPoint, bl);
		}

		tankPoint = tankPoint->next;
	}
	glutPostRedisplay();
	glutTimerFunc(20, tankMoving, 1);
}

void tankShowing()
{
	Tank *tankPoint;

	tankPoint = tankHead;

	while (tankPoint != NULL)
	{
		if (tankPoint->isAlive == GL_TRUE)
		{
			generateTank(*tankPoint);
		}

		tankPoint = tankPoint->next;
	}
}

void tankDelete()
{
	Tank *tankPoint1, *tankPoint2;

	while ((tankHead != NULL) && (tankHead->isAlive == GL_FALSE))
	{
		tankPoint1 = tankHead;
		tankHead = tankHead->next;
		free(tankPoint1);
	}

	tankPoint1 = tankHead;

	while (tankPoint1 != NULL)
	{
		tankPoint2 = tankPoint1;
		tankPoint1 = tankPoint1->next;

		if ((tankPoint1 != NULL) && (tankPoint1->isAlive == false))
		{
			tankPoint2->next = tankPoint1->next;
			free(tankPoint1);
			tankPoint1 = tankPoint2;
		}
	}
}
