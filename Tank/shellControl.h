#pragma once
#include<stdlib.h>

#include "my_struct.h"
#include "global.h"
#include "prefabs.h"
#include "collision.h"
#include "destroy.h"

//�ڵ�ͼ�����һ���ӵ���
void shellAdd(Tank tank);

//�����ӵ��ƶ���
void shellMoving(GLint value);

//��ʾ�ӵ���
void shellShowing();

//�����ӵ���
void shellDelete();