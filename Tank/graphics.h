#pragma once
#include<gl/glut.h>

#include "global.h"
#include "prefabs.h"
#include "shellControl.h"
#include "collision.h"
#include "tankControl.h"

//���������ɫ��
void setupRC();

//����ͼ��
void renderScene();

//�ı䴰����ʾ�Ĵ�С
void changeSize(GLsizei w, GLsizei h);
