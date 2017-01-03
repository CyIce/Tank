
#include "keysInput.h"

#include<stdio.h>

void player1SpecialKeys(int key, int x, int y)
{
	if (gameState == 1 || gameState>=3)
	{
		return;
	}
	switch (key)
	{
	case GLUT_KEY_LEFT:	player1->increment = direction[3]; player1->direction = 270; break;
	case GLUT_KEY_RIGHT:player1->increment = direction[1]; player1->direction =  90; break;
	case GLUT_KEY_DOWN:	player1->increment = direction[2]; player1->direction = 180; break;
	case GLUT_KEY_UP:	player1->increment = direction[0]; player1->direction =   0; break;
	//���1�����ӵ���
	case GLUT_KEY_PAGE_UP: shellAdd(*player1); break;
	default:break;
	}
}

void player1SpecialKeysUp(int key, int x, int y)
{
	if (gameState == 1 || gameState >= 3)
	{
		return;
	}
	switch (key)
	{
	case GLUT_KEY_LEFT:	changeNestStep(&player1->increment.x, -1); break;
	case GLUT_KEY_RIGHT:changeNestStep(&player1->increment.x,  1); break;
	case GLUT_KEY_DOWN:	changeNestStep(&player1->increment.y, -1); break;
	case GLUT_KEY_UP:	changeNestStep(&player1->increment.y,  1); break;
	default:break;
	}
}


void player2Keys(unsigned char key, int x, int y)
{
	if (gameState == 2 || gameState >= 3)
	{
		return;
	}
	switch (key)
	{
	case 'a' :case 'A':	player2->increment = direction[3]; player2->direction = 270; break;
	case 'd' :case 'D': player2->increment = direction[1]; player2->direction =  90; break;
	case 's' :case 'S':	player2->increment = direction[2]; player2->direction = 180; break;
	case 'w' :case 'W':	player2->increment = direction[0]; player2->direction =   0; break;

	//���2�����ӵ���
	case 32: shellAdd(*player2); break;
	default:break;
	}
}

void player2KeysUp(unsigned char key, int x, int y)
{
	if (gameState == 2 || gameState >= 3)
	{
		return;
	}
	switch (key)
	{
	case 'a':case 'A':	changeNestStep(&player2->increment.x, -1); break;
	case 'd':case 'D':  changeNestStep(&player2->increment.x,  1); break;
	case 's':case 'S':	changeNestStep(&player2->increment.y, -1); break;
	case 'w':case 'W':	changeNestStep(&player2->increment.y,  1); break;
	default:break;
	}
}

void changeNestStep(GLint * value, GLint flag)
{
	if (*value == flag)
	{
		*value = 0;
	}
}
