#include "shell.h"

void addShell(Tank tank)
{
	Shell *shell = (Shell*)malloc(sizeof(Shell));

	if (shell == nullptr)
	{
		return;
	}

	//����̹�˷�������ӵ��ĳ�ʼλ�ã�
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

	//����̹�˷�������ӵ����˶�����
	shell->increment = direction[(tank.direction / 90) + 1];

	//��ʼ���ӵ�������˶����룻
	shell->power = 10;

	//��ʼ���ӵ����ٶȣ�
	shell->speed = 5;

	//��ʼ���ӵ������ͣ�
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
