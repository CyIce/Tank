
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

