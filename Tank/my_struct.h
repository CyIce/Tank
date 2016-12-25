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
	GLfloat direction;
	//̹�˵�����ֵ��
	GLfloat HP;
	//̹�˵��ٶȣ�
	GLfloat speed;

};

struct shell
{
	Vector3 position;
	Vector3 direcion;
	GLfloat lifetime;
	GLfloat speed;
};