#pragma once
#include<gl/glut.h>
#include<stddef.h>

#include"my_struct.h"

/*定义全局变量*/

//屏幕的大小；
extern GLfloat windowWidth;
extern GLfloat windowHeight;

//玩家坦克；
extern Tank player1;
extern Tank player2;

//敌方坦克的头指针；
extern Tank *enemyHead;
//敌方坦克的尾指针；
extern Tank *enemyTail;

//游戏物体的颜色；
extern Vector3 color[14];

//储存标准的运动方向,分别为上右下左；
extern Vector3 direction[4];

//子弹的头指针；
extern Shell *shellHead;
//子弹的尾指针；
extern Shell *shellTail;