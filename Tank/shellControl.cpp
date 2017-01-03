#include "shellControl.h"
#include<stdio.h>
void shellAdd(Tank tank)
{
	Shell *shell = (Shell*)malloc(sizeof(Shell));

	if (shell == NULL || &tank == NULL)
	{
		return;
	}

	//����̹�˷�������ӵ��ĳ�ʼλ�ã�
	if (tank.direction == 0)
	{
		shell->position.x = tank.position.x + 10;
		shell->position.y = tank.position.y + 18;
		shell->position.z = tank.position.z;
	}
	else if (tank.direction == 90)
	{
		shell->position.x = tank.position.x + 16;
		shell->position.y = tank.position.y + 10;
		shell->position.z = tank.position.z;
	}
	else if (tank.direction == 180)
	{
		shell->position.x = tank.position.x +10;
		shell->position.y = tank.position.y + 2;
		shell->position.z = tank.position.z;
	}
	else if (tank.direction == 270)
	{
		shell->position.x = tank.position.x + 2;
		shell->position.y = tank.position.y + 10;
		shell->position.z = tank.position.z;
	}

	//����̹�˷�������ӵ����˶�����
	shell->increment = direction[(tank.direction / 90)];

	//��ʼ���ӵ��ı߽磻
	shellBoundary(shell);

	//��ʼ���ӵ�������˶����룻
	shell->power = 10;

	//��ʼ���ӵ����ٶȣ�
	shell->speed = 5;

	//��¼�ӵ������ͣ�
	shell->type = tank.type;

	//��ʼ���ӵ��Ĵ���״̬��
	shell->isAlive = GL_TRUE;

	if (shellHead == NULL)
	{
		shellHead = shell;
		shellTail = shell;

	}
	else
	{
		shellTail->next = shell;
		shellTail = shell;
	}

	shellTail->next = NULL;
}

void shellMoving(GLint value)
{
	Shell *shellPoint;
	
	shellPoint = shellHead;

	while (shellPoint!=NULL)
	{
		if (shellPoint->position.x > 0 && shellPoint->position.y > 0 && shellPoint->position.x < mapWidth && shellPoint->position.y < windowHeight)
		{
			map[shellPoint->position.x][shellPoint->position.y] = 0;
		}

		shellPoint->position.x += shellPoint->increment.x*shellPoint->speed;
		shellPoint->position.y += shellPoint->increment.y*shellPoint->speed;
		shellPoint->position.z += shellPoint->increment.z*shellPoint->speed;

		if (shellPoint->position.x <= 0 || shellPoint->position.y <= 0 || shellPoint->position.x >= windowWidth || shellPoint->position.y >= windowHeight)
		{
			shellPoint->isAlive = GL_FALSE;
			//continue;
		}
		else if(shellPoint->position.x > 0 && shellPoint->position.y > 0 && shellPoint->position.x < windowWidth && shellPoint->position.y < windowHeight)
		{
			if (map[shellPoint->position.x][shellPoint->position.y] >= 10 && shellPoint->type <= 2)
			{
				if (shellPoint->type == 1)
				{
					player1Score++;				
				}
				else if (shellPoint->type == 2)
				{
					player2Score++;
				}  

				destroyTank(map[shellPoint->position.x][shellPoint->position.y]);
				map[shellPoint->position.x][shellPoint->position.y] = 0;
			}
			else if (map[shellPoint->position.x][shellPoint->position.y] > 0 && map[shellPoint->position.x][shellPoint->position.y] <= 2  && shellPoint->type >= 10)
			{
				gameState += map[shellPoint->position.x][shellPoint->position.y];

				destroyTank(map[shellPoint->position.x][shellPoint->position.y]);
				map[shellPoint->position.x][shellPoint->position.y] = 0;
			}
			else
			{
				map[shellPoint->position.x][shellPoint->position.y] = 4;
			}

		}
		shellPoint = shellPoint->next;
	}
	shellDelete();
	glutPostRedisplay();
	glutTimerFunc(20, shellMoving, 1);
}

void shellShowing()
{
	Shell *shellPoint;

	shellPoint = shellHead;

	while (shellPoint != NULL)
	{
		if (shellPoint->isAlive == GL_TRUE)
		{
			generateShell(*shellPoint);
		}

		shellPoint = shellPoint->next;
	}
}

void shellDelete()
{
	Shell *shellPoint1, *shellPoint2;

	while ((shellHead != NULL) && (shellHead->isAlive == GL_FALSE))
	{
		shellPoint1 = shellHead;
		shellHead = shellHead->next;
		free(shellPoint1);
	}

	shellPoint1 = shellHead;

	while (shellPoint1 != NULL)
	{
		shellPoint2 = shellPoint1;
		shellPoint1 = shellPoint1->next;

		if ((shellPoint1 != NULL) && (shellPoint1->isAlive == GL_FALSE))
		{
			shellPoint2->next = shellPoint1->next;
			free(shellPoint1);
			shellPoint1 = shellPoint2;
		}
	}
	
}
