#pragma once
#include<gl/glut.h>

#include"my_struct.h"
/*����ȫ�ֱ���*/

//��Ļ�Ĵ�С��
extern GLfloat windowWidth;
extern GLfloat windowHeight;

//���̹�ˣ�
extern Tank player1;
extern Tank player2;

//�з�̹�ˣ�
extern Tank enemy[20];

//��Ϸ�������ɫ��
extern Vector3 color[14];

//�����׼���˶�����,�ֱ�Ϊ�������£�
extern Vector3 direction[4];