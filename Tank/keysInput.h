#pragma once
#include<gl/glut.h>

#include "global.h"
#include "shellControl.h"

//检测玩家1按键按下；
void player1SpecialKeys(int key, int x, int y);
//检测玩家1按键抬起；
void player1SpecialKeysUp(int key, int x, int y);


//检测玩家2按键按下&&玩家1，2发射子弹；
void player2Keys(unsigned char key, int x, int y);
//检测玩家2按键抬起；
void player2KeysUp(unsigned char key, int x, int y);


//在按键抬起时改变玩家下一步的动作；
void changeNestStep(GLint *value, GLint flag);