#include "shellControl.h"

void shellAdd(Tank tank)
{
	Shell *shell = (Shell*)malloc(sizeof(Shell));

	if (shell == NULL)
	{
		return;
	}

	//根据坦克方向计算子弹的初始位置；
	if (tank.direction == 0)
	{
		shell->position.x = tank.position.x;
		shell->position.y = tank.position.y + 20;
		shell->position.z = tank.position.z;
	}
	else if (tank.direction == 90)
	{
		shell->position.x = tank.position.x + 13;
		shell->position.y = tank.position.y + 7;
		shell->position.z = tank.position.z;
	}
	else if (tank.direction == 180)
	{
		shell->position.x = tank.position.x ;
		shell->position.y = tank.position.y - 5;
		shell->position.z = tank.position.z;
	}
	else if (tank.direction == 270)
	{
		shell->position.x = tank.position.x - 13;
		shell->position.y = tank.position.y + 7;
		shell->position.z = tank.position.z;
	}

	//根据坦克方向计算子弹的运动方向；
	shell->increment = direction[(tank.direction / 90)];

	//初始化子弹的最大运动距离；
	shell->power = 10;

	//初始化子弹的速度；
	shell->speed = 5;

	//初始化子弹的类型；
	shell->type = 1;

	//子弹的存在状态；
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
		shellPoint->position.x += shellPoint->increment.x*shellPoint->speed;
		shellPoint->position.y += shellPoint->increment.y*shellPoint->speed;
		shellPoint->position.z += shellPoint->increment.z*shellPoint->speed;

		shellPoint = shellPoint->next;
	}

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

void sheelDelete()
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

		if ((shellPoint1 != NULL) && (shellPoint1->isAlive == false))
		{
			shellPoint2->next = shellPoint1->next;
			free(shellPoint1);
			shellPoint1 = shellPoint2;
		}
	}
	
}
