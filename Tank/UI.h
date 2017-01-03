#pragma once
#include<stdio.h>
#include<stdlib.h>

#include "global.h"
#include "drawString.h"


//显示玩家的分数；
void score();

//显示排行榜；
void rank();

//更新排行榜；
void updateRank();

//检测游戏结束；
void gameOver(GLint value);