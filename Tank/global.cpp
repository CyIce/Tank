
#include"global.h"

GLint windowWidth;
GLint windowHeight;

GLint map[251][481];

Tank player1;
Tank player2;

Tank *enemyHead = NULL;
Tank *enemyTail = NULL;

Shell *shellHead = NULL;
Shell *shellTail = NULL;

Vector3f color[14] = 
{
	{0,0,0},//ºÚ£»
	{1,0,0},//ºì£»
	{0,1,0},//ÂÌ£»
	{1,1,0},//»Æ£»
	{0,0,1},//À¶£»
	{1,0,1},//×Ï£»
	{0,1,1},//Çà£»
	{0.25f,0.25f,0.25f},//Éî»Ò£»
	{0.75f,0.75f,0.75f},//Ç³»Ò£»
	{0.6f,0.4f,0.12f},//×Ø£»
	{0.98f,0.625f,0.12f},//ÄÏ¹Ï³È£»
	{0.98f,0.04f,0.7f},//·Ûºì£»
	{0.6f,0.4f,0.7f},//×Ïºì£»
	{1,1,1}//°×£»
};
Vector3i direction[4]=
{
	{ 0, 1, 0},
	{ 1, 0, 0},
	{ 0,-1, 0},
	{-1, 0, 0}
};
