#pragma once
#include<stdlib.h>

#include "my_struct.h"
#include "global.h"

//在地图上添加一个子弹；
void addShell(Tank tank);

//控制子弹移动；
void shellMoving(Tank *head);