#include "destroy.h"

void destroyTank(GLint type)
{
	Tank *tank;

	tank = tankHead;

	while (tank != NULL)
	{
		if (tank->type == type)
		{
			tank->isAlive = GL_FALSE;
			break;
		}

		tank = tank->next;
	}

	tankDelete();
}
