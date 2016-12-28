
#include "playerControl.h"

void player1Control()
{
	glutSpecialFunc(player1SpecialKeys);
	glutSpecialUpFunc(player1SpecialKeysUp);
}

void player2Control()
{
	glutKeyboardFunc(player2Keys);
	glutKeyboardUpFunc(player2KeysUp);
}

void playMoving(GLint value)
{

	player1.position.x += player1.increment.x;
	player1.position.y += player1.increment.y;

	if(map[player1.position.x +  10][player1.position.y +  10] == 1)
	{
		player1.position.x -= player1.increment.x;
		player1.position.y -= player1.increment.y;
	}

	player2.position.x += player2.increment.x;
	player2.position.y += player2.increment.y;

	glutPostRedisplay();
	glutTimerFunc(20, playMoving, 1);
}
