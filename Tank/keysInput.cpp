
#include "keysInput.h"


void processSpecialKeys(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:	player1.increment = direction[0]; player1.direction = -90; break;
	case GLUT_KEY_RIGHT:player1.increment = direction[2]; player1.direction =  90; break;
	case GLUT_KEY_DOWN:	player1.increment = direction[3]; player1.direction = 180; break;
	case GLUT_KEY_UP:	player1.increment = direction[1]; player1.direction =   0; break;
	default:break;
	}
}

void processSpecialKeysUp(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:	changeNestStep(&player1.increment.x, -1); break;
	case GLUT_KEY_RIGHT:changeNestStep(&player1.increment.x,  1); break;
	case GLUT_KEY_DOWN:	changeNestStep(&player1.increment.y, -1); break;
	case GLUT_KEY_UP:	changeNestStep(&player1.increment.y,  1); break;
	default:break;
	}
}

void processKeys(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'a':case 'A':	player2.increment = direction[0]; player2.direction = -90; break;
	case 'd':case 'D':  player2.increment = direction[2]; player2.direction =  90; break;
	case 's':case 'S':	player2.increment = direction[3]; player2.direction = 180; break;
	case 'w':case 'W':	player2.increment = direction[1]; player2.direction =   0; break;
	default:break;
	}
}

void processKeysUp(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'a':case 'A':	changeNestStep(&player2.increment.x, -1); break;
	case 'd':case 'D':  changeNestStep(&player2.increment.x,  1); break;
	case 's':case 'S':	changeNestStep(&player2.increment.y, -1); break;
	case 'w':case 'W':	changeNestStep(&player2.increment.y,  1); break;
	default:break;
	}
}

void changeNestStep(GLfloat * value, GLfloat flag)
{
	if (*value == flag)
	{
		*value = 0;
	}
}
