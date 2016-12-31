#pragma once
#include<gl/glut.h>
#include<stddef.h>

#include"my_struct.h"

/*����ȫ�ֱ���*/

//��Ļ�Ĵ�С��
extern GLint windowWidth;
extern GLint windowHeight;

//������Ϸ��ͼ,map��0.1.2.3.4�ֱ�Ϊ���ƶ������1�����2���ӵ���
extern GLint map[800][800];

//��Ϸ��ͼ��ʵ�ʴ�С��
extern GLint mapWidth;
extern GLint mapHeight;

//���̹�ˣ�
extern Tank player1;
extern Tank player2;

//�з�̹�˵�ͷָ�룻
extern Tank *enemyHead;
//�з�̹�˵�βָ�룻
extern Tank *enemyTail;

//��Ϸ�������ɫ��
extern Vector3f color[14];

//�����׼���˶�����,�ֱ�Ϊ��������
extern Vector3i direction[4];

//�ӵ���ͷָ�룻
extern Shell *shellHead;
//�ӵ���βָ�룻
extern Shell *shellTail;