#pragma once
#include<gl/glut.h>
#include "global.h"

//������1�������£�
void processSpecialKeys(int key, int x, int y);
//������1����̧��
void processSpecialKeysUp(int key, int x, int y);
//������2�������£�
void processKeys(unsigned char key, int x, int y);
//������2����̧��
void processKeysUp(unsigned char key, int x, int y);
//�ڰ���̧��ʱ�ı������һ���Ķ�����
void changeNestStep(GLfloat *value, GLfloat flag);