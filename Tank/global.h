#pragma once
#include<gl/glut.h>
#include<stddef.h>

#include"my_struct.h"

/*����ȫ�ֱ���*/

//��Ļ�Ĵ�С��
extern GLfloat windowWidth;
extern GLfloat windowHeight;

//���̹�ˣ�
extern Tank player1;
extern Tank player2;

//�з�̹�˵�ͷָ�룻
extern Tank *enemyHead;
//�з�̹�˵�βָ�룻
extern Tank *enemyTail;

//��Ϸ�������ɫ��
extern Vector3 color[14];

//�����׼���˶�����,�ֱ�Ϊ��������
extern Vector3 direction[4];

//�ӵ���ͷָ�룻
extern Shell *shellHead;
//�ӵ���βָ�룻
extern Shell *shellTail;