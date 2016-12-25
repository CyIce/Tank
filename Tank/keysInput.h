#pragma once
#include<gl/glut.h>
#include "global.h"

//检测玩家1按键按下；
void processSpecialKeys(int key, int x, int y);
//检测玩家1按键抬起；
void processSpecialKeysUp(int key, int x, int y);
//检测玩家2按键按下；
void processKeys(unsigned char key, int x, int y);
//检测玩家2按键抬起；
void processKeysUp(unsigned char key, int x, int y);
//在按键抬起时改变玩家下一步的动作；
void changeNestStep(GLfloat *value, GLfloat flag);