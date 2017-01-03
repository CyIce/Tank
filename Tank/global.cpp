
#include"global.h"

GLint windowWidth;
GLint windowHeight;

GLint map[800][800];

GLint mapWidth;
GLint mapHeight;

Tank *player1;
Tank *player2;

GLint player1Score;
GLint player2Score;

Vector3i player1Position = { 200 ,20,0 };
Vector3i player2Position = { 20,20,0 };

Vector3i enemyPosition = { 380,210,0 };

GLint colorNum = 0;

GLint num = 10;

GLfloat lastTime;

GLint gameState = 0;

GLint maxTankNum = 0;

Tank *tankHead = NULL;
Tank *tankTail = NULL;

Shell *shellHead = NULL;
Shell *shellTail = NULL;

Vector3f color[14] = 
{
	{0,0,0},//�ڣ�
	{1,0,0},//�죻
	{0,1,0},//�̣�
	{1,1,0},//�ƣ�
	{0,0,1},//����
	{1,0,1},//�ϣ�
	{0,1,1},//�ࣻ
	{0.25f,0.25f,0.25f},//��ң�
	{0.75f,0.75f,0.75f},//ǳ�ң�
	{0.6f,0.4f,0.12f},//�أ�
	{0.98f,0.625f,0.12f},//�Ϲϳȣ�
	{0.98f,0.04f,0.7f},//�ۺ죻
	{0.6f,0.4f,0.7f},//�Ϻ죻
	{1,1,1}//�ף�
};
Vector3i direction[4]=
{
	{ 0, 1, 0},
	{ 1, 0, 0},
	{ 0,-1, 0},
	{-1, 0, 0}
};
