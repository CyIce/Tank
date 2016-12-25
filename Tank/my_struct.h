#pragma once
#include<gl/glut.h>

//����һ����ά��������
struct Vector3
{
	GLfloat x;
	GLfloat y;
	GLfloat z;
};

//����һ��̹�˵Ľṹ�壻
struct Tank
{
	//̹�˵�λ�ã�
	Vector3 position;
	//̹����һ��λ�õ�������
	Vector3 increment;
	//̹�˵���ɫ��
	Vector3 RBG;
	//̹�˵��˶�����,�����X��˳ʱ����ת�ĽǶȣ�
	GLuint direction;
	//̹�˵�����ֵ��
	GLfloat HP;
	//̹�˵��ٶȣ�
	GLfloat speed;

};

struct Shell
{
	//��ǰ�ӵ���λ�ã�
	Vector3 position;
	//�ӵ���һ����λ�ã�
	Vector3 increment;
	//�ӵ�������˶����룻
	GLuint power;
	//�ӵ����˶��ٶȣ�
	GLfloat speed;
	//�ӵ������ͣ�
	GLuint type;
	//ָ����һ���ӵ���ָ��
	Shell *next;
};