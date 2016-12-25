#include "shell.h"

void addShell(Tank tank)
{
	Shell *shell = (Shell*)malloc(sizeof(Shell));

	if (shell == nullptr)
	{
		return;
	}

	//根据坦克方向计算子弹的初始位置；
	if (tank.direction == 0)
	{
		shell->position.x = tank.position.x + 10;
		shell->position.y = tank.position.y + 5;
		shell->position.z = tank.position.z;
	}
	else if (tank.direction == 180)
	{
		shell->position.x = tank.position.x + 10;
		shell->position.y = tank.position.y - 5;
		shell->position.z = tank.position.z;
	}
	else if (tank.direction == -90)
	{
		shell->position.x = tank.position.x - 5;
		shell->position.y = tank.position.y + 10;
		shell->position.z = tank.position.z;
	}
	else if (tank.direction == 90)
	{
		shell->position.x = tank.position.x + 5;
		shell->position.y = tank.position.y + 10;
		shell->position.z = tank.position.z;
	}

	//根据坦克方向计算子弹的运动方向；
	shell->increment = direction[(tank.direction / 90) + 1];

	//初始化子弹的最大运动距离；
	shell->power = 10;

	//初始化子弹的速度；
	shell->speed = 5;

	//初始化子弹的类型；
	shell->type = 1;

	if (shellHead == nullptr)
	{
		shellHead = shell;
		shellTail = shell;
		shellHead->next = nullptr;
		shellTail->next = nullptr;
	}
	else
	{
		shellTail->next = shell;
		shellTail = shell;
	}



}

void shellMoving(Tank * head)
{
}
