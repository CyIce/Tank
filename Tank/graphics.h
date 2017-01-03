#pragma once
#include<gl/glut.h>

#include "global.h"
#include "prefabs.h"
#include "shellControl.h"
#include "collision.h"
#include "tankControl.h"
#include "UI.h"

//清除窗口颜色；
void setupRC();

//绘制图像；
void renderScene();

//改变窗口显示的大小
void changeSize(GLsizei w, GLsizei h);
