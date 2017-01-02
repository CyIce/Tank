#include "initialization.h"

void initializate()
{
	tankAdd(player1Position,1);
	tankAdd(player2Position,2);

	player1 = tankHead;
	player2 = tankTail;

	player1->RBG = color[5];
	player2->RBG = color[9];

	tankAdd(enemyPosition, 9);

}
