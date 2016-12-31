#pragma once

#include "prefabs.h"
#include "global.h"
#include "my_struct.h"

//初始化游戏边界；
void gameBoundary();

//初始化坦克的边界；
void tankBoundary(Tank tank);

//随着坦克的运动改变坦克的边界；
void changeTankBoundary(Tank tank);