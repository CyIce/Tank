#pragma once
#include<gl/glut.h>
#include<stddef.h>

#include"my_struct.h"

/*定义全局变量*/

//屏幕的大小；
extern GLint windowWidth;
extern GLint windowHeight;

//定义游戏地图,map中0.1.2.3.4分别为可移动，玩家1，玩家2，墙壁，子弹；
extern GLint map[800][800];

//游戏地图的实际大小；
extern GLint mapWidth;
extern GLint mapHeight;

//玩家坦克；
extern Tank *player1;
extern Tank *player2;

//玩家的分数；
extern GLint player1Score;
extern GLint player2Score;

//玩家坦克的初始位置；
extern Vector3i player1Position;
extern Vector3i player2Position;

//敌方坦克的初始位置；
extern Vector3i enemyPosition;

//敌方坦克的颜色；
extern GLint colorNum;

//敌方坦克的编号；
extern GLint num;

//游戏中最大敌方坦克数目；
extern GLint maxTankNum;

//上一次坦克的时间；
extern 	GLfloat lastTime;

//游戏状态；
extern GLint gameState;

//坦克的头指针；
extern Tank *tankHead;
//坦克的尾指针；
extern Tank *tankTail;

//游戏物体的颜色；
extern Vector3f color[14];

//储存标准的运动方向,分别为上右下左；
extern Vector3i direction[4];

//子弹的头指针；
extern Shell *shellHead;
//子弹的尾指针；
extern Shell *shellTail;