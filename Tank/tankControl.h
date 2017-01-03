#pragma once
#include<stdlib.h>
#include<time.h>

#include<gl/glut.h>
#include "my_struct.h"
#include "global.h"
#include "prefabs.h"
#include "collision.h"
#include "AI.h"

//在游戏中添加一个坦克；
void tankAdd(Vector3i vec,GLint mark);

//控制坦克移动；
void tankMoving(GLint value);

//显示坦克；
void tankShowing();

//销毁坦克；
void tankDelete();

//不断添加坦克；
void tankAppend(GLint value);