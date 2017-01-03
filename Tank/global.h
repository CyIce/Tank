#pragma once
#include<gl/glut.h>
#include<stddef.h>

#include"my_struct.h"

/*����ȫ�ֱ���*/

//��Ļ�Ĵ�С��
extern GLint windowWidth;
extern GLint windowHeight;

//������Ϸ��ͼ,map��0.1.2.3.4�ֱ�Ϊ���ƶ������1�����2��ǽ�ڣ��ӵ���
extern GLint map[800][800];

//��Ϸ��ͼ��ʵ�ʴ�С��
extern GLint mapWidth;
extern GLint mapHeight;

//���̹�ˣ�
extern Tank *player1;
extern Tank *player2;

//��ҵķ�����
extern GLint player1Score;
extern GLint player2Score;

//���̹�˵ĳ�ʼλ�ã�
extern Vector3i player1Position;
extern Vector3i player2Position;

//�з�̹�˵ĳ�ʼλ�ã�
extern Vector3i enemyPosition;

//�з�̹�˵���ɫ��
extern GLint colorNum;

//�з�̹�˵ı�ţ�
extern GLint num;

//��Ϸ�����з�̹����Ŀ��
extern GLint maxTankNum;

//��һ��̹�˵�ʱ�䣻
extern 	GLfloat lastTime;

//��Ϸ״̬��
extern GLint gameState;

//̹�˵�ͷָ�룻
extern Tank *tankHead;
//̹�˵�βָ�룻
extern Tank *tankTail;

//��Ϸ�������ɫ��
extern Vector3f color[14];

//�����׼���˶�����,�ֱ�Ϊ��������
extern Vector3i direction[4];

//�ӵ���ͷָ�룻
extern Shell *shellHead;
//�ӵ���βָ�룻
extern Shell *shellTail;