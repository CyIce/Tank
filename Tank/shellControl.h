#pragma once
#include<stdlib.h>

#include "my_struct.h"
#include "global.h"
#include "prefabs.h"
#include "collision.h"
#include "destroy.h"

//在地图上添加一个子弹；
void shellAdd(Tank tank);

//控制子弹移动；
void shellMoving(GLint value);

//显示子弹；
void shellShowing();

//销毁子弹；
void shellDelete();