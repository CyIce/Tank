#pragma once
#include<gl/glut.h>
#include "global.h"

//������1�������£�
void player1SpecialKeys(int key, int x, int y);
//������1����̧��
void player1SpecialKeysUp(int key, int x, int y);
//���1�����ӵ���
void player1Keys(unsigned char key, int x, int y);


//������2�������£�
void player2Keys(unsigned char key, int x, int y);
//������2����̧��
void player2KeysUp(unsigned char key, int x, int y);


//�ڰ���̧��ʱ�ı������һ���Ķ�����
void changeNestStep(GLfloat *value, GLfloat flag);