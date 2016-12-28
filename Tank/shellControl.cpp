#include "shellControl.h"

void shellAdd(Tank tank)
{
	Shell *shell = (Shell*)malloc(sizeof(Shell));

	if (shell == NULL)
	{
		return;
	}

	//����̹�˷�������ӵ��ĳ�ʼλ�ã�
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

	//����̹�˷�������ӵ����˶�����
	shell->increment = direction[(tank.direction / 90)];

	//��ʼ���ӵ�������˶����룻
	shell->power = 10;

	//��ʼ���ӵ����ٶȣ�
	shell->speed = 5;

	//��ʼ���ӵ������ͣ�
	shell->type = 1;

	//�ӵ��Ĵ���״̬��
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
