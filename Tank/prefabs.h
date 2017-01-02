#pragma once

#include"my_struct.h"
#include<math.h>

#define PI 3.141592657

//创造坦克；
void generateTank(Tank tank);

//生成子弹；
void generateShell(Shell shell);

//生成障碍物；
void generateBlock(GLint x, GLint y,GLint color);

void test();

