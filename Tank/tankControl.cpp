#include "tankControl.h"

#include<stdio.h>
void tankAdd(Vector3i vec, GLint mark)
{
	Tank *tank = (Tank*)malloc(sizeof(Tank));

	if (tank == NULL)
	{
		return;
	}

	//��¼̹�˵����ࣻ
	tank->type = mark;
	//��ʼ��̹�˵Ĵ���״̬��
	tank->isAlive = GL_TRUE;
	//��ʼ��̹�˵�λ�ã�
	tank->position = vec;
	//��ʼ��̹����һ����λ�ã�
	tank->increment = direction[1];
	//��ʼ��̹�˵ķ���
	tank->direction = 0;
	//��ʼ��̹�˵ı߽磻
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
						if (tankPoint->type >= 10)
						{
							bl = GL_TRUE;
						}
						break;
					}
					if (map[x][y] != 0)
					{
						b = GL_FALSE;

						if (tankPoint->type >= 10)
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
			else if (tankPoint->type >= 10)
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
							b = GL_TRUE;
						}
						break;
					}

					if (map[x][y] != 0)
					{
						b = GL_FALSE;

						if (tankPoint->type >= 10)
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
			else if (tankPoint->type >= 10)
			{
				bl = GL_TRUE;
			}
		}

		//AI1��
		if (tankPoint->type >= 10 && tankPoint->type < 50)
		{
			enemyAI1(tankPoint, bl);
		}
		//AI2;
		if (tankPoint->type >= 50 && tankPoint->type)
		{
			enemyAI2(tankPoint);
		}

		tankPoint = tankPoint->next;
	}
	glutPostRedisplay();
	glutTimerFunc(20, tankMoving, 1);
}

void tankShowing()
{
	int numbers = 0;

	Tank *tankPoint;

	tankPoint = tankHead;

	while (tankPoint != NULL)
	{
		if (tankPoint->isAlive == GL_TRUE)
		{
			generateTank(*tankPoint);
			numbers++;
		}

		tankPoint = tankPoint->next;
	}

	maxTankNum = numbers;
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

		if ((tankPoint1 != NULL) && (tankPoint1->isAlive == GL_FALSE))
		{
			//tankPoint2->next = tankPoint1->next;
			//free(tankPoint1);
			//tankPoint1 = tankPoint2;
		}
	}
}

void tankAppend(GLint value)
{
	int lv=50;

	if (clock() - lastTime > 3000 && maxTankNum <= 6)
	{
		lastTime = clock();

		if (colorNum >= 12)
		{
			colorNum = 0;
		}

		tankAdd(enemyPosition, num);
		tankTail->RBG = color[colorNum];
		colorNum++;

		tankAdd(enemyPosition, lv+num);
		tankTail->RBG = color[colorNum];
		colorNum++;

		num+=1;
	}

	glutTimerFunc(100, tankAppend, 1);
}
