#pragma once
#include<gl/glut.h>

#include"my_struct.h"
/*����ȫ�ֱ���*/

//��Ļ�Ĵ�С��
extern GLfloat windowWidth;
extern GLfloat windowHeight;

//���̹�ˣ�
extern tank player1;
extern tank player2;

//�з�̹�ˣ�
extern tank enemy[20];

//��Ϸ�������ɫ��
extern vector3 color[14];

//�����׼���˶�����,�ֱ�Ϊ�������£�
extern vector3 direction[4];