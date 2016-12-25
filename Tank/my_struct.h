#pragma once
#include<gl/glut.h>

//����һ����ά��������
struct vector3
{
	GLfloat x;
	GLfloat y;
	GLfloat z;
};

//����һ��̹�˵Ľṹ�壻
struct tank
{
	//̹�˵�λ�ã�
	vector3 position;
	//̹����һ��λ�õ�������
	vector3 increment;
	//̹�˵���ɫ��
	vector3 RBG;
	//̹�˵��˶�����,�����X��˳ʱ����ת�ĽǶȣ�
	GLfloat direction;
	//̹�˵�����ֵ��
	GLfloat HP;
	//̹�˵��ٶȣ�
	GLfloat speed;

};

struct shell
{
	vector3 position;
	vector3 direcion;
	GLfloat lifetime;
	GLfloat speed;
};