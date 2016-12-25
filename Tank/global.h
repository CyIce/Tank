#pragma once
#include<gl/glut.h>

#include"my_struct.h"
/*定义全局变量*/

//屏幕的大小；
extern GLfloat windowWidth;
extern GLfloat windowHeight;

//玩家坦克；
extern Tank player1;
extern Tank player2;

//敌方坦克；
extern Tank enemy[20];

//游戏物体的颜色；
extern Vector3 color[14];

//储存标准的运动方向,分别为左上右下；
extern Vector3 direction[4];